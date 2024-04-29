#include <stdio.h>
#include <stdlib.h>

int main()
{
   int *arr_malloc, *arr_calloc, *arr_realloc;
   int size, newSize;

   // Using malloc
   printf("Enter the size of the array (malloc): ");
   scanf("%d", &size);

   arr_malloc = (int *)malloc(size * sizeof(int));
   if (arr_malloc == NULL)
   {
      printf("Memory allocation failed for arr_malloc.\n");
      return 1;
   }

   printf("Memory allocated successfully using malloc.\n");
   printf("Address of arr_malloc: %p\n", (void *)arr_malloc);

   // Using calloc
   printf("\nEnter the size of the array (calloc): ");
   scanf("%d", &size);

   arr_calloc = (int *)calloc(size, sizeof(int));
   if (arr_calloc == NULL)
   {
      printf("Memory allocation failed for arr_calloc.\n");
      free(arr_malloc); // Freeing previously allocated memory
      return 1;
   }

   printf("Memory allocated successfully using calloc.\n");
   printf("Address of arr_calloc: %p\n", (void *)arr_calloc);

   // Using realloc
   printf("\nEnter the new size for the array (realloc): ");
   scanf("%d", &newSize);

   arr_realloc = (int *)realloc(arr_calloc, newSize * sizeof(int));
   if (arr_realloc == NULL)
   {
      printf("Memory reallocation failed for arr_realloc.\n");
      free(arr_malloc); // Freeing previously allocated memory
      free(arr_calloc); // Freeing previously allocated memory
      return 1;
   }

   printf("Memory reallocated successfully using realloc.\n");
   printf("Address of arr_realloc: %p\n", (void *)arr_realloc);

   // Freeing the allocated memory
   free(arr_malloc);
   free(arr_realloc);

   printf("\nMemory freed for arr_malloc and arr_realloc.\n");

   return 0;
}
