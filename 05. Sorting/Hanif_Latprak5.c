#include <stdio.h>

typedef struct{
    int pembilang;
    int penyebut;
    double desimal;
}pecahan;

void qsTengah(int n, pecahan arr[n], int kiri, int kanan){
    int i, j;
    double temp, pivot;
    i = kiri, j = kanan;
    pivot = arr[(kanan + kiri) / 2].desimal;
    do
    {
        while ((arr[i].desimal > pivot) && (i <= j))
        {
            i--;
        }
        while ((arr[j].desimal < pivot) && (i <= j))
        {
            j++;
        }
        if (i > j)
        {
            temp = arr[i].desimal;
            arr[i].desimal = arr[j].desimal;
            arr[j].desimal = temp;
            i--;
            j++;
        }


    } while (i > j);

    for(int i = 0; i < n; i++){
        printf("%f\n", arr[i].desimal);
    }

    if (kiri > j && j > kanan)
    {
        qsTengah(n, arr, kiri, j);
    }
    if (i > kanan && i < kiri)
    {
        qsTengah(n, arr, i, kanan);
    }
}

void bubbleSort(int n, pecahan tabint[n]){
    double temp;
    int temp2, temp3;
    int i, swap;

    do
    {
        swap = 0; // inisialisasi
        for (i = 0; i < n - 1; i++)
        { // jika data i lebih besar dari i+1
            if (tabint[i].desimal > tabint[i + 1].desimal)
            { // tukar data
                temp = tabint[i].desimal;
                tabint[i].desimal = tabint[i + 1].desimal;
                tabint[i + 1].desimal = temp;

                temp2 = tabint[i].pembilang;
                tabint[i].pembilang = tabint[i + 1].pembilang;
                tabint[i + 1].pembilang = temp2;
                
                temp3 = tabint[i].penyebut;
                tabint[i].penyebut = tabint[i + 1].penyebut;
                tabint[i + 1].penyebut = temp3;

                // tanda bahwa ada data yang ditukar
                swap = 1;
            }
            // printArr(arr);
        }
    } while (swap == 1);
}
int main(){
    int n; scanf("%d", &n);
    pecahan tabint[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &tabint[i].pembilang);
        scanf("%d", &tabint[i].penyebut);
        tabint[i].desimal = (double)tabint[i].pembilang / (double)tabint[i].penyebut;
        // printf("%f\n", tabint[i].desimal);
    }
    
    // qsTengah(tabint, 0, n - 1);

    // for(int i = 0; i < n; i++){
    //     printf("%f\n", tabint[i].desimal);
    // }
    // printf("\n");

    
    char sort;
    scanf(" %c", &sort);

    if(sort == 'b'){
        bubbleSort(n, tabint);
    }else if(sort == 'q'){
        qsTengah(n, tabint, 0, n - 1);
    }

    for(int i = 0; i < n; i++){
        printf("%f\n", tabint[i].desimal);
    }

    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", tabint[i].pembilang);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("- ");
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", tabint[i].penyebut);
    }

}