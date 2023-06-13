// 0.BFS(큐) 연습.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 3번 복습함. 돌아가는 원리, 그려가면서 이해하기. 

#include <iostream>
#include <queue> // 큐를 사용하기 위함. 

// 이게 큐 구현 원리 
//template <typename T>
//class Queue
//{
//public:
//    Queue()
//        : mDatas{-1, -1,}
//        , mFront(0)
//        , mEnd(0)
//    {
//
//    }
//
//    void Push(T data)
//    {
//        mDatas[mEnd] = data;
//        mEnd++;
//    }
//
//    T Pop()
//    {
//        return mDatas[mFront++];
//    }
//
//private:
//    T mDatas[256];
//    int mFront;
//    int mEnd;
//};


// 그래프 탐색할떄 노드가 사용됬는지
// 체크해주는 배열
int used[256] = {};

int bfsMatrix[6][6] =
{
	0,1,1,0,0,0,
	0,0,0,1,1,0,
	0,0,0,0,0,1,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
};
// 그래프를 그리고 시작. 


struct Node
{
	int num;
	int level;
};


int main()
{
	std::queue<Node> queue;
	queue.push(Node({ 0,0 }));

	while (!queue.empty())
	{
		Node p = queue.front();
		std::cout << p.num << " ";

		for (int i = 0; i < 6; i++)
		{
			if (bfsMatrix[p.num][i] == 1
			  	&& used[i] == 0)
			{
				used[i] = 1;
 				queue.push(Node{ i, p.level + 1 });
			}
		}
		queue.pop();
	}
	
}

//std::queue<Node2> queue;
// queue<Node2> : 여기까지가 자료형
// queue뒤의 큐는 변수. n1 같은거. 

///*이진트리 dfs로 푸는 문제*///
// char binaryTree[256] = "_ABCDEFG";
// 
//void dfs(int level)
//{
//	if (binaryTree[level] == '\0')
//	{
//		return;
//	}
//
//	dfs(level * 2);
//	dfs(level * 2 + 1);
//}

//int* p = new int[num2];


///*레벨 29의 이진트리(7번)를 BFS로 푸는 문제*///
// ** 이건 틀린 풀이!! 내가 한 방법이 맞다!! ** 
// int main
// {
//std::queue<Node2> queue;
//queue.push(Node2({ 1,0 }));
//
//while (!queue.empty())
//{
//	Node2 p = queue.front();
//	std::cout << binaryTree[p.idx] << " ";
//
//	if (binaryTree[p.idx * 2] != '\0')
//	{
//		queue.push(Node2{ p.idx * 2 , p.level + 1 });
//	}
//	if (binaryTree[p.idx * 2 + 1] != '\0')
//	{
//		queue.push(Node2{ p.idx * 2 + 1 , p.level + 1 });
//	}
//
//	queue.pop();
//}