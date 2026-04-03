#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
    
    int n = atoi(argv[1]);
    int from = atoi(argv[2]);
    int dest = atoi(argv[3]);
    
    //Incorrect command
    if ((argc > 4) || (from == dest) || (from < 1) || (from > 3) || (dest < 1) || (dest > 3)){
		fprintf(stderr, "Command is not invoked correctly, try again.");
		exit(-1);
	}
	//No arguments
	else if(argc == 1){
		n = 3 ;
		from = 1 ;
		dest = 2 ;
		towers(n, from, dest);
		exit(0);
	}
	//One Argument
	else if (argc == 2) {
		 n = atoi(argv[1]);
		 from = 1;
		 dest = 2;
        towers(n, from, dest);
		exit(0);
    }
    //Three arguments
    else if (argc == 4) {
		 n = atoi(argv[1]);
		 from = atoi(argv[2]);
		 dest = atoi(argv[3]);
        towers(n, from, dest);
		exit(0);
	}
}

