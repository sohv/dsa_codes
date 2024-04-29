#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Define the structure for a node in the circular queue
struct Node
{
   int data;
   struct Node *next;
};

// Define the structure for a circular queue
struct CircularQueue
{
   struct Node *front, *rear;
};

// Function prototypes
struct CircularQueue *createCircularQueue();
int isFull(struct CircularQueue *queue);
int isEmpty(struct CircularQueue *queue);
void enqueue(struct CircularQueue *queue, int data);
int dequeue(struct CircularQueue *queue);
void displayQueue(struct CircularQueue *queue);

int main()
{
   struct CircularQueue *trafficSystem = createCircularQueue();
   int choice, vehicle;

   do
   {
      printf("\nTraffic System Menu:\n");
      printf("1. Add Vehicle to Queue\n");
      printf("2. Remove Vehicle from Queue\n");
      printf("3. Display Queue\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         if (!isFull(trafficSystem))
         {
            printf("Enter the vehicle number: ");
            scanf("%d", &vehicle);
            enqueue(trafficSystem, vehicle);
            printf("Vehicle %d added to the queue.\n", vehicle);
         }
         else
         {
            printf("Queue is full. Cannot add more vehicles.\n");
         }
         break;
      case 2:
         if (!isEmpty(trafficSystem))
         {
            vehicle = dequeue(trafficSystem);
            printf("Vehicle %d removed from the queue.\n", vehicle);
         }
         else
         {
            printf("Queue is empty. No vehicles to remove.\n");
         }
         break;
      case 3:
         displayQueue(trafficSystem);
         break;
      case 4:
         printf("Exiting the traffic system.\n");
         break;
      default:
         printf("Invalid choice. Please enter a valid option.\n");
      }
   } while (choice != 4);

   return 0;
}

// Function to create a circular queue
struct CircularQueue *createCircularQueue()
{
   struct CircularQueue *queue = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
   queue->front = queue->rear = NULL;
   return queue;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue *queue)
{
   return (queue->front == queue->rear->next);
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue *queue)
{
   return (queue->front == NULL);
}

// Function to add an element to the circular queue
void enqueue(struct CircularQueue *queue, int data)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->next = NULL;

   if (isEmpty(queue))
   {
      queue->front = newNode;
      queue->rear = newNode;
      newNode->next = queue->front; // Make it circular
   }
   else
   {
      queue->rear->next = newNode;
      queue->rear = newNode;
      newNode->next = queue->front; // Make it circular
   }
}

// Function to remove an element from the circular queue
int dequeue(struct CircularQueue *queue)
{
   if (isEmpty(queue))
   {
      return -1; // Return -1 to indicate an empty queue
   }

   int data;
   struct Node *temp = queue->front;

   if (queue->front == queue->rear)
   {
      data = temp->data;
      free(temp);
      queue->front = queue->rear = NULL;
   }
   else
   {
      data = temp->data;
      queue->front = queue->front->next;
      queue->rear->next = queue->front; // Maintain circularity
      free(temp);
   }

   return data;
}

// Function to display the elements of the circular queue
void displayQueue(struct CircularQueue *queue)
{
   if (isEmpty(queue))
   {
      printf("Queue is empty.\n");
   }
   else
   {
      printf("Vehicles in the queue: ");
      struct Node *temp = queue->front;

      do
      {
         printf("%d ", temp->data);
         temp = temp->next;
      } while (temp != queue->front);

      printf("\n");
   }
}
