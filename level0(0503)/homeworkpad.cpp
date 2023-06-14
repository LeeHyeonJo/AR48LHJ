// 4번 
#include <iostream>
using namespace std;

int arr[4] = {3,5,9,10};
int arr2[4] = {2,6,9,11};
int result[8] = {};

int main()
{
	int index = 0; //result 용 인덱스는 따로 

	for (int i = 0; i < 4; i++)
	{
		if (arr[i] > arr2[i])
		{
			result[index] = arr2[i]; 
			index++; 
			result[index] = arr[i]; // 이 구간 주의 
			index++; 
		}
	
		else 
		{
			result[index] = arr[i]; 
			index++; 
			result[index] = arr2[i]; // 이 구간 주의 
			index++;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		cout << result[i] << ' '; 
	}
}