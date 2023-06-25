/*Saya Muhammad Hanif Abdillah NIM 2210239 mengerjakan soal
Tugas Praktikum 5 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahannya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin */
#include "header.h"

int main(){
    // Deklarasi berapa banyak sihir yang akan dipelajari
    int jumlahData;
    scanf("%d", &jumlahData);
    sihir data[jumlahData]; // Array of struct dari data sihir
    // Input setiap nilai dari data
    for(int i = 0; i < jumlahData; i++){
        scanf("%s", &data[i].dataSihir);
        scanf("%d", &data[i].magicPower);
        scanf("%d", &data[i].time);
        data[i].efektivitas = (double)data[i].magicPower / (double)data[i].time; // Pencarian nilai efektivitas sihir
    }
    // Input untuk pengkondisian algortima sorting
    char sort;
    scanf(" %c", &sort);
    // Pemanggilan fungsi mencari nilai spasi
    int spasi = space(spasi, jumlahData, data);
    // Input untuk pengkondisian urutan sorting
    char urutan[15];
    scanf("%s", &urutan);
    // Pengkondisian dan pemanggilan sorting
    if(sort == 'b'){ // Bubble Sort
        if(strcmp(urutan, "Efektif") == 0){ // Pengkondisian urutan sihir yang efektif
            sortEfektif(jumlahData, data);
        }else if(strcmp(urutan, "TidakEfektif") == 0){ // Pengkondisian urutan sihir yang tidak efektif
            sortTdkEfektif(jumlahData, data);
        }
    }else if(sort == 'q'){ // Quick sort
        if(strcmp(urutan, "Efektif") == 0){ // Pengkondisian urutan sihir yang efektif
            sortEfektif(jumlahData, data);
        }else if(strcmp(urutan, "TidakEfektif") == 0){ // Pengkondisian urutan sihir yang tidak efektif
            sortTdkEfektif(jumlahData, data);
        }
    }
    
    // Print tabel akhir
    printHeader(spasi, jumlahData);
    printContent(jumlahData, data, spasi);
    printBottom(spasi, jumlahData);
    // Mencari nilai waktu yang dibutuhkan dalam mempelajari sihir
    int jam = 0, menit = 0;
    for(int i = 0; i < jumlahData; i++){
        jam += data[i].time;
    }
    // Format waktu dalam bentuk jam dan menit
    menit = jam % 60;
    jam /= 60;
    printf("Anda memerlukan %d jam %d menit untuk menguasai %d mantra diatas\n", jam, menit, jumlahData);

    return 0;

}
