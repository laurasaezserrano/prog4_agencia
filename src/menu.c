/*
 * menu.c
 *
 *  Created on: 17 mar 2026
 *      Author: zaira.diez
 */

#include <stdio.h>
#include "menu.h"

void mostrar_menu(sqlite3 *db) {
    int opcion;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Clientes\n");
        printf("2. Paquetes\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

    } while (opcion != 0);
}
