﻿// 26.5_tree(BFS).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 사용 이유: 그래프/트리를 탐색하는데 dfs 만으로는 시간적 소요가 크다. 
// 그래프/ 트리으 ㅣ연결상태에 따라 dfs보다 빠른 속도로 탐색하기 위해 bfs를 사용한다. 

#include <iostream>
#include <queue> // 큐만 라이브러리 해제 

// ** 깊이우선 탐색(dfs)
// 모든 노드를 탐색할때 bfs보다 빠르다.
// 구현 소스코드가 짧다.
// 구현 난이도는 높다 (재귀함수 사용) 

// ** 너비 우선 탐색(bfs)
// 최소 level (위쪽) 에 있는 노드를 찾아야 할 때, dfs보다 더 빠른 속도가 난다
// 이해하기는 쉽지만, 구현해야할 소스코드가 더 길다. 

//
//template <typename t> // 일단 선언, 타입 네임(그릇으로 쓸거) 
//class qu
//{
//public:
//    qu()
//        : mdata{-1,-1}, // 배열을 생성자에서 초기화할때는 {} 이렇게. 
//        mfrontindex(-1), // 배열의 가장 앞 인덱스 이용해서 가장 앞의 값을 불러오고, 가장 앞의 값을 해제함. 
//        mendindex(-1) // 배열의 가장 뒤 인덱스를 이용해서 node 추가를 구현함. 
//    {
//         0. 생성자에서 클래스 qu의 멤버 변수들 초기화. (멤버 이니셜라이저)  
//    }
//
//    void push(t data) // 1. 배열 맨 뒤에 데이터가 들어오는 함수 
//         들어오는 데이터의 자료형을 템플릿으로 구현했으므로, 자료형은 t
//    {
//        mdata[mendindex] = data;
//        mendindex++;
//    }
//
//    t tpop() // 2. 배열 맨 앞의 데이터를 리턴 & 맨 앞의 데이터를 해제(원리: froint index 한칸 이동) //top+pop
//         들어오는 데이터의 자료형을 템플릿으로 구현했으므로, 자료형은 t
//    {
//        return mdata[mfrontindex++];
//         우선 맨 앞의 데이터를 리턴한 후
//         후위연산자를 이용해, frontindex를 한 칸 우측으로 옮겨줌. 
//    }
//
//private:
//    t mdata[256];
//    int mfrontindex; // 배열의 제일 앞을 가리키는 인덱스 
//    int memdindex; // 배열의 제일 뒤를 기리키는 인덱스 
//};

// 1. 탐색할 그래프를 그린다. 
// 1
// [E]
// 
//  1    2 : 1의 자식  좌/ 우
// [A]  [U]
// 
// 3    4    5  
// [R] [Q]  [Y] 

int bfsmatrix[6][6] = 
{
    0,1,1,0,0,0,
    0,0,0,1,1,0,
    0,0,0,0,0,1,
    0,0,0,0,0,0,
    0,0,0,0,0,0,
};     
// ㄴ 노트필기 그림 참고 

// 2. 노드를 만든다

struct node
{
    int num; // 노드 구성체들 번호 
    int level; // 가로로 긋는 레벨의 번호기억함

};

int main()
{
    std::queue<node> queue;0
    queue.push(node{ 0,0 }); // 이게 큐 함수 기본 사용 법 
    int used[234] = {}; // 중복 체크용 배열 

    while (!queue.empty()) // 큐가 비어있지 않을때까지 이짓을 반복 
    {
        ///// 이것을
        node p = queue.front(); // p에 큐의 가장 앞 값을 넣는다  // 10라인에서 큐가 빠지므로, 그 다음 노드가 p에 들어감 
        // queue에 값이 잘 들어가고 있는지, p를 통해서 확인 가능
        std::cout << p.num << " ";

        // 배열 돌면서 갈 수 있는 구간 체크 
        for (int i = 0; i < 6; i++)
        {
            if (bfsmatrix[p.num][i] == 1 && used[i] == 0)
                // [p. num] = 가장 처음인 E에서, E,A,U,R,Q,Y로 갈 수 있는 루트 서치. 
                // used[i] 중복 순회를 막기 위해 넣어준 조건 
            {
                used[i] == 1; // 중복체크용
                queue.push(node{ i, p.level + 1 }); // 돌면서 큐에. 그린 그래프의 순서대로 데이터를 넣어줌 
                //노드의 번호(순서) & 노드가 그래프에 위치한 레벨  *** 그래프 그리면서 체크해보기 . 
            }
        }
        queue.pop(); // 가장 앞에 있는 큐를 빼줌 (삭제) 
        /// 이것을  
    }

    // 한 것: 결과적으로, 트리를 가로형태로 큐에 저장해주었다가, 앞에서부터 하나씩 빼내며 검사한 형태가 된다. 

    // 실 사용처: 게임에서 길 찾을떄. (A*: 에이스타 이 방식이 더 보편적) 
    // 게임의 형태에 따라서 취사선택해야함 (간단한 게임은 BFS, 큰 게임은 에이스타) 




    /// ** 길찾기를 BFS에 활용해보기 
    struct maze
    {
        int x;
        int y;
    };

    int map[3][4] = {}; 
    std::queue<maze> mazequeue; 
    maze.push(maze)

    // 길찾기는 내 기준으로 좌우상하, 4개를 채크해도 된다. 
    // 다이렉트로 방향 체크.
     // ㄴ x,y 반대인 이유 
        // 맵 밖으로 나가지 않게 예외처리. 
        // 갈 수 있는 좌표만 큐에 저장하는 중 

        // 도착 - 출발지점까지 1로 채워가면서 찾아가는 것

        // 도착 좌표가 필요한 곳에 if 문 걸고 찾을 것 


            //길찾기 BFS
        struct MazeNode
    {
        int x;
        int y;
    };

    int map[3][4] = {};
    std::queue<MazeNode> mazeQueue;
    mazeQueue.push(MazeNode({ 0,2 }));

    int direct[4][2] =
    {
        0,-1,
        1,0,
        0,1,
        -1,0,
    };

    while (!mazeQueue.empty())
    {
        MazeNode p = mazeQueue.front();
        map[p.y][p.x] = 1;

        if (p.x == 3 && p.y == 0)
        {
            // 찾았다.
        }

        for (size_t i = 0; i < 4; i++)
        {
            int newX = p.x + direct[i][0];
            int newY = p.y + direct[i][1];

            if (map[newY][newX] == 1)
                continue;
            if (newX < 0 || newY < 0)
                continue;
            if (newX >= 4 || newY >= 3)
                continue;

            mazeQueue.push(MazeNode({ newX , newY }));

        }

        mazeQueue.pop();
    }

}

