// 22.5_stack(구현).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 자료구조: 스텍 - 접시쌓기 (들어오는 순서대로 넣어주고, 가장 나중에 들어온거부터 빠지는 방식) 
// 문제를 풀기 위해 클래스를 설계하는 연습을 해야 함. 

// 하는 것: 생성자에서 구조체의 멤버변수를 초기화.
// 1,2,3 의 값을 PUSH 함수로  넣어주고. TOP 함수로 가장 위의 값을불러냄. 그 후 pop 함수로 가장 윗값을 지우기

// **스택을 링크드 리스트로 구현한 예시. 

#include <iostream>
using namespace std; 

// ** 스택을 사용해보자 **  
// 노드(데이터 저장 덩어리) 를 stack 형식으로 구현한 것 

struct stack
{
public:
	struct node // 이너 클래스 
	{
		node() // 1. node 생성자 호출 (node 내부의 변수를 초기화) 
			:data(0)
			, next(nullptr)
			, prev(nullptr) 
		{

		}

		int data; // 단점: char 형 등 다른 자료형을 구혀하고 싶다면...~ 
		// char ch; 이렇게 넣어주면 되지만

		// 그럼 push 함수가 int 형, char형 각각 따로따로 추가도게 된다. 

		node* prev;// tail 앞의 노드를 가리키는 포인터 변수 (pop - 가장 윗값을 지우는 함수에서 사용)
		node* next;
	}; // 여기까지 앞에서 쭉 해온 노드 구현 

	//2. stack의 생성자 호출 (스택 내부에서 쓸 변수들 초기화) 
	stack()
		: mhead(nullptr)
		, mtail(nullptr)
	{

	}

	// 3. push 함수: 노드를 스택 방식으로 추가해주는 함수 
	void push(int num)
	{
		if (mhead == nullptr) // 첫 스텍 생성
		{
			mhead = new node();
			mhead->data - num;
			mhead->prev = nullptr; // 이거 잘 익혀두가 
			mhead->next = nullptr;
			mtail = mhead;
		}

		else // 다음 스텍 생성
		{
			mtail->next = new node();
			mtail->next->data = num;

			// 테일을 끝으로 넘기기 전, 그 테일을 프리브에 연결
			mtail->next->prev = mtail;
			mtail->next->next = nullptr; // 마지막 노드에 널값

			// 테일 이동
			mtail = mtail->next;


		}
	}

	void pop() // 맨 위의 스텍을 지우는 함수 
	{
		node* last = mtail; // 새로운 리모컨을 추가.

		mtail = mtail->prev; // 테일은 테일 바로 앞의 값을 가리키는 프리브로 연결
		mtail->next = nullptr; // 이동 후 n3에연결되어있던 것을 해제 

		delete last; // 리모컨 다 썼으니 할당 해제
		last = nullptr; // 해제 후 쓰레기값 안 들어가게 null값 넣어주기 
	}

	int top() // 맨 위의 스택 값을 불러오는 함수 
	{
		return mtail->data; 
	}

private:
	node* mhead;
	node* mtail; // 스택용 
};

int main()
{
	stack stack1; 

	stack1.push(1);
	stack1.push(2);
	stack1.push(3);

	int top = stack1.top(); 
	stack.pop();

	return 0; 

}