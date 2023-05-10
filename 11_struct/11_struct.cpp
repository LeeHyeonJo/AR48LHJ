// 11_struct.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 구조체 (사용자 정의 자료형 중 대표) - 클래스와 유사하다. 

#include <iostream>

// 사용자 정의 자료형 - struct의 정의방법 
// 구조체의 특징: 기본 접근제한 지정자가 public. 
// 숙제: player. best 생성 > 내부 변수 접근 > 접근제한 지정자 디폴트/퍼블/프베 걸고 테스트. 
    // C++11 미만에선 구조체에선 퍼블/프라를 걸 수 없음. 지금은 걸 수 있음.
    // 아직은 클래스와의 차이가 미미함. 

// 주로 쓰는 거: 쉽게 접근해서 써야하는 데이터(ex. 수학 등) 

struct player
{
    int hp;
    int mp;
    int att;
    int def;

};

// 클래스 맛보기
// 클래스의 특징: 기본접근제한 지정자가 private. 
// 숙제: player1. best 생성 > 내부 변수 접근 > 접근제한 지정자 디폴트/퍼블/프베 걸고 테스트. 
// 주로 쓰는 거: 보안이 중요한 데이터(캡슐화..) 

class player1
{
public:
    int hp;
    int mp;

private:
    int att;
    int def;
};


int main()
{
    // 예시: 플레이어를 만든다.
    // 플레이어가 늘어날떄마다 이 4줄을 다 복붙해야한다.
    // >> 이게 번거로우므로, 사용자 정의 자료형을 설계해서 써보자. 

    //int playerhp;
    //int playermp;
    //int playeratt;
    //int playerdef;

    // 2. 자료형 player의 사용법
    // 숙제: 메모리의 그림 그려가며 파악하기 
    // [4바이트 hp][4바이트 mp][4바이트 att][4바이트 def] = 16바이트 

    player archer;
    player caster;
    // 3. 자료형 player 내부의 변수(메모리)에 접근하는 법
    caster.mp = 100; //.변수 이름. 꺼내쓰거나 대입하는 것도 가능하다. 


    // 구조체를 쓰는 이유
    // 1. 여러 변수를 묶은 형태로 그룹화 하고 싶을떄.
    // 2. 특정 상황에서 소스코드를 보다 간결하게 표현 가능
    // 3. 

    return 0;
}
