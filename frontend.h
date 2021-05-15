

#ifndef BETA_BANK_FRONTEND_H
#define BETA_BANK_FRONTEND_H


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

void egitimOdemeIslemleri(){
    printf("EGITIM ODEME ISLEMLERI\n");
    int response;

    strcpy(user.yks_ucreti , "100");
    strcpy(user.kpss_ucreti , "250");
    strcpy(user.ehliyet_ucreti , "750");
    strcpy(user.bakiye , "300");

    printf("1 - YKS ucreti: %d\n",atoi(user.yks_ucreti));
    printf("2 - KPSS ucreti: %d\n",atoi(user.kpss_ucreti));
    printf("3 - Ehliyet sinavi ucreti: %d\n",atoi(user.ehliyet_ucreti));

    printf("Ucretini odemek istediginiz sinavin numarasini giriniz:");
    scanf(" %d",&response);

    switch (response) {
        case 1:
            if(atoi(user.bakiye) >= atoi(user.yks_ucreti)){
                strcpy(user.yks_ucreti , "0");
                printf("Isleminiz basariyla gerceklesmistir.\n");
            }
            else{
                printf("Borcunuzu odemek icin yeterli bakiyeye sahip degilsiniz.\n");
            }
            anamenu();
            break;
        case 2:
            if(atoi(user.bakiye) >= atoi(user.kpss_ucreti)){
                strcpy(user.kpss_ucreti , "0");
                printf("Isleminiz basariyla gerceklesmistir.\n");
            }
            else{
                printf("Borcunuzu odemek icin yeterli bakiyeye sahip degilsiniz.\n");
            }
            anamenu();
            break;
        case 3:
            if(atoi(user.bakiye) >= atoi(user.ehliyet_ucreti)){
                strcpy(user.ehliyet_ucreti , "0");
                printf("Isleminiz basariyla gerceklesmistir.\n");
            }
            else{
                printf("Borcunuzu odemek icin yeterli bakiyeye sahip degilsiniz.\n");
            }
            anamenu();
            break;
        default:
            printf("\nHatali secim yaptiniz\n\n");
            anamenu();
            break;
    }
}

void trafikCezaOdemeIslemleri(){
    printf("TRAFIK CEZASI ODEME ISLEMLERI\n");
    int response;
    strcpy(user.trafik_cezasi_borc , "1000");
    strcpy(user.bakiye , "2000");

    if(user.trafik_cezasi_borc != 0){
        printf("Trafik cezasi borcunuz: %d\n",atoi(user.trafik_cezasi_borc));
    }
    else{
        printf("Borcunuz bulunmamaktadir.\n");
    }
    printf("Borcunuzu odemek istiyorsaniz 1'e yoksa 0'a basiniz:");
    scanf(" %d",&response);

    switch (response) {
        case 1:
            if(atoi(user.bakiye) >= atoi(user.trafik_cezasi_borc)){
                strcpy(user.trafik_cezasi_borc , "0");
                printf("Borcunuz basariyla odendi.\n");
            }
            else{
                printf("Borcunuzu odemek icin yeterli bakiyeye sahip degilsiniz.\n");
            }
            anamenu();
            break;
        case 0:
            anamenu();
            break;
        default:
            printf("\nHatali secim yaptiniz\n\n");
            anamenu();
            break;
    }
}

void faturaOdemeIslemleri(){
    printf("FATURA ODEME ISLEMLERI\n");
    int response;

    strcpy(user.su_faturasi , "500");
    strcpy(user.elektrik_faturasi , "1000");
    strcpy(user.dogalGaz_faturasi , "1500");
    strcpy(user.bakiye , "1000");

    printf("1 - Su faturasi borcunuz: %d\n",atoi(user.su_faturasi));
    printf("2 - Elektrik faturasi borcunuz: %d\n",atoi(user.elektrik_faturasi));
    printf("1 - Dogalgaz faturasi borcunuz: %d\n",atoi(user.dogalGaz_faturasi));

    printf("Yatirmak istediginiz fatura numarasini giriniz:");
    scanf(" %d",&response);

    switch (response) {
        case 1:
            if(atoi(user.bakiye) >= atoi(user.su_faturasi)){
                strcpy(user.su_faturasi , "0");

                printf("1 - Su faturasi borcunuz: %d\n",atoi(user.su_faturasi));
                printf("2 - Elektrik faturasi borcunuz: %d\n",atoi(user.elektrik_faturasi));
                printf("1 - Dogalgaz faturasi borcunuz: %d\n",atoi(user.dogalGaz_faturasi));
            }
            else{
                printf("Borcunuzu odemek icin yeterli bakiyeye sahip degilsiniz.\n");
            }
            anamenu();
            break;
        case 2:
            if(atoi(user.bakiye) >= atoi(user.elektrik_faturasi)){
                strcpy(user.elektrik_faturasi , "0");

                printf("1 - Su faturasi borcunuz: %d\n",atoi(user.su_faturasi));
                printf("2 - Elektrik faturasi borcunuz: %d\n",atoi(user.elektrik_faturasi));
                printf("3 - Dogalgaz faturasi borcunuz: %d\n",atoi(user.dogalGaz_faturasi));
            }
            else{
                printf("Borcunuzu odemek icin yeterli bakiyeye sahip degilsiniz.\n");
            }
            anamenu();
            break;
        case 3:
            if(atoi(user.bakiye) >= atoi(user.dogalGaz_faturasi)){
                strcpy(user.dogalGaz_faturasi , "0");

                printf("1 - Su faturasi borcunuz: %d\n",atoi(user.su_faturasi));
                printf("2 - Elektrik faturasi borcunuz: %d\n",atoi(user.elektrik_faturasi));
                printf("1 - Dogalgaz faturasi borcunuz: %d\n",atoi(user.dogalGaz_faturasi));
            }
            else{
                printf("Borcunuzu odemek icin yeterli bakiyeye sahip degilsiniz.\n");
            }
            anamenu();
            break;
        default:
            printf("\nHatali secim yaptiniz\n\n");
            anamenu();
            break;
    }
}

void odemeIslemleri_Menu() {
    printf("2 - ODEME ISLEMLERI MENUSU\n");
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
            anamenu();
            break;
    }
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

void sinavOdemeleri_Menu(){
    printf("SINAV ODEMELERI SAYFASI\n");
    char kimlikNo[11];
    int kpssUcreti=300;
    int response;

    printf("TC kimlik numaranizi giriniz:");
    gets(kimlikNo);

    while(strlen(kimlikNo) != 11){
        printf("\nHatali kimlik no giris yaptiniz, tekrar giriniz...\n");
        gets(kimlikNo);
    }
    printf("KPSS sinav ucreti: %d\n",kpssUcreti);
    printf("Odemek istiyorsaniz 1'e, cikis yapmak icin 0'a basiniz:");
    scanf(" %d", &response);

    switch (response) {
        case 1:
            kpssUcreti=0;
            printf("Odemeniz basariyla alinmistir.\n");
            applicationStart();
            break;
        case 0:
            printf("Odeme gerceklestirilmedi...\n");
            printf("Giris sayfasina yonlendiriliyorsunuz...\n");
            applicationStart();
            break;
        default:
            printf("\nHatali secim yaptiniz\n\n");
            applicationStart();
            break;
    }
}

void applicationStart() {
    anamenu();
}


#endif //BETA_BANK_FRONTEND_H
