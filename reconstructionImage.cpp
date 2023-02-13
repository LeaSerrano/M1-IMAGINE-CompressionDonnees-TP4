#include <stdio.h>
#include "image_ppm.h"
#include <iostream>

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgLueBF[250], cNomImgLueMFH[250], cNomImgLueMFV[250], cNomImgLueHF[250], cNomImgEcriteOut[250];
  int nH, nW, nTaille;
  
  if (argc != 7) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgLueBF);
   sscanf (argv[3],"%s",cNomImgLueMFH);
   sscanf (argv[4],"%s",cNomImgLueMFV);
   sscanf (argv[5],"%s",cNomImgLueHF);
   sscanf (argv[6],"%s",cNomImgEcriteOut);

   OCTET *ImgIn, *BF, *MFH, *MFV, *HF, *ImgOut;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille);
   allocation_tableau(ImgOut, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);

   allocation_tableau(BF, OCTET, nTaille/4);
   allocation_tableau(MFH, OCTET, nTaille/4);
   allocation_tableau(MFV, OCTET, nTaille/4);
   allocation_tableau(HF, OCTET, nTaille/4);

   lire_image_pgm(cNomImgLueBF, BF, nTaille/4);
   lire_image_pgm(cNomImgLueMFH, MFH, nTaille/4);
   lire_image_pgm(cNomImgLueMFV, MFV, nTaille/4);
   lire_image_pgm(cNomImgLueHF, HF, nTaille/4);

    for (int i = 0; i < nH/2; i++) {
        for (int j = 0; j < nW/2; j++) {
            ImgOut[i*2*nW+j*2] = BF[i*(nW/2)+j] + ((MFH[i*(nW/2)+j]-128)/2) + ((MFV[i*(nW/2)+j]-128)/2) + ((HF[i*(nW/2)+j]-128)/4);
            ImgOut[i*2*nW+(j*2+1)] = BF[i*(nW/2)+j] + ((MFH[i*(nW/2)+j]-128)/2) - ((MFV[i*(nW/2)+j]-128)/2) - ((HF[i*(nW/2)+j]-128)/4);
            ImgOut[(i*2+1)*nW+j*2] = BF[i*(nW/2)+j] - ((MFH[i*(nW/2)+j]-128)/2) + ((MFV[i*(nW/2)+j]-128)/2) - ((HF[i*(nW/2)+j]-128)/4);
            ImgOut[(i*2+1)*nW+(j*2+1)] = BF[i*(nW/2)+j] - ((MFH[i*(nW/2)+j]-128)/2) - ((MFV[i*(nW/2)+j]-128)/2) + ((HF[i*(nW/2)+j]-128)/4);
      }
    }

   ecrire_image_pgm(cNomImgEcriteOut, ImgOut,  nH, nW);

   free(ImgIn); free(BF); free(MFH); free(MFV); free(HF); free(ImgOut);

   return 1;
}