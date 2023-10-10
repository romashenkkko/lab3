#include <stdio.h>
#include <stdlib.h>

void print(int n, int m, int arr[][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void valley(int n, int m, int arr[][m]) {
    int sum_valley = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i][j + 1] && arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i + 1][j]) {
                printf("Valley at (%d, %d)\n", i, j);
                sum_valley++;
            }
        }
    }
    printf("Amount of valleys: %d\n", sum_valley);
}

void mountain(int n, int m, int arr[][m]) {
    int sum_mountain = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (arr[i][j] > arr[i][j - 1] && arr[i][j] > arr[i][j + 1] && arr[i][j] > arr[i - 1][j] && arr[i][j] > arr[i + 1][j]) {
                printf("Mountain at (%d, %d)\n", i, j);
                sum_mountain++;
            }
        }
    }
    printf("Amount of mountains: %d\n", sum_mountain);
}

int main() {
    int n, m;
    int i, j;

    printf("Input number of rows in 2D array: ");
    scanf("%d", &n);
    printf("Input number of columns in array: ");
    scanf("%d", &m);
    int arr[n][m];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Enter a[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nArray:\n");
    print(n, m, arr);

    valley(n, m, arr);
    mountain(n, m, arr);
    return 0;
}
