#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int skipcount;
void print_array(int array[])
{
  for(int i=0; i<skipcount+3; i++)
  {
    printf("Array %d: %d\n", i, array[i]); 
  }
};
int main()
{
  long buffer[5000];
  int iter;
  scanf("%d", &iter);
  for(int i=0; i<iter; i++)
  {
  memset(buffer, 0, 5000);
  long sum=0;
  scanf(" %d", &skipcount);
  for(int i=0; i<3; i++)
    buffer[i]=1;
  for(int i=0; i<skipcount; i++)
  {
    buffer[i+3]=buffer[i+3-1] + buffer[i+3-3];	
  }
  for(int i=0; i <skipcount; i++)
  {
    sum += buffer[i];
  }
  printf("%ld\n", sum);
  }
}
