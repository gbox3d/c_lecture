#include <stdio.h>

typedef struct ex14
{
  float height;
  int age;
  short class;
  unsigned char p1;
  unsigned char p2;
} S_TEST;

int main()
{
  S_TEST test;
  test.height = 181.2;
  test.age = 350;
  test.class = 7;
  test.p1 = 0x40;
  test.p2 = 0x88;

  FILE *fp = fopen("t2.bin","wb");

  fwrite(&test,sizeof(S_TEST),1,fp);
  fclose(fp);
  return 0;
}