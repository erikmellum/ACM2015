#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <map>
#include <iostream>
using namespace std;
using std::pair;
map<string, string> mymap;
void clean_input(char* input)
{
  if((strlen(input) > 0) && (input[strlen(input)-1] == '\n'))
    input[strlen(input)-1] = '\0';
};
int main()
{
  int count;
  scanf("%d", &count);

  char* value = (char*) malloc(50);
  char* token = (char*) malloc(50);
  scanf(" ");
  char buffer[256];
  for(int i=0; i<count; i++)
  {
    memset(buffer, 0, 256);
    buffer[256] = '\0';
    
    fgets(buffer, 256, stdin);
    clean_input(buffer);
    value = strtok(buffer, " ");
    while(token)
    {
      mymap[token] = value;
      token = strtok(NULL, " ");
    }
  }


  scanf("  ");

  for(int i=0; i<count; i++)
  {
    memset(buffer, 0, 256);
    buffer[256] = '\0';
    
    fgets(buffer, 256, stdin);
    clean_input(buffer);
     cout << "BUFFER:" << buffer << endl;
    value = strtok(buffer, " ");
    cout << "TOKEN:" << value << endl;
    while(token)
    {
      cout << mymap[value] << endl;
      value = strtok(NULL, " ");
    }
    
  }
}
