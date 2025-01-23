#include<stdio.h>
#include<stdlib.h>
int main()
{
    //calloc -> used to allocate the memory at runtime and intialize all the block by 0;

    int *ptr,elements = 5;
    ptr = (int*)calloc(elements,sizeof(int));

    if(ptr == NULL)
    {
        printf("Memory allocation failed");
        exit(0);
    }
    else{
        printf("Memory allocated succesfully!\n");

        for(int i = 0 ; i < elements; i++)
        {
            printf("%d\t",ptr[i]);
        }

        free(ptr);
    }

}