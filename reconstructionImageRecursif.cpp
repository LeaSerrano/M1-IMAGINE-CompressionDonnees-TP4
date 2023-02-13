#include <stdio.h>
#include "image_ppm.h"
#include <iostream>

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcriteOut[250],

  cNomImgLueBF[250], cNomImgLueMFH[250], cNomImgLueMFV[250], cNomImgLueHF[250],
  
  cNomImgLueBF2[250], cNomImgLueMFH2[250], cNomImgLueMFV2[250], cNomImgLueHF2[250],
  
  cNomImgLueBF3[250], cNomImgLueMFH3[250], cNomImgLueMFV3[250], cNomImgLueHF3[250],
  
  cNomImgLueBF4[250], cNomImgLueMFH4[250], cNomImgLueMFV4[250], cNomImgLueHF4[250],
  
  cNomImgLueBF5[250], cNomImgLueMFH5[250], cNomImgLueMFV5[250], cNomImgLueHF5[250],
  
  cNomImgLueBF6[250], cNomImgLueMFH6[250], cNomImgLueMFV6[250], cNomImgLueHF6[250];
  
  int nH, nW, nTaille, N;
  
  if (argc != 28) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%i",&N);
   sscanf (argv[3],"%s",cNomImgEcriteOut);

   sscanf (argv[4],"%s",cNomImgLueBF);
   sscanf (argv[5],"%s",cNomImgLueMFH);
   sscanf (argv[6],"%s",cNomImgLueMFV);
   sscanf (argv[7],"%s",cNomImgLueHF);

   sscanf (argv[8],"%s",cNomImgLueBF2);
   sscanf (argv[9],"%s",cNomImgLueMFH2);
   sscanf (argv[10],"%s",cNomImgLueMFV2);
   sscanf (argv[11],"%s",cNomImgLueHF2);

   sscanf (argv[12],"%s",cNomImgLueBF3);
   sscanf (argv[13],"%s",cNomImgLueMFH3);
   sscanf (argv[14],"%s",cNomImgLueMFV3);
   sscanf (argv[15],"%s",cNomImgLueHF3);

   sscanf (argv[16],"%s",cNomImgLueBF4);
   sscanf (argv[17],"%s",cNomImgLueMFH4);
   sscanf (argv[18],"%s",cNomImgLueMFV4);
   sscanf (argv[19],"%s",cNomImgLueHF4);

   sscanf (argv[20],"%s",cNomImgLueBF5);
   sscanf (argv[21],"%s",cNomImgLueMFH5);
   sscanf (argv[22],"%s",cNomImgLueMFV5);
   sscanf (argv[23],"%s",cNomImgLueHF5);

   sscanf (argv[24],"%s",cNomImgLueBF6);
   sscanf (argv[25],"%s",cNomImgLueMFH6);
   sscanf (argv[26],"%s",cNomImgLueMFV6);
   sscanf (argv[27],"%s",cNomImgLueHF6);

   OCTET *ImgIn, *BF, *MFH, *MFV, *HF, *ImgOut, *BF2, *MFH2, *MFV2, *HF2, *BF3, 
   *MFH3, *MFV3, *HF3, *BF4, *MFH4, *MFV4, *HF4, *BF5, *MFH5, *MFV5, *HF5,
   *BF6, *MFH6, *MFV6, *HF6;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille);
   allocation_tableau(ImgOut, OCTET, nTaille);
   
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);

   allocation_tableau(BF, OCTET, nH/2 * nW/2);
   allocation_tableau(MFH, OCTET, nH/2 * nW/2);
   allocation_tableau(MFV, OCTET, nH/2 * nW/2);
   allocation_tableau(HF, OCTET, nH/2 * nW/2);

   lire_image_pgm(cNomImgLueBF, BF, nH/2 * nW/2);
   lire_image_pgm(cNomImgLueMFH, MFH, nH/2 * nW/2);
   lire_image_pgm(cNomImgLueMFV, MFV, nH/2 * nW/2);
   lire_image_pgm(cNomImgLueHF, HF, nH/2 * nW/2);

   allocation_tableau(BF2, OCTET, nTaille/4);
   allocation_tableau(MFH2, OCTET, nTaille/4);
   allocation_tableau(MFV2, OCTET, nTaille/4);
   allocation_tableau(HF2, OCTET, nTaille/4);

   lire_image_pgm(cNomImgLueBF2, BF2, nH/4 * nW/4);
   lire_image_pgm(cNomImgLueMFH2, MFH2, nH/4 * nW/4);
   lire_image_pgm(cNomImgLueMFV2, MFV2, nH/4 * nW/4);
   lire_image_pgm(cNomImgLueHF2, HF2, nH/4 * nW/4);

   allocation_tableau(BF3, OCTET, nH/8 * nW/8);
   allocation_tableau(MFH3, OCTET, nH/8 * nW/8);
   allocation_tableau(MFV3, OCTET, nH/8 * nW/8);
   allocation_tableau(HF3, OCTET, nH/8 * nW/8);

   lire_image_pgm(cNomImgLueBF3, BF3, nH/8 * nW/8);
   lire_image_pgm(cNomImgLueMFH3, MFH3, nH/8 * nW/8);
   lire_image_pgm(cNomImgLueMFV3, MFV3, nH/8 * nW/8);
   lire_image_pgm(cNomImgLueHF3, HF3, nH/8 * nW/8);

   allocation_tableau(BF4, OCTET, nH/16 * nW/16);
   allocation_tableau(MFH4, OCTET, nH/16 * nW/16);
   allocation_tableau(MFV4, OCTET, nH/16 * nW/16);
   allocation_tableau(HF4, OCTET, nH/16 * nW/16);

   lire_image_pgm(cNomImgLueBF4, BF4, nH/16 * nW/16);
   lire_image_pgm(cNomImgLueMFH4, MFH4, nH/16 * nW/16);
   lire_image_pgm(cNomImgLueMFV4, MFV4, nH/16 * nW/16);
   lire_image_pgm(cNomImgLueHF4, HF4, nH/16 * nW/16);

   allocation_tableau(BF5, OCTET, nH/32 * nW/32);
   allocation_tableau(MFH5, OCTET, nH/32 * nW/32);
   allocation_tableau(MFV5, OCTET, nH/32 * nW/32);
   allocation_tableau(HF5, OCTET, nH/32 * nW/32);

   lire_image_pgm(cNomImgLueBF5, BF5, nH/32 * nW/32);
   lire_image_pgm(cNomImgLueMFH5, MFH5, nH/32 * nW/32);
   lire_image_pgm(cNomImgLueMFV5, MFV5, nH/32 * nW/32);
   lire_image_pgm(cNomImgLueHF5, HF5, nH/32 * nW/32);

   allocation_tableau(BF6, OCTET, nH/64 * nW/64);
   allocation_tableau(MFH6, OCTET, nH/64 * nW/64);
   allocation_tableau(MFV6, OCTET, nH/64 * nW/64);
   allocation_tableau(HF6, OCTET, nH/64 * nW/64);

   lire_image_pgm(cNomImgLueBF6, BF6, nH/64 * nW/64);
   lire_image_pgm(cNomImgLueMFH6, MFH6, nH/64 * nW/64);
   lire_image_pgm(cNomImgLueMFV6, MFV6, nH/64 * nW/64);
   lire_image_pgm(cNomImgLueHF6, HF6, nH/64 * nW/64);

    if (N == 2) {
        for (int i = 0; i < nH/4; i++) {
            for (int j = 0; j < nW/4; j++) {
                BF[i*2*(nW/2)+j*2] = BF2[i*(nW/4)+j] + ((MFH2[i*(nW/4)+j]-128)/2) + ((MFV2[i*(nW/4)+j]-128)/2) + ((HF2[i*(nW/4)+j]-128)/4);
                BF[i*2*(nW/2)+(j*2+1)] = BF2[i*(nW/4)+j] + ((MFH2[i*(nW/4)+j]-128)/2) - ((MFV2[i*(nW/4)+j]-128)/2) - ((HF2[i*(nW/4)+j]-128)/4);
                BF[(i*2+1)*(nW/2)+j*2] = BF2[i*(nW/4)+j] - ((MFH2[i*(nW/4)+j]-128)/2) + ((MFV2[i*(nW/4)+j]-128)/2) - ((HF2[i*(nW/4)+j]-128)/4);
                BF[(i*2+1)*(nW/2)+(j*2+1)] = BF2[i*(nW/4)+j] - ((MFH2[i*(nW/4)+j]-128)/2) - ((MFV2[i*(nW/4)+j]-128)/2) + ((HF2[i*(nW/4)+j]-128)/4);
            }
        }
    }
    else if (N == 3) {
        for (int i = 0; i < nH/8; i++) {
            for (int j = 0; j < nW/8; j++) {
                BF[i*4*(nW/2)+j*4] = BF3[i*(nW/8)+j] + ((MFH3[i*(nW/8)+j]-128)/2) + ((MFV3[i*(nW/8)+j]-128)/2) + ((HF3[i*(nW/8)+j]-128)/4);
                BF[i*4*(nW/2)+(j*4+1)] = BF3[i*(nW/8)+j] + ((MFH3[i*(nW/8)+j]-128)/2) - ((MFV3[i*(nW/8)+j]-128)/2) - ((HF3[i*(nW/8)+j]-128)/4);
                BF[(i*4+1)*(nW/2)+j*4] = BF3[i*(nW/8)+j] - ((MFH3[i*(nW/8)+j]-128)/2) + ((MFV3[i*(nW/8)+j]-128)/2) - ((HF3[i*(nW/8)+j]-128)/4);
                BF[(i*4+1)*(nW/2)+(j*4+1)] = BF3[i*(nW/8)+j] - ((MFH3[i*(nW/8)+j]-128)/2) - ((MFV3[i*(nW/8)+j]-128)/2) + ((HF3[i*(nW/8)+j]-128)/4);
            }
        }

    }
    else if (N == 4) {
        for (int i = 0; i < nH/16; i++) {
            for (int j = 0; j < nW/16; j++) {
                BF[i*8*(nW/2)+j*8] = BF4[i*(nW/16)+j] + ((MFH4[i*(nW/16)+j]-128)/2) + ((MFV4[i*(nW/16)+j]-128)/2) + ((HF4[i*(nW/16)+j]-128)/4);
                BF[i*8*(nW/2)+(j*8+1)] = BF4[i*(nW/16)+j] + ((MFH4[i*(nW/16)+j]-128)/2) - ((MFV4[i*(nW/16)+j]-128)/2) - ((HF4[i*(nW/16)+j]-128)/4);
                BF[(i*8+1)*(nW/2)+j*8] = BF4[i*(nW/16)+j] - ((MFH4[i*(nW/16)+j]-128)/2) + ((MFV4[i*(nW/16)+j]-128)/2) - ((HF4[i*(nW/16)+j]-128)/4);
                BF[(i*8+1)*(nW/2)+(j*8+1)] = BF4[i*(nW/16)+j] - ((MFH4[i*(nW/16)+j]-128)/2) - ((MFV4[i*(nW/16)+j]-128)/2) + ((HF4[i*(nW/16)+j]-128)/4);
            }
        }
    }
    else if (N == 5) {
        for (int i = 0; i < nH/32; i++) {
            for (int j = 0; j < nW/32; j++) {
                BF[i*16*(nW/2)+j*16] = BF5[i*(nW/32)+j] + ((MFH5[i*(nW/32)+j]-128)/2) + ((MFV5[i*(nW/32)+j]-128)/2) + ((HF5[i*(nW/32)+j]-128)/4);
                BF[i*16*(nW/2)+(j*16+1)] = BF5[i*(nW/32)+j] + ((MFH5[i*(nW/32)+j]-128)/2) - ((MFV5[i*(nW/32)+j]-128)/2) - ((HF5[i*(nW/32)+j]-128)/4);
                BF[(i*16+1)*(nW/2)+j*16] = BF5[i*(nW/32)+j] - ((MFH5[i*(nW/32)+j]-128)/2) + ((MFV5[i*(nW/32)+j]-128)/2) - ((HF5[i*(nW/32)+j]-128)/4);
                BF[(i*16+1)*(nW/2)+(j*16+1)] = BF5[i*(nW/32)+j] - ((MFH5[i*(nW/32)+j]-128)/2) - ((MFV5[i*(nW/32)+j]-128)/2) + ((HF5[i*(nW/32)+j]-128)/4);
            }
        }
    }
    else if (N == 6) {
        for (int i = 0; i < nH/64; i++) {
            for (int j = 0; j < nW/64; j++) {
                BF[i*32*(nW/2)+j*32] = BF6[i*(nW/64)+j] + ((MFH6[i*(nW/64)+j]-128)/2) + ((MFV6[i*(nW/64)+j]-128)/2) + ((HF6[i*(nW/64)+j]-128)/4);
                BF[i*32*(nW/2)+(j*32+1)] = BF6[i*(nW/64)+j] + ((MFH6[i*(nW/64)+j]-128)/2) - ((MFV6[i*(nW/64)+j]-128)/2) - ((HF6[i*(nW/64)+j]-128)/4);
                BF[(i*32+1)*(nW/2)+j*32] = BF6[i*(nW/64)+j] - ((MFH6[i*(nW/64)+j]-128)/2) + ((MFV6[i*(nW/64)+j]-128)/2) - ((HF6[i*(nW/64)+j]-128)/4);
                BF[(i*32+1)*(nW/2)+(j*32+1)] = BF6[i*(nW/64)+j] - ((MFH6[i*(nW/64)+j]-128)/2) - ((MFV6[i*(nW/64)+j]-128)/2) + ((HF6[i*(nW/64)+j]-128)/4);
            }
        }
    }

    for (int i = 0; i < nH/2; i++) {
        for (int j = 0; j < nW/2; j++) {
            ImgOut[i*2*nW+j*2] = BF[i*(nW/2)+j] + ((MFH[i*(nW/2)+j]-128)/2) + ((MFV[i*(nW/2)+j]-128)/2) + ((HF[i*(nW/2)+j]-128)/4);
            ImgOut[i*2*nW+(j*2+1)] = BF[i*(nW/2)+j] + ((MFH[i*(nW/2)+j]-128)/2) - ((MFV[i*(nW/2)+j]-128)/2) - ((HF[i*(nW/2)+j]-128)/4);
            ImgOut[(i*2+1)*nW+j*2] = BF[i*(nW/2)+j] - ((MFH[i*(nW/2)+j]-128)/2) + ((MFV[i*(nW/2)+j]-128)/2) - ((HF[i*(nW/2)+j]-128)/4);
            ImgOut[(i*2+1)*nW+(j*2+1)] = BF[i*(nW/2)+j] - ((MFH[i*(nW/2)+j]-128)/2) - ((MFV[i*(nW/2)+j]-128)/2) + ((HF[i*(nW/2)+j]-128)/4);
        }
    }

   ecrire_image_pgm(cNomImgEcriteOut, ImgOut,  nH, nW);

   free(ImgIn); free(BF); free(MFH); free(MFV); free(HF); free(BF2); free(MFH2); free(MFV2); free(HF2); free(BF3); free(MFH3); free(MFV3); free(HF3); free(BF4); free(MFH4); free(MFV4); free(HF4); free(BF5); free(MFH5); free(MFV5); free(HF5); free(BF6); free(MFH6); free(MFV6); free(HF6); free(ImgOut);

   return 1;
}