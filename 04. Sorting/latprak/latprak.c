#include <stdio.h>
#include <string.h>

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

int main(){
    int n;
    scanf("%d",&n);
    char nama[n][100];
    for(int i = 0; i < n; i++){
        scanf("%s", &nama[i]);
    }

    char metode[50];
    scanf("%s", &metode);

    if(strcmp(metode, "insertion") == 0){
        insertion(n, nama);
    }else if(strcmp(metode, "selection") == 0){
        selection(n, nama);
    }

    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%s\n", &nama[i]);
    }

    return 0;
}