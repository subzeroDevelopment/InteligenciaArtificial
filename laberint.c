#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
void load(void);
bool search(int [2],int);
void push(int[2]);
void imprimir(int[2]);
void copiar(int[2],int[2]);
int sonIguales(int[2],int[2]);
void pop(void);
void izq(int,int);
void der(int,int);
void arriba(int,int);
void abajo(int,int);
//int profundidad=39;
int vector[2];
int destino[2]={19,19};
int stack[30][2];
bool var;
int cont=0;
int stck=30;

/*falta hacer el stack y ingresar matriz final y origen*/
int main(void){
	//profundidad=20;
	//id=0;
	/*orig[0][0]=1;
	orig[0][1]=0;
	orig[0][2]=2;
	orig[1][0]=3;
	orig[1][1]=4;
	orig[1][2]=5;
	orig[2][0]=6;
	orig[2][1]=7;
	orig[2][2]=8;
	destino[0][0]=1;
	destino[0][1]=2;
	destino[0][2]=3;
	destino[1][0]=0;
	destino[1][1]=4;
	destino[1][2]=5;
	destino[2][0]=6;
	destino[2][1]=7;
	destino[2][2]=8;*/
	/*int ve[2];
	imprimir(orig);
	buscarCero(orig,ve);
	abajo(ve[0],ve[1],orig);
	printf("\n");
	imprimir(orig);
	printf("\n");
	buscarCero(orig,ve);
	abajo(ve[0],ve[1],orig);
	printf("\n");
	imprimir(orig);
	printf("\n");
	buscarCero(orig,ve);
	der(ve[0],ve[1],orig);
	printf("\n");
	imprimir(orig);
	printf("\n");
	buscarCero(orig,ve);
	izq(ve[0],ve[1],orig);
	printf("\n");
	imprimir(orig);
	printf("\n");
	buscarCero(orig,ve);
	arriba(ve[0],ve[1],orig);
	printf("\n");
	imprimir(orig);*/

	var=search(orig,0);
	if(var==true){
		printf("%s\n","encontro" );
	int o;
	for (int i = 0; i < stck; ++i){
		for (int b = 0; b < 3; ++b){
			for (int h=0; h<3;++h){
				int n=stack[i][b][h];
				if(n==50);
				else printf("%d ",n);
				o=n;
			}
			printf("\n");
		}
		if(o!=50)
		printf("\n");
	printf("%d\n",i);
	}
	}
	else{
		printf("%s\n","no se encontro solucion" );
	}
	
	return 0;
	}
bool search(int vector[2],int profundidad){
	int aux[2];
	push(matriz);
	profundidad++;
	if(sonIguales(vector,destino)==2){
		return true;
	}
	//copiar(matriz,aux);
	//imprimir(aux);
	if(profundidad<stck){
		int x=vector[0];
		int y=vector[1];
		if(y>0 && matriz[x][y-1]==0){
			aux[0]=x;
			aux[1]=y-1;
			estado(inicio[0],inicio[1],aux[0],aux[1]);
			if(search(aux,profundidad)==true)return true;
		
		}
		if(y<19 && matriz[x][y+1]==0){
			aux[0]=x;
			aux[1]=y+1;
			estado(inicio[0],inicio[1],aux[0],aux[1]);
			if(search(aux,profundidad)==true)return true;
			//else imprimir(matriz);
		}
		if(x>0 && matriz[x-1][y]==0){
			aux[0]=x-1;
			aux[1]=y;
			estado(inicio[0],inicio[1],aux[0],aux[1]);	
			if(search(aux,profundidad)==true)return true;
			
		}
		
		if(x<19 && matriz[x+1][y]==0){
			aux[0]=x+1;
			aux[1]=y;
			estado(inicio[0],inicio[1],aux[0],aux[1]);
			if(search(aux,profundidad)==true)return true;
			
		}
	}	
		//printf("false:\n");
		//imprimir(matriz);
		//printf("falseend\n");
		pop();
		return false;
	
}
void imprimir(int ma[3][3]){
	//sleep(0.8);
	//system("clear");
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			printf("%d",ma[i][j]);	
		}
		printf("\n");
	}
}


//terminar todas la posiciones
void izq(int x,int y,int mat[3][3]){
	mat[x][y]=mat[x][y-1];
	mat[x][y-1]=0;
}
void der(int x,int y,int mat[3][3]){
	mat[x][y]=mat[x][y+1];
	mat[x][y+1]=0;
}
void arriba(int x,int y,int mat[3][3]){
	mat[x][y]=mat[x-1][y];
	mat[x-1][y]=0;
}
void abajo(int x,int y,int mat[3][3]){
	int q;
	q=mat[x+1][y];
	mat[x][y]=q;
	mat[x+1][y]=0;
}


int sonIguales(int mat1[2],int mat2[2]){
	int var=0;
		for (int j = 0; j < 2; ++j){
			if(mat1[j]==mat2[j])var++;
		}
	return var;
}
void buscarCero(int matriz[3][3],int arre[2]){
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			if (matriz[i][j]==0)
			{
				arre[0]=i;
				arre[1]=j;
			}
		}
	}
}
void copiar(int mat1[3][3],int mat2[3][3]){
	int p;
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			p=mat1[i][j];
			mat2[i][j]=p;
		}
	}	
}



//

void push(int ele[3][3]){
	for (int i = 0; i < 3; ++i){
		for (int j=0; j < 3; ++j){
			int z=ele[i][j];
			stack[cont][i][j]=z;
		}
	}
	cont++;
}
void pop(){
	cont--;
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			stack[cont][i][j]=50;
		}
	}

}
void load(){
matriz[0][0]=1; matriz[0][1]=1; matriz[0][2]=1; matriz[0][3]=1; matriz[0][4]=0; matriz[0][5]=1; matriz[0][6]=1; matriz[0][7]=1; matriz[0][8]=0; matriz[0][9]=1; matriz[0][10]=1; matriz[0][11]=1; matriz[0][12]=1; matriz[0][13]=1; matriz[0][14]=1; matriz[0][15]=0; matriz[0][16]=1; matriz[0][17]=0; matriz[0][18]=0; matriz[0][19]=1;
matriz[1][0]=1; matriz[1][1]=1; matriz[1][2]=0; matriz[1][3]=1; matriz[1][4]=0; matriz[1][5]=0; matriz[1][6]=0; matriz[1][7]=0; matriz[1][8]=1; matriz[1][9]=1; matriz[1][10]=1; matriz[1][11]=0; matriz[1][12]=1; matriz[1][13]=0; matriz[1][14]=0; matriz[1][15]=1; matriz[1][16]=1; matriz[1][17]=1; matriz[1][18]=0; matriz[1][19]=1;
matriz[2][0]=1; matriz[2][1]=0; matriz[2][2]=1; matriz[2][3]=0; matriz[2][4]=0; matriz[2][5]=0; matriz[2][6]=1; matriz[2][7]=1; matriz[2][8]=0; matriz[2][9]=0; matriz[2][10]=1; matriz[2][11]=1; matriz[2][12]=0; matriz[2][13]=1; matriz[2][14]=1; matriz[2][15]=0; matriz[2][16]=0; matriz[2][17]=1; matriz[2][18]=1; matriz[2][19]=0;
matriz[3][0]=1; matriz[3][1]=0; matriz[3][2]=1; matriz[3][3]=1; matriz[3][4]=0; matriz[3][5]=1; matriz[3][6]=1; matriz[3][7]=1; matriz[3][8]=1; matriz[3][9]=1; matriz[3][10]=1; matriz[3][11]=1; matriz[3][12]=1; matriz[3][13]=1; matriz[3][14]=1; matriz[3][15]=0; matriz[3][16]=0; matriz[3][17]=1; matriz[3][18]=1; matriz[3][19]=0;
matriz[4][0]=0; matriz[4][1]=1; matriz[4][2]=1; matriz[4][3]=0; matriz[4][4]=0; matriz[4][5]=1; matriz[4][6]=1; matriz[4][7]=0; matriz[4][8]=1; matriz[4][9]=1; matriz[4][10]=1; matriz[4][11]=0; matriz[4][12]=0; matriz[4][13]=0; matriz[4][14]=1; matriz[4][15]=0; matriz[4][16]=1; matriz[4][17]=1; matriz[4][18]=0; matriz[4][19]=0;
matriz[5][0]=0; matriz[5][1]=0; matriz[5][2]=1; matriz[5][3]=0; matriz[5][4]=0; matriz[5][5]=0; matriz[5][6]=1; matriz[5][7]=1; matriz[5][8]=0; matriz[5][9]=0; matriz[5][10]=0; matriz[5][11]=0; matriz[5][12]=1; matriz[5][13]=0; matriz[5][14]=1; matriz[5][15]=0; matriz[5][16]=1; matriz[5][17]=0; matriz[5][18]=1; matriz[5][19]=0;
matriz[6][0]=1; matriz[6][1]=1; matriz[6][2]=0; matriz[6][3]=0; matriz[6][4]=0; matriz[6][5]=1; matriz[6][6]=0; matriz[6][7]=0; matriz[6][8]=1; matriz[6][9]=0; matriz[6][10]=1; matriz[6][11]=0; matriz[6][12]=1; matriz[6][13]=0; matriz[6][14]=0; matriz[6][15]=0; matriz[6][16]=0; matriz[6][17]=1; matriz[6][18]=1; matriz[6][19]=1;
matriz[7][0]=0; matriz[7][1]=1; matriz[7][2]=1; matriz[7][3]=0; matriz[7][4]=1; matriz[7][5]=1; matriz[7][6]=1; matriz[7][7]=0; matriz[7][8]=0; matriz[7][9]=1; matriz[7][10]=0; matriz[7][11]=1; matriz[7][12]=1; matriz[7][13]=0; matriz[7][14]=1; matriz[7][15]=1; matriz[7][16]=0; matriz[7][17]=1; matriz[7][18]=1; matriz[7][19]=1;
matriz[8][0]=1; matriz[8][1]=1; matriz[8][2]=1; matriz[8][3]=0; matriz[8][4]=0; matriz[8][5]=0; matriz[8][6]=1; matriz[8][7]=0; matriz[8][8]=0; matriz[8][9]=1; matriz[8][10]=0; matriz[8][11]=0; matriz[8][12]=0; matriz[8][13]=1; matriz[8][14]=0; matriz[8][15]=1; matriz[8][16]=1; matriz[8][17]=0; matriz[8][18]=0; matriz[8][19]=1;
matriz[9][0]=1; matriz[9][1]=1; matriz[9][2]=1; matriz[9][3]=0; matriz[9][4]=1; matriz[9][5]=1; matriz[9][6]=0; matriz[9][7]=1; matriz[9][8]=1; matriz[9][9]=1; matriz[9][10]=0; matriz[9][11]=1; matriz[9][12]=1; matriz[9][13]=1; matriz[9][14]=0; matriz[9][15]=0; matriz[9][16]=1; matriz[9][17]=1; matriz[9][18]=1; matriz[9][19]=1;
matriz[10][0]=1; matriz[10][1]=1; matriz[10][2]=0; matriz[10][3]=1; matriz[10][4]=0; matriz[10][5]=0; matriz[10][6]=1; matriz[10][7]=1; matriz[10][8]=1; matriz[10][9]=1; matriz[10][10]=1; matriz[10][11]=1; matriz[10][12]=0; matriz[10][13]=1; matriz[10][14]=1; matriz[10][15]=0; matriz[10][16]=0; matriz[10][17]=1; matriz[10][18]=1; matriz[10][19]=0;
matriz[11][0]=1; matriz[11][1]=0; matriz[11][2]=1; matriz[11][3]=1; matriz[11][4]=0; matriz[11][5]=1; matriz[11][6]=0; matriz[11][7]=0; matriz[11][8]=0; matriz[11][9]=1; matriz[11][10]=1; matriz[11][11]=1; matriz[11][12]=1; matriz[11][13]=1; matriz[11][14]=1; matriz[11][15]=1; matriz[11][16]=0; matriz[11][17]=0; matriz[11][18]=0; matriz[11][19]=0;
matriz[12][0]=1; matriz[12][1]=1; matriz[12][2]=0; matriz[12][3]=0; matriz[12][4]=1; matriz[12][5]=1; matriz[12][6]=1; matriz[12][7]=0; matriz[12][8]=0; matriz[12][9]=1; matriz[12][10]=0; matriz[12][11]=1; matriz[12][12]=1; matriz[12][13]=0; matriz[12][14]=1; matriz[12][15]=0; matriz[12][16]=0; matriz[12][17]=0; matriz[12][18]=1; matriz[12][19]=1;
matriz[13][0]=0; matriz[13][1]=0; matriz[13][2]=0; matriz[13][3]=1; matriz[13][4]=0; matriz[13][5]=1; matriz[13][6]=1; matriz[13][7]=1; matriz[13][8]=1; matriz[13][9]=1; matriz[13][10]=1; matriz[13][11]=0; matriz[13][12]=0; matriz[13][13]=1; matriz[13][14]=1; matriz[13][15]=0; matriz[13][16]=1; matriz[13][17]=0; matriz[13][18]=0; matriz[13][19]=0;
matriz[14][0]=0; matriz[14][1]=1; matriz[14][2]=0; matriz[14][3]=0; matriz[14][4]=0; matriz[14][5]=0; matriz[14][6]=1; matriz[14][7]=0; matriz[14][8]=0; matriz[14][9]=0; matriz[14][10]=0; matriz[14][11]=1; matriz[14][12]=1; matriz[14][13]=1; matriz[14][14]=1; matriz[14][15]=0; matriz[14][16]=1; matriz[14][17]=0; matriz[14][18]=1; matriz[14][19]=1;
matriz[15][0]=0; matriz[15][1]=0; matriz[15][2]=1; matriz[15][3]=1; matriz[15][4]=0; matriz[15][5]=1; matriz[15][6]=0; matriz[15][7]=0; matriz[15][8]=0; matriz[15][9]=1; matriz[15][10]=0; matriz[15][11]=1; matriz[15][12]=0; matriz[15][13]=1; matriz[15][14]=1; matriz[15][15]=0; matriz[15][16]=0; matriz[15][17]=1; matriz[15][18]=0; matriz[15][19]=1;
matriz[16][0]=1; matriz[16][1]=1; matriz[16][2]=1; matriz[16][3]=1; matriz[16][4]=0; matriz[16][5]=0; matriz[16][6]=1; matriz[16][7]=0; matriz[16][8]=1; matriz[16][9]=0; matriz[16][10]=0; matriz[16][11]=1; matriz[16][12]=1; matriz[16][13]=0; matriz[16][14]=1; matriz[16][15]=0; matriz[16][16]=1; matriz[16][17]=1; matriz[16][18]=0; matriz[16][19]=1;
matriz[17][0]=0; matriz[17][1]=0; matriz[17][2]=0; matriz[17][3]=1; matriz[17][4]=1; matriz[17][5]=0; matriz[17][6]=0; matriz[17][7]=0; matriz[17][8]=1; matriz[17][9]=0; matriz[17][10]=0; matriz[17][11]=0; matriz[17][12]=1; matriz[17][13]=0; matriz[17][14]=1; matriz[17][15]=0; matriz[17][16]=1; matriz[17][17]=1; matriz[17][18]=1; matriz[17][19]=1;
matriz[18][0]=1; matriz[18][1]=0; matriz[18][2]=0; matriz[18][3]=0; matriz[18][4]=1; matriz[18][5]=0; matriz[18][6]=1; matriz[18][7]=1; matriz[18][8]=0; matriz[18][9]=1; matriz[18][10]=0; matriz[18][11]=0; matriz[18][12]=0; matriz[18][13]=1; matriz[18][14]=0; matriz[18][15]=0; matriz[18][16]=1; matriz[18][17]=1; matriz[18][18]=1; matriz[18][19]=1;
matriz[19][0]=0; matriz[19][1]=0; matriz[19][2]=1; matriz[19][3]=1; matriz[19][4]=1; matriz[19][5]=1; matriz[19][6]=1; matriz[19][7]=0; matriz[19][8]=1; matriz[19][9]=1; matriz[19][10]=1; matriz[19][11]=0; matriz[19][12]=1; matriz[19][13]=1; matriz[19][14]=1; matriz[19][15]=0; matriz[19][16]=1; matriz[19][17]=1; matriz[19][18]=0; matriz[19][19]=0;
}

