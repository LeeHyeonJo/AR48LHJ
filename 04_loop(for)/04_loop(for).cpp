// 04_loop(for).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// for문. 반복문 중 하나. 
// 코드를 반복해서 실행한다. 

#include <iostream>

int main()
{
    int i; // 몇번 시행할지 세어줄 int형 변수 
    for (i = 0; i<10; i++) //i가 0~9까지 10번 반복 
    {
        std::cout << "Hello World!\n";
    }
  
    //int i
    //for (초기화, 조건식, 증감식)
    // 초기식, 조건식, 증감식은 프로그래머 마음대로 바꿀 수 있다. 

    int d = 0;
    std::cin >> d; // d를 입력 받음 
    k < d // 이렇게 조건식을 바꿀 수도 있음 


    int k; 
    for (k = 0; k < i; k++) // 상단의 if문을 빠져나온 i = 10도 사용 가능 
    {
        std::cout << "Hello World!\n";
    }

    // for문 안에 if문을 사용하는 것도 가능하다. 
    // 0부터 10까지 홀짝 구분하는 함수 
    int j;
    for (j = 0; j < 10; j++)
    {
        if (j % 2 == 0)
        {
            std::cout << j << "는 짝수";
        }
        else
        {
            std::cout << j << "는 홀수";
        }
    }

    
    return 0; 
}

