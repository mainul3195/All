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

//assignment code
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
//assignment function ends here

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
    //extra code for assignment
    printf("Enter the number and position: ");
    scanf("%d %d", &x, &pos);
    insertAtPos(x, pos);
    printf("\nList after insertion:\n");
    print();
    //extra code ends here
    return 0;
}

