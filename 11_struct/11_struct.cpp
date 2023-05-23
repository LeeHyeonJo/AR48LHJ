// 11_struct.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 구조체 (사용자 정의 자료형 중 대표) - 클래스와 유사하다. 

#include <iostream>

// 0. 구조체 struct의 특징 : 기본 접근 제한 지정자가 public. (확인함)

// C++11 미만에선 구조체에서 접근제한 지정자를 설정할 수 있음. 지금 버전은 가능. 
// class와 큰 차이는 없다. (아직까지는) 
// 주 사용처: 다수가 쉽게 접근해서 사용해야하는 데이터(ex. 게임 수학 등) 
// 숙제: player.saber 생성 > 내부 변수 접근 > 접근제한 지정자 디폴트/퍼블/프베 걸고 테스트. (확인함)

// ::구조체를 사용하는 이유::
// a. 여러 변수를 묶은 형태로 그룹화 하고 싶을때. 
// b. 특정 상황에서 소스코드를 보다 간결하게 표현 가능. 


// 1. struct(사용자 정의 자료형 중1) 문법 
struct player
{
public:
    int hp = 100;
    int mp = 200;
private:
    int att = 20;
    int def = 50;
};

// 0524: 구조체의 배열 
// 구조체의 객체는 배열로도 선언이 가능하다
// Player players[256] 
// player라는 구조체의 객체 players가 256개 생성된 상태. 
// ㄴ 전부 각각의 hp, mp등을 갖고 있다. 

// struct player의 메모리 사용상황
// [int hp][int mp][int att][int def] = 총합 16바이트  
// 객체 player 생성 시 player와 동일한 메모리가 생성되는건가?

// bonus. class에 대해 조금 
// 클래스의 특징: 기본 접근 제한 지정자가 private 
// 숙제: master.human 생성 > 내부 변수 접근 > 접근제한 지정자 디폴트/퍼블/프베 걸고 테스트. 
// 주로 쓰는 거: 보안이 중요한 데이터(캡슐화하고 함) 

class master
{
public:
    int magic = 1000;
private:
    int spell = 2000;
};


int main()
{
    //↓ 들어가며: player를 만들어보자.
    //↓ 필요한것 : player를 구성하는 hp,att,mp,def 변수 
    //↓ 아래처럼 작성시: 새로운 플레이어를 구현할 때마다, 매번 새로운 변수를 선언해야 한다. 

       //*player 1p
       //int playerhp;
       //int playeratt;
       //int playermp;
       //int playerdef; 

       //*player 2p
       //int playerhp2;
       //int playeratt2;
       //int playermp2;
       //int playerdef2;

   // ↓매번 이렇게 선언하긴 불편하다. 아예 처음부터 한 그룹에 선언해두고, 거기에서 매번 빼내와서 쓰면
   // ↓더욱 편리하지 않을까~ 하는 생각에 만들어진 것이 "사용자 정의 자료형" 이다.
   // ↓그 중 "구조체"에 대해서 학습해보도록 하자.

   //  ↑최상단으로 

       // 1-1. 구조체에서 객체 생성(p1.p2 생성임) 
       //구조체이름 객체 이름 ; (점 없음 공백) 

    player saber; // 구조체에서 객체 생성

    saber.hp // 


    player lancer;

    // 1-2. 생성한 객체 내부의 변수(메모리)에 접근하는 법
    //객체 이름.사용할변수; (점 찍으셈!!) 
    saber.hp = 10; //public이므로 접근 가능
    //saber.att = 5; //private이므로 접근 불가 

    //bonus. class 를 객체로 선언한 후, 내부의 변수에 접근해보기
    master human;
    master dog;

    human.magic = 10; // 기본 private이므로 접근이 불가능하다. (현재 가능하게 변경)
    //dog.spell = 5; // private를 걸어주었으므로 접근 불가능. 

    // f10으로 체크할 때, 접근이 불가능한 변수는 
    // 벽돌에 자물쇠가 걸린다! 

    return 0;
}