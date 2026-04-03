#include <stdio.h>
#include "../include/menu.h"
#include "../include/alojamiento.h"
#include "../include/transporte.h"
#include "../include/paquete.h"
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
                printf("Clientes...\n");
                break;
            case 2:
                printf("Paquetes...\n");
                break;
            case 3:
                printf("Alojamientos...\n");
                break;
            case 4:
                printf("Transportes...\n");
                break;
        }

    } while(opcion != 0);
}
