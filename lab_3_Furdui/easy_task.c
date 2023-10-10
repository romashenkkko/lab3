#include <stdio.h>    
#include<stdlib.h>
//quicksorting by rows and columns
void change(int* a, int* b) 
{
    
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 
    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) {
            i++;
            change(&arr[i], &arr[j]);
        }
    }

    change(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high); 

        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main () 
   
{
    int n,m;
    
    int i, j; 
    printf("Give the size of matrix NxM:");
    scanf(" %d %d",&n,&m);
    int arr[n][m];
    int size_arr= sizeof(arr) / sizeof(arr[0]);
    for (i=0; i<n; i++)    
    {    
        for (j=0; j<m; j++)    
        {    
            printf("Enter a[%d][%d]: ",i,j);                
            scanf("%d",&arr[i][j]);    
        }    
    }    

 // Sort by columns
    for (j = 0; j < m; j++) {
        int column[n];
        for (i = 0; i < n; i++) {
            column[i] = arr[i][j];
        }
        quickSort(column, 0, n - 1);
        for (i = 0; i < n; i++) {
            arr[i][j] = column[i];
        }
    }
 printf("\nSorted array by columns\n");

    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < m; j++) {
            printf("%d\t", arr[i][j]);
        }
    }

for (int i = 0; i < n; i++)
{
quickSort(arr[i],0, size_arr-1);
    
}   
printf("\nSorted array by rows\n");     

    for(i=0;i<n;i++)    
    {    
        printf("\n");    
        for (j=0;j<m;j++)    
        {    
            printf("%d\t",arr[i][j]);    
        }    
    } 

}