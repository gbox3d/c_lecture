#include <stdio.h>

int main()
{
  
  int *pa;
  int num = 3;
  int num2 = 9;
  const int *pb; // 값 변경불가
  int * const pc=&num2; //주소값 변경불가.

  pa = &num;
  pb = pa;
  //*pb = 7;
  *pa = 7;
  // pc = pa;

  printf("%d %d\n",*pb,*pc);
  return 0;

}