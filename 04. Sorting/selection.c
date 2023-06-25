#include <stdio.h>
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int minIndex, key, temp, i, j, n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Sebelum di sort:\n");
    printArr(arr, n);
    // algoritma selection sort
    for (i = 0; i < (n - 1); i++)
    {
        minIndex = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[minIndex] < arr[j])
            {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }


    printf("Setelah di sort:\n");
    printArr(arr, n);
    return 0;

}