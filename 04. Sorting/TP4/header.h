/*Saya Muhammad Hanif Abdillah NIM 2210239 mengerjakan soal
Tugas Praktikum 4 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahannya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin */

// Deklarasi Library
#include <stdio.h>
#include <string.h>

// Bungkusan untuk wadah data nama dan umur siswa hogwarts
typedef struct{
    char nama[100];
    int umur;
}siswa;

// Deklarasi fungsi dan prosedur yang akan digunakan
int valueAscii(int ascii, siswa data[0]);
int space(int spasi, int n, siswa data[n]);
void insertion(int n, siswa data[n], char syarat[4]);
void selection(int n, siswa data[n], char syarat[4]);
void sortingData(int n, siswa data[n], int spasi, int jumlahAscii, int jumlahUmur);
