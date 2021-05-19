

#ifndef BETA_BANK_FRONTEND_H
#define BETA_BANK_FRONTEND_H


void anamenu();

void applicationStart();

/**************** YARDIMCI FONKSİYONLAR ***************/

void beklet(int saniye) {
    printf("\n\nISLEMINIZ GERCEKLESTIRILIYOR. LUTFEN BEKLEYINIZ...\n\n");
    usleep(saniye * 1000000);
}

char clearMessage[6];


void detectOperatingSystem() {

#ifdef __APPLE__
    strcpy(clearMessage, "clear");
#elif _WIN32
    strcpy(clearMessage,"cls");
#endif

}

void clearScreen() {
    system(clearMessage);
}

/*******************************/
void sonYonlendirme() {
    int response;
    printf("\n\n9 - ANA MENUYE DON");
    printf("\n0 - CIKIS YAP\n");
    scanf(" %d", &response);
    switch (response) {
        case 9:
            anamenu();
            break;
        case 0:
            exit(0);
            break;
        default:
            break;
    }
}

void bakiyeSorgulama() {
    clearScreen();
    printf("BAKIYE SORUGULAMA\n");
    printf("\nVARLIKLARINIZ\n");
    printf("\nTURK LIRASI: %d TL", user.bakiye);
    printf("\nDOLAR: %d $", user.dolar_bakiye);
    printf("\nEURO: %d €", user.euro_bakiye);
    printf("\nALTIN: %d GRAM", user.altin_bakiye);
    sonYonlendirme();
}

void sifreDegistirme() {
    clearScreen();
    int result;
    char girilenSifre[25];
    char eskiSifre[25];

    sprintf(eskiSifre, "%d", user.password);

    printf("\nSIFRE DEGISTIRME");
    printf("\nVAR OLAN SIFRENIZI GIRINIZ:\n");
    scanf("%s", girilenSifre);

    result = strcmp(girilenSifre, eskiSifre);


    if (result == 0) {
        clearScreen();
        char yeniSifre[25];

        tekrarDeneyin:

        printf("\nYENI SIFRENIZI GIRINIZ:\n");
        printf("\nSIFRE KURALLARI:\n");
        printf("* 0 ILE BASLAMAMALIDIR\n");
        printf("* EN FAZLA 8 KARAKTER OLMALIDIR\n\n");
        scanf(" %s", yeniSifre);

        if (yeniSifre[0] != '0' && strlen(yeniSifre) < 9) {
            printf("SIFRE OLUSTURMA BASARILI.");
            user.password = atoi(yeniSifre);
            kullaniciBilgileriniYazdir();
            kullaniciBilgileriniCek(USER1);
            beklet(2);
            sonYonlendirme();
        } else {
            printf("\nSIFRE OLUSTURMA BASARISIZ.\nLUTFEN SIFRENIZIN KURALLARA UYDUGUNDAN EMIN OLUN\n\n");
            goto tekrarDeneyin;
        }
    }

}

void ibanGoruntuleme() {
    clearScreen();
    printf("\nIBAN GORUNTULE\n");
    printf("IBAN: %d", user.iban);
    sonYonlendirme();
}

void hesapOzeti() {
    clearScreen();
    printf("\nHESAP OZETI");
    printf("\nHESAP NUMARANIZ: %d", user.hesap_no);
    printf("\nVARLIKLARINIZ\n");
    printf("\nTURK LIRASI: %d TL", user.bakiye);
    printf("\nDOLAR: %d $", user.dolar_bakiye);
    printf("\nEURO: %d €", user.euro_bakiye);
    printf("\nALTIN: %d GRAM", user.altin_bakiye);
    printf("\n\nKREDI KARTI BORCUNUZ: %d", user.kredi_karti_borc);
    printf("\nKREDI KARTI LIMITINIZ: %d", user.kredi_karti_limit_miktari);
    printf("\nKREDI KARTI KULLANILABILIR LIMITINIZ: %d\n", user.kredi_karti_limit_miktari - user.kredi_karti_borc);
    sonYonlendirme();

}

void betaKart_Menu() {
    clearScreen();
    int response;

    printf("BETAKART MENUSU\n");
    printf("1 - HESAP OZETI\n");
    printf("2 - IBAN GORUNTULE\n");
    printf("3 - SIFRE DEGISTIR\n");
    printf("4 - BAKIYE SORGULA\n");


    printf("Menu numarasini giriniz: ");
    scanf(" %d", &response);

    switch (response) {
        case 1:
            hesapOzeti();
            break;
        case 2:
            ibanGoruntuleme();
            break;
        case 3:
            sifreDegistirme();
            break;
        case 4:
            bakiyeSorgulama();
            break;

        default:
            printf("\nHatali secim yaptiniz\n\n");
            betaKart_Menu();
            break;
    }
}


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

void dovizSatim() {
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
    int dolar = 3, euro = 4, altin = 221, response;
    printf("\nYATIRIM ISLEMLERI MENUSU\n");
    printf("DOVIZ KURLARI:\n");
    printf("DOLAR/TL: %d\n", dolar);
    printf("EURO/TL: %d\n", euro);
    printf("ALTIN/TL: %d\n", altin);
    printf("VARLIKLARINIZ\n");
    printf("DOLAR:%d\n", user.dolar_bakiye);
    printf("EURO:%d\n", user.euro_bakiye);
    printf("ALTIN:%d\n", user.altin_bakiye);


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

void bireyselKrediBasvurusu() {
    int maas, oran = 2, vade;
    printf("BIREYSEL KREDI BASVURUSU\n");
    printf("AYLIK NET MAASINIZI GIRINIZ:");
    scanf(" %d", &maas);
}

void krediLimitArttirma() {
    printf("KREDI KARTI LIMIT ARTTIRMA");
}

void krediKartiBasvurusu() {
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

void egitimOdemeIslemleri() {
    clearScreen();
    printf("EGITIM ODEME ISLEMLERI\n");
    int response;

    printf("1 - YKS ucreti: %d\n", user.yks_ucreti);
    printf("2 - KPSS ucreti: %d\n", user.kpss_ucreti);
    printf("3 - Ehliyet sinavi ucreti: %d\n", user.ehliyet_ucreti);

    printf("Ucretini odemek istediginiz sinavin numarasini giriniz:");
    scanf(" %d", &response);

    switch (response) {
        case 1:
            if (user.bakiye >= user.yks_ucreti) {
                user.bakiye = (user.bakiye - user.yks_ucreti);
                user.yks_ucreti = 0;
                kullaniciBilgileriniYazdir();
                kullaniciBilgileriniCek(USER1);

                beklet(3);
                printf("Isleminiz basariyla gerceklesmistir.\n");
            } else {
                printf("Borcunuzu odemek icin yeterli bakiyeye sahip degilsiniz.\n");
            }
            sonYonlendirme();
            break;
        case 2:
            if (user.bakiye >= user.kpss_ucreti) {
                user.bakiye = (user.bakiye - user.kpss_ucreti);
                user.kpss_ucreti = 0;
                kullaniciBilgileriniYazdir();
                kullaniciBilgileriniCek(USER1);
                beklet(3);
                printf("Isleminiz basariyla gerceklesmistir.\n");
            } else {
                printf("Borcunuzu odemek icin yeterli bakiyeye sahip degilsiniz.\n");
            }
            sonYonlendirme();
            break;
        case 3:
            if (user.bakiye >= user.ehliyet_ucreti) {
                user.bakiye = (user.bakiye - user.ehliyet_ucreti);
                user.ehliyet_ucreti = 0;
                kullaniciBilgileriniYazdir();
                kullaniciBilgileriniCek(USER1);
                beklet(3);
                printf("Isleminiz basariyla gerceklesmistir.\n");
            } else {
                printf("Borcunuzu odemek icin yeterli bakiyeye sahip degilsiniz.\n");
            }
            sonYonlendirme();
            break;
        default:
            printf("\nHatali secim yaptiniz\n\n");
            sonYonlendirme();
            break;
    }
}

void trafikCezaOdemeIslemleri() {
    clearScreen();
    printf("TRAFIK CEZASI ODEME ISLEMLERI\n");
    int response;

    if (user.trafik_cezasi_borc != 0) {
        printf("Trafik cezasi borcunuz: %d\n", user.trafik_cezasi_borc);

        printf("Borcunuzu odemek istiyorsaniz 1'e yoksa 0'a basiniz:");
        scanf(" %d", &response);

        switch (response) {
            case 1:
                if (user.bakiye >= user.trafik_cezasi_borc) {
                    user.bakiye = (user.bakiye - user.trafik_cezasi_borc);
                    user.trafik_cezasi_borc = 0;

                    kullaniciBilgileriniYazdir();
                    kullaniciBilgileriniCek(USER1);
                    beklet(3);
                    printf("Borcunuz basariyla odendi.\n");

                } else {
                    printf("Borcunuzu odemek icin yeterli bakiyeye sahip degilsiniz.\n");
                }
                sonYonlendirme();
                break;
            case 0:
                anamenu();
                break;
            default:
                printf("\nHatali secim yaptiniz\n\n");
                sonYonlendirme();
                break;
        }
    } else {

        printf("Borcunuz bulunmamaktadir.\n");
        sonYonlendirme();
    }
}

void faturaOdemeIslemleri() {
    clearScreen();
    printf("FATURA ODEME ISLEMLERI\n");
    int response;

    printf("1 - Su faturasi borcunuz: %d\n", user.su_faturasi);
    printf("2 - Elektrik faturasi borcunuz: %d\n", user.elektrik_faturasi);
    printf("3 - Dogalgaz faturasi borcunuz: %d\n", user.dogalGaz_faturasi);

    printf("Yatirmak istediginiz fatura numarasini giriniz:");
    scanf(" %d", &response);

    switch (response) {
        case 1:
            if (user.bakiye >= user.su_faturasi) {
                user.bakiye = (user.bakiye - user.su_faturasi);
                user.su_faturasi = 0;
                kullaniciBilgileriniYazdir();
                kullaniciBilgileriniCek(USER1);
                beklet(3);

                printf("1 - Su faturasi borcunuz: %d\n", user.su_faturasi);
                printf("2 - Elektrik faturasi borcunuz: %d\n", user.elektrik_faturasi);
                printf("3 - Dogalgaz faturasi borcunuz: %d\n", user.dogalGaz_faturasi);
            } else {
                printf("Borcunuzu odemek icin yeterli bakiyeye sahip degilsiniz.\n");
            }
            sonYonlendirme();
            break;
        case 2:
            if (user.bakiye >= user.elektrik_faturasi) {
                user.bakiye = (user.bakiye - user.elektrik_faturasi);
                user.elektrik_faturasi = 0;
                kullaniciBilgileriniYazdir();
                kullaniciBilgileriniCek(USER1);
                beklet(3);

                printf("1 - Su faturasi borcunuz: %d\n", user.su_faturasi);
                printf("2 - Elektrik faturasi borcunuz: %d\n", user.elektrik_faturasi);
                printf("3 - Dogalgaz faturasi borcunuz: %d\n", user.dogalGaz_faturasi);
            } else {
                printf("Borcunuzu odemek icin yeterli bakiyeye sahip degilsiniz.\n");
            }
            sonYonlendirme();
            break;
        case 3:
            if (user.bakiye >= user.dogalGaz_faturasi) {
                user.bakiye = (user.bakiye - user.dogalGaz_faturasi);
                user.dogalGaz_faturasi = 0;
                kullaniciBilgileriniYazdir();
                kullaniciBilgileriniCek(USER1);
                beklet(3);

                printf("1 - Su faturasi borcunuz: %d\n", user.su_faturasi);
                printf("2 - Elektrik faturasi borcunuz: %d\n", user.elektrik_faturasi);
                printf("3 - Dogalgaz faturasi borcunuz: %d\n", user.dogalGaz_faturasi);
            } else {
                printf("Borcunuzu odemek icin yeterli bakiyeye sahip degilsiniz.\n");
            }
            sonYonlendirme();
            break;
        default:
            printf("\nHatali secim yaptiniz\n\n");
            sonYonlendirme();
            break;
    }
}

void odemeIslemleri_Menu() {
    clearScreen();
    printf("ODEME ISLEMLERI MENUSU\n");
    int response;

    printf("1 - Fatura Odeme \n");
    printf("2 - Trafik Cezasi Odeme \n");
    printf("3 - Egitim Odemeleri \n");

    printf("Odemek istediginiz faturanin numarasini giriniz:");
    scanf(" %d", &response);

    switch (response) {
        case 1:
            faturaOdemeIslemleri();
            break;
        case 2:
            trafikCezaOdemeIslemleri();
            break;
        case 3:
            egitimOdemeIslemleri();
            break;
        default:
            printf("\nHatali secim yaptiniz\n\n");
            sonYonlendirme();
            break;
    }
}

void paraCekme() {
    int bakiye, tutar, islemSonucu;
    bakiye = 1000;
    printf(" BAKIYENIZ: %d\n", bakiye);
    printf(" CEKMEK ISTEDIGINIZ TUTARI GIRINIZ: ");
    scanf(" %d", &tutar);
    islemSonucu = bakiye - tutar;

    //??ıslemler user.bakiye =bakiye- tutar
    printf(" YENI BAKIYENIZ: %d", islemSonucu);
    printf(" CEKMIS OLDUGUNUZ TUTAR: %d\n\n", tutar);
    anamenu();
}


void krediKartinaYatirma() {
    int tutar;




    // kredi kartı bakiye ya da kullanılabilir limiti eksik tanımlanmalı
    // yeni bakiye user.bakiye ye mi yazdırılmalı


    printf("YATIRMAK ISTEDIGINIZ TUTARI GIRINIZ : ");
    scanf(" %d", &tutar);

    user.bakiye -= tutar;
    user.kredi_karti_borc -= tutar;

    printf(" YATIRDIGINIZ TUTAR: %d\n\n ", tutar);
    anamenu();
}

void hesabaYatirma() {

    int tutar, bakiye, islemSonucu;
    //bakiye = user.bakiye;
    bakiye = 1000;


    printf("YATIRMAK ISTEDIGINIZ TUTARI GIRINIZ : ");
    scanf(" %d", &tutar);

    // ??ıslemeler? user.bakiye = user.bakiye+tutar;
    // user.bakiye = bakiye - tutar;
    // user.bakiye = islemSonucu;

    islemSonucu = bakiye - tutar;

    printf(" YATIRDIGINIZ TUTAR: %d ", tutar);
    printf(" YENI BAKIYENIZ: %d\n\n", islemSonucu);
    anamenu();


}

void paraYatirma_Menu() {

    int response;
    printf(" PAARA YATIRMA MENUSU\n\n");
    printf("1 - HESABA PARA YATIRMA\n");
    printf("2 - KREDI KARTINA PARA YATIRMA\n");

    scanf(" %d", &response);

    switch (response) {
        case 1 :
            hesabaYatirma();
            break;
        case 2 :
            krediKartinaYatirma();
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
            paraYatirma_Menu();
            break;
        case 2 :
            paraCekme();
            break;
        default:
            printf("\nHatali islem yaptiniz \n\n");
            anamenu();
            break;

    }


}

void anamenu() {
clearScreen();
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
        case 1:
            paraIslemleri_Menu();
            break;
        case 2:
            odemeIslemleri_Menu();
            break;
        case 3:
            basvuruIslemleri_Menu();
            break;
        case 4:
            yatirimIslemleri_Menu();
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


void girisYap() {
clearScreen();

    int result;
    char deger[25];
    printf("GIRIS YAP\n\n");
    printf("HESABINIZA AIT SIFREYI GIRINIZ:");

    scanf("%s", deger);
    char sifre[25];

    sprintf(sifre, "%d", user.password);


    result = strcmp(deger, sifre);

    if (result == 0) {
        anamenu();
    } else {
        printf("\nHATALI SIFRE GIRDINIZ TEKRAR DENEYIN\n");
        girisYap();
    }
}

void sinavOdemeleri_Menu() {
    clearScreen();
    printf("SINAV ODEMELERI SAYFASI\n");
    char kimlikNo[11];
    int kpssUcreti = 300;
    int response;

    printf("TC kimlik numaranizi giriniz:");
    scanf(" %s", kimlikNo);

    while (strlen(kimlikNo) != 11) {
        printf("\nHatali kimlik no giris yaptiniz, tekrar giriniz...\n");
        scanf(" %s", kimlikNo);
    }
    printf("KPSS sinav ucreti: %d\n", kpssUcreti);
    printf("Odemek istiyorsaniz 1'e, cikis yapmak icin 0'a basiniz:");
    scanf(" %d", &response);

    switch (response) {

        case 1:
            kpssUcreti = 0;
            beklet(3);
            printf("Odemeniz basariyla alinmistir.\n");
            anamenu();
            break;
        case 0:
            printf("Odeme gerceklestirilmedi...\n");
            // printf("Giris sayfasina yonlendiriliyorsunuz...\n");
            anamenu();
            break;
        default:
            printf("\nHatali secim yaptiniz\n\n");
            anamenu();
            break;
    }
}

void applicationStart() {
    clearScreen();
    int response;
    printf("BETABANK'A HOS GELDINIZ\n");
    printf("1 - GIRIS YAP\n");
    printf("2 - KARTSIZ ISLEMLER(SINAV ODEMELERI)\n");
    scanf(" %d", &response);
    switch (response) {
        case 1:
            girisYap();
            break;
        case 2:
            sinavOdemeleri_Menu();
            break;
        default:
            applicationStart();
            break;
    }
}


#endif //BETA_BANK_FRONTEND_H
