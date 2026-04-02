#ifndef AUTH_H_
#define AUTH_H_

#include <sqlite3.h>

// Definición de estructura
typedef struct {
    char usuario[50];
    int nivel_permiso;
} Sesion;

int login(sqlite3 *db, const char *usuario, const char *password);
void logout(void);

#endif /* AUTH_H_ */
