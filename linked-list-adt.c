#include <stdio.h>
#include <stdlib.h>

void displayList();
void count();
void insertAtBeg();
void insertAtEnd();
void insertAtPosition();
void deleteFirst();
void deleteLast();
void deletePosition();
void sort();
void reverse();
void maximum();
void mean();

struct node {
    int data;
    struct node* next;
};
struct node* start = NULL;

void main()
{
    int choice;
    while ("Dev")
    {
        printf("\n\nMENU\n");
        printf("1 Display the list\n");
        printf("2 Display number of elements in the list\n");
        printf("3 Insert element at Start\n");
        printf("4 Insert element at End\n");
        printf("5 Insert element at a particular position\n");
        printf("6 Delete the first element\n");
        printf("7 Delete the last element\n");
        printf("8 Delete element at a particular position\n");
        printf("9 Sort the list in ascending order\n");
        printf("10 Reverse the linked list\n");
        printf("11 Find the maximum among the elements\n");
        printf("12 Find the mean of the elements\n");
        printf("13 Exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                displayList();
                break;
            case 2:
                count();
                break;
            case 3:
                insertAtBeg();
                printf("Updated list:\n");
                displayList();
                break;
            case 4:
                insertAtEnd();
                printf("Updated list:\n");
                displayList();
                break;
            case 5:
                insertAtPosition();
                printf("Updated list:\n");
                displayList();
                break;
            case 6:
                deleteFirst();
                printf("Updated list:\n");
                displayList();
                break;
            case 7:
                deleteLast();
                printf("Updated list:\n");
                displayList();
                break;
            case 8:
                deletePosition();
                printf("Updated list:\n");
                displayList();
                break;
            case 9:
                sort();
                printf("Updated list:\n");
                displayList();
                break;
            case 10:
                reverse();
                break;
            case 11:
                maximum();
                break;
            case 12:
                mean();
                break;
            case 13:
                exit(1);
                break;
            default:
                printf("Incorrect Choice\n");
        }
    }
}
 
void displayList()
{
    struct node* ptr;
    if (start == NULL)
        printf("\nList is empty\n");
    else 
    {
        ptr = start;
        while (ptr != NULL) 
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}

void count()
{
    int count =0;
    struct node* ptr;
    if(start == NULL)
        printf("\nList is Empty\n");
    else
    {
        ptr = start;
        while(ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        printf("Number of values = %d",count);
    }
}

void insertAtBeg()
{
    int data;
    struct node* ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    ptr->data = data;
    ptr->next = start;
    start = ptr;
}

void insertAtEnd()
{
    int value;
    struct node *ptr, *head;
    ptr =(struct node*) malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &value);
    ptr->next= 0;
    ptr->data = value;
    head = start;
    while (head->next!= NULL) 
    {
        head = head->next;
    }
    head->next= ptr;
}
 
void insertAtPosition()
{
    struct node *ptr, *newnode;
    int pos, value, i = 1;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter position and data :");
    scanf("%d%d", &pos,&value);
    ptr = start;
    newnode->data = value;
    newnode->next= 0;
    while (i < pos- 1) 
    {
        ptr = ptr->next;
        i++;
    }
    newnode->next= ptr->next;
    ptr->next= newnode;
}
 
void deleteFirst()
{
    struct node* ptr;
    if (start == NULL)
        printf("\nList is empty\n");
    else 
    {
        ptr = start;
        start = start->next;
        free(ptr);
    }
}
 
void deleteLast()
{
    struct node *ptr, *prevnode;
    if (start == NULL)
        printf("\nList is Empty\n");
    else
    {
        ptr = start;
        while (ptr->next!= 0) 
        {
            prevnode = ptr;
            ptr = ptr->next;
        }
        free(ptr);
        prevnode->next= 0;
    }
}
 
void deletePosition()
{
    struct node *ptr, *position;
    int i = 1, pos;
    if (start == NULL)
        printf("\nList is empty\n");
    else 
    {
        printf("\nEnter position that data is to be deleted from: ");
        scanf("%d", &pos);
        position = (struct node*)malloc(sizeof(struct node));
        ptr = start;
        while (i < pos - 1) 
        {
            ptr = ptr->next;
            i++;
        }
        position = ptr->next;
        ptr->next= position->next;
        free(position);
    }
}
 
void sort()
{
    struct node* current = start;
    struct node* index = NULL;
    int temp;
    if (start == NULL)
        printf("List is empty");
    else 
    {
        while (current != NULL)
        {
            index = current->next;
            while (index != NULL)
            {
                if (current->data > index->data) 
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}
 
void reverse()
{
    struct node *t1, *t2, *ptr;
    t1 = t2 = NULL;
 
    if (start == NULL)
        printf("List is empty\n");
    else 
    {
        while (start != NULL) 
        {
            t2 = start->next;
            start->next= t1;
            t1 = start;
            start = t2;
        }
        start = t1;
        ptr = start;
        printf("Reversed linked list is : ");
        while (ptr != NULL) 
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

void maximum()
{
    int max;
    struct node* ptr;
    if (start == NULL)
        printf("\nList is empty\n");
    else 
    {
        ptr = start;
        max = ptr->data;
        while (ptr != NULL) 
        {
 
            if (max < ptr->data)
                max = ptr->data;
            ptr = ptr->next;
        }
        printf("\nMaximum number is : %d ", max);
    }
}

void mean()
{
    int count=0;
    float m,sum=0;
    struct node* ptr;
    if (start == NULL)
        printf("\nList is empty\n");
    else 
    {
        ptr = start;
        while (ptr != NULL) 
        {
            sum = sum + ptr->data;
            ptr = ptr->next;
            count++;
        }
        m = sum/count;
        printf("\nMean is %0.2f ", m);
    }
}
