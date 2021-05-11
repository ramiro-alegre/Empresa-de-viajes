#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <ctime>
using namespace std;

#define ABAJO 80
#define ARRIBA 72
#define ENTER 13

#include "menus.h"
#include "choferes.h"
#include "viajes.h"
#include "configuracion.h"
#include "rlutil.h"

void MenuPrincipal() {

	int opc;

	do {

		system("cls");
		recuadro();
		rlutil::locate(50, 16); cout << "*** MENU PRINCIPAL ***" << endl;
		rlutil::locate(50, 17); cout << "---------------" << endl;
		rlutil::locate(50, 18); cout << "1) CHOFERES" << endl;
		rlutil::locate(50, 19); cout << "2) VIAJES " << endl;
		rlutil::locate(50, 20); cout << "3) REPORTES" << endl;
		rlutil::locate(50, 21); cout << "4) CONFIGURACION" << endl;
		rlutil::locate(50, 22); cout << "0) SALIR DEL PROGRAMA" << endl;

		opc = elegirOpcion(49,18,22);

		switch (opc)

		{
		case 18:
			system("cls");
			MenuChoferes();
			;

			break;

		case 19:

			system("cls");
			MenuViajes();

			break;

		case 20:

			system("cls");
			MenuReportes();

			break;

		case 21:;
			system("cls");
			MenuConfiguracion();

			break;
		}


	} while (opc != 22);


}







void MenuChoferes() {

	int opc = 0;

	do {

		system("cls");
		recuadro();
		rlutil::locate(50, 16);cout << "*** MENU CHOFERES ***" << endl;
		rlutil::locate(50, 17);cout << "---------------" << endl;
		rlutil::locate(50, 18);cout << "1) NUEVO CHOFER" << endl;
		rlutil::locate(50, 19);cout << "2) MODIFICAR CHOFER " << endl;
		rlutil::locate(50, 20);cout << "3) LISTAR CHOFER POR DNI" << endl;
		rlutil::locate(50, 21);cout << "4) LISTAR TODOS LOS CHOFERES" << endl;
		rlutil::locate(50, 22);cout << "5) ELIMINAR CHOFER POR DNI" << endl;
		rlutil::locate(50, 23);cout << "0) VOLVER AL MENU PRINCIPAL" << endl;
		int x=49, y=18;
		opc = elegirOpcion(x, y, 23);


		switch (opc)

		{
		case 18:

			system("cls");

			altaChofer();


			break;

		case 19:
			system("cls");

			ModificarFechaVto();

			break;

		case 20:


			char dni[10];
			system("cls");
			cout << "INGRESE EL DNI:  " << endl;
			cin >> dni;
			MostrarChoferPorDni(dni);
			system("cls");

			break;

		case 21:

			listarChoferes();



			break;

		case 22:

		     bajaChofer();

			  system("pause");

			break;
		}

	} while (opc != 23);

}


void MenuViajes() {

	int opc = 0;

	do {

		system("cls");

		recuadro();

		rlutil::locate(50, 16); cout << "*** MENU VIAJES ***" << endl;
		rlutil::locate(50, 17); cout << "---------------" << endl;
		rlutil::locate(50, 18); cout << "1) NUEVO VIAJE" << endl;
		rlutil::locate(50, 19); cout << "2) LISTAR VIAJE POR ID DE VIAJE" << endl;
		rlutil::locate(50, 20); cout << "3) LISTAR TODOS LOS VIAJES " << endl;
		rlutil::locate(50, 21); cout << "4) ELIMINAR VIAJE" << endl;
		rlutil::locate(50, 22); cout << "0) VOLVER AL MENU PRINCIPAL" << endl;



		opc=elegirOpcion(49,18,22);


		switch (opc)

		{
		case 18:
			system("cls");
			altaViaje();


			break;

		case 19:
			MostrarViajePorIDviaje();
			system("pause");
			break;

		case 20:
			system("cls");
			listarViajes();
			system("pause");

			break;

		case 21:

			system("cls");
			bajaViaje();


			break;
		}

	}while (opc != 22);
}


void MenuReportes() {

	int opc = 0;

	do {


		system("cls");

		recuadro();

		rlutil::locate(50, 16); cout << "*** MENU REPORTES ***" << endl;
		rlutil::locate(50, 17); cout << "---------------" << endl;
		rlutil::locate(50, 18); cout << "1) REPORTE 1" << endl;
		rlutil::locate(50, 19); cout << "2) REPORTE 2" << endl;
		rlutil::locate(50, 20); cout << "3) REPORTE 3 " << endl;
		rlutil::locate(50, 21); cout << "0) VOLVER AL MENÚ PRINCIPAL" << endl;


		opc = elegirOpcion(49, 18, 21);


		switch (opc)

		{
		case 18:

			system("cls");

			;

			break;

		case 19:;

			break;

		case 20:;

			break;

		}

	} while (opc != 21);
}



void MenuConfiguracion() {

	int opc = 0;
	bool confirmarChoferes,confirmarViajes;
	do {

		system("cls");

		recuadro();

		rlutil::locate(50, 16);cout << "*** MENU CONFIGURACION ***" << endl;
		rlutil::locate(50, 17);cout << "---------------" << endl;
		rlutil::locate(50, 18);cout << "1) REALIZAR BACKUP " << endl;
		rlutil::locate(50, 19);cout << "2) RESTAURAR BACKUP " << endl;
		rlutil::locate(50, 20);cout << "3) CARGAR DATOS DE INICIO " << endl;
		rlutil::locate(50, 21);cout << "0) VOLVER AL MENU PRINCIPAL" << endl;



		opc = elegirOpcion(49, 18, 21);

		switch (opc)

		{
		case 18:

			system("cls");
			confirmarChoferes=BackUpChoferes();
			confirmarViajes=BackUpViajes();
			if(confirmarChoferes==true && confirmarViajes==true){
				cout << "El BackUp se ha realizado correctamente!"<<endl;
				system("pause");
			}
			else { cout << "El BackUp no se ha realizado correctamente!" << endl;
			system("pause");}


			break;

		case 19:

			system("cls");
			confirmarChoferes=RestaurarChoferes();
			confirmarViajes=RestaurarViajesDat();
			if(confirmarChoferes==true && confirmarViajes==true){
				cout << "La restauracion se ha realizado correctamente!"<<endl;
				system("pause");
			}
			else { cout << "La restauracion no se ha realizado correctamente!" << endl;
			system("pause");}
			break;

		case 20:
			system("cls");

		  CargarDatosIniChoferes();
		  CargarDatosIniViajes();

			;

			break;

		}

	} while (opc != 21);

}


void cargarCadena(char* pal, int tam) {
	int i;
	fflush(stdin);
	for (i = 0; i < tam; i++) {
		pal[i] = cin.get();
		if (pal[i] == '\n') break;
	}
	pal[i] = '\0';
	fflush(stdin);
}


void recuadro() { //Recuadro de informacíon
    int i, j;
    rlutil::setColor(rlutil::LIGHTRED);
    for (i = 30; i <= 100; i++) {
        rlutil::locate(i, 10); printf("%c", 205);
        rlutil::locate(i, 30); printf("%c", 205);
        for (j = 10; j <= 30; j++) {
            rlutil::locate(30, j); printf("%c", 186);
            rlutil::locate(100, j); printf("%c", 186);
        }
    }
    rlutil::locate(30, 30); printf("%c", 200); //ABAJO A LA IZQUIERDA
    rlutil::locate(30, 10); printf("%c", 201); //ARRIBA A LA IZQUIERDA
    rlutil::locate(100, 10); printf("%c", 187); //ARRIBA A LA DERECHA
    rlutil::locate(100, 30); printf("%c", 188); //ABAJO A LA DERECHA

    cout << endl;
    cout << endl;
}


int elegirOpcion(int x, int y, int limiteSuperior) {
	rlutil::locate(x, y); printf("*"); //a partir de aca es para utilizar las flechas del teclado
	bool elegir = false;


	while (!elegir) {
		if (_kbhit()) {
			rlutil::locate(x, y); cout << " ";
			char tecla = _getch();
			if (tecla == ENTER) { elegir = true; return y; }
			if (tecla == ARRIBA && y > 18) rlutil::locate(x, y--);
			if (tecla == ABAJO && y < limiteSuperior) rlutil::locate(x, y++);
			rlutil::locate(x, y); cout << "*";

		}
	}
}
