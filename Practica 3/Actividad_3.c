/*
 *   UCAB - Guayana
 *   Algoritmos y Programacion II
 *   Practica 05 - Actividad 02
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTOS 25

int cant_prod = 0;

struct registro{
	int   codigo;
	char  descripcion[20];
	char  ubicacion[6];
	float costo_unitario;
	int   cantidad;
} inventario[MAX_PRODUCTOS];

void imprime_producto(int i){
	if(i<0 || i>= cant_prod){
		printf("Producto No encontrado");
		return;
	}
	printf("Codigo:     %4d\n",inventario[i].codigo);
	printf("Decripcion: %s\n",inventario[i].descripcion);
	printf("Ubicacion:  %s\n",inventario[i].ubicacion);
	printf("Costo/Unit: %.2f\n",inventario[i].costo_unitario);
	printf("Cantidad:   %d\n\n",inventario[i].cantidad);
}

void leer_productos(char *archivo){
	FILE *fp;
	int i;

	if((fp=fopen(archivo,"r"))==NULL){
		fprintf(stderr,"leer_productos: no se pudo abrir %s\n",archivo);
		exit(1);
	}
	fscanf(fp,"%d",&cant_prod);
	for(i=0;i<cant_prod;i++)
		fscanf(fp,"%d %s %s %f %d",&inventario[i].codigo,inventario[i].descripcion,
			inventario[i].ubicacion,&inventario[i].costo_unitario,&inventario[i].cantidad);
	fclose(fp);
}

// Aprovechando el hecho de que los productos están ordenados por código, utilizaremos la búsqueda binaria que tiene un tiempo
// de búsqueda O(log)

int buscar_por_codigo(int codigo, int bajo, int alto){
	int centro, eCentral;

	if (bajo > alto) return -1;

	centro = (bajo+alto)/2;
	eCentral = inventario[centro].codigo;
	if (codigo == eCentral)
		return centro;
	if (codigo < eCentral)
		return buscar_por_codigo(codigo,bajo,centro-1);	// Izquierda
	return buscar_por_codigo(codigo,centro+1,alto);		// Derecha
}

int main(void) {
	int i;

	leer_productos("productos.dat");
	for(i=0;i<cant_prod;i++)
		imprime_producto(i);
	printf("Codigo a buscar:");
	scanf("%d",&i);
	imprime_producto(buscar_por_codigo(i,0,cant_prod-1));
	return EXIT_SUCCESS;
}
