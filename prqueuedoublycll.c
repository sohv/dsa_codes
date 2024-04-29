// implement a priority queue using doubly circular linked list

#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
struct Node
{
   int data;
   int priority;
   struct Node *next;
   struct Node *prev;
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
   newNode->prev = NULL;

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
      if (pq->front != NULL)
      {
         // Adjust pointers for circular doubly linked list
         newNode->next = pq->front;
         newNode->prev = pq->front->prev;
         pq->front->prev->next = newNode;
         pq->front->prev = newNode;
      }
      else
      {
         // List is empty, make it circular
         newNode->next = newNode;
         newNode->prev = newNode;
      }

      pq->front = newNode;
   }
   else
   {
      struct Node *current = pq->front->next;

      // Find the correct position to insert the new node
      while (current != pq->front && priority >= current->priority)
      {
         current = current->next;
      }

      // Insert the new node before the current node
      newNode->next = current;
      newNode->prev = current->prev;
      current->prev->next = newNode;
      current->prev = newNode;
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
   if (temp->next != temp)
   {
      pq->front->prev->next = pq->front->next;
      pq->front->next->prev = pq->front->prev;
      pq->front = pq->front->next;
   }
   else
   {
      // List has only one node, set front to NULL to indicate an empty list
      pq->front = NULL;
   }

   free(temp);

   return data;
}

// Function to check if the priority queue is empty
int isEmpty(struct PriorityQueue *pq)
{
   return pq->front == NULL;
}

// Function to display the contents of the priority queue
void display(struct PriorityQueue *pq)
{
   if (isEmpty(pq))
   {
      printf("Priority queue is empty.\n");
      return;
   }

   struct Node *current = pq->front;
   do
   {
      printf("(%d, %d) ", current->data, current->priority);
      current = current->next;
   } while (current != pq->front);

   printf("\n");
}

// Function to free the memory allocated for the priority queue
void freePriorityQueue(struct PriorityQueue *pq)
{
   while (!isEmpty(pq))
   {
      dequeue(pq);
   }
   free(pq);
}

int main()
{
   // Example usage
   struct PriorityQueue *pq = initializePriorityQueue();

   enqueue(pq, 10, 2);
   enqueue(pq, 20, 1);
   enqueue(pq, 30, 3);

   printf("Priority Queue: ");
   display(pq);

   printf("Dequeue: %d\n", dequeue(pq));

   printf("Priority Queue after dequeue: ");
   display(pq);

   freePriorityQueue(pq);

   return 0;
}
