//2번
#include <iostream>
using namespace std;

int counting = 0;
char arr[4] = {}; // 경로를 저장할 배열 

void test(int level, char _spell[5])
{
	if (level == 4) // 4글자를 전부 조합 (깊이 4까지)
	{
		// 레벨 4에 도착했을때 카운트
		counting++;
		return;
	}


	// 4글자를 입력받음 (가지 4개)
	for (int i = 0; i < 4; i++)
	{
		//B,T가 붙어있을때는, 다음 반복문으로 넘어간다. 
		//따라서 continue가 옳다. 
		if ((_spell[level] == 'B' && _spell[i] == 'T') || (_spell[level] == 'T' && _spell[i] == 'B'))
		{ // leve1>0, level-1 이라는 조건이 붙어야함. 
			continue;
		}

		arr[level] = _spell[i]; // 진입 전, arr에 경로 저장 
		test(level + 1, _spell); // 다음으로 내려갈 수 있게 lv+1
		arr[level] = 0;
	}

}

int main()
{
	char spell[5] = {};
	cin >> spell;

	// 네 글자를 조합해서 나올 수 있는
	// 모든 경우의 수를 출력.

	test(0, spell);
	cout << counting;
}