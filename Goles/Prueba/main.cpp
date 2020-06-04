#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct gol
{
    int id_gol;
    int cod_equipo;
    int fecha;
    char nombre_jugador [20];
    int id_partido;
};

struct fgol
{
    int cod_equipo;
    int id_gol;
    int fecha;
    char nombre_jugador [20];
};

struct Nodo
{
    fgol mgol;
    Nodo*sgte;
};

struct team
{
    int team;
    int cant;
};
team teamgol;

struct infolistag
{
    char nombre_jugador [20];
    int cod_equipo;
    int cantgoles;
    int fecha;
};

struct listag
{
    gol info;
    listag* sgte;
};

void GenArchivo(FILE*);

void Mostrar(FILE*);

void CargarMatriz(FILE*,Nodo*[32][64]);

Nodo* InsertarOrdenado(Nodo*&, fgol );

listag* InsertarOrdenadoGL(listag*&, fgol&,int&);
listag*Buscar(listag*&,char[] );
listag*buscaroinsertar(listag*&,fgol& ,int &);
fgol Pop(Nodo* &);

gol Popgol(listag* &);

int main()
{

    Nodo*M[32][64];
    listag*pichichi=new listag();
    pichichi=NULL;

    int i,j;
    for(i=0; i<32; i++)
    {
        for(j=0; j<64; j++)
        {
            M[i][j]=NULL;
        }
    }

    FILE*goles=fopen("Goles.bin","wb+");

    GenArchivo(goles);

    Mostrar(goles);

    CargarMatriz(goles,M);
    ////////MOSTRAR MATRIZ////////
listag*pichichen=pichichi;
    fgol x;
    for(i=0; i<32; i++)
    {
        for(j=0; j<64; j++)
        {
            while (M[i][j]!=NULL)
            {
                x = Pop(M[i][j]);
                //pichichen=/buscaroinsertar(pichichi,x,i);
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
    }

    gol z;
    cout<<"-------GOLEADORES:\n";
    while(pichichi!=NULL)
    {
        z=Popgol(pichichi);
        cout<<z.nombre_jugador<<"  Equipo: "<<z.cod_equipo<<"  Goles: "<<z.id_gol<<" Fecha: "<<z.fecha<<"\n";
    }

    fclose(goles);
}

gol Popgol(listag* &Lista)
{
    gol g;
    listag* p = Lista;
    g.fecha= p->info.fecha;
    g.id_gol= p->info.id_gol;
    strcpy(g.nombre_jugador,p->info.nombre_jugador);
    g.cod_equipo=p->info.cod_equipo;
    Lista = p->sgte;
    delete p;
    return g;
}

fgol Pop(Nodo* &Pila)
{
    fgol y;
    Nodo* p = Pila;
    y.fecha= p->mgol.fecha;
    y.id_gol= p->mgol.id_gol;
    y.cod_equipo= p->mgol.cod_equipo;
    strcpy(y.nombre_jugador,p->mgol.nombre_jugador);
    Pila = p->sgte;
    delete p;
    return y;
}

void GenArchivo (FILE* goles)
{

    int x=1;
    gol rgol;

    while(x==1)
    {
        cout<<"\nIngrese el id del gol: ";
        cin>>rgol.id_gol;
        cout<<"\nIngrese el codigo del equipo: ";
        cin>>rgol.cod_equipo;
        cout<<"\nIngrese la fecha del gol: ";
        cin>>rgol.fecha;
        cin.ignore();
        cout<<"\nIngrese el nombre del jugador: ";
        cin.getline(rgol.nombre_jugador,20);
        cout<<"\nIngrese el id del partido: ";
        cin>>rgol.id_partido;
        fwrite(&rgol,sizeof(gol),1,goles);
        cout<<"\nDesea ingresar otro gol?(1 para SI/0 para NO): ";
        cin>>x;
    }

}

void Mostrar(FILE* goles)
{
    gol rgol;
    fseek(goles,0,SEEK_SET);
    cout << "\n\n------------DATOS DE LOS GOLES---------------";

    while(fread(&rgol,sizeof(gol),1,goles))
    {
        cout << "\n\nId del gol: " << rgol.id_gol << "\n";
        cout << "Codigo de equipo: " << rgol.cod_equipo << "\n";
        cout << "Fecha: " << rgol.fecha << "\n";
        cout << "Nombre del jugador: " << rgol.nombre_jugador << "\n";
        cout << "Id del partido: " << rgol.id_partido << "\n";

    }
}

Nodo* InsertarOrdenado(Nodo*& Lista, fgol x)
{
    Nodo* p = new Nodo();
    p->mgol.fecha = x.fecha;
    p->mgol.id_gol=x.id_gol;
    strcpy(p->mgol.nombre_jugador,x.nombre_jugador);

    if(Lista==NULL || x.id_gol<Lista->mgol.id_gol)
    {
        p->sgte=Lista;
        Lista=p;
        return p;
    }

    Nodo* q = Lista;

    while(q->sgte!=NULL && x.id_gol>q->sgte->mgol.id_gol)
    {
        q=q->sgte;
    }

    p->sgte=q->sgte;
    q->sgte=p;
    return p;
}


listag* InsertarOrdenadoGL(listag*& Lista, fgol &m,int& i)
{
    listag* p = new listag();
    p->info.fecha = m.fecha;
    //p->info.id_gol=m.id_gol;
    p->info.cod_equipo=m.cod_equipo;
    strcpy(p->info.nombre_jugador,m.nombre_jugador);

    if(Lista==NULL || m.fecha<Lista->info.fecha)
    {
        p->sgte=Lista;
        Lista=p;
        return p;
    }

    listag* q = Lista;

    while(q->sgte!=NULL && m.fecha>q->sgte->info.fecha)
    {
        q=q->sgte;
    }

    p->sgte=q->sgte;
    q->sgte=p;
    return p;
}


void CargarMatriz(FILE* goles,Nodo* M[32][64])
{
    gol tgol;
    fgol ffgol;
    int i,j;

    fseek(goles,0,SEEK_SET);

    while (fread(&tgol,sizeof(gol),1,goles))
    {
        i=tgol.cod_equipo;
        j=tgol.id_partido;
        ffgol.fecha=tgol.fecha;
        ffgol.id_gol=tgol.id_gol;
        strcpy(ffgol.nombre_jugador,tgol.nombre_jugador);
        InsertarOrdenado(M[i][j],ffgol);
    }
}

listag*buscaroinsertar(listag*&Lista,fgol &x,int &i){
    char l[20];
    strcpy(l,x.nombre_jugador);
    listag*v=Buscar(Lista,l);
    if(v==NULL)
    {
        v=InsertarOrdenadoGL(Lista,x,i);
        v->info.id_gol=1;
    }
       else{
            v->info.id_gol++;
            return v;
            }
}

listag*Buscar(listag*&Lista,char x[]){
listag*v=Lista;
    while(v!=NULL && strcmp(x,v->info.nombre_jugador)!=0)
    {
        v=v->sgte;
    }
    if(v!=NULL && strcmp(x,v->info.nombre_jugador)==0)
    {
        return v;
    }else{return NULL;}
}
