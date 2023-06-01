// 21.5_LinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 노드2: 가장 끝에 노드 추가(하단 꼬리부) 2가지 방법 학습하기 
// 0601: 전면부에 노드 추가하는 법 학습 

#include <iostream>
using namespace std;

struct Node
{
	char ch;
	Node* pNext; // Node형 포인터. pNext는 구조체 Node 자체의 주소를 갖고 있다. 
	// 다음 노드에 접근하기 위해 사용한다. (n1 구조체에 포함된 변수 pNext는 n2 "자체"의 주소를 갖고 있다.) 
};


Node* head = nullptr;
Node* tail = nullptr;

// ** 노드의 추가 ** 
// 개념: 노드 (데이터를 저장하는 한 덩이) 는 메모리를 "동적 할당" 하므로 프로그램 실행 도중에도 자유롭게 추가하거나 삭제할 수 있다.
// 일반적으로 노드는 가장 끝 노드, 그 다음에 생성된다. (삭제는 자유자재) 

//						 <0x07>					  <0x08>						<0x09>
// 원리:  (n1)[ch=A, pNex=0x08] → (n2)[ch=B, pNext=0x09] → (n3)[ch=C, pNext=nullptr]  → << 여기에 새로운 노드 추가! >> 
//					 ↑
//			 <Node* head = &n1>  : 가장 첫 노드인 n1을 가리키는 (= n1의 주솟값 0x07 갖고있음) 

// 이러한 노드가 있다고 가정. 노드는 일반적으로 가장 뒤에 새롭게 생성된다. (꼬리물기) 
// 노드가 추가되기 위해서는, 그 다음 노드가 할당되지 않은. 즉 pNext로 접근할 수 있는 노드가 없는, 다시 말해 
// 다음 노드로 접근하는걸 돕는 포인터 변수 pNext가 nullptr인 노드를 찾아야 한다. (그래야 그 뒤에 붙으니까) 

// 가장 꼬리에 있는 노드 ( = pNext값이 nullptr인 노드)를 찾는 방법은 두가지가 있다. 

// 1. 노드를 반복문을 돌면서, pNext == nullptr인 노드를 찾는다. 그 노드의 pNext에 새로운 노드를 연결해준다. 
// 2. 처음부터 head 선언 시 tail을 추가해, tail의 pNext를 nullptr에서 연결해줄 새로운 노드로 바꾼다 (&n4) 

// >> 이것을 AddNode 함수로 구현. 
// >> 목적: main 에서 AddNode(data) 를 선언시, heap에 노드 1개를 동적할당으로 생성하고, 그 노드의 멤버 변수에 입력받은 data값을 넣어준다. 


void AddNode(char data)
{
	if (head == nullptr)
	{
		/* Node* */ head = new Node(); // 포인터 변수이름 = new 자료형;
		// 왜 Node; 가 아니라 Node(); 지? >> Node(); 는 생성자를 의미함. 생성자의 크기만큼 heap에 할당하는 것. 
		// 생성자의 크기만큼 할당한다는 것을 명시하기 위해 ();를 붙인다. 생략해도 문제는 없다. 
		// Node 형의 포인터 변수 head이므로, head = new Node(); 
		// 의미: Node()의 크기만큼 Heap 메모리를 동적할당. 리턴 받은 주소값을 head에 저장. 
		// 예시: int* ptr = new int; 
		// 과정: int 타입의 포인터 변수 ptr을 먼저 선언. (int* ptr = nullptr;)
		// 그 변수 ptr에 int의 크기(4바이트)만큼 heap을 동적할당 후, 리턴한 heap의 주소값을 저장. 
		
		
		head->ch = data; //(*head).ch = data; 와 동일 
		head->pNext = nullptr;

		tail = head;
	}

	else
	{
		// 1. 반복문 돌면서 노드 추가하는 방식
		//Node* p = head; (Node 타입 포인터변수 p를 하나 생성해줌) 
		// ㄴ 풀이: head 값을 대입한 이유 >> 그래야 n1부터 검사가 가능하기 때문. (p가 n1을 가리키면 n2부터 검사하게 됨) 
		// ㄴ head를 가리키는게 아님!!!!! head를 대체하는 새로운 리모컨이라고 생각하기. 

		//while (true)
		//{
		// 
		//	if (p->pNext == nullptr) // 풀이: p->pNext == (*p).pNext == head.pNext == n1 자체의 주소 
		//		{
		//			break; // 풀이: p->pNext == (*p).pNext == head.pNext == n1 자체의 주소, 거기가 null이라면 while문 종료(null node찾은거니까)
		//		}
		// 
		// ** 풀이: nullptr이 아닌 경우, p는 다음 노드를 검사해야 함. 
		// 
		//	p = p->pNext; // 새로운 리모컨 p로 n1을 검사했음. 이제 다음 node로 넘어가기 위해선, n2의 주소값이 필요
		//					// p = (*p).pNext ==> p = p->pNext;  이 형태가 된다. 
		// 
		//}


		// 반복문으로 null값을 가진 node(가장 끝)을 찾은 후. 
		// 그 뒤에 새로운 node를 생성해준다. 

		//p->pNext = new Node(); // (*p).pNext 에는 (= n1의 pNext 값), heap에 node크기의 메모리를 동적할당(new)한 후, 리턴된 주소값이 대입된다. // 만든 동시에 연결 
		//p->pNext->ch = data; // 생성된 노드(n2)의 멤버변수에 data를 넣어준다. 
		//p->pNext->pNext = nullptr; // 생성된 노드(n2)의 pNext 에 nullptr(마지막이니까) 를 넣어준다. 

		// 2. tail을 이용한 노드추가
		tail->pNext = new Node();
		tail->pNext->ch = data;
		tail->pNext->pNext = nullptr;
		// tail을 새롭게 생성된 노드쪽으로 옮겨준다. 
		tail = tail->pNext;
	}
}


int main()
{   // 예시: 새로운 노드를 추가하고, 거기에  data 값을 C, A, D를 넣어주려고 한다. (노드 1개당 하나씩) 
	AddNode('C');
	AddNode('A');
	AddNode('D');

	return 0;
}

