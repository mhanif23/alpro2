/*Saya Muhammad Hanif Abdillah NIM 2210239 mengerjakan soal
Tugas Praktikum 4 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahannya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin */

#include "header.h"
// Fungsi untuk menentukan jumlah nilai ascii
int valueAscii(int ascii, siswa data[0]){
    ascii = 0; // Inisialisasi ascii
    for(int i = 0; i < strlen(data[0].nama); i++){
        // Perulangan sebanyak panjang ascii string pertama
        ascii += data[0].nama[i];
    }
    return ascii;
}
// Fungsi untuk menentukan jumlah spasi
int space(int spasi, int n, siswa data[n]){
    spasi = 0; // Inisialisasi spasi
    for(int i = 0; i < n; i++){
        if(spasi < strlen(data[i].nama)){
            // Menentukan jumlah spasi menyesuaikan string terpanjang pada array
            spasi = strlen(data[i].nama);
        }
    }
    return spasi;
}
// Prosedur ketika sorting yang digunakan Insertion
void insertion(int n, siswa data[n], char syarat[4]){
    // Deklarasi counter dan variabel wadah untuk data yang disisipkan
    int i, j; 
    char sisip_nama[100];
    int sisip_umur;
    // Syarat INA (Sorting berdasarkan nama dan ascending)
    if(syarat[1] == 'N' && syarat[2] == 'A'){
        // Algoritma insertion sort
        for(i = 1; i < n; i++){
            strcpy(sisip_nama, data[i].nama);
            sisip_umur = data[i].umur;
            j = i - 1;
            // Pengkondisian sort berdasarkan nama
            while(strcmp(sisip_nama, data[j].nama) < 0 && j >= 0){
                strcpy(data[j + 1].nama, data[j].nama); 
                data[j + 1].umur = data[j].umur;
                j--;
            }
            strcpy(data[j + 1].nama, sisip_nama);
            data[j + 1].umur = sisip_umur;
        }
    // Syarat IND (Sorting berdasarkan nama dan descending)
    }else if(syarat[1] == 'N' && syarat[2] == 'D'){
        // Algoritma insertion sort
        for(i = 1; i < n; i++){
            strcpy(sisip_nama, data[i].nama);
            sisip_umur = data[i].umur;
            j = i - 1;
            // Pengkondisian sort berdasarkan nama
            while(strcmp(sisip_nama, data[j].nama) > 0 && j >= 0){
                strcpy(data[j + 1].nama, data[j].nama); 
                data[j + 1].umur = data[j].umur;
                j--;
            }
            strcpy(data[j + 1].nama, sisip_nama);
            data[j + 1].umur = sisip_umur;
        }
    // Syarat IUA (Sorting berdasarkan umur dan ascending)
    }else if(syarat[1] == 'U' && syarat[2] == 'A'){
        // Algoritma insertion sort
        for(i = 1; i < n; i++){
            strcpy(sisip_nama, data[i].nama);
            sisip_umur = data[i].umur;
            j = i - 1;
            // Pengkondisian sort berdasarkan umur
            while(sisip_umur < data[j].umur && j >= 0){
                strcpy(data[j + 1].nama, data[j].nama); 
                data[j + 1].umur = data[j].umur;
                j--;
            }
            strcpy(data[j + 1].nama, sisip_nama);
            data[j + 1].umur = sisip_umur;
        }
    // Syarat IUD (Sorting berdasarkan umut dan descending)
    }else if(syarat[1] == 'U' && syarat[2] == 'D'){
        // Algoritma insertion sort
        for(i = 1; i < n; i++){
            strcpy(sisip_nama, data[i].nama);
            sisip_umur = data[i].umur;
            j = i - 1;
            // Pengkondisian sort berdasarkan umur
            while(sisip_umur > data[j].umur && j >= 0){
                strcpy(data[j + 1].nama, data[j].nama); 
                data[j + 1].umur = data[j].umur;
                j--;
            }
            strcpy(data[j + 1].nama, sisip_nama);
            data[j + 1].umur = sisip_umur;
        }
    }
}
// Prosedur ketika sorting yang digunakan Selection
void selection(int n, siswa data[n], char syarat[4]){
    // Deklarasi counter, variabel minIndex, dan wadah temporary index ketika sorting
    int i, j, minIndex; 
    char tempNama[100]; int tempUmur;
    // Syarat SNA (Sorting berdasarkan nama dan ascending)
    if(syarat[1] == 'N' && syarat[2] == 'A'){
        // Algoritma selection sort
        for (i = 0; i < (n - 1); i++){
            minIndex = i;
            for (j = i+1; j < n; j++)
            {
                // Pengkondisian sort berdasarkan nama
                if (strcmp(data[minIndex].nama, data[j].nama) > 0)
                {
                    minIndex = j;
                }
            }
            strcpy(tempNama, data[i].nama);
            tempUmur = data[i].umur;
            strcpy(data[i].nama, data[minIndex].nama);
            data[i].umur = data[minIndex].umur;
            strcpy(data[minIndex].nama, tempNama);
            data[minIndex].umur = tempUmur;
        }
    // Syarat SND (Sorting berdasarkan nama dan descending)
    }else if(syarat[1] == 'N' && syarat[2] == 'D'){
        // Algoritma selection sort
        for (i = 0; i < (n - 1); i++){
            minIndex = i;
            for (j = i+1; j < n; j++)
            {
                // Pengkondisian sort berdasarkan nama
                if (strcmp(data[minIndex].nama, data[j].nama) < 0)
                {
                    minIndex = j;
                }
            }
            strcpy(tempNama, data[i].nama);
            tempUmur = data[i].umur;
            strcpy(data[i].nama, data[minIndex].nama);
            data[i].umur = data[minIndex].umur;
            strcpy(data[minIndex].nama, tempNama);
            data[minIndex].umur = tempUmur;
        }
    // Syarat SUA (Sorting berdasarkan umur dan ascending)
    }else if(syarat[1] == 'U' && syarat[2] == 'A'){
        // Algoritma selection sort
        for (i = 0; i < (n - 1); i++){
            minIndex = i;
            for (j = i+1; j < n; j++)
            {
                // Pengkondisian sort berdasarkan umur
                if (data[minIndex].umur > data[j].umur)
                {
                    minIndex = j;
                }
            }
            strcpy(tempNama, data[i].nama);
            tempUmur = data[i].umur;
            strcpy(data[i].nama, data[minIndex].nama);
            data[i].umur = data[minIndex].umur;
            strcpy(data[minIndex].nama, tempNama);
            data[minIndex].umur = tempUmur;
        }
    // Syarat SUD (Sorting berdasarkan nama dan descending)
    }else if(syarat[1] == 'U' && syarat[2] == 'D'){
        // Algoritma selection sort
        for (i = 0; i < (n - 1); i++){
            minIndex = i;
            for (j = i+1; j < n; j++)
            {
                // Pengkondisian sort berdasarkan umur
                if (data[minIndex].umur < data[j].umur)
                {
                        minIndex = j;
                }
            }
            strcpy(tempNama, data[i].nama);
            tempUmur = data[i].umur;
            strcpy(data[i].nama, data[minIndex].nama);
            data[i].umur = data[minIndex].umur;
            strcpy(data[minIndex].nama, tempNama);
            data[minIndex].umur = tempUmur;
        }
    }
}
// Prosedur output hasil akhir
void sortingData(int n, siswa data[n], int spasi, int jumlahAscii, int jumlahUmur){
    printf("Hasil setelah diurutkan :\n");
    // Print nama siswa yang telah disorting lalu umurnya
    for(int i = 0; i < n; i++){
        printf("%s  ", data[i].nama);
        // Print spasi menyesuaikan nilai spasi dikurangi panjang string nya
        for(int j = 0; j < spasi - strlen(data[i].nama); j++){
            printf(" ");
        }
        printf("%d\n", data[i].umur);
    }
    // Penentuan masuk ke asrama mana
    if(jumlahAscii % 2 == 0 && jumlahUmur % 2 == 0){
    // Jika jumlah ascii genap dan jumlah umur genap masuk Gryffindor
        printf("Selamat, Anda masuk ke asrama Gryffindor!\n");
    }else if(jumlahAscii % 2 == 0 && jumlahUmur % 2 == 1){
    // Jika jumlah ascii genap dan jumlah umur ganjil masuk Hufflepuff
        printf("Selamat, Anda masuk ke asrama Hufflepuff!\n");
    }else if(jumlahAscii % 2 == 1 && jumlahUmur % 2 == 1){
    // Jika jumlah ascii ganjil dan jumlah umur ganjil masuk Ravenclaw
        printf("Selamat, Anda masuk ke asrama Ravenclaw!\n");
    }else if(jumlahAscii % 2 == 1 && jumlahUmur % 2 == 0){
    // Jika jumlah ascii ganjil dan jumlah umur genap masuk Slytherin
        printf("Selamat, Anda masuk ke asrama Slytherin!\n");
    }
}