#include<stdio.h>

struct node
{
    int data;
    struct node*next;

};
struct node*front = NULL;
struct node*rear = NULL;

void enqueue()
{
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    int item;
    printf("Enter a item : ");
    scanf("%d" , &item);
    temp->data = item;
    temp->next = NULL;

    if(rear==NULL || front == NULL)
    {
        front=rear=temp;
    }
    else
    {
        temp->next = rear;
        rear = temp;
        struct node*t;

        t = rear;

        while(t->next!=NULL)
        {
            t = t->next;
        }
        front =t;

    }


}

void rear_node()
{
    if(rear!=NULL){
    printf("%d" , rear->data);
    }
    else
    {
        printf("Queue is Empty");

    }
}

void front_node()
{
    if(front!=NULL){
    printf("%d" , front->data);
    }
    else
    {
        printf("Queue is Empty");

    }
}




void dequeue()
{
    if(front==NULL ||  rear==NULL)
    {

        return;
    }
    if(rear->next==NULL)
    {
         rear = NULL;
    }
    else
    {
        struct node*temp , *temp1;
        temp=rear;

        while(temp->next!=NULL)
        {
            temp1 = temp;
            temp = temp->next;

        }

        temp1->next = NULL;
        front = temp1;
        free(temp);

    }
}

void display()
{
    struct node*temp;
    if(front==NULL || rear==NULL)
    {
        printf("Queue is Empty");
        return;
    }
    else
    {
        temp = rear;
        printf("Queue is : ");
        while(temp!=NULL)
        {
            printf("%d " ,temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("1 Insert \n");
        printf("2 Rear node\n");
        printf("3 Front Node\n");
        printf("4 Delete \n");
        printf("5 Exit\n");
        printf("Enter your choice : ");
        scanf("%d" , &ch);

        switch(ch)
        {
        case 1:
            enqueue();
            display();
            printf("\n");
            break;
        case 2:
            rear_node();
            printf("\n");
            break;
        case 3:
            front_node();
            printf("\n");
            break;

        case 4:
            dequeue();
            display();
            printf("\n");
            break;
        case 5:
            exit(0);

        }
    }
}

