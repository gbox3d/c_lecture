// ex02.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>

typedef struct MyStruct
{
    char szName[32];
    unsigned short x;
    unsigned short y;
    unsigned short w;
    unsigned short h;
}S_SHEET;

int get_data_size(FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    int _size = ftell(fp);
    int _count = _size / sizeof(S_SHEET);
    fseek(fp, 0, SEEK_SET);

    return _count;
}

void trim_space(char* str)
{
    for (int i = 31; i > 0; i--)
    {
        if (str[i] != 0x20)
        {
            str[i + 1] = 0x00;
            break;
        }
    }
}

int main()
{
    FILE* fp;
    fp = fopen("../sheet2.bin", "rb");
    int _data_size = get_data_size(fp);
    printf("data size : %d \n", _data_size);

    void* ptrBuf;
    ptrBuf = malloc(_data_size * sizeof(S_SHEET));
    fread(ptrBuf, sizeof(S_SHEET), _data_size,fp);
    fclose(fp);

    for (int i = 0; i < _data_size; i++)
    {
        S_SHEET* pSheet = ((S_SHEET*)ptrBuf + i);
        //pSheet->szName[31] = 0x00;        
        trim_space(pSheet->szName);

        printf("%5d%5d%5d%5d : %s\n",pSheet->x, pSheet->y, pSheet->w, pSheet->h,pSheet->szName);
    }

    free(ptrBuf);
    return 0;
}
