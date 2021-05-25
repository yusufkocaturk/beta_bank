#ifndef BETA_BANK_BACKEND_H
#define BETA_BANK_BACKEND_H

#define USER "user1.txt"


FILE *file;

void kullaniciBilgileriniYazdir();

void kullaniciBilgileriniCek(char userName[]) {

    int satirSayisi = 0;
    char c;
    file = fopen(userName, "rb");
    if (file == NULL) {
        printf("VERITABANINDAN VERILER OKUNAMADI");
        exit(0);
    }
    c = getc(file);
    while (c != EOF) {
        if (c == '\n') {
            satirSayisi++;
        }
        c = getc(file);
    }


 
    rewind(file);
    int *dataArray;
    dataArray = (int*)malloc(100*sizeof(int));
    for (int i = 0; i < satirSayisi; ++i) {

        char *sayiVerisi;
        sayiVerisi = (char*)calloc(100 , sizeof(char));
        char *satirVerisi;
        satirVerisi = (char*)calloc(100 , sizeof(char));

        fscanf(file, "%[^\n]", (satirVerisi));
        strcpy((sayiVerisi), strstr((satirVerisi), " "));
        *(dataArray+i) = atoi((sayiVerisi));
        fseek(file, 1, SEEK_CUR);

        free(sayiVerisi);
        free(satirVerisi);

    }
    user.userId = dataArray[0];
    user.password = dataArray[1];
    user.hesap_no = dataArray[2];
    user.iban = dataArray[3];
    user.bakiye = dataArray[4];
    user.kredi_karti = dataArray[5];
    user.kredi_karti_borc = dataArray[6];
    user.kredi_karti_basvuru = dataArray[7];
    user.kredi_karti_limit_arttirma = dataArray[8];
    user.kredi_karti_limit_miktari = dataArray[9];
    user.elektrik_faturasi = dataArray[10];
    user.su_faturasi = dataArray[11];
    user.dogalGaz_faturasi = dataArray[12];
    user.trafik_cezasi_borc = dataArray[13];
    user.yks_ucreti = dataArray[14];
    user.kpss_ucreti = dataArray[15];
    user.ehliyet_ucreti = dataArray[16];
    user.bireysel_kredi_basvurusu = dataArray[17];
    user.dolar_bakiye = dataArray[18];
    user.euro_bakiye = dataArray[19];
    user.altin_bakiye = dataArray[20];
    fclose(file);
    free(dataArray);

}

void kullaniciBilgileriniYazdir() {


    file = fopen(USER, "wb");

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

    fclose(file);
}



#endif //BETA_BANK_BACKEND_H
