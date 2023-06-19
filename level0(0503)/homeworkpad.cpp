// 3번
#include <iostream>
#include <queue>
using namespace std;

int graph[6][6] =
{
  //0 1 2 3 4 5
	0,1,0,0,1,0, //0
	0,0,1,0,0,1, //1
	0,0,0,1,0,0, //2
	0,0,0,0,0,0, //3
	0,0,0,0,0,0, //4
	0,0,0,0,0,0, //5
}; 

int start = -1; // 출발지점
int visited[10] = {}; // 방문 여부 체크 

void bfs()
{
	queue<int>cute; // 인트의 값을 담는 큐 

	// 1. 큐에 첫 노드 생성
	cute.push(start); // start노드 

	// 2. 큐에 두번째 노드 생성 
	while (!cute.empty()) // 큐가 비어있지 않을 때 
	{
		int p = cute.front(); // p는 start 노드와 같음 (이게 필요한지 아닌지는 일단 써놓고) 

		// 인접행렬 돌면서 연결된 곳 찾기
		for (int x = 0; x < 6; x++)
		{
			if (graph[start][x] == 1 && visited[x] == 0)
			{
				// 큐에 그 다음 값을 넣어줌 
				visited[x] = 1; 
				cute.push(x); // (graph[start][x]을 넣으면 1만 들어감.. 
			}
		}
	
		// 한 줄 다 돌았으니
		// 출력하고 & 팝
		cout << p << ' '; 
		cute.pop(); 
	}


}

int main()
{
	cin >> start; 
	visited[start] = 1; 
	bfs(); 
}
