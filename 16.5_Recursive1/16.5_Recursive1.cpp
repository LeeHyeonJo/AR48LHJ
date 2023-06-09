﻿// 16_Recursive.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 1.재귀함수의 가지치기 & 2.중복을 허용하지 않는 재귀함수 
#include <iostream>
using namespace std; 

// 1.가지치기: 예시 - 처음이 B로 시작하는 것만 제거해준다. 
// 진입할 필요가 없는 곳에서 if,return 문으로 막아준다. 
// 장점: 프로그램 성능 향상을 기대할 수 있다. 
// 유의: 정확한 위치에 조건문을 걸어주어야 한다.

// a. 진입하고 가지치는 방식
// b. 진입 자체를 막는 방식 (새로운 배열을 만들어 방문 여부를 체크) 


// 2. 중복을 허용하지 않는 가지치기: (전체 3개중에 2개를 중복을 허용하지 않고 뽑을 때) 
// 원리 : visited 배열에서 사용 여부를 체크. visited[i] 가 0일때만 진입하도록 체크한다. 
// 0530 복습; 배열 2개와, 트리 그려가면서 이동 여부 체크해보기. 

char path[8] = {};
int visited[10] = {};

void kfc(int level)
{
	if (level == 2) // 레벨이 2일떄 (= 그 중 뽑을 카드의 수) 
	{
		cout << path << endl;
		return;
	}

	for (int i = 0; i < 3; i++) // i = 가지의 수 (=총 카드의 수) 
	{
		if (visited[i] == 0) // 방문하지 않았을때만 진행 
		{
			visited[i] = 1; // 들어가기 직전에 진입 기록
			path[level] = 'a' + i; // 들어가기 직전에 경로 기록  a,b,c 
			kfc(level + 1);
			path[level] = 0; // 돌아간 후 기록 지우기. 
			visited[i] = 0; // 돌아간 후 기록 지우기. 
		}
	}
	// 원리: 들어가기 전에 경로를 기록. 나오면서(=이전 함수로 돌아가서) 지움. 
}

	int main()
	{
		kfc(0);
	}
