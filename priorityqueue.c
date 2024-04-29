// priority queue using linked list

#include <stdio.h>
#include <stdlib.h>

// Node structure for the priority queue
struct Node
{
   int data;
   int priority;
   struct Node *next;
};

// Priority Queue structure
struct PriorityQueue
{
   struct Node *front;
};

// Function to create a new node
struct Node *createNode(int data, int priority)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   if (newNode == NULL)
   {
      printf("Memory allocation failed.\n");
      exit(EXIT_FAILURE);
   }

   newNode->data = data;
   newNode->priority = priority;
   newNode->next = NULL;

   return newNode;
}

// Function to initialize an empty priority queue
struct PriorityQueue *initializePriorityQueue()
{
   struct PriorityQueue *pq = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
   if (pq == NULL)
   {
      printf("Memory allocation failed.\n");
      exit(EXIT_FAILURE);
   }

   pq->front = NULL;
   return pq;
}

// Function to insert a new element with priority into the priority queue
void enqueue(struct PriorityQueue *pq, int data, int priority)
{
   struct Node *newNode = createNode(data, priority);

   // If the queue is empty or the new node has higher priority than the front
   if (pq->front == NULL || priority < pq->front->priority)
   {
      newNode->next = pq->front;
      pq->front = newNode;
   }
   else
   {
      struct Node *current = pq->front;

      // Find the correct position to insert the new node
      while (current->next != NULL && priority >= current->next->priority)
      {
         current = current->next;
      }

      // Insert the new node
      newNode->next = current->next;
      current->next = newNode;
   }
}

// Function to remove and return the element with the highest priority from the priority queue
int dequeue(struct PriorityQueue *pq)
{
   if (pq->front == NULL)
   {
      printf("Priority queue is empty.\n");
      exit(EXIT_FAILURE);
   }

   int data = pq->front->data;

   // Remove the front node
   struct Node *temp = pq->front;
   pq->front = pq->front->next;
   free(temp);

   return data;
}

// Function to display the contents of the priority queue
void display(struct PriorityQueue *pq)
{
   if (pq->front == NULL)
   {
      printf("Priority queue is empty.\n");
      return;
   }

   struct Node *current = pq->front;
   while (current != NULL)
   {
      printf("(%d, %d) ", current->data, current->priority);
      current = current->next;
   }

   printf("\n");
}

// Function to free the memory allocated for the priority queue
void freePriorityQueue(struct PriorityQueue *pq)
{
   while (pq->front != NULL)
   {
      dequeue(pq);
   }
   free(pq);
}

// Main function
int main()
{
   struct PriorityQueue *pq = initializePriorityQueue();
   int choice, data, priority;

   do
   {
      printf("\nPriority Queue Menu:\n");
      printf("1. Enqueue\n");
      printf("2. Dequeue\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         printf("Enter data and priority: ");
         scanf("%d %d", &data, &priority);
         enqueue(pq, data, priority);
         break;
      case 2:
         if (pq->front != NULL)
         {
            printf("Dequeued: %d\n", dequeue(pq));
         }
         else
         {
            printf("Priority queue is empty.\n");
         }
         break;
      case 3:
         display(pq);
         break;
      case 4:
         printf("Exiting the program.\n");
         break;
      default:
         printf("Invalid choice. Please enter a valid option.\n");
      }

   } while (choice != 4);

   // Free allocated memory before exiting
   freePriorityQueue(pq);

   return 0;
}
