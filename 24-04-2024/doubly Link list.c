#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;

void first_insert()
{
    struct node *ptr;
    int value;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Linklist Overflow");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);
        ptr->data = value;
        ptr->next = head;
        ptr->prev = NULL;
        head = ptr;
        printf("Node inserted at first");
    }
}

void last_insert()
{
    struct node *ptr, *temp;
    int x;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Linklist Overflow");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &x);
        ptr->data = x;
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
            printf("Node inserted at first");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
            printf("Node inserted at last");
        }
    }
}

void index_insert(){
    struct node *ptr,*temp;
    int value,index, count = 1;
    ptr = (struct node *) malloc(sizeof(struct node ));
    if(ptr == NULL){
        printf("Linklist Overflow");
    } else{
        printf("Enter index at which you want to insert: ");
        scanf("%d", &index);
        if (index < 0) {
        printf("\nEnter a valid index");
        } else{
            printf("Enter value: ");
            scanf("%d", &value);
            ptr -> data = value;
            if(head == NULL){
                ptr -> next = NULL;
                ptr -> prev = NULL;
                head = ptr;
                printf("Node inserted at first");
            } else{
                if(index==0){
                    ptr -> data = value;
                    ptr -> next = head;
                    head = ptr;
                    //first_insert(); //not using fuction because it is taking input two times.
                    printf("Node inserted at first");
                }else{
                    temp = head;
                    while(temp -> next != NULL && count != index){
                        temp = temp -> next;
                        count++;
                    }
                    (temp -> next) -> prev = ptr;
                    ptr -> next = temp -> next;
                    ptr -> prev = temp;
                    temp -> next = ptr;
                    printf("Node inserted at %d", index);
                }

            }
        }
    }
}

void first_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nLisklist is Empty");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        (ptr-> next) -> prev = NULL;
        free(ptr);
        printf("\nFisrt Node Deleted");
    }
}

void last_delete()
{
    struct node *ptr, *temp, *ptr1;
    if (head == NULL)
    {
        printf("\nLisklist is Empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nNode Deleted");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            ptr1 = temp;
            temp = temp->next;
        }
        ptr1->next = NULL;
        free(temp);
        printf("\nLast Node Deleted");
    }
}

void index_delete(){
    struct node *ptr, *temp, *ptr1;
    int index, count = 0;

    if(head == NULL){
        printf("\nLisklist is Empty");
    } else if(head -> next == NULL){
        head = NULL;
        free(head);
        printf("First Node deleted ");
    } else{
        printf("Enter index which you want to delete: ");
        scanf("%d", &index);
        if(index<0){
            printf("\nEnter valid position");
        }else {

            if (index==0){
                first_delete();
            } else{
                temp = head;
                while(temp -> next != NULL && count != index){
                ptr1 = temp;
                temp = temp -> next;
                count++;
                }
                ptr1 -> next = temp -> next;
                (temp -> next) -> prev = ptr1;
                free(temp);
                printf("%d Node deleted", index);
            }
        }

    }
}

void search(){
    struct node *ptr;
    int value, count = 0, flag = 0;
    if(head == NULL){
        printf("\nLisklist is Empty");
    } else{
        ptr = head;
        printf("\nEnter value you want to search :");
        scanf("%d", &value);

        while(ptr != NULL){
            count++;
            if(ptr -> data == value){
                flag = 1;
                printf("\nNumber found at %d node", count);
                break;
            }
            ptr = ptr -> next;
        }

        if(flag == 0){
            printf("\nNumber not found!!!");
        } else{
        }
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Lisklist is Empty");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
    printf("\n0.Exit\n");
    printf("1.Insert in begining\n");
    printf("2.Insert at last\n");
    printf("3.Insert at any specified location\n");
    printf("4.Delete from Beginning\n");
    printf("5.Delete from last\n");
    printf("6.Delete node after specified location \n");
    printf("7.Search for an element\n");
    printf("8.Display all nodes\n");
    int choice;
    do
    {
        printf("\nEnter chioce: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            break;
        case 1:
            first_insert();
            break;
        case 2:
            last_insert();
            break;
        case 3:
            index_insert();
            break;
        case 4:
            first_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            index_delete();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        default:
            printf("Enter valid choice!!!\n");
            break;
        }
    } while (choice != 0);
}
