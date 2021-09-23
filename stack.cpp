#include<bits/stdc++.h>
using namespace std;

//using array
// struct Stack
// {
// 	int size;
// 	int tp;
// 	int *s;
// 	void Push(int);
// 	int Pop();
// 	int Peek(int);
// 	bool isFull();
// 	bool isEmpty();
// 	int Top();
// 	void Create(int);
// };
// void Stack::Push(int x)
// {
// 	if(tp == size-1)
// 		cout << "Overflow\n";
// 	else
// 		s[++tp]=x;
// 	return;
// }
// int Stack::Pop()
// {
// 	int x = -1;
// 	if(tp == -1)
// 		cout << "Underflow\n";
// 	else
// 		x=s[tp--];
// 	return x;
// }
// int Stack::Peek(int index)
// {
// 	int x = -1;
// 	if(tp-index+1<0)
// 		cout << "Invalid peek request\n";
// 	else
// 		x = s[tp - index + 1];
// 	return x;
// }
// bool Stack::isFull()
// {
// 	if(tp == size-1)
// 		return 1;
// 	return 0;
// }
// bool Stack::isEmpty()
// {
// 	if(tp == -1)
// 		return 1;
// 	return 0;
// }
// int Stack::Top()
// {
// 	int x = -1;
// 	if(tp == -1)
// 		cout << "Empty\n";
// 	else
// 		x = s[tp];
// 	return x;
// }
// void Stack::Create(int sz)
// {
// 	size = sz;
// 	tp = -1;
// 	s = new int[size];
// }
// int main()
// {
// 	Stack st;
// 	st.Create(5);
// 	cout << st.isFull() << "\n";
//     st.Push(9);
//     cout << st.Top() << "\n";
//     cout << st.Pop() << "\n";
//     cout << st.Pop() << "\n";
// 	return 0;
// }


//using linked lsit
struct node
{
    int val;
    node *next;
    node(int x)
    {
        val = x;
        next = NULL;
    }
};
struct Stack
{
	node *tp;
    Stack()
    {
        tp = NULL;
    }
	void Push(int);
	int Pop();
	int Peek(int);
	bool isFull();
	bool isEmpty();
	int Top();
	void Create(int);
};
void Stack::Push(int x)
{
    node *cur = new node(x);
    if(cur == NULL)
        cout << "Overflow\n";
    else 
    {
        cur->next=tp;
        tp = cur;
    }
	return;
}
int Stack::Pop()
{
	int x = -1;
	if(tp == NULL)
		cout << "Underflow\n";
	else
	{
        x= tp->val;
        node *temp = tp;
        tp = tp->next;
        free(temp);
    }
	return x;
}
int Stack::Peek(int index)
{
	int x = -1;
	if(tp==NULL)
		x = -1;
	else
	{
        int ind = 1;
        for(node *temp = tp; ind<=index && temp != NULL; temp = temp->next, ind++)
            if(ind==index)
            {
                x = temp->val;
                break;
            }
    }
	if(x==-1)
        cout << "Invalid peek request\n";
    return x;
}
bool Stack::isFull()
{
    node *test = new node(3);
	if(test == NULL)
		return 1;
	return 0;
}
bool Stack::isEmpty()
{
	if(tp == NULL)
		return 1;
	return 0;
}
int Stack::Top()
{
	int x = -1;
	if(tp == NULL)
		cout << "Empty\n";
	else
		x = tp->val;
	return x;
}
int main()
{
	Stack st;
	cout << st.isFull() << "\n";
    st.Push(9);
    cout << st.Top() << "\n";
    cout << st.Pop() << "\n";
    cout << st.Pop() << "\n";
    st.Push(5);
    st.Push(7);
    st.Push(4);
    st.Push(3);
    cout << st.Top() << "\n";
    cout << st.Peek(3) << "\n";
	return 0;
}