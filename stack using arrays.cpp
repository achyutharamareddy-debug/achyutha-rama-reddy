# include<stdio.h>
# define MAX 5
int stack[MAX];
int top=-1;
void push()
{
    int a;
    if(top==MAX-1)
    {
        printf("\noverflow");
    }
    else
    {
        printf("\nenter data: ");
        scanf("%d",&a);
        top++;
        stack[top]=a;
    }
}
void pop()
{
    int temp;
    if(top==-1)
    {
        printf("\nstack is empty");
    }
    else
    {
        temp=stack[top];
        printf("\npoped item is: %d",temp);
        top--;
    }
}
void peek()
{
    if(top==-1)
    {
        printf("\nstack is underflow");
    }
    else
    {
        printf("\ntop most element is: %d",stack[top]);
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("\nstack is empty");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("\n%d",stack[i]);
        }
    }
}
int main()
{
    int choice,ch;
    while(ch)
    {
        printf("\nstack menu");
        printf("\n1 push()\n2.pop()\n3.peek()\n4.display()");
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            default:
            printf("\ninvalid option");
        }
        printf("\nDO YOU WANT ANOTHER OPTION: ");
        scanf("%d",&ch);
    }
    return 0;
}
