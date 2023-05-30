// 중복을 허용하지 않는 뽑기 (전체 3개중에 2개를 중복을 허용하지 않고 뽑을 때) 
#include <iostream>
using namespace std; 

char path[8] = {}; // 왼쪽으로 가면 a, 오른쪽으로 가면 b. 
int visited[10] = {}; 

void kfc(int level)
{
	if (level == 2) // 레벨이 2일떄 (= 전체에서 뽑을 카드의 수) 
	{
		cout << path << endl; 
		return; 
	}

	for (int i = 0; i < 3; i++) // i = 가지의 수 (=총 카드의 수) 
	{
		if(visited[i]==0) // 방문하지 않았을때만 진행 
		{ 
			visited[i] = 1; // 들어가기 직전에 진입 기록
			path[level] = 'a' + i; // 들어가기 직전에 경로 기록  a,b,c 
			kfc(level + 1);
			path[level] = 0; // 돌아간 후 기록 지우기. 
			visited[i] = 0; // 돌아간 후 기록 지우기. 
		}
	}
	// 원리: 들어가기 전에 경로를 기록. 나오면서(=이전 함수로 돌아가서) 지움. 
}

int main()
 {
	kfc(0);

}

