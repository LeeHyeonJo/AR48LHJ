// 11번
#include <iostream>
using namespace std;

char arr[11] = ""; 

int main()
{
	cin >> arr; 

	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == 'G') // 첫 글자가 G라면 
		{
			if (strlen(arr) - i - 1 >= 4)// 뒤에 HOST가 올 공간이 있다면
			{
				// 그 다음 글자들 비교 
				if (arr[i + 1] == 'H' && arr[i + 2] == 'O' && arr[i + 3] == 'S' && arr[i + 4] == 'T')
				{
					cout << "존재";
				}

				else
				{
					cout << "존재하지 않음"; // 글자수는 충분, but 다른 글자가 들어감. 
				}
			}

			else
			{
				cout << "존재하지 않음"; // 글자수 부족 
			}
		}
	}
}