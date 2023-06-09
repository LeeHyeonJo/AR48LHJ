﻿// 26_Tree.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 트리: 그래프의 일종 

#include <iostream>

//**트리란? 
// 단방향 그래프. 순환이 없다. 
// 위에서 아래로 내려가는 구조이므로, 부모 자식 관계라고도 볼 수 있다. 
//     ㅁ 부모 
//   ↙  ↘
//  ㅁ     ㅁ 자식 


// 실무에선 이진 트리(자식이 2개만)를 자주 사용한다
// 이유: 컴퓨터는 이진법 연산에 특화되어있기 때문. 
// 많은 데이터를 다루게 될 수록, 이진 트리가 더욱 유용해진다. 

//** 시간복잡도의 개념  : 데이터를 처리할때 해당 데이터가, 얼마나 시간이 걸리는지 그래프로 표현
// 항상 최악의 경우(데이터가 졸래 많을떄, 찾아야 하는 데이터가 뒤에 있을때) 를 가정한다. 
// 예시: 밑수가 10으로 고정인 로그인 경우, 컴퓨터에선 밑수가 2로 고정
// 로그를 왜 쓰나요?!: 큰 수를 다룰때 연산 빠르게 하려고! 

// ** 이진트리 => 로그 밑수 2, 삼진 트리 => 로그 밑수 3
// 현존하는 가장 빠른 알고리즘이다. 


// 1. 배열을 이용해서 표현한 트리. 
// 단방향으로만 얽혀야 함 

int matrixGraph[5][5] = // 순회 없는 버전 
{
    0,1,0,0,0,
    0,0,1,1,0,
    0,0,0,0,0,
    1,0,0,0,1,
    0,0,0,0,0,
};


int matrix[5][5] = // 순회 있는 버전 
{
    0,1,1,0,0, 
    0,0,0,1,1,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
};
// ㄴ 이거 그림으로 그린 상태에서 복습하기 
// 대강 이해함 


// 1-1. 단방향 트리를 재귀함수로 서치하는 원리
// 원리: 가로로 한줄씩 돌면서, 갈 수 있는 곳(1)을 찾는다. 
// 만나면, 재귀함수를 통해서 (배열로 치면) 그 아래 줄로 내려간다. 
// 돌아올땐 재귀함수 원리와 동일하게, 실행하기 직전의 윗줄로 올라온다. 

char valueGr[10] = "TEQWA"; // 출력용 
char value[10] = "TBECD"; // 출력용2
char path[10] = ""; // 길 기록용 (중복 방지) 
int visited[10] = {}; // 방문 여부 체크 (중복방지) 

//** 순회없는 버전 
void dfs(int now)
{
    std::cout << valueGr[now];

    for (int i = 0; i < 5; i++)
    {
        if (matrixGraph[now][i] == 1 && visited[i] == 0) // 갈 수 있는 루트일때
        {
            //// 재귀함수를 활용해 그 루트 안으로 들어간다. 
            //path[level + 1] = value[i];
            //dfs(level + 1, i); 
            //path[level + 1] = 0; <- 무한루프에 걸릴 수 있음. 

            //** 그래프의 순회: 나올 필요가 없으므로 (연결된 다른 쪽으로 가야지) 
            //** 굳이 리턴할 필요 없음. 알아서 돌게 하면 된다. 
            visited[i] = 1; 
            dfs(i); // 흠 이거 아닌듯? 순회가 안끝남 
                        // 비지티드로 체크해주지 않으면 무한순회 발생!! 
        }
    }
}

// ** 연결된 고리가 있을 경우, 순회를 방지하기 위해 visited를 추가. 

void dfs(int level, int now) // dfs = 깊이 탐색 
{
    std::cout << value[now]; // 맨 처음 경로 출력 &  

    for (int i = 0; i < 5; i++) // 가로로 돌면서 i 0~4 ( T~A 연결 여부 체크 ) 
    {
        if (matrix[now][i] == 1 && visited[i]==0) // 갈 수 있는 루트일때 아래로 들어감 
        {
            if (matrix[now][i] == 1) // visited[i]==0 : T->E->W->T의 무한루트 방지하기 위해 
            {
                path[level + 1] = value[i]; // 들어가면서 path 에 경로 기록 
                                                //value[i] 로 잡는건 레벨이 증가할때마다 "TEQWA" 한깐씩 이동하기 때문
                dfs(level + 1, i); // level+1 인건, 맨 처음 인덱스가 0이면 배열 이진트리 꼼수 못써서 

                path[level + 1] = 0;
            }
        }
    }
}



// 2. 링크드 리스트로도, 단방향으로 얽히면 만들 수 있다. (실무에선 이걸 자주 씀) 
// ** 문제 풀때는 배열로 하셈. (코테) 

// 3. 일차원 배열로도 표현 가능. 
// 이진 트리 한정으로 ~!!!!!!!!!!!!
// 1   : 부모
// [A]
// 
// 2  3 : 1의 자식  좌/ 우
// [B]  [C]
// 
// 4   5     6   7 : 각자 2(좌/우), 3(좌/우)의 자식
// [D] [E]  [I] [K]
// 
// 
// 0 1  2  3  4  5 6  7
// [][A][B][C][][][I][K]


// 규칙!!
// 좌측 자식은 인덱스 *2
// 우측 자식은 인덱스 *2 + 1 에 위치

int main()
{
    dfs(0, 0);

    std::cout << std::endl;

    visited[0] = 1;

    dfs(0);

    return 0;

    // 비지티스 써둔 이유; 제일 처음 T값 사용했다는 의미. 
}

// ** 트리와 그래프를 순회하는 알고리즘이 중요하다 ** 
// ** 코테 단골 문제 : 1. 문자열, 2.그리디 알고리즘 ( = 내 생각대로 푸는거) 3. DFS/BFS 둘 중 하나 4. D/P 동적계획 : 공식이 정해진 문제. 알아야 함. 
// 전략: D/P 문제는 공식 모르면 제끼고, 나머지 주르륵 풀기. (1~3 문제 위주로) 

// DFS(깊이 탐색) : 깊이 탐색 
// 단점: K의 데이터를 찾는 경우, 가장 마지막의 경우의 수에서 찾을 수 있음
// 장점: 데이터가 상단에 있으면 이게 유리 

// BFX(너비 탐색) : 너비 탐색 (가로로 레벨 0, 1, 2 관통해서 탐색)
// 장점: 데이터가 하단에 있으면 이게 유리 

// ** 뭐가 유리할지 어떻게 알아보나요? **
// 제한사항에 적힌 인원수, 입력받는 숫자의 범위를 본다.
// ex)1~100명 : 적당히 적으니 가로, 너비검색 BFX
// ex)1~1000명 : 꽤 있으니 세로, 깊이 검색 DFX

// 1   : 부모
// [A]
// 
// 2  3 : 1의 자식  좌/ 우
// [B]  [C]
// 
// 4   5     6   7 : 각자 2(좌/우), 3(좌/우)의 자식
// [D] [E]  [I] [K]
// 