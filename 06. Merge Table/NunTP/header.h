/*Saya Nur ainun NIM 2202046 mengerjakan tugas praktikum 6 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include <stdio.h> // perpus
#include <string.h> // perpus
typedef struct 
{
    char nama[100]; // variabel nama
    char kode[100]; // variabel kode asrama
    int power; // variabel power
    char spell[100]; // variabel spell
}bungkusan;

void printArr(int n, bungkusan siswa1[][100], int spasi);
void bubblesortspell(int n, bungkusan siswa1[][100]);
void bubblesortspower(int n, bungkusan siswa1[][100]);
void mergepower(int nG, int nH, bungkusan siswa1[][100], bungkusan siswa2[][100], bungkusan siswa5[][100]);
void mergespell(int nG, int nH, bungkusan siswa1[][100], bungkusan siswa2[][100], bungkusan siswa5[][100]);


