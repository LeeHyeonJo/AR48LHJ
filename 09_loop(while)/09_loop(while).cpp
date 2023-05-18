﻿// 09_loop(while).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// while: 의식하고 쓰던 것을 무의식으로 쓸 수 있게 익숙해지기.

#include <iostream>
int main()
{
    // while 문 & break

       //1. while 문 문법 

    // 조건문에 쓸 변수 초기화
    int x = 0; 
    while (x < 10)
    {
        x++; // x = 0~9까지 돌고 10일때 빠져나온다. 단, if문과 달리 조건문에서 인수 초기화 불가능!
    }
    // 1-1. while문과 for문의 일반적인 사용처. 
    // while문: 무한으로, 언제 끝날지 모르는 작업을 반복할 때 사용.
    // for문: 횟수가 정해진 반복을 할때 사용.


    // 2. 특정 조건/구간에서 빠져나오고 싶을때? break!
    // 정의: 가장 가까운 반복문에서 빠져나온다. 
    // 함수에서 빠져나오는 건: return; 

    int a = 1;
    while (a < 10)
    {
        for (int i = 0; i < 2; i++)
        {
            //여기에 for문이 있다면, for문을 빠져나오게 됨. 
            //관찰결과: for문을 빠져나와 36행으로. 그리고 다시 while을 실행한다. 
            if (a == 5)
            {
                break; // 가장 가까운 while 문에서 빠져나옴. 
            }
        }
        a++;
    }


    //2. 2중while문
    int y = 0;
    while (y < 10)
    {

    }

    return 0;
}


