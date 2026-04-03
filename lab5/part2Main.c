#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "intHeap.c" 
#include "intStack.c"

extern int pop();
extern void push(int);

int main(int argc, char * argv[])
{
  int value;
  while (scanf("%d\n", &value) != EOF) {
    fprintf(stderr, "READING INPUT: %d\n", value);
    //
    
    addHeap(value);
    
  }
  exit(0);
}

//gcc -Wall -o main1 part1Main.c intStack.c stringStack.c
//gcc -Wall -o main2 part2Main.c intHeap.c intStack.c
