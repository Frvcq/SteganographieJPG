/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "flavian.h"

void afficherSteganoTxt(char * chemin, int pas) {
    size_t check;
    FILE * f;
    int i = 0, seekCheck = 0;
    char code;

    f = fopen(chemin, "r");

    if (f == NULL) {
        printf("Ouverture impossible , veuillez contacter votre centrale : %s",
                strerror(errno));
    }


    seekCheck = fseek(f, sizeof (TypeEnTeteImage) + sizeof (TypeEnTeteFichierBmp)+(sizeof (typeCouleur)*256)
            , SEEK_SET);

    if (seekCheck == -1) {
        printf("Erreur du premier Fseek : %s", strerror(errno));

    }


    while (!(feof(f))) {
        check = fread(&code, sizeof (char), 1, f);

        if (check != 1) {
            printf("pb de décodage , la CIA arrive : %s\n", strerror(errno));
            exit(errno);
        }
        printf("%c", code);
        seekCheck = fseek(f, pas, SEEK_CUR);

        if (seekCheck == -1) {
            printf("Pb de fseek au pas : %s", strerror(errno));
        }

    }

    if (fclose(f) == EOF) {
        printf("%s", strerror(errno));

    }


}

void extraireSteganoImg(char* chemin, int pas, char* agenerer) {
    size_t check;
    FILE * f;
    FILE * d;
    int i = 0, seekCheck = 0;
    char code;

    f = fopen(chemin, "r");



    if (f == NULL) {
        printf("Ouverture impossible de la source , veuillez contacter votre centrale : %s \n",
                strerror(errno));
        exit(errno);
    }

    d = fopen(agenerer, "w");
    if (d == NULL) {
        printf("Ouverture impossible de la destination , veuillez contacter votre centrale : %s \n",
                strerror(errno));
        exit(errno);
    }


    seekCheck = fseek(f, sizeof (TypeEnTeteImage) + sizeof (TypeEnTeteFichierBmp)+(sizeof (typeCouleur)*256)
            , SEEK_SET);

    if (seekCheck == -1) {
        printf("Erreur du premier Fseek : %s", strerror(errno));

    }

    while (!(feof(f))) {
        check = fread(&code, sizeof (char), 1, f);

        if (check != 1) {
            printf("pb de lecture de décodage  : %s\n", strerror(errno));
            exit(errno);
        }
        check = fwrite(&code, sizeof (char), 1, d);

        if (check != 1) {
            printf("pb de décodage  : %s\n", strerror(errno));
            exit(errno);
        }
        seekCheck = fseek(f, pas, SEEK_CUR);

        if (seekCheck == -1) {
            printf("Pb de fseek au pas : %s", strerror(errno));
        }



    }

    if (fclose(f) == EOF) {
        printf("%s", strerror(errno));

    }

    if (fclose(d) == EOF) {
        printf("%s", strerror(errno));

    }




}

void cachePalette(char* message, char* source, char* destination) {
    FILE * ficsource;
    size_t check;
    FILE * ficdestination;
    typeCouleur palette[256];
    TypeEnTeteFichierBmp bmp;
    TypeEnTeteImage image;
    unsigned char tampon;

    int taille, i, checkfseek;

    ficsource = fopen(source, "r");
    if (ficsource == NULL) {
        printf("%s", strerror(errno));
    }
    ficdestination = fopen(destination, "w");

    if (ficdestination == NULL) {
        printf("%s", strerror(errno));
    }



    check = fread(&bmp, sizeof (TypeEnTeteFichierBmp), 1, ficsource);
    if (check != 1) {

        printf("%s", strerror(errno));

    }

    check = fwrite(&bmp, sizeof (TypeEnTeteFichierBmp), 1, ficdestination);
    if (check != 1) {

        printf("%s", strerror(errno));

    }
    check = fread(&image, sizeof (TypeEnTeteImage), 1, ficsource);
    if (check != 1) {

        printf("%s", strerror(errno));

    }

    check = fwrite(&image, sizeof (TypeEnTeteImage), 1, ficdestination);

    if (check != 1) {

        printf("%s", strerror(errno));

    }


    check = fread(&palette, sizeof (typeCouleur), 256, ficsource);



    if (check != 256) {

        printf("%s", strerror(errno));

    }
    taille = strlen(message);



    for (i = 0; i <= taille; i++) {
        if (palette[0].alpha != taille) {
            palette[0].alpha = taille;

        } else {

            palette[i].alpha = message[i - 1];
        }

    }

    fwrite(&palette, sizeof (typeCouleur), 256, ficdestination);

    while (!(feof(ficsource))) {

        check = fread(&tampon, sizeof (unsigned char), 1, source);
        if (check != 1) {

            printf("%s", strerror(errno));

        }

        check = fwrite(&tampon, sizeof (unsigned char), 1, destination);
        if (check != 1) {

            printf("%s", strerror(errno));

        }

    }

    if (fclose(ficsource) == EOF) {
        printf("%s", strerror(errno));
    }

    if (fclose(ficdestination) == EOF) {
        printf("%s", strerror(errno));
    }


}