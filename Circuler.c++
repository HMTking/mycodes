#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int info;
    struct node* link;
};
struct node* start = NULL;

void createList()
{
    if (start == NULL) {
        int n,i;
        i=1;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        if (n > 0) 
        {
            int data;
            struct node* newnode;
            struct node* temp;
            newnode = (struct node *)malloc(sizeof(struct node));
            start = newnode;
            temp = start;
            printf("\nEnter number to be inserted at %d : ",i);
            scanf("%d", &data);
            start->info = data;
            i++;
            for (i; i <= n; i++) {
                newnode = malloc(sizeof(struct node));
                temp->link = newnode;
                printf("\nEnter number to be inserted at %d : ",i);
                scanf("%d", &data);
                newnode->info = data;
                temp = temp->link;
            }
            temp->link = start;
        }
        printf("\nThe list is created\n");
    }
    else
        printf("\nThe list is already created\n");
}

void traverse()
{
    struct node* temp;

    if (start == NULL)
        printf("\nList is empty\n");

    else 
    {   temp = start;
        do 
        {
            printf("Data = %d\n", temp->info);
            temp = temp->link;
        }while (temp->link != start) ;
    }
}

void traversalAtPosition()
{
    int pos,i;
    i=1;
    struct node* temp;
    printf("\nEnter Position for"
        " Traversal : ");
    scanf("%d", &pos);
    if (start == NULL)
        printf("\nList is empty\n");

    else 
    {   
        temp = start;
        do 
        {
            if (i>=pos)
            {
                printf("Data = %d\n", temp->info);
                temp = temp->link;
            }
            else
                temp = temp->link;
            i++;
        }while (temp->link != start) ;
    }
}

void insertAtFront()
{
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
        " be inserted : ");
    scanf("%d", &data);
    temp->info = data;
    temp->link = start;
    start = temp;
}

void insertAtEnd()
{
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));

    printf("\nEnter number to"
        " be inserted : ");
    scanf("%d", &data);

    temp->link = start;
    temp->info = data;
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}

int getsize()
{
    struct node* temp;
    int i;
    i=0;
    if (start == NULL)
        return i;
    else 
    {   temp = start;
        i=1;
        while (temp->link != start) 
        {
            i++;
            temp = temp->link;
        }
        return i;
    }
}

void insertAtPosition()
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));

    printf("\nEnter position :");
    scanf("%d %d", &pos);

    if (pos == 1)
    {
        void insertAtFront();
    }
    else if (pos == getsize())
    {
        void insertAtEnd();
    }
    else
    {
        printf("\nEnter number to"
                " be inserted : ");
        scanf("%d", &data);
        temp = start;
        newnode->info = data;
        newnode->link = 0;
        while (i < pos - 1) 
        {
            temp = temp->link;
            i++;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
}

void deleteFirst()
{
    struct node* temp,*t1;
    if (start == NULL)
        printf("\nList is empty\n");
    else 
    {
        t1 = start;
        start = start->link;
        temp = start;
        do {
            printf("Data = %d\n", temp->info);
            temp = temp->link;
        } while (temp->link != start) ;
        
        temp->link = start;
    }
}

void deleteEnd()
{
    struct node *temp, *prevnode;
    if (start == NULL)
        printf("\nList is Empty\n");
    else {
        temp = start;
        do 
        {
            printf("Data = %d\n", temp->info);
            prevnode = temp;
            temp = temp->link;
        }while (temp->link != start) ;
        free(temp);
        prevnode->link = start;
    }
}

void deletePosition()
{
    struct node *temp, *position;
    int i = 1, pos;

    if (start == NULL)
        printf("\nList is empty\n");

    else {
        printf("\nEnter index : ");
        scanf("%d", &pos);
        if (pos == 1)
        {
            void deleteFirst();
        }
        else if (pos == getsize())
        {
            void deleteEnd();
        }
        else
        {
            position = malloc(sizeof(struct node));
            temp = start;

            while (i < pos - 1) {
                temp = temp->link;
                i++;
            }
            position = temp->link;
            temp->link = position->link;
            free(position);
        }
    }
}
int main()
{
    int choice;
    while (1) 
    {
        printf("\n\t1 To Creation of "
            "Linked list\n");
        printf("\t2 To see list\n");
        printf("\t3 For insertion at"
            " starting\n");
        printf("\t4 For insertion at"
            " end\n");
        printf("\t5 For insertion at "
            "any position\n");
        printf("\t6 For deletion of "
            "first element\n");
        printf("\t7 For deletion of "
            "last element\n");
        printf("\t8 For deletion of "
            "element at any position\n");
        printf("\t9 For Traversal from "
            "any position\n");
        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createList();
            break;
        case 2:
            traverse();
            break;
        case 3:
            insertAtFront();
            break;
        case 4:
            insertAtEnd();
            break;
        case 5:
            insertAtPosition();
            break;
        case 6:
            deleteFirst();
            break;
        case 7:
            deleteEnd();
            break;
        case 8:
            deletePosition();
            break;
        case 9:
            traversalAtPosition();
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}

