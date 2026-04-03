/**
 *  The functions in this module implement a Stack data structure
 *  of char pointers (aka "strings").
 *
 *  NOTE: the stack is implemented as a fixed size array (size = 100).
 *  Consequently, no more than 100 strings can be pushed onto
 *  the Stack at any given time.
 */

// Implementation hints:
//   The 3 functions--push, pop and isEmpty--share information
//   about the array used to implement the stack and the index
//   of the "top" of the stack.
//
//   You may want to make these variables global...
//   ...but that would
//   be a mistake (because anyone using the module would have
//   to ensure that they did not use global variables with the
//   same names).
//
//   An alternative in C is a "static global".
//   If a global variable is qualified as "static", it is global only
//   within the source code file where it is declared.
//   In parituclar, it cannot conflict with any other global variable.
//
//  RECOMMENDATION:
//   Uncomment the following 2 lines and use these static globals!
//static int top = 0;
//static char * stack[100];

/**
 * pop() removes the top string on the stack and returns it.
 *
 * If pop() is attempted on an empty stack, an error message
 * is printed to stderr and the value NULL ((char *) 0) is returned.
 */

#include "stringStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a fixed size for the stack
#define STACK_SIZE 100

// Static variables to maintain the stack and top index
static int top = 0;
static char *stack[STACK_SIZE];

// Function declarations
char *pop();
void push(char *thing2push);
int isEmpty();

char *pop()
{
    // Check if the stack is empty
    if (isEmpty()) {
        fprintf(stderr, "Error: Attempt to pop from an empty stack.\n");
        return NULL;
    }

    // Decrement top and return the top string
    return stack[--top];
}

/**
 *  push(thing2push) adds the "thing2push" to the top of the stack.
 *
 *  If there is no more space available on the Stack, an error
 *  message is printed to stderr.
 */
void push(char *thing2push)
{
    // Check if the stack is full
    if (top >= STACK_SIZE) {
        fprintf(stderr, "Error: Stack overflow. Cannot push more elements.\n");
        return;
    }

    // Allocate memory for the new string and copy it onto the stack
    stack[top] = strdup(thing2push);
    // Increment top
    top++;
}

/**
 * isEmpty() returns a non-zero integer (not necessarily 1) if the
 * stack is empty; otherwise, it returns 0 (zero).
 *
 */
 
int isEmpty() {
	if (top == 0){
		return 1;
  }else{
	  return 0;
}
}
