#include <stdio.h>

int matriz[2][2][2];
int y;

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 2; ++i){
		for (int j = 0; j < 2; ++j){
			for (int k = 0; k < 2; ++k){
				printf("%s%d%d%d\n","ingresa:",i,j,k);
				scanf("%d",&y);
				matriz[i][j][k]=y;
			}
			
		}
	}

	for (int i = 0; i < 2; ++i){
		for (int j = 0; j < 2; ++j){
			for (int k = 0; k < 2; ++k){
				y=matriz[i][j][k];
				printf("%d",y);
			}
			printf("\n");
		}
		printf("\n");
	}


	return 0;
}