#include <stdio.h>
#include <string.h>

typedef struct{
    char nama[100];
    int nim;
}mahasiswa;

void inputData(int n, mahasiswa data[n]){
    for(int i = 0; i < n; i++){
        scanf("%s", &data[i].nama);
        scanf("%d", &data[i].nim);
    }
}

void nameSort(int n, mahasiswa data[n]){
    // Deklarasi counter dan minIndex untuk temporary
    int i, j, minIndex; 
    char tempnama[100]; 
    int tempNIM;
    // Algorithm selection sort
    for (i = 0; i < (n - 1); i++){
        minIndex = i;
        for (j = i+1; j < n; j++)
        {
            // Pengkondisian sort berdasarkan nama
            if (strcmp(data[minIndex].nama, data[j].nama) > 0)
            {   
                minIndex = j;
            }
        }
        // Proses pertukaran nilai data sesuai kondisi
        strcpy(tempnama, data[i].nama);
        tempNIM = data[i].nim;
        strcpy(data[i].nama, data[minIndex].nama);
        data[i].nim = data[minIndex].nim;
        strcpy(data[minIndex].nama, tempnama);
        data[minIndex].nim = tempNIM;
    }
}

void mergeData(int n1, mahasiswa arr1[],  int n2, mahasiswa arr2[],  mahasiswa arr3[]){
    // Inisialisasi counter
    int i1 = 0, i2 = 0, i3 = 0;

    // ulangi hingga arr1 habis atau arr2 habis
    while ((i1 < n1) && (i2 < n2))
    {
        // jika elemen teratas arr1 lebih kecil dari arr2
        if (strcmp(arr1[i1].nama, arr2[i2].nama) < 0)
        {
            // masukkan elemen teratas arr1 ke dalam arr3
            strcpy(arr3[i3].nama, arr1[i1].nama);
            arr3[i3].nim = arr1[i1].nim;
            i3++;
            i1++;
        }
        // jika elemen teratas arr1 lebih besar dari arr2
        else 
        {
            // masukkan elemen teratas arr2 ke dalam arr3
            strcpy(arr3[i3].nama, arr2[i2].nama);
            arr3[i3].nim = arr2[i2].nim;
            i3++;
            i2++;
        }
            
    }

    // masukkan sisa arr1 jika ada
    while(i1 < n1)
    {
        strcpy(arr3[i3].nama, arr1[i1].nama);
        arr3[i3].nim = arr1[i1].nim;
        i3++;
        i1++;
    }
    // masukkan sisa arr2 jika ada
    while(i2 < n2)
    {
        strcpy(arr3[i3].nama, arr2[i2].nama);
        arr3[i3].nim = arr2[i2].nim;
        i3++;
        i2++;
    }
}

void printData(int n, mahasiswa data[n]){
    for(int i = 0; i < n; i++){
        printf("%d ", data[i].nim);
        printf("%s\n", data[i].nama);
    }
}

int main(){
    int n1; scanf("%d", &n1);
    mahasiswa data1[n1];
    inputData(n1, data1);
    nameSort(n1, data1);
    int n2; scanf("%d", &n2);
    mahasiswa data2[n2];
    inputData(n2, data2);
    nameSort(n2, data2);
    int n3; scanf("%d", &n3);
    mahasiswa data3[n3];
    inputData(n3, data3);
    nameSort(n3, data3);

    int n12 = n1 + n2;
    mahasiswa data12[n12];
    mergeData(n1, data1, n2, data2, data12);
    int n123 = n12 + n3;
    mahasiswa data123[n123];
    mergeData(n12, data12, n3, data3, data123);

    printData(n123, data123);

}