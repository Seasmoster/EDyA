#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 101

typedef struct Avion
{
    int dato;
    char estado;
    struct Avion *siguiente;
}Nodo;

void insertaAvion(Nodo** cabeza, int matricula, char estado);
Nodo* crearAvion(int matricula,char estado);
void recorrer(Nodo* cabeza);
void cambiarEstado(Nodo* cabeza,int matricula);
void despegar(Nodo* cabeza);
//void eliminar(Nodo** cabeza,Item entrada);

void main()
{
    int matricula =0, i;
    char estado = ' ';
    Nodo *cabeza;

    cabeza = NULL;

    /*Menu */

    for(i = 0 ; i<13; i++ )
    {
        printf("Dame la matricula de la avioneta: ");
        scanf("%d",&matricula);
        estado = 'A';
        insertaAvion(&cabeza,matricula,estado);
    }

    recorrer(cabeza);
    /*Que aviones deseas que despeguen*/
    cambiarEstado(cabeza,10);

}


void insertaAvion(Nodo** cabeza,int matricula, char estado)
{
    Nodo *nuevo;
    nuevo = crearAvion(matricula,estado);
    nuevo ->siguiente = *cabeza;
    *cabeza = nuevo;
}

Nodo* crearAvion(int matricula,char estado)
{
    Nodo *p;
    p= (Nodo*)malloc(sizeof(Nodo));
    p->dato = matricula;
    p->estado = estado;
    p->siguiente = NULL;
    return p;
}

void recorrer(Nodo* cabeza){
    int k;
    printf("\n\t\t Aviones \n");
    for(k=0;cabeza ;cabeza = cabeza->siguiente)
    {
        printf("%d ",cabeza->dato);
        printf("%c ",cabeza->estado);
        k++;
        printf("%c",(k%13 ?  ' ':'\n'));
    }
    printf("\n\n");
}

void cambiarEstado(Nodo* cabeza,int matricula){
    int k;
    printf("\n\t\t Aviones \n");
    for(k=0;cabeza ;cabeza = cabeza->siguiente)
    {
        if(matricula == cabeza->dato)
            cabeza->estado = 'D';
        printf("%d ",cabeza->dato);
        printf("%c ",cabeza->estado);
        k++;
        printf("%c",(k%13 ?  ' ':'\n'));
    }
    printf("\n\n");
}
