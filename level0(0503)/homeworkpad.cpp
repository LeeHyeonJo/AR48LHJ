// 7번
#include <iostream>
using namespace std;
int btree[8] = { 0,3,7,10,5,6,3,6 };
//  0 1 2  3 4 5 6 7
int visited[8] = {}; // 방문 여부 체크 
int path[8] = {};

// 이차원 트리에 한해서 일차원 배열로 표현할 수 있다. 
// 부모 - 자식 공식을 사용하기 위해 인덱스 1부터 값 넣어줌. 

void dfs(int level, int now) // 레벨과, 초기값(변동) 
{
	// 1. 레벨 2일때 리턴되면 안되지.
	// 2. 출력이 for문 위에서 
	// 3. 짝수 체크는 path 에서. 

	for (int i = 1; i < 8; i++)
	{
		if (level == 0)
		{
			path[0] = btree[1]; // 제일 첫 값 넣어줌 
		}

		// 자식쪽 인덱스의 값이 존재하면 내려간다. 
		if (btree[now * 2] != 0 && visited[i] == 0)
		{
			visited[i] = 1; // 첫값 때문에 두번째 자리부터 
			path[level + 1] = btree[now * 2]; // 첫값 때문에 두번째 자리부터 

			if (btree[now * 2] % 2 == 0) // 짝수라면 
			{
				// 멈추고 출력 
				for (int i = 0; path[i] != 0; i++)
				{
					cout << path[i] << ' ';
				}
			}

			dfs(level + 1, i * 2);
			path[level + 1] = 0;
		}

	}
}

int main()
{
	// 1. 트리 입력 
	//for (int i = 0; i < 8; i++)
	//{
	//	cin >> btree[i]; 
	//}

	dfs(0, 1);
}