//bst   
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a binary search tree
struct TreeNode
{
   int data;
   struct TreeNode *left;
   struct TreeNode *right;
};

// Function prototypes
struct TreeNode *insertNode(struct TreeNode *root, int key);
struct TreeNode *deleteNode(struct TreeNode *root, int key);
struct TreeNode *searchNode(struct TreeNode *root, int key);
void inorderTraversal(struct TreeNode *root);

// Function to create a new node with the given key
struct TreeNode *createNode(int key)
{
   struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
   newNode->data = key;
   newNode->left = newNode->right = NULL;
   return newNode;
}

int main()
{
   struct TreeNode *root = NULL;
   int choice, key;

   do
   {
      printf("\nBinary Search Tree Operations:\n");
      printf("1. Insert Element\n");
      printf("2. Delete Element\n");
      printf("3. Search for Element\n");
      printf("4. Inorder Traversal\n");
      printf("5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         printf("Enter the key to insert: ");
         scanf("%d", &key);
         root = insertNode(root, key);
         break;
      case 2:
         printf("Enter the key to delete: ");
         scanf("%d", &key);
         root = deleteNode(root, key);
         break;
      case 3:
         printf("Enter the key to search: ");
         scanf("%d", &key);
         if (searchNode(root, key) != NULL)
         {
            printf("Element %d found in the tree.\n", key);
         }
         else
         {
            printf("Element %d not found in the tree.\n", key);
         }
         break;
      case 4:
         printf("Inorder Traversal:\n");
         inorderTraversal(root);
         printf("\n");
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

// Function to insert a key into a binary search tree
struct TreeNode *insertNode(struct TreeNode *root, int key)
{
   // If the tree is empty, create a new node
   if (root == NULL)
   {
      return createNode(key);
   }

   // Otherwise, recur down the tree
   if (key < root->data)
   {
      root->left = insertNode(root->left, key);
   }
   else if (key > root->data)
   {
      root->right = insertNode(root->right, key);
   }

   // Return the unchanged node pointer
   return root;
}

// Function to delete a key from a binary search tree
struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
   // Base case: If the tree is empty
   if (root == NULL)
   {
      return root;
   }

   // Recur down the tree
   if (key < root->data)
   {
      root->left = deleteNode(root->left, key);
   }
   else if (key > root->data)
   {
      root->right = deleteNode(root->right, key);
   }
   else
   {
      // Node with only one child or no child
      if (root->left == NULL)
      {
         struct TreeNode *temp = root->right;
         free(root);
         return temp;
      }
      else if (root->right == NULL)
      {
         struct TreeNode *temp = root->left;
         free(root);
         return temp;
      }

      // Node with two children: Get the inorder successor (smallest
      // in the right subtree) or the inorder predecessor (largest
      // in the left subtree)
      struct TreeNode *temp = root->right;
      while (temp->left != NULL)
      {
         temp = temp->left;
      }

      // Copy the inorder successor's data to this node
      root->data = temp->data;

      // Delete the inorder successor
      root->right = deleteNode(root->right, temp->data);
   }

   // Return the unchanged node pointer
   return root;
}

// Function to search for a key in a binary search tree
struct TreeNode *searchNode(struct TreeNode *root, int key)
{
   // Base cases: root is null or the key is present at root
   if (root == NULL || root->data == key)
   {
      return root;
   }

   if (key > root->data)
   {
      return searchNode(root->right, key);
   }

   // Key is smaller than root's key
   return searchNode(root->left, key);
}

// Function to perform inorder traversal of a binary search tree
void inorderTraversal(struct TreeNode *root)
{
   if (root != NULL)
   {
      inorderTraversal(root->left);
      printf("%d ", root->data);
      inorderTraversal(root->right);
   }
}
