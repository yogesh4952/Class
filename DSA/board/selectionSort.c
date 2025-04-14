        #include<stdio.h>
        void selectionSort(int arr[],int n){
            for(int i =  0 ; i < n - 1; i ++){
                int mini = i; 
                for(int j = i ; j < n ; j++)
                {
                    if(arr[j]<arr[mini]){
                        mini = j;
                    }
                }
                int temp = arr[mini];
                arr[mini]= arr[i];
                arr[i]=temp;
            }
        }


        int main()
        {
            int arr[] = {7, 6, 5, 4, 3, 2, 1};
            selectionSort(arr, 7);
            for (int i = 0; i < 7; i++)
            {
                printf("%d\t", arr[i]);
            }

            return 0;
        }