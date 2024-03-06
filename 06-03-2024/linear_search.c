#include <stdio.h>

int main() {
    int size,ele,index = 0, flag = 0;
    printf("Enter the size of an array: ");
    scanf("%d",&size);
   
    int arr[size];
    for(int i=0;i<=size-1;i++)
    {
        printf("Enter the %d element in an array: ", i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the element that you need to find in an array: ");
    scanf("%d",&ele);
    for(int i=0; i<size; i++){
        if(arr[i] == ele){
            printf("%d is present in %d index", ele, index);
            flag = 1;
            break;
        }
        else{
            index++;
        } 
    }
    if(flag == 0){
        printf("%d is not present", ele);
    }
    return 0;
}
