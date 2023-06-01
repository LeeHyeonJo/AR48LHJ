// 24_memberfunction.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 멤버 함수! 

#include <iostream>

struct player
{
	int hp;

	player()
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
void damaged(player* player)
{
	player->hp -= 10; 
}

int main()
{
	player p1; 

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

