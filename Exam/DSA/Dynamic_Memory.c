#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr,n;

    printf("Enter the size of an arrya: ");
    scanf("%d",&n);

    ptr = (int *)malloc(n*sizeof(int));
    if(ptr ==NULL){
        printf("Failed to allocate memory");
        return 0;

    }
    else{
        printf("Sucess!");
    }


    return 0;

}