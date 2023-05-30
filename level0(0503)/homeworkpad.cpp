// 재귀함수의 위치를 path에 기록하기 복습. 
#include <iostream>
char path[8] = {}; // 왼쪽으로 가면 a, 오른쪽으로 가면 b. 

void kfc(int level)
{
	if (level == 3) // 레벨이 3일떄 (= 뽑을 카드의 수, 총 3장에서) 
	{
		return; 
	}

	// 카드 2개(가지수) 를 뽑았을때 나오는 모든 경우의 수.

	for (int i = 0; i < 2; i++) // i = 가지수 
	{
		path[level] = 'a' + i; // 들어가기 직전에 경로 기록  a,b,c/...
		kfc(level + 1);
		path[level] = 0; // 돌아간 후 기록 지우기. 

	}
	// 원리: 들어가기 전에 경로를 기록. 나오면서(=이전 함수로 돌아가서) 지움. 
}

int main()
 {
	kfc(0);

}

