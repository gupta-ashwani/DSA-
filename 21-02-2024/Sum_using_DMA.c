//Sum of elements of array using dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,sum = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *ptr =(int *)malloc(n * sizeof(int));

    for(int i=0;i<n;i++){
        printf("Enter %d element of array:", i+1);
        scanf("%d", &ptr[i]);
    }
    for(int i=0;i<n;i++){
        sum+=ptr[i];
    }
    printf("Sum of elements of  array is %d", sum);

}
