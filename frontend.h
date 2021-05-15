

#ifndef BETA_BANK_FRONTEND_H
#define BETA_BANK_FRONTEND_H
void anamenu();

void bakiyeSorgulama();

void sifreDegistirme();

void ibanGoruntuleme();

void hesapOzeti();

void betaKart_Menu() {
    printf("5 - BETAKART MENUSU\n");
}

void hisseSenediHesabi();

void dovizAlim() {
    int response;
    printf("DOVIZ ALIM\n");
    printf("1 - DOLAR\n");
    printf("2 - EURO\n");
    printf("3 - ALTIN\n");
    printf("Alacaginiz doviz tipini seciniz: ");
    scanf(" %d", &response);
    switch (response) {
        case 1:
            printf("Alacaginiz dolar miktarini giriniz: ");
            break;
        case 2:
            printf("Alacaginiz euro miktarini giriniz: ");
            break;
        case 3:
            printf("Alacaginiz altin miktarini giriniz: ");
            break;
        default:
            printf("\nHatali secim yaptiniz\n\n");
            dovizAlim();
            break;
    }
}
void dovizSatim(){
    int response;
    printf("DOVIZ SATIM\n");
    printf("1 - DOLAR\n");
    printf("2 - EURO\n");
    printf("3 - ALTIN\n");
    printf("Satacaginiz doviz tipini seciniz: ");
    scanf(" %d", &response);
    switch (response) {
        case 1:
            printf("Satacaginiz dolar miktarini giriniz: ");
            break;
        case 2:
            printf("Satacaginiz euro miktarini giriniz: ");
            break;
        case 3:
            printf("Satacaginiz altin miktarini giriniz: ");
            break;
        default:
            printf("\nHatali secim yaptiniz\n\n");
            dovizSatim();
            break;
    }
}

void yatirimIslemleri_Menu() {
    int dolar=3.02, euro=4.12, altin=221.24,response;
    printf("\nYATIRIM ISLEMLERI MENUSU\n");
    printf("DOVIZ KURLARI:\n");
    printf("DOLAR/TL: %d\n",dolar);
    printf("EURO/TL: %d\n",euro);
    printf("ALTIN/TL: %d\n",altin);
    printf("VARLIKLARINIZ\n");
    printf("DOLAR:%c\n",user.dolar_bakiye);
    printf("EURO:%c\n",user.euro_bakiye);
    printf("ALTIN:%c\n",user.altin_bakiye);


    printf("1- DOVIZ ALIM \n");
    printf("2- DOVIZ SATIM \n");
    printf("Seciniz: ");
    scanf(" %d", &response);
    switch (response) {
        case 1:
            dovizAlim();
            break;
        case 2:
            dovizSatim();
            break;
        default:
            printf("\nHatali secim yaptiniz\n\n");
            yatirimIslemleri_Menu();
            break;
    }

}

void bireyselKrediBasvurusu(){
    int maas,oran=2,vade;
    printf("BIREYSEL KREDI BASVURUSU\n");
    printf("AYLIK NET MAASINIZI GIRINIZ:");
    scanf(" %d",&maas);
}

void krediLimitArttirma(){
    printf("KREDI KARTI LIMIT ARTTIRMA");
}

void krediKartiBasvurusu(){
    printf("KREDI KARTI BASVURUSU\n");

}

void basvuruIslemleri_Menu() {

    int response;
    printf("\nBASVURU ISLEMLERI MENUSU\n");
    printf("1 - KREDI KARTI BASVURUSU\n");
    printf("2 - KREDI KARTI LIMIT ARTTIRMA\n");
    printf("3 - BIREYSEL KREDI BASVURUSU\n");
    printf("4 - ANA MENU\n");
    printf("Menu numarasini giriniz: ");
    scanf(" %d", &response);
    switch (response) {
        case 1:
            krediKartiBasvurusu();
            break;
        case 2:
            krediLimitArttirma();
            break;
        case 3:
            bireyselKrediBasvurusu();
            break;
        case 4:
            anamenu();
            break;
        default:
            printf("\nHatali secim yaptiniz\n\n");
            basvuruIslemleri_Menu();
            break;

    }
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
    int response;

    printf("ANA MENU\n");
    printf("1 - PARA ISLEMLERI MENUSU\n");
    printf("2 - ODEME ISLEMLERI MENUSU\n");
    printf("3 - BASVURU ISLEMLERI MENUSU\n");
    printf("4 - YATIRIM ISLEMLERI MENUSU\n");
    printf("5 - BETAKART MENUSU\n");

    printf("Menu numarasini giriniz: ");
    scanf(" %d", &response);

    switch (response) {
        case 1 :
            paraIslemleri_Menu();
            break;
        case 2:
            odemeIslemleri_Menu();
            break;
        case 3:
            basvuruIslemleri_Menu(user);
            break;
        case 4:
            yatirimIslemleri_Menu(user);
            break;
        case 5:
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
