#include<stdio.h>
void insertionSort(int arr[],int n){
    for(int i = 0 ; i< n; i++)
    {
        for(int j = i ; j > 0 ; j--)
        {
            if(arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j]= arr[j-1];
                arr[j-1]=temp;
            }
        }
    }

}
    
int main()
{

    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    insertionSort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}

