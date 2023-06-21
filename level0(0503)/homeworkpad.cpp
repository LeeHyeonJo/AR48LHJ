// 6번
#include <iostream>
using namespace std;

int num = 0; // 자전거 암호 숫자 갯수
char pw[20][5] = {}; // 자전거 암호들 

// 몇번만에 각 암호들을 해제할 수 있는지 출력 

void dfs(int level)
{
	
}

int main()
{
	cin >> num; 
	
	for (int i = 0; i < num; i++)
	{
		cin >> pw[i];    
	}

	// 일단 경로를 기록하며 그게 암호와 일치하는지 여부 체크해야 함

	dfs(0); 
}