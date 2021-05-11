#ifndef CHOFERES_H_INCLUDED
#define CHOFERES_H_INCLUDED
struct FechaActual {
	int diaActual;
	int mesActual;
	int anioActual;
};


struct Fecha {

	int dia;
	int mes;
	int anio;
	int diaVencimiento;
	int mesVencimiento;
	int anioVencimiento;
};


struct choferes {

	char dni[10];
	char apellido[50];
	char nombre[50];
	Fecha diamesanio;
	char cuit[20];
	int TipoRegistro;
	char NroTel[15];
	bool PropietarioAuto;
	bool Estado;

};




//DECLARO LAS FUNCIONES DE CHOFERES
// PROTOTIPOS

choferes CargarChofer();
void MostrarChofer(choferes reg);
bool GuardarChoferArchivo(choferes reg);
void listarChoferes();
int VerificarDni(char *aux);
int ConfirmarCadena(char* cadena);
int VerificarCuit(char* aux);
bool LeerDniChofer(char dni[10],choferes* reg_ir);
int buscarRegistroPorDni(char* dni);
bool leerChofer(int pos, choferes* pReg);
bool ModificarArchivoChoferes(choferes reg, int pos);
void bajaChofer();
int PosicionRegistroPorDni(char* dni);
void cargarCadena(char* pal, int tam);
bool MostrarChoferPorDni(char* dni);
bool leerChoferes(int pos, choferes* pReg);
void altaChofer();
void ModificarFechaVto();


///funciones de fecha ACTUAL
FechaActual fechayhora();
bool leerFechaActual(choferes reg);
bool ValidarFechaVto(choferes reg);
///fin funciones fecha ACTUAL

///Funciones de los reacuadros

void recuadroChoferes();
void ingresaDatosCuadro();
void limpiarPantallaFechaIngreso();
void limpiarPantallaFechaVencimiento();
void limpiarPantallaFechaInvalida();
void limpiarPantallaDNI();
void limpiarPrimerRecuadro();
void limpiarSegundoRecuadro();
void limpiarTercerRecuadro();
void limpiarCuartoRecuadro();
void limpiarQuintoRecuadro();
void limpiarSextoRecuadro();
void limpiarSeptimoRecuadro();
void limpiarOctavoRecuadro();
void limpiarNovenoRecuadro();
///Fin funciones de los recuadros

// FIN PROTOTIPOS

#endif // CHOFERES_H_INCLUDED
