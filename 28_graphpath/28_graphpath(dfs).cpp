// 28_graphpath.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 그래프에서 이어지는 문서.
// 그래프의 경로 구현. (필기 참고하고 내부 내용 보충하기!) 

// ** 특정 노드에 도착하는 경로의 수 체크하는 법 **

#include <iostream>
using namespace std; 

int matrixGraph[6][6] = 
{
//  0 1 2 3 4 5  i
//  Z A D C E B
	0,1,1,1,0,0, // Z
	1,0,0,1,0,1, // A
	1,0,0,1,0,0, // D
	1,1,1,0,1,1, // C
	0,0,0,1,0,1, // E
	0,1,0,1,1,0, // B
};

// ** 어떻게 연결되어있는지 그림으로 그려보고 시작. (그렸음)
              // 012345
char alpha[7] = "ZADCEB"; // 연결되어있는 정보(노드) 
char path[10] = ""; // 경로 기록용 (출력할때 사용) 
int visited[10] = {}; // 중복 체크를 위한 길 (필수!) 

// 그래프의 특징: ** 중복체크 (비지티드)를 반드시 해줘야 한다.**
// 이유: 양방향으로 연결되어 있기 때문에, 해주지 않으면 빙빙 돌게 된다. 

// 1. 우선 모든 경로를 도는 법 부터 시작. 
// - dfs로 탐색 
// ** 예시는 Z부터 탐색했으므로, Z부터 시작하는 모든 경로를 보게 됨. 

void dfs(int _level, int _now) // level 은 path를 위해 now는 탐색을 위해 
{
	// **b. path의 출력 
	cout << path << endl;

	// **a. 함수가 작동하는 부분 
	for (int i = 0; i < 6; i++) // 인접행렬 돌기 시작 
	{

		// 예시: Z->A (i = 1)를 찾은 상황 
		if (matrixGraph[_now][i] == 1 // 조건 1: 연결된 곳이 있을 때
			&& visited[i] == 0) // 조건 2: 연결된 곳이, 첫 방문일때 
		{
			// 맨 처음은 main에서 기록함. 그 다음 부터 
			// 이어진 경로(alpha[i]를 넣어줌) 
			path[_level + 1] = alpha[i]; 
			visited[i] = 1; // 이어진 경로에 방문했다는 기록 (Z->A라면, A를 체크) 
			dfs(_level + 1, i); // 이어진 경로(i)를 y축으로, level은 1씩 증가 
								// ㄴ A에 이어지는 경로를 찾기 위해 & path의 인덱스 증가
			visited[i] = 0;
			path[_level+1] = 0;
					
		}

	}

}


int main()
{
	path[0] = 'Z';// 여기서 제일 처음인 Z의 방문 여부를 path[0]에 기록,
	visited[0] = 1; // 비지티즈 에도 1로 기록 
	
	dfs(0, 0); // level, now (첫 y축)
}

// 29에서 할거임. 
// 가장 간단한 경로를 찾는 법
// 지하철 노선도 가장 짧는 길 찾는 원리와 동일. 

// int min = 6567576; 하나 만들고 시작 

// 정상적인 출력 값 
//Z
//ZA
//ZAC
//ZACD
//ZACE
//ZACEB
//ZACB
//ZACBE
//ZAB
//ZABC
//ZABCD
//ZABCE
//ZABE
//ZABEC
//ZABECD
//ZD
//ZDC
//ZDCA
//ZDCAB
//ZDCABE
//ZDCE
//ZDCEB
//ZDCEBA
//ZDCB
//ZDCBA
//ZDCBE
//ZC
//ZCA
//ZCAB
//ZCABE
//ZCD
//ZCE
//ZCEB
//ZCEBA
//ZCB
//ZCBA
//ZCBE
