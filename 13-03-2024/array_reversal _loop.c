//array reversal using loop
#include <stdio.h>
int main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++){
        printf("Enter %d element of array: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Reverse of array is: \n");
    for(int i = size-1; i >= 0; i--){
        printf("%d\t", arr[i]);
    }
    return 0;
}
