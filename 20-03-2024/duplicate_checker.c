//To check the duplicate element in array
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n], dup[n] ;
    int i;
    for(i = 0; i < n; i++){
      printf("Enter %d element of array: ",i+1);
      scanf("%d", &arr[i]);
    }
    for(i = 0 ;i < n; i++){
      dup[arr[i]]++;
    }
    for(i = 0; i < n; i++){
      if(dup[arr[i]] > 1){
      printf("%d is duplicate\n", arr[i]);    
      dup[arr[i]] = 0;    
      }
    }
    return 0;
}
