// 29.5_graphpath_minimuncost(bfs).cpp 
// ** 그래프로 경로찾기의 응용 **
// 가장 "빠른" / "저렴한" 경로 찾기 (bfs)

#include <iostream>
#include <queue>
using namespace std;

int map[7][7] =
{
    // 5,1,35,1,10,70,20
       0,1,1,0,0,0,0, //5
       0,0,0,1,0,1,0, //1
       0,0,0,0,1,1,0, //35
       0,0,0,0,1,0,0, //1
       0,0,0,0,0,0,1, //10
       0,0,0,0,0,0,1, //70
       0,0,0,0,0,0,0, //20

}; // 0. 그래프 그려보고 시작하기. (함)

int value[7] = { 5,1,35,1,10,70,20 };
// 연결된 녀석들 

int save = 0; // front.sum을 저장하는 값

struct node
{
    int num; // y축이 되어주는 변수 
    int sum; // 경로의 합 저장하는 변수 
    int used[7]; // 중복 여부 역할 (used와 동일함) 
};

// ** 핵심 원리: 노드에, 경로와, 이번에는 최소를 구하므로,
// ** 경로의 합까지, 저장되어야 함 
// sum에 저장되는거가 memcpy 코드 
// used와 비지티드는 동일한 역할 

int minBFS = 98782; 

void bfs()
{
    queue<node> cute;

    // 1. 큐에 첫번째 노드 넣어줌 
                 // num,   sum,    used
    cute.push(node{ 0, value[0], {1,0,0,0,0,0,0,} });
    // y축(시작하는 값), 노드에 저장된 경로(합) , 중복 여부 체크 

    // 2. 큐에 두번째 노드 넣는 과정 
    while (!cute.empty())
    {
        // a. 우선 첫 노드를 가리키는, front 생성. 
        node front = cute.front();

        // b. 인접행렬 돌면서 맞닿아 있는 노드 찾기 
        for (int x = 0; x < 6; x++)
        {       //  y 축              //  중복여부체크    
            if (map[front.num][x] == 1 && front.used[x] == 0)
            {
                // 큐에 진짜 두번쨰 노드 넣는 과정 // 
                node newnode1 = {/*num(Y), sum(경로 합), used*/ }; // 새로운 노드 생성 
                newnode1.num = x;
                newnode1.sum = front.sum + value[x];
                //앞 노드(첫 노드) 의 값 + 현재 위치 값을 sum에 저장

                // *** 여기 주의 *** //
                // used에는 경로를 기록함. 바로 앞 노드에 있는 경로를 복사 후, 현재 경로를 추가하는 방식. 이걸 위해 memcpy(a,b,복사할 바이트)를 사용 (a에 b를 복사)
                memcpy(newnode1.used, front.used, sizeof(int) * 7); // used[7] 이므로

                // 복사해온 경로에 현재 경로 추가 기록
                newnode1.used[x] = 1;

                /// 그 다음!!! 큐에 내용을 채워넣은 노드를 넣어준다. 
                cute.push(newnode1);
            }
        }

        // 한줄 다 돌면 
        cute.pop();

        /// front에 이미 가장 마지막 노드에 도달하기 직전의 값이 저장되어 있음. 
        save = front.sum; 
    }

    // 가장 마지막 노드의 값을 더해준걸 출력 (이게 맞나...) 
    cout << save + 20; 
}

int main()
{
    bfs(); 
}

