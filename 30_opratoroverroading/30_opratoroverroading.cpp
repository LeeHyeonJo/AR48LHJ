// 30_opratoroverroading.cpp : 오퍼레이터 "오 버 로 드" 
// 클래스에서 제공하는 편리한 기능. 안 써도 OK.

//API때는 직접 만들어서 사용해볼 것. 다렉때는 구현되어있는 함수를 사용. 

#include <iostream>

// 예시: 위치를 나타내는 구조체 pos 선언 
struct pos
{
	int x;
	int y; 

	// ** 연산자 오버로딩 예시(+) ** //
	// 문법적 예시: 함수처럼 사용하면 된다. 

	pos operator+(pos other) // (반환값의 자료형: pos sum 이니 pos) operator(내가 사용할 연산자)("우항을 인자로 받음")
		//      ㄴ + 기호는 내 마음대로 정할 수 있음 (별을 넣고 + 를 구현해도 됨) 
   //ㄴ 여기는 반환 값의 필요 여부에 따라 갈림. 	

		// pos sum = num1+num2; 
		// num1 은 이 struct pos 자체. num2는 void operator에 들어오는 인자가 됨
		// == pos other 에 num2가 들어간다는 뜻. 
	{
		pos result; // 이 연산자 함수 내부에서 계산 후 나온 결과값을 받아줄 변수 선언
		result.x = this->x + other.x; // x는 num1.x , other.x 는 num2.x 
		result.y = y + other.y; // y는 num1.y , other.y 는 num2.y 

		return result; // 합을 리턴해준다. 

		// ** 또는 this를 사용해도 된다.
		// ** this 는 자기 자신을 가리키는 값 (질문하기. 인자로 들어오는 값이 this가 아닌가?) 
	}
};

int main()
{
	pos num1{ 3,5 };
	pos num2{ 1,6 }; 

	// 두개의 위치를 합치려 하는 경우 
	int x = num1.x + num2.x;
	int y = num1.y + num2.y;
	// .. 이렇게 모두 전부 계산하는 건 너무 시간이 많이 걸린다.
	// 3+4 f라는 상수 계산처럼 간단하게,.
	// pos sum = num1 + num2; 로 표현하고 싶다
	// ㄴ 이것을 가능하게 하는 것이 "연산자 오버로딩" 이다. 

	// 원리: +에 오버로딩을 씌워서, pos 구조체 내부에선, num1+num2를 동작 가능하게 하겠다. 
	// ㄴ pos struct 내에 "함수처럼" 구현하는 것. 

	// 하단에서 + 연산자의 오버로딩의 작동여부를 확인해보자.
	// 상단에서 + 연산자의 오버로딩을 구현하면, 정상적으로 작동하는 것을 확인할 수 있다. 
	pos sum = num1 + num2; 
	// f11로 들어가는 과정을 확인할 것. 
}

