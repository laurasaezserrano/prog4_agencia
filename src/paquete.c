/*
 * paquete.c
 *
 *  Created on: 26 mar 2026
 *      Author: zaira.diez
 */

#include <stdio.h>
#include <string.h>
#include "paquete.h"

#define ARCHIVO "paquetes.dat"

// Guardar paquete
void guardarPaquete(Paquete p) {
    FILE *f = fopen(ARCHIVO, "ab");
    if (f != NULL) {
        fwrite(&p, sizeof(Paquete), 1, f);
        fclose(f);
    }
}

// CREAR
void crearPaquete(void) {
    Paquete p;

    printf("Codigo: ");
    scanf("%d", &p.cod);

    printf("Nombre: ");
    scanf(" %[^\n]", p.nombre);

    printf("Precio: ");
    scanf("%f", &p.precio);

    printf("Codigo ciudad origen: ");
    scanf("%s", p.cod_ciudad_origen);

    printf("Codigo ciudad destino: ");
    scanf("%s", p.cod_ciudad_destino);

    printf("Plazas totales: ");
    scanf("%d", &p.plazas_totales);

    p.plazas_disponibles = p.plazas_totales;
    p.activo = 1;

    guardarPaquete(p);

    printf("Paquete creado correctamente.\n");
}

// ELIMINAR (baja lógica)
void eliminarPaquete(void) {
    FILE *f = fopen(ARCHIVO, "rb+");
    Paquete p;
    int codigo;

    if (f == NULL) return;

    printf("Codigo a eliminar: ");
    scanf("%d", &codigo);

    while (fread(&p, sizeof(Paquete), 1, f)) {
        if (p.cod == codigo && p.activo == 1) {
            p.activo = 0;
            fseek(f, -sizeof(Paquete), SEEK_CUR);
            fwrite(&p, sizeof(Paquete), 1, f);
            printf("Paquete eliminado.\n");
            fclose(f);
            return;
        }
    }

    printf("No encontrado.\n");
    fclose(f);
}

// CONSULTAR
void consultarPaquete(void) {
    FILE *f = fopen(ARCHIVO, "rb");
    Paquete p;
    int codigo;

    if (f == NULL) return;

    printf("Codigo a consultar: ");
    scanf("%d", &codigo);

    while (fread(&p, sizeof(Paquete), 1, f)) {
        if (p.cod == codigo && p.activo == 1) {
            printf("\n--- PAQUETE ---\n");
            printf("Codigo: %d\n", p.cod);
            printf("Nombre: %s\n", p.nombre);
            printf("Precio: %.2f\n", p.precio);
            printf("Origen: %s\n", p.cod_ciudad_origen);
            printf("Destino: %s\n", p.cod_ciudad_destino);
            printf("Plazas totales: %d\n", p.plazas_totales);
            printf("Plazas disponibles: %d\n", p.plazas_disponibles);
            fclose(f);
            return;
        }
    }

    printf("No encontrado.\n");
    fclose(f);
}

// LISTADO
void listadoPaquetes(void) {
    FILE *f = fopen(ARCHIVO, "rb");
    Paquete p;

    if (f == NULL) {
        printf("No hay paquetes.\n");
        return;
    }

    printf("\n--- LISTADO DE PAQUETES ---\n");

    while (fread(&p, sizeof(Paquete), 1, f)) {
        if (p.activo == 1) {
            printf("\nCodigo: %d\n", p.cod);
            printf("Nombre: %s\n", p.nombre);
            printf("Precio: %.2f\n", p.precio);
            printf("Origen: %s\n", p.cod_ciudad_origen);
            printf("Destino: %s\n", p.cod_ciudad_destino);
            printf("Plazas totales: %d\n", p.plazas_totales);
            printf("Plazas disponibles: %d\n", p.plazas_disponibles);
        }
    }

    fclose(f);
}

// MENU
void menuPaquetes(void) {
    int opcion;

    do {
        printf("\n--- MENU PAQUETES ---\n");
        printf("1. Crear paquete\n");
        printf("2. Eliminar paquete\n");
        printf("3. Consultar paquete\n");
        printf("4. Listado paquetes\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: crearPaquete(); break;
            case 2: eliminarPaquete(); break;
            case 3: consultarPaquete(); break;
            case 4: listadoPaquetes(); break;
        }

    } while (opcion != 0);
}
