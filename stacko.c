#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

// Function prototypes
void push(int value);
int pop();
void display();

int main()
{
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
         push(value);
         break;
      case 2:
         value = pop();
         if (value != -1)
         {
            printf("Popped element: %d\n", value);
         }
         break;
      case 3:
         display();
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

void push(int value)
{
   if (top == MAX_SIZE - 1)
   {
      printf("Stack overflow. Cannot push element.\n");
   }
   else
   {
      top++;
      stack[top] = value;
      printf("Element %d pushed to the stack.\n", value);
   }
}

int pop()
{
   if (top == -1)
   {
      printf("Stack underflow. Cannot pop element.\n");
      return -1;
   }
   else
   {
      int poppedValue = stack[top];
      top--;
      return poppedValue;
   }
}

void display()
{
   if (top == -1)
   {
      printf("Stack is empty.\n");
   }
   else
   {
      printf("Stack elements: ");
      for (int i = 0; i <= top; i++)
      {
         printf("%d ", stack[i]);
      }
      printf("\n");
   }
}