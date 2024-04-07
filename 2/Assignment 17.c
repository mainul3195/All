#include <stdio.h>
#include <malloc.h>

struct node
{
    int val;
    struct node *next;
}*start;

void insert(int val)
{
    struct node *cur = (struct node*) malloc(sizeof(struct node)), *temp;
    cur->val = val;
    cur->next = NULL;
    if(start==NULL)
    {
        start = cur;
        return;
    }
    temp = start;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = cur;
}

void deleteStart()
{
    if(start==NULL)
    {
        puts("Underflow!");
        return;
    }
    struct node *temp = start;
    start = start->next;
    free(temp);
}

void insertAtPos(int val, int pos)
{
    int i=2;
    struct node *cur = (struct node*) malloc(sizeof(struct node)), *temp1,*temp2;
    cur->val = val;
    temp1 = start;
    if(pos==1)
    {
        cur->next=temp1;
        start=cur;
        return;
    }
    while(i<pos)
    {
        temp1 = temp1->next;
        i++;
    }
    temp2 = temp1->next;
    temp1->next=cur;
    cur->next=temp2;
}
void deleteAtPos(int pos)
{
    struct node *temp = start,*temp2;
    if(pos==1)
    {
        start = start->next;
        free(temp);
    }
    else
    {
        while(pos-->2)
        {
            temp = temp->next;
        }
        temp2 = temp -> next;
        temp->next = temp2->next;

        free(temp2);
    }


}
void deleteVal(int val)
{
    struct node *temp = start,*temp2;
    if(start->val == val)
    {
        start = start->next;
        free(temp);
    }
    else
    {
        temp2 = temp -> next;
        while(temp2->val!=val)
        {
            temp = temp->next;
            temp2= temp2->next;
        }
        temp->next = temp2->next;

        free(temp2);
    }

}

void print()
{
    struct node *temp;
    if(start==NULL)
    {
        puts("List Empty!");
        return;
    }
    temp = start;
    printf("List: ");
    do
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    while(temp!=NULL);
    puts("");
}

int main()
{
    start=NULL;
    int n, i, x,pos;

    scanf("%d", &n);
    print();
    for (i=0; i<n; i++)
    {
        scanf("%d", &x);
        insert(x);
        print();
    }
    printf("Enter the number and position: ");
    scanf("%d %d", &x, &pos);
    insertAtPos(x, pos);
    printf("\nList after insertion:\n");
    print();


    deleteStart();
    print();


    printf("Enter the position you want to delete...");
    scanf("%d",&x);
    deleteAtPos(x);
    print();
    printf("Enter the value you want to delete...");
    scanf("%d",&x);
    deleteVal(x);
    print();


    return 0;
}
