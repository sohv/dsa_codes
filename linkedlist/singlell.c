#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
   int data;
   struct Node *next;
};

// Function prototypes
struct Node *createNode(int data);
struct Node *insertAtBeginning(struct Node *head, int data);
struct Node *insertAtEnd(struct Node *head, int data);
struct Node *deleteFromBeginning(struct Node *head);
struct Node *deleteFromEnd(struct Node *head);
void displayList(struct Node *head);

int main()
{
   struct Node *head = NULL;
   int choice, data;

   do
   {
      printf("\nSingly Linked List Operations:\n");
      printf("1. Insert at Beginning\n");
      printf("2. Insert at End\n");
      printf("3. Delete from Beginning\n");
      printf("4. Delete from End\n");
      printf("5. Display List\n");
      printf("6. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         printf("Enter the data to insert at the beginning: ");
         scanf("%d", &data);
         head = insertAtBeginning(head, data);
         printf("%d inserted at the beginning.\n", data);
         break;
      case 2:
         printf("Enter the data to insert at the end: ");
         scanf("%d", &data);
         head = insertAtEnd(head, data);
         printf("%d inserted at the end.\n", data);
         break;
      case 3:
         if (head != NULL)
         {
            head = deleteFromBeginning(head);
            printf("Deleted from the beginning.\n");
         }
         else
         {
            printf("List is empty. Cannot delete from the beginning.\n");
         }
         break;
      case 4:
         if (head != NULL)
         {
            head = deleteFromEnd(head);
            printf("Deleted from the end.\n");
         }
         else
         {
            printf("List is empty. Cannot delete from the end.\n");
         }
         break;
      case 5:
         displayList(head);
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
struct Node *createNode(int data)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

// Function to insert a node at the beginning of the linked list
struct Node *insertAtBeginning(struct Node *head, int data)
{
   struct Node *newNode = createNode(data);
   newNode->next = head;
   return newNode;
}

// Function to insert a node at the end of the linked list
struct Node *insertAtEnd(struct Node *head, int data)
{
   struct Node *newNode = createNode(data);
   if (head == NULL)
   {
      return newNode;
   }

   struct Node *temp = head;
   while (temp->next != NULL)
   {
      temp = temp->next;
   }

   temp->next = newNode;
   return head;
}

// Function to delete a node from the beginning of the linked list
struct Node *deleteFromBeginning(struct Node *head)
{
   struct Node *temp = head;

   head = head->next;
   free(temp);

   return head;
}

// Function to delete a node from the end of the linked list
struct Node *deleteFromEnd(struct Node *head)
{
   if (head->next == NULL)
   {
      free(head);
      return NULL;
   }

   struct Node *temp = head;
   while (temp->next->next != NULL)
   {
      temp = temp->next;
   }

   free(temp->next);
   temp->next = NULL;

   return head;
}

// Function to display the elements of the linked list
void displayList(struct Node *head)
{
   if (head == NULL)
   {
      printf("List is empty.\n");
   }
   else
   {
      printf("Linked List: ");
      while (head != NULL)
      {
         printf("%d ", head->data);
         head = head->next;
      }
      printf("\n");
   }
}
