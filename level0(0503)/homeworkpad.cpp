//**선택 정렬의 사용법. (오름차순 정리)
#include <iostream>
int main()
{
	int arr[6] = {5,3,6,1,2,8};

	for (int y = 0; y < 6; y++)
	{
		for (int x = y + 1; x < 6; x++) // x는 y의 다음 값이므로 y+1임에 주의!! 
		{
			if (arr[y] > arr[x])
			{
				int temp = arr[y];
				arr[y] = arr[x];
				arr[x] = temp;
			}
		}
	}
}