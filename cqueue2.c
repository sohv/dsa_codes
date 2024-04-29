#include <stdio.h>
#include <stdlib.h>
#define size 5

int count = 0, front = 0, rear = -1;
int queue[size];
void enqueue(int value);
int dequeue();
void display();

int main()
{
   int choice, value;
   do
   {
      printf("\nQueue Operations:\n");
      printf("1. Enqueue\n");
      printf("2. Dequeue\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         printf("Enter the value to enqueue: ");
         scanf("%d", &value);
         enqueue(value);
         break;
      case 2:
         value = dequeue();
         if (value != -1)
         {
            printf("Dequeued element: %d\n", value);
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

void enqueue(int value)
{
   if (count == size)
   {
      printf("Queue is full");
   }
   else
   {
      rear = (rear + 1) % (size);
      queue[rear] = value;
      count++;
      printf("%d inserted successfully", value);
   }
}
int dequeue()
{
   if (count == 0)
   {
      printf("Queue is empty");
      return -1;
   }
   else
   {
      int value = queue[front];
      front = (front + 1) % (size);
      count--;
      return value;
   }
}
void display()
{
   if (count == 0)
   {
      printf("Queue is empty");
   }
   if (front <= rear)
   {
      for (int i = front; i <= rear; i++)
      {
         printf("%d ", queue[i]);
      }
   }
   else
   {
      for (int i = front; i < size; i++)
      {
         printf("%d ", queue[i]);
      }
      for (int i = 0; i <= rear; i++)
      {
         printf("%d ", queue[i]);
      }
      printf("\n");
   }
}
