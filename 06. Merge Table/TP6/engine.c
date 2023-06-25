/*Saya Muhammad Hanif Abdillah NIM 2210239 mengerjakan soal
Tugas Praktikum 6 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahannya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin */

#include "header.h"
// Prosedur input data wizard
void dataMurid(int n, murid asrama[n]){
    for(int i = 0; i < n; i++){
        scanf("%s", &asrama[i].nama); // Nama wizard
        scanf("%d", &asrama[i].power); // Power wizard
        scanf("%s", &asrama[i].spell); // Spell wizard
    }
}
// Prosedur sorting dengan mengurutkan sesuai spell
void spellSort(int n, murid asrama[n]){
    // Deklarasi counter dan minIndex untuk temporary
    int i, j, minIndex; 
    char tempSpell[100], tempNama[100]; int tempPower;
    char tempAsrama;
    // Algorithm selection sort
    for (i = 0; i < (n - 1); i++){
        minIndex = i;
        for (j = i+1; j < n; j++)
        {
            // Pengkondisian sort berdasarkan spell
            if (strcmp(asrama[minIndex].spell, asrama[j].spell) > 0)
            {   
                minIndex = j;
            }
        }
        // Proses pertukaran nilai data sesuai kondisi
        strcpy(tempSpell, asrama[i].spell);
        strcpy(tempNama, asrama[i].nama);
        tempPower = asrama[i].power;
        tempAsrama = asrama[i].asrama;
        strcpy(asrama[i].spell, asrama[minIndex].spell);
        strcpy(asrama[i].nama, asrama[minIndex].nama);
        asrama[i].power = asrama[minIndex].power;
        asrama[i].asrama = asrama[minIndex].asrama;
        strcpy(asrama[minIndex].spell, tempSpell);
        strcpy(asrama[minIndex].nama, tempNama);
        asrama[minIndex].power = tempPower;
        asrama[minIndex].asrama = tempAsrama;
    }
}
// Prosedur sorting dengan mengurutkan sesuai Power
void powerSort(int n, murid asrama[n]){
    // Deklarasi counter dan minIndex untuk temporary
    int i, j, minIndex; 
    char tempSpell[100], tempNama[100]; int tempPower;
    char tempAsrama;
    // Algorithm selection sort
    for (i = 0; i < (n - 1); i++){
        minIndex = i;
        for (j = i+1; j < n; j++)
        {
            // Pengkondisian sort berdasarkan power
            if (asrama[minIndex].power < asrama[j].power)
            {
                    minIndex = j;
            }
        }
        // Proses pertukaran nilai data sesuai kondisi
        strcpy(tempSpell, asrama[i].spell);
        strcpy(tempNama, asrama[i].nama);
        tempPower = asrama[i].power;
        tempAsrama = asrama[i].asrama;
        strcpy(asrama[i].spell, asrama[minIndex].spell);
        strcpy(asrama[i].nama, asrama[minIndex].nama);
        asrama[i].power = asrama[minIndex].power;
        asrama[i].asrama = asrama[minIndex].asrama;
        strcpy(asrama[minIndex].spell, tempSpell);
        strcpy(asrama[minIndex].nama, tempNama);
        asrama[minIndex].power = tempPower;
        asrama[minIndex].asrama = tempAsrama;
    }
}
// Fungsi mencari nilai maksimum spasi
int space(int spasi, int n, murid asrama[n]){
    spasi = 0; // Inisialisasi spasi
    for(int i = 0; i < n; i++){
        if(spasi < strlen(asrama[i].nama)){
            // Menentukan jumlah spasi menyesuaikan string terpanjang pada array
            spasi = strlen(asrama[i].nama);
        }
    }
    return spasi;
}
// Prosedur printout data murid
void printData(int i, murid mergeWizard[], int spasi){ 
    // Print nama
    printf("%s ", mergeWizard[i].nama);
    // Print spasi menyesuaikan string nama dengan maksimum spasi
    for(int j = 0; j < spasi - strlen(mergeWizard[i].nama); j++){
        printf(" ");
    }
    // Print asrama, power, dan spell muridnya
    printf("%c ", mergeWizard[i].asrama);
    printf("%d ", mergeWizard[i].power);
    printf("%s\n", mergeWizard[i].spell);
}

void mergeData(int n1, murid arr1[],  int n2, murid arr2[],  murid arr3[], char sort[]){
    // Inisialisasi counter
    int i1 = 0, i2 = 0, i3 = 0;

    // ulangi hingga arr1 habis atau arr2 habis
    while ((i1 < n1) && (i2 < n2))
    {
        if(strcmp(sort, "Spell") == 0){
            // jika elemen teratas arr1 lebih kecil dari arr2
            if (strcmp(arr1[i1].spell, arr2[i2].spell) < 0)
            {
                // masukkan elemen teratas arr1 ke dalam arr3
                strcpy(arr3[i3].nama, arr1[i1].nama);
                arr3[i3].asrama = arr1[i1].asrama;
                arr3[i3].power = arr1[i1].power;
                strcpy(arr3[i3].spell, arr1[i1].spell);
                i3++;
                i1++;
            }
            // jika elemen teratas arr1 lebih besar dari arr2
            else 
            {
                // masukkan elemen teratas arr2 ke dalam arr3
                strcpy(arr3[i3].nama, arr2[i2].nama);
                arr3[i3].asrama = arr2[i2].asrama;
                arr3[i3].power = arr2[i2].power;
                strcpy(arr3[i3].spell, arr2[i2].spell);
                i3++;
                i2++;
            }
        }else if(strcmp(sort, "Power") == 0){
            // jika elemen teratas arr1 lebih kecil dari arr2
            if (arr1[i1].power >= arr2[i2].power)
            {
                // masukkan elemen teratas arr1 ke dalam arr3
                strcpy(arr3[i3].nama, arr1[i1].nama);
                arr3[i3].asrama = arr1[i1].asrama;
                arr3[i3].power = arr1[i1].power;
                strcpy(arr3[i3].spell, arr1[i1].spell);
                i3++;
                i1++;
            }
            // jika elemen teratas arr1 lebih besar dari arr2
            else 
            {
                // masukkan elemen teratas arr2 ke dalam arr3
                strcpy(arr3[i3].nama, arr2[i2].nama);
                arr3[i3].asrama = arr2[i2].asrama;
                arr3[i3].power = arr2[i2].power;
                strcpy(arr3[i3].spell, arr2[i2].spell);
                i3++;
                i2++;
            }
        }
            
    }

    // masukkan sisa arr1 jika ada
    while(i1 < n1)
    {
        strcpy(arr3[i3].nama, arr1[i1].nama);
        arr3[i3].asrama = arr1[i1].asrama;
        arr3[i3].power = arr1[i1].power;
        strcpy(arr3[i3].spell, arr1[i1].spell);
        i3++;
        i1++;
    }
    // masukkan sisa arr2 jika ada
    while(i2 < n2)
    {
        strcpy(arr3[i3].nama, arr2[i2].nama);
        arr3[i3].asrama = arr2[i2].asrama;
        arr3[i3].power = arr2[i2].power;
        strcpy(arr3[i3].spell, arr2[i2].spell);
        i3++;
        i2++;
    }
}
