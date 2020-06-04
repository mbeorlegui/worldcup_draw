#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstring>

using namespace std;

#define CONMEBOL 1
#define UEFA 2
#define CONCACAF 3
#define AFC 4
#define CAF 5
#define USADO 6

struct datos {
    char pais [16];
    int conf;
    int bol;
};

void sorteo (datos[], datos[], datos[], datos[], datos[], datos[], datos[], datos[], datos[], datos[], datos[], datos[]);
void bolilleroUno(void);
void bolilleroDos(void);
void bolilleroTres(void);
void bolilleroCuatro(void);

datos G1[4], G2[4], G3[4], G4[4], G5[4], G6[4], G7[4], G8[4];

datos bol_1[8] = { {"RUSIA",UEFA,1},{"ALEMANIA",UEFA,1},{"BRASIL",CONMEBOL,1},{"PORTUGAL",UEFA,1},
                    {"ARGENTINA",CONMEBOL,1},{"BELGICA", UEFA,1},{"POLONIA",UEFA,1},{"FRANCIA",UEFA,1} };
datos bol_2[8] = { {"ESPANIA",UEFA,2},{"PERU",CONMEBOL,2},{"SUIZA",UEFA,2},{"INGLATERRA",UEFA,2},{"COLOMBIA",CONMEBOL,2},
                    {"MEXICO",CONCACAF,2},{"URUGUAY",CONMEBOL,2},{"CROACIA",UEFA,2} };
datos bol_3[8] = { {"DINAMARCA",UEFA,3},{"ISLANDIA",UEFA,3},{"COSTA RICA",CONCACAF,3},{"SUECIA",UEFA,3},{"TUNEZ",CAF,3},
                    {"EGIPTO",CAF,3},{"SENEGAL",CAF,3},{"IRAN",AFC,3} };
datos bol_4[8] = { {"SERBIA",UEFA,4},{"NIGERIA",CAF,4},{"AUSTRALIA",AFC,4},{"JAPON",AFC,4},{"MARRUECOS",CAF,4},
                    {"PANAMA",CONCACAF,4},{"COREA DEL SUR",AFC,4},{"ARABIA SAUDITA",AFC,4} };

int contadorUEFA[8]={1,0,0,0,0,0,0,0}, contadorAFC[8]={0,0,0,0,0,0,0,0},
    contadorCAF[8]={0,0,0,0,0,0,0,0}, contadorCONCACAF[8]={0,0,0,0,0,0,0,0};
int memoContadorUEFA[8],memoContadorCAF[8],memoContadorAFC[8],memoContadorCONCACAF[8];

int main(){



    srand(time(NULL));

    sorteo(bol_1, bol_2, bol_3, bol_4, G1, G2, G3, G4, G5, G6, G7, G8);

    cout << "GRUPO A: " << G1[0].pais << " " << G1[0].conf << " " << G1[1].pais << " " << G1[1].conf << " " << G1[2].pais << " " << G1[2].conf << " " << G1[3].pais << " " << G1[3].conf << endl;
    cout << "GRUPO B: " << G2[0].pais << " " << G2[0].conf << " " << G2[1].pais << " " << G2[1].conf << " " << G2[2].pais << " " << G2[2].conf << " " << G2[3].pais << " " << G2[3].conf << endl;
    cout << "GRUPO C: " << G3[0].pais << " " << G3[0].conf << " " << G3[1].pais << " " << G3[1].conf << " " << G3[2].pais << " " << G3[2].conf << " " << G3[3].pais << " " << G3[3].conf << endl;
    cout << "GRUPO D: " << G4[0].pais << " " << G4[0].conf << " " << G4[1].pais << " " << G4[1].conf << " " << G4[2].pais << " " << G4[2].conf << " " << G4[3].pais << " " << G4[3].conf << endl;
    cout << "GRUPO E: " << G5[0].pais << " " << G5[0].conf << " " << G5[1].pais << " " << G5[1].conf << " " << G5[2].pais << " " << G5[2].conf << " " << G5[3].pais << " " << G5[3].conf << endl;
    cout << "GRUPO F: " << G6[0].pais << " " << G6[0].conf << " " << G6[1].pais << " " << G6[1].conf << " " << G6[2].pais << " " << G6[2].conf << " " << G6[3].pais << " " << G6[3].conf << endl;
    cout << "GRUPO G: " << G7[0].pais << " " << G7[0].conf << " " << G7[1].pais << " " << G7[1].conf << " " << G7[2].pais << " " << G7[2].conf << " " << G7[3].pais << " " << G7[3].conf << endl;
    cout << "GRUPO H: " << G8[0].pais << " " << G8[0].conf << " " << G8[1].pais << " " << G8[1].conf << " " << G8[2].pais << " " << G8[2].conf << " " << G8[3].pais << " " << G8[3].conf << endl;
    cout << "UEFA GRUPO A: " << contadorUEFA[0] << endl;
    cout << "UEFA GRUPO B: " << contadorUEFA[1] << endl;
    cout << "UEFA GRUPO C: " << contadorUEFA[2] << endl;
    cout << "UEFA GRUPO D: " << contadorUEFA[3] << endl;
    cout << "UEFA GRUPO E: " << contadorUEFA[4] << endl;
    cout << "UEFA GRUPO F: " << contadorUEFA[5] << endl;
    cout << "UEFA GRUPO G: " << contadorUEFA[6] << endl;
    cout << "UEFA GRUPO H: " << contadorUEFA[7] << endl;
    cout << "CONCACAF GRUPO A: " << contadorCONCACAF[0] << endl;
    cout << "CONCACAF GRUPO B: " << contadorCONCACAF[1] << endl;
    cout << "CONCACAF GRUPO C: " << contadorCONCACAF[2] << endl;
    cout << "CONCACAF GRUPO D: " << contadorCONCACAF[3] << endl;
    cout << "CONCACAF GRUPO E: " << contadorCONCACAF[4] << endl;
    cout << "CONCACAF GRUPO F: " << contadorCONCACAF[5] << endl;
    cout << "CONCACAF GRUPO G: " << contadorCONCACAF[6] << endl;
    cout << "CONCACAF GRUPO H: " << contadorCONCACAF[7] << endl;
    cout << "AFC GRUPO A: " << contadorAFC[0] << endl;
    cout << "AFC GRUPO B: " << contadorAFC[1] << endl;
    cout << "AFC GRUPO C: " << contadorAFC[2] << endl;
    cout << "AFC GRUPO D: " << contadorAFC[3] << endl;
    cout << "AFC GRUPO E: " << contadorAFC[4] << endl;
    cout << "AFC GRUPO F: " << contadorAFC[5] << endl;
    cout << "AFC GRUPO G: " << contadorAFC[6] << endl;
    cout << "AFC GRUPO H: " << contadorAFC[7] << endl;
    cout << "CAF GRUPO A: " << contadorCAF[0] << endl;
    cout << "CAF GRUPO B: " << contadorCAF[1] << endl;
    cout << "CAF GRUPO C: " << contadorCAF[2] << endl;
    cout << "CAF GRUPO D: " << contadorCAF[3] << endl;
    cout << "CAF GRUPO E: " << contadorCAF[4] << endl;
    cout << "CAF GRUPO F: " << contadorCAF[5] << endl;
    cout << "CAF GRUPO G: " << contadorCAF[6] << endl;
    cout << "CAF GRUPO H: " << contadorCAF[7] << endl;
}

void sorteo (datos bol_1[], datos bol_2[], datos bol_3[], datos bol_4[], datos G1[], datos G2[],
             datos G3[], datos G4[], datos G5[], datos G6[], datos G7[], datos G8[]){

    bolilleroUno();
    bolilleroDos();
    bolilleroTres();
    bolilleroCuatro();

}


void bolilleroUno(){

    int num, grupo;

    ///DEFINO RUSIA CABEZA DE GRUPO A
    G1[0] = bol_1[0];
    bol_1[0].conf = USADO;

    for(grupo=2;grupo<9;grupo++){
        do{
            num = rand()%(8);
        }while( bol_1[num].conf == USADO );

        if(grupo == 2){
            G2[0] = bol_1[num];
            if(bol_1[num].conf == UEFA){
                contadorUEFA[1]++;
            }
        }if(grupo == 3){
            G3[0] = bol_1[num];
            if(bol_1[num].conf == UEFA){
                contadorUEFA[2]++;
            }
        }if(grupo == 4){
            G4[0] = bol_1[num];
            if(bol_1[num].conf == UEFA){
                contadorUEFA[3]++;
            }
        }if(grupo == 5){
            G5[0] = bol_1[num];
            if(bol_1[num].conf == UEFA){
                contadorUEFA[4]++;
            }
        }if(grupo == 6){
            G6[0] = bol_1[num];
            if(bol_1[num].conf == UEFA){
                contadorUEFA[5]++;
            }
        }if(grupo == 7){
            G7[0] = bol_1[num];
            if(bol_1[num].conf == UEFA){
                contadorUEFA[6]++;
            }
        }if(grupo == 8){
            G8[0] = bol_1[num];
            if(bol_1[num].conf == UEFA){
                contadorUEFA[7]++;
            }
        }
        bol_1[num].conf = USADO;
    }
    ///SORTEO CABEZAS DE GRUPO, O EL BOLILLERO 1
    ///PRIMERO EL GRUPO 1

}

void bolilleroDos(void){
    int num, grupo=1;

    //Sorteo BOLILLERO 2(2dos de los grupos)
    do{
        for(grupo=1;grupo<9;grupo++){

            do{
                num = rand()%8 ;
            }while( bol_2[num].conf == USADO );     ///COMPRUEBA SI EL PAIS YA SE USO EN OTRO GRUPO

            if(grupo == 1){
                G1[1] = bol_2[num];
            }if(grupo == 2){
                G2[1] = bol_2[num];
            }if(grupo == 3){
                G3[1] = bol_2[num];
            }if(grupo == 4){
                G4[1] = bol_2[num];
            }if(grupo == 5){
                G5[1] = bol_2[num];
            }if(grupo == 6){
                G6[1] = bol_2[num];
            }if(grupo == 7){
                G7[1] = bol_2[num];
            }if(grupo == 8){
                G8[1] = bol_2[num];
            }
            bol_2[num].conf = USADO;
        }


        ///REINICIO BOLILLEROS POR SI LOS NECESITO...
        bol_2[0].conf = UEFA;
        bol_2[1].conf = CONMEBOL;
        bol_2[2].conf = UEFA;
        bol_2[3].conf = UEFA;
        bol_2[4].conf = CONMEBOL;
        bol_2[5].conf = CONCACAF;
        bol_2[6].conf = CONMEBOL;
        bol_2[7].conf = UEFA;

    }while((G2[0].conf == CONMEBOL && G2[1].conf == CONMEBOL) || (G3[0].conf == CONMEBOL && G3[1].conf == CONMEBOL)||
           (G4[0].conf == CONMEBOL && G4[1].conf == CONMEBOL) || (G5[0].conf == CONMEBOL && G5[1].conf == CONMEBOL)||
           (G6[0].conf == CONMEBOL && G6[1].conf == CONMEBOL) || (G7[0].conf == CONMEBOL && G7[1].conf == CONMEBOL)||
           (G8[0].conf == CONMEBOL && G8[1].conf == CONMEBOL) );

    if(G1[1].conf == UEFA){
        contadorUEFA[0]++;
    }if(G1[1].conf == CONCACAF){
        contadorCONCACAF[0]++;
    }if(G2[1].conf == UEFA){
        contadorUEFA[1]++;
    }else if(G2[1].conf == CONCACAF){
        contadorCONCACAF[1]++;
    }if(G3[1].conf == UEFA){
        contadorUEFA[2]++;
    }else if(G3[1].conf == CONCACAF){
        contadorCONCACAF[2]++;
    }if(G4[1].conf == UEFA){
        contadorUEFA[3]++;
    }else if(G4[1].conf == CONCACAF){
        contadorCONCACAF[3]++;
    }if(G5[1].conf == UEFA){
        contadorUEFA[4]++;
    }else if(G5[1].conf == CONCACAF){
        contadorCONCACAF[4]++;
    } if(G6[1].conf == UEFA){
        contadorUEFA[5]++;
    }else if(G6[1].conf == CONCACAF){
        contadorCONCACAF[5]++;
    } if(G7[1].conf == UEFA){
        contadorUEFA[6]++;
    }else if(G7[1].conf == CONCACAF){
        contadorCONCACAF[6]++;
    } if(G8[1].conf == UEFA){
        contadorUEFA[7]++;
    }else if(G8[1].conf == CONCACAF){
        contadorCONCACAF[7]++;
    }

}

void bolilleroTres(void){

    int num, grupo=1,i;

    //COPIO EL CONTADOR EN SU MEMORIA, POR SI LO NECESITO
    for( i=0 ; i<8 ; i++ ){
        memoContadorAFC[i] = contadorAFC[i];
    }
    for( i=0 ; i<8 ; i++ ){
        memoContadorCAF[i] = contadorCAF[i];
    }
    for( i=0 ; i<8 ; i++ ){
        memoContadorCONCACAF[i] = contadorCONCACAF[i];
    }
    for( i=0 ; i<8 ; i++ ){
        memoContadorUEFA[i] = contadorUEFA[i];
    }

    //Sorteo BOLILLERO 2(2dos de los grupos)
    do{
        //COPIO MEMORIA DE CONTADOR EN SU CONTADOR ORIGINAR, POR SI LO NECESITO
        for( i=0 ; i<8 ; i++ ){
            contadorAFC[i] = memoContadorAFC[i];
        }
        for( i=0 ; i<8 ; i++ ){
            contadorCAF[i] = memoContadorCAF[i];
        }
        for( i=0 ; i<8 ; i++ ){
            contadorCONCACAF[i] = memoContadorCONCACAF[i];
        }
        for( i=0 ; i<8 ; i++ ){
            contadorUEFA[i] = memoContadorUEFA[i];
        }

        for(grupo=1;grupo<9;grupo++){

            do{
                num = rand()%8 ;
            }while( bol_3[num].conf == USADO );     ///COMPRUEBA SI EL PAIS YA SE USO EN OTRO GRUPO

            if(grupo == 1){
                G1[2] = bol_3[num];
            }if(grupo == 2){
                G2[2] = bol_3[num];
            }if(grupo == 3){
                G3[2] = bol_3[num];
            }if(grupo == 4){
                G4[2] = bol_3[num];
            }if(grupo == 5){
                G5[2] = bol_3[num];
            }if(grupo == 6){
                G6[2] = bol_3[num];
            }if(grupo == 7){
                G7[2] = bol_3[num];
            }if(grupo == 8){
                G8[2] = bol_3[num];
            }
            bol_3[num].conf = USADO;
        }

        ///REINICIO BOLILLEROS POR SI LOS NECESITO...
        bol_3[0].conf = UEFA;
        bol_3[1].conf = UEFA;
        bol_3[2].conf = CONCACAF;
        bol_3[3].conf = UEFA;
        bol_3[4].conf = CAF;
        bol_3[5].conf = CAF;
        bol_3[6].conf = CAF;
        bol_3[7].conf = AFC;

        if(G1[2].conf == UEFA){
            contadorUEFA[0]++;
        }if(G1[2].conf == AFC){
            contadorAFC[0]++;
        }if(G1[2].conf == CONCACAF){
            contadorCONCACAF[0]++;
        }if(G1[2].conf == CAF){
            contadorCAF[0]++;
        }
        if(G2[2].conf == UEFA){
            contadorUEFA[1]++;
        }if(G2[2].conf == CONCACAF){
            contadorCONCACAF[1]++;
        }if(G2[2].conf == AFC){
            contadorAFC[1]++;
        }if(G2[2].conf == CAF){
            contadorCAF[1]++;
        }
        if(G3[2].conf == UEFA){
            contadorUEFA[2]++;
        }if(G3[2].conf == CAF){
            contadorCAF[2]++;
        }if(G3[2].conf == CONCACAF){
            contadorCONCACAF[2]++;
        }if(G3[2].conf == AFC){
            contadorAFC[2]++;
        }
        if(G4[2].conf == UEFA){
            contadorUEFA[3]++;
        }if(G4[2].conf == CONCACAF){
            contadorCONCACAF[3]++;
        }if(G4[2].conf == AFC){
            contadorAFC[3]++;
        }if(G4[2].conf == CAF){
            contadorCAF[3]++;
        }
        if(G5[2].conf == UEFA){
            contadorUEFA[4]++;
        }if(G5[2].conf == CONCACAF){
            contadorCONCACAF[4]++;
        }if(G5[2].conf == AFC){
            contadorAFC[4]++;
        }if(G5[2].conf == CAF){
            contadorCAF[4]++;
        }
        if(G6[2].conf == UEFA){
            contadorUEFA[5]++;
        }if(G6[2].conf == CONCACAF){
            contadorCONCACAF[5]++;
        }if(G6[2].conf == AFC){
            contadorAFC[5]++;
        }if(G6[2].conf == CAF){
            contadorCAF[5]++;
        }
        if(G7[2].conf == UEFA){
            contadorUEFA[6]++;
        }if(G7[2].conf == CONCACAF){
            contadorCONCACAF[6]++;
        }if(G7[2].conf == AFC){
            contadorAFC[6]++;
        }if(G7[2].conf == CAF){
            contadorCAF[6]++;
        }
        if(G8[2].conf == UEFA){
            contadorUEFA[7]++;
        }if(G8[2].conf == CONCACAF){
            contadorCONCACAF[7]++;
        }if(G8[2].conf == AFC){
            contadorAFC[7]++;
        }if(G8[2].conf == CAF){
            contadorCAF[7]++;
        }

    }while((contadorUEFA[0]>2) || (contadorAFC[0]>1) || (contadorCAF[0]>1) || (contadorCONCACAF[0]>1) ||
           (contadorUEFA[1]>2) || (contadorAFC[1]>1) || (contadorCAF[1]>1) || (contadorCONCACAF[1]>1) ||
           (contadorUEFA[2]>2) || (contadorAFC[2]>1) || (contadorCAF[2]>1) || (contadorCONCACAF[2]>1) ||
           (contadorUEFA[3]>2) || (contadorAFC[3]>1) || (contadorCAF[3]>1) || (contadorCONCACAF[3]>1) ||
           (contadorUEFA[4]>2) || (contadorAFC[4]>1) || (contadorCAF[4]>1) || (contadorCONCACAF[4]>1) ||
           (contadorUEFA[5]>2) || (contadorAFC[5]>1) || (contadorCAF[5]>1) || (contadorCONCACAF[5]>1) ||
           (contadorUEFA[6]>2) || (contadorAFC[6]>1) || (contadorCAF[6]>1) || (contadorCONCACAF[6]>1) ||
           (contadorUEFA[7]>2) || (contadorAFC[7]>1) || (contadorCAF[7]>1) || (contadorCONCACAF[7]>1) );
    ///CONDICION PARA VOLVER A SORTEAR, EN CASO DE QUE NO SE CUMPLAN LAS CONDICIONES PEDIDAS
}

void bolilleroCuatro(void){

    int num, grupo=1,i;

    //COPIO EL CONTADOR EN SU MEMORIA, POR SI LO NECESITO
    for( i=0 ; i<8 ; i++ ){
        memoContadorAFC[i] = contadorAFC[i];
    }
    for( i=0 ; i<8 ; i++ ){
        memoContadorCAF[i] = contadorCAF[i];
    }
    for( i=0 ; i<8 ; i++ ){
        memoContadorCONCACAF[i] = contadorCONCACAF[i];
    }
    for( i=0 ; i<8 ; i++ ){
        memoContadorUEFA[i] = contadorUEFA[i];
    }

    //Sorteo BOLILLERO 2(2dos de los grupos)
    do{
        //COPIO MEMORIA DE CONTADOR EN SU CONTADOR ORIGINAR, POR SI LO NECESITO
        for( i=0 ; i<8 ; i++ ){
            contadorAFC[i] = memoContadorAFC[i];
        }
        for( i=0 ; i<8 ; i++ ){
            contadorCAF[i] = memoContadorCAF[i];
        }
        for( i=0 ; i<8 ; i++ ){
            contadorCONCACAF[i] = memoContadorCONCACAF[i];
        }
        for( i=0 ; i<8 ; i++ ){
            contadorUEFA[i] = memoContadorUEFA[i];
        }

        for(grupo=1;grupo<9;grupo++){

            do{
                num = rand()%8 ;
            }while( bol_4[num].conf == USADO );     ///COMPRUEBA SI EL PAIS YA SE USO EN OTRO GRUPO

            if(grupo == 1){
                G1[3] = bol_4[num];
            }if(grupo == 2){
                G2[3] = bol_4[num];
            }if(grupo == 3){
                G3[3] = bol_4[num];
            }if(grupo == 4){
                G4[3] = bol_4[num];
            }if(grupo == 5){
                G5[3] = bol_4[num];
            }if(grupo == 6){
                G6[3] = bol_4[num];
            }if(grupo == 7){
                G7[3] = bol_4[num];
            }if(grupo == 8){
                G8[3] = bol_4[num];
            }
            bol_4[num].conf = USADO;
        }

        ///REINICIO BOLILLEROS POR SI LOS NECESITO...
        bol_4[0].conf = UEFA;
        bol_4[1].conf = CAF;
        bol_4[2].conf = AFC;
        bol_4[3].conf = AFC;
        bol_4[4].conf = CAF;
        bol_4[5].conf = CONCACAF;
        bol_4[6].conf = AFC;
        bol_4[7].conf = AFC;

        if(G1[3].conf == UEFA){
            contadorUEFA[0]++;
        }if(G1[3].conf == AFC){
            contadorAFC[0]++;
        }if(G1[3].conf == CONCACAF){
            contadorCONCACAF[0]++;
        }if(G1[3].conf == CAF){
            contadorCAF[0]++;
        }
        if(G2[3].conf == UEFA){
            contadorUEFA[1]++;
        }if(G2[3].conf == CONCACAF){
            contadorCONCACAF[1]++;
        }if(G2[3].conf == AFC){
            contadorAFC[1]++;
        }if(G2[3].conf == CAF){
            contadorCAF[1]++;
        }
        if(G3[3].conf == UEFA){
            contadorUEFA[2]++;
        }if(G3[3].conf == CAF){
            contadorCAF[2]++;
        }if(G3[3].conf == CONCACAF){
            contadorCONCACAF[2]++;
        }if(G3[3].conf == AFC){
            contadorAFC[2]++;
        }
        if(G4[3].conf == UEFA){
            contadorUEFA[3]++;
        }if(G4[3].conf == CONCACAF){
            contadorCONCACAF[3]++;
        }if(G4[3].conf == AFC){
            contadorAFC[3]++;
        }if(G4[3].conf == CAF){
            contadorCAF[3]++;
        }
        if(G5[3].conf == UEFA){
            contadorUEFA[4]++;
        }if(G5[3].conf == CONCACAF){
            contadorCONCACAF[4]++;
        }if(G5[3].conf == AFC){
            contadorAFC[4]++;
        }if(G5[3].conf == CAF){
            contadorCAF[4]++;
        }
        if(G6[3].conf == UEFA){
            contadorUEFA[5]++;
        }if(G6[3].conf == CONCACAF){
            contadorCONCACAF[5]++;
        }if(G6[3].conf == AFC){
            contadorAFC[5]++;
        }if(G6[3].conf == CAF){
            contadorCAF[5]++;
        }
        if(G7[3].conf == UEFA){
            contadorUEFA[6]++;
        }if(G7[3].conf == CONCACAF){
            contadorCONCACAF[6]++;
        }if(G7[3].conf == AFC){
            contadorAFC[6]++;
        }if(G7[3].conf == CAF){
            contadorCAF[6]++;
        }
        if(G8[3].conf == UEFA){
            contadorUEFA[7]++;
        }if(G8[3].conf == CONCACAF){
            contadorCONCACAF[7]++;
        }if(G8[3].conf == AFC){
            contadorAFC[7]++;
        }if(G8[3].conf == CAF){
            contadorCAF[7]++;
        }

    }while((contadorUEFA[0]>2) || (contadorAFC[0]>1) || (contadorCAF[0]>1) || (contadorCONCACAF[0]>1) ||
           (contadorUEFA[1]>2) || (contadorAFC[1]>1) || (contadorCAF[1]>1) || (contadorCONCACAF[1]>1) ||
           (contadorUEFA[2]>2) || (contadorAFC[2]>1) || (contadorCAF[2]>1) || (contadorCONCACAF[2]>1) ||
           (contadorUEFA[3]>2) || (contadorAFC[3]>1) || (contadorCAF[3]>1) || (contadorCONCACAF[3]>1) ||
           (contadorUEFA[4]>2) || (contadorAFC[4]>1) || (contadorCAF[4]>1) || (contadorCONCACAF[4]>1) ||
           (contadorUEFA[5]>2) || (contadorAFC[5]>1) || (contadorCAF[5]>1) || (contadorCONCACAF[5]>1) ||
           (contadorUEFA[6]>2) || (contadorAFC[6]>1) || (contadorCAF[6]>1) || (contadorCONCACAF[6]>1) ||
           (contadorUEFA[7]>2) || (contadorAFC[7]>1) || (contadorCAF[7]>1) || (contadorCONCACAF[7]>1) );
    ///CONDICION PARA VOLVER A SORTEAR, EN CASO DE QUE NO SE CUMPLAN LAS CONDICIONES PEDIDAS

}

