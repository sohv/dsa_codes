#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Deque {
    int front, rear;
    char items[MAX_SIZE];
};

// Function to initialize the deque
void initDeque(struct Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

// Function to check if the deque is empty
bool isEmpty(struct Deque* deque) {
    return (deque->front == -1 && deque->rear == -1);
}

// Function to add an element to the front of the deque
void addToFront(struct Deque* deque, char item) {
    if (deque->front == -1)
        deque->front = deque->rear = 0;
    else if (deque->front == 0)
        deque->front = MAX_SIZE - 1;
    else
        deque->front--;

    deque->items[deque->front] = item;
}

// Function to add an element to the rear of the deque
void addToRear(struct Deque* deque, char item) {
    if (deque->rear == -1)
        deque->front = deque->rear = 0;
    else if (deque->rear == MAX_SIZE - 1)
        deque->rear = 0;
    else
        deque->rear++;

    deque->items[deque->rear] = item;
}

// Function to remove an element from the front of the deque
char removeFromFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        fprintf(stderr, "Deque is empty\n");
        exit(EXIT_FAILURE);
    }

    char item = deque->items[deque->front];

    if (deque->front == deque->rear)
        deque->front = deque->rear = -1;
    else if (deque->front == MAX_SIZE - 1)
        deque->front = 0;
    else
        deque->front++;

    return item;
}

// Function to remove an element from the rear of the deque
char removeFromRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        fprintf(stderr, "Deque is empty\n");
        exit(EXIT_FAILURE);
    }

    char item = deque->items[deque->rear];

    if (deque->front == deque->rear)
        deque->front = deque->rear = -1;
    else if (deque->rear == 0)
        deque->rear = MAX_SIZE - 1;
    else
        deque->rear--;

    return item;
}

// Function to check if a string is a palindrome
bool isPalindrome(char* str) {
    struct Deque deque;
    initDeque(&deque);

    int len = strlen(str);

    // Add characters to the rear of the deque
    for (int i = 0; i < len; i++) {
        addToRear(&deque, str[i]);
    }

    // Check for palindrome by comparing characters from both ends
    while (!isEmpty(&deque) && deque.front != deque.rear) {
        if (removeFromFront(&deque) != removeFromRear(&deque)) {
            return false; // Not a palindrome
        }
    }

    return true; // Palindrome
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    // Remove newline character from the input
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}
