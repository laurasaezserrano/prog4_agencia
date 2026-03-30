#include <stdio.h>
#include "menu.h"

void mostrar_menu(sqlite3 *db) {
    int opcion;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Clientes\n");
        printf("2. Paquetes\n");
        printf("3. Alojamientos\n");
        printf("4. Transportes\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        	case 1:
            menu_clientes(db);
            break;
            case 2:
            menu_paquetes(db);
            break;
            case 3:
            menuAlojamiento();
            break;
            case 4:
            menuTransporte();
            break;
            case 0:
            printf("\nSaliendo...\n");
            break;
            default:
            printf("Opción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 0);
}
