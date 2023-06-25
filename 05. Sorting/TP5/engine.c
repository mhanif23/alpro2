/*Saya Muhammad Hanif Abdillah NIM 2210239 mengerjakan soal
Tugas Praktikum 5 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahannya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin */
#include "header.h"
// Prosedur untuk sorting sihir efektif
void sortEfektif(int jumlahData, sihir data[jumlahData]){
    // Deklarasi counter dan penampung
    double temp; 
    int temp2, temp3;
    int i, swap;
    char temp4[100];
    do
    {
        swap = 0; // inisialisasi
        for (i = 0; i < jumlahData - 1; i++)
        { // jika data efektivitas lebih kecil dari i+1
            if (data[i].efektivitas < data[i + 1].efektivitas)
            { // tukar data satu bungkusan
                temp = data[i].efektivitas;
                data[i].efektivitas = data[i + 1].efektivitas;
                data[i + 1].efektivitas = temp;

                temp2 = data[i].magicPower;
                data[i].magicPower = data[i + 1].magicPower;
                data[i + 1].magicPower = temp2;
                
                temp3 = data[i].time;
                data[i].time = data[i + 1].time;
                data[i + 1].time = temp3;

                strcpy(temp4, data[i].dataSihir);
                strcpy(data[i].dataSihir, data[i + 1].dataSihir);
                strcpy(data[i + 1].dataSihir, temp4);

                // tanda bahwa ada data yang ditukar
                swap = 1;
            // Kondisi ketika keefektivitasan sama
            }else if(data[i].efektivitas == data[i + 1].efektivitas){
                // Ditentukan dengan panjangnya nama mantra sihir
                if(strlen(data[i].dataSihir) > strlen(data[i + 1].dataSihir)){
                    // Nama yang lebih pendek lebih efektif
                    temp = data[i].efektivitas;
                    data[i].efektivitas = data[i + 1].efektivitas;
                    data[i + 1].efektivitas = temp;

                    temp2 = data[i].magicPower;
                    data[i].magicPower = data[i + 1].magicPower;
                    data[i + 1].magicPower = temp2;
                    
                    temp3 = data[i].time;
                    data[i].time = data[i + 1].time;
                    data[i + 1].time = temp3;

                    strcpy(temp4, data[i].dataSihir);
                    strcpy(data[i].dataSihir, data[i + 1].dataSihir);
                    strcpy(data[i + 1].dataSihir, temp4);
                }
            }
        }
    } while (swap == 1);
}
// Prosedur untuk sorting sihir tidak efektif
void sortTdkEfektif(int jumlahData, sihir data[jumlahData]){
    // Deklarasi counter dan penampung
    double temp;
    int temp2, temp3;
    int i, swap;
    char temp4[100];
    do
    {
        swap = 0; // inisialisasi
        for (i = 0; i < jumlahData - 1; i++)
        { // jika data efektivitas lebih besar dari i+1
            if (data[i].efektivitas > data[i + 1].efektivitas)
            { // tukar data dengan mengurutkan dari yang paling tidak efektif
                temp = data[i].efektivitas;
                data[i].efektivitas = data[i + 1].efektivitas;
                data[i + 1].efektivitas = temp;

                temp2 = data[i].magicPower;
                data[i].magicPower = data[i + 1].magicPower;
                data[i + 1].magicPower = temp2;
                
                temp3 = data[i].time;
                data[i].time = data[i + 1].time;
                data[i + 1].time = temp3;

                strcpy(temp4, data[i].dataSihir);
                strcpy(data[i].dataSihir, data[i + 1].dataSihir);
                strcpy(data[i + 1].dataSihir, temp4);

                // tanda bahwa ada data yang ditukar
                swap = 1;
            // Kondisi ketika keefektivitasan sama
            }else if(data[i].efektivitas == data[i + 1].efektivitas){
                 // Ditentukan dengan panjangnya nama mantra sihir
                if(strlen(data[i].dataSihir) < strlen(data[i + 1].dataSihir)){
                    // Nama yang lebih pendek lebih efektif
                    temp = data[i].efektivitas;
                    data[i].efektivitas = data[i + 1].efektivitas;
                    data[i + 1].efektivitas = temp;

                    temp2 = data[i].magicPower;
                    data[i].magicPower = data[i + 1].magicPower;
                    data[i + 1].magicPower = temp2;
                    
                    temp3 = data[i].time;
                    data[i].time = data[i + 1].time;
                    data[i + 1].time = temp3;

                    strcpy(temp4, data[i].dataSihir);
                    strcpy(data[i].dataSihir, data[i + 1].dataSihir);
                    strcpy(data[i + 1].dataSihir, temp4);
                }
            }
        }
    } while (swap == 1);
}
// Pencarian nilai spasi
int space(int spasi, int n, sihir data[n]){
    spasi = 0; // Inisialisasi spasi
    for(int i = 0; i < n; i++){
        if(spasi < strlen(data[i].dataSihir)){
            // Menentukan jumlah spasi menyesuaikan string terpanjang pada array
            spasi = strlen(data[i].dataSihir);
        }
    }
    return spasi;
}
// Prosedur pencetakan tabel kolom header
void printHeader(int spasi, int jumlahData){
    // Kondisi panjang tabel kolom awal menyesuaikan jumlah data
    if(jumlahData < 10){
        printf("+----+-");
    }else if(jumlahData < 20){
        printf("+-----+-");
    }
    // Kondisi panjang tabel kolom kedua menyesuaikan panjang nama mantra
    if(spasi > strlen("Nama Mantra")){
        for(int i = 0; i < spasi; i++){
            printf("-");
        }
    }else if(spasi < strlen("Nama Mantra")){
        for(int i = 1; i < strlen("Nama Mantra"); i++){
            printf("-");
        }
    }
    printf("--+-------------+-------+\n");

    // Kondisi panjang tabel kolom awal menyesuaikan jumlah data
    if(jumlahData < 10){ 
        printf("| No | Nama Mantra");
    }else if(jumlahData < 20){
        printf("| No  | Nama Mantra");
    }
    // Kondisi panjang tabel kolom kedua menyesuaikan panjang nama mantra
    if(spasi > strlen("Nama Mantra")){
        for(int i = 0; i < spasi - strlen("Nama Mantra"); i++){
            printf(" ");
        }
        printf("  | Magic Power | Waktu |\n");
    }else if(spasi <= strlen("Nama Mantra")){
        printf(" | Magic Power | Waktu |\n");
    }

    // Kondisi panjang tabel kolom awal menyesuaikan jumlah data
    if(jumlahData < 10){
        printf("+----+-");
    }else if(jumlahData < 20){
        printf("+-----+-");
    }
    // Kondisi panjang tabel kolom kedua menyesuaikan panjang nama mantra
    if(spasi > strlen("Nama Mantra")){
        for(int i = 0; i < spasi; i++){
            printf("-");
        }
    }else if(spasi < strlen("Nama Mantra")){
        for(int i = 1; i < strlen("Nama Mantra"); i++){
            printf("-");
        }
    }
    printf("--+-------------+-------+\n");
}
// Print tabel data sihir
void printContent(int jumlahData, sihir data[jumlahData], int spasi){
    // Pencarian nilai spasi untuk kolom magic power
    for(int i = 0; i < jumlahData; i++){
        int spasi2 = 0;
        if(data[i].magicPower < 10){
            spasi2 = 11;
        }else if(data[i].magicPower < 100){
            spasi2 = 10;
        }else if(data[i].magicPower < 1000){
            spasi2 = 9;
        }else if(data[i].magicPower < 10000){
            spasi2 = 8;
        }else if(data[i].magicPower < 100000){
            spasi2 = 7;
        }
        // Pencarian nilai spasi untuk kolom waktu
        int spasi3 = 0;
        if(data[i].time < 10){
        spasi3 = 5;
        }else if(data[i].time < 100){
            spasi3 = 4;
        }else if(data[i].time < 1000){
            spasi3 = 3;
        }else if(data[i].time < 10000){
            spasi3 = 2;
        }
        // Print tabel menyesuaikan no apakah 1 digit atau 2 digit
        if(jumlahData < 10){
            printf("| %d  | %s", i+1, data[i].dataSihir);
        }else if(jumlahData > 9 && jumlahData < 20){
            if(i < 9){
                printf("| %d   | %s", i+1, data[i].dataSihir);
            }else if(i > 8 && i < 20){
                printf("| %d  | %s", i+1, data[i].dataSihir);
            }
        }
        // Print tabel nama mantra menyesuaikan panjang nama apakah lebih panjang dari kolom header atau tidak
        if(spasi > strlen("Nama Mantra")){
            for(int j = 0; j < spasi - strlen(data[i].dataSihir); j++){
                printf(" ");
            }
        }else if(spasi < strlen("Nama Mantra")){
            for(int j = 1; j < strlen("Nama Mantra") - spasi; j++){
                printf(" ");
            }
        }
        // Print spasi magic power dan waktu beserta data
        printf("  | %d", data[i].magicPower);
        for(int j = 0; j < spasi2; j++){
            printf(" ");
        }
        printf("| %d", data[i].time);
        for(int j = 0; j < spasi3; j++){
            printf(" ");
        }
        printf("|\n");
    }
}
// Print tabel bottom atau footer
void printBottom(int spasi, int jumlahData){
    // Kondisi panjang tabel kolom awal menyesuaikan jumlah data
    if(jumlahData < 10){
        printf("+----+-");
    }else if(jumlahData < 20){
        printf("+-----+-");
    }
    // Kondisi panjang tabel kolom kedua menyesuaikan panjang nama mantra
    if(spasi > strlen("Nama Mantra")){
        for(int i = 0; i < spasi; i++){
            printf("-");
        }
    }else if(spasi < strlen("Nama Mantra")){
        for(int i = 1; i < strlen("Nama Mantra"); i++){
            printf("-");
        }
    }
    printf("--+-------------+-------+\n");
}