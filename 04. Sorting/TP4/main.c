/*Saya Muhammad Hanif Abdillah NIM 2210239 mengerjakan soal
Tugas Praktikum 4 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahannya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin */

#include  "header.h"

int main(){
    // Deklarasi jumlah siswa yang akan diinput
    int n;
    scanf("%d", &n);
    // Deklarasi struct siswa untuk input nama dan umur
    siswa data[n];
    for(int i = 0; i < n; i++){
        scanf("%s", &data[i].nama);
        scanf("%d", &data[i].umur);
    }
    // Deklarasi input untuk syarat yang akan digunakan saat sorting
    char syarat[4];
    scanf("%s", &syarat);

    // Deklarasi untuk nilai ascii sebelum di sorting
    int firstAscii = valueAscii(firstAscii, data); // Pemanggilan fungsi pencari nilai ascii
    int firstAge = data[0].umur; // Value umur data siswa pertama sebelum di sorting

    // Pengkondisian sorting
    if(syarat[0] == 'I'){ // Kondisi ketika insertion
        // // Pemanggilan prosedur insertion sort
        insertion(n, data, syarat);
    }else if(syarat[0] == 'S'){ // Kondisi ketika selection
        // Pemanggilan prosedur selection sort
        selection(n, data, syarat);
    }

    // Deklarasi untuk nilai ascii sesudah di sorting
    int lastAscii = valueAscii(lastAscii, data); // Pemanggilan fungsi pencari nilai ascii
    int lastAge = data[0].umur; // Value umur data siswa pertama sesudah di sorting
    // Penjumalahan nilai ascii dan nilai umur sesudah dan sebelum disorting
    int jumlahAscii = firstAscii + lastAscii;
    int jumlahUmur = firstAge + lastAge;
    
    // Deklarasi wadah untuk jumlah spasi
    int spasi = space(spasi, n, data); // Pemanggilan fungsi perhitungan nilai spasi

    // Pemanggilan prosedur output akhir
    sortingData(n, data, spasi, jumlahAscii, jumlahUmur);

    return 0;

}