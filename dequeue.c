#include <stdio.h>
#include <stdlib.h>

// Define a node for the doubly ended queue
typedef struct Node
{
   int data;
   struct Node *next;
} Node;

// Function prototypes
Node *createNode(int data);
int isEmpty(Node *front, Node *rear);
void insertFront(Node **front, Node **rear, int data);
void insertRear(Node **front, Node **rear, int data);
int deleteFront(Node **front, Node **rear);
int deleteRear(Node **front, Node **rear);
void displayDeque(Node *front);

int main()
{
   Node *front = NULL;
   Node *rear = NULL;
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
         insertFront(&front, &rear, data);
         printf("%d inserted at the front.\n", data);
         break;
      case 2:
         printf("Enter the data to insert at the rear: ");
         scanf("%d", &data);
         insertRear(&front, &rear, data);
         printf("%d inserted at the rear.\n", data);
         break;
      case 3:
         if (!isEmpty(front, rear))
         {
            data = deleteFront(&front, &rear);
            printf("%d deleted from the front.\n", data);
         }
         else
         {
            printf("Deque is empty. Cannot delete from the front.\n");
         }
         break;
      case 4:
         if (!isEmpty(front, rear))
         {
            data = deleteRear(&front, &rear);
            printf("%d deleted from the rear.\n", data);
         }
         else
         {
            printf("Deque is empty. Cannot delete from the rear.\n");
         }
         break;
      case 5:
         displayDeque(front);
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

// Function to create a new node with the given data
Node *createNode(int data)
{
   Node *newNode = (Node *)malloc(sizeof(Node));
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

// Function to check if the deque is empty
int isEmpty(Node *front, Node *rear)
{
   return (front == NULL && rear == NULL);
}

// Function to insert an element at the front of the deque
void insertFront(Node **front, Node **rear, int data)
{
   Node *newNode = createNode(data);

   if (isEmpty(*front, *rear))
   {
      *front = *rear = newNode;
   }
   else
   {
      newNode->next = *front;
      *front = newNode;
   }
}

// Function to insert an element at the rear of the deque
void insertRear(Node **front, Node **rear, int data)
{
   Node *newNode = createNode(data);

   if (isEmpty(*front, *rear))
   {
      *front = *rear = newNode;
   }
   else
   {
      (*rear)->next = newNode;
      *rear = newNode;
   }
}

// Function to delete an element from the front of the deque
int deleteFront(Node **front, Node **rear)
{
   int data;
   Node *temp = *front;

   data = temp->data;
   *front = temp->next;

   if (*front == NULL)
   {
      *rear = NULL;
   }

   free(temp);
   return data;
}

// Function to delete an element from the rear of the deque
int deleteRear(Node **front, Node **rear)
{
   int data;
   Node *temp = *front;

   if (*front == *rear)
   {
      data = temp->data;
      *front = *rear = NULL;
   }
   else
   {
      while (temp->next != *rear)
      {
         temp = temp->next;
      }

      data = (*rear)->data;
      temp->next = NULL;
      *rear = temp;
   }

   free(*rear);
   return data;
}

// Function to display the elements of the deque
void displayDeque(Node *front)
{
   if (front == NULL)
   {
      printf("Deque is empty.\n");
   }
   else
   {
      printf("Deque elements: ");
      while (front != NULL)
      {
         printf("%d ", front->data);
         front = front->next;
      }
      printf("\n");
   }
}
