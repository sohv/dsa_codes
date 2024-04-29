#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly ended queue
struct Node
{
   int data;
   struct Node *next;
   struct Node *prev;
};

// Define the structure for a doubly ended queue
struct Deque
{
   struct Node *front;
   struct Node *rear;
};

// Function prototypes
struct Deque *createDeque();
int isEmpty(struct Deque *deque);
void insertFront(struct Deque *deque, int data);
void insertRear(struct Deque *deque, int data);
int deleteFront(struct Deque *deque);
int deleteRear(struct Deque *deque);
void displayDeque(struct Deque *deque);

int main()
{
   struct Deque *deque = createDeque();
   int choice, data;

   do
   {
      printf("\nDoubly Ended Queue (Deque) Operations:\n");
      printf("1. Insert at Front\n");
      printf("2. Insert at Rear\n");
      printf("3. Delete from Front\n");
      printf("4. Delete from Rear\n");
      printf("5. Display Deque\n");
      printf("6. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         printf("Enter the data to insert at the front: ");
         scanf("%d", &data);
         insertFront(deque, data);
         printf("%d inserted at the front.\n", data);
         break;
      case 2:
         printf("Enter the data to insert at the rear: ");
         scanf("%d", &data);
         insertRear(deque, data);
         printf("%d inserted at the rear.\n", data);
         break;
      case 3:
         if (!isEmpty(deque))
         {
            data = deleteFront(deque);
            printf("%d deleted from the front.\n", data);
         }
         else
         {
            printf("Deque is empty. Cannot delete from the front.\n");
         }
         break;
      case 4:
         if (!isEmpty(deque))
         {
            data = deleteRear(deque);
            printf("%d deleted from the rear.\n", data);
         }
         else
         {
            printf("Deque is empty. Cannot delete from the rear.\n");
         }
         break;
      case 5:
         displayDeque(deque);
         break;
      case 6:
         printf("Exiting the program.\n");
         break;
      default:
         printf("Invalid choice. Please enter a valid option.\n");
      }
   } while (choice != 6);

   return 0;
}

// Function to create a doubly ended queue
struct Deque *createDeque()
{
   struct Deque *deque = (struct Deque *)malloc(sizeof(struct Deque));
   deque->front = deque->rear = NULL;
   return deque;
}

// Function to check if the doubly ended queue is empty
int isEmpty(struct Deque *deque)
{
   return (deque->front == NULL);
}

// Function to insert an element at the front of the doubly ended queue
void insertFront(struct Deque *deque, int data)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->prev = NULL;
   newNode->next = deque->front;

   if (isEmpty(deque))
   {
      deque->front = deque->rear = newNode;
   }
   else
   {
      deque->front->prev = newNode;
      deque->front = newNode;
   }
}

// Function to insert an element at the rear of the doubly ended queue
void insertRear(struct Deque *deque, int data)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->next = NULL;
   newNode->prev = deque->rear;

   if (isEmpty(deque))
   {
      deque->front = deque->rear = newNode;
   }
   else
   {
      deque->rear->next = newNode;
      deque->rear = newNode;
   }
}

// Function to delete an element from the front of the doubly ended queue
int deleteFront(struct Deque *deque)
{
   int data;
   struct Node *temp = deque->front;

   data = temp->data;
   deque->front = temp->next;

   if (deque->front != NULL)
   {
      deque->front->prev = NULL;
   }
   else
   {
      deque->rear = NULL;
   }

   free(temp);
   return data;
}

// Function to delete an element from the rear of the doubly ended queue
int deleteRear(struct Deque *deque)
{
   int data;
   struct Node *temp = deque->rear;

   data = temp->data;
   deque->rear = temp->prev;

   if (deque->rear != NULL)
   {
      deque->rear->next = NULL;
   }
   else
   {
      deque->front = NULL;
   }

   free(temp);
   return data;
}

// Function to display the elements of the doubly ended queue
void displayDeque(struct Deque *deque)
{
   if (isEmpty(deque))
   {
      printf("Deque is empty.\n");
   }
   else
   {
      struct Node *temp = deque->front;
      printf("Deque elements: ");

      while (temp != NULL)
      {
         printf("%d ", temp->data);
         temp = temp->next;
      }

      printf("\n");
   }
}
