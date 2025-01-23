#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr , size = 10;
    
    //aba malai yo thau nira memory chaiyo thorai jun chai kei operation garna parne xa 
    ptr = (int*)malloc(size*sizeof(int));

    //Aba ma yo nira error handling garxu kinaki its good
    if(ptr == NULL)
    {
        printf("Memory allocation Unsuccesfull");
        exit(0);
    }
    else{
        printf("Dami\n");
    }

    //Aba maile value assigne gare
    ptr[0]=5;
    ptr[1]=6;

    //Mathi ko ma herda 2 ta matra use vayo tara hamle ta 10 ota ko lagi space use garya xam extra vayo so aba reallocation garxu ma

    //Yesle pointer return garxa so that i made a new pointer to store it
    int *new_ptr ;
    new_ptr = (int*)realloc(ptr,sizeof(int)*5);

    //Mathiko ma maile 5 ota ko lagi size allocate gare

    new_ptr[2] = 5;

    for(int i = 0 ; i <5;i++)
    {
        printf("%d\t",new_ptr[i]);
    }

    //Outpu = 5       6       5       0       0       

    free(new_ptr);
    return 0;
}