#include <stdio.h>
#include <string.h>
#include "../include/config.h"

int cargar_config(const char *ruta, Config *cfg) {
    FILE *f = fopen(ruta, "r");
    if (!f) return 1;

    char linea[256];

    while (fgets(linea, sizeof(linea), f)) {
        if (sscanf(linea, "ADMIN_USER=%s", cfg->admin_user) == 1);
        if (sscanf(linea, "ADMIN_PASS=%s", cfg->admin_pass) == 1);
        if (sscanf(linea, "DB_PATH=%s", cfg->db_path) == 1);
        if (sscanf(linea, "LOG_PATH=%s", cfg->log_path) == 1);
    }

    fclose(f);
    return 0;
}
