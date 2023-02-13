#include <stdio.h>
#include "image_ppm.h"
#include <iostream>


int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcriteOut[250],
  
  cNomImgEcriteBF1[250], cNomImgEcriteMFH1[250],
   cNomImgEcriteMFV1[250], cNomImgEcriteHF1[250], 

   cNomImgEcriteBF2[250], cNomImgEcriteMFH2[250], 
   cNomImgEcriteMFV2[250], cNomImgEcriteHF2[250], 
   
   cNomImgEcriteBF3[250], cNomImgEcriteMFH3[250], 
   cNomImgEcriteMFV3[250], cNomImgEcriteHF3[250], 
   
   cNomImgEcriteBF4[250], cNomImgEcriteMFH4[250], 
   cNomImgEcriteMFV4[250], cNomImgEcriteHF4[250],
   
   cNomImgEcriteBF5[250], cNomImgEcriteMFH5[250], 
   cNomImgEcriteMFV5[250], cNomImgEcriteHF5[250], 
   
   cNomImgEcriteBF6[250], cNomImgEcriteMFH6[250], 
   cNomImgEcriteMFV6[250], cNomImgEcriteHF6[250];;
  int nH, nW, nTaille, N, coeff1, coeff2;
  
  if (argc != 30) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%i",&N);
   sscanf (argv[3],"%s",cNomImgEcriteOut);

   sscanf (argv[4],"%s",cNomImgEcriteBF1);
   sscanf (argv[5],"%s",cNomImgEcriteMFH1);
   sscanf (argv[6],"%s",cNomImgEcriteMFV1);
   sscanf (argv[7],"%s",cNomImgEcriteHF1);

   sscanf (argv[8],"%s",cNomImgEcriteBF2);
   sscanf (argv[9],"%s",cNomImgEcriteMFH2);
   sscanf (argv[10],"%s",cNomImgEcriteMFV2);
   sscanf (argv[11],"%s",cNomImgEcriteHF2);

   sscanf (argv[12],"%s",cNomImgEcriteBF3);
   sscanf (argv[13],"%s",cNomImgEcriteMFH3);
   sscanf (argv[14],"%s",cNomImgEcriteMFV3);
   sscanf (argv[15],"%s",cNomImgEcriteHF3);

   sscanf (argv[16],"%s",cNomImgEcriteBF4);
   sscanf (argv[17],"%s",cNomImgEcriteMFH4);
   sscanf (argv[18],"%s",cNomImgEcriteMFV4);
   sscanf (argv[19],"%s",cNomImgEcriteHF4);

   sscanf (argv[20],"%s",cNomImgEcriteBF5);
   sscanf (argv[21],"%s",cNomImgEcriteMFH5);
   sscanf (argv[22],"%s",cNomImgEcriteMFV5);
   sscanf (argv[23],"%s",cNomImgEcriteHF5);

   sscanf (argv[24],"%s",cNomImgEcriteBF6);
   sscanf (argv[25],"%s",cNomImgEcriteMFH6);
   sscanf (argv[26],"%s",cNomImgEcriteMFV6);
   sscanf (argv[27],"%s",cNomImgEcriteHF6);

   sscanf (argv[28],"%i",&coeff1);
   sscanf (argv[29],"%i",&coeff2);

   OCTET *ImgIn, *BF, *MFH, *MFV, *HF, *ImgOut, *BF2, *MFH2, *MFV2, *HF2, *BF3, 
   *MFH3, *MFV3, *HF3, *BF4, *MFH4, *MFV4, *HF4, *BF5, *MFH5, *MFV5, *HF5,
   *BF6, *MFH6, *MFV6, *HF6;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille);
   allocation_tableau(ImgOut, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);

   allocation_tableau(BF, OCTET, nTaille/4);
   allocation_tableau(MFH, OCTET, nTaille/4);
   allocation_tableau(MFV, OCTET, nTaille/4);
   allocation_tableau(HF, OCTET, nTaille/4);

   allocation_tableau(BF2, OCTET, nTaille/8);
   allocation_tableau(MFH2, OCTET, nTaille/8);
   allocation_tableau(MFV2, OCTET, nTaille/8);
   allocation_tableau(HF2, OCTET, nTaille/8);

   allocation_tableau(BF3, OCTET, nTaille/16);
   allocation_tableau(MFH3, OCTET, nTaille/16);
   allocation_tableau(MFV3, OCTET, nTaille/16);
   allocation_tableau(HF3, OCTET, nTaille/16);

   allocation_tableau(BF4, OCTET, nTaille/32);
   allocation_tableau(MFH4, OCTET, nTaille/32);
   allocation_tableau(MFV4, OCTET, nTaille/32);
   allocation_tableau(HF4, OCTET, nTaille/32);

   allocation_tableau(BF5, OCTET, nTaille/64);
   allocation_tableau(MFH5, OCTET, nTaille/64);
   allocation_tableau(MFV5, OCTET, nTaille/64);
   allocation_tableau(HF5, OCTET, nTaille/64);

   allocation_tableau(BF6, OCTET, nTaille/128);
   allocation_tableau(MFH6, OCTET, nTaille/128);
   allocation_tableau(MFV6, OCTET, nTaille/128);
   allocation_tableau(HF6, OCTET, nTaille/128);

    for (int i = 0; i < nH/2; i++) {
        for (int j = 0; j < nW/2; j++) {
            BF[i*(nW/2)+j] = (ImgIn[2*i*nW+(2*j)] + ImgIn[(2*i+1)*nW+(2*j)] + ImgIn[2*i*nW+(j*2)+1] + ImgIn[(i*2+1)*nW+(j*2)+1])/4;

            MFH[i*(nW/2)+j] = ((ImgIn[2*i*nW+2*j] + ImgIn[(2*i+1)*nW+2*j] - ImgIn[2*i*nW+2*j+1] - ImgIn[(2*i+1)*nW+2*j+1])/2 + 128)/coeff1;
     
            MFV[i*(nW/2)+j] = ((ImgIn[2*i*nW+2*j] - ImgIn[(2*i+1)*nW+2*j] + ImgIn[2*i*nW+2*j+1] - ImgIn[(2*i+1)*nW+2*j+1])/2 + 128)/coeff1;
      
            HF[i*(nW/2)+j] = (ImgIn[2*i*nW+2*j] - ImgIn[(2*i+1)*nW+2*j] - ImgIn[2*i*nW+2*j+1] + ImgIn[(2*i+1)*nW+2*j+1] + 128)/coeff2;
        }
    }

    for (int i = 0; i < nH/4; i++) {
        for (int j = 0; j < nW/4; j++) {
            BF2[i*(nW/4)+j] = (BF[2*i*(nW/2)+2*j] + BF[(2*i+1)*(nW/2)+2*j] + BF[2*i*(nW/2)+2*j+1] + BF[(2*i+1)*(nW/2)+2*j+1])/4;
        
            MFH2[i*(nW/4)+j] = ((BF[2*i*(nW/2)+2*j] + BF[(2*i+1)*(nW/2)+2*j] - BF[2*i*(nW/2)+2*j+1] - BF[(2*i+1)*(nW/2)+2*j+1])/2 + 128)/(coeff1-coeff1/6);
     
            MFV2[i*(nW/4)+j] = ((BF[2*i*(nW/2)+2*j] - BF[(2*i+1)*(nW/2)+2*j] + BF[2*i*(nW/2)+2*j+1] - BF[(2*i+1)*(nW/2)+2*j+1])/2 + 128)/(coeff1-coeff1/6);
      
            HF2[i*(nW/4)+j] = (BF[2*i*(nW/2)+2*j] - BF[(2*i+1)*(nW/2)+2*j] - BF[2*i*(nW/2)+2*j+1] + BF[(2*i+1)*(nW/2)+2*j+1] + 128)/(coeff2-coeff2/6);
        }
    }

    for (int i = 0; i < nH/8; i++) {
        for (int j = 0; j < nW/8; j++) {
            BF3[i*(nW/8)+j] = (BF2[2*i*(nW/4)+2*j] + BF2[(2*i+1)*(nW/4)+2*j] + BF2[2*i*(nW/4)+2*j+1] + BF2[(2*i+1)*(nW/4)+2*j+1])/4;
        
            MFH3[i*(nW/8)+j] = ((BF2[2*i*(nW/4)+2*j] + BF2[(2*i+1)*(nW/4)+2*j] - BF2[2*i*(nW/4)+2*j+1] - BF2[(2*i+1)*(nW/4)+2*j+1])/2 + 128)/(coeff1-2*coeff1/6);
     
            MFV3[i*(nW/8)+j] = ((BF2[2*i*(nW/4)+2*j] - BF2[(2*i+1)*(nW/4)+2*j] + BF2[2*i*(nW/4)+2*j+1] - BF2[(2*i+1)*(nW/4)+2*j+1])/2 + 128)/(coeff1-2*coeff1/6);
      
            HF3[i*(nW/8)+j] = (BF2[2*i*(nW/4)+2*j] - BF2[(2*i+1)*(nW/4)+2*j] - BF2[2*i*(nW/4)+2*j+1] + BF2[(2*i+1)*(nW/4)+2*j+1] + 128)/(coeff2-2*coeff2/6);
        }
    }

    for (int i = 0; i < nH/16; i++) {
        for (int j = 0; j < nW/16; j++) {
            BF4[i*(nW/16)+j] = (BF3[2*i*(nW/8)+2*j] + BF3[(2*i+1)*(nW/8)+2*j] + BF3[2*i*(nW/8)+2*j+1] + BF3[(2*i+1)*(nW/8)+2*j+1])/4;
        
            MFH4[i*(nW/16)+j] = ((BF3[2*i*(nW/8)+2*j] + BF3[(2*i+1)*(nW/8)+2*j] - BF3[2*i*(nW/8)+2*j+1] - BF3[(2*i+1)*(nW/8)+2*j+1])/2 + 128)/(coeff1-3*coeff1/6);
     
            MFV4[i*(nW/16)+j] = ((BF3[2*i*(nW/8)+2*j] - BF3[(2*i+1)*(nW/8)+2*j] + BF3[2*i*(nW/8)+2*j+1] - BF3[(2*i+1)*(nW/8)+2*j+1])/2 + 128)/(coeff1-3*coeff1/6);
      
            HF4[i*(nW/16)+j] = (BF3[2*i*(nW/8)+2*j] - BF3[(2*i+1)*(nW/8)+2*j] - BF3[2*i*(nW/8)+2*j+1] + BF3[(2*i+1)*(nW/8)+2*j+1] + 128)/(coeff2-3*coeff2/6);
        }
    }

    for (int i = 0; i < nH/32; i++) {
        for (int j = 0; j < nW/32; j++) {
            BF5[i*(nW/32)+j] = (BF4[2*i*(nW/16)+2*j] + BF4[(2*i+1)*(nW/16)+2*j] + BF4[2*i*(nW/16)+2*j+1] + BF4[(2*i+1)*(nW/16)+2*j+1])/4;
        
            MFH5[i*(nW/32)+j] = ((BF4[2*i*(nW/16)+2*j] + BF4[(2*i+1)*(nW/16)+2*j] - BF4[2*i*(nW/16)+2*j+1] - BF4[(2*i+1)*(nW/16)+2*j+1])/2 + 128)/(coeff1-4*coeff1/6);
     
            MFV5[i*(nW/32)+j] = ((BF4[2*i*(nW/16)+2*j] - BF4[(2*i+1)*(nW/16)+2*j] + BF4[2*i*(nW/16)+2*j+1] - BF4[(2*i+1)*(nW/16)+2*j+1])/2 + 128)/(coeff1-4*coeff1/6);
      
            HF5[i*(nW/32)+j] = (BF4[2*i*(nW/16)+2*j] - BF4[(2*i+1)*(nW/16)+2*j] - BF4[2*i*(nW/16)+2*j+1] + BF4[(2*i+1)*(nW/16)+2*j+1] + 128)/(coeff2-4*coeff2/6);
        }
    }

    for (int i = 0; i < nH/64; i++) {
        for (int j = 0; j < nW/64; j++) {
            BF6[i*(nW/64)+j] = (BF5[2*i*(nW/32)+2*j] + BF5[(2*i+1)*(nW/32)+2*j] + BF5[2*i*(nW/32)+2*j+1] + BF5[(2*i+1)*(nW/32)+2*j+1])/4;
        
            MFH6[i*(nW/64)+j] = ((BF5[2*i*(nW/32)+2*j] + BF5[(2*i+1)*(nW/32)+2*j] - BF5[2*i*(nW/32)+2*j+1] - BF5[(2*i+1)*(nW/32)+2*j+1])/2 + 128)/(coeff1-5*coeff1/6);
     
            MFV6[i*(nW/64)+j] = ((BF5[2*i*(nW/32)+2*j] - BF5[(2*i+1)*(nW/32)+2*j] + BF5[2*i*(nW/32)+2*j+1] - BF5[(2*i+1)*(nW/32)+2*j+1])/2 + 128)/(coeff1-5*coeff1/6);
      
            HF6[i*(nW/64)+j] = (BF5[2*i*(nW/32)+2*j] - BF5[(2*i+1)*(nW/32)+2*j] - BF5[2*i*(nW/32)+2*j+1] + BF5[(2*i+1)*(nW/32)+2*j+1] + 128)/(coeff2-5*coeff2/6);
        }
    }

    for (int i = 0; i < nH; i++) {
        for (int j = 0; j < nW; j++) {
            if (i < nH/2 && j < nW/2) {
                if (N == 1) {
                    ImgOut[i*nW+j] = BF[i*(nW/2)+j];
                }
                else if (N == 2) {
                    if (i < nH/4 && j < nW/4) {
                        ImgOut[i*nW+j] = BF2[i*(nW/4)+j];
                    }
                    else if (i < nH/4 && j >= nW/4) {
                        ImgOut[i*nW+j] = MFH2[i*(nW/4)+j-nW/4];
                    }
                    else if (i >= nH/4 && j < nW/4) {
                        ImgOut[i*nW+j] = MFV2[(i-nH/4)*(nW/4)+j];
                    }
                    else if (i >= nH/4 && j >= nW/4) {
                        ImgOut[i*nW+j] = HF2[(i-nH/4)*(nW/4)+j-nW/4];
                    }
                }
                else if (N == 3) {

                    if (i < nH/4 && j >= nW/4) {
                        ImgOut[i*nW+j] = MFH2[i*(nW/4)+j-nW/4];
                    }
                    else if (i >= nH/4 && j < nW/4) {
                        ImgOut[i*nW+j] = MFV2[(i-nH/4)*(nW/4)+j];
                    }
                    else if (i >= nH/4 && j >= nW/4) {
                        ImgOut[i*nW+j] = HF2[(i-nH/4)*(nW/4)+j-nW/4];
                    }


                    else if (i < nH/8 && j < nW/8) {
                        ImgOut[i*nW+j] = BF3[i*(nW/8)+j];
                    }
                    else if (i < nH/8 && j >= nW/8) {
                        ImgOut[i*nW+j] = MFH3[i*(nW/8)+j-nW/8];
                    }
                    else if (i >= nH/8 && j < nW/8) {
                        ImgOut[i*nW+j] = MFV3[(i-nH/8)*(nW/8)+j];
                    }
                    else if (i >= nH/8 && j >= nW/8) {
                        ImgOut[i*nW+j] = HF3[(i-nH/8)*(nW/8)+j-nW/8];
                    }
                }
                else if (N == 4) {

                   if (i < nH/4 && j >= nW/4) {
                        ImgOut[i*nW+j] = MFH2[i*(nW/4)+j-nW/4];
                    }
                    else if (i >= nH/4 && j < nW/4) {
                        ImgOut[i*nW+j] = MFV2[(i-nH/4)*(nW/4)+j];
                    }
                    else if (i >= nH/4 && j >= nW/4) {
                        ImgOut[i*nW+j] = HF2[(i-nH/4)*(nW/4)+j-nW/4];
                    }


                    else if (i < nH/8 && j >= nW/8) {
                        ImgOut[i*nW+j] = MFH3[i*(nW/8)+j-nW/8];
                    }
                    else if (i >= nH/8 && j < nW/8) {
                        ImgOut[i*nW+j] = MFV3[(i-nH/8)*(nW/8)+j];
                    }
                    else if (i >= nH/8 && j >= nW/8) {
                        ImgOut[i*nW+j] = HF3[(i-nH/8)*(nW/8)+j-nW/8];
                    }


                    else if (i < nH/16 && j < nW/16) {
                        ImgOut[i*nW+j] = BF4[i*(nW/16)+j];
                    }
                    else if (i < nH/16 && j >= nW/16) {
                        ImgOut[i*nW+j] = MFH4[i*(nW/16)+j-nW/16];
                    }
                    else if (i >= nH/16 && j < nW/16) {
                        ImgOut[i*nW+j] = MFV4[(i-nH/16)*(nW/16)+j];
                    }
                    else if (i >= nH/16 && j >= nW/16) {
                        ImgOut[i*nW+j] = HF4[(i-nH/16)*(nW/16)+j-nW/16];
                    }
                }
                else if (N == 5) {

                    if (i < nH/4 && j >= nW/4) {
                        ImgOut[i*nW+j] = MFH2[i*(nW/4)+j-nW/4];
                    }
                    else if (i >= nH/4 && j < nW/4) {
                        ImgOut[i*nW+j] = MFV2[(i-nH/4)*(nW/4)+j];
                    }
                    else if (i >= nH/4 && j >= nW/4) {
                        ImgOut[i*nW+j] = HF2[(i-nH/4)*(nW/4)+j-nW/4];
                    }


                    else if (i < nH/8 && j >= nW/8) {
                        ImgOut[i*nW+j] = MFH3[i*(nW/8)+j-nW/8];
                    }
                    else if (i >= nH/8 && j < nW/8) {
                        ImgOut[i*nW+j] = MFV3[(i-nH/8)*(nW/8)+j];
                    }
                    else if (i >= nH/8 && j >= nW/8) {
                        ImgOut[i*nW+j] = HF3[(i-nH/8)*(nW/8)+j-nW/8];
                    }


                    else if (i < nH/16 && j >= nW/16) {
                        ImgOut[i*nW+j] = MFH4[i*(nW/16)+j-nW/16];
                    }
                    else if (i >= nH/16 && j < nW/16) {
                        ImgOut[i*nW+j] = MFV4[(i-nH/16)*(nW/16)+j];
                    }
                    else if (i >= nH/16 && j >= nW/16) {
                        ImgOut[i*nW+j] = HF4[(i-nH/16)*(nW/16)+j-nW/16];
                    }
                    

                    else if (i < nH/32 && j < nW/32) {
                        ImgOut[i*nW+j] = BF5[i*(nW/32)+j];
                    }
                    else if (i < nH/32 && j >= nW/32) {
                        ImgOut[i*nW+j] = MFH5[i*(nW/32)+j-nW/32];
                    }
                    else if (i >= nH/32 && j < nW/32) {
                        ImgOut[i*nW+j] = MFV5[(i-nH/32)*(nW/32)+j];
                    }
                    else if (i >= nH/32 && j >= nW/32) {
                        ImgOut[i*nW+j] = HF5[(i-nH/32)*(nW/32)+j-nW/32];
                    }
                }
                else if (N == 6) {

                    if (i < nH/4 && j >= nW/4) {
                        ImgOut[i*nW+j] = MFH2[i*(nW/4)+j-nW/4];
                    }
                    else if (i >= nH/4 && j < nW/4) {
                        ImgOut[i*nW+j] = MFV2[(i-nH/4)*(nW/4)+j];
                    }
                    else if (i >= nH/4 && j >= nW/4) {
                        ImgOut[i*nW+j] = HF2[(i-nH/4)*(nW/4)+j-nW/4];
                    }


                    else if (i < nH/8 && j >= nW/8) {
                        ImgOut[i*nW+j] = MFH3[i*(nW/8)+j-nW/8];
                    }
                    else if (i >= nH/8 && j < nW/8) {
                        ImgOut[i*nW+j] = MFV3[(i-nH/8)*(nW/8)+j];
                    }
                    else if (i >= nH/8 && j >= nW/8) {
                        ImgOut[i*nW+j] = HF3[(i-nH/8)*(nW/8)+j-nW/8];
                    }


                    else if (i < nH/16 && j >= nW/16) {
                        ImgOut[i*nW+j] = MFH4[i*(nW/16)+j-nW/16];
                    }
                    else if (i >= nH/16 && j < nW/16) {
                        ImgOut[i*nW+j] = MFV4[(i-nH/16)*(nW/16)+j];
                    }
                    else if (i >= nH/16 && j >= nW/16) {
                        ImgOut[i*nW+j] = HF4[(i-nH/16)*(nW/16)+j-nW/16];
                    }
                    

                    else if (i < nH/32 && j >= nW/32) {
                        ImgOut[i*nW+j] = MFH5[i*(nW/32)+j-nW/32];
                    }
                    else if (i >= nH/32 && j < nW/32) {
                        ImgOut[i*nW+j] = MFV5[(i-nH/32)*(nW/32)+j];
                    }
                    else if (i >= nH/32 && j >= nW/32) {
                        ImgOut[i*nW+j] = HF5[(i-nH/32)*(nW/32)+j-nW/32];
                    }


                    else if (i < nH/64 && j < nW/64) {
                        ImgOut[i*nW+j] = BF6[i*(nW/64)+j];
                    }
                    else if (i < nH/64 && j >= nW/64) {
                        ImgOut[i*nW+j] = MFH6[i*(nW/64)+j-nW/64];
                    }
                    else if (i >= nH/64 && j < nW/64) {
                        ImgOut[i*nW+j] = MFV6[(i-nH/64)*(nW/64)+j];
                    }
                    else if (i >= nH/64 && j >= nW/64) {
                        ImgOut[i*nW+j] = HF6[(i-nH/64)*(nW/64)+j-nW/64];
                    }
                }
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

    ecrire_image_pgm(cNomImgEcriteBF1, BF,  nH/2, nW/2);
   ecrire_image_pgm(cNomImgEcriteMFH1, MFH,  nH/2, nW/2);
   ecrire_image_pgm(cNomImgEcriteMFV1, MFV,  nH/2, nW/2);
   ecrire_image_pgm(cNomImgEcriteHF1, HF,  nH/2, nW/2);

   ecrire_image_pgm(cNomImgEcriteBF2, BF2,  nH/4, nW/4);
   ecrire_image_pgm(cNomImgEcriteMFH2, MFH2,  nH/4, nW/4);
   ecrire_image_pgm(cNomImgEcriteMFV2, MFV2,  nH/4, nW/4);
   ecrire_image_pgm(cNomImgEcriteHF2, HF2,  nH/4, nW/4);

   ecrire_image_pgm(cNomImgEcriteBF3, BF3,  nH/8, nW/8);
   ecrire_image_pgm(cNomImgEcriteMFH3, MFH3,  nH/8, nW/8);
   ecrire_image_pgm(cNomImgEcriteMFV3, MFV3,  nH/8, nW/8);
   ecrire_image_pgm(cNomImgEcriteHF3, HF3,  nH/8, nW/8);

   ecrire_image_pgm(cNomImgEcriteBF4, BF4,  nH/16, nW/16);
   ecrire_image_pgm(cNomImgEcriteMFH4, MFH4,  nH/16, nW/16);
   ecrire_image_pgm(cNomImgEcriteMFV4, MFV4,  nH/16, nW/16);
   ecrire_image_pgm(cNomImgEcriteHF4, HF4,  nH/16, nW/16);

   ecrire_image_pgm(cNomImgEcriteBF5, BF5,  nH/32, nW/32);
   ecrire_image_pgm(cNomImgEcriteMFH5, MFH5,  nH/32, nW/32);
   ecrire_image_pgm(cNomImgEcriteMFV5, MFV5,  nH/32, nW/32);
   ecrire_image_pgm(cNomImgEcriteHF5, HF5,  nH/32, nW/32);

   ecrire_image_pgm(cNomImgEcriteBF6, BF6,  nH/64, nW/64);
   ecrire_image_pgm(cNomImgEcriteMFH6, MFH6,  nH/64, nW/64);
   ecrire_image_pgm(cNomImgEcriteMFV6, MFV6,  nH/64, nW/64);
   ecrire_image_pgm(cNomImgEcriteHF6, HF6,  nH/64, nW/64);

   ecrire_image_pgm(cNomImgEcriteOut, ImgOut,  nH, nW);

   free(ImgIn); free(BF); free(MFH); free(MFV); free(HF); free(ImgOut);

   return 1;
}