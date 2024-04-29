#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node
{
   int data;
   struct Node *next;
};

// Function prototypes
struct Node *createCircularLinkedList();
struct Node *insertNode(struct Node *head, int value, int position);
struct Node *deleteNode(struct Node *head, int position);
void traverseList(struct Node *head);

int main()
{
   struct Node *head = NULL;
   int choice, value, position;

   do
   {
      printf("\nCircular Linked List Operations:\n");
      printf("1. Create Circular Linked List\n");
      printf("2. Insert Node\n");
      printf("3. Delete Node\n");
      printf("4. Traverse List\n");
      printf("5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         head = createCircularLinkedList();
         break;
      case 2:
         printf("Enter the value to insert: ");
         scanf("%d", &value);
         printf("Enter the position to insert (1-based): ");
         scanf("%d", &position);
         head = insertNode(head, value, position);
         break;
      case 3:
         printf("Enter the position to delete (1-based): ");
         scanf("%d", &position);
         head = deleteNode(head, position);
         break;
      case 4:
         traverseList(head);
         break;
      case 5:
         printf("Exiting the program.\n");
         break;
      default:
         printf("Invalid choice. Please enter a valid option.\n");
      }
   } while (choice != 5);

   return 0;
}

// Function to create a circular linked list
struct Node *createCircularLinkedList()
{
   struct Node *head = NULL;
   struct Node *temp = NULL;
   struct Node *new_node = NULL;
   int value, n;

   printf("Enter the number of nodes in the circular linked list: ");
   scanf("%d", &n);

   for (int i = 0; i < n; i++)
   {
      printf("Enter the value for node %d: ", i + 1);
      scanf("%d", &value);

      new_node = (struct Node *)malloc(sizeof(struct Node));
      new_node->data = value;
      new_node->next = NULL;

      if (head == NULL)
      {
         head = new_node;
         temp = head;
      }
      else
      {
         temp->next = new_node;
         temp = new_node;
      }
   }

   // Make the list circular by connecting the last node to the head
   if (temp != NULL)
   {
      temp->next = head;
   }

   printf("Circular linked list created successfully.\n");

   return head;
}

// Function to insert a node at a specified position in a circular linked list
struct Node *insertNode(struct Node *head, int value, int position)
{
   struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
   new_node->data = value;
   new_node->next = NULL;

   if (position == 1)
   {
      struct Node *temp = head;
      while (temp->next != head)
      {
         temp = temp->next;
      }
      new_node->next = head;
      head = new_node;
      temp->next = head;

      printf("Node inserted successfully.\n");
   }
   else
   {
      struct Node *temp = head;
      for (int i = 1; i < position - 1 && temp != NULL; i++)
      {
         temp = temp->next;
      }

      if (temp == NULL)
      {
         printf("Invalid position. Node not inserted.\n");
      }
      else
      {
         new_node->next = temp->next;
         temp->next = new_node;

         printf("Node inserted successfully.\n");
      }
   }

   return head;
}

// Function to delete a node at a specified position in a circular linked list
struct Node *deleteNode(struct Node *head, int position)
{
   if (head == NULL)
   {
      printf("Circular linked list is empty. Cannot delete node.\n");
   }
   else
   {
      struct Node *temp = head;

      if (position == 1)
      {
         while (temp->next != head)
         {
            temp = temp->next;
         }

         temp->next = head->next;
         free(head);
         head = temp->next;

         printf("Node deleted successfully.\n");
      }
      else
      {
         for (int i = 1; i < position - 1 && temp != NULL; i++)
         {
            temp = temp->next;
         }

         if (temp == NULL || temp->next == head)
         {
            printf("Invalid position. Node not deleted.\n");
         }
         else
         {
            struct Node *toDelete = temp->next;
            temp->next = temp->next->next;
            free(toDelete);

            printf("Node deleted successfully.\n");
         }
      }
   }

   return head;
}

// Function to traverse and display a circular linked list
void traverseList(struct Node *head)
{
   if (head == NULL)
   {
      printf("Circular linked list is empty.\n");
   }
   else
   {
      printf("Circular linked list elements: ");
      struct Node *temp = head;
      do
      {
         printf("%d -> ", temp->data);
         temp = temp->next;
      } while (temp != head);
      printf("(head)\n");
   }
}
