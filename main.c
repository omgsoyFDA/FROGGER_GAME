#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>


 void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }


int Mapa[90][40];
int posx=35;
int posy=36;
int nivel=0;


 struct Obstaculos{
     int posicionX;
     int posicionY;
 }Autos[30];//


//VOLVERLO VARIABLE DESPUES(AÑADIR PARAMETROS) CORTAR 6 DEDOS AL MAPA
void MapDesign(){
    //DEFINIR LOS ESPACIOS EN BLANCOS
    for(int i=0;i<90;i++){
        for(int j=0;j<40;j++){
            Mapa[i][j]=0;
        }
    }
    //ESQUINAS DEL MAPA
    gotoxy(0,0);printf("%c",201);Mapa[0][0]=2;
    gotoxy(0,40);printf("%c",200);Mapa[0][39]=2;
    gotoxy(90,0);printf("%c",187);Mapa[89][0]=2;
    gotoxy(90,40);printf("%c",188);Mapa[89][39]=2;
    //BORDES DEL MAPA
    //EJE X
    for(int i=0; i<89;i++){
        Mapa[i+1][0]=2;
        Mapa[i+1][39]=2;
        gotoxy(i+1,0);printf("%c",205);//MARCO SUPERIOR HORIZONTAL
        gotoxy(i+1,40);printf("%c",205);//MARCO INFERIOR HORIZONTAL

        gotoxy(i+1,3);printf("-");//BLOQUE SUPERIOR - CUADRO DE SCORE
        gotoxy(i+1,37);printf("-");//BLOQUE INFERIOR - CUADRO DE VIDA TIEMPO RANA

        gotoxy(i+1,35);printf("-");//ACERA AL PRINCIPIO
        gotoxy(i+1,17);printf("-");//ACERA DE EN MEDIO LINEA SUPERIOR
        gotoxy(i+1,19);printf("-");//ACERA DE EN MEDIO LINEA INFERIOR
    }
    //EJE Y
    for(int i=0; i<39;i++){
        gotoxy(0,i+1);printf("%c",186);
        gotoxy(90,i+1);printf("%c",186);
        Mapa[0][i+1]=2;
        Mapa[89][i+1]=2;
    }
}

void MovimientoDeRana(char z){
    if(kbhit()){
        z=getch();
        if(z=='w'){
            gotoxy(posx,posy);printf("   ");
            posy=posy-2;
            if(posy<=0){
                posy=posy+2;
            }
            gotoxy(posx,posy);printf("}%c{",219);
        }
        if(z=='s'){
            gotoxy(posx,posy);printf("   ");
            posy=posy+2;
            if(posy>=40){
                posy=posy-2;
            }
            gotoxy(posx,posy);printf("}%c{",219);
        }
        if(z=='d'){
            gotoxy(posx,posy);printf("   ");
            posx=posx+2;
            if(posx>=90){
                posx=posx+2;
            }
            gotoxy(posx,posy);printf("}%c{",219);
        }
        if(z=='a'){
            gotoxy(posx,posy);printf("   ");
            posx=posx-2;
            if(posx<=0){
                posx=posx+2;
            }
            gotoxy(posx,posy);printf("}%c{",219);
        }
        }
}

void llenaren_blanco_lleno(int opcion){
    if(opcion==1){

    }
    else{

    }
}

void inicializar_objetos(int nivel){
//NIVEL = FASES DEPENDIENDO DE LA FASES AUMENTA LOS AUTOS

int i=0;//INDICADOR DE LOS OBJETOS - SIRVE PARA EL WHILE COMO UN CONTADOR

int tope=0; //INTENTAR CONVERTIRLOS EN PILAS(PARA LUEGO)

//AUTOS
int Espacio_mapa=90/nivel; // DIVIDO EL MAPA DEPENDIENDO DE LA CANTIDAD DE AUTOS POR FASE (PREDETERMINADAMENTE ES 3)

int posi[2]={1,12}; //POSICION INICIAL EN X DEL PRIMER AUTO

while(i<nivel){
    for(int j=0;j<7;j++){ // HACER LOS AUTOS DE UNA COLUMNA COMPLETA
        if(j%2==0){ //AUTOS LAS FILAS PARES
            gotoxy(posi[0]+1,33-(j*2));printf("%c",220); // POSICION DEL TECHO DEL AUTO
            gotoxy(posi[0],34-(j*2));printf("%c%c%c%c%c",254,223,223,223,254); //POSICION DEL CUERPO DEL AUTO
            //ALMACENAMOS POSICION DE LOS AUTOS EN SU RESPECTIVA ESTRUCTURA
            Autos[tope].posicionX=posi[0];
            Autos[tope].posicionY=34-(j*2);
            tope++;
        }
        else{ //AUTOS PARA LOS ESPACIOS QUE DEJAN LOS OTROS AUTOS
            gotoxy(posi[1]+1,33-(j*2));printf("%c",220);
            gotoxy(posi[1],34-(j*2));printf("%c%c%c%c%c",254,223,223,223,254);
            //ALMACENAMOS POSICION DE LOS AUTOS EN SU RESPECTIVA ESTRUCTURA
            Autos[tope].posicionX=posi[1];
            Autos[tope].posicionY=34-(j*2);
            tope++;
        }
    }
    posi[0]=posi[0]+Espacio_mapa; // PASAMOS A LA OTRA POSICION DE COLUMNA PARA LOS OTROS AUTOS (FILA 0, FILA 2)
    posi[1]=posi[1]+Espacio_mapa; // PASAMOS A LA OTRA POSICION DE COLUMNA PARA LOS OTROS AUTOS PARA LOS ESPACIOS EN BLANCOS (FILA 1, FILA 3)
    i++;
}
//TRONCOS/TORTUGAS/NEUFARES
i=0;
while(i)
}

void funciondeprubea(){
}

void Movimiento_Auto(int nivel){
//MOVIMIENTO
    for(int i=0;i<7*nivel;i++){//SE MULTIPLICA EL TOTAL DE FILAS POR LA CANTIDAD DE AUTO QUE VA A VER POR CADA UNA
        gotoxy(Autos[i].posicionX+1,Autos[i].posicionY-1);printf("   ");
        gotoxy(Autos[i].posicionX,Autos[i].posicionY);printf("     "); //DEJA LOS ESPAPCIO
        Autos[i].posicionX +=1; //MUEVE EL AUTO
        if(Autos[i].posicionX+4>=90){ //ARREGLAR LA VALIDACION PARA QUE NO CHOQUE CON EL MARCO
                Autos[i].posicionX=1;
        }
        gotoxy(Autos[i].posicionX+1,Autos[i].posicionY-1);printf("%c",220);//MOVIMIENTO DEL AUTO
        gotoxy(Autos[i].posicionX,Autos[i].posicionY);printf("%c%c%c%c%c",254,223,223,223,254); //MOVIMIENTO DEL AUTO
        Mapa[Autos[i].posicionX][Autos[i].posicionY]=1; //SE ASIGNA EN EL MAPA QUE VALE UNO LA POSICION ACTUAL
    }
    Sleep(50);
}

void Movimiento_tronco(){
}

void Movimiento_Animales(){
}

void MovimientoDeObstaculos(){

}

void Juego(){
    char z;
    int gameover=0;

    MapDesign();
    inicializar_objetos(4);
    gotoxy(35,36);printf("}%c{",219);

    while(gameover!=1){
        Movimiento_Auto(4);
        MovimientoDeRana(z);
}
}


int main(){
    Juego();
    return 0;
}
