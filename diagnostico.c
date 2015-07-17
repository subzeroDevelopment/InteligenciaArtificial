#include <stdio.h>

int main(void){
	int n,m;
	printf("%s\n","ingrese n" );
	scanf("%d",&n);
	printf("%s\n", "ingrese m");
	scanf("%d",&m);
	int arre[n][m];
	int aux;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("ingrese valor %d %d\n",i,j);
			scanf("%d",&aux);
			arre[i][j]=aux;

		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d",arre[i][j]);

		}
		printf("\n" );
	}
	
	int cont=0;
	for(int i=0;i<n;i++){
		if(arre[i][i]==1){
				cont++;
		}	
	}

	int count=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arre[i][j]==1)count++;
			}
	}



	if(cont==n && count==n){
		printf("%s\n","Matriz identidad");
	}
	else
		printf("%s\n","No es Matriz identidad");






}