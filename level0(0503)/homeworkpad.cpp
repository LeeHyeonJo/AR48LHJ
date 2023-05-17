//6

#include <iostream>

comparego()
{

}

int main()
{
	int arr[5] = {3,5,1,2,7};

	int arr1[5] = {};
	int a = 0;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> a;
		arr1[i] = a;
	}

	comparego(arr,arr1); //배열 여기로 전달... 
}