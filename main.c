#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//

typedef struct {
    int userId;
    int password;
    int hesap_no;
    int iban;
    int bakiye;
    int kredi_karti;
    int kredi_karti_borc;
    int elektrik_faturasi;
    int su_faturasi;
    int dogalGaz_faturasi;
    int trafik_cezasi_borc;
    int yks_ucreti;
    int kpss_ucreti;
    int ehliyet_ucreti;
    int kredi_karti_basvuru;
    int kredi_karti_limit_arttirma;
    int kredi_karti_limit_miktari;
    int bireysel_kredi_basvurusu;

    int dolar_bakiye;
    int euro_bakiye;
    int altin_bakiye;

} User;

User user;

#include "backend.h"
#include "frontend.h"


int main() {
    //
    //veriGirisiYap(USER1);
    detectOperatingSystem();
    kullaniciBilgileriniCek(USER1);
    applicationStart();
}


