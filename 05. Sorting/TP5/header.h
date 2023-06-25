/*Saya Muhammad Hanif Abdillah NIM 2210239 mengerjakan soal
Tugas Praktikum 5 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahannya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin */

// Deklarasi library yang digunakan
#include <stdio.h>
#include <string.h>
// Bungkusuan data sihir yang dipelajari
typedef struct{
    char dataSihir[100];
    int magicPower;
    int time;
    double efektivitas;
}sihir;
// Deklarasi prosedur fungsi program
void sortEfektif(int jumlahData, sihir data[]); // Sorting dengan pengurutan sihir efektif
void sortTdkEfektif(int jumlahData, sihir data[]); // Sorting dengan pengurutan sihir tidak efektif
int space(int spasi, int n, sihir data[]); // Pencarian nilai spasi 
void printHeader(int spasi, int jumlahData); // Pencetakan tabel kolom header 
void printContent(int jumlahData, sihir data[], int spasi); // Pencetakan tabel record data
void printBottom(int spasi, int jumlahData); // Pencetakan tabel kolom footer
