﻿// 04_loop(for).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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

    //이중포문 - 반드시 다 돌려보고 직접 확인해보기. 
    // 숙제: 돌아가는거 확인해보기. 
    //1234
    //1234
    //1234
    //를 출력해주는 것을 for문으로 작성해보자 

    for (int z = 0; z < 3; z++) //1234의 출력을 반복 
    {
        for (int x = 0; x < 4; x++) // 1234 출력
        {
            std::cout << x + 1; 
        }
        std::cout << std::endl;
    }
    
    //삼중for문은 잘 쓰지 않는다. 가독성도 좋지 못하고 친숙하지 않기 때문. 
    //이따금 함수를 이용한 삼중for문을 사용한다. 
    return 0; 
}

//for문은 배열과 같이 쓰이는 경우가 매우 잦다. 
