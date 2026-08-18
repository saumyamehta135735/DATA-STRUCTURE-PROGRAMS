//92500588037
// Write a program of dynamic queue

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void insert()
{
    int value;

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert : ");
    scanf("%d",&value);
    newNode->data = value;
    newNode->next = NULL;

    if(rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted into Queue.\n",value);
}

void delete_element()
{
    if(front == NULL)
    {
        printf("Stack Underflow! Stack is Empty. \n");
    }
    else
    {
        struct Node *temp = front;
        printf("%d deleted from Queue.\n",front->data);
        front = front->next;
        if(front == NULL)
        {
            rear = NULL;
        }
        free(temp);
    }
}

void display()
{
    struct Node *temp = front;
    if(temp == NULL)
    {
        printf("Queue is Empty. \n");
    }
    else
    {
        printf("Queue Element are : \n");
        while(temp != NULL)
        {
            printf("%d \n",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main()
{
    int choice;
    while(1)
    {
        printf("\n1. INSERT\n2. DELETE\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete_element();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }
}
