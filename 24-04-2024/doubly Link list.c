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
        ptr->next = head;
        ptr->prev = NULL;
        head -> prev = ptr;
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
        case 8:
            display();
            break;
        default:
            printf("Enter valid choice!!!\n");
            break;
        }
    } while (choice != 0);
}
