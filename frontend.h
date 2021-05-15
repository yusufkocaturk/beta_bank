

#ifndef BETA_BANK_FRONTEND_H
#define BETA_BANK_FRONTEND_H


void bakiyeSorgulama(){}

void sifreDegistirme(){}

void ibanGoruntuleme(){}

void hesapOzeti(){}

void betaKart_Menu() {
    printf("5 - BETAKART MENUSU\n");
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

void sinavOdemeleri_Menu();

void applicationStart() {

    anamenu();
}


#endif //BETA_BANK_FRONTEND_H
