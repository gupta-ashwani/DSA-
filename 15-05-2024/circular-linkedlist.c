#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *temp;

void first_insert(){
    struct node *ptr;
    int x;
    ptr = (struct node *) malloc(sizeof(struct node ));
    if(ptr == NULL){
        printf("Linklist Overflow");
    } else{
        printf("Enter value: ");
        scanf("%d", &x);
        ptr -> data = x;
        temp = ptr;
        temp -> next = ptr;
        ptr -> next = head;
        head = ptr;
        printf("Node inserted at first");
    }
}

void last_insert(){
    struct node *ptr,*temp;
    int x;
    ptr = (struct node *) malloc(sizeof(struct node ));
    if(ptr == NULL){
        printf("Linklist Overflow");
    } else{
        printf("Enter value: ");
        scanf("%d", &x);
        ptr -> data = x;
        if(head == NULL){
            ptr -> next = ptr;
            head = ptr;
            printf("Node inserted at first");
        }
        else{
            temp = head;
            while(temp -> next != NULL){
                temp = temp-> next;
            }
            ptr -> next = temp -> next;
            temp -> next = ptr;
            
            printf("Node inserted at last");

        } 
    }
}

void random_insert(){
    struct node *ptr,*temp;
    int x,a, count = 1;
    ptr = (struct node *) malloc(sizeof(struct node ));
    if(ptr == NULL){
        printf("Linklist Overflow");
    } else{
        printf("Enter position of node after which you want to insert: ");
        scanf("%d", &a);
        if (a < 0) {
        printf("\nEnter a valid position");
        } else{
            printf("Enter value: ");
            scanf("%d", &x);
            ptr -> data = x;
            if(head == NULL){
                ptr -> next = ptr;
                head = ptr;
                printf("Node inserted at first");
            } else{
                if(a == 0){
                    ptr -> data = x;
                    temp = ptr;
                    temp -> next = ptr;
                    ptr -> next = head;
                    head = ptr;
                    printf("Node inserted at first");
                }else{
                    temp = head;
                    while(temp -> next != head && count != a){
                        temp = temp -> next;
                        count++;
                    }
                    ptr -> next = temp -> next;
                    temp -> next = ptr;
                    printf("Node inserted at %d", a);
                }
            }
        }
    }       
}

void first_delete(){
    struct node *ptr;
    if(head == NULL){
        printf("\nLisklist is Empty");
    } else{
        ptr = head ;
        temp = head;
        while(ptr -> next != head)
        {
            ptr = ptr -> next;
        }
        ptr -> next = head -> next;
        head = head -> next;
        free (temp);
        printf("\nFisrt Node Deleted");
        
    }
}

void last_delete(){
    struct node *ptr, *temp, *ptr1;
    if(head == NULL){
        printf("\nLisklist is Empty");
    } else if(head -> next == head){
        head = NULL;
        free(head);
        printf("\nNode Deleted");

    } else{
        temp = head;
        while(temp -> next != head){
            ptr1 = temp;
            temp = temp -> next;   
        }
        ptr1 -> next = head;
        free(temp);
        printf("\nLast Node Deleted");

    }
}

void random_delete(){
    struct node *ptr, *temp, *ptr1;
    int a, count = 1;

    if(head == NULL){
        printf("\nLisklist is Empty");
    } else if(head -> next == head){
        free(head);
        head = NULL;
        printf("First Node deleted ");
    } else{
        printf("Enter position of node which you want to delete: ");
        scanf("%d", &a);
        if(a<=0){
            printf("\nEnter valid position");
        }else {
            temp = head;
            if (a==1){
                head = head -> next;
                free(head);
                printf("\nNode deleted at position %d", a);
            } else{
                while(temp -> next != head && count != a){
                ptr1 = temp;
                temp = temp -> next;
                count++;
                }
                if(count == a){
                    ptr1 -> next = temp -> next;
                    free(temp);
                    printf("\n%d Node deleted", a);
                } else{
                    printf("\nPosition not found");
                }
            }
        }
    }
}

void search(){
    struct node *ptr;
    int a, count = 0, flag = 0;
    if(head == NULL){
        printf("\nLisklist is Empty");
    } else{
        ptr = head;
        printf("\nEnter value you want to search :");
        scanf("%d", &a);

        while(ptr != NULL){
            count++;
            if(ptr -> data == a){
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

void display(){
    struct node *ptr;
    ptr = head;
    if (ptr == NULL){
        printf("Lisklist is Empty");
    } else{
        // while(ptr != head){
        //     printf("%d\t", ptr -> data);
        //     ptr = ptr -> next;
        // }
        for(ptr = ptr -> next; ptr != head; ptr = ptr -> next){
            printf("%d\t", ptr -> data);
        }
    }
}

int main(){
    printf("\nCircular Link list\n");
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
    do{
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
            random_insert(); 
            break;
        case 4:
            first_delete(); 
            break;
        case 5:
            last_delete(); 
            break;
        case 6:
            random_delete(); 
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
    } while(choice!=0);
    return 0;
}
