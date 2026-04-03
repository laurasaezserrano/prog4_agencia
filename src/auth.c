#include <stdio.h>
#include <string.h>
#include "../include/auth.h"

int login_admin(sqlite3 *db) {
	char usuario[50];
	char clave[50];

	printf("===== LOGIN ADMIN =====\n");

    printf("Usuario: ");
    scanf("%s", usuario);

    printf("Clave: ");
    scanf("%s", clave);

    // Simplificado (luego lo conectas a la BD)
    if (strcmp(usuario, "admin") == 0 && strcmp(clave, "1234") == 0) {
        return 1;
    }

    return 0;
}
