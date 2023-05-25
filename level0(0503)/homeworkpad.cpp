#include <iostream>
// 숙제: 집에서 이거 그림 꼭 다시 그려보기 !! 
void kfc(int level)
{

	if (level == 2)
	{
		return; 
	}

	kfc(level + 1);
	kfc(level + 1);
	kfc(level + 1);
	std::cout << level; 
	// 작동이 어떻게 그려지는지 직접 손으로 그려가면서 확인해보기 
}

int main()
{
	kfc(0);
}
