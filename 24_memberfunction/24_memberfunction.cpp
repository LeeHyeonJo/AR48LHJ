// 24_memberfunction.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 멤버 함수! : 필기 옮기기 

#include <iostream>

struct player1
{
	int hp;

	player1()
		: hp(100)
	{
		// 생성자. hp를 이니셜라이저 중
	}

	// 보완된 방식:: 멤버함수 
	void damaged()
	{
		hp -= 10; 
	}

};

// 이전의 방법: 넣어준 player의 hp값을 깎아준다. 
void damaged(player1* player)
{
	player->hp -= 10; 
}

int main()
{
	player1 p1; 

	damaged(&p1); // 입력ㄷ받은 플레이어의 hp를 깎아주는 함수 

	// 이 방식의 단점 : 객체가 늘어나면 함수를 계속 추가해야 함//
	// >> 이것을 보안하기 위해 등장한 문법이 "멤버 함수" 
	// 구조체 내부에서 함수를 선언 후 사용한다. 


	//C스타일에선 멤버함수가 없었고, 새로운 객체의 값을 바꿔주려고 할 떄마다
	// damaged(&p1) damaged(&p2)damaged(&p3) 전부 호출해줘야했음.

	//**멤버함수의 원리: this 함수 
	// C++에선 이걸 .. 함수를 하나만 쓰고 싶었음. 그래서 전역변수로 쓰던 함수를 구조체에 넣어주고.
	// 구조체로 들어간 함수(멤버함수) 가 인자(p1,p2,p3)를 받을때, 
	// archer.player 이렇게만 작성해도. archer을 넘겨도, 자동으로 생성된 this에 archer의 주소가 들어가게해줌.
	// >> 멤버함수 하나로, this 포인터 변수 덕분에 들어오는 모든 인자들 각자에 접근할 수 있게 된거임. 

}



// ** 객체지향적 프로그래밍 **
// 정의:함수 먼저(동작먼저). 그 다음에 변수 작성하기. 
// 예시: 몬스터와 플레이어가 서로를 공격하고 대미지를 입는 프로그램 구현하기. 

class player // 기본이 private
{
	// 1. 플레이어의 동작(함수)를 구현한다.
	// 파이어볼을 발사할 수 있다. 
	void fireball(monster* monster)
	{

	}

	// 달릴 수 있다.
	void run(monster* monster)
	{

	}

	// 2. 1의 함수에 필요한 변수들을 작성한다. 

	int speed;
	int mp;
};


struct monster // 기본이 public
{
	// 1. 몬스터가 플레이어의 공격을 받는다 
	void damaged(player* player)
	{

	}

	// 2. 몬스터가 플레이어를 공격
	void damaged(player* player)
	{

	}

	// 3. 1,2 번 함수에 필요한 변수 작성

	int att;
	int hp;
};

