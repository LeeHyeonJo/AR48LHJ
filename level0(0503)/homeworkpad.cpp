// 4번
#include <iostream>
using namespace std; 

int matrixGraph[5][5] = // 순회 없는 버전 
{
	0,1,0,0,0,
	0,0,1,1,0,
	0,0,0,0,0,
	1,0,0,0,1,
	0,0,0,0,0,
};

char valueGr[10] = "TEQWA"; // 출력용 
 
// int num = 0; 
int name[7] = { 0,1,2,3,4,5,6 }; 

void dfs(int now)
{
	std::cout << valueGr[now];

	for (int i = 0; i < 5; i++)
	{
		if (matrixGraph[now][i] == 1) // 갈 수 있는 루트일때
		{
			//// 재귀함수를 활용해 그 루트 안으로 들어간다. 
			//path[level + 1] = value[i];
			//dfs(level + 1, i); 
			//path[level + 1] = 0; <- 무한루프에 걸릴 수 있음. 

			//** 그래프의 순회: 나올 필요가 없으므로 (연결된 다른 쪽으로 가야지) 
			//** 굳이 리턴할 필요 없음. 알아서 돌게 하면 된다. 

			dfs(i); // 흠 이거 아닌듯? 맞는듯 
		}
	}
}

int main()
{
	dfs(0);

	return 0;

	// 비지티스 써둔 이유; 제일 처음 T값 사용했다는 의미. 
}