// 숙제 푸는 패드. 

// f11 테스트해보기. 
// 4번 풀이
#include <iostream>

void KFC()
{
	std::cout << "KFC입니다.";
}

void MC()
{
	std::cout << "MC입니다.";
}

int main()
{
	int a = 0;
	std::cin >> a;

	if (a == 1)
	{
		KFC();
	}

	else if (a == 2)
	{
		MC();
	}

	else
	{
		std::cout << "입력한 숫자가 1또는 2가 아닙니다.";
	}
}
