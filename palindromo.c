#include<stdio.h>	
#include<string.h>
int main(void)
{
   char palabra[80];
   int x;
   printf("\n\nEscribe una palabra: ");
   scanf("%[^\n]",palabra);
   x=strlen(palabra);
   printf("%d\n",x);
   char copia[80];
   //strcpy(copia,palabra);
   int a=0;
   for (int i = x-1;i>=0;i--){
      copia[a]=palabra[i];
      a++;
   }
   printf("%s\n",copia);
   a=0;
   for (int i = 0;i<x;i++){
      if(copia[i]==palabra[i])
      a++;
   }
   if(a==x)printf("%s\n","es palindromo");
   else printf("%s\n","no es palindromo" );
 }   		

