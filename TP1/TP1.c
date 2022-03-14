#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Prototipos

int cantCaracteres(FILE *entrada);
void lectura(FILE *entrada, char *palabra);
int evaluarCadena(char *palabra);
void escribirArchivo(char *palabra, int resultado, FILE *salida);

int matrizTT [7][6]={1,2,2,6,6,6,
                     5,5,6,6,3,6,
                     2,2,2,6,6,6,
                     4,4,4,4,6,6,
                     4,4,4,4,6,6,
                     5,5,6,6,6,6,
                     6,6,6,6,6,6};
//Main

int main()
{
    FILE *entrada, *salida;

    entrada = fopen("entrada.txt", "rt");
    salida = fopen("salida.txt", "wt+");
    int tamanioPalabra;

    while (!feof(entrada))
    {
        tamanioPalabra=cantCaracteres(entrada);
        char* palabra = (char*) malloc(tamanioPalabra);
        lectura(entrada, palabra);

        if (strlen(palabra) > 0)
        {
            int resultado=evaluarCadena(palabra); 
            escribirArchivo(palabra, resultado, salida);
        }
        free(palabra);
    }

    fclose(entrada);
    fclose(salida);

    return 0;
}

//Main Funciones

int evaluarCadena(char *palabra)
{
    int i=0;
    int fila = 0;
    int columna = 0;

    int longCadena=strlen(palabra);

    char caracter = palabra[i];

    while (i<longCadena)
    {
        switch (caracter)
        {
        case '0':
            columna=0;
            fila=matrizTT[fila][columna];
            break;
        case '1'...'7':
            columna=1;
            fila=matrizTT[fila][columna];
            break;
        case '8': case '9':
            columna=2;
            fila=matrizTT[fila][columna];
            break;
        case 'a'...'f': case 'A'...'F':
            columna=3;
            fila=matrizTT[fila][columna];
            break;
        case 'x': case 'X':
            columna=4;
            fila=matrizTT[fila][columna];
            break;
        default:
            columna=5;
            fila=6;
            break;
        }

        i++;
        caracter = palabra[i];
    }
    return matrizTT[fila][columna];
}
int cantCaracteres(FILE *entrada)
{
    char c;
    int j=0;

    int pos = ftell(entrada) / sizeof(char);
c
    fread(&c, sizeof(char), 1, entrada);

    while (c != ',' && !feof(entrada))
    {
        j++;
        fread(&c, sizeof(char), 1, entrada);
    }
    if(c==',')
        fseek(entrada, -(j+1), SEEK_CUR);
    else
        fseek(entrada, -j, SEEK_CUR);
    return j+1;
}
void lectura(FILE *entrada, char *palabra)
{
    char c;
    int i = 0;
    fread(&c, sizeof(char), 1, entrada);

    while (c != ',' && !feof(entrada))
    {
        palabra[i] = c;
        i++;
        fread(&c, sizeof(char), 1, entrada);
    }

    palabra[i] = '\0';
}
void escribirArchivo(char *palabra, int resultado, FILE *salida)
{
    char sistemasNumericos[6][20]={"Octal", "Decimal", "Error", "Hexadecimal", "Octal", "Error"};
    
    fprintf(salida, "%s - %s \n", sistemasNumericos[resultado-1], palabra);
}
