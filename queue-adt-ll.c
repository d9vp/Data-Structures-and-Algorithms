//Dev Patel - 60009200016

#include<stdio.h>   
#include<stdlib.h>  

struct node   
{  
    int data;   
    struct node *next;  
};  

struct node *front;  
struct node *rear;   

void enqueue();  
void dequeue();  
void display();  
void count();

void main ()  
{  
    int choice;   
    while("Dev")   
    {     
        printf("\nMENU\n");  
        printf("\n1. Insert an element\n2. Delete an element\n3. Display the queue\n4. Count number of elements\n5. Exit\n");  
        printf("\nEnter your choice: ");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1:  
            enqueue();  
            break;  
            case 2:  
            dequeue();  
            break;  
            case 3:  
            display();  
            break;  
            case 4:
            count();
            break;
            case 5:  
            exit(0);  
            break;  
            default:   
            printf("\nPlease enter valid choice\n");  
            break;
        }  
    }  
}  

void enqueue()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOverflow\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter value: \n");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}  

void dequeue ()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nUnderflow.\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  

void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nQueue is displayed:\n");  
        while(ptr != NULL)   
        {  
            printf("%d\t",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}  

void count()
{
    int count = 0;
    struct node *ptr;
    ptr = front;
    
    while(ptr!=NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("Number of elements = %d",count);
}
