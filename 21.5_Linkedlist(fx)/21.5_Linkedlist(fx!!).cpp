// 21.5_LinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 노드를 앞에 추가하기 (푸시 프론트) / 노드를 뒤에 추가하기 (푸시 백) 
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

// ** 노드 추가는 1. 제일 앞에 / 2. 제일 뒤에 할 수 있다.
// Addnode => push_back으로 이름 변경. 

//** 1. 제일 앞에 노드 추가하는 법(푸쉬 프론트) 
void push_front(char data)
{
	Node* temp = new Node(); // 새로운 리모컨을 만든 후, 거기에 뉴 노드를 생성. 리턴되는 주소를 연결해준다. 
	temp->ch = data; // 뉴 노드에 temp로 접근해 값을 넣어준다 
	temp->pNext = head; // ** 중요! 뉴 노드는 n1 앞에 연결되어야 함. pNext는 n1으로 가는 주소를 가져야 함.
						//이 주소는 head에 있으므로 head값을 대입하면 된다. 

	// 그 다음!! head는 항상 앞의 값을 가르켜야 한다. n1 앞에 뉴노드가 들어왔으므로 head도 뉴 노드를 가르켜야 한다. 
	head = temp; // 뉴 노드의 주소를 갖고있는건 temp이므로 그 값을 head에 넣어준다. 
}

//** 2. 가장 뒤에 노드 추가하는 법(푸쉬백: 이름만 바꾼거임) 
void push_back(char data)
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
		tail->pNext = new Node(); // = n1의 pNext가(= tail->pNext) 새롭게 할당된 노드(n2) 자체의 주소를 받도록. (연결)
		tail->pNext->ch = data; // tail->pNext-> 이게 n2를 역참조 
		tail->pNext->pNext = nullptr;
		// tail을 새롭게 생성된 노드쪽으로 옮겨준다. 
		tail = tail->pNext;
		// tail이 n2를 가리켜야 함. n2의 주소는 n1 pNext에 저장되어있음. 
	}
}

// ** 노드 지우는 방법 (new - delete)
// 이유: 동적할당한 메모리는 지워주지 않으면 프로그램이 종료될 때까지 계속 남아있다.
// 이 낭비를 막기 위해서, 동적 할당한 메모리는 사용 후 항상 지워주어야 한다. (반납하는 개념) 
 
void DeleteNode(char data) // 뜻: 들어온 데이터에 해당하는 노드를 지운다. 
{
	Node* pNode = head; // 새로운 리모컨 추가 . for문에서 i 역할 (노드 돌면서 data가 있는 노드를 찾는 역할)  
	Node* prevNode = head; // 새로운 리모컨 추가 (목적: 지워지는 노드의 "앞" 노드 기억하는 목적) 

	/// 1. 지워야 하는 노드가 제일 앞일때 
	if (pNode->ch == data) // 노드가 가리킨 것이, 헤드와 동일하다면(=들어온 데이터 값이 n1에 있는지 여부 체크용) 
	{
		head = pNode->pNext; // 헤드를 n1에서 n2로 연결시켜버린다. 

		delete pNode; // 새로운 리모컨을 지워준다(반납) 
		pNode = nullptr; // 지운 후 nullptr값을 넣어준다. (반납 후 null값 넣는것까지가 세트) 

		return; 
	}
	/// 2. 지워야 하는 노드가 중간~끝에 있을 때
	for(/*pNode의 정의는 이미 위에 해서 생략 가능!*/; pNode->pNext != nullptr;    pNode = pNode->pNext)
		//pNode가 nullptr을 가리키지 않을떄만 돌기 ; 증감식은 pNode = pNode->next :다음 노드로 이동)
	{
		if (pNode->ch == data) // 노드가 가리킨 값에 지워야 할 값이 들어있으면
			// 이 조건을 충족할떄 pnode는 data 노드에, prev는 바로 앞 노드에 위치하기 된다. (for문 돈 결과) 
		{
			prevNode->pNext = pNode->pNext; //A 노드 바로 앞에 연결된 prevnode를 A뒤의 노드와 연결시켜주는 과정 
			//A노드로 가는 값 //B노드로 가는 값   // ㅁ -> A - > B  ~~~~ ㅁ->B 이렇게 

			delete pNode; // data가 들어있는 노드를찾던 리모컨을 반납 
			pNode = nullptr; // 그 노드값청소 

			delete prevNode; // 리모컨을 반납 
			prevNode = nullptr; // 그 노드값청소 

			break; 
		}

		prevNode = pNode; 
	}


}

int main()
{   // 예시: 새로운 노드를 추가하고, 거기에  data 값을 C, A, D를 넣어주려고 한다. (노드 1개당 하나씩) 
	// 1. 뒤에 노드 추가 
	push_back('C'); 
	push_back('A');
	push_back('D');

	//2. 앞에 노드 추가 
	push_front('F');

	// 3. 노드 삭제 
	DeleteNode('A');

	return 0;
}

