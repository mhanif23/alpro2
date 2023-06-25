#include <stdio.h>

typedef struct{
    int pembilang;
    int penyebut;
}pecahan;

void sort(int n, pecahan tabint[n]){
    int i, j; int dataPembilang, dataPenyebut;
    for(i = 1; i < n; i++){
        dataPembilang = tabint[i].pembilang;
        dataPenyebut = tabint[i].penyebut;
        j = i - 1;
        while(dataPembilang < tabint[j].pembilang && j <= n){
            tabint[j + 1].pembilang = tabint[j].pembilang;
            tabint[j + 1].penyebut = tabint[j].penyebut;
            j--;
        }
        tabint[j + 1].pembilang = dataPembilang;
        tabint[j + 1].penyebut = dataPenyebut;
    }
}
int main(){
    int n; scanf("%d", &n);
    pecahan tabint[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &tabint[i].pembilang);
        scanf("%d", &tabint[i].penyebut);
    }

    sort(n, tabint);
    
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