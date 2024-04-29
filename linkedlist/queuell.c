#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};

struct Queue
{
   struct Node *front;
   struct Node *rear;
};

void initialize(struct Queue *queue)
{
   queue->front = NULL;
   queue->rear = NULL;
}

int isEmpty(struct Queue *queue)
{
   return (queue->front == NULL);
}

void enqueue(struct Queue *queue, int data)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   if (newNode == NULL)
   {
      printf("Queue Overflow: Cannot enqueue element\n");
      return;
   }
   newNode->data = data;
   newNode->next = NULL;

   if (isEmpty(queue))
   {
      queue->front = newNode;
      queue->rear = newNode;
   }
   else
   {
      queue->rear->next = newNode;
      queue->rear = newNode;
   }
   printf("Enqueued %d into the queue\n", data);
}

int dequeue(struct Queue *queue)
{
   if (isEmpty(queue))
   {
      printf("Queue Underflow: Cannot dequeue element\n");
      return -1;
   }
   struct Node *temp = queue->front;
   int data = temp->data;
   queue->front = temp->next;
   free(temp);
   return data;
}

int search(struct Queue *queue, int key)
{
   struct Node *current = queue->front;
   int position = 1;

   while (current != NULL)
   {
      if (current->data == key)
      {
         return position;
      }
      current = current->next;
      position++;
   }

   return -1;
}

void display(struct Queue *queue)
{
   if (isEmpty(queue))
   {
      printf("Queue is empty\n");
      return;
   }
   struct Node *current = queue->front;
   printf("Queue elements: ");
   while (current != NULL)
   {
      printf("%d ", current->data);
      current = current->next;
   }
   printf("\n");
}

int main()
{
   struct Queue queue;
   initialize(&queue);

   int choice, data, key, position;

   while (1)
   {
      printf("\nQueue Menu:\n");
      printf("1. Enqueue\n");
      printf("2. Dequeue\n");
      printf("3. Search\n");
      printf("4. Display\n");
      printf("5. Quit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         printf("Enter data to enqueue into the queue: ");
         scanf("%d", &data);
         enqueue(&queue, data);
         break;
      case 2:
         data = dequeue(&queue);
         if (data != -1)
            printf("Dequeued %d from the queue\n", data);
         break;
      case 3:
         printf("Enter element to search for: ");
         scanf("%d", &key);
         position = search(&queue, key);
         if (position != -1)
            printf("%d found at position %d in the queue\n", key, position);
         else
            printf("%d not found in the queue\n", key);
         break;
      case 4:
         display(&queue);
         break;
      case 5:
         exit(0);
      default:
         printf("Invalid choice. Please try again.\n");
      }
   }

   return 0;
}
