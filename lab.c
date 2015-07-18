#include </usr/include/GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#define N 20

void cargaMatriz(int matriz[N][N]);
void prueba(void);
void pared(int x, int y, int r, int g, int b);
void estado(int x, int y, int tX, int tY);
int search(int [2],int);
void push(int[2]);
int sonIguales(int[2],int[2]);
void pop(void);

bool var;
int stck=100;
int cont=0;
int stack[100][2];
int matriz[N][N];
int inicio[2] = {0,0};// el inicio estará en el origen del laberinto
int salida[2] = {9,2}; //la salida estará en la esquina que se encuentra en la diagonal
int tx = 0;
int ty = 0;

void display() //Funcion de dibujado
{
int i;
int j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
        if (matriz[i][j] == 1)
            pared(j,i,0,0,0);
        else
            pared(j,i,1,1,1);
        


        }
    }
        estado(inicio[1],inicio[0],ty,tx);
            


glFlush(); //Forza el limpiado de pantalla
}

int search(int vector[2],int profundidad){
    
    int aux[2];
    push(vector);
    profundidad++;
    printf("vector:%d %d\n",vector[0],vector[1]);
    printf("%d\n",sonIguales(vector,salida));
    if(sonIguales(vector,salida)==2){
        return 1;
    }
    //copiar(matriz,aux);
    //imprimir(aux);
    if(profundidad<stck){
        int x=vector[0];
        int y=vector[1];
        if(y>0 && matriz[x][y-1]==0){
            printf("izq\n");
            aux[0]=x;
            aux[1]=y-1;
            tx=aux[1];
            ty=aux[0];      
            //glutPostRedisplay();      
            if(search(aux,profundidad)==1)return 1;
        
        }
        if(y<19 && matriz[x][y+1]==0){
            printf("der\n");
            aux[0]=x;
            aux[1]=y+1;
            tx=aux[0];
            ty=aux[1];
            //glutPostRedisplay();
            if(search(aux,profundidad)==1)return 1;
            //else imprimir(matriz);
        }
        if(x>0 && matriz[x-1][y]==0){
            printf("abj\n");
            aux[0]=x-1;
            aux[1]=y;
            tx=aux[0];
            ty=aux[1];  
            //glutPostRedisplay();
            if(search(aux,profundidad)==1)return 1;
            
        }
        
        if(x<19 && matriz[x+1][y]==0){
            printf("arr\n");
            aux[0]=x+1;
            aux[1]=y;
            tx=aux[0];
            ty=aux[1]; 
            //glutPostRedisplay();
            if(search(aux,profundidad)==1)return 1;
            
        }
    }   

        pop();
        return 0;
    
}
int sonIguales(int mat1[2],int mat2[2]){
    int var=0;
        for (int j = 0; j < 2; ++j){
            if(mat1[j]==mat2[j])var++;
        }
    return var;
}
void push(int ele[2]){
    for (int i = 0; i < 2; ++i){
        stack[cont][i]=ele[i];
    }
    cont++;
}
void pop(){
    cont--;
        for (int j = 0; j < 3; ++j){
            stack[cont][j]=50;
        }

}
void initstack(){
    for (int i = 0; i < 30; ++i){
        for (int j = 0; j < 2; ++j){
            stack[i][j]=50;   
        }
        
    }
}


void init()
{

    glClearColor(1.0,1.0,1.0,0.0); //Limpiar Pantalla

}

void reshape(int width, int height)
{
glClear(GL_COLOR_BUFFER_BIT); //Buffer
glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION); //Genera proyeccion
glLoadIdentity();
glOrtho(0.0,N,0.0,N,-1.0,1.0); //Perspectiva
glMatrixMode(GL_MODELVIEW); //Tipo de Proyeccion
}


int main(int argc, char ** argv)
{   

    cargaMatriz(matriz);//se llena la forma del laberinto mediante una matriz binaria
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); //Funcion Main
    glutInitWindowPosition(100,100); //Posicion de Ventana
    glutInitWindowSize(500,500); //Cambiar Tamaño de Ventana
    glutCreateWindow("Inteligencia Artificial - Laberinto - Instituto Tecnologico de Oaxaca"); //Crea y cambia el nombre de la ventana
    glutDisplayFunc(display); //Funcion de Dibujado anteriormente creada
    glutReshapeFunc(reshape);
    glutTimerFunc(10,prueba,0);
    glutMainLoop(); //Loop
    
    
    return 0;
}
void prueba(){
    search(inicio,0);
    glutPostRedisplay(); //Tell GLUT that the scene has changed

    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(5,search, 0);
}

void cargaMatriz(int matriz[N][N]){
    int i;
    int j;
    int matriz1[N][N] = {    //el laberinto está dado por una mtriz binaria en donde 0 indica que es un /				      //pasillo y 0 que es un muro.
                {0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
                {0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1},
                {0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0},
                {1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1},
                {0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0},
                {1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0},
                {0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,1,0,1,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1},
                {0,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0},
                {1,1,1,1,0,1,1,1,0,1,0,0,0,0,1,0,0,0,1,0},
                {0,0,0,0,0,1,0,1,0,0,0,1,1,0,1,0,1,1,1,0},
                {0,1,1,1,1,1,0,1,0,1,1,1,1,0,0,0,1,0,0,0},
                {0,1,0,0,0,1,0,1,0,0,1,1,1,1,1,1,1,0,1,1},
                {0,1,1,1,0,1,0,1,1,0,0,0,0,0,0,0,1,0,0,0},
                {0,0,0,0,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0},
                {0,0,0,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,1},
                {0,1,1,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,0},
                {0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,1,1,1,0}
                        };

    for (i = 0 ; i< N; i ++)
        for (j = 0 ; j< N; j ++)
        {
            matriz[j][i] = matriz1[j][i];
        }
}

void pared(int x, int y, int r, int g, int b)
{
    glBegin(GL_QUADS); //Modelo a Dibujar
        glColor3f(r,g,b);
        glVertex3f(x,y,0.0);
        glVertex3f(x + 1,y,0.0);
        glVertex3f(x + 1,y + 1,0.0);
        glVertex3f(x,y + 1,0.0);
    glEnd(); //Finaliza el dibujo
}
void estado(int x, int y, int tX, int tY)
{

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glPointSize(10.0f);
    glBegin(GL_POINTS);
        glVertex2f(x +0.5 + tX,y + 0.5 +tY);
    glEnd();
    glTranslatef(tX,tY,0.0f);
glPopMatrix();
}