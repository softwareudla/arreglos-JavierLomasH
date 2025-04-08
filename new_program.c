#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
    char nombres[5][10];
    char materias[3][10];
    int notas[3][10];
    int cont = 0,opc;

    printf("REGISTRO DE MATERIAS\n");
    while(cont<3){
        printf("Ingrese el nombre de la materia %d: ", cont+1);
        scanf("%s", &materias[cont]);
        cont++;
    }    

    do{
        printf("___________________________\n");
        printf("Seleccione opcion:\n");
        printf("1. Registrar estudiante y notas\n");
        printf("2. Cambiar notas de estudiante\n");
        printf("3. Promedio por materia/estudiante\n");
        printf("4. Calificaciónes altas y bajas\n");
        printf("5. Aprobados y reprobados por materia\n");
        printf("6. Salir\n");
        printf("___________________________\n");
        printf(">> ");
        scanf("%d",&opc);

    }while(opc!=6);
    return 0;
}