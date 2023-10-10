#include <stdio.h>
#include <stdlib.h>
//aici e codul final cu reversed si substraction, de lucrat aici!!!!!!!!!111
int main() {
    int n, m;
    int i, j;

    printf("Give the size of matrix NxM:");
    scanf(" %d %d", &n, &m);
    int arr[n][m];
    int rev_arr[n][m];
    int substr_arr[n][m];


    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Enter a[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
   

    printf("\nArraiul original\n");     
    for(i=0;i<n;i++)    
    {    
        printf("\n");    
        for (j=0;j<m;j++)    
        {    
            printf("%d\t",arr[i][j]);    
        }    
    } 

    printf("\nReversed array\n");
  for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            rev_arr[i][j] = arr[i][m - 1 - j];
            printf("%d\t", rev_arr[i][j]);           
        }
         printf("\n");
    }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                substr_arr[i][j] = arr[i][j] - rev_arr[i][j];
        }
    }

    printf("\nSubtracted Array\n");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < m; j++) {
            printf("%d\t", substr_arr[i][j]);
        }
    }

  
    return 0;
}
