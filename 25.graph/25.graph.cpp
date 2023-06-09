﻿// 25.graph.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 자료구조: 그래프 (양방향으로 유기적으로 연결된 데이터) > 이 안에 "트리(단방향)" 존재  

#include <iostream>

int main()
{
    // 1. 자료구조 정리
    // [][][][][][]
    // 특징; 순차적으로 노드를 관리. index를 알고 있으면 해당 인덱스로 이동해 데이터를 읽고 쓸 수 있음. 
    // 탐색법; for문/while문


    //2. 리스트
    // 특징: 노드들끼리 서로의 주소를 포인터 변수에 저장해 연결한 자료구조. 
    // 중간에 노드를 읽으려면  for문을 순회해서 처음부터 탐색해야 함.
    // 탐색법: for문/while문

    // 3. 그래프
    // 특징: 노드 값 및 노드들끼리 관계를 저장한 자료구조. 
    // 트리(단방향) 이 그래프에 포함되어있는 개념. 
    // 탐색법: DFS(재귀함수), BFS(큐 자료구조를 이용하여 탐색) 
    // 사용처: 네트워크, 통신망 등 



    // **구현' 배열로 

    //    ↗  [0]↘
    //[1]   → ↓     [2]
    //   ↘  [3]
    //

    int map[4][4] =
    {
        0,0,1,1,  //0이 연결되어있는 방식
        1,0,1,1, //1이 연결되어있는 방식
        0,1,0,0, //2이 연결되어있는 방식
        0,0,1,1 //3이 연결되어있는 방식

    }; 


    for (size_t i = 0; i < 4; i++) 
    {
        if (map[1][i] == 0)
            continue;

        std::cout << map[1][i];
    }

    return 0;

    // 헉 기억 안남 ... !! >> 새롭게 문서 ㅎ팜 
    // 그래프의 경로구현 28 참고 

    // 2. 구현: 리스트로
    ////0list
    //list.push(2);
    //list.push(3);

    ////1list
    //list.push(0);
    //list.push(2);
    //list.push(3);

}
