// 18_DirectAddressTable.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 해시 테이블 

#include <iostream>


int hashFucntion(int data)
{
    int index = 0;

    index = data * 7 / 32 + 22 - 108 * 32;
    return index;

    // 중복값이 나올수있다.
    // 지구상에서 해결 불가능 아직은
    // 어떤 해시 함수도 천만분의 1억만분의 1
}


int main()
{
    char str[256] = "ASDVVSDFEBDSSFAJEJFKDKEJZ";

    char target = 'A'; // 65
    // A가 나올떄마다 A의 갯수를 세주는데

    int bucket[128] = {};
    for (size_t i = 0; i < 256; i++)
    {
        char target = str[i];
        bucket[target]++;
    }

    int len = bucket['B'];


    // 정렬도 편리하다'
    for (size_t i = 1; i < 128; i++)
    {
        if (bucket[i] > 0)
        {
            for (size_t j = 0; j < bucket[i]; j++)
            {
                std::cout << (char)i;
            }
        }
    }

    return 0;
}

