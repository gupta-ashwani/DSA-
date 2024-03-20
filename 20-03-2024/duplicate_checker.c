//To check the duplicate element in array
#include<stdio.h>
int main()
{
    int i,n,rotate,temp;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n], dup[n] ;
    for(i = 0; i < n; i++){
      printf("Enter %d element of array: ",i+1);
      scanf("%d", &arr[i]);
    }
    printf("Orignal array is:\n");
    for(i = 0; i < n; i++){
      printf("%d\t", arr[i]);
    }
    printf("\nEnter value to rotate: ");
    scanf("%d", &rotate);
    for(int j = 0; j != rotate; j++){
        temp = arr[0];
        for(i = 0; i < n-1; i++){
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        }
    }
    printf("\nRotated array is:\n");
    for(i = 0; i < n; i++){
      printf("%d\t", arr[i]);
    }
    return 0;
}
