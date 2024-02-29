//Binary search algorith

#include <stdio.h>
int binarySearch(int array[], int low, int high, int x)
{
  if (high >= low) 
  {
    int mid = low + (high - low) / 2;
    // If found at mid, then return it
    if (array[mid] == x)
      return mid;
    // Search the left half
    if (array[mid] > x)
      return binarySearch(array,  low, mid - 1,x);
    // Search the right half
    return binarySearch(array, mid + 1, high, x);
  }
  return -1;
}
int main() {
    int size,ele;
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
    int result = binarySearch(arr, 0,size - 1, ele);
    if (result == -1){ 
        printf("Element is not present in array");
    }
    else { 
        printf("Element is present at index %d",result);
}
    return 0;
}
