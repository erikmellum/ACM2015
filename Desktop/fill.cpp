#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int width;
int height;
int fillcount[4];
void clean_input(char* input)
{
  if((strlen(input) > 0) && (input[strlen(input)-1] == '\n'))
    input[strlen(input)-1] = '\0';
};
void print_matrix(int* matrix)
{
  for(int i=0; i<height; i++)
  {
    for(int j=0; j<width; j++)
    {
      printf("%d ", matrix[i*width + j]);
    }
    printf("\n");
  }
};
bool check(int x, int y)
{
  if(x < 0) return false;
  else if(x>=height) return false;
  else if(y < 0) return false;
  else if(y >= width) return false;
  return true;
}
void apply_fill(int x, int y, int c, int new_c, int* matrix)
{
 
  if(check(x-1, y))
  {
    if(matrix[(x-1)*width+y] == c)
    {
      matrix[(x-1)*width+y] = new_c;
      apply_fill(x-1, y, c, new_c, matrix);
    }
  }
  if(check(x+1, y))
  {
    if(matrix[(x+1)*width+y] == c)
    {
      matrix[(x+1)*width+y] = new_c;
      apply_fill(x+1, y, c, new_c, matrix);
    }
  }
  if(check(x, y-1))
  {
    if(matrix[(x)*width+(y-1)] == c)
    {
      matrix[(x)*width+(y-1)] = new_c;
      apply_fill(x, y-1, c, new_c, matrix);
    }
  }
  if(check(x, y+1))
  {
    if(matrix[(x)*width+(y+1)] == c) {
      matrix[(x)*width+(y+1)] = new_c;
      apply_fill(x, y+1, c, new_c, matrix);
    }
  }
  if(check(x+1, y+1))
  {
    if(matrix[(x+1)*width+(y+1)] == c) {
      matrix[(x+1)*width+(y+1)] = new_c;
      apply_fill(x+1, y+1, c, new_c, matrix);
    }
  }
  if(check(x+1, y-1))
  {
    if(matrix[(x+1)*width+(y-1)] == c) {
      matrix[(x+1)*width+(y-1)] = new_c;
      apply_fill(x+1, y-1, c, new_c, matrix);
    }
  }
  if(check(x-1, y+1))
  {
    if(matrix[(x-1)*width+(y+1)] == c) {
      matrix[(x-1)*width+(y+1)] = new_c;
      apply_fill(x-1, y+1, c, new_c, matrix);
    }
  }
  if(check(x-1, y-1))
  {
    if(matrix[(x-1)*width+(y-1)] == c) {
      matrix[(x-1)*width+(y-1)] = new_c;
      apply_fill(x-1, y-1, c, new_c, matrix);
    }
  }
}
void count_fills(int* matrix)
{
  for(int i=0; i<height; i++)
  {
    for(int j=0; j<width; j++)
    {
      if(matrix[i*width+j] == 1)
        fillcount[0]++;
      else if(matrix[i*width+j] == 2)
        fillcount[1]++;
      else if(matrix[i*width+j] == 3)
        fillcount[2]++;
      else if(matrix[i*width+j] == 4)
        fillcount[3]++;
    }
  }
}
void print_fills()
{
  for(int i=0; i<4; i++)
  {
    if(i==3)
    printf("%d ", fillcount[i]);
  }
}
int main()
{
  char buffer[1000];
  
  fgets(buffer, 1000, stdin);
  char* token = strtok(buffer, " ");
  width = atoi(token);
  token = strtok(NULL, " ");
  height = atoi(token);
  int* grid;
  grid = (int*) malloc(width*height);
  memset(grid, 0, width*height);
  memset(fillcount, 0, 4);
  for(int i=0; i<height; i++)
  {
    
    memset(buffer, 0, 1000);
    buffer[1000] = '\0';

    fgets(buffer, width*3, stdin);
    
_input(buffer);
    token = strtok(buffer, " ");
    int j=0;
    while(token)
    {
      
      grid[i*width + j] = atoi(token);
     
      token = strtok(NULL, " ");
      j++;
    }
    
  }
  int k;
  scanf("%d", &k);
  scanf(" ");
  for(int i=0; i<k; i++)
  {
  memset(buffer, 0, 1000);
    buffer[1000] = '\0';

  fgets(buffer, 1000, stdin);
  token = strtok(buffer, " ");
  int x = atoi(token)-1;
  token = strtok(NULL, " ");
  int y = atoi(token)-1;
  token = strtok(NULL, " ");
  int c = atoi(token);
  apply_fill(x, y, grid[x*width+y], c, grid);
  }
  count_fills(grid);
  print_fills();
}
