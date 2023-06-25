/*Saya Nur ainun NIM 2202046 mengerjakan tugas praktikum 6 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h"

int main(){
    int n;
    bungkusan nps[n][100];
    int nG; // variabel  gryffindor
    scanf("%d", &nG); // meminta masukan user untuk jumlah murid Gryffindor
    bungkusan siswa1[nG][100];
   
    for (int i = 0; i < nG; i++) // perulangan untuk masukan user kurang dari ng
    {
        scanf("%s %d %s", &siswa1[i]->nama, &siswa1[i]->power, &siswa1[i]->spell); // meminta masukan user untuk nama, power dan spell
        strcpy(siswa1[i]->kode, "@");
    }

    int nH; // variabel Hufflepuff
    scanf("%d", &nH); // meminta masukan user untuk jumlah hufflepuff
    bungkusan siswa2[nH][100];
    for (int i = 0; i < nH; i++) // perulangan untuk masukan kurang dari nh
    {
        scanf("%s %d %s", &siswa2[i]->nama, &siswa2[i]->power, &siswa2[i]->spell); // meminta masukan user untuk nama, power dan spell
        strcpy(siswa2[i]->kode, "&");
    }
    
    int nR; // variabel ravenclaw
    scanf("%d", &nR); // meminta masukan user jumlah ravenclaw
    bungkusan siswa3[nR][100];
    for (int i = 0; i < nR; i++) // perulangan untuk jumlah masukan kurang dari nr
    {
        scanf("%s %d %s", &siswa3[i]->nama, &siswa3[i]->power, &siswa3[i]->spell);// meminta masukan user untuk nama, power dan spell
        strcpy(siswa3[i]->kode, "!");
    }
   
    int nS; // variabel slytherin
    scanf("%d", &nS);// meminta masukan user untuk jumlah slytherin
    bungkusan siswa4[nS][100];
    for (int i = 0; i < nS; i++)// perulangan untuk jumlah masukan kurang dari ns
    {
        scanf("%s %d %s", &siswa4[i]->nama, &siswa4[i]->power, &siswa4[i]->spell); //meminta masukan user untuk nama, power dan spell
        strcpy(siswa4[i]->kode, "$");
    }

    int min; // variabel minimal jumlah power yang dibutuhkan untuk evakuasi
    scanf("%d", &min);// meminta masukan user untuk minimal jumlah power yang dibutuhkan untuk evakuasi

    char sort[50];// varibel sorting
    scanf("%s", &sort);// meminta masukan useer tipe pengurutan (spell/power)

        // proses sorting data murid sebelum di marge

    if (strcmp(sort, "Power") == 0)
    {
    bubblesortspower(nG, siswa1);  
    bubblesortspower(nH, siswa2);
    bubblesortspower(nR, siswa3);
    bubblesortspower(nS, siswa4);

    }

    if (strcmp(sort, "Spell") == 0)
    {
    bubblesortspell(nG, siswa1);  
    bubblesortspell(nH, siswa2);
    bubblesortspell(nR, siswa3);
    bubblesortspell(nS, siswa4);
    }

    int m = nG + nH;
    int y = m + nR;
    int x = y + nS;
    bungkusan siswa5 [m][100];
    bungkusan siswa6 [y][100];
    bungkusan siswa7 [x][100];

    // memanggil prosedur marge table

    if (strcmp(sort, "Power") == 0)
    {
    mergepower(nG, nH, siswa1, siswa2, siswa5); 
    mergepower(m, nR, siswa5 , siswa3, siswa6);
    mergepower(y, nS, siswa6, siswa4, siswa7);
    }else if (strcmp(sort, "Spell") == 0)
    {
    mergespell(nG, nH, siswa1, siswa2, siswa5); 
    mergespell(m, nR, siswa5 , siswa3, siswa6);
    mergespell(y, nS, siswa6, siswa4, siswa7);
    }

    int spasi = 0; 
    for(int i = 0; i < x; i++){
        if(spasi < strlen(siswa7[i]->nama)){
            spasi = strlen(siswa7[i]->nama);
        }
    }
    
    int penghitung = x - 1; 
    int evacuation = 0;
    int battle = 0;
    int total = 0;
    int j = 0;
    while(evacuation < min){ 
        evacuation = evacuation + siswa7[penghitung]->power; 
        penghitung--; 
        j++; 
    }
    printf("*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n");
    printf("\n");
    printf("= A L L   W I Z A R D S =\n");
    printArr(x, siswa7, spasi);
    printf("\n");
    printf("*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n");
    printf("\n");
    printf("= B A T T L E   L I N E U P =\n");
    printArr(x-j, siswa7, spasi);
    printf("\n");
    printf("*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n");
    printf("\n");
    printf("= P O W E R   S T A T I S T I C S =\n");
    for(int i = 0; i < x; i++){
        total = total + siswa7[i]->power; 
    }
    for(int i = 0; i < x - j; i++){
        battle = battle + siswa7[i]->power; 
    }
    printf("Total Power      : %d\n", total);
    printf("Battle Power     : %d\n", battle);
    printf("Evacuation Power : %d\n", evacuation);
    printf("\n");
    printf("*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n");
    
    
    return 0;
}


