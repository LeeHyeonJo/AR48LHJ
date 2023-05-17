//6
#include <iostream>
int main()
{
	char vect[100] = {};
	char a = '\0'; 
	std::cin >> a; // 문장 입력 - 큰 char 형 배열에 넣어주면 된다.

	for (int i = 0; i < 100; i++)
	{
		vect[i] = a;

		if (vect[i-1] == 0)
		{
			break;
		}
	}

	//length :: index +1
	int length = 0; 

	for (int i = 0; i < 100; i++)
	{
		while (vect[i] != 0) //ascii
		{
			length = i + 1;
		}

		if (vect[i] == 0)
		{
			break; //for
		}
	}


	// find last index
	int index = length - 1;
	int count = 0; 
	for (int i = 0; i < length; i++)
	{
		if (vect[i] == vect[index])
		{
			count++; 
		}
	}

	std::cout << "길이 = " << length << std::endl;
	std::cout << "갯수 = " << count << std::endl;


}
