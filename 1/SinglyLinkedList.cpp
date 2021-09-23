#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *next;
};
struct SinglyLinkedList
{
	node head, tail;
	SinglyLinkedList()
	{
		head.val = -1;
		head.next = 0;
		tail.val = -1;
		tail.next = 0;
	}
	void push(int x)
	{
		node cur ;
		cur.val = x;
		cur.next = 0;
		if(head.val == -1)
			head = tail = cur;
		else
			tail.next = &cur;
		return;
	}
	void printList()
	{
		if(head.val==-1)
			cout << "Empty List\n";
		else 
			for(node temp = head; ;temp = *(temp.next))
			{
				cout << temp.val << " ";
				if(temp.next==0)
				{
					cout << "\n";
					break;
				}
			}
		return;
	}
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	SinglyLinkedList s1;
	s1.printList();
	s1.push(3);
	s1.printList();
		s1.push(2);
	s1.printList();	s1.push(1);
	s1.printList();	s1.push(4);
	s1.printList();	s1.push(5);
	s1.printList();	s1.push(6);
	s1.printList();	s1.push(7);
	s1.printList();	s1.push(8);
	s1.printList();	s1.push(9);
	s1.printList();	s1.push(10);
	s1.printList();	s1.push(3);
	s1.printList();
	return 0;
}