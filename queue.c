#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = 0, rear = -1;

// Function prototypes
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
   if (rear == MAX_SIZE - 1)
   {
      printf("Queue overflow. Cannot enqueue element.\n");
   }
   else
   {
      if (front == -1)
      {
         front = 0; // Set front to 0 if the queue is empty
      }
      rear++;
      queue[rear] = value;
      printf("Element %d enqueued.\n", value);
   }
}

int dequeue()
{
   int dequeuedValue;
   if (rear == -1 || front > rear)
   {
      printf("Queue underflow. Cannot dequeue element.\n");
      return -1;
   }
   else
   {
      dequeuedValue = queue[front];
      front++;
      return dequeuedValue;
   }
}

void display()
{
   if (front == -1 || front > rear)
   {
      printf("Queue is empty.\n");
   }
   else
   {
      printf("Queue elements: ");
      for (int i = front; i <= rear; i++)
      {
         printf("%d ", queue[i]);
      }
      printf("\n");
   }
}
