#include <stdio.h>
#include <string.h>

#include <stdlib.h>

typedef struct {
    int userId;
    int password;
    int bakiye;
    int suFaturasi;
    int elektrikFaturasi;
} kullanici;

int main() {

    kullanici kul;

    char c[1000];
    char chr;
    FILE *fptr;
//    fptr = fopen("meti.txt", "w");
//    fprintf(fptr, "userId: %d \npassword: %d \n", 123412, 23434);
//

    if ((fptr = fopen("metin.txt", "r")) == NULL) {
        printf("Error! File cannot be opened.");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    //Count whenever new line is encountered
    int count_lines = 0;
    chr = getc(fptr);
    while (chr != EOF) {
        if (chr == '\n') {
            count_lines = count_lines + 1;
        }
        //take next character from file.
        chr = getc(fptr);
    }
    rewind(fptr);
    printf("%d", count_lines);


    int i = 0;
    int den[100];
    for (i; i < count_lines; i++) {
        char deneme[100];

        fscanf(fptr, "%[^\n]", c);
        strcpy(deneme, strstr(c, " "));
        den[i] = atoi(deneme);
        fseek(fptr, 1, SEEK_CUR);
        printf("\n%d.Satır\n%d\n", i + 1, den[i]);

    }
    kul.userId = den[0];
    printf("\nUser ID %d", kul.userId);

//    fscanf(fptr, "%[^\n]", c);
//    fseek(fptr,1,SEEK_CUR);
//    printf("%d.Satır\n%s offset:%d",i, c, ftell(fptr));
//    fscanf(fptr, "%[^\n]", c);
//    fseek(fptr,1,SEEK_CUR);
//    printf("\nData from the file:\n%s offset:%d", c, ftell(fptr));
//    fclose(fptr);
    return 0;

}
