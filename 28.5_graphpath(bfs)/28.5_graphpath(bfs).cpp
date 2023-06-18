﻿// 28.5_graphpath(bfs).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 그래프에서 이어지는 문서 / 2.그래프의 경로 구현. (필기 참고하고 내부 내용 보충하기!) 
// BFS 로 해보자! (28에 있는 같은 그래프를 bfs로 도는거임) 
// ** 그래프 그려보고 시작하는거 잊지 말기 ** 

// **그래프를 도는 모든 경로를 탐색하는 법 

#include <iostream>
#include <queue>
using namespace std; 


//** BFS로 탐색할때는
//** 큐의 모든 노드가 경로를 들고 있어야 한다. <- 중요 (dfs에서 visited와 같은 역할) 

// 원리: 
// 그림을 그려보고, Z에서 시작했을 때, C로 가는 경로는 3가지.
// 이 경로를 0과 1로 기록해둔다

int matrixGraph[6][6] =
{
	//  0 1 2 3 4 5  x
	//  Z A D C E B  
		0,1,1,1,0,0, // Z
		1,0,0,1,0,1, // A
		1,0,0,1,0,0, // D
		1,1,1,0,1,1, // C
		0,0,0,1,0,1, // E
		0,1,0,1,1,0, // B
};

char alpha[10] = "ZADCEB"; // 연결된 알파벳들 
char path[10] = ""; // 경로 기록용 (출력할때 쓰는 거)

struct node
{
	int num = -1; // 시작하는 값(ex. Z)의 y 축 값!!
					// (큐 생성시 num값이 바뀌는 걸 확인하려고 일부러 -1을 넣어준 것) 

	int used[6] = {}; // 큐에 들어가는 노드가 들고있을 경로 
};


int main()
{
	std::queue<node> cute; // 큐트라는 이름의 큐를 생성
	cute.push(node{ 0,{1,0,0,0,0,0} }); // 첫 노드 생성 (num에 0, 첫 방문Z에 1 넣음) 
		   // num:Z의 y축, used:Z방문 여부 체크 

	// 두번째 노드 생성 (큐가 비어있지 않을때 계속 반복)
	while (!cute.empty()) // 비어있을 경우 n을 리턴. 
	{
		// 제일 앞 노드를 가리키는 변수 p 생성 
		node p = cute.front(); 
		 /// + 2번째부터는 pop 된 뒤의 노드를 가리키기 시작하면서 돈다. 

		// 인접행렬을 돌면서,그래프를 탐색하기 시작.
		// 값을 (자료를) 큐에 차례대로 넣어주고, 앞에서부터 빼주며 처리한다. 

		for (int x = 0; x < 6; x++) // x축
		{
			if (matrixGraph[p.num][x] == 1 && p.used[x] == 0)
				// 연결되어있고, 첫 방문일때 (Z에서 A로 막 넘어가는 상황일때,
				// 즉 p.used[x] 는 A를 가리키며, 그 값이 0 이다) 
			{
				// 두번째 노드 추가 시작 ~
				node newnode2 = {}; // newnode2는 두번째 노드를 뜻하는 변수 
								// 상단 노드 선언에서 {}로 묶이므로 
								// 초기화도 {}로 해줄 수 있는 것. 
								
				// 두번째 노드의 내부를 채워줌 
				
				// 1. num
				newnode2.num = x; // A의 인덱스. 이게 다음 줄 탐색하면서 y축이 될거임 

				// 2. used(경로) - 이전 노드에 있던 값을 복사해서 넣어준 다음
				// 이번에 사용된 경로를 따로 기록해준다.

				// a. 이전 경로를 복사 
				memcpy(newnode2.used, p.used, sizeof(int) * 6); 

				// ** 경로 기록의 원리
				// (큐) 바로 앞 노드에 있는 경로를 복사해와서 그 뒤의 새로운 노드에 넣어준 것 뿐. 
				// 그 부분이 memcopy: ~ <- 원래는  for문으로 풀어야 하나.. 
				// memcopy(a.b.c) : a에 b를 c바이트만큼 복사한다.
				// 예시에서 b는 int형, 크기가 6인 배열임./ c는 이 크기를 나타내야 함
				// 그래서 c는 size od(int) * 6 이 된 것 

				// b. 복사해온 경로에, 이번에 들어가는 경로(A)를 체크. 
				newnode2.used[x] = 1; // A를 사용했다고 체크. 

				cute.push(newnode2); // 두번째 노드를 큐에 넣어줌. 
			}
		}

		// 경로 출력
		for (int i = 0; i < 6; i++)
		{
			if (p.used[i] == 1) // 그 경로에 방문했다면
				// (현재 p가 가리키고 있는 큐에 들어있는 노드)
			{
				cout << alpha[i] << ' '; // 해당하는 알파벳을 출력해줌
										//(== used에 따라, 경로가 출력됨) 
			}
		}

		cout << endl; 

		// 가장 앞의 노드 값은 전부 사용 끝. 
		cute.pop(); 
	}
}


// ㄴ 마찬가지로 used에서 중복체크를 해주고 있으므로, 
// Z에서 A로 pop 된 후 큐가 넘어갔을 떄. 
// A->Z로 넘어가는 건 불가능하다. 




