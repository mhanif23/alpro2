/*Saya Nur ainun NIM 2202046 mengerjakan tugas praktikum 6 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h"

void printArr(int n, bungkusan siswa1[][100], int spasi)
{
    int i; 
    for ( i = 0; i < n; i++)
    {
        printf("%s", siswa1[i]->nama);
        for(int j = 0; j < spasi - strlen(siswa1[i]->nama); j++){
            printf(" ");
        }
        printf(" %s %d %s\n", siswa1[i]->kode, siswa1[i]->power, siswa1[i]->spell); // printf nama power spell
    }
} 

void bubblesortspell(int n, bungkusan siswa1[][100])
    {
        int i, j, swap , temp;
        
        char temps[50];
        char temps2[50];
        char temps3[50];
        do
            {
            swap = 0; // inisialisasi tukar
            for (i = 0; i < n - 1; i++)
                { // jika data i lebih besar dari i+1
                    if (strcmp(siswa1[i]->spell, siswa1[i + 1]->spell)> 0)
                    { // tukar data
                        temp = siswa1[i]->power;
                        siswa1[i]->power = siswa1[i + 1]->power;
                        siswa1[i + 1]->power = temp;
                        

                        strcpy(temps, siswa1[i]->spell);
                        strcpy(temps2, siswa1[i]->nama);
                        strcpy(temps3, siswa1[i]->kode);
                        strcpy(siswa1[i]->spell, siswa1[i + 1]->spell);
                        strcpy(siswa1[i]->nama, siswa1[i + 1]->nama);
                        strcpy(siswa1[i]->kode, siswa1[i + 1]->kode);
                        strcpy(siswa1[i + 1]->spell, temps);
                        strcpy(siswa1[i + 1]->nama, temps2);
                        strcpy(siswa1[i + 1]->kode, temps3);
                        swap = 1;// tanda bahwa ada data yang ditukar
                    }

                }
            } while (swap == 1); 
            
}

void bubblesortspower(int n, bungkusan siswa1[][100])
    {
        int i, j, swap, temp;
        
        char temps[50];
        char temps2[50];
        char temps3[50];
        do
            {
            swap = 0; // inisialisasi tukar
            for (i = 0; i < n - 1; i++)
                { // jika data i lebih besar dari i+1
                    if (siswa1[i]->power < siswa1[i + 1]->power )
                    { // tukar data
                        temp = siswa1[i]->power;
                        siswa1[i]->power = siswa1[i + 1]->power;
                        siswa1[i + 1]->power = temp;
                        

                        strcpy(temps, siswa1[i]->spell);
                        strcpy(temps2, siswa1[i]->nama);
                        strcpy(temps3, siswa1[i]->kode);
                        strcpy(siswa1[i]->spell, siswa1[i + 1]->spell);
                        strcpy(siswa1[i]->nama, siswa1[i + 1]->nama);
                        strcpy(siswa1[i]->kode, siswa1[i + 1]->kode);
                        strcpy(siswa1[i + 1]->spell, temps);
                        strcpy(siswa1[i + 1]->nama, temps2);
                        strcpy(siswa1[i + 1]->kode, temps3);
                        swap = 1;// tanda bahwa ada data yang ditukar
                    }

                }
            } while (swap == 1);
}

void mergepower(int nG, int nH, bungkusan siswa1[][100], bungkusan siswa2[][100], bungkusan siswa5[][100]){

    int penghitung1 = 0, penghitung2 = 0, penghitung3 = 0;
    while ((penghitung1 < nG) && (penghitung2 < nH))
    {
        if (siswa1[penghitung1]->power >= siswa2[penghitung2]->power)
        {
            strcpy(siswa5[penghitung3]->nama,siswa1[penghitung1]->nama);
            siswa5[penghitung3]->power = siswa1[penghitung1]->power;
            strcpy(siswa5[penghitung3]->kode,siswa1[penghitung1]->kode);
            strcpy(siswa5[penghitung3]->spell,siswa1[penghitung1]->spell);
            penghitung3++;
            penghitung1++;
        }
        else
        {
            strcpy(siswa5[penghitung3]->nama,siswa2[penghitung2]->nama);
            strcpy(siswa5[penghitung3]->kode,siswa2[penghitung2]->kode);
            siswa5[penghitung3]->power = siswa2[penghitung2]->power;
            strcpy(siswa5[penghitung3]->spell,siswa2[penghitung2]->spell);
            penghitung3++;
            penghitung2++;
        }
    }
    while(penghitung1 < nG)
    {
        strcpy(siswa5[penghitung3]->nama,siswa1[penghitung1]->nama);
        strcpy(siswa5[penghitung3]->kode,siswa1[penghitung1]->kode);
        siswa5[penghitung3]->power = siswa1[penghitung1]->power;
        strcpy(siswa5[penghitung3]->spell,siswa1[penghitung1]->spell);
        penghitung3++;
        penghitung1++;
    }
    while(penghitung2 < nH)
    {
        strcpy(siswa5[penghitung3]->nama,siswa2[penghitung2]->nama);
        strcpy(siswa5[penghitung3]->kode,siswa2[penghitung2]->kode);
        siswa5[penghitung3]->power = siswa2[penghitung2]->power;
        strcpy(siswa5[penghitung3]->spell,siswa2[penghitung2]->spell);
        penghitung3++;
        penghitung2++;
    }
}

void mergespell(int nG, int nH, bungkusan siswa1[][100], bungkusan siswa2[][100], bungkusan siswa5[][100]){

    int penghitung1 = 0, penghitung2 = 0, penghitung3 = 0;
    while ((penghitung1 < nG) && (penghitung2 < nH))
    {
        if (strcmp(siswa1[penghitung1]->spell, siswa2[penghitung2]->spell) < 0)
        {
            strcpy(siswa5[penghitung3]->nama,siswa1[penghitung1]->nama);
            siswa5[penghitung3]->power = siswa1[penghitung1]->power;
            strcpy(siswa5[penghitung3]->kode,siswa1[penghitung1]->kode);
            strcpy(siswa5[penghitung3]->spell,siswa1[penghitung1]->spell);
            penghitung3++;
            penghitung1++;
        }
        else
        {
            strcpy(siswa5[penghitung3]->nama,siswa2[penghitung2]->nama);
            strcpy(siswa5[penghitung3]->kode,siswa2[penghitung2]->kode);
            siswa5[penghitung3]->power = siswa2[penghitung2]->power;
            strcpy(siswa5[penghitung3]->spell,siswa2[penghitung2]->spell);
            penghitung3++;
            penghitung2++;
        }
    }
    while(penghitung1 < nG)
    {
        strcpy(siswa5[penghitung3]->nama,siswa1[penghitung1]->nama);
        strcpy(siswa5[penghitung3]->kode,siswa1[penghitung1]->kode);
        siswa5[penghitung3]->power = siswa1[penghitung1]->power;
        strcpy(siswa5[penghitung3]->spell,siswa1[penghitung1]->spell);
        penghitung3++;
        penghitung1++;
    }
    while(penghitung2 < nH)
    {
        strcpy(siswa5[penghitung3]->nama,siswa2[penghitung2]->nama);
        strcpy(siswa5[penghitung3]->kode,siswa2[penghitung2]->kode);
        siswa5[penghitung3]->power = siswa2[penghitung2]->power;
        strcpy(siswa5[penghitung3]->spell,siswa2[penghitung2]->spell);
        penghitung3++;
        penghitung2++;
    }
}

            
