// ex04.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int main()
{
    //int _a1[] = { 7, 4, 9, 3, 5, 1 };
    std::vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << std::endl;
    }
    
    v1.resize(5);
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << std::endl;
    }

    std::cout << "capacity :" << v1.capacity() << std::endl;
    v1.shrink_to_fit();
    std::cout << "capacity :" << v1.capacity() << std::endl;

    return 0;
}
