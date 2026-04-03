#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "intStack.h"
#include "stringStack.h"

//extern char *  pop();
//extern void push(char *);

int main(int argc, char * argv[])
{
    int ch;
    char tag[100];  // Buffer to store tag identities
    
    // Read characters from stdin
    while ((ch = getchar()) != EOF) {
        if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
            continue;
        
        memset(tag, 0, sizeof(tag));
        
        // Check if a tag is beginning
        if (ch == '<')
        {
            // Read the tag's identity
            int i = 0;
            while ((ch = getchar()) != EOF && ch != '>')  // Read until end of tag
            {
                if (!isalpha(ch))
                {
                    fprintf(stderr, "Error: Invalid character in tag.\n");
                    exit(EXIT_FAILURE);
                }
                tag[i++] = ch;
            }
            
            // Check if it's a start-tag or an end-tag
            if (tag[0] != '/')  // Start-tag
            {
                // Push the start-tag onto the stack
                push((int) tag[0]);  // Convert char to int for compatibility
            }
            else  // End-tag
            {
                // Remove leading slash from end-tag
                memmove(tag, tag + 1, strlen(tag));
                
                // Pop the stack and compare with the end-tag
                int start_tag = pop();
                if (start_tag == -1 || strcmp((char*) &start_tag, tag) != 0)  // Convert int to char* for comparison
                {
                    fprintf(stderr, "Error: Invalid XML. Tags do not match.\n");
                    exit(EXIT_FAILURE);
                }
                else if (strcmp((char*) &start_tag, tag) != 0)  // Convert int to char* for comparison
                {
                    fprintf(stderr, "Error: Invalid XML. Tags do not match.\n");
                    fprintf(stderr, "Expected: </%s>, Found: </%s>\n", (char*) &start_tag, tag);  // Convert int to char* for formatting
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    // Check if the stack is empty (valid XML) or not (invalid XML)
    if (isEmpty())
    {
        printf("Valid XML: Tags are balanced.\n");
    }
    else
    {
        printf("Invalid XML: Tags are not balanced.\n");
        exit(EXIT_FAILURE);
    }
  
    exit(0);
}
