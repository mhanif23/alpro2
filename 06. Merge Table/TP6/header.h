/*Saya Muhammad Hanif Abdillah NIM 2210239 mengerjakan soal
Tugas Praktikum 6 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahannya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin */

#include <stdio.h>
#include <string.h>
// Bungkusan variabel untuk data murid wizards
typedef struct{
    char nama[100];
    int power;
    char spell[100];
    char asrama;
}murid;
// Deklarasi prosedur dan fungsi yang akan digunakan
void dataMurid(int n, murid asrama[n]);
void spellSort(int n, murid asrama[n]);
void powerSort(int n, murid asrama[n]);
int space(int spasi, int n, murid asrama[n]);
void printData(int i, murid mergeWizard[], int spasi);
void mergeData(int n1, murid arr1[], int n2, murid arr2[],  murid arr3[], char sort[]);