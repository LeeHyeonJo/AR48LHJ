﻿// 05_Array.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 배열: 변수 여러개를 한번에 선언하는 방법. 

#include <iostream>

int main()
{
    // 메모리에 저장되는 변수는 위치가 랜덤하게 정해진다. 
    // 운영체제(윈도우)는 메모리를 할당하고, 값을 찾아갈 수 있게 도와줌
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;

    // 1. 배열의 문법

    int arr[5]; // int형 변수 5개 할당. 

   // 2. 배열에 값 넣는 법 
    // 인덱스: 배열의 각 값에 접근할 수 있도록 돕는 번호. 
    arr[0] = 1; // 배열의 인덱스는 0부터 시작. 거기에 1의 값을 넣어줌. (메모리 주소가 0부터 시작하기 때문) 
    arr[2] = 3;   // [0] = 0번째 변수 , [2] = 2번째 변수 

    // 3. 배열의 출력 
    std::cout << arr[2]; // 2번째 값인 3을 출력돔. 

    //4. 배열의 초기화 
    int arr[5] = { }; // 전부 0으로 초기화 
    int arr[5] = { 1,2,3,4,5 }; // 특정값으로 초기화 
    int arr[5] = { 1,2,3 }; // 입력되지 않은 값은 0으로 치환. (중간은 0입력) 

    // 아래의 초기화는 동일하다 
    int arr[3] = { 1,2,3 }; 

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    // 값을 다 넣어주는걸 "하드코딩' 이라고 한다. 
    // 툴을 만들어야 하는 경우도 있지만, 포폴할때는 그거 만들 시간에 하드코딩하는게 빠르다. 
    // 툴을 만들어야 하는 경우: 컨텐츠 양을 보고 결정됨. (툴을 만드는게 엔진 프로그래머의 역할) 

    // 5. 배열에서 꼭 주의해야할 점. 
    // 반드시 해당 배열의 최대 인덱스 (대괄호 안의 숫자)가 배열의 크기를 넘어가지 않는지 주의해야한다. 
    // 배열의 크기 = n, 최대 인덱스 = n-1 
    // ex) 위에선 크기가 5인 배열을 씀. 하단의 출력한 인덱스는 6임. 최대 인덱스가 배열의 크기를 초과함. 
 
    // 회사는 개발한 게임의 연식에 따라서 해당하는 비.스를 쓴다. 던파는 2005년꺼씀..실화냐 . 
    // 이 경우 오류를 잡아주지 않을 수도 있음. 

    std::cout<<arr[6]; //ex. 넘어간 케이스. 그럼에도 쓰레기 값이 들어간 채로 출력된다. 

    // for문의 조건문이 0부터 시작하는 경우. (int i = 0)
    // 배열의 인덱스가 0부터 시작하기 때문임 

    // for문을 이용해서 배열에 값을 넣고, 출력하기 
    // 숙제: f10으로 i값의 변화와, 그에 따른 배열의 인덱스 변화 및 값의대입 확인할것. 

    for (int i = 0; i < 3; i++)
    {
        arr[i] = 10;
    }

    // 크기가 3인 배열을 만든 후 , 0~2까지의 인덱스에 10의 메모리를 할당한다. 
    // 배열은 동적할당이 불가능하다. 다시 말해, 배열의 크기가 만드시 정해져야한다. (정적) 
    // 이하의 예시는 배열의 크기를 우선 정한 후 초기화를 한 뒤. 
    // for 문으로 배열의 인덱스에 10을 채우는 예시를 보여주고 있다. 

        int arr[3] = { 1,1,1 };

        for (int i = 0; i < 3; i++)
        {
            arr[i] = 10;

            std::cout << arr[i];
        }


    // 문제를 풀 땐 필요한 만큼 변수를 많이 써라. 
    // 위 문제를 좀 더 깔끔하게 정리한 풀이 
    
    int num = 3;
    int x;
    for (x = 0; x < 5; x++) //x로 배열 인덱스, num이 출력 
    {
        arr[x] = num;
        num++;
    }

    // 왜 메모리를 더 사용하고, 변수를 더 할당해야하는가? 
    // 요즘 컴퓨터가 좋아서 메모리 아낄 필요가 없다.



   // 이차형 배열 : 메모리 손으로 그리면서 복습하기! 
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

    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            arr2d1[y][x] = x + 1;
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

    // ** 2중 배열에 입력받는 법 ** 

    // 이중배열  선언함. 
    // char str[3][100000] = 
    // {
    // "asdgasgd", 
    // "asdfasdf",
    // "gjhrty"
    // }; 

    // >> 이렇게 입력하면 실제로는 한 글자씩, 각 배열의 한 칸마다 들어간다.
    // 제일 끝에는 null값이 들어가는것 잊지 말기 !! 

    //** 이중배열 각 가로줄에 입력받는 방법 
    //  char str[3][100000] = (위의 꺼) 
    // ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ......x축 
    // ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ......
    // ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ......
    // y축
    // **  사용법 
    // std::cin>> str[0];
    // std::cin>> str[1]; 
    // std::cin>> str[2];  

    // ** 원리 
    // 배열의 가장 첫 인덱스는 자신의 주소를 갖고 있고. 이는 해당 배열의 주소로 기능한다.
    //  = arr, arr[0] 을 조사식으로 확인하면 들고 있는 메모리의 갯수만 다르고 (전제/맨앞) 주소는 동일 
    // ㄴ 포인터의 원리 상 가장 첫 주소를 알면 주소값을 +1씩 증가 (= 원 메모리의 자료형만큼 바이트 증가)
    // ㄴ 시키며 다음 배열(메모리)에 접근할 수 있기 때문이다. 
    // 이때 str[0]. str[1]. str[2] 는 str[0][0],str[1][0],str[2][0] 를 축약해서 쓴 것이다
    // = 0의 y축 가로줄 전체, 1의 y축 가로줄 전체 ... 이런 식으로. 
    // 이들은 각 가로축의 첫번째 인덱스이므로, 해당 가로줄 배열에 접근할 수 있는 주소가 될 수 있다.

    // 따라서, str[0]. str[1]. str[2] 에 문자열을 받으면, 컴파일러는 첫 인덱스의 주소를 이용해
    // 각 배열의 주소로 차근차근 접근. 한 칸씩 글자를 넣어주는 것이다.

    // 이것이 y축의 라인 값(0번째 라인, 1번째 라인..) 만 인덱스로 지정해도 해당 열에 전체 문자열을
    // 넣을 수 있는 이유이다. 


    // 요약
    // 배열의 첫 인덱스는 해당 배열(한 가로줄)에 접근할 수 있는 주소이기도 하다.
    // 배열은 기본적으로 한 즐씩 출력된다
    // 이중 배열의 경우 해당 y축 의 숫자만을 기입.x축을 생략해서 써준 후 
    // arr[0],arr[1],arr[2] (3xnn 배열 가정) 에 std::Cin으로 문자열을 받아주면 된다.
    // 컴파일러는 각 가로줄의 첫 인덱스의 주소에 접근해서, 한 칸씩 입력받은 문자열을 배열에 입력하게 된다. 


    //** int형 정수는 이렇게 "123352" 한번에 넣는게 불가능하다.
    // 하드코딩밖에 방법이 없다! 


    // *int 형 배열
    // - 일차원 배열
    // std::cin>>arr: 안됨
    // std::cin>>arr[0] : 해당 인덱스에만 들어감. 
    // std::cin>>arr[0]>>arr[1] .. : 각 인덱스에 값 대입

    // 요약: int형 배열은 for문 돌리는게 빠름
    // - 2차원도 동일 

    // *char형 배열
    // - 일차원 배열
    // std::cin>>arr: 됨! >> arr 그 가로줄의 주소를 들고 있기 때문
    // std::cin>>arr[0] : 해당 인덱스에만 들어감. 길게 입력해도 제일 앞글자만. 

    // 요약: arr, 인덱스 없이 배열 이름만. 

    // - 이차원 배열
    // **한줄씩 입력하기
    // std::cin>>arr[0]>>arr[1] : 됨. 한 줄씩 입력된다.
    // std::cin>>arr : 안됨

    // 요약; arr[0]. arr[1] == 해당 y축의 가로줄에 해당. 


    //**삼차원 배열 >> 삼중 포문으로 초기화할 수 있다.
    // int arr[n][2][2] = {}; 
    // >> 이건 이차원배열 [2][2] 을 n개 만든다는 뜻. 

    return 0; 
}

