// write a program to implement a priority queue using circular linked list in C

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
   int data;
   int priority;
   struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data, int priority)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   if (newNode == NULL)
   {
      printf("Memory allocation failed\n");
      exit(EXIT_FAILURE);
   }
   newNode->data = data;
   newNode->priority = priority;
   newNode->next = NULL;
   return newNode;
}

// Function to insert a node into the priority queue based on priority
void enqueue(struct Node **front, int data, int priority)
{
   struct Node *newNode = createNode(data, priority);

   if (*front == NULL)
   {
      *front = newNode;
      newNode->next = *front;
   }
   else
   {
      struct Node *temp = *front;
      while (temp->next != *front && temp->next->priority >= priority)
      {
         temp = temp->next;
      }
      newNode->next = temp->next;
      temp->next = newNode;
   }
}

// Function to remove and return the highest priority element from the priority queue
int dequeue(struct Node **front)
{
   if (*front == NULL)
   {
      printf("Priority queue is empty\n");
      exit(EXIT_FAILURE);
   }

   int data = (*front)->data;
   struct Node *temp = *front;

   if ((*front)->next == *front)
   {
      *front = NULL;
   }
   else
   {
      (*front)->data = (*front)->next->data;
      (*front)->priority = (*front)->next->priority;
      temp = (*front)->next;
      (*front)->next = (*front)->next->next;
   }

   free(temp);
   return data;
}

// Function to display the elements of the priority queue
void display(struct Node *front)
{
   if (front == NULL)
   {
      printf("Priority queue is empty\n");
      return;
   }

   struct Node *temp = front;
   do
   {
      printf("(%d, %d) ", temp->data, temp->priority);
      temp = temp->next;
   } while (temp != front);
   printf("\n");
}

// Function to free the memory allocated for the priority queue
void freePriorityQueue(struct Node **front)
{
   if (*front == NULL)
   {
      return;
   }

   struct Node *current = *front;
   struct Node *next;

   do
   {
      next = current->next;
      free(current);
      current = next;
   } while (current != *front);

   *front = NULL;
}

// Main function for testing
int main()
{
   struct Node *front = NULL;

   // Enqueue elements with priorities
   enqueue(&front, 10, 2);
   enqueue(&front, 20, 1);
   enqueue(&front, 30, 3);

   // Display the priority queue
   printf("Priority Queue: ");
   display(front);

   // Dequeue and display elements
   printf("Dequeue: %d\n", dequeue(&front));
   printf("Priority Queue after dequeue: ");
   display(front);

   // Free memory
   freePriorityQueue(&front);

   return 0;
}
