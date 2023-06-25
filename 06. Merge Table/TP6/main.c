/*Saya Muhammad Hanif Abdillah NIM 2210239 mengerjakan soal
Tugas Praktikum 6 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahannya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin */

#include "header.h"

int main(){
    // Deklarasi dan input data murid asrama gryffindor
    int nG;
    scanf("%d", &nG);
    murid gryffindor[nG];
    dataMurid(nG, gryffindor);
    for(int i = 0; i < nG; i++){
        gryffindor[i].asrama = '@';
    }
    // Deklarasi dan input data murid asrama hufflepuff
    int nH;
    scanf("%d", &nH);
    murid hufflepuff[nH];
    dataMurid(nH, hufflepuff);
    for(int i = 0; i < nH; i++){
        hufflepuff[i].asrama = '&';
    }
    // Deklarasi dan input data murid asrama ravenclaw
    int nR;
    scanf("%d", &nR);
    murid ravenclaw[nR];
    dataMurid(nR, ravenclaw);
    for(int i = 0; i < nR; i++){
        ravenclaw[i].asrama = '!';
    }
    // Deklarasi dan input data murid asrama slytherin
    int nS;
    scanf("%d", &nS);
    murid slytherin[nS];
    dataMurid(nS, slytherin);
    for(int i = 0; i < nS; i++){
        slytherin[i].asrama = '$';
    }
    
    int m; scanf("%d", &m); // Minimal power yang dibutuhkan untuk evakuasi
    char sort[6]; scanf("%s", &sort); // Penentuan sorting dengan acuan ke power atau spell
    // Pemanggilan prosedur selection sorting dengan kondisional spell atau power
    if(strcmp(sort, "Spell") == 0){
        spellSort(nG, gryffindor);
        spellSort(nH, hufflepuff);
        spellSort(nR, ravenclaw);
        spellSort(nS, slytherin);
    }else if(strcmp(sort, "Power") == 0){
        powerSort(nG, gryffindor);
        powerSort(nH, hufflepuff);
        powerSort(nR, ravenclaw);
        powerSort(nS, slytherin);
    }
    // Algortima merge table data murid keseluruhan asrama
    int nGH = nG + nH;
    murid mergeGH[nGH];
    mergeData(nG, gryffindor, nH, hufflepuff, mergeGH, sort); // Merge data gryffindor dengan hufflepuff

    int nGHR = nG + nH + nR;
    murid mergeGHR[nGHR];
    mergeData(nGH, mergeGH, nR, ravenclaw, mergeGHR, sort); // Merge data gryffindor hufflepuff dengan ravenclaw

    int n = nG + nH + nR + nS;
    murid mergeWizard[n];
    mergeData(nGHR, mergeGHR, nS, slytherin, mergeWizard, sort); // Merge data gryffindor hufflepuff ravenclaw dengan slytherin
    // Fungsi dalam menentukan jumlah spasi pada data
    int spasi = space(spasi, n, mergeWizard);   
    // Print hasil akhir
    printf("*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n");
    printf("\n= A L L   W I Z A R D S =\n");
    for(int i = 0; i < n; i++){
        printData(i, mergeWizard, spasi); // Prosedur printout data all wizards
    }
    
    // Alur pencarian nilai power
    int totalPower = 0;
    for(int i = 0; i < n; i++){
        totalPower += mergeWizard[i].power; // Menentukan nilai total power
    }
    int evacuationPower = 0;
    int count = n - 1, j = 0;
    while(evacuationPower < m){ // Kondisi selama evacuation power belum memenuhi minimal
        evacuationPower += mergeWizard[count].power; // Menentukan nilai evacuation power
        count--; // Diambil dari data paling bawah
        j++; // Untuk counter yang diperlukan saat printout battleline wizard
    }
    int battlePower = 0;
    for(int i = 0; i < n - j; i++){
        battlePower += mergeWizard[i].power; // Menentukan nilai battle power
    }
    // Printout data battleline wizard
    printf("\n*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n");
    printf("\n= B A T T L E   L I N E U P =\n");
    for(int i = 0; i < n - j; i++){ // Print data wizard yang masuk ke battleline 
        printData(i, mergeWizard, spasi);
    }
    // Printout statistics power yang ada
    printf("\n*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n");
    printf("\n= P O W E R   S T A T I S T I C S =\n");
    printf("Total Power      : %d\n", totalPower);
    printf("Battle Power     : %d\n", battlePower);
    printf("Evacuation Power : %d\n", evacuationPower);
    printf("\n*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n");

    return 0;

}