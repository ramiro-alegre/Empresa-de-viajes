#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <time.h>
#include <stdio.h>

using namespace std;

#include "choferes.h"
#include "menus.h"
#include "configuracion.h"
#include "rlutil.h"


//FUNCION PARA CARGAR UN NUEVO CHOFER DE A UNO

choferes CargarChofer() {

	choferes reg;
	int verificar,verificar2;
	bool fechasVerificar,fechasVto,verificarPropietario;
	recuadroChoferes();
	ingresaDatosCuadro();
	do {
		rlutil::locate(26, 2); cin >> reg.dni;
		verificar =  VerificarDni(reg.dni);
		verificar2 = ConfirmarCadena(reg.dni);
		if((verificar != 1 && verificar != -1) && verificar2 != 0){
            limpiarPrimerRecuadro();
		}
	} while ((verificar != 1 && verificar != -1) && verificar2 != 0);

	    do {

	   rlutil::locate(26, 4);

	   cargarCadena(reg.apellido, 50);
	   verificar2=ConfirmarCadena(reg.apellido);
	   if(verificar2<2){
        limpiarSegundoRecuadro();
	   }
	     } while (verificar2<2);

	 do {
		 rlutil::locate(26, 6);

		 cargarCadena(reg.nombre, 50);
		 verificar2 = ConfirmarCadena(reg.nombre);
		 if(verificar2<2){
            limpiarTercerRecuadro();
		 }
	 } while (verificar2 < 2);



	do {
		rlutil::locate(26, 8); cin >> reg.diamesanio.dia;
	    rlutil::locate(28, 8); cout << "/";
	    rlutil::locate(29, 8); cin >> reg.diamesanio.mes;
	    rlutil::locate(31, 8); cout << "/";
	    rlutil::locate(32, 8); cin >> reg.diamesanio.anio;

		fechasVerificar=leerFechaActual(reg);
		if(fechasVerificar==false){
		    limpiarPantallaFechaIngreso();
		    rlutil::locate(1, 25);
			cout << "Debe ingresar una fecha valida" << endl;
			system("pause");
			limpiarPantallaFechaInvalida();
		}
	} while (fechasVerificar==false);

	do {
		rlutil::locate(26, 10); cin >> reg.cuit;
		verificar = VerificarCuit(reg.cuit);
		verificar2= ConfirmarCadena(reg.cuit);
		if((verificar2 < 1 && (verificar!=1 && verificar!=-1))){
            limpiarQuintoRecuadro();
		}
	} while (verificar2 < 1 && (verificar!=1 && verificar!=-1));



	do {
		rlutil::locate(26, 12); cin >> reg.TipoRegistro;
		if((reg.TipoRegistro != 1 && reg.TipoRegistro != 2 && reg.TipoRegistro != 3)){
            limpiarSextoRecuadro();
		}
	}

	while (reg.TipoRegistro != 1 && reg.TipoRegistro != 2 && reg.TipoRegistro != 3);


	do {

		rlutil::locate(26, 14); cin >> reg.diamesanio.diaVencimiento;
		rlutil::locate(28, 14); cout << "/";
		rlutil::locate(29, 14); cin >> reg.diamesanio.mesVencimiento;
		rlutil::locate(31, 14); cout << "/";
		rlutil::locate(32, 14); cin >> reg.diamesanio.anioVencimiento;

		fechasVto = ValidarFechaVto(reg);
		if(fechasVto==false){
		    rlutil::locate(1, 25);
			cout << "Debe ingresar una fecha valida" << endl;
			system("pause");
			limpiarPantallaFechaVencimiento();
			limpiarPantallaFechaInvalida();
		}
	} while (fechasVto==false);


	rlutil::locate(26, 16); cin >> reg.NroTel;

do{
	rlutil::locate(26, 18); cin >> reg.PropietarioAuto;
	verificarPropietario=reg.PropietarioAuto;
	if(verificarPropietario!=true && verificarPropietario!=false){
        limpiarNovenoRecuadro();
	}
}while(verificarPropietario!=true && verificarPropietario!=false);
		reg.Estado = true;
		return reg;

}




//FUNCION PARA MOSTRAR A LOS CHOFERES

void MostrarChofer(choferes reg) {

	if (reg.Estado == true) {

	ingresaDatosCuadro();
	rlutil::locate(26, 2);  cout<< reg.dni;
	rlutil::locate(26, 4); cout << reg.apellido;
	rlutil::locate(26, 6); cout << reg.nombre;
	rlutil::locate(26, 8); cout << reg.diamesanio.dia;
	rlutil::locate(28, 8); cout << "/";
	rlutil::locate(29, 8); cout << reg.diamesanio.mes;
	rlutil::locate(31, 8); cout << "/";
	rlutil::locate(32, 8); cout << reg.diamesanio.anio;
	rlutil::locate(26, 10); cout<< reg.cuit;
	rlutil::locate(26, 12);  cout<< reg.TipoRegistro;
	rlutil::locate(26, 14); cout << reg.diamesanio.diaVencimiento;
	rlutil::locate(28, 14); cout << "/";
	rlutil::locate(29, 14); cout << reg.diamesanio.mesVencimiento;
	rlutil::locate(31, 14); cout << "/";
	rlutil::locate(32, 14); cout << reg.diamesanio.anioVencimiento;
	rlutil::locate(26, 16); cout << reg.NroTel;
	rlutil::locate(26, 18); cout << reg.PropietarioAuto;
	cout << '\n'<< '\n'<< '\n'<< '\n';
	system("pause");
	system("cls");
	}

}


/// funcion para guardar un chofer nuevo en el disco y me diga si ta bien

bool GuardarChoferArchivo(choferes reg) {

	FILE* pFile;
	bool escribio;

	pFile = fopen("choferes.dat", "ab");

		if (pFile == NULL)
		{
			return false;
		}

		escribio=fwrite(&reg,sizeof(reg),1,pFile);

		fclose(pFile);
		return escribio;
}


//FUNCION PARA DAR DE ALTA A UN NUEVO CHOFER

void altaChofer() {
	choferes reg;
	bool grabo;
	reg = CargarChofer();


	grabo = GuardarChoferArchivo(reg);
	if (grabo == true) {
		cout << "REGISTRO AGREGADO" << endl;
	}
	else {
		cout << "NO SE PUDO AGREGAR EL REGISTRO" << endl;
	}
}

//FUNCION PARA LISTAR A TODOS LOS CHOFERES


bool leerChoferes(int pos, choferes* pReg) {
	FILE* p;
	bool leyo;
	p = fopen("choferes.dat", "rb");
	if (p == NULL) {
		cout << "No se pudo abrir el archivo correctamente" << endl;
		return false;
	}
	fseek(p, pos * sizeof(choferes), 0);
	leyo = fread(pReg, sizeof(choferes), 1, p);
	fclose(p);
	return leyo;
}

void listarChoferes() {
	FILE* p;
	choferes reg;

	p = fopen("choferes.dat", "rb");
	if (p == NULL) return;
	while (fread(&reg, sizeof(choferes), 1, p) == 1) {
		system("cls");
		MostrarChofer(reg);
	}
	fclose(p);
}



// compara que no haya dos numeros de DNI IGUALES

int VerificarDni(char *aux) {

	FILE* pFile;
	int comparar;
	choferes reg;



	pFile = fopen("choferes.dat", "rb");


	while (fread(&reg, sizeof (choferes), 1, pFile)) {

		comparar = strcmp(reg.dni,aux);
		if(comparar==0){
			return 0;
		}
	}

	fclose(pFile);
	return 1;
}

int ConfirmarCadena(char *cadena) {

	int cantidadCaracteres;

 cantidadCaracteres= strlen(cadena);
 return cantidadCaracteres;
}

int VerificarCuit(char *aux) {

	FILE* pFile;
	int comparar;
	choferes reg;

	pFile = fopen("choferes.dat", "rb");


	while (fread(&reg, sizeof(choferes), 1, pFile)) {

		comparar = strcmp(reg.cuit,aux);
		if(comparar==0){
			return 0;
		}
	}

	fclose(pFile);
	return 1;
}

bool MostrarChoferPorDni(char *dni){
	choferes reg;
	int pos;
	pos = PosicionRegistroPorDni(dni);
	if(pos==-1){
		cout << "No existe este chofer" << endl;
		system("pause");
		return false;
	}
	if(leerChofer(pos,&reg)==false){
		cout << "No se pudo leer el registro" << endl;
		system("pause");
		return false;
	}
	system("cls");
	MostrarChofer(reg);


	return false;
}



// FUNCIONES PARA LA BAJA DE CHOFER POR DNI

void bajaChofer() {

	char dni[10];
	choferes reg;
	int pos;
	system("cls");
	cout << "INGRESE EL DNI DEL CHOFER A ELIMINAR: ";
	cin >> dni;

	pos = PosicionRegistroPorDni(dni);
	if (pos == -1) {
		cout << "Este chofer no esta registrado" << endl;
		return;
	}
	if (leerChofer(pos, &reg) == false) {
		cout << "No se pudo leer el registro" << endl;
		return;
	}
	reg.Estado = false;
	if (ModificarArchivoChoferes(reg, pos) == true) {
		cout << "Baja realizada correctamente" << endl;

	}
	else { cout << "No se pudo realizar correctamente la baja" << endl; }

}

int PosicionRegistroPorDni(char* dni) {
	FILE* pFILE;
	choferes reg;
	int pos = 0;
	pFILE = fopen("choferes.dat", "rb");
	if (pFILE == NULL) {
		cout << "No se pudo abrir el archivo correctamente" << endl;
		system("pause");
		return -1;
	}
	while (fread(&reg, sizeof(choferes), 1, pFILE) == 1) {

		if (strcmp(reg.dni, dni) == 0 && reg.Estado==true) {

			fclose(pFILE);
			return pos;
		}
		pos++;
	}
	fclose(pFILE);
	return -1;
}


bool leerChofer(int pos, choferes* pReg) {
	FILE* pFILE;
	bool leyo;
	pFILE = fopen("choferes.dat", "rb");
	if (pFILE == NULL) {
		cout << "No se pudo abrir el archivo correctamente" << endl;
		system("pause");
		return false;
	}
	fseek(pFILE, pos * sizeof(choferes), 0);
	leyo = fread(pReg, sizeof(choferes), 1, pFILE);
	fclose(pFILE);
	return leyo;
}

bool ModificarArchivoChoferes(choferes reg, int pos) {
	FILE* pFILE;
	bool escribio;
	pFILE = fopen("choferes.dat", "rb+");
	if (pFILE == NULL) {
		cout << "No se pudo abrir el archivo correctamente" << endl;
		system("pause");
		return false;
	}
	fseek(pFILE,  sizeof reg * pos, 0);
	escribio = fwrite(&reg, sizeof reg, 1, pFILE);
	fclose(pFILE);
	return escribio;

}


void ModificarFechaVto() {

	char dni[10];
	int diaNuevo, mesNuevo, anioNuevo;
	bool verificarFecha;
	system("cls");
	cout << "INGRESE DNI DEL CHOFER A MODIFICAR: ";
	cin >> dni;

	int pos;
	choferes reg;

	pos = PosicionRegistroPorDni(dni);

	if (pos == -1) { cout << "NO SE ENCONTRO CHOFER" << endl; return; }

	if (leerChofer(pos, &reg) == false) {
		cout << "NO SE PUDO LEER EL REGISTRO" << endl;
		return;
	}



	do{
	recuadroChoferes();
	ingresaDatosCuadro();
	rlutil::locate(26, 2);  cout<< reg.dni;
	rlutil::locate(26, 4); cout << reg.apellido;
	rlutil::locate(26, 6); cout << reg.nombre;
	rlutil::locate(26, 8); cout << reg.diamesanio.dia;
	rlutil::locate(28, 8); cout << "/";
	rlutil::locate(29, 8); cout << reg.diamesanio.mes;
	rlutil::locate(31, 8); cout << "/";
	rlutil::locate(32, 8); cout << reg.diamesanio.anio;
	rlutil::locate(26, 10); cout<< reg.cuit;
	rlutil::locate(26, 12);  cout<< reg.TipoRegistro;
	rlutil::locate(26, 16); cout << reg.NroTel;
	rlutil::locate(26, 18); cout << reg.PropietarioAuto;
	rlutil::locate(26, 14); cin >> diaNuevo;
	rlutil::locate(28, 14); cout << "/";
	rlutil::locate(29, 14); cin >> mesNuevo;
	rlutil::locate(31, 14); cout << "/";
	rlutil::locate(32, 14); cin >> anioNuevo;
	cout << '\n'<< '\n'<< '\n'<< '\n'<< '\n'<< '\n';
	system("pause");
	     reg.diamesanio.diaVencimiento = diaNuevo;
		 reg.diamesanio.mesVencimiento = mesNuevo;
		 reg.diamesanio.anioVencimiento = anioNuevo;
		 verificarFecha=ValidarFechaVto(reg);
		 if(verificarFecha==false){
		      rlutil::locate(1, 25);
			  cout << "Debe ingresa una fecha valida"<<endl;
			  system("pause");
			  system("cls");
		 }
	 } while (verificarFecha==false);

	if (ModificarArchivoChoferes(reg, pos) == true) {
	     rlutil::locate(1, 26);
		cout << "MODIFICACION REALIZADA" << endl;
		system("pause");
	}
	else {
	    rlutil::locate(1, 26);
		cout << "NO SE PUDO HACER LA MODIFICACION" << endl;
		system("pause");
		return;
	}
}



// funciones para la fecha

///Sacamos la fecha actual utilizando "ctime" "cstdio" "time.h"
FechaActual fechayhora() {

	FechaActual reg;
	time_t tiempo;

	struct tm* tmPtr;

	tiempo = time(NULL);
	tmPtr = localtime(&tiempo);

     reg.diaActual = tmPtr->tm_mday;
     reg.mesActual = tmPtr->tm_mon+1;
     reg.anioActual = 1900+tmPtr->tm_year;

	 return reg;

}



bool leerFechaActual(choferes reg) {

	FechaActual pReg = fechayhora();
	bool confirmar=false;

	if(reg.diamesanio.dia<0 || reg.diamesanio.dia>31){
		confirmar = false;
		return confirmar;
	}
	if(reg.diamesanio.mes<0 || reg.diamesanio.mes>12){
		confirmar = false;
		return confirmar;
	}
	if(reg.diamesanio.anio>2020 ){
	    confirmar =  false;
		return confirmar;
	}

	///Si llega hasta aca significa que las fechas ingresas fueron dentro del rango, ahora faltaria analizar si son menores o iguales
	if(reg.diamesanio.dia<=pReg.diaActual){

		if(reg.diamesanio.mes<=pReg.mesActual){

			if(reg.diamesanio.anio<=pReg.anioActual){

				confirmar = true;
			}
		}
	}
	else {

		if (reg.diamesanio.mes < pReg.mesActual) {

		if(reg.diamesanio.anio <= pReg.anioActual){

				confirmar = true;
			}
		}
	}
	return confirmar;
}


// funciones validar vto registro


bool ValidarFechaVto(choferes reg) {
	FechaActual pReg=fechayhora();
	bool confirmar=false;


	if (reg.diamesanio.diaVencimiento < 0 || reg.diamesanio.diaVencimiento>31) {
		confirmar = false;
		return confirmar;
	}
	if (reg.diamesanio.mesVencimiento < 0 || reg.diamesanio.mesVencimiento>12) {
		confirmar = false;
		return confirmar;
	}
	if (reg.diamesanio.anioVencimiento < 2020) {
		confirmar = false;
		return confirmar;
	}
	///Si llega hasta aca significa que las fechas ingresas fueron dentro del rango, ahora faltaria analizar si son menores o iguales
	if (reg.diamesanio.diaVencimiento > pReg.diaActual) {
		if (reg.diamesanio.mesVencimiento >= pReg.mesActual) {
			if (reg.diamesanio.anioVencimiento >= pReg.anioActual) {
				confirmar = true;
			}
	}
		}
	else {
		if (reg.diamesanio.mesVencimiento > pReg.mesActual) {
			if (reg.diamesanio.anioVencimiento >= pReg.anioActual) {
				confirmar = true;
			}
		}else{
		   if (reg.diamesanio.anioVencimiento > pReg.anioActual) {
				confirmar = true;
			}
		}
	}

	return confirmar;
}
///FIN FECHAS

///RECUADROS CHOFERES

// con esta funcion dibujamos la tabla general donde se van a pedir los datos y mostrarlos posteriormente

void recuadroChoferes() {
	int x, y;

	for (x = 1; x <= 100; x++) {
		rlutil::locate(x, 1); printf("%c", 205);
		rlutil::locate(x, 3); printf("%c", 205);
		rlutil::locate(x, 5); printf("%c", 205);
		rlutil::locate(x, 7); printf("%c", 205);
		rlutil::locate(x, 9); printf("%c", 205);
		rlutil::locate(x, 11); printf("%c", 205);
		rlutil::locate(x, 13); printf("%c", 205);
		rlutil::locate(x, 15); printf("%c", 205);
		rlutil::locate(x, 17); printf("%c", 205);
		rlutil::locate(x, 19); printf("%c", 205);

		for (y = 1; y <= 18; y++) {
			rlutil::locate(1, y); printf("%c", 186);
			rlutil::locate(100, y); printf("%c", 186);
			rlutil::locate(24, y); printf("%c", 186);
		}
	}

	rlutil::locate(1, 19); printf("%c", 200); //ABAJO A LA IZQUIERDA
	rlutil::locate(1, 1); printf("%c", 201); //ARRIBA A LA IZQUIERDA
	rlutil::locate(100, 1); printf("%c", 187); //ARRIBA A LA DERECHA
	rlutil::locate(100, 19); printf("%c", 188); //ABAJO A LA DERECHA
	//Simbolo que une (4) los recuadros
	rlutil::locate(24, 3); printf("%c", 206);
	rlutil::locate(24, 5); printf("%c", 206);
	rlutil::locate(24, 7); printf("%c", 206);
	rlutil::locate(24, 9); printf("%c", 206);
	rlutil::locate(24, 11); printf("%c", 206);
	rlutil::locate(24, 13); printf("%c", 206);
	rlutil::locate(24, 15); printf("%c", 206);
	rlutil::locate(24, 17); printf("%c", 206);

	//Fin
	//Simbolos que une al recuadro(2)
	rlutil::locate(24, 1); printf("%c", 203);
	rlutil::locate(24, 19); printf("%c", 202);
	//Fin
	//Más simbolos que unen cosas
	rlutil::locate(1, 3); printf("%c", 204);
	rlutil::locate(1, 5); printf("%c", 204);
	rlutil::locate(1, 7); printf("%c", 204);
	rlutil::locate(1, 9); printf("%c", 204);
	rlutil::locate(1, 11); printf("%c", 204);
	rlutil::locate(1, 13); printf("%c", 204);
	rlutil::locate(1, 15); printf("%c", 204);
	rlutil::locate(1, 17); printf("%c", 204);

	//Fin
	//Ya no se que poner aca
	rlutil::locate(100, 3); printf("%c", 185);
	rlutil::locate(100, 5); printf("%c", 185);
	rlutil::locate(100, 7); printf("%c", 185);
	rlutil::locate(100, 9); printf("%c", 185);
	rlutil::locate(100, 11); printf("%c", 185);
	rlutil::locate(100, 13); printf("%c", 185);
	rlutil::locate(100, 15); printf("%c", 185);
	rlutil::locate(100, 17); printf("%c", 185);

	//Fin
}

void ingresaDatosCuadro() {
	recuadroChoferes();
	rlutil::locate(11, 2); cout << "DNI";
	rlutil::locate(9, 4); cout << "APELLIDO";
	rlutil::locate(10, 6); cout << "NOMBRE";
	rlutil::locate(5, 8); cout << "FECHA DE INGRESO";
	rlutil::locate(10, 10); cout << "CUIT";
	rlutil::locate(5, 12); cout << "TIPO DE REGISTRO";
	rlutil::locate(3, 14); cout << "FECHA DE VTO REGISTRO";
	rlutil::locate(9, 16); cout << "TELEFONO";
	rlutil::locate(3, 18); cout << "PROPIETARIO DEL AUTO";
}


void limpiarPantallaFechaIngreso(){

   int x, y = 8;

    for(x=26;x<=99;x++){
	    rlutil::locate(x, y); cout << " ";
	}
}

void limpiarPantallaFechaVencimiento(){

    int x, y = 14;

    for(x=26;x<=99;x++){
	    rlutil::locate(x, y); cout << " ";
	}
}

void limpiarPantallaFechaInvalida() {
	int x, y = 25;

    for(x=1;x<=99;x++){
	    rlutil::locate(x, y); cout << " ";
	}


}

void limpiarPrimerRecuadro() {
	int x, y = 2;

    for(x=26;x<=99;x++){
	    rlutil::locate(x, y); cout << " ";
	}
}

void limpiarSegundoRecuadro() {
	int x, y = 4;

    for(x=26;x<=99;x++){
	    rlutil::locate(x, y); cout << " ";
	}
}

void limpiarTercerRecuadro() {
	int x, y = 6;

    for(x=26;x<=99;x++){
	    rlutil::locate(x, y); cout << " ";
	}
}

void limpiarQuintoRecuadro() {
	int x, y = 10;

    for(x=26;x<=99;x++){
	    rlutil::locate(x, y); cout << " ";
	}
}


void limpiarSextoRecuadro() {
	int x, y = 12;

    for(x=26;x<=99;x++){
	    rlutil::locate(x, y); cout << " ";
	}
}

void limpiarSeptimoRecuadro() {
	int x, y = 14;

    for(x=26;x<=99;x++){
	    rlutil::locate(x, y); cout << " ";
	}
}

void limpiarOctavoRecuadro() {
	int x, y = 16;

    for(x=26;x<=99;x++){
	    rlutil::locate(x, y); cout << " ";
	}
}


void limpiarNovenoRecuadro() {
	int x, y = 18;

    for(x=26;x<=99;x++){
	    rlutil::locate(x, y); cout << " ";
	}
}


///FIN RECUADROS CHOFERES
