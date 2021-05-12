#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char userId[50];
    char password[50];
    char hesap_no[50];
    char iban[50];
    char bakiye[50];
    char kredi_karti[50];
    char kredi_karti_borc[50];
    char elektrik_faturasi[50];
    char su_faturasi[50];
    char dogalGaz_faturasi[50];
    char trafik_cezasi[50];
    char trafik_cezasi_borc[50];
    char egitim_odemeleri[50];
    char yks_ucreti[50];
    char kpss_ucreti[50];
    char ehliyet_ucreti[50];
    char kredi_karti_basvuru[50];
    char kredi_karti_limit_arttirma[50];
    char bireysel_kredi_basvurusu[50];
    char doviz_hesabi[50];
    char dolar_bakiye[50];
    char euro_bakiye[50];
    char altin_bakiye[50];
    char hisse_senedi_hesabi[50];
    char doviz_bakiyeleri[50];
    char hisseler[50];
} User;

User user;

#include "frontend.h"
#include "backend.h"


int main() {



    applicationStart();


}



