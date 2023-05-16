// 7번
#include <iostream>

int arr[7][5] =
{
	{1,},
	{1,0,1,},
	{1,1,0,1,},
	{1,0,1,},
	{0,1,0,0,1},
	{0,0,0,1,},
	{1,1,}
};

int input()
{
	int num = 0;
	std::cin >> num;
	return num; 
}

int process()
{
	int count = 0; 
	for (int x = 0; x < 5; x++)
	{
		if (arr[0][x] == 1)
		{
			count++; 
		}
	}

	return count; 
}

output()
{
	std::cout << ;
}

int main()
{
	input();
	process();
	output();
}