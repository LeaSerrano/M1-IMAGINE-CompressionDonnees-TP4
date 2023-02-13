#include <stdio.h>
#include "image_ppm.h"
#include <iostream>

int main(int argc, char* argv[])
{
  char cNomImgEcriteQBF[250], cNomImgEcriteQMFH[250], cNomImgEcriteQMFV[250], cNomImgEcriteQHF[250], cNomImgLueBF[250], cNomImgLueMFH[250], cNomImgLueMFV[250], cNomImgLueHF[250], cNomImgEcriteOut[250];
  int nH, nW, nTaille;
  
  if (argc != 10) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLueBF);
   sscanf (argv[2],"%s",cNomImgLueMFH);
   sscanf (argv[3],"%s",cNomImgLueMFV);
   sscanf (argv[4],"%s",cNomImgLueHF);
   sscanf (argv[5],"%s",cNomImgEcriteQBF);
   sscanf (argv[6],"%s",cNomImgEcriteQMFH);
   sscanf (argv[7],"%s",cNomImgEcriteQMFV);
   sscanf (argv[8],"%s",cNomImgEcriteQHF);
   sscanf (argv[9],"%s",cNomImgEcriteOut);

   OCTET *BF, *MFH, *MFV, *HF, *QBF, *QMFH, *QMFV, *QHF, *ImgOut;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLueBF, &nH, &nW);
   nTaille = nH * nW;

   int nTailleNormale = nTaille*4;

   allocation_tableau(BF, OCTET, nTaille);
   allocation_tableau(MFH, OCTET, nTaille);
   allocation_tableau(MFV, OCTET, nTaille);
   allocation_tableau(HF, OCTET, nTaille);

   allocation_tableau(ImgOut, OCTET, nTailleNormale);

   lire_image_pgm(cNomImgLueBF, BF, nH * nW);
   lire_image_pgm(cNomImgLueMFH, MFH, nH * nW);
   lire_image_pgm(cNomImgLueMFV, MFV, nH * nW);
   lire_image_pgm(cNomImgLueHF, HF, nH * nW);

   allocation_tableau(QBF, OCTET, nTaille);
   allocation_tableau(QMFH, OCTET, nTaille);
   allocation_tableau(QMFV, OCTET, nTaille);
   allocation_tableau(QHF, OCTET, nTaille);

   for (int i = 0; i < nH; i++) {
        for (int j = 0; j < nW; j++) {
            QBF[i*nW+j] = round(BF[i*nW+j]);
            QMFH[i*nW+j] = MFH[i*nW+j]/4;
            QMFV[i*nW+j] = MFV[i*nW+j]/4;
            QHF[i*nW+j] = HF[i*nW+j]/16;
        }
   }

    for (int i = 0; i < nH*2; i++) {
        for (int j = 0; j < nW*2; j++) {
            if (i < nH && j < nW) {
                ImgOut[i*nW*2+j] = QBF[i*nW+j];
            }
            else if (i < nH && j >= nW) {
                ImgOut[i*nW*2+j] = QMFH[i*nW+j-nW];
            }
            else if (i >= nH && j < nW) {
                ImgOut[i*nW*2+j] = QMFV[(i-nH)*nW+j];
            }
            else if (i >= nH && j >= nW) {
                ImgOut[i*nW*2+j] = QHF[(i-nH)*nW+j];
            }
        }
    }

   ecrire_image_pgm(cNomImgEcriteQBF, QBF,  nH, nW);
   ecrire_image_pgm(cNomImgEcriteQMFH, QMFH,  nH, nW);
   ecrire_image_pgm(cNomImgEcriteQMFV, QMFV,  nH, nW);
   ecrire_image_pgm(cNomImgEcriteQHF, QHF,  nH, nW);

   ecrire_image_pgm(cNomImgEcriteOut, ImgOut,  nH*2, nW*2);

   free(BF); free(MFH); free(MFV); free(HF); free(ImgOut); free(QBF); free(QMFH); free(QMFV); free(QHF);

   return 1;
}