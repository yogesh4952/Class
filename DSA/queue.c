#include <stdio.h>
#include <stdbool.h>
#define SIZE 5
int queue[SIZE];
int rear = -1,front = -1;

bool isEmpty()
{
	return rear == -1;
}

bool isFull()
{
	return rear == SIZE -1;
}

void enqueue(int x)
{
	if(isFull())
	{
		printf("Queue is full! Overflow Conditin\n");
		return;
	}else{
		front=0;
		queue[++rear]=x;
	}

}


void dequeue()
{
	if(isEmpty())
	{
		printf("Queue is empty! Underflow Condition\n");
		return;
	}else{
		front ++;
	}
}


void show()
{
	for(int i = front  ; i <= rear;i++)
	{
		printf("%d\n",queue[i] );
	}
}
int main()
{
	enqueue(5);
	enqueue(0);
	enqueue(85);
	enqueue(10);
	enqueue(07);
	show();
	
	printf("After Dequeue\n");
	dequeue();
	show();
	return 0;
}