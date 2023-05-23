// 재귀함수 모법담안
#include <iostream>

int arr[5] = { 5,7,1,2,3 };

void wow(int level)
{
	if (level == 5)
	{
		return; 
	}
	std::cout << arr[level]; 
	wow(level + 1);
	// return 받고 돌아오는 곳 
	std::cout << arr[level]; 
}

int main()
{
	wow(0);
	std::cout << "재귀함수가 종료되었습니다."; 
}