// 9번
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int year = 0;
	int sum = 1; // 0번째 해의 두더지 수는 들어오자마자 제거됨 
	cin >> year; 

	std::queue</*여기에 다른 자료형 넣고 쓸 수 있음*/int> moles;
	// 첫 노드 만들기
	moles.push(1); // 첫 노드에 1만 넣어줌. 


	//큐: [0년 두더지:1마리][1년 두더지:3마리][2년 두더지: 9마리] .. 

	for (int i = 0; i < year; i++)
		// 1년이면 3개, 2년이면 3x3개 .. 
	{
		int babymoles = moles.front() * 3;
		moles.push(babymoles); 
		//큐 상황:[0년:1마리][1년: 1x3마리] <- 이게 추가됨 
		moles.pop();// 맨 앞의 큐 탈락시킴 
		// 큐 상황: [1년: 1x3마리] 
		sum = sum + moles.front(); 
		// 해당 년도에 해당하는 가장 최신의 두더지 수를
		// 큐 가장 앞에 기록, 유지해가며
		// sum에 더해주는 과정. 
	}

	cout << sum << "마리"; 
}