#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

// Function prototypes
void enqueue(int value);
int dequeue();
void display();

int main()
{
   int choice, value;

   do
   {
      printf("\nCircular Queue Operations:\n");
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
   if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1)))
   {
      printf("Circular Queue overflow. Cannot enqueue element.\n");
   }
   else if (front == -1)
   {
      // Queue is empty
      front = rear = 0;
      circularQueue[rear] = value;
      printf("Element %d enqueued.\n", value);
   }
   else if (rear == MAX_SIZE - 1 && front != 0)
   {
      // Wrap around if rear reaches the end of the array
      rear = 0;
      circularQueue[rear] = value;
      printf("Element %d enqueued.\n", value);
   }
   else
   {
      rear++;
      circularQueue[rear] = value;
      printf("Element %d enqueued.\n", value);
   }
}

int dequeue()
{
   int dequeuedValue;
   if (front == -1)
   {
      printf("Circular Queue underflow. Cannot dequeue element.\n");
      return -1;
   }
   else
   {
      dequeuedValue = circularQueue[front];

      if (front == rear)
      {
         // Queue has only one element, reset front and rear
         front = rear = -1;
      }
      else if (front == MAX_SIZE - 1)
      {
         // Wrap around if front reaches the end of the array
         front = 0;
      }
      else
      {
         front++;
      }

      return dequeuedValue;
   }
}

void display()
{
   if (front == -1)
   {
      printf("Circular Queue is empty.\n");
   }
   else
   {
      printf("Circular Queue elements: ");
      if (front <= rear)
      {
         for (int i = front; i <= rear; i++)
         {
            printf("%d ", circularQueue[i]);
         }
      }
      else
      {
         for (int i = front; i < MAX_SIZE; i++)
         {
            printf("%d ", circularQueue[i]);
         }
         for (int i = 0; i <= rear; i++)
         {
            printf("%d ", circularQueue[i]);
         }
      }
      printf("\n");
   }
}
