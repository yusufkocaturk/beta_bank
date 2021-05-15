

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

void paraCekme() {
    int bakiye, tutar,islemSonucu;
     bakiye = 1000;
    printf(" BAKIYENIZ: %d\n", bakiye );
    printf(" CEKMEK ISTEDIGINIZ TUTARI GIRINIZ: ");
    scanf(" %d", &tutar );
    islemSonucu = bakiye - tutar;

    //??ıslemler user.bakiye =bakiye- tutar
    printf(" YENI BAKIYENIZ: %d", islemSonucu);
    printf(" CEKMIS OLDUGUNUZ TUTAR: %d\n\n", tutar );
    anamenu();
}



void krediKartinaYatirma() {
    int tutar ;

    // kredi kartı bakiye ya da kullanılabilir limiti eksik tanımlanmalı
  // yeni bakiye user.bakiye ye mi yazdırılmalı


    printf("YATIRMAK ISTEDIGINIZ TUTARI GIRINIZ : " );
     scanf(" %d", &tutar );
    // ?? ıslemlerr

    printf(" YATIRDIGINIZ TUTAR: %d\n\n ", tutar );
    anamenu();
}

void hesabaYatirma() {
    int tutar,bakiye,islemSonucu;
    //bakiye = user.bakiye;
    bakiye = 1000;


    printf("YATIRMAK ISTEDIGINIZ TUTARI GIRINIZ : " );
    scanf(" %d", &tutar  );

    // ??ıslemeler? user.bakiye = user.bakiye+tutar;
   // user.bakiye = bakiye - tutar;
   // user.bakiye = islemSonucu;

    islemSonucu = bakiye - tutar;

    printf(" YATIRDIGINIZ TUTAR: %d ", tutar );
    printf(" YENI BAKIYENIZ: %d\n\n", islemSonucu );
    anamenu();


}

void paraYatirma_Menu() {
    int response ;
    printf(" PAARA YATIRMA MENUSU\n\n");
    printf("1 - HESABA PARA YATIRMA\n");
    printf("2 - KREDI KARTINA PARA YATIRMA\n");

    scanf(" %d", &response);

    switch (response) {
        case 1 :
            hesabaYatirma() ;
            break;
        case 2 :
            krediKartinaYatirma() ;
            break;
        default:
            printf("\nHatali islem yaptiniz\n\n");
            anamenu();
            break;
    }

}

void paraIslemleri_Menu() {
    int response;
    printf(" PARA ISLEMLERI MENUSU\n\n");

    printf("1 - PARA YATIRMA MENUSU\n");
    printf("2 - PARA CEKME ISLEMLER\n");

    scanf(" %d", &response);

    switch (response) {
        case 1 :
            paraYatirma_Menu() ;
            break;
        case 2 :
           paraCekme() ;
            break;
        default:
            printf("\nHatali islem yaptiniz \n\n");
            anamenu() ;
            break;

    }



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
        case 2 :
            odemeIslemleri_Menu();
            break;
        case 3 :
            basvuruIslemleri_Menu();
            break;
        case 4 :
            yatirimIslemleri_Menu();
            break;
        case 5 :
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
