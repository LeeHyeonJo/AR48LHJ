// 21_LinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 0530: 노드 삭제, 화살표로 역참조, head
// 0531: 노드 추가(보통 제일 뒤), - 반복문 돌면서 추가 / tail(head 선언할때 같이) 다음에 추가 
// ㄴ 원리: 우선 구조체형 포인터 변수 head 선언 & 초기화 -> 어딘가에 만들어진 노드를 가리키게 함 (if문, head가 null일떄) 
// ㄴ 함수를 통해 head 뒤에 node가 추가되도록 함 (else문 내부: 이떄 노드는 동적할당) 
// ㄴ else 내부에서 두가지 방식 (1. 반복문으로 추가, tail로 추가) 

#include <iostream>

// 링크드 리스트
// 중간에 데이터가 삭제 또는 삽입이
// 자주 일어날떄 링크드리스트를 활용하면
// 속도에서 이점이 생긴다.

struct Node
{
	char ch;
	Node* pNext;
};

int main()
{
	Node* head = nullptr;

	Node n1;
	Node n2;
	Node n3;

	head = &n1;

	n1.ch = 'H';
	n1.pNext = &n2;

	//(*n1.pNext).ch = 'e';

	n2.ch = 'e';
	n2.pNext = &n3;

	n3.ch = 'l';
	//n3.pNext = nullptr;

	// 중간 데이터 삭제하는 코드
	//n1.pNext = &n3;

	// 화살표로 역참조 연산을 간단하게 사용할수
	// 있다.
	//std::cout << (*head).ch;
	//std::cout << head->ch;

	// -> 과 . 덜 헷갈리는 방법
	// 만약 구조체를 가리키는 포인터라면
	// 고민없이 화살표를 쓰면된다.
	//std::cout << head->ch;

	// 구조체 변수 자체라면
	// 고민없이 .을쓰면 된다.
	//Node noode;
	//noode.ch = 'A';

	std::cout << head->pNext->pNext->ch;

	return 0;
}

