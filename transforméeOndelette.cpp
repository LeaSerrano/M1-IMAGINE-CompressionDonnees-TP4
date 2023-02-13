#include <stdio.h>
#include "image_ppm.h"
#include <iostream>

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcriteBF[250], cNomImgEcriteMFH[250], cNomImgEcriteMFV[250], cNomImgEcriteHF[250], cNomImgEcriteOut[250];
  int nH, nW, nTaille;
  
  if (argc != 7) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcriteBF);
   sscanf (argv[3],"%s",cNomImgEcriteMFH);
   sscanf (argv[4],"%s",cNomImgEcriteMFV);
   sscanf (argv[5],"%s",cNomImgEcriteHF);
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

    for (int i = 0; i < nH/2; i++) {
        for (int j = 0; j < nW/2; j++) {
            BF[i*(nW/2)+j] = (ImgIn[2*i*nW+2*j] + ImgIn[(2*i+1)*nW+2*j] + ImgIn[2*i*nW+(2*j+1)] + ImgIn[(2*i+1)*nW+(j*2+1)])/4;
        }
    }

    for (int i = 0; i < nH/2; i++) {
        for (int j = 0; j < nW/2; j++) {
            MFH[i*(nW/2)+j] = (ImgIn[2*i*nW+2*j] + ImgIn[(2*i+1)*nW+2*j] - ImgIn[2*i*nW+(2*j+1)] - ImgIn[(2*i+1)*nW+(2*j+1)])/2 + 128;
        }
    }

    for (int i = 0; i < nH/2; i++) {
        for (int j = 0; j < nW/2; j++) {
            MFV[i*(nW/2)+j] = (ImgIn[2*i*nW+2*j] - ImgIn[(2*i+1)*nW+2*j] + ImgIn[2*i*nW+(2*j+1)] - ImgIn[(2*i+1)*nW+(2*j+1)])/2 + 128;
        }
    }

    for (int i = 0; i < nH/2; i++) {
        for (int j = 0; j < nW/2; j++) {
            HF[i*(nW/2)+j] = ImgIn[2*i*nW+2*j] - ImgIn[(2*i+1)*nW+2*j] - ImgIn[2*i*nW+(2*j+1)] + ImgIn[(2*i+1)*nW+(2*j+1)] + 128;
        }
    }

    for (int i = 0; i < nH; i++) {
        for (int j = 0; j < nW; j++) {
            if (i < nH/2 && j < nW/2) {
                ImgOut[i*nW+j] = BF[i*(nW/2)+j];
            }
            else if (i < nH/2 && j >= nW/2) {
                ImgOut[i*nW+j] = MFH[i*(nW/2)+j-nW/2];
            }
            else if (i >= nH/2 && j < nW/2) {
                ImgOut[i*nW+j] = MFV[(i-nH/2)*(nW/2)+j];
            }
            else if (i >= nH/2 && j >= nW/2) {
                ImgOut[i*nW+j] = HF[(i-nH/2)*(nW/2)+j-nW/2];
            }
        }
    }

   ecrire_image_pgm(cNomImgEcriteBF, BF,  nH/2, nW/2);
   ecrire_image_pgm(cNomImgEcriteMFH, MFH,  nH/2, nW/2);
   ecrire_image_pgm(cNomImgEcriteMFV, MFV,  nH/2, nW/2);
   ecrire_image_pgm(cNomImgEcriteHF, HF,  nH/2, nW/2);

   ecrire_image_pgm(cNomImgEcriteOut, ImgOut,  nH, nW);

   free(ImgIn); free(BF); free(MFH); free(MFV); free(HF); free(ImgOut);

   return 1;
}