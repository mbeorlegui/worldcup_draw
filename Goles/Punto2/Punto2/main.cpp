#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

struct gol{
    int id_gol;
    int cod_equipo;
    int fecha;
    char nombre_jugador [20];
    int id_partido;
};

struct fgol{
    int id_gol;
    int fecha;
    char nombre_jugador [20];
};

struct Nodo{
    fgol mgol;
    Nodo*sgte;
};

struct team{
    int team;
    int cant;
};

team teamgol;
Nodo* InsertarOrdenado(Nodo*&, fgol );
fgol Pop(Nodo* &);
void cargarMatriz(Nodo*[][64]);
void mostrarMatriz(Nodo*[][64]);

int main(){
	Nodo*M[32][64];
	int i,j;
	for(i=0;i<32;i++){
	    for(j=0;j<64;j++){
	      M[i][j]=NULL;
	    }
	}
	cargarMatriz(M);
	mostrarMatriz(M);

}

void cargarMatriz(Nodo*M[][64]){
	gol golesCargados;
	fgol ffgol;
	int i,j;
		FILE*goles=fopen("Goles.txt","rb+");
	    fseek(goles,0,SEEK_SET);
		while (fread(&golesCargados,sizeof(gol),1,goles)){
	        i=golesCargados.cod_equipo;
	        j=golesCargados.id_partido;
	        ffgol.fecha=golesCargados.fecha;
	        ffgol.id_gol=golesCargados.id_gol;
	        strcpy(ffgol.nombre_jugador,golesCargados.nombre_jugador);
	        InsertarOrdenado(M[i][j],ffgol);
		}
	fclose(goles);
}

void mostrarMatriz(Nodo*M[][64]){
	fgol x;
	int i, j;
	for(i=0;i<32;i++){
	    for(j=0;j<64;j++){
	        while (M[i][j]!=NULL){
	            x = Pop(M[i][j]);
	          //  cout<<"La matriz tiene fecha:---- "<<x.fecha;
	          //  cout<<"\nLa matriz tiene gol:---- "<<x.id_gol;
	          //  cout<<"\nLa matriz tiene jugador: "<<x.nombre_jugador;
	            teamgol.cant++;
	   		}
		}
		teamgol.team=i;
		cout<<"\n La cantidad de goles del equipo "<<teamgol.team<<" es : "<<teamgol.cant;
		teamgol.cant=0;
		teamgol.team=0;
	};
	
}

fgol Pop(Nodo* &Pila){
	fgol y;
	Nodo* p = Pila;
	y.fecha= p->mgol.fecha;
	y.id_gol= p->mgol.id_gol;
	strcpy(y.nombre_jugador,p->mgol.nombre_jugador);
	Pila = p->sgte;
	delete p;
	return y;
}

Nodo* InsertarOrdenado(Nodo*& Lista, fgol x){
	Nodo* p = new Nodo();
	p->mgol=x;
	if(Lista==NULL || x.id_gol<Lista->mgol.id_gol){
		p->sgte=Lista;
		Lista=p;
		return p;
	}
	Nodo* q = Lista;
	while(q->sgte!=NULL && x.id_gol>q->sgte->mgol.id_gol){
		q=q->sgte;
	}
	p->sgte=q->sgte;
	q->sgte=p;
	return p;
}
