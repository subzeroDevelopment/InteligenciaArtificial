#include <stdio.h>

int matriz[39][39];
int main(void){
	cargar();
	for (int i = 0; i <39; ++i){
		for (int j = 0; j< 39; ++j)
		{
			printf("%d\n",matriz[i][j]);
		}
		printf("\n");
		
	}





return 0;

int cargar(){

matriz[0][1]=1;matriz[1][0]=1;
matriz[1][3]=1;matriz[3][1]=1;
matriz[2][1]=1;matriz[1][2]=1;
matriz[2][4]=1;matriz[4][2]=1;
matriz[4][5]=1;matriz[5][4]=1;
matriz[2][6]=1;matriz[6][2]=1;
matriz[6][7]=1;matriz[7][6]=1;
matriz[7][8]=1;matriz[8][7]=1;
matriz[8][9]=1;matriz[9][8]=1;
matriz[6][10]=1;matriz[10][6]=1;
matriz[10][11]=1;matriz[11][10]=1;
matriz[12][13]=1;matriz[13][12]=1;
matriz[13][14]=1;matriz[14][13]=1;
matriz[14][15]=1;matriz[15][14]=1;
matriz[15][11]=1;matriz[11][15]=1;
matriz[0][16]=1;matriz[16][0]=1;
matriz[16][17]=1;matriz[17][16]=1;
matriz[3][18]=1;matriz[18][3]=1;
matriz[11][19]=1;matriz[19][11]=1;
matriz[11][20]=1;matriz[20][11]=1;
matriz[20][21]=1;matriz[21][20]=1;
matriz[21][22]=1;matriz[22][21]=1;
matriz[22][23]=1;matriz[23][22]=1;
matriz[23][24]=1;matriz[24][23]=1;
matriz[24][25]=1;matriz[25][24]=1;
matriz[21][25]=1;matriz[25][21]=1;
matriz[19][26]=1;matriz[26][19]=1;
matriz[26][27]=1;matriz[27][26]=1;
matriz[27][28]=1;matriz[28][27]=1;
matriz[28][29]=1;matriz[29][28]=1;
matriz[28][2]=1;matriz[2][28]=1;
matriz[29][30]=1;matriz[30][29]=1;
matriz[30][18]=1;matriz[18][30]=1;
matriz[18][31]=1;matriz[31][18]=1;
matriz[28][32]=1;matriz[32][28]=1;
matriz[32][33]=1;matriz[33][32]=1;
matriz[32][34]=1;matriz[34][32]=1;
matriz[34][35]=1;matriz[35][34]=1;
matriz[35][36]=1;matriz[36][35]=1;
matriz[36][37]=1;matriz[37][36]=1;
matriz[37][38]=1;matriz[38][37]=1;
return 0;
}}