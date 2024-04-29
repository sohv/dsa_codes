#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a binary tree
struct TreeNode
{
   int data;
   struct TreeNode *left;
   struct TreeNode *right;
};

// Function prototypes
struct TreeNode *createNode(int key);
struct TreeNode *insertNode(struct TreeNode *root, int key);
void inorderTraversal(struct TreeNode *root);
void preorderTraversal(struct TreeNode *root);
void postorderTraversal(struct TreeNode *root);

int main()
{
   struct TreeNode *root = NULL;
   int choice, key;

   do
   {
      printf("\nBinary Tree Traversal Methods:\n");
      printf("1. Insert Element\n");
      printf("2. Inorder Traversal\n");
      printf("3. Preorder Traversal\n");
      printf("4. Postorder Traversal\n");
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
         printf("Inorder Traversal:\n");
         inorderTraversal(root);
         printf("\n");
         break;
      case 3:
         printf("Preorder Traversal:\n");
         preorderTraversal(root);
         printf("\n");
         break;
      case 4:
         printf("Postorder Traversal:\n");
         postorderTraversal(root);
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

// Function to create a new node with the given key
struct TreeNode *createNode(int key)
{
   struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
   newNode->data = key;
   newNode->left = newNode->right = NULL;
   return newNode;
}

// Function to insert a key into a binary tree
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

// Function to perform inorder traversal of a binary tree
void inorderTraversal(struct TreeNode *root)
{
   if (root != NULL)
   {
      inorderTraversal(root->left);
      printf("%d ", root->data);
      inorderTraversal(root->right);
   }
}

// Function to perform preorder traversal of a binary tree
void preorderTraversal(struct TreeNode *root)
{
   if (root != NULL)
   {
      printf("%d ", root->data);
      preorderTraversal(root->left);
      preorderTraversal(root->right);
   }
}

// Function to perform postorder traversal of a binary tree
void postorderTraversal(struct TreeNode *root)
{
   if (root != NULL)
   {
      postorderTraversal(root->left);
      postorderTraversal(root->right);
      printf("%d ", root->data);
   }
}
