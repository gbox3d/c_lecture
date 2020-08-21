#include <stdio.h>

int main()
{
  char a[][4] = {
    {0x1,0x0,0x00,0x00}, //a1
    {0x2,0x0,0x00,0x00}, //a2
    {0x3,0x00,0x0,0x00}, //a3
    {0x4,0x00,0x0,0x00}, //a4
    {0x5,0x00,0x00,0x0}  //a5
  };

  int a1,a2,a3,a4,a5;
  int _a1,_a2,_a3,_a4,_a5;
  int sum;

  //0x00000001,0x01000000

  char _temp[4];
  a1 = *(int *)a[0]; //intel cpu 는 기본 리틀엔디언
  printf("%08x \n",a1);

  //빅엔디언으로 수정 
  _temp[0] = a[0][3];
  _temp[1] = a[0][2];
  _temp[2] = a[0][1];
  _temp[3] = a[0][0];
  _a1 = *(int *)_temp;
  printf("%08x \n",_a1);
  
  a2 = *(int *)a[1];
  printf("%d \n",a2);

  return 0;
}
