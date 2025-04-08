#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
    char nombres[5][10];
    char materias[3][10];
    float notas[5][3];
    int cont = 0,opc,len;

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
                if(cont<5){        
                    printf("Ingrese el nombre de la estudiante %d: ", cont+1);
                    fflush(stdin);                    
                    fgets(nombres[cont], 10, stdin);
                    len=strlen(nombres[cont])-1;
                    nombres[cont][len]='\0';

                    for (int i = 0; i < 3; i++){
                        printf("Ingrese calificacion de %s: ",materias[i]);
                        scanf("%f", &notas[cont][i]);
                    }
                    cont++;
                }else{
                    printf("Limite de estudiantes alcanzado");
                }
                break;
            case 2:
                if(cont>=1){
                    printf("Notas\t\t%s\t\t%s\t\t%s\n",materias[0],materias[1],materias[2]);
                    for (int i = 0; i < cont; i++){
                        printf("%s\t\t%.2f\t\t%.2f\t\t%.2f\n",nombres[i],notas[i][0],notas[i][1],notas[i][2]);
                    }
                }
                break;
            default:
                break;
            }

    }while(opc!=6);

    return 0;
}
