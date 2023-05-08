// 숙제 푸는 패드. 

//9번 풀이
#include <iostream>
int main()
{
	int arr[4] = {};
	int a = 0;
	int b = 0;
	std::cin >> a >> b;

	arr[0] = a;
	arr[2] = b;

	// std::cout << arr;
	// arr 출력 결과: 0000000F5E6FF928

	std::cout << arr[0] << arr[1] << arr[2] << arr[3];
}