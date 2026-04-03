#include <stdio.h>
#include "../include/menu.h"
#include "../include/alojamiento.h"
#include "../include/transporte.h"
#include "../include/paquete.h"
#include "../include/clientes.h"
#include <stdio.h>


void mostrar_menu(sqlite3 *db) {
    int opcion;

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Clientes\n");
        printf("2. Paquetes\n");
        printf("3. Alojamientos\n");
        printf("4. Transportes\n");
        printf("0. Salir\n");
        printf("Opcion: ");

        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                menu_clientes(db);
                break;
            case 2:
            	menuPaquetes(db);
                break;
            case 3:
                menuAlojamiento(db);
                break;
            case 4:
                menuTransporte(db);
                break;
        }

    } while(opcion != 0);
}

