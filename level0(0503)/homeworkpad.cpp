// 7번
#include <iostream>
using namespace std;
// 이진트리는 일차배열로 나타낼 수 있다. 
int tree[8] = { 0,3,7,10,5,6,3,6 };
			  // 0 1 2 3 4 5 6 7
int path[100] = {};  

void dfs(int now) // now 시작하는 곳 
{
	if (tree[now] % 2 == 0) // 짝수일때 
	{
		for (int i = 0; i < 8; i++) // 0만 걸러내고 출력하고 싶음. 
		{
			if (path[i] != 0)
			{
				cout << path[i] << ' '; 
			}
		}
		cout << endl; 
	}

	for (int i = 1; i < 8; i++) 
	{
		if (i == now * 2) // 좌 , i는 자식 
		{
			path[now] = tree[now]; // path에 차곡차곡 저장하는법 ㅅㅂ.. 
			dfs(i); // 그 자식에서 다시 자식찾기 
			path[now] = 0;
		}

		else if (i == now * 2 + 1) // 우, i는 자식
		{
			path[now] = tree[now];
			dfs(i); 
			path[now] = 0;
		}
	}
}

int main()
{
	dfs(1); 
}