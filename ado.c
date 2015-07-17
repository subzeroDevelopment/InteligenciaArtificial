#include <stdio.h>
#include <stdbool.h>

int load(void);
void ciudades(void);
bool search(int,int);
void  recorrer(int,int);
int matriz[39][39];
void push(int);
void pop(void);
//int profundidad=39;
int val[40];
int stack[39];
int id=0;
int origen;
int destino;
bool var;
int cont=0;
const char *list[39];


int main(void){
	//profundidad=20;
	//id=0;
	for (int z = 0; z < 39; ++z){
		stack[z]=50;
	}
	printf("%s\n","ingrese origen en numero");
	scanf("%d",&origen);
	printf("%s\n","ingrese destino en numero");
	scanf("%d",&destino);
	load();
	ciudades();
	var=search(origen,0);
	if(var==true){
		printf("%s\n","encontro" );
		for (int i=0; i<39;++i)
		{
			int n=stack[i];
			if(n==50)printf(" ");
			else printf("%s ",list[n]);
			
		}
	}
	else{
		printf("%s\n","no se encontro solucion" );
	}
	
	return 0;
}
bool search(int origen,int profundidad){
	profundidad++;
	push(origen);
	id++;
	if (origen==destino){
		return true;
	}
	if(profundidad<39){
  for (int t=0;t<39;t++){
    if (matriz[origen][t]==1){ 
    	if(search(t,profundidad)==true){
    		return true;
    		break;
    	}
    }
	}}
	pop();
	return false;
}

void push(int ele){
	stack[cont]=ele;
	cont++;
}
void pop(){
	cont--;
	stack[cont]=50;
}






int load(){
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
for (int i = 0; i <39; ++i){
		for (int j = 0; j< 39; ++j)
		{
			if(matriz[i][j]!=1)matriz[i][j]=0;	
			//printf("%d",matriz[i][j]);
		}
		//printf("\n");
		
	}
return 0;
}
void ciudades(){
list[0]="salina";
list[1]="tehuantepec";
list[2]="juchitan";
list[3]="oaxaca";
list[4]="ixtepec";
list[5]="ixtaltepec";
list[6]="tonala";
list[7]="pijijiapan";
list[8]="huixtla";
list[9]="tapachula";
list[10]="tuxtla";
list[11]="villahermosa";
list[12]="comitan";
list[13]="sancristo";
list[14]="ocosingo";
list[15]="palenque";
list[16]="huatulco";
list[17]="ptoesco";
list[18]="puebla";
list[19]="cardenaz";
list[20]="cdcarmen";
list[21]="campeche";
list[22]="merida";
list[23]="cancun";
list[24]="playa";
list[25]="chetumal";
list[26]="coatza";
list[27]="minatitlan";
list[28]="acayucan";
list[29]="cordoba";
list[30]="orizaba";
list[31]="cdmex";
list[32]="veracruz";
list[33]="xalapa";
list[34]="pozarica";
list[35]="tuxpan";
list[36]="tampico";
list[37]="matamoros";
list[38]="reynosa";

}