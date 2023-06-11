// 7번
#include <iostream>
using namespace std; 

int arr[4][3] =
{
	{3,5,1},
	{3,1,2},
	{3,4,6},
	{5,4,6}
};

int dat[7] = {}; 

int main()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			dat[arr[y][x]]++; 
		}
	}

	// 출력
	for (int i = 1; i <7; i++)
	{
		cout << i << ' '; 

		for (int k = 0; k < dat[i]; k++) //  반복 횟수 
		{ 
			cout << "★ "; 
		}
		cout << endl; 
	}
}