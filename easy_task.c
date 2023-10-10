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

void SortinCol(int n, int m, int arr[n][m]) {
    
// Sort by columns
    for (int j = 0; j < m; j++) {
        int column[n];
        for (int i = 0; i < n; i++) {
            column[i] = arr[i][j];
        }
        quickSort(column, 0, n - 1);
        for (int i = 0; i < n; i++) {
            arr[i][j] = column[i];
        }
    }


    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < m; j++) {
            printf("%d\t", arr[i][j]);
        }
    }


  
}

void ReverseSubstract(int n, int m, int arr[n][m]){
    int rev_arr[n][m], substr_arr[n][m];

 printf("\nReversed array\n");
  for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rev_arr[i][j] = arr[i][m - 1 - j];
            printf("%d\t", rev_arr[i][j]);           
        }
         printf("\n");
    }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                substr_arr[i][j] = arr[i][j] - rev_arr[i][j];
        }
    }
 printf("\nSubtracted Array\n");
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < m; j++) {
            printf("%d\t", substr_arr[i][j]);
        }
    }

}
void Graphs(){
    int n;
    
    printf("Introduceti numarul de noduri: ");
    scanf("%d", &n);

    int adjacencyMatrix[n][n];

    
    printf("Introduceti matricea de adiacenta (0 sau 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }


    printf("Matricea de Adiacenta:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    int incidentMatrix[n][n]; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            incidentMatrix[i][j] = 0;
        }
    }

    int edgeCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                incidentMatrix[i][edgeCount] = 1;
                incidentMatrix[j][edgeCount] = 1;
                edgeCount++;
            }
        }
    }

    // Afisam matricea de incidenta
    printf("\nMatricea de Incidenta:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < edgeCount; j++) {
            printf("%d ", incidentMatrix[i][j]);
        }
        printf("\n");
    }
}


void MountValley(int n, int m, int arr[n][m] ){
    int sum_vals = 0;
    int sum_mont = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((j == 0  ||  arr[i][j] < arr[i][j - 1]) && (j == m -1 || arr[i][j] < arr[i][j + 1]) && (i == 0 || arr[i][j] < arr[i - 1][j]) && (i == n -1 || arr[i][j] < arr[i + 1][j])) {
                sum_vals++;
            }
            if((j == 0  ||  arr[i][j] > arr[i][j - 1]) && (j == m -1 || arr[i][j] > arr[i][j + 1]) && (i == 0 || arr[i][j] > arr[i - 1][j]) && (i == n -1 || arr[i][j] > arr[i + 1][j])) {
                sum_mont++;
            }
        }
    }
    printf("Vals: %d, Monts: %d\n", sum_vals, sum_mont);
}

void printArr(int n, int m, int arr[n][m]){
     for(int i=0;i<n;i++)    
    {    
        printf("\n");    
        for (int j=0;j<m;j++)    
        {    
            printf("%d\t",arr[i][j]);    
        }    
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
printArr(n, m, arr);
    
///Mountains
MountValley(n, m, arr);


//////sortare

 


    


////////////// reverse and substract
ReverseSubstract(n, m, arr);



printf("\nSorted array by columns\n");
SortinCol(n, m, arr);

printf("\nSorted array by rows\n");
for (int i = 0; i < n; i++)
{
    quickSort(arr[i],0, m-1);
    

} 
printArr(n, m, arr);

///grafuri
Graphs();



}