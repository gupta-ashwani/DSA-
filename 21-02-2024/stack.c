//Performing push, pop, peep and display in stack of max size of 5.


#include<stdio.h>
#define max 5
int top = -1;
int stack[max];


void push (){
    if (top == max-1){
            printf("Stack overflow\n");
    }
    else{
        int n;
        printf("Enter element to push: ");
        scanf("%d", &n);
        top++;
        stack[top] = n;
    }
}

void pop(){
    if(top == -1){
        printf("Stack Underflow!!!\n");
    }
    else{
        printf("Poped element: %d\n", stack[top]);
        top--;
    }
}

void peep(){
    int n;
    printf("Enter element to search: ");
    scanf("%d", &n);
    if(top == -1){
        printf("Stack Underflow!!!\n");
    }
    else{
        for(int i = 0; i <=top; i++){
            if (stack[i] == n){
                printf("%d is present in %d index. \n", n,i);
            }
        }
    }
}

void display(){
    if(top == -1){
        printf("Stack Underflow!!!\n");
    }
    else{
        for (int i=top;i>= 0;i--){
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{
    int choice;
    do{
        printf("\nEnter 1 to Push element: \n");
        printf("Enter 2 to Pop element: \n");
        printf("Enter 3 to Peep element: \n");
        printf("Enter 4 to display element: \n");
        printf("Enter 0 to exit:  \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("Exited Program Successfully...");
            break;
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            display();
            break;
        default:
            printf("Enter valid number!!\n");
            break;
        }
    }
    
    while(choice != 0);
    return 0;
}
