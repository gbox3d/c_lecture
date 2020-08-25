// ex01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void test(int a,int b)
{
    std::cout << a + b << std::endl;
}

int main()
{
    int a = 100;
    int b[5] = { 1,2,3,4,5 };
    char* ptr1 = (char *)b;
    unsigned short * ptr2 = (unsigned short*)b;

    test(a, b[2]);

    std::cout << "Hello World!\n";
}
