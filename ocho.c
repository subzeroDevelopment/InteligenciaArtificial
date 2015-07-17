#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

bool search(int [3][3],int);
void push(int[3][3]);
void imprimir(int[3][3]);
void copiar(int[3][3],int[3][3]);
int sonIguales(int[3][3],int[3][3]);
void buscarCero(int [3][3],int [2]);
void pop(void);
void izq(int,int,int[3][3]);
void der(int,int,int[3][3]);
void arriba(int,int,int[3][3]);
void abajo(int,int,int[3][3]);
//int profundidad=39;
int stack[30][3][3];
int orig[3][3];
int destino[3][3];
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


	for (int z = 0; z < stck; ++z){
		for (int x = 0; x < 3 ; ++x){
			for (int i = 0; i < 3; ++i){

				stack[z][x][i]=50;	
			}
		}	
	}
	printf("ingrese estado inicial\n");
	for (int x = 0; x < 3 ; ++x){
			for (int i = 0; i < 3; ++i){
				printf("%s%d %d","inicial: ",x,i);
				printf("   ");
				int b;
				scanf("%d",&b);
				orig[x][i]=b;
			}
			printf("\n");
		}	
	printf("ingrese estado final\n");
	for (int x = 0; x < 3 ; ++x){
			for (int i = 0; i < 3; ++i){
				printf("%s%d %d","final: ",x,i);
				printf("   ");
				int b;
				scanf("%d",&b);
				destino[x][i]=b;
			}
			printf("\n");
		}
	
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
bool search(int matriz[3][3],int profundidad){
	int vec[2];
	int aux[3][3];
	//printf("%s%d\n","contador:",cont );
	//imprimir(matriz);
	buscarCero(matriz,vec);
	push(matriz);
	profundidad++;
	if(sonIguales(matriz,destino)==9){
		return true;
	}
	//copiar(matriz,aux);
	//imprimir(aux);
	if(profundidad<stck){
		
		if(vec[1]>0){
			//imprimir(matriz);
			////printf("\n");
			copiar(matriz,aux);
			buscarCero(aux,vec);
			//imprimir(aux);
			//printf("%d %d\n",vec[0],vec[1]);
			izq(vec[0],vec[1],aux);
			//printf("%s\n","auxi izq");
			//imprimir(aux);
			//printf("****\n");
			if(search(aux,profundidad)==true)return true;
			//else imprimir(matriz);
		}
		if(vec[1]<2){
			//imprimir(matriz);
			//printf("\n");
			copiar(matriz,aux);
			buscarCero(aux,vec);
			//imprimir(aux);
			//printf("%d %d\n",vec[0],vec[1]);
			der(vec[0],vec[1],aux);
			//printf("%s\n","auxi der");
			//imprim//ir(aux);
			//printf("****\n");
			if(search(aux,profundidad)==true)return true;
			//else imprimir(matriz);
		}
		if(vec[0]>0){
			//imprimir(matriz);
			//printf("\n");
			copiar(matriz,aux);
			buscarCero(aux,vec);
			//imprimir(aux);
			//printf("%d %d\n",vec[0],vec[1]);
			arriba(vec[0],vec[1],aux);
			//printf("%s\n","auxi arriba");
			//imprimir(aux);
			//printf("****\n");
			if(search(aux,profundidad)==true)return true;
			//else imprimir(matriz);
		}
		
		if(vec[0]<2){
			//imprimir(matriz);
			//printf("\n");
			copiar(matriz,aux);
			buscarCero(aux,vec);
			//imprimir(aux);
			//printf("%d %d\n",vec[0],vec[1]);
			abajo(vec[0],vec[1],aux);
			//printf("%s\n","auxi abajo");
			//imprimir(aux);
			//printf("****\n");
			if(search(aux,profundidad)==true)return true;
			//else imprimir(matriz);
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


int sonIguales(int mat1[3][3],int mat2[3][3]){
	int var=0;
	for (int i = 0; i <3; ++i){
		for (int j = 0; j < 3; ++j){
			if(mat1[i][j]==mat2[i][j])var++;
		}
	
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

