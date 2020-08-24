// ex06.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct s_object {
    int hp;
    int mp;
    std::string name;
};

bool _compare(s_object a,s_object b)
{
    //if (a.hp > b.hp) return true;
    if (a.mp > b.mp) return true;
    else return false;
}

int main()
{
    std::vector<s_object> objs;
    {
        s_object obj1;
        obj1.hp = 100;
        obj1.mp = 35;
        obj1.name = std::string("knight_1");
        objs.push_back(obj1);
    }
    {
        s_object obj1;
        obj1.hp = 120;
        obj1.mp = 20;
        obj1.name = std::string("knight_2");
        objs.push_back(obj1);
    }
    {
        s_object obj1;
        obj1.hp = 80;
        obj1.mp = 55;
        obj1.name = std::string("knight_3");
        objs.push_back(obj1);
    }
    for (int i = 0; i < objs.size(); i++)
    {
        std::cout << objs[i].name <<"," << objs[i].hp  <<"," << objs[i].mp << std::endl;
    }

    std::sort(objs.begin(), objs.end(), _compare);
    
    std::cout << "--------------------------" << std::endl;
    for (int i = 0; i < objs.size(); i++)
    {
        std::cout << objs[i].name << "," << objs[i].hp << "," << objs[i].mp << std::endl;
    }
    


    return 0;
}
