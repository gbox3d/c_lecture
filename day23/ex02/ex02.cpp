// ex02.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
int main()
{
    FILE* fp;
    fp = fopen("../sheet2.bin", "rb");

    fclose(fp);
    return 0;
}
