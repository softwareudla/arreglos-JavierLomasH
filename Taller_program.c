#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]){
    char nombres[5][30];
    char materias[3][30];
    float notas[5][3];
    int opc,len,cont=0;
    float promedio[3];
    int alta=0, baja=0;
    int aprobados=0, reprobados=0;

    printf("REGISTRO DE MATERIAS\n");
    while(cont<3){
        printf("Ingrese el nombre de la materia %d: ", cont+1);
        fgets(materias[cont], sizeof materias[cont], stdin);
        len=strlen(materias[cont])-1;
        materias[cont][len]='\0';
        cont++;
    }    
    cont=0;
    do{
        printf("___________________________\n");
        printf("Seleccione opcion:\n");
        printf("1. Registrar estudiante y notas\n");
        printf("2. Ver notas y promedios\n");
        printf("3. Calificaciones altas y bajas\n");
        printf("4. Aprobados y reprobados por materia\n");
        printf("5. Salir\n");
        printf("___________________________\n");
        printf(">> ");
        scanf("%d",&opc);
        switch (opc){
            case 1:
                if(cont<5){        
                    printf("Ingrese el nombre de la estudiante %d: ", cont+1);
                    while(getchar() != '\n'); //Forma diferente de limiar el buffer
                    fgets(nombres[cont],sizeof nombres[cont] , stdin);
                    len=strlen(nombres[cont])-1;
                    nombres[cont][len]='\0';

                    for (int i = 0; i < 3; i++){
                        while(1){
                            printf("Ingrese calificacion de %s: ",materias[i]);        
                            if (scanf("%f", &notas[cont][i]) == 1 && notas[cont][i] >= 0 && notas[cont][i] <= 10){
                                break;
                            }        
                            printf("Nota invalida.\nIntente nuevamente: \n");        
                            while (getchar() != '\n'); 
                        }
                    }
                    cont++;
                }else{
                    printf("Limite de estudiantes alcanzado");
                }
                break;
            case 2:
                if(cont>=1){
                    printf("Notas\t\t%s\t\t%s\t\t%s\t\tP.Estudiante.\n",materias[0],materias[1],materias[2]);
                    for (int i = 0; i < cont; i++){
                        printf("%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",nombres[i],notas[i][0],notas[i][1],notas[i][2],(notas[i][0]+notas[i][1]+notas[i][2])/3);
                    }
                    for(int i=0;i<3;i++){
                        promedio[i]=0;
                        for(int j=0;j<cont;j++){
                            promedio[i]+=notas[j][i];
                        }
                        promedio[i]/=cont;
                    }
                    printf("P.Materia.\t%.2f\t\t%.2f\t\t%.2f\n",promedio[0],promedio[1],promedio[2]);
                }else{
                    printf("No hay estudiantes registrados\n");
                }               

                break;
            case 3:
                printf("Notas\t\t%s\t\t%s\t\t%s\n",materias[0],materias[1],materias[2]);
                printf("Altas\t\t");
                for (int i = 0; i < 3; i++){
                    for (int j = 0; j < cont; j++){
                        if(notas[j][i]>notas[alta][i]){
                            alta=j;
                        }
                    }
                    printf("%s:%.2f\t\t",nombres[alta],notas[alta][i]);
                }
                printf("\nBajas\t\t");
                for (int i = 0; i < 3; i++){
                    for (int j = 0; j < cont; j++){
                        if(notas[j][i]<notas[baja][i]){
                            baja=j;
                        }
                    }
                    printf("%s:%.2f\t\t",nombres[baja],notas[baja][i]);
                }
                printf("\n");
                break;

            case 4:
                printf("APROBADOS\n");
                for (int j=0 ;j<3 ;j++){
                    printf("%s: ", materias[j]);
                    for (int i = 0; i < cont; i++){
                        if(notas[i][j]>=6){
                            printf("%s, ", nombres[i]);
                            aprobados++;
                        }
                    }
                    printf("=%d\n",aprobados);
                    aprobados=0;
                }
                
                printf("REPROBADOS\n");
                for (int j=0 ;j<3 ;j++){
                    printf("%s: ", materias[j]);
                    for (int i = 0; i < cont; i++){
                        if(notas[i][j]<6){
                            printf("%s, ", nombres[i]);
                            reprobados++;
                        }
                    }
                    printf("=%d\n",reprobados);
                    reprobados=0;
                }
            default:
                break;
            }

    }while(opc!=5);

    return 0;
}
