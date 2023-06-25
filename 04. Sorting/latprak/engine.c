#include "header.h"

void insertion(int n, char nama[n][100]){
    int i, j; char data_sisip[100];
    for(i = 1; i < n; i++){
        strcpy(data_sisip, nama[i]);
        j = i - 1;
        while(strcmp(data_sisip, nama[j]) < 0 && j >= 0){
            strcpy(nama[j + 1], nama[j]); j--;
        }
        strcpy(nama[j + 1], data_sisip);
    }
}

void selection(int n, char nama[n][100]){
    int i, j, minIndex; char temp[100];
    for (i = 0; i < (n - 1); i++){
        minIndex = i;
        for (j = i+1; j < n; j++)
        {
            if (strcmp(nama[minIndex], nama[j]) < 0)
            {
                minIndex = j;
            }
        }
        strcpy(temp, nama[i]);
        strcpy(nama[i], nama[minIndex]);
        strcpy(nama[minIndex],temp);
    }
}