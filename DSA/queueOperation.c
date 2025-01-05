#include <stdio.h>
#define max 6

int queue[max];
int front = -1;
int rear = -1;

void enqueue(int element)
{
  if ((rear + 1) % max == front)
  {
    printf("Queue is overflow\n");
  }
  else if (front == -1 && rear == -1)
  {
    front = 0;
    rear = 0;
    queue[rear] = element;
  }
  else
  {
    rear = (rear + 1) % max;
    queue[rear] = element;
  }
}

void dequeue()
{
  if (front == -1 && rear == -1)
  {
    printf("The queue is empty\n");
  }
  else if (front == rear) // Single element left
  {
    printf("The dequeued value is %d\n", queue[front]);
    front = -1;
    rear = -1;
  }
  else
  {
    printf("The dequeued value is %d\n", queue[front]);
    front = (front + 1) % max; // Move front to the next position
  }
}

void display()
{
  if (front == -1 && rear == -1)
  {
    printf("The queue is empty\n");
  }
  else
  {
    int i = front;
    printf("Queue elements are: ");
    while (i != rear)
    {
      printf("%d ", queue[i]);
      i = (i + 1) % max;
    }
    printf("%d\n", queue[rear]);
  }
}

int main()
{
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);
  display();
  dequeue();
  display();
  enqueue(60);
  display();
  enqueue(70);
  display();

  return 0;
}
