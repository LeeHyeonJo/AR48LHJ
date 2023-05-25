// 20.5_string함수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 지금까지 문자열을 구하는 함수를 직접 코딩해서 썼다.
// 이젠 문자열의 길이를 구하는 함수를 사용해보자. >> 레벨 22부터는 함수 쓰기 

#include <iostream>
#include <string.h>

int main()
{
    char str[54] = "dsf"; 
    //1. 문자열의 길이를 구해주는 함수 
    // strlen(배열의 주소가 들어간다) ; 
    int len = strlen(str);

    char strA[5] = "fdf";
    char strB[5] = "fdf";

    // 2. 문자열을 비교하는 함수 
    //strcmp(인자 2개) 
    if (strcmp(strA, strB) == 0)
    {
        // 인자를 2개 받음(배열의 주소, 즉 포인터) 
        // 주의점 : 같으면 0을 반환, 다르면 아마 -1을 반환. 
        // 하지만 다를 떈 !=0 이라고 쓰면 됨. 
    }

    // 3. 문자열을 복사해주는 함수 
    //strcpy_s(); 인자 2개: 첫인자는 목적지, 두번째 인자는 목적지에 보낼 소스 
    //                          ㄴ 포인터                       ㄴ 포인터 
    char strTemp[34] = "";
    strcpy_s(strTemp, strA);
    // strTemp 배열에 strA을 넣어줌. 

}

