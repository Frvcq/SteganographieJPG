/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ffarvacque
 *
 * Created on 27 janvier 2021, 07:58
 */

#include <stdio.h>
#include <stdlib.h>
#include "flavian.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
  
  // afficherSteganoTxt(CHEMIN, 49152);
   
   extraireSteganoImg(CHEMINIMAGECACHER,999,CHEMINDESTINATION);


    return (EXIT_SUCCESS);
}

