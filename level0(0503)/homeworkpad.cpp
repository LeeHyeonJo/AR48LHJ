//9번
#include <iostream>
int main()
{
	int a = 0; 
	int b = 0;
	char ch = 0;
	std::cin >> a >> b >> ch; 

	 // ch = 출력할 문자
	// a  = y축 , b = x축 

	for (int i = 0; i < 2; i++)
	{
		for (int y = 0; y < a; y++)
		{
			for (int x = 0; x < b; x++)
			{
				std::cout << ch;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

}