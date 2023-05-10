﻿// 10_swap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 스왑 

#include <iostream>

int main()
{
    // 스왑: 변수 2개가 있을 떄, 서로를 바꿔주는 로직. 
    // 예시

    int a = 5;
    int b = 9; 

    // a = b;  이렇게 하면 안됨! a가 사라짐 

    //방법: 임시 변수를 생성해서 값을 저장해두고 교환해준다.

    int c = a;

    a = b;
    b = c;
}

