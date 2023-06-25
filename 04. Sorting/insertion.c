#include <stdio.h>

void sort(int tabint[]){
    int i, j; int data_sisip;
    for(i = 1; i < 10; i++){
        data_sisip = tabint[i];
        j = i - 1;
        while(data_sisip < tabint[j] && j >= 0){
            tabint[j + 1] = tabint[j]; j--;
        }
        tabint[j + 1] = data_sisip;
    }
}

int main(){
    int tabint[10] = {34, 67, 23, 28, 98, 15, 89, 67, 28, 18};

    sort(tabint);

    for(int i = 0; i < 10; i++){
        printf("%d ",tabint[i]);
    }

    return 0;
}