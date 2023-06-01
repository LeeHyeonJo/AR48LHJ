﻿// 21_LinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 자료구조-리스트 연습
// 노드 줄이기 & 노드 뒤에 추가하기 (두가지 방법 - 반복문 / tail 기법) 
// 0601: 전면에 노드 추가하는 법 

#include <iostream>

// ** 자료구조 **
// 정의: 데이터(자료)를 저장하는 방법. 내가 만들 기능(프로그램)에 적합한 자료구조를 사용하면 된다.
// 대표적인 종류: 배열(DAT), 링크드 리스트(리스트), 큐, 스택, 그래프, 트리


// <링크드 리스트>
// 중간에 데이터가 삭제 또는 삽입이
// 자주 일어날떄 링크드리스트를 활용하면
// 속도에서 이점이 생긴다.

// 1. 링크드 리스트(Linked list)
// 장점: 중간에 데이터가 삭제 or 삽입이 자주 일어날때, 링크드 리스트를 활용하면 속도에 이점이 생긴다.
// 링크드 리스트는 배열과 달리 데이터 삭제/삽입이 용이하기 때문. (포인터로 접근하므로 주소를 연결/끊어주면 됨) 


// ** 노드(node) **
// 정의: 자료구조에서 자료를 저장하는 최소 단위. 
// 배열에서의 노드는 각 칸을 의미한다. [] [] [] [] 하나하나가 노드. 
// 링크드 리스트에서 노드는 각 데이터가 "하나" 들어있는 메모리를 의미한다. 

// 배열 VS 링크드 리스트
// 배열은 실행도중에 노드수를 늘리수 없다.
// 링크드리스트는 실행 도중에 노드를 계속 추가할수 있다.

// 배열과 링크드 리스트의 비교 
// 배열: 실행 도중 노드([] [] 이 칸) 수를 늘릴 수 없다. 메모리를 정적으로 할당하기 때문. (ex. 이름짓기 글자수 제한) 
// 링크드 리스트: 실행 도중에 노드를 추가할 수 있다. 메모리를 동적으로 할당하기 때문. (ex. 이름짓기 글자수 제한 없음) 

struct Node
{
	char ch;
	Node* pNext; // Node형 포인터. pNext는 구조체 Node 자체의 주소를 갖고 있다. 
	// 다음 노드에 접근하기 위해 사용한다. (n1 구조체에 포함된 변수 pNext는 n2 "자체"의 주소를 갖고 있다.) 
};

// ** head 란 무엇인가? **

// 구조체 Node의 객체를 n1,n2,n3 3개 만든다. 
// n1(ch = A / pNext = ) : n1의 주소 - 0x07
// n2(ch = B / pNext = ) : n2의 주소 - 0x08
// n3(ch = C / pNext = ) : n3의 주소 - 0x09

// 편의상 이렇게 3개가 있다고 가정한다. 

// n1(ch = A / pNext = 0x08 ) : n1의 주소 - 0x07
// n2(ch = B / pNext = 0x09) : n2의 주소 - 0x08
// n3(ch = C / pNext = nullptr) : n3의 주소 - 0x09

// n1은 n2를, n2는 n3을. n3은 마지막 노드이므로 자신의 다음 노드는 없다는 의미로 nullptr를 가리킨다.
// 하지만 제일 첫 노드인 n1에 접근할 방법이 존재하지 않는다.
// 제일 첫 노드의 주소를 알면, 해당 노드와 연결되어있는 노드들(n2,n3)에 접근할 수 있다.

// >> 따라서 head라는 이름의 포인터 변수를 선언. 
// >> head라는 포인터 변수가 "가장 첫 노드"를 가리키게 만들어, 결과적으로 모든 노드에 접근할 수 있도록 하는 것이다.

// 즉 노드들은 연결된 TV이며, head는 리모컨으로 가장 첫번째 TV를 조작하는 것이라고 생각하면 된다. 

// ** head의 사용법 **
// 문법: 구조체이름* head = nullptr; 

// ** 구조체이름*( 예시: Node*)를 자료형으로 사용하는 이유
// 예시에서 Node* pNext;. 구조체 이름을 자료형으로 사용하는 포인터 변수는, 해당 구조체(객체) "자체"를 가리키게 된다.
// head는 구조체 struct Node에서 생성된 객체(변수) n1을 가리켜야하는 포인터 변수이다.
// Node n1; 은 내부에 멤버변수 n1.ch와 n1.pNext를 들고 있다.
// 그리고 포인터 변수의 자료형은, 받는 주소의 원 자료형 (ex. int k =10; int* ptr = &k;) 과 동일한 자료형을 사용해야한다.
// 즉, head가 가리켜야 할 메모리 (=받는 주소)의 자료형은 Node형이므로, 포인터 변수 head의 자료형은 Node* 가 된다.

Node* head = nullptr;

int main()
{

	// ------------------------------------------------------------------------- // 

	// <링크드 리스트의 기본 사용법>
	// ** 메모리 정적 할당의 경우 

	// 1. 우선 예시가 될 객체를 생성한다. n1 -> n2 -> n3로 연결할 것이다. 
	Node n1;
	Node n2;
	Node n3;

	// 2. 상단에  head를 선언&nullptr로 초기화한다. (변수 초기화와 동일)
	// Node* head = nullptr;
	// 그 후, head가 n1을 가리키도록 한다. 
	head = &n1;

	// 3. 구조체 변수 n1의 멤버변수에 값을 대입한다.
	// n1.pNext는 구조체 변수 n2 자체를 가리켜야 한다. 즉,n2의 주소를 가리켜야 한다. (=갖고있다) 
	// 동일하게 n2,n3도 진행해준다. (n2.pNext와 n3.pNext가 그 다음에 있는 구조체 변수(주소)를 가리키도록) 
	n1.ch = 'H';
	n1.pNext = &n2;

	// <역참조(*)를 이용해 다음 노드의 메모리에 접근하는 법> 
	// ** n1.pNext는 n2의 주소를 갖고 있다 (=가리키고 있다.) 
	// ** 그리고 n1.pNext도 포인터 변수이므로, *을 찍어서 갖고있는/가리키고 있는 주소의 원 메모리에 접근할 수 있다. 
	// 헷갈리지 말것:n1.pNext 까지가 포인터 변수인거임. 따라서 그 앞에 역참조 표시(괄호 반드시 사용) 
	// (*n1.pNext) == n2 그 자체
	// (*n1.pNext).ch == n2.ch == n2 내부에 있는 ch값 = E; 
		// 따라서 (*n1.pNext).ch == n2.ch == 'E'; 

	n2.ch = 'E';
	n2.pNext = &n3;

	// 3-1. 마지막 노드인 n3의 경우, 그 다음에 연결된 노드가 없으므로 
	// 가리켜야할 주소는 nullptr이 된다. (외우셈) 
	n3.ch = 'I';
	n3.pNext = nullptr;

	// ------------------------------------------------------------------------- // 

	// <링크드 리스트의 중간 데이터를 삭제하는 법> 
	// 원리: 리스트 방식으로 연결된 노드들은, 포인터 변수 n(숫자).pNext가 다음 노드를 가리키고 (=주소값을 갖고) 있다. 
	// 즉, 다음 노드에 접근할 주소를 "변경" 해주면 중간 데이터를 끊어낼 수 있다. 
	// 
	// 예시: n1.pNext = &n2 // n2.pNext = &n3 // n3.pNext = nullptr; 
	// 문제: 중간 데이터 n2를 삭제하려고 한다.
	// 방법: n2을 가리키는(=n2의 주소를 갖는) 포인터 변수 n1.pNext가, n2 대신 n3을 가리키면 (=주소값을 가지면) 된다. 
	// 변경 결과: n1.pNext = &n3 (n2,n3은 건드릴 필요 없음. 삭제할 데이터에 접근할 수 있는 포인터를 가진 노드에서 수정하면 됨) 
	// 이때 끊어진 n2는 "잃어버린 값" 이 된다. (접근할 방법이 없으므로) 
	// 간단하게 주소값을 변경하는 것으로, n1->n3으로 바로 이어지는 노드가 완성된다. 

	// ** 화살표(->)로 역참조 연산하기 ** 
	// 정의: 구조체를 가리키는 포인터 변수라면!! * 대신 화살표(->) 로 역참조를 나타낼 수 있다. 

	// 사용법: 예시로 Node.n1을 가리키고 있는 포인터 변수 Node* head를 사용한다. 
	// (*head).ch; == head->ch;  : 둘의 의미는 동일하다. 

	// 풀이: Node* head는 Node.n1을 가리키고 있는(= n1의 주소를 갖고 있는) 포인터 변수이다. 
	// 따라서 (*head) 이렇게 역참조를 하면, n1 그 자체(n1.ch & n1.pNext)를 의미하게 된다. 
	// n1의 멤버변수 n1.ch에 head로 접근하려면, (*head).ch; 의 형태가 된다. 
	// 이것이 너무 길기 때문에, "구조체 자체를 가리키는 포인터 변수라면(=멤버변수를 가리키는 것이 아님)" 
	// (*head).ch를 head->ch 로 축약할 수 있도록 정했다.
	// 따라서 ->의 의미는 (*)와 동일하다. head 주소가 가리키는 곳에 있는 멤버변수를 역참조하겠다는 의미로 쓰인다. 


	// ** ->와 . 덜 헷갈리는 방법 **
	// 1. ->의 사용처 
	// "구조체 자체" 를 가리키는(=구조체의 주소를 갖는) 포인터 변수라면, ->를 사용할 수 있다. 
	// 예시: head->ch == Node형 포인터 변수 head가 가리키는 노드(=갖고있는 주소), node.n1에 들어있는 멤버변수 ch를 참조. 

	// 2. *의 사용처 
	// "구조체 변수" 라면, .을 사용해서 참조한다. 
	// 예시: n1.ch == n1 노드에 들어있는 멤버변수 ch를 참조. 


	// ** 질문: 이 코드는?? 가장 마지막에 있는 노드(n3)에서 새로운 노드 생성
	// ** 새로운 노드에 멤버변수 채워주고, 새로운 노드의 pNext에 nullptr채워줌 
	// n3.pNext = new Node();
	// n3.pNext->ch = 'D';
	// n3.pNext->pNext = nullptr;

	return 0;
}

