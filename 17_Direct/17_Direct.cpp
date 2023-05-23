// 17_Direct.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 방향 나눈거: 

#include <iostream>

int map[5][4] = {};


int main()
{

    int x = 1;
    int y = 2;


    // 하드코딩 방식
    int left = map[y][x - 1];
    int right = map[y][x + 1];
    int top = map[y - 1][x];
    int bottom = map[y + 1][x];


    // Direct 방식
    int offset[4][2] =
    {
        0, 1, //right
        0, -1, //left
        1, 0, //bottom
        -1, 0, //top
    };

    for (size_t i = 0; i < 4; i++)
    {
        int newX = x + offset[i][1];
        int newY = y + offset[i][0];

        int data = map[newY][newX];

        if (data)
        {

        }
    }


    return 0;
}

