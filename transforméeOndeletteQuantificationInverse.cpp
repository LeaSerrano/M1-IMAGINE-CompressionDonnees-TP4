#include <stdio.h>
#include "image_ppm.h"
#include <iostream>

int main(int argc, char* argv[])
{
  char cNomImgEcriteBF[250], cNomImgEcriteMFH[250], cNomImgEcriteMFV[250], cNomImgEcriteHF[250], cNomImgLueQBF[250], cNomImgLueQMFH[250], cNomImgLueQMFV[250], cNomImgLueQHF[250], cNomImgEcriteOut[250];
  int nH, nW, nTaille, coeff1, coeff2;
  
  if (argc != 12) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLueQBF);
   sscanf (argv[2],"%s",cNomImgLueQMFH);
   sscanf (argv[3],"%s",cNomImgLueQMFV);
   sscanf (argv[4],"%s",cNomImgLueQHF);
   sscanf (argv[5],"%s",cNomImgEcriteBF);
   sscanf (argv[6],"%s",cNomImgEcriteMFH);
   sscanf (argv[7],"%s",cNomImgEcriteMFV);
   sscanf (argv[8],"%s",cNomImgEcriteHF);
   sscanf (argv[9],"%s",cNomImgEcriteOut);
   sscanf (argv[10],"%i",&coeff1);
   sscanf (argv[11],"%i",&coeff2);

   OCTET *BF, *MFH, *MFV, *HF, *QBF, *QMFH, *QMFV, *QHF, *ImgOut;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLueQBF, &nH, &nW);
   nTaille = nH * nW;

   int nTailleNormale = nTaille*4;

   allocation_tableau(QBF, OCTET, nTaille);
   allocation_tableau(QMFH, OCTET, nTaille);
   allocation_tableau(QMFV, OCTET, nTaille);
   allocation_tableau(QHF, OCTET, nTaille);

   allocation_tableau(ImgOut, OCTET, nTailleNormale);

   lire_image_pgm(cNomImgLueQBF, QBF, nH * nW);
   lire_image_pgm(cNomImgLueQMFH, QMFH, nH * nW);
   lire_image_pgm(cNomImgLueQMFV, QMFV, nH * nW);
   lire_image_pgm(cNomImgLueQHF, QHF, nH * nW);

   allocation_tableau(BF, OCTET, nTaille);
   allocation_tableau(MFH, OCTET, nTaille);
   allocation_tableau(MFV, OCTET, nTaille);
   allocation_tableau(HF, OCTET, nTaille);

   for (int i = 0; i < nH; i++) {
        for (int j = 0; j < nW; j++) {
            BF[i*nW+j] = QBF[i*nW+j];
            MFH[i*nW+j] = QMFH[i*nW+j]*coeff1;
            MFV[i*nW+j] = QMFV[i*nW+j]*coeff1;
            HF[i*nW+j] = QHF[i*nW+j]*coeff2;
        }
   }

    for (int i = 0; i < nH*2; i++) {
        for (int j = 0; j < nW*2; j++) {
            if (i < nH && j < nW) {
                ImgOut[i*nW*2+j] = BF[i*nW+j];
            }
            else if (i < nH && j >= nW) {
                ImgOut[i*nW*2+j] = MFH[i*nW+j-nW];
            }
            else if (i >= nH && j < nW) {
                ImgOut[i*nW*2+j] = MFV[(i-nH)*nW+j];
            }
            else if (i >= nH && j >= nW) {
                ImgOut[i*nW*2+j] = HF[(i-nH)*nW+j];
            }
        }
    }

   ecrire_image_pgm(cNomImgEcriteBF, BF,  nH, nW);
   ecrire_image_pgm(cNomImgEcriteMFH, MFH,  nH, nW);
   ecrire_image_pgm(cNomImgEcriteMFV, MFV,  nH, nW);
   ecrire_image_pgm(cNomImgEcriteHF, HF,  nH, nW);

   ecrire_image_pgm(cNomImgEcriteOut, ImgOut,  nH*2, nW*2);

   free(BF); free(MFH); free(MFV); free(HF); free(ImgOut); free(QBF); free(QMFH); free(QMFV); free(QHF);

   return 1;
}