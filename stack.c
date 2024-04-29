#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Stack
{
   int items[MAX_SIZE];
   int top;
};

// Function prototypes
void initializeStack(struct Stack *s);
void push(struct Stack *s, int value);
int pop(struct Stack *s);
void display(struct Stack *s);

int main()
{
   struct Stack stack;
   initializeStack(&stack);

   int choice, value;

   do
   {
      printf("\nStack Operations:\n");
      printf("1. Push\n");
      printf("2. Pop\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         printf("Enter the value to push: ");
         scanf("%d", &value);
         push(&stack, value);
         break;
      case 2:
         value = pop(&stack);
         if (value != -1)
         {
            printf("Popped element: %d\n", value);
         }
         break;
      case 3:
         display(&stack);
         break;
      case 4:
         printf("Exiting the program.\n");
         break;
      default:
         printf("Invalid choice. Please enter a valid option.\n");
      }
   } while (choice != 4);

   return 0;
}

void initializeStack(struct Stack *s)
{
   s->top = -1;
}

void push(struct Stack *s, int value)
{
   if (s->top == MAX_SIZE - 1)
   {
      printf("Stack overflow. Cannot push element.\n");
   }
   else
   {
      s->top++;
      s->items[s->top] = value;
      printf("Element %d pushed to the stack.\n", value);
   }
}

int pop(struct Stack *s)
{
   if (s->top == -1)
   {
      printf("Stack underflow. Cannot pop element.\n");
      return -1;
   }
   else
   {
      int poppedValue = s->items[s->top];
      s->top--;
      return poppedValue;
   }
}

void display(struct Stack *s)
{
   if (s->top == -1)
   {
      printf("Stack is empty.\n");
   }
   else
   {
      printf("Stack elements: ");
      for (int i = 0; i <= s->top; i++)
      {
         printf("%d ", s->items[i]);
      }
      printf("\n");
   }
}
