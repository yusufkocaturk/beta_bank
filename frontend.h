

#ifndef BETA_BANK_FRONTEND_H
#define BETA_BANK_FRONTEND_H


void bakiyeSorgulama() {}

void sifreDegistirme() {
    char passwordCurrent[] = "123456";
    char response[] = "";
    int result;
    printf("\nSIFRE DEGISTIRME");
    printf("\nVAR OLAN SIFRENIZI GIRINIZ:\n");
    scanf("%s", response);
    result = strcmp(response, passwordCurrent);

    if (result == 0) {
        char passwordNew[] = "";
        printf("\nYENI SIFRENIZI GIRINIZ:\n");
        scanf(" %s", passwordNew);
        printf("YENI SIFRENIZ: %s", passwordNew);
    }

}

void ibanGoruntuleme() {
    char iban[] = "1234-5678-9101-1121";
    printf("\nIBAN GORUNTULE\n");
    printf("IBAN: %s", iban);
}

void hesapOzeti() {
    printf("\nHESAP OZETI");
}

void betaKart_Menu() {
    char response;

    printf("BETAKART MENUSU\n");
    printf("1 - HESAP OZETI\n");
    printf("2 - IBAN GORUNTULE\n");
    printf("3 - SIFRE DEGISTIR\n");
    printf("4 - BAKIYE SORGULA\n");


    printf("Menu numarasini giriniz: ");
    scanf(" %c", &response);

    switch (response) {
        case '1':
            hesapOzeti();
            break;
        case '2':
            ibanGoruntuleme();
            break;
        case '3':
            sifreDegistirme();
            break;
        case '4':
            bakiyeSorgulama();
            break;

        default:
            printf("\nHatali secim yaptiniz\n\n");
            betaKart_Menu();
            break;
    }
}

void hisseSenediHesabi();

void dovizHesabi();

void yatirimIslemleri_Menu() {
    printf("4 - YATIRIM ISLEMLERI MENUSU\n");
}

void bireyselKrediBasvurusu();

void krediLimitArttirma();

void krediKartiBasvurusu();

void basvuruIslemleri_Menu() {
    printf("3 - BASVURU ISLEMLERI MENUSU\n");
}

void egitimOdemeIslemleri();

void trafikCezaOdemeIslemleri();

void faturaOdemeIslemleri();

void odemeIslemleri_Menu() {
    printf("2 - ODEME ISLEMLERI MENUSU\n");
}

void paraCekme();

void krediKartinaYatirma();

void hesabaYatirma();

void paraYatirma_Menu() {

}

void paraIslemleri_Menu() {
    printf("1 - PARA ISLEMLERI MENUSU\n");
}

void anamenu() {
    char response;

    printf("ANA MENU\n");
    printf("1 - PARA ISLEMLERI MENUSU\n");
    printf("2 - ODEME ISLEMLERI MENUSU\n");
    printf("3 - BASVURU ISLEMLERI MENUSU\n");
    printf("4 - YATIRIM ISLEMLERI MENUSU\n");
    printf("5 - BETAKART MENUSU\n");

    printf("Menu numarasini giriniz: ");
    scanf(" %c", &response);

    switch (response) {
        case '1':
            paraIslemleri_Menu();
            break;
        case '2':
            odemeIslemleri_Menu();
            break;
        case '3':
            basvuruIslemleri_Menu();
            break;
        case '4':
            yatirimIslemleri_Menu();
            break;
        case '5':
            betaKart_Menu();
            break;
        default:
            printf("\nHatali secim yaptiniz\n\n");
            anamenu();
            break;
    }
}

void sinavOdemeleri_Menu() {}

void girisYap() {
    char password[] = "123456";
    char response[6];
    int result;
    printf("GIRIS YAP\n\n");
    printf("HESABINIZA AIT SIFREYI GIRINIZ:");

    //gets(response);
    scanf(" %s", response);
    printf("şifre : %s", response);

    result = strcmp(response, password);
//    printf("%d", result);

    if (result == 0) {
        anamenu();
    } else {
        printf("\nHATALI SIFRE GIRDINIZ TEKRAR DENEYIN\n");
        girisYap();
    }
}

void applicationStart() {

    char response;
    printf("BETABANK'A HOS GELDINIZ\n");
    printf("1 - GIRIS YAP\n");
    printf("2 - KARTSIZ ISLEMLER(SINAV ODEMELERI)\n");
    scanf(" %c", &response);
    switch (response) {
        case '1':
            girisYap();
            break;
        case '2':
            sinavOdemeleri_Menu();
            break;
        default:
            applicationStart();
            break;
    }
}


#endif //BETA_BANK_FRONTEND_H
