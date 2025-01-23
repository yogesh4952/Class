#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size = 5;
    int *ptr;
    ptr = (int *)malloc(size*sizeof(int));


    if(ptr==NULL)
    {
        printf("Memory allocated unsuccessfull!");
        exit(0);
    }
    else{
        printf("Memory allocated sucessfully\n");
        // free(ptr);
    }

    for(int i = 0 ; i < size ; i++){
        printf("%d\n",ptr[i]);
    }
    free(ptr);

    return 0;
}