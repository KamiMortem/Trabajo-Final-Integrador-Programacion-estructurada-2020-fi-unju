#include<iostream>
#include <cstring>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

using namespace std;

//variables mas
typedef char tcad[30];

/** Numero de jugadores ingresados **/
int numJugador=-1;
int jugador1=-1;
int jugador2=-1;
int puntajeMax[] = {-1,0};


typedef struct tJugador{
    tcad nombre;
    tcad apellido;
    tcad apodo;
    int puntaje=0;
    int noPrimoNiCapicua=0;
    bool activo=false;
    bool numCasillero[9][9];
};
tJugador jugador[49];

typedef struct tCasillero{
    int valor;
    bool numPrimo;
    bool numCapicua;
    bool diagonalPrin;
    bool numAmigo;
    bool numPerfecto;
};

typedef struct tTablero{
    tCasillero casilla[10][10];
    int numeroDorado=0;
};
tTablero tablero;


//fuciones procedimientos --------

 bool capicua(int num) {

    if(num<10){
 		return true;
	}else{
		int a=num;
        int c=0;
		int b=0;

		while(a!=0)
		{
			b=a%10;
			a=a/10;
			c=c*10+b;
		}
		if(c==num)
			return true;
		else
			return false;
    }
 }

 void divisores(int numero, int &cont, int divisor[100]){
    int resto;
    cont=0;
		for (int i=1; i<=numero ; i++){
			resto = numero%i;
			if (resto==0)
				{
				divisor[cont]=i;
				cont=cont+1;
				}
        }
 }

 bool numAmigo(int numero){
    int cont;
    int divisor[100];
    int numAmi=0;
    int numAmi2=0;
    divisores(numero,cont,divisor);

    for(int i=0;i<cont-1;i++){
        numAmi= divisor[i]+numAmi;
    }

    divisores(numAmi,cont,divisor);

    for(int j=0;j<cont-1;j++){
        numAmi2 = divisor[j]+numAmi2;
    }

    if(numero==numAmi2){
        return true;
    }else{
        return false;
    }
 }

 bool numPerfecto(int numero){
    int cont;
    int divisor[100];
    int numAmi=0;
    int numAmi2=0;
    divisores(numero,cont,divisor);

    for(int i=0;i<cont-1;i++){
        numAmi= divisor[i]+numAmi;
    }

    divisores(numAmi,cont,divisor);

    for(int j=0;j<cont-1;j++){
        numAmi2 = divisor[j]+numAmi2;
    }

    if(numero==numAmi2){
        if(numAmi==numAmi2){
            return true;
        }
        return false;
    }else{
        return false;
    }
 }

 bool primo(int numero) {
 	bool band;

 	for(int i=2;i<=numero;i++){
 		band=false;
 		for(int j = 2 ;j<i; j++){
 			if(i % j == 0){
 				band=true;
			 }
		 }
	 }
	 if(band==false){
        return true;
     }else
        return false;
 }

 // ---------------------
 // ---------------------

 void mostrarTablero(){
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            cout<<i<<" "<<j<<" :"<<tablero.casilla[i][j].valor<<endl;
        }
    }
    cout<<"-----Comprobaciones-------"<<endl;
    if(primo(1279)){
        cout<<"es primo"<<"   1279 "<<endl;
    }else{
        cout<<"NO primo "<<"   1279 "<<endl;
    }
    if(numAmigo(220)){
            cout<<"es amigo"<<"   220 "<<endl;
    }else{
        cout<<"NO amigo "<<"   220 "<<endl;
    }
    if(numPerfecto(28)){
            cout<<"es Perfecto"<<"   28 "<<endl;
    }else{
        cout<<"NO Perfecto "<<"   28 "<<endl;
    }
    if(capicua(2002)){
            cout<<"es capicua"<<"   2002 "<<endl;
    }else{
        cout<<"NO capicua "<<"   2002 "<<endl;
    }

    if(primo(24)){
        cout<<"es primo"<<"   24 "<<endl;
    }else{
        cout<<"NO primo "<<"   24 "<<endl;
    }
    if(numAmigo(221)){
            cout<<"es amigo"<<"   221 "<<endl;
    }else{
        cout<<"NO amigo "<<"   221 "<<endl;
    }
    if(numPerfecto(29)){
            cout<<"es Perfecto"<<"   29 "<<endl;
    }else{
        cout<<"NO Perfecto "<<"   29 "<<endl;
    }
    if(capicua(2003)){
            cout<<"es capicua"<<"   2003 "<<endl<<endl;
    }else{
        cout<<"NO capicua "<<"   2003 "<<endl<<endl;
    }
 }

 int puntajeDorado(){
    int num,sumPrimo=0,sumCapicua=0,sumPrimoCapicua=0;

    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(tablero.casilla[i][j].numPrimo){
                sumPrimo=sumPrimo+tablero.casilla[i][j].valor;
            }
            if(tablero.casilla[i][j].numCapicua){
                sumCapicua=sumCapicua+tablero.casilla[i][j].valor;
            }
            if(tablero.casilla[i][j].numCapicua && tablero.casilla[i][j].numPrimo){
                sumPrimoCapicua=sumPrimoCapicua+tablero.casilla[i][j].valor;
            }
        }
    }
    num=sumPrimo*0.2+sumCapicua*0.3+sumPrimoCapicua*0.5;

    return num;
 }

 bool comprobarNumerosTabla(int numE){
    bool band=false;

    for(int i=0; i<=9; i++){
        for(int j=0; j<=9; j++){
            if(tablero.casilla[i][j].valor == numE){
                band=true;
            }
        }
    }
    return band;
 }

 void generarTablero(){
    int numRandom;
    srand(time(NULL));

    system("cls");
    cout<<"Generando tablero..."<<endl;

    for(int a=0; a<=10; a++){
        for(int b=0; b<=10; b++){
            tablero.casilla[a][b].valor=0;
        }
    }

    for(int i=0; i<=10; i++){
        for(int j=0; j<=10; j++){
            if(i==0 && j==0){
                do{
                    numRandom = rand()%(10000-1);
                }while(numRandom==0);
                tablero.casilla[0][0].valor = numRandom;
                if(capicua(numRandom)){
                    tablero.casilla[0][0].numCapicua=true;
                }else{
                    tablero.casilla[0][0].numCapicua=false;
                }
                if(primo(numRandom)){
                    tablero.casilla[0][0].numPrimo=true;
                }else{
                    tablero.casilla[0][0].numPrimo=false;
                }
                tablero.casilla[0][0].diagonalPrin=true;
                if(numAmigo(numRandom)){
                    tablero.casilla[0][0].numAmigo=true;
                }else{
                    tablero.casilla[0][0].numAmigo=false;
                }
                if(numPerfecto(numRandom)){
                    tablero.casilla[0][0].numPerfecto=true;
                }else{
                    tablero.casilla[0][0].numPerfecto=false;
                }
            }else{
                do{
                    numRandom = rand()%(10000-1);
                }while(comprobarNumerosTabla(numRandom)==true);
                tablero.casilla[i][j].valor = numRandom;
                if(capicua(numRandom)){
                    tablero.casilla[i][j].numCapicua=true;
                }else{
                    tablero.casilla[i][j].numCapicua=false;
                }
                if(primo(numRandom)){
                    tablero.casilla[i][j].numPrimo=true;
                }else{
                    tablero.casilla[i][j].numPrimo=false;
                }
                if(i==j){
                    tablero.casilla[i][j].diagonalPrin=true;
                }else{
                    tablero.casilla[i][j].diagonalPrin=false;
                }
                if(numAmigo(numRandom)){
                    tablero.casilla[i][j].numAmigo=true;
                }else{
                    tablero.casilla[i][j].numAmigo=false;
                }
                if(numPerfecto(numRandom)){
                    tablero.casilla[i][j].numPerfecto=true;
                }else{
                    tablero.casilla[i][j].numPerfecto=false;
                }
            }
        }
    }
    //puntaje dorado
    tablero.numeroDorado=puntajeDorado();

    //mostrarTablero();
    cout<<"TABLERO GENERADO..."<<endl;
 }

 /** ordena los jugadores de orden creciente por apellido **/
 void ordenarJugadores(){
    bool band;
    tcad apellido;
    tcad nombre;
    tcad apodo;

    for(int i=numJugador;i>0;i--){
        while(strcmp(jugador[i-1].apellido,jugador[i].apellido)>0){
            strcpy(apellido,jugador[i-1].apellido);
            strcpy(nombre,jugador[i-1].nombre);
            strcpy(apodo,jugador[i-1].apodo);

            strcpy(jugador[i-1].apellido,jugador[i].apellido);
            strcpy(jugador[i-1].nombre,jugador[i].nombre);
            strcpy(jugador[i-1].apodo,jugador[i].apodo);

            strcpy(jugador[i].apellido,apellido);
            strcpy(jugador[i].nombre,nombre);
            strcpy(jugador[i].apodo,apodo);
        }
    }
 }

 /** Comprueba si el jugador ya fue ingresado **/
 bool jugadorYaRegistrado(tcad apodo,tcad nombre,tcad apellido){
    bool band=false;

    if(numJugador>=0){
        for(int i=0;i<=numJugador;i++){
            if(strcmp(jugador[i].apodo,apodo)==0){
                band=true;
            }
            if(strcmp(jugador[i].apellido,apellido)==0){
                if(strcmp(jugador[i].apellido,apellido)==0){
                    band=true;
                }
            }
        }
    }else{
        band=false;
    }

 return band;
 }

 void registrarJugador(){
    int a;
    tcad nombre;
    tcad apellido;
    tcad apodo;

    do{
        cout<<"Ingrese el nombre del jugador:"<<endl;
        cin>>nombre;
        cout<<"Ingrese el apellido del jugador:"<<endl;
        cin>>apellido;
        cout<<"Ingrese el apodo"<<endl;
        cin>>apodo;
        if(jugadorYaRegistrado(apodo,nombre,apellido)){
            cout<<"Error, ya ingresado"<<endl;
        }
    }while(jugadorYaRegistrado(apodo,nombre,apellido));
    numJugador=numJugador+1;
    strcpy(jugador[numJugador].nombre,nombre);
    strcpy(jugador[numJugador].apellido,apellido);
    strcpy(jugador[numJugador].apodo,apodo);
    if(numJugador>0){
        ordenarJugadores();
    }
 }

 /** Muestra todos los jugadores alguna vezz ingresados **/
 void listarJugadores(){

    if(numJugador>=0){
        for(int i=0;i<=numJugador;i++){
            cout<<"----------------------"<<endl;
            cout<<"Apellido: "<<jugador[i].apellido<<endl;
            cout<<"Nombre: "<<jugador[i].nombre<<endl;
            cout<<"Apodo: "<<jugador[i].apodo<<endl;
            cout<<"----------------------"<<endl<<endl;
        }
    }else{
        cout<<"NO HAY JUGADORES"<<endl;
    }
 }

 // ---------------------

 /** selecciona los jugadores con los cuales se jugara esta partida **/
 void seleccionarJugadores(){
    tcad apodo;
    int pos1;
    bool band=true;
    if(numJugador>=1){
        for(int j=0;j<=numJugador;j++){
            jugador[j].activo=false;
        }
        do{
            cout<<"Ingrese el apodo del 1er jugador: "<<endl;
            cin>>apodo;

            for(int i=0;i<=numJugador;i++){
                if(strcmp(jugador[i].apodo,apodo)==0){
                    jugador[i].activo=true;
                    band=false;
                    pos1=i;
                    jugador1=i;
                }
            }
        }while(band);

        band=true;
        do{
            cout<<"Ingrese el apodo del 2do jugador: "<<endl;
            cin>>apodo;

            for(int i=0;i<=numJugador;i++){
                if(strcmp(jugador[i].apodo,apodo)==0 && strcmp(jugador[pos1].apodo,apodo)!=0){
                    jugador[i].activo=true;
                    band=false;
                    jugador2=i;
                }
            }
        }while(band);
    }else{
        cout<<"Numero de jugadores insuficientes..."<<endl;
    }
 }

 void lanzandoD(int jugadore1,int jugadore2){
    bool band1,bandTaF;
    int dado1, dado2;
    int posI,posJ;
    int contEspecial=0;
    srand(time(NULL));

        do{
            cout<<"------------------------------"<<endl;
            cout<<"Jugador: "<<jugador[jugadore1].apodo<<endl;
            dado1=1 + rand() % (11 - 1);
            dado2=1 + rand() % (11 - 1);
            cout<<"dado 1: "<<dado1<<" , dado 2: "<<dado2<<" .Suma: "<<dado1+dado2<<endl;

            posI=dado1-1;
            posJ=dado2-1;

            band1=true;
            if(jugador[jugadore2].numCasillero[posI][posJ]==false){

                jugador[jugadore1].numCasillero[posI][posJ]=true;
                bandTaF=true;
                for(int i=9; i>=0; i--){
                    for(int j=9; j>=0; j--){
                        if(bandTaF && jugador[jugadore1].numCasillero[i][j]==true){
                            bandTaF=false;
                        }else{
                            jugador[jugadore1].numCasillero[i][j]=false;
                        }
                    }
                }

                if(contEspecial>0){
                    band1=true;
                    contEspecial=contEspecial-1;
                }else{
                    band1=false;
                }

                cout<<"Numero encontrado: "<<tablero.casilla[posI][posJ].valor;
                if(tablero.casilla[posI][posJ].numCapicua){
                    cout<<" (capicua) ";
                }
                if(tablero.casilla[posI][posJ].numPrimo){
                    cout<<" (primo) ";
                }
                if(tablero.casilla[posI][posJ].diagonalPrin){
                    cout<<" (diagonal principal) "<<endl;
                }
                if(tablero.casilla[posI][posJ].numAmigo){
                    contEspecial=contEspecial+1;
                }
                if(tablero.casilla[posI][posJ].numPerfecto){
                    contEspecial=contEspecial+2;
                }

                if(tablero.casilla[posI][posJ].numCapicua || tablero.casilla[posI][posJ].numPrimo || tablero.casilla[posI][posJ].diagonalPrin){
                    if(tablero.casilla[posI][posJ].numPrimo && tablero.casilla[posI][posJ].numCapicua && tablero.casilla[posI][posJ].diagonalPrin){
                        jugador[jugadore1].puntaje=jugador[jugadore1].puntaje+(tablero.casilla[posI][posJ].valor)*4;
                    }else{
                        if(tablero.casilla[posI][posJ].numPrimo && tablero.casilla[posI][posJ].numCapicua){
                            jugador[jugadore1].puntaje=jugador[jugadore1].puntaje+(tablero.casilla[posI][posJ].valor)*3;
                        }else{
                            if(tablero.casilla[posI][posJ].diagonalPrin){
                                jugador[jugadore1].puntaje=jugador[jugadore1].puntaje+(tablero.casilla[posI][posJ].valor)*2;
                            }else{
                                jugador[jugadore1].puntaje=jugador[jugadore1].puntaje+tablero.casilla[posI][posJ].valor;
                            }
                        }
                    }
                }
                cout<<" Puntaje: "<<jugador[jugadore1].puntaje<<endl;

                if(tablero.casilla[posI][posJ].numCapicua==false && tablero.casilla[posI][posJ].numPrimo == false && tablero.casilla[posI][posJ].diagonalPrin==false){
                    jugador[jugadore1].noPrimoNiCapicua=jugador[jugadore1].noPrimoNiCapicua+1;
                    if(jugador[jugadore1].noPrimoNiCapicua==3){
                        jugador[jugadore1].noPrimoNiCapicua=0;
                        jugador[jugadore1].puntaje=jugador[jugadore1].puntaje-10;
                        cout<<"Se le restaron 10 puntos por no conseguir puntaje en 3 turnos..."<<endl;
                        cout<<"Puntaje: "<<jugador[jugadore1].puntaje<<endl;
                    }else{
                        cout<<"No gano puntos este turno, en "<<3-jugador[jugadore1].noPrimoNiCapicua<<" turno(s), perdera 10 puntos."<<endl;
                    }

                }else{
                    jugador[jugadore1].noPrimoNiCapicua=0;
                }
                if(puntajeMax[1]<jugador[jugadore1].puntaje){
                    puntajeMax[1]=jugador[jugadore1].puntaje;
                    puntajeMax[0]=jugadore1;
                }

            }else{
                cout<<"Casillero OCUPADO. Volviendo a tirar..."<<endl<<endl;
                system("PAUSE");
            }
            cout<<"------------------------------"<<endl<<endl;
        }while(band1);

 }

 /** los jugadores se alternan para lanzar los dados
    mostrando los dados, el puntaje y el numero encontrado **/
 void lanzamientoDeDados(){
    int jugadore1=jugador1,jugadore2=jugador2;

    if(jugador1>=0 && jugadore2>=0){
        for(int i=0; i<=9; i++){
            for(int j=0; j<=9; j++){
                jugador[jugador1].numCasillero[i][j]=false;
                jugador[jugador2].numCasillero[i][j]=false;
            }
        }
        cout<<"-----Numero Dorado-------"<<endl;
        cout<<"es: "<<tablero.numeroDorado<<endl;
        do{
            lanzandoD( jugadore1, jugadore2);
            system("PAUSE");
            lanzandoD( jugadore2, jugadore1);
            system("PAUSE");
        }while(puntajeMax[1]<tablero.numeroDorado);
        cout<<"YA HAY UN GANADOR..."<<endl;
        system("PAUSE");
        system("cls");
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"Gano: "<<jugador[puntajeMax[0]].apellido<<" "<<jugador[puntajeMax[0]].nombre<<", como le dicen: "<<jugador[puntajeMax[0]].apodo<<endl;
        cout<<"Gano con: "<<puntajeMax[1]<<" "<<endl;
        cout<<"--------------------------------------------------------"<<endl;

        jugador[jugador1].puntaje=0;
        jugador[jugador2].puntaje=0;

        jugador[jugador1].activo=false;
        jugador[jugador2].activo=false;

        puntajeMax[1]=0;
        puntajeMax[0]=-1;

    }else{
        cout<<"PRIMERO INGRESE LOS JUGADORES"<<endl<<endl;
    }
 }

 // ---------------------
 // ---------------------

 void menuJugarOP(int op1){
    switch (op1){
    case 1:
        seleccionarJugadores();
        break;
    case 2:
        lanzamientoDeDados();
        break;
    case 3:
        cout<<"Volviendo al menu principal..."<<endl<<endl;
        break;
    default:
        cout<<"Opcion invalida, ingrese nuevamente..."<<endl<<endl;
        break;
    }
 }

 void menuJugar(){
    int op1;

    if(numJugador>=1 && tablero.numeroDorado!=0){
        do{
            cout<<"--------------------------"<<endl;
            cout<<"---- COMIENZA LA AVENTURA ----"<<endl;
            cout<<"1- Seleccionar jugadores "<<endl;
            cout<<"2- Lanzar dados"<<endl;
            cout<<"3- Salir"<<endl;
            cout<<"Elija una opcion: ";
            cin>>op1;
            system("cls");
            menuJugarOP(op1);
        }while(op1!=3);
    }else{
        if(numJugador<1){
            cout<<"faltan jugadores..."<<endl;
        }else{
            cout<<"falta generar tablero..."<<endl;
        }

    }

 }

 void menuPrincipal(int op){
    switch (op){
    case 1:
        generarTablero();
        break;
    case 2:
        registrarJugador();
        break;
    case 3:
        listarJugadores();
        break;
    case 4:
        menuJugar();
        break;
    case 5:
        cout<<"saliendo..."<<endl;
        break;
    default:
        cout<<"Opcion invalida, ingrese nuevamente..."<<endl<<endl;
        break;
    }
 }

//main (principal) -------
 main(){
    int op;

    do{
        cout<<"------------------------"<<endl;
        cout<<"---- Menu Principal ----"<<endl;
        cout<<"1- Generar tablero "<<endl;
        cout<<"2- Registrar jugador"<<endl;
        cout<<"3- Listar jugadores"<<endl;
        cout<<"4- Jugar"<<endl;
        cout<<"5- Salir"<<endl;
        cout<<"Elija una opcion: ";
        cin>>op;
        system("cls");
        menuPrincipal(op);
    }while(op!=5);

    cout<<"Muchas gracias por jugar!"<<endl;
    system("PAUSE");
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"Juego realizado por Emilio Jesus Calderon, LU:3840, DNI:41750208"<<endl;
    cout<<"Facultad de Ingenieria - UNJu - Programacion estructurada 2020"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    system("PAUSE");
 }
