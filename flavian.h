/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   flavian.h
 * Author: ffarvacque
 *
 * Created on 27 janvier 2021, 07:58
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#pragma pack(push, 1)
#ifndef FLAVIAN_H
#define FLAVIAN_H
#define CHEMIN "/home/USERS/ELEVES/SNIR2020/imgBMP/plasmaSteganoTexte.bmp"
#define CHEMINIMAGECACHER "/home/USERS/ELEVES/SNIR2020/imgBMP/mandelSteganoImg.bmp"
#define CHEMINDESTINATION "/tmp/test.bmp"
#ifdef __cplusplus
extern "C" {
#endif
    
    typedef struct {
        unsigned char signature[2];
        unsigned int tailleFichier;
        unsigned int reserve;
        unsigned int adresseImg;

    } TypeEnTeteFichierBmp;

    typedef struct {
        unsigned int tailleEnTete;
        unsigned int largeur;
        unsigned int hauteur;
        unsigned short int nbPlan;
        unsigned short int bitParPixel;
        unsigned int typeCompression;
        unsigned int tailleImage;
        unsigned int resolutionHorizontale;
        unsigned int resolutionVerticale;
        unsigned int nbCouleursUtilises;
        unsigned int nbCouleursImportantes;
    } TypeEnTeteImage;

    typedef struct {
        unsigned char bleu;
        unsigned char vert;
        unsigned char rouge;
        unsigned char alpha; // reserve
    } typeCouleur;

    void afficherSteganoTxt(char *, int);
    void extraireSteganoImg(char*,int,char*);
    void cachePalette(char*,char*,char*);


#ifdef __cplusplus
}
#endif

#endif /* FLAVIAN_H */

