//
// Created by Yusuf Kocatürk on 12.05.2021.
//

#ifndef BETA_BANK_BACKEND_H
#define BETA_BANK_BACKEND_H

#define USER1 "user1.txt"
#define USER2 "user2.txt"
#define USER3 "user3.txt"
#define USER4 "user4.txt"


FILE *file;

void kullaniciBilgileriniYazdir();

void kullaniciBilgileriniCek(char userName[]) {

    int satirSayisi = 0;
    char c;


    file = fopen("user1.txt", "r");

    if (file == NULL) {
        printf("VERITABANINDAN VERILER OKUNAMADI");
        //exit(0);
    }
    // SATIR SAYISI VERISINI ÇEKME

    c = getc(file);
    while (c != EOF) {
        if (c == '\n') {
            satirSayisi++;
        }
        c = getc(file);
    }
    //printf("%d", satirSayisi);

    int dataArray[40];
    for (int i = 0; i < satirSayisi; ++i) {

        char sayiVerisi[100];
        char satirVerisi[100];
        fscanf(file, "%[^\n]", satirVerisi);
        strcpy(sayiVerisi, strstr(satirVerisi, " "));
        dataArray[i] = atoi(sayiVerisi);
        fseek(file, 1, SEEK_CUR);
        printf("%s", satirVerisi);
    }

    printf("%d", dataArray[0]);



    // ***************
    // user.userId = 12341682;
    // user.password = 12345;
    // user.hesap_no = 1239876;
    // user.iban = 76859403;
    // user.bakiye = 15754;
    // user.kredi_karti = 1;
    // user.kredi_karti_borc = 3682;
    // user.kredi_karti_basvuru = 0;
    // user.kredi_karti_limit_arttirma = 0;
    // user.kredi_karti_limit_miktari = 12500;
    // user.elektrik_faturasi = 350;
    // user.su_faturasi = 264;
    // user.dogalGaz_faturasi = 560;
    // user.trafik_cezasi_borc = 2000;
    // user.yks_ucreti = 100;
    // user.kpss_ucreti = 250;
    // user.ehliyet_ucreti = 750;
    // user.bireysel_kredi_basvurusu = 1;
    // user.dolar_bakiye = 3867;
    // user.euro_bakiye = 1906;
    // user.altin_bakiye = 10;
    // user.bakiye -= user.elektrik_faturasi;
    // user.elektrik_faturasi = 0;

    kullaniciBilgileriniYazdir();

}

void kullaniciBilgileriniYazdir() {


    fprintf(file, "userId %d\n", user.userId);

    fprintf(file, "password %d\n", user.password);
    fprintf(file, "hesapNo %d\n", user.hesap_no);
    fprintf(file, "iban %d\n", user.iban);
    fprintf(file, "bakiye %d\n", user.bakiye);
    fprintf(file, "krediKarti %d\n", user.kredi_karti);
    fprintf(file, "krediKartiBorc %d\n", user.kredi_karti_borc);
    fprintf(file, "krediKartiBasvuru %d\n", user.kredi_karti_basvuru);
    fprintf(file, "krediKartiLimitArttirma %d\n", user.kredi_karti_limit_arttirma);
    fprintf(file, "krediKartiLimitMiktari %d\n", user.kredi_karti_limit_miktari);

    fprintf(file, "elektrikFaturasi %d\n", user.elektrik_faturasi);
    fprintf(file, "suFaturasi %d\n", user.su_faturasi);
    fprintf(file, "dogalgazFaturasi %d\n", user.dogalGaz_faturasi);
    fprintf(file, "trafikCezasiBorc %d\n", user.trafik_cezasi_borc);
    fprintf(file, "yksUcreti %d\n", user.yks_ucreti);
    fprintf(file, "kpssUcreti %d\n", user.kpss_ucreti);
    fprintf(file, "ehliyetUcreti %d\n", user.ehliyet_ucreti);
    fprintf(file, "bireyselKrediBasvurusu %d\n", user.bireysel_kredi_basvurusu);
    fprintf(file, "dolarBakiye %d\n", user.dolar_bakiye);
    fprintf(file, "euroBakiye %d\n", user.euro_bakiye);
    fprintf(file, "altinBakiye %d\n", user.altin_bakiye);


}

#endif //BETA_BANK_BACKEND_H
