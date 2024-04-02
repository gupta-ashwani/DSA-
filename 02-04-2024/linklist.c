#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

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
            ptr -> next = NULL;
            head = ptr;
            printf("Node inserted at first");
        }
        else{
            temp = head;
            while(temp -> next != NULL){
                temp = temp-> next;
            }
            temp -> next = ptr;
            ptr -> next = NULL;
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
        printf("Enter number of node after which you want to insert: ");
        scanf("%d", &a);
        if (a < 0) {
        printf("\nEnter a valid position");
        } else{
            printf("Enter value: ");
            scanf("%d", &x);
            ptr -> data = x;
            if(head == NULL){
                ptr -> next = NULL;
                head = ptr;
                printf("Node inserted at first");
            } else{
                if(a==0){
                    ptr -> data = x;
                    ptr -> next = head;
                    head = ptr;
                    printf("Node inserted at first");
                }else{
                    temp = head;
                    while(temp -> next != NULL && count != a){
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
        ptr = head;
        head = ptr -> next;
        free (ptr);
        printf("\nFisrt Node Deleted");
        
    }
}

void last_delete(){
    struct node *ptr, *temp, *ptr1;
    if(head == NULL){
        printf("\nLisklist is Empty");
    } else if(head -> next == NULL){
        head = NULL;
        free(head);
        printf("\nNode Deleted");

    } else{
        temp = head;
        while(temp -> next != NULL){
            ptr1 = temp;
            temp = temp -> next;   
        }
        ptr1 -> next = NULL;
        free(temp);
        printf("\nLast Node Deleted");

    }
}

void random_delete(){
    struct node *ptr, *temp, *ptr1;
    int a, count = 1;

    if(head == NULL){
        printf("\nLisklist is Empty");
    } else if(head -> next == NULL){
        head = NULL;
        free(head);
        printf("First Node deleted ");
    } else{
        printf("Enter number of node which you want to delete: ");
        scanf("%d", &a);
        if(a<=0){
            printf("\nEnter valid position");
        }else {
            
            if (a==1){
                first_delete();
            } else{
                temp = head;
                while(temp -> next != NULL && count != a){
                ptr1 = temp;
                temp = temp -> next;
                count++;
                }
                ptr1 -> next = temp -> next;
                free(temp);
                printf("%d Node deleted", a);
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
        while(ptr != NULL){
            printf("\n%d", ptr -> data);
            ptr = ptr -> next;
        }
    }
}

int main(){
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
}
