#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};

struct Stack
{
   struct Node *top;
};

void initialize(struct Stack *stack)
{
   stack->top = NULL;
}

int isEmpty(struct Stack *stack)
{
   return (stack->top == NULL);
}

void push(struct Stack *stack, int data)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   if (newNode == NULL)
   {
      printf("Stack Overflow: Cannot push element\n");
      return;
   }
   newNode->data = data;
   newNode->next = stack->top;
   stack->top = newNode;
   printf("Pushed %d onto the stack\n", data);
}

int pop(struct Stack *stack)
{
   if (isEmpty(stack))
   {
      printf("Stack Underflow: Cannot pop element\n");
      return -1;
   }
   struct Node *temp = stack->top;
   int data = temp->data;
   stack->top = temp->next;
   free(temp);
   return data;
}
void display(struct Stack *stack)
{
   if (isEmpty(stack))
   {
      printf("Stack is empty\n");
      return;
   }
   struct Node *current = stack->top;
   printf("Stack elements: ");
   while (current != NULL)
   {
      printf("%d ", current->data);
      current = current->next;
   }
   printf("\n");
}

int main()
{
   struct Stack stack;
   initialize(&stack);

   int choice, data;

   while (1)
   {
      printf("\nStack Menu:\n");
      printf("1. Push\n");
      printf("2. Pop\n");
      printf("3. Display\n");
      printf("4. Quit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         printf("Enter data to push onto the stack: ");
         scanf("%d", &data);
         push(&stack, data);
         break;
      case 2:
         data = pop(&stack);
         if (data != -1)
            printf("Popped %d from the stack\n", data);
         break;
      case 3:
         display(&stack);
         break;
      case 4:
         exit(0);
      default:
         printf("Invalid choice. Please try again.\n");
      }
   }

   return 0;
}
