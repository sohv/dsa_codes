#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the BST
struct Node
{
   int data;
   struct Node *left;
   struct Node *right;
};

// Function to create a new node with the given data
struct Node *createNode(int data)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->left = newNode->right = NULL;
   return newNode;
}

// Function to insert a node into the BST
struct Node *insertNode(struct Node *root, int data)
{
   if (root == NULL)
   {
      return createNode(data);
   }

   if (data < root->data)
   {
      root->left = insertNode(root->left, data);
   }
   else if (data > root->data)
   {
      root->right = insertNode(root->right, data);
   }

   return root;
}

// Function to find the minimum element in the BST
int findMin(struct Node *root)
{
   if (root == NULL)
   {
      printf("BST is empty.\n");
      return -1; // Assuming -1 represents an invalid result
   }

   while (root->left != NULL)
   {
      root = root->left;
   }

   return root->data;
}

// Function to find the maximum element in the BST
int findMax(struct Node *root)
{
   if (root == NULL)
   {
      printf("BST is empty.\n");
      return -1; // Assuming -1 represents an invalid result
   }

   while (root->right != NULL)
   {
      root = root->right;
   }

   return root->data;
}

// Main function
int main()
{
   struct Node *root = NULL;

   // Insert elements into the BST
   root = insertNode(root, 50);
   insertNode(root, 30);
   insertNode(root, 20);
   insertNode(root, 40);
   insertNode(root, 70);
   insertNode(root, 60);
   insertNode(root, 80);

   // Find and print the minimum and maximum elements
   printf("Minimum element in the BST: %d\n", findMin(root));
   printf("Maximum element in the BST: %d\n", findMax(root));

   return 0;
}
