/*
 * auth.c
 *
 *  Created on: 17 mar 2026
 *      Author: zaira.diez
 */


#include <stdio.h>
#include <string.h>
#include "auth.h"

int login_admin(sqlite3 *db) {
    char user[50], pass[50];

    printf("Usuario: ");
    scanf("%s", user);

    printf("Clave: ");
    scanf("%s", pass);

    // Simplificado (luego lo conectas a la BD)
    if (strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0) {
        return 1;
    }

    return 0;
}
