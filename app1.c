#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_char_por_linea 1000
#define max_largo_nom_pizza 1000
#define max_orders 1000
typedef struct {
    char nombre[max_largo_nom_pizza];
    int cont;
} cont_pizza;

// Definición de la estructura Order
typedef struct {
    int pizza_id;
    int order_id;
    char pizza_name_id[max_largo_nom_pizza];
    int quantity;
    char order_date[11];
    char order_time[9];
    float unit_price;
    float total_price;
    char pizza_size;
    char pizza_category[max_largo_nom_pizza];
    char pizza_ingredients[500];
    char pizza_name[max_largo_nom_pizza];
} Order;

int pls() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[1024];
    char *token;
    cont_pizza pizzas[max_char_por_linea];
    int num_pizzas = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener el nombre de la pizza
        token = strtok(line, ";");
        token = strtok(NULL, ";"); // Ignorar order_id
        token = strtok(NULL, ";"); // Ignorar pizza_name_id
        token = strtok(NULL, ";"); // Ignorar quantity
        token = strtok(NULL, ";"); // Ignorar order_date
        token = strtok(NULL, ";"); // Ignorar order_time
        token = strtok(NULL, ";"); // Ignorar unit_price
        token = strtok(NULL, ";"); // Ignorar total_price
        token = strtok(NULL, ";"); // Ignorar pizza_size
        token = strtok(NULL, ";"); // Ignorar pizza_category
        token = strtok(NULL, ";"); // Ignorar pizza_ingredients
        token = strtok(NULL, ";"); // Obtener pizza_name

        // Quitar el salto de línea del nombre
        token[strcspn(token, "\n")] = 0;

        // Verificar si la pizza ya está en la lista
        int found = 0;
        for (int i = 0; i < num_pizzas; i++) {
            if (strcmp(pizzas[i].nombre, token) == 0) {
                pizzas[i].cont++;
                found = 1;
                break; 
            }
        }

        // Si no está en la lista, añadirlo
        if (!found) {
            strcpy(pizzas[num_pizzas].nombre, token);
            pizzas[num_pizzas].cont = 1;
            num_pizzas++;
        }
    }

    // Cerrar archivo
    fclose(archivo);

    // Encontrar la cantidad mínima de ventas
    int min_ventas = pizzas[0].cont;
    for (int i = 1; i < num_pizzas; i++) {
        if (pizzas[i].cont < min_ventas) {
            min_ventas = pizzas[i].cont;
        }
    }

    // Imprimir las pizzas menos vendidas
    printf("Pizzas menos vendidas: ");
    for (int i = 1; i < num_pizzas; i++) {
        if (pizzas[i].cont == min_ventas) {
            printf("%s\n", pizzas[i].nombre);
        }
    }

    return 0;
}

int pms() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[1024];
    char *token;
    cont_pizza pizzas[max_char_por_linea];
    int num_pizzas = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener el nombre de la pizza
        token = strtok(line, ";");
        token = strtok(NULL, ";"); // Ignorar order_id
        token = strtok(NULL, ";"); // Ignorar pizza_name_id
        token = strtok(NULL, ";"); // Ignorar quantity
        token = strtok(NULL, ";"); // Ignorar order_date
        token = strtok(NULL, ";"); // Ignorar order_time
        token = strtok(NULL, ";"); // Ignorar unit_price
        token = strtok(NULL, ";"); // Ignorar total_price
        token = strtok(NULL, ";"); // Ignorar pizza_size
        token = strtok(NULL, ";"); // Ignorar pizza_category
        token = strtok(NULL, ";"); // Ignorar pizza_ingredients
        token = strtok(NULL, ";"); // Obtener pizza_name

        // Quitar el salto de línea del nombre
        token[strcspn(token, "\n")] = 0;

        // Verificar si la pizza ya está en la lista
        int found = 0;
        for (int i = 0; i < num_pizzas; i++) {
            if (strcmp(pizzas[i].nombre, token) == 0) {
                pizzas[i].cont++;
                found = 1;
                break;
            }
        }

        // Si no está en la lista, añadirlo
        if (!found) {
            strcpy(pizzas[num_pizzas].nombre, token);
            pizzas[num_pizzas].cont = 1;
            num_pizzas++;
        }
    }

    // Cerrar archivo
    fclose(archivo);

    // Encontrar la cantidad máxima de ventas
    int max_ventas = pizzas[0].cont;
    for (int i = 1; i < num_pizzas; i++) {
        if (pizzas[i].cont > max_ventas) {
            max_ventas = pizzas[i].cont;
        }
    }

    // Imprimir las pizzas más vendidas
    printf("Pizzas mas vendidas: ");
    for (int i = 0; i < num_pizzas; i++) {
        if (pizzas[i].cont == max_ventas) {
            printf("%s\n", pizzas[i].nombre);
        }
    }

    return 0;
}
#define max_fecha 10000
#define largo_fecha 11

typedef struct {
    char fecha[largo_fecha];
    float total_ventas;
} fecha_ventas;

int dms() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[1024];
    char *token;
    fecha_ventas fechas[max_fecha];
    int num_fechas = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Inicializar total de ventas para cada fecha
    for (int i = 0; i < max_fecha; i++) {
        fechas[i].total_ventas = 0.0f;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener la fecha y el total de ventas
        token = strtok(line, ";"); // Ignorar pizza_id
        token = strtok(NULL, ";"); // Ignorar order_id
        token = strtok(NULL, ";"); // Ignorar pizza_name_id
        token = strtok(NULL, ";"); // Ignorar quantity
        token = strtok(NULL, ";"); // Obtener order_date
        char *fecha = token;
        token = strtok(NULL, ";"); // Ignorar order_time
        token = strtok(NULL, ";"); // Ignorar unit_price
        float precio_total = atof(strtok(NULL, ";")); // Obtener total_price

        // Quitar el salto de línea de la fecha
        fecha[strcspn(fecha, "\n")] = 0;

        // Actualizar el total de ventas para cada fecha
        int found = 0;
        for (int i = 0; i < num_fechas; i++) {
            if (strcmp(fechas[i].fecha, fecha) == 0) {
                fechas[i].total_ventas += precio_total;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(fechas[num_fechas].fecha, fecha);
            fechas[num_fechas].total_ventas = precio_total;
            num_fechas++;
        }
    }

    // Cerrar archivo
    fclose(archivo);

    // Encontrar la fecha con más ventas
    float max_ventas = fechas[0].total_ventas;
    char *fecha_mas_ventas = fechas[0].fecha;
    for (int i = 1; i < num_fechas; i++) {
        if (fechas[i].total_ventas > max_ventas) {
            max_ventas = fechas[i].total_ventas;
            fecha_mas_ventas = fechas[i].fecha;
        }
    }

    // Imprimir la fecha con más ventas en términos de dinero
    printf("La fecha con menos ventas en terminos de dinero es: %s\nCon el monto vendido: %f\n", fecha_mas_ventas, max_ventas);

    return 0;
}

int dls() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[1024];
    char *token;
    fecha_ventas fechas[max_fecha];
    int num_fechas = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Inicializar total de ventas para cada fecha
    for (int i = 0; i < max_fecha; i++) {
        fechas[i].total_ventas = 0.0f;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener la fecha y el total de ventas
        token = strtok(line, ";"); // Ignorar pizza_id
        token = strtok(NULL, ";"); // Ignorar order_id
        token = strtok(NULL, ";"); // Ignorar pizza_name_id
        token = strtok(NULL, ";"); // Ignorar quantity
        token = strtok(NULL, ";"); // Obtener order_date
        char *fecha = token;
        token = strtok(NULL, ";"); // Ignorar order_time
        token = strtok(NULL, ";"); // Ignorar unit_price
        float precio_total = atof(strtok(NULL, ";")); // Obtener total_price

        // Quitar el salto de línea de la fecha
        fecha[strcspn(fecha, "\n")] = 0;

        // Actualizar el total de ventas para cada fecha
        int found = 0;
        for (int i = 0; i < num_fechas; i++) {
            if (strcmp(fechas[i].fecha, fecha) == 0) {
                fechas[i].total_ventas += precio_total;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(fechas[num_fechas].fecha, fecha);
            fechas[num_fechas].total_ventas = precio_total;
            num_fechas++;
        }
    }

    // Cerrar archivo
    fclose(archivo);
    for(int i = 0; i < num_fechas - 1; i++) {
        fechas[i] = fechas[i + 1];
    }
    num_fechas--;

   // Encontrar la fecha con menos ventas
    float min_ventas = fechas[0].total_ventas;
    char *fecha_menos_ventas = fechas[0].fecha;
    for (int i = 1; i < num_fechas; i++) {
        if (fechas[i].total_ventas < min_ventas) {
            min_ventas = fechas[i].total_ventas;
            fecha_menos_ventas = fechas[i].fecha;
        }
    }
    // Imprimir la fecha con más ventas en términos de dinero
    printf("La fecha con menos ventas en terminos de dinero es: %s\nCon el monto vendido: %f\n", fecha_menos_ventas, min_ventas);

    return 0;
}

#define largo_fecha 11 // Longitud máxima de una fecha en formato DD-MM-YYYY
#define max_fechas 10000
typedef struct {
    char fecha[largo_fecha];
    int cant_total;
} fecha_ventas_pizza;

char dmsp() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[1024];
    char *token;
    fecha_ventas_pizza fechas[max_fechas];
    int num_fechas = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return NULL;
    }

    // Inicializar total de cantidad de pizzas vendidas para cada fecha
    for (int i = 0; i < max_fechas; i++) {
        fechas[i].cant_total = 0;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Ignorar las primeras 3 columnas
        token = strtok(line, ";");
        for (int i = 0; i < 3; i++) {
            token = strtok(NULL, ";");
        }
        // Nos quedamos con la cantidad de pizzas vendidas
        int cantidad = atoi(token);
        // Obtener la fecha y la cantidad de pizzas vendidas
        token = strtok(NULL, ";"); // Ignorar quantity
        char *fecha = token;
        // printf("En la fecha %s se vendieron %d pizzas\n", date, quantity);
        token = strtok(NULL, ";"); // Ignorar order_time
        token = strtok(NULL, ";"); // Ignorar unit_price
        token = strtok(NULL, ";"); // Ignorar total_price
        token = strtok(NULL, ";"); // Ignorar pizza_size
        token = strtok(NULL, ";"); // Ignorar pizza_category
        token = strtok(NULL, ";"); // Ignorar pizza_ingredients
        token = strtok(NULL, ";"); // Ignorar pizza_name

        // Quitar el salto de línea de la fecha
        fecha[strcspn(fecha, "\n")] = 0;

        // Buscar si ya existe una entrada para esta fecha y actualizarla
        int found = 0;
        for (int i = 0; i < num_fechas; i++) {
            if (strcmp(fechas[i].fecha, fecha) == 0) {
                fechas[i].cant_total += cantidad;
                found = 1;
                break;
            }
        }
        // Si no se encuentra, agregar una nueva entrada
        if (!found) {
            strcpy(fechas[num_fechas].fecha, fecha);
            fechas[num_fechas].cant_total = cantidad;
            num_fechas++;
            
        }
    }

    // Cerrar archivo
    fclose(archivo);
    
    for(int i = 0; i < num_fechas - 1; i++) {
        fechas[i] = fechas[i + 1];
    }
    num_fechas--;

    char *fecha_mas_pizzas = fechas[0].fecha;
    int max_cantidad = fechas[0].cant_total;
    for (int i = 1; i < num_fechas; i++) {
        if (fechas[i].cant_total > max_cantidad) {
            max_cantidad = fechas[i].cant_total;
            fecha_mas_pizzas = fechas[i].fecha;
        }
    }

    // Devolver la fecha con más pizzas vendidas
    printf("La fecha con mas pizzas vendidas es: %s\n", fecha_mas_pizzas);
    printf("Cantidad de pizzas vendidas: %d\n", max_cantidad);



    return 0;
}

char dlsp() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[1024];
    char *token;
    fecha_ventas_pizza fechas[max_fechas];
    int num_fechas = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return NULL;
    }

    // Inicializar total de cantidad de pizzas vendidas para cada fecha
    for (int i = 0; i < max_fechas; i++) {
        fechas[i].cant_total = 0;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Ignorar las primeras 3 columnas
        token = strtok(line, ";");
        for (int i = 0; i < 3; i++) {
            token = strtok(NULL, ";");
        }
        // Nos quedamos con la cantidad de pizzas vendidas
        int cantidad = atoi(token);
        // Obtener la fecha y la cantidad de pizzas vendidas
        token = strtok(NULL, ";"); // Ignorar quantity
        char *fecha = token;
        // printf("En la fecha %s se vendieron %d pizzas\n", date, quantity);
        token = strtok(NULL, ";"); // Ignorar order_time
        token = strtok(NULL, ";"); // Ignorar unit_price
        token = strtok(NULL, ";"); // Ignorar total_price
        token = strtok(NULL, ";"); // Ignorar pizza_size
        token = strtok(NULL, ";"); // Ignorar pizza_category
        token = strtok(NULL, ";"); // Ignorar pizza_ingredients
        token = strtok(NULL, ";"); // Ignorar pizza_name

        // Quitar el salto de línea de la fecha
        fecha[strcspn(fecha, "\n")] = 0;

        // Buscar si ya existe una entrada para esta fecha y actualizarla
        int found = 0;
        for (int i = 0; i < num_fechas; i++) {
            if (strcmp(fechas[i].fecha, fecha) == 0) {
                fechas[i].cant_total += cantidad;
                found = 1;
                break;
            }
        }
        // Si no se encuentra, agregar una nueva entrada
        if (!found) {
            strcpy(fechas[num_fechas].fecha, fecha);
            fechas[num_fechas].cant_total = cantidad;
            num_fechas++;
            
        }
    }

    // Cerrar archivo
    fclose(archivo);
    
    for(int i = 0; i < num_fechas - 1; i++) {
        fechas[i] = fechas[i + 1];
    }
    num_fechas--;

    char *fecha_menos_pizzas = fechas[0].fecha;
    int min_cantidad = fechas[0].cant_total;
    // Encontrar la fecha con menos pizzas vendidas
    for (int i = 0; i < num_fechas; i++) {
        // Your code here
        // printf("En la fecha %s se vendieron %d pizzas\n", fechas[i].date, fechas[i].cant_total);
        if (fechas[i].cant_total < min_cantidad) {
            min_cantidad = fechas[i].cant_total;
            fecha_menos_pizzas = fechas[i].fecha;
        }
    }
    printf("La fecha con menos pizzas vendidas es: %s\n", fecha_menos_pizzas);
    printf("Cantidad de pizzas vendidas: %d\n", min_cantidad);
    
    return 0;
}

#define max_ingredientes 1000

typedef struct {
    char nombre[max_char_por_linea];
    int cont;
} ingred_cont;

int ims() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[max_char_por_linea];
    char *token;
    ingred_cont ingred[max_ingredientes];
    int num_ingred = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener los ingredientes de la pizza
        token = strtok(line, ";");
        for (int i = 0; i < 9; i++) {
            token = strtok(NULL, ";"); // Ignorar las primeras 9 columnas
        }
        token = strtok(NULL, ";"); // Obtener los ingredientes

        // Tokenizar los ingredientes
        char *ingrediente = strtok(token, ",");
        while (ingrediente != NULL) {
            // Quitar espacios en blanco al principio y al final del ingrediente
            while (*ingrediente == ' ') {
                ingrediente++;
            }
            char *end = ingrediente + strlen(ingrediente) - 1;
            while (end > ingrediente && *end == ' ') {
                *end-- = '\0';
            }

            // Verificar si el ingrediente ya está en la lista
            int found = -1;
            for (int i = 0; i < num_ingred; i++) {
                if (strcmp(ingred[i].nombre, ingrediente) == 0) {
                    found = i;
                    break;
                }
            }

            // Si el ingrediente no está en la lista, añadirlo
            if (found == -1) {
                strcpy(ingred[num_ingred].nombre, ingrediente);
                ingred[num_ingred].cont = 1;
                num_ingred++;
            } else {
                ingred[found].cont++;
            }

            // Obtener el siguiente ingrediente
            ingrediente = strtok(NULL, ",");
        }
    }

    // Cerrar archivo
    fclose(archivo);

    // Encontrar la cantidad máxima de ventas de un ingrediente
    int max_ventas = 0;
    for (int i = 0; i < num_ingred; i++) {
        if (ingred[i].cont > max_ventas) {
            max_ventas = ingred[i].cont;
        }
    }

    // Imprimir los ingredientes más vendidos
    printf("Ingredientes mas vendidos:\n");
    for (int i = 0; i < num_ingred; i++) {
        if (ingred[i].cont == max_ventas) {
            printf("%s\n", ingred[i].nombre);
        }
    }

    return 0;
}

typedef struct {
    char categoria[max_char_por_linea];
    int cont;
} cont_pizza_categoria;

int hp() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[max_char_por_linea];
    char *token;
    cont_pizza_categoria categorias[max_char_por_linea];
    int num_categorias = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener la categoría de la pizza
        token = strtok(line, ";"); // Ignorar la primera columna
        token = strtok(NULL, ";"); // Ignorar las siguientes 2 columnas
        token = strtok(NULL, ";");
        token = strtok(NULL, ";"); // Ignorar las siguientes 6 columnas
        token = strtok(NULL, ";");
        token = strtok(NULL, ";");
        token = strtok(NULL, ";");
        token = strtok(NULL, ";");
        token = strtok(NULL, ";"); // Obtener la categoría
        token = strtok(NULL, ";"); // Obtener la categoría


        // Quitar el salto de línea de la categoría
        token[strcspn(token, "\n")] = 0;

        // Verificar si la categoría ya está en la lista
        int found = -1;
        for (int i = 0; i < num_categorias; i++) {
            if (strcmp(categorias[i].categoria, token) == 0) {
                found = i;
                break;
            }
        }
        
   
        // Si la categoría no está en la lista, añadirla
        if (found == -1) {
            strcpy(categorias[num_categorias].categoria, token);
            categorias[num_categorias].cont = 1;
            num_categorias++;
        } else {
            categorias[found].cont++;
        }
    }

    // Cerrar archivo
    fclose(archivo);

    for(int i = 0; i < num_categorias - 1; i++) {
        categorias[i] = categorias[i + 1];
    }
    num_categorias--;

    // Imprimir la cantidad de pizzas vendidas por categoría
    printf("Cantidad de pizzas vendidas por categoria:\n");
    for (int i = 0; i < num_categorias; i++) {
        printf("%s: %d\n", categorias[i].categoria, categorias[i].cont);
    }

    return 0;
}

typedef struct {
    int order_id;
    int total_pizzas;
    int num_orders;
} cont_pizza_order;

int apo() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[max_char_por_linea];
    char *token;
    cont_pizza_order orders[max_char_por_linea];
    int num_orders = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener el ID de orden y la cantidad de pizzas
        token = strtok(line, ";"); // Ignorar la primera columna
        int order_id = atoi(strtok(NULL, ";")); // Obtener el ID de orden
        strtok(NULL, ";"); // Ignorar la siguiente columna
        int cantidad = atoi(strtok(NULL, ";")); // Obtener la cantidad de pizzas

        // Buscar si el ID de orden ya está registrado
        int found = -1;
        for (int i = 0; i < num_orders; i++) {
            if (orders[i].order_id == order_id) {
                found = i;
                break;
            }
        }

        // Si el ID de orden no está registrado, añadirlo
        if (found == -1) {
            orders[num_orders].order_id = order_id;
            orders[num_orders].total_pizzas = cantidad;
            orders[num_orders].num_orders = 1;
            num_orders++;
        } else {
            orders[found].total_pizzas += cantidad;
            orders[found].num_orders++;
        }
    }

    // Cerrar archivo
    fclose(archivo);

    for(int i = 0; i < num_orders - 1; i++) {
        orders[i] = orders[i + 1];
    }
    num_orders--;
    // Calcular el promedio de pizzas por orden
    float total_pizzas = 0;
    for (int i = 0; i < num_orders; i++) {
        total_pizzas += (float)orders[i].total_pizzas / orders[i].num_orders;
    }
    
    float prom_pizzas_orden = total_pizzas / num_orders;

    // Imprimir el promedio de pizzas por orden
    printf("Promedio de pizzas por orden: %.2f\n", prom_pizzas_orden);

    return 0;
}

#define max_fechas 100

typedef struct {
    char fecha[11];
    int num_pizzas;
} DatePizzas;

int apd() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[1024];
    char *token;
    DatePizzas fechas[max_fechas];
    int num_fechas = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Inicializar total de pizzas para cada fecha
    for (int i = 0; i < max_fechas; i++) {
        fechas[i].num_pizzas = 0;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener la fecha y el número de pizzas
        token = strtok(line, ";"); // Ignorar pizza_id
        token = strtok(NULL, ";"); // Ignorar order_id
        token = strtok(NULL, ";"); // Ignorar pizza_name_id
        int cantidad = atoi(strtok(NULL, ";")); // Obtener quantity
        token = strtok(NULL, ";"); // Obtener order_date
        char *fecha = token;
        token = strtok(NULL, ";"); // Ignorar order_time
        token = strtok(NULL, ";"); // Ignorar unit_price
        token = strtok(NULL, ";"); // Ignorar total_price
        token = strtok(NULL, ";"); // Ignorar pizza_size
        token = strtok(NULL, ";"); // Ignorar pizza_category
        token = strtok(NULL, ";"); // Ignorar pizza_ingredients
        token = strtok(NULL, ";"); // Ignorar pizza_name

        // Quitar el salto de línea de la fecha
        fecha[strcspn(fecha, "\n")] = 0;

        // Actualizar el número total de pizzas para cada fecha
        int found = 0;
        for (int i = 0; i < num_fechas; i++) {
            if (strcmp(fechas[i].fecha, fecha) == 0) {
                fechas[i].num_pizzas += cantidad;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(fechas[num_fechas].fecha, fecha);
            fechas[num_fechas].num_pizzas = cantidad;
            num_fechas++;
        }
    }

    // Cerrar archivo
    fclose(archivo);

    for(int i = 0; i < num_fechas - 1; i++) {
        fechas[i] = fechas[i + 1];
    }
    num_fechas--;

    // Calcular el promedio de pizzas por día
    int total_pizzas = 0;
    for (int i = 0; i < num_fechas; i++) {
        total_pizzas += fechas[i].num_pizzas;
    }
    float prom_pizzas = (float)total_pizzas / num_fechas;

    // Imprimir el promedio de pizzas por día
    printf("Promedio de pizzas por dia es: %.2f\n", prom_pizzas);

    return 0;
}


int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s [nombre_archivo.csv] [funcion1] [funcion2] ...\n", argv[0]);
        return 1;
    }

    // Llama a las funciones especificadas en los argumentos de la línea de comandos
    for (int i = 2; i < argc; i++) {
        char *metrica = argv[i];
        char *resultado = NULL;

        // Llama a la función correspondiente
        if (strcmp(metrica, "pls") == 0) {
            resultado = pls();
        } else if (strcmp(metrica, "pms") == 0) {
            resultado = pms();
        } else if (strcmp(metrica, "dms") == 0) {
            resultado = dms(); 
        } else if (strcmp(metrica, "dls") == 0) {
            resultado = dls(); 
        } else if (strcmp(metrica, "dmsp") == 0) {
            resultado = dmsp();
        } else if (strcmp(metrica, "dlsp") == 0) {
            resultado = dlsp();
        } else if (strcmp(metrica, "apo") == 0) {
            resultado = apo(); 
        } else if (strcmp(metrica, "apd") == 0) {
            resultado = apd(); 
        }  else if (strcmp(metrica, "ims") == 0) {
            resultado = ims(); 
        } else if (strcmp(metrica, "hp") == 0) {
            resultado = hp(); 
        } 
         
        if (resultado != NULL) {
            printf("%s\n", resultado);
            free(resultado);
        }
    }

    return 0;
}