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
    cont=0;
    do{
        printf("___________________________\n");
        printf("Seleccione opcion:\n");
        printf("1. Registrar estudiante y notas\n");
        printf("2. Cambiar notas de estudiante\n");
        printf("3. Promedio por materia/estudiante\n");
        printf("4. Calificaciones altas y bajas\n");
        printf("5. Aprobados y reprobados por materia\n");
        printf("6. Salir\n");
        printf("___________________________\n");
        printf(">> ");
        scanf("%d",&opc);
        switch (opc){
            case 1:        
                printf("Ingrese el nombre de la estudiante %d: ", cont+1);
                scanf("%s", &nombres[cont]);
                for (int i = 0; i < 3; i++){
                    printf("Ingrese calificacion de %s: ", materias[i]);
                    scanf("%s", &notas[cont][i]);
                }
                cont++;
                break;
                    
            default:
                break;
            }

    }while(opc!=6);

    return 0;
