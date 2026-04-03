
#include <stdio.h>
#include <stdlib.h>

#define STATE_NAME_LENGTH 2
#define NUM_STATES 8

// Structure to represent a state
struct State {
    char name;
    int transitions[2];  // 0: transition on 0, 1: transition on 1
};

// Array of states
struct State states[NUM_STATES];

// Function prototypes
void printState(char currentState);
void changeState(char input, char nextState);
void printConfiguration();
void identifyGarbage();
void deleteStates(char currentState, char stateToDelete[]);

int main(int argc, char *argv[]) {
    char currentState = 'A';  // Initial state

    // Initialize states
    for (int i = 0; i < NUM_STATES; ++i) {
        states[i].name = 'A' + i;
        for (int j = 0; j < 2; ++j) {
            states[i].transitions[j] = i;  // Default transition to itself
        }
    }

    // Print starting state
    printState(currentState);

    // Process commands
    char command;
    while (scanf(" %c", &command) != EOF) {
        switch (command) {
            case '0':
            case '1': {
                // Transition to the next state based on input
                currentState = 'A' + states[currentState - 'A'].transitions[command - '0'];
                printState(currentState);
                break;
            }
            case 'c': {
                // Change state command
                char input;
                char nextState;
                scanf(" %c %c", &input, &nextState);
                changeState(input, nextState);
                break;
            }
            case 'p':
                // Print configuration command
                printConfiguration();
                break;
            case 'g':
                // Identify garbage command
                identifyGarbage();
                break;
            case 'd': {
                // Delete command
                char stateToDelete[STATE_NAME_LENGTH];
                if (scanf(" %2s", stateToDelete) == 1) {
                    deleteStates(currentState, stateToDelete);
                } else {
                    deleteStates(currentState, "");
                }
                break;
            }
            default:
                break;
        }
    }

    return 0;
}

void printState(char currentState) {
    // Print current state
    printf("%c\n", currentState);
}

void changeState(char input, char nextState) {
    // Change state transition based on input
    states[currentState - 'A'].transitions[input - '0'] = nextState - 'A';
}

void printConfiguration() {
    // Print current state machine configuration
    for (int i = 0; i < NUM_STATES; ++i) {
        printf("%c %c %c\n", states[i].name, states[i].transitions[0] + 'A', states[i].transitions[1] + 'A');
    }
}

void identifyGarbage() {
    // Identify reachable and unreachable states
    int reachable[NUM_STATES] = {0};  // Initialize to 0 (not reachable)
    int stack[NUM_STATES];
    int stackTop = -1;

    stack[++stackTop] = currentState - 'A';  // Push initial state to stack
    reachable[currentState - 'A'] = 1;  // Mark initial state as reachable

    // DFS traversal to mark reachable states
    while (stackTop != -1) {
        int currentStateIndex = stack[stackTop--];
        for (int i = 0; i < 2; ++i) {
            int nextStateIndex = states[currentStateIndex].transitions[i];
            if (!reachable[nextStateIndex]) {
                reachable[nextStateIndex] = 1;
                stack[++stackTop] = nextStateIndex;
            }
        }
    }

    // Print reachable states
    printf("Reachable: ");
    for (int i = 0; i < NUM_STATES; ++i) {
        if (reachable[i]) {
            printf("%c ", 'A' + i);
        }
    }
    printf("\n");
}

void deleteStates(char currentState, char stateToDelete[]) {
    // Implement delete states logic
    if (stateToDelete[0] == '\0') {
        int reachable[NUM_STATES] = {0};  // Initialize to 0 (not reachable)
        int stack[NUM_STATES];
        int stackTop = -1;

        stack[++stackTop] = currentState - 'A';  // Push initial state to stack
        reachable[currentState - 'A'] = 1;  // Mark initial state as reachable

        // DFS traversal to mark reachable states
        while (stackTop != -1) {
            int currentStateIndex = stack[stackTop--];
            for (int i = 0; i < 2; ++i) {
                int nextStateIndex = states[currentStateIndex].transitions[i];
                if (!reachable[nextStateIndex]) {
                    reachable[nextStateIndex] = 1;
                    stack[++stackTop] = nextStateIndex;
                }
            }
        }

        // Print reachable states
        printf("Reachable: ");
        for (int i = 0; i < NUM_STATES; ++i) {
            if (reachable[i]) {
                printf("%c ", 'A' + i);
            }
        }
        printf("\n");
    } 
}
