#include<iostream>
using namespace std;
struct Queue
{
	int front, back, size, *q;
	Queue(int x)
	{
		front = 0;
		back = 0;
		size = x;
		q = (int *)malloc(x*sizeof(int));
	}
	void enQueue(int);
	int deQueue();
	bool isFull();
	bool isEmpty();
	void displayQueue();
};
bool Queue::isEmpty()
{
	if(back == front)
		return true;
	return false;
}
bool Queue::isFull()
{
	if((back+1)%size==front)
		return true;
	return false;
}
void Queue::enQueue(int x)
{
	if((back+1)%size == front)
		cout << "Queue is full\n";
	else
	{
		back = (back+1)%size;
		q[back]=x;
	}
	return;
}
int Queue::deQueue()
{
	if(back == front)
		cout << "Queue is empty\n";
	else
	{
		front = (front +1)%size;
		return q[front];
	}
}
void Queue::displayQueue()
{
	//cout << "back = " << back << "   |||   front = " << front << "    |||";
	if(back == front)
		cout << "Queue is empty\n";
	else
		for(int i=(front+1)%size;; i=(++i)%size)
		{
			cout << q[i] << " " ;
			if(i==back)
			{
				cout << "\n";break;
			}
		}
	return;
}
int main()
{
	Queue que(7);
	que.displayQueue();
	que.enQueue(5);
	que.displayQueue();
	que.enQueue(6);
	que.displayQueue();	que.enQueue(7);
	que.displayQueue();	que.enQueue(8);
	que.displayQueue();	que.enQueue(9);
	que.displayQueue();	que.enQueue(10);
	que.displayQueue();	que.enQueue(11);
	que.displayQueue();	que.enQueue(12);
	cout << que.isFull() << " " << que.isEmpty() << "\n";

	que.displayQueue();que.deQueue();
	cout << que.isFull() << " " << que.isEmpty() << "\n";

	que.displayQueue();que.deQueue();
	que.displayQueue();que.deQueue();
	que.displayQueue();que.deQueue();
	que.displayQueue();que.deQueue();
	que.displayQueue();que.deQueue();
	que.displayQueue();que.deQueue();
	que.displayQueue();que.deQueue();
	que.displayQueue();que.deQueue();
	que.displayQueue();que.deQueue();
	cout << que.isFull() << " " << que.isEmpty() << "\n";

}