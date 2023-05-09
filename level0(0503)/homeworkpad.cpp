// 숙제 푸는 패드. 

#include <iostream>
int main()
{
    // 이차형 배열 
    // 배열 선언을 편하게 해보자. 

    int arr2d1[3][4] = // 초기화 
    {
        {4,3,2,1},
        {4,3,2,1},
        {4,3,2,1}
    }; // 세미콜론 잊지말기 


    // 이 배열에 접근하는 법
    // int a = arr2d1[y][x]; 
    // 우측에서 좌측으로 읽는다! 

    //int a = arr2d1[0][2]; // 2
    //int b = arr2d1[2][1]; // 3
    //int c = arr2d1[2][3]; // 1
    //std::cout << a << std::endl;
    //std::cout << b << std::endl;
    //std::cout << c << std::endl;


    // 이중 포문으로 내용을 채워줄 수 있다.
    // arr2d1 은 크기가 4인 배열이 3개 묶인 형태. 

    // 이중배열의 내부를 채워준다. 1,2,3,4로 

    for (int y =0 ;y<3;y++)
    {
        for (int x = 0; x < 4; x++)
        {
            arr2d1[y][x] = x+1;       
        }
    }


    // 이중배열을 출력해본다. 
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            arr2d1[y][x] = x + 1;
            std::cout << arr2d1[y][x];
        }

        std::cout << std::endl;
    }

 }

