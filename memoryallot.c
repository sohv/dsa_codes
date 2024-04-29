#include <stdio.h>
#include <stdlib.h>

int main()
{
   int *arr_malloc, *arr_calloc, *arr_realloc;
   int size, newSize, i;

   // (i) Using malloc()
   printf("Enter the size of the array for malloc: ");
   scanf("%d", &size);

   arr_malloc = (int *)malloc(size * sizeof(int));

   if (arr_malloc == NULL)
   {
      printf("Memory allocation failed for malloc.\n");
      return 1;
   }

   printf("Enter %d elements for malloc:\n", size);
   for (i = 0; i < size; i++)
   {
      scanf("%d", &arr_malloc[i]);
   }

   printf("Elements using malloc: ");
   for (i = 0; i < size; i++)
   {
      printf("%d ", arr_malloc[i]);
   }
   printf("\n");

   // (ii) Using calloc()
   printf("Enter the size of the array for calloc: ");
   scanf("%d", &size);

   arr_calloc = (int *)calloc(size, sizeof(int));

   if (arr_calloc == NULL)
   {
      printf("Memory allocation failed for calloc.\n");
      free(arr_malloc); // Free previously allocated memory
      return 1;
   }

   printf("Enter %d elements for calloc:\n", size);
   for (i = 0; i < size; i++)
   {
      scanf("%d", &arr_calloc[i]);
   }

   printf("Elements using calloc: ");
   for (i = 0; i < size; i++)
   {
      printf("%d ", arr_calloc[i]);
   }
   printf("\n");

   // (iii) Using realloc()
   printf("Enter the new size for realloc: ");
   scanf("%d", &newSize);

   arr_realloc = (int *)realloc(arr_malloc, newSize * sizeof(int));

   if (arr_realloc == NULL)
   {
      printf("Memory reallocation failed for realloc.\n");
      free(arr_malloc); // Free previously allocated memory
      free(arr_calloc); // Free previously allocated memory
      return 1;
   }

   printf("Enter %d elements for realloc:\n", newSize);
   for (i = 0; i < newSize; i++)
   {
      scanf("%d", &arr_realloc[i]);
   }

   printf("Elements using realloc: ");
   for (i = 0; i < newSize; i++)
   {
      printf("%d ", arr_realloc[i]);
   }
   printf("\n");

   free(arr_calloc);
   free(arr_realloc);

   printf("Memory freed for calloc and realloc.\n");

   return 0;
}
