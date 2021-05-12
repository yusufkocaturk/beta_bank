
// Created by Yusuf Kocatürk on 7.05.2021.
/*
 *  * İŞLEYİŞ
 * UYGULAMA BAŞLAR => KULLANICI BİLGİLERİ TEXT DOSYASINDAN PROGRAM BELLEĞİNE AKTARILIR
 * BUNU STRUCT KULLANARAK İLGİLİ ALANLARIN TEXTTEN ÇEKTİRİLİP DOLDURULMASI İLE YAPILMASI SAĞLANIR
 * TEXTTEKİ VERİLERİ RAM'E ALDIKTAN SONRA DOSYA İLE TEKRAR İŞLEM YAPILACAK ZAMANA KADAR DOSYA KAPATILIP
 * İŞLEMLERİN RAMDE TANIMLANMIŞ BİR STRUCT(KULLANICI VEYA USER ADINDA) İLE AKTARILIP PERFORMANS İYİLEŞTİRMESİ YAPMIŞ OLUNUR
 *
 * KULLANICI VERİLERİ GETİRİLDİKTEN SONRA ANA MENU GOSTERİLİR VE ILGILI İŞLEMLERİN İLGİLİ SORGULARI YAPILARAK PROGRAM
 * AKIŞI DEVAM EDER
 *
 * YAZMA OKUMA İŞLEMLERİ İÇİN DOSYA YOLLARI, OKUMA MODLARI GİBİ ŞEYLER DEFİNE İLE TANIMLANIP OKUNABİLİRLİK SAĞLANIR
 *
 * HER MENU ARAYUZU BIR FONKSİYON OLARAK TANIMLANIP İLGİLİ YERLERDE FONKSİYON TANIMLANMASI YAPILIR
 *
 *
 *
 *
  ============================== İŞLEM FONKSİYONLARI =============================================
  DOSYALARDA VERİ GİRİŞİ OLARAK TETX VE BINARY OLMAK UZERE 2 MOD VARDIR

    fopen(dosya_adı,işlem_modu)	dosyayı açar => ptr = fopen("fileopen","mode");
    fclose(dosya_işaretçisi) dosyayı kapatır => fclose(fptr);

	fprintf()	printf in dosya ile çalışan hali =>  fprintf(fptr,"%formatı",deger);
    fscanf()	scanf in dosya ile çalışan hali  =>  fscanf(fptr,"%format", &degeri_tutmak_icin_degisken);

    feof(filepointer) pointerın gösterdiği dosaynın end of file olup olmadığını bool oalrak döner
    while(!feof(dosya){işlemler} gibi kullanılabilir

    fwrite() binary dosyaları yazmak için kullanılır
    fread() dosyalardan veri okur
    => fread(veri_tutan_degisken , tek_seferde_kac_karakter_okuyacagı , islemi_kac_kere_yapacagi , dosya_pointeri);
    =>  fread(charDizisi,6,1,file); tek seferde 6 karakteri 1 kere okuyup 11 karakterli
    charDizisine yazar dolayısıyla 4 karakter 1 null kalır
    =>  fread(charDizisi,2,3,file); tek seferde 2 karakteri 3 kere okur 6 ya 1 ile aynı işlemi yapmış olur
    =>  fread(charDizisi,1,6,file); tek seferde 1 karakteri 6 kere okur 6 ya 1 ve 3 e 2 ile aynı işlemleri yapar
    yani bu sayıların verilen değerin sayısıyla uyuşması gerekir yoksa yazmada belirsiz karakterler ortaya çıkabilir


    fseek()	dosyada pointer'ı verilen noktaya ayarlar
    pointer yerini set etmek için 3 modu var
    SEEK_SET    baştan
    SEEK_END    sondan
    SEEK_CUR    o anki konumundan itibaren hareket eder
    =>  fseek(dosya,-30,SEEK_END); dosya adlı pointerın işaret ettiği file'da
    sondan başlayıp -50 karakter gitmesi gerektiğini söyler.

    fputs() string ekler => fputs("string",fptr);
    fgets()	reads a character from file

    ftell()	=> ftell(fptr) cursor'ın o anki konumunu dönderir d veya ld formatında

    fputc()	writes a character into the file
    fgetc()	reads a character from file


    fputw()	writes an integer to file
    fgetw()	reads an integer from file

	rewind()	sets the file pointer to the beginning of the file

 ============================== İŞLEM MODLARI =============================================
r	okuma modunda açar, dosya yoksa oluşturmaz
w	yazma modunda açar, dosya içeriği üzerine yazılır, dosya yoksa oluştutur
a	dosyanın sonuna ekleme yapar dosya yoksa oluşturur

r+	hem okuma hem yazma modunda açar, dosya yoksa null döner, oluşturmaz
w+	okuma ve yazma modunda açar dosya içeriği üzerine yazılır dosya yoksa oluşturulur
a+  okuma ve ekleme modunda açar, dosya yoksa oluşturulur
 ******************************************************************
rb	aynı işlemlerin binary mod için geçerli durumları
wb	aynı işlemlerin binary mod için geçerli durumları
ab	aynı işlemlerin binary mod için geçerli durumları
rb+	aynı işlemlerin binary mod için geçerli durumları
wb+	aynı işlemlerin binary mod için geçerli durumları
ab+	aynı işlemlerin binary mod için geçerli durumları

 ==================== İŞLETİM SİSTEMİ KONTROLÜ ==========================
 Global path vermede gerekli olabilir



 ==================== GEREKLİ OLABİLECEK FONKSİYONLAR ==========================

 STRING FONKSİYONLAR
 strlen() bir string arrayinin uzunluğunu döner
 strcmp(dizi1,dizi2) 2 string arrayini karşılaştırıp doğru ise 0 döner yanlış ise 1
 strcat(dizi1,dizi2) 2 string arrayini birleştirir
 strcpy(dizi1,dizi2) dizi2 nin değerini dizi1 in değerinin yerine yazar.

 strstr(dizi_adi,"string") dizi_adi dizisindeki yazıların string ile belirtilen kısmından sonrasını alır
 => Ornegin
    char dizi[] = "bu bir ornektir";
    printf("%s",strstr(dizi,"bir"));
    OUTPUT:
    bir ornektir
    **********************************************************************
    *
    STRING DEGERİ INT E CEVİRME
    int a = 0;
    char strinG[] ="1234";
    a = atoi(strinG);
    a artık 1234 sayısı olmuş oluyor.
 */
//

#ifndef BETA_BANK_NOTLAR_H
#define BETA_BANK_NOTLAR_H

#define USER1 "user1.txt"
#define USER2 "user2.txt"
#define TEDAS "tedas.txt"


#include <stdbool.h>
#include <stdio.h>

#ifndef _WIN32
printf("win");
#endif __APPLE__
printf("apple");


#define OKUMA_MODU "r"
#define YAZMA_MODU "w"
#define OKUMA_YAZMA_MODU "wr"


void elektrikOde() {

}


void dosyaAc(char filename[], char mode[], bool newLine) {

    char den[18];
    FILE *file = fopen("deneme.txt", "w");
//    fprintf(file, "deneme deniyorum\nguzel de oldu");

//    fclose(file);
//    file = fopen("deneme.txt", "r");
//
//    if (!feof(file)) {
//        fread(den, 1, 1, file);
//
//    } else {
//        printf("\ndosya sounu");
//    }
//
//    printf(" %s ", den);


    //  printf("\nkonum: %d ", ftell(file));

//    char cdizi[] = "deneme";
//
//    FILE *dosya;
//    dosya = fopen(filename, "w");
//    fprintf(dosya, "userId: %d \npassword: %d \n", 123412, 23434);
//    fwrite(cdizi, strlen(cdizi), 1, dosya);
//    fwrite(cdizi, strlen(cdizi), 1, dosya);
//    int count_lines = 0;
//    char chr;
//    rewind(dosya);
//    dosya = fopen(filename, "r");
//    chr = getc(dosya);

//    fseek(dosya, -30, SEEK_END);
//    while (chr != EOF) {
//        //Count whenever new line is encountered
//        if (chr == '\n') {
//
//            count_lines = count_lines + 1;
//        }
//        //take next character from file.
//        chr = getc(dosya);
//    }
//    fclose(dosya);
//    printf("There are %d lines in %s  in a file\n", count_lines, filename);


//    rewind(dosya);
//    dosya = fopen(filename, "r");
//    char deger;
//
//    while (1) {
//        deger = fgetc(dosya,1); //Each character of the file is read and stored in the character file.
//        if (deger == EOF)
//            break;
//        printf("%c", deger);
//    }
//    fclose(dosya);


}


#endif //BETA_BANK_NOTLAR_H

// SATIR SAYMA FONKSİYONU
int count_line() {
    char chr;
    int count_lines = 0;
    chr = getc(fptr);
    while (chr != EOF) {
        if (chr == '\n') {
            count_lines = count_lines + 1;
        }
        //take next character from file.
        chr = getc(fptr);
    }
    return count_lines;
}


// ****** ÇEŞİTLİ PARAMETRELER İLE MODÜLER HALE GETİRİLMELİ DÜZELTME VE GUNCELLEME GEREKLİ *********

// SATIRLARDAN GELEN VERİNİN BİR DİZİNİN ELEMANLARI OALRAK SAKLANMASI FONKSİYONU



void get_data_from_lines() {

    printf("\n****** get_data_from_lines fonksiyonundan gelen veriler *****\n");
    char c[1000];
    int i = 0;
    // BURADAKİ 2 SAYISININ YERİNE count_line fonksiyonunda gelen veri aktarılacak
    for (i; i < 2; i++) {
        fscanf(fptr, "%[^\n]", c);
        fseek(fptr, 1, SEEK_CUR);
        printf("\n%d.Satır\n%s offset:%d\n", i + 1, c, ftell(fptr));
    }
    printf("\n*****************************************\n");
}



// SATIRLARDAN GELEN VERİNİN SADECE SAYI OLDUĞU FONKSİYON
// DoL: data from lines



void get_DfL_as_number() {

    int count_lines = 0;
    printf("\n****** get_DfL_as_number fonksiyonundan gelen veriler *****\n");
    int i = 0;
    char deneme[100];
    int den = 0;
    for (i; i < count_lines; i++) {

        fscanf(fptr, "%[^\n]", c);
        strcpy(deneme, strstr(c, " "));
        den = atoi(deneme);
        fseek(fptr, 1, SEEK_CUR);
        printf("\n%d.Satır\n%d\n", i + 1, den);
    }
    printf("\n*****************************************\n");
}



//    FILE *ptr;
//
//    ptr = fopen("sule.txt", "w");
//
//
//    char response;
//    printf("ana menu 1");
//
//
//    switch (getchar()) {
//        case '1':
//             hesaba_para_yatirma();
//            break;
//        case '2':
//            kredi_kartina_para_yatirma();
//            break;
//        default:
//            printf("Lütfen Menüdeki Seçeneklerden Birini Seçiniz");
//            break;
//    }





//    kullanici kul;
//
//    char c[1000];
//    char chr;
//    FILE *fptr;
//
//    fptr = fopen("metin.txt", "w");
//    fprintf(fptr, "userId: %d \npassword: %d \n", 123412, 23434);
//
//
//
//  if ((fptr = fopen("metin.txt", "r")) == NULL) {
//        printf("Error! File cannot be opened.");
//        // Program exits if the file pointer returns NULL.
//        exit(1);
//    }
//
//
//
//    //Count whenever new line is encountered
//    int count_lines = 0;
//    chr = getc(fptr);
//    while (chr != EOF) {
//        if (chr == '\n') {
//            count_lines = count_lines + 1;
//        }
//        //take next character from file.
//        chr = getc(fptr);
//    }
//    rewind(fptr);
//    printf("%d", count_lines);
//
//
//    int i = 0;
//    int den[100];
//    for (i; i < count_lines; i++) {
//        char deneme[100];
//
//        fscanf(fptr, "%[^\n]", c);
//        strcpy(deneme, strstr(c, " "));
//        den[i] = atoi(deneme);
//        fseek(fptr, 1, SEEK_CUR);
//        printf("\n%d.Satır\n%d\n", i + 1, den[i]);
//
//    }
//    kul.userId = den[0];
//    kul.bakiye = den[2];
//



//    printf("\nUser ID %d\n", kul.userId);
//    printf("\nbky %d", kul.bakiye);
//
//    fscanf(fptr, "%[^\n]", c);
//    fseek(fptr, 1, SEEK_CUR);
//    printf("%d.Satır\n%s offset:%d", i, c, ftell(fptr));
//    fscanf(fptr, "%[^\n]", c);
//    fseek(fptr, 1, SEEK_CUR);
//    printf("\nData from the file:\n%s offset:%d", c, ftell(fptr));
//    fclose(fptr);
//

