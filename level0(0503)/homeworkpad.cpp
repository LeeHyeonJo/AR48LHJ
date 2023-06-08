// 2번 

#include <iostream>
#include <cstring>
using namespace std;

int family[8][8] =
  //A B H C D F G E 
{
	0,1,1,1,0,0,0,0, // A : 65 
	0,0,0,0,0,0,0,0, // B : 66
	0,0,0,0,0,0,0,0, // H : 72
	0,0,0,0,1,0,1,1, // C : 67
	0,0,0,0,0,1,0,0, // D : 68
	0,0,0,0,0,0,0,0, // F : 70
	0,0,0,0,0,0,0,0, // G : 71
	0,0,0,0,0,0,0,0, // E : 69
};

char name[9] = "ABHCDFGE"; 
char path[9] = ""; 
int index = 0; 

int main()
{
	char ch = 0; 
	cin >> ch; 

	// 가로로 돌면서 1이 2개 이상일때 출력 
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (family[y][x] == 1)
			{
				path[index++] = name[x]; 
			}
		}

		// path 의 길이가 2 이상일때 출력 
		// 그 후 path 청소 
		if (strlen(path) >= 2)
		{
			cout << path;
			// path 청소 
			for (int i = 0; i < 9; i++)
			{
				path[i] = '\0';  
			}
			index = 0; 
		}
	}
}