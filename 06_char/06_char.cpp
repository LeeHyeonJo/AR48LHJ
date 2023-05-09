// 06_char.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 문자 (문자열은 아직) 

#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; // 긴 문자는 "" 큰따옴표 

    char ch = 'A'; // 한 글자는 '' 작은 따옴표 (알파벳만) - 한글이 안되는 이유는 나중에. 
    std::cout << ch; // ch가 char형 변수이기 때문에 ch만 입력해도 알아서 A로 치환해줌 

    // printf 는 치환자가 필요함. C언어 스타일. 올드하다 
    // printf("%d",ch); 이런식 


    // 캐릭터형 배열의 문법. 초기화는 중괄호로 동일하다. 
    // str은 단순한 이름임. 
    char str[5] = { 'A','A', 'A', 'A', 'A' };

    return 0; 

    // 0에 대하여 
    // 0 NULL nullptr '\0' -> 값은 전부 0이다.
    
    // 다 같은 0이지만, 가독성의 차이가 생긴다.
    // 상단처럼 쓰면 변수의 자료형의 유추가 가능하다. 
    char ch = '\0';
    void* p = nullptr;
    int data = NULL;
    int num = 0; 

    // 아래와 동일 
    char ch = 0;
    void* p = 0;
    int data = 0;
    int num = 0;
}


