// 8번
#include <iostream>
using namespace std;

int image[4][4] =
{
	1, 5, 5, 4,
	4, 2, 1, 1,
	3, 9, 3, 2,
	4, 5, 9, 1 
};

int max1 = -1234; 

int newY = 0; 
int newX = 0; 

int maxY = 0; 
int maxX = 0; 

int rectSum(int _y, int _x)
{
	int sumsum = 0;

	// 2x3 사이즈의 합을 리턴해주는 함수 
	// 스타트 값에서 2x3을 서치하는 것 
	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			// **이 부분 주의 
			newY = _y + y; 
			newX = _x + x; 

			// **2x3 배열이 map 밖으로 나가지 않게 
			if ((newY >= 0 && newY <= 3) && (newX >= 0 && newX <= 3))
			{
				sumsum += image[newY][newX]; 
			}
		}
	}
	
	return sumsum; // 총합만 리턴함 
}

int main()
{
	// 이미지 배열에 입력 
	//for (int i = 0; i < 4; i++)
	//{
	//	for (int k = 0; k < 4; k++)
	//	{
	//		cin >> image[i][k]; 
	//	}
	//}

	// 배열을 돌면서 시작 좌표를 함수로 보냄 
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			int result = rectSum(y, x); // 여러 값이 리턴될거임 

			// 여기서 합의 최대값을 비교 
			if (max1 < result) 
			{
				max1 = result; 
				maxY = y;
				maxX = x;
			}
		}
	}

	cout << "(" << maxY << "," << maxX << ")"; 
}