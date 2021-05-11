#include <iostream>
using namespace std;

#include "configuracion.h"
#include "choferes.h"
#include "menus.h"
#include "viajes.h"
#include "rlutil.h"



bool BackUpChoferes() {

	FILE* p;
	FILE* pFile;
	choferes reg;

	   p = fopen("choferes.dat", "rb");
	   if (p == NULL) { return false; }

	   pFile = fopen("choferes.bkp", "wb");
	   if (pFile == NULL) { return false; }

	   while (fread(&reg, sizeof reg, 1, p) == 1)
	   {
		   if(fwrite(&reg, sizeof reg, 1, pFile) == 0)

		   {
			   return false;
		   }
	   }

    fclose(p);
	fclose(pFile);

	return true;

}


bool BackUpViajes() {

	FILE* p;
	FILE* pFile;
	choferes reg;

	p = fopen("viajes.dat", "rb");
	if (p == NULL) { return false; }

	pFile = fopen("viajes.bkp", "wb");
	if (pFile == NULL) { return false; }

	while (fread(&reg, sizeof reg, 1, p) == 1)
	{
		if (fwrite(&reg, sizeof reg, 1, pFile) == 0)

		{
			return false;
		}
	}

	fclose(p);
	fclose(pFile);

	return true;

}

bool RestaurarViajesDat() {

	FILE* p;
	FILE* pFile;
	choferes reg;

	p = fopen("viajes.bkp", "rb");
	if (p == NULL) { return false; }

	pFile = fopen("viajes.dat", "wb");
	if (pFile == NULL) { return false; }

	while (fread(&reg, sizeof reg, 1, p) == 1)
	{
		if (fwrite(&reg, sizeof reg, 1, pFile) == 0)

		{
			return false;
		}
	}

	fclose(p);
	fclose(pFile);

	return true;

}


bool RestaurarChoferes() {

	FILE* p;
	FILE* pFile;
	choferes reg;

	p = fopen("choferes.bkp", "rb");
	if (p == NULL) { return false; }

	pFile = fopen("choferes.dat", "wb");
	if (pFile == NULL) { return false; }

	while (fread(&reg, sizeof reg, 1, p) == 1)
	{
		if (fwrite(&reg, sizeof reg, 1, pFile) == 0)

		{
			return false;
		}
	}

	fclose(p);
	fclose(pFile);

	return true;

}



bool CargarDatosIniChoferes() {

	FILE* p;
	FILE* pFile;
	choferes reg;

	p = fopen("choferes.ini", "rb");
	if (p == NULL) { return false; }

	pFile = fopen("choferes.dat", "wb");
	if (pFile == NULL) { return false; }

	while (fread(&reg, sizeof reg, 1, p) == 1)
	{
		if (fwrite(&reg, sizeof reg, 1, pFile) == 0)

		{
			return false;
		}
	}

	fclose(p);
	fclose(pFile);

	return true;

}



bool CargarDatosIniViajes() {

	FILE* p;
	FILE* pFile;
	viajes reg;

	p = fopen("viajes.ini", "rb");
	if (p == NULL) { return false; }

	pFile = fopen("viajes.dat", "wb");
	if (pFile == NULL) { return false; }

	while (fread(&reg, sizeof reg, 1, p) == 1)
	{
		if (fwrite(&reg, sizeof reg, 1, pFile) == 0)

		{
			return false;
		}
	}

	fclose(p);
	fclose(pFile);

	return true;

}
