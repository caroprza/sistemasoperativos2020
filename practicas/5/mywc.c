#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char c;
    char buffer[64];
    char anterior = ' ';
    unsigned palabras = 0;
    unsigned lineas = 0;
    unsigned caracteres = 0;
    while(read(STDIN_FILENO, &c, 1) != 0) {
        if (c == ' '){
            if (anterior != '\n'){
                palabras++;
            }
        }
        else if (c == '\n') {
            lineas++;
        }
        caracteres++;
        anterior = c;

        //write(STDOUT_FILENO, &c, 1);
    }
    
    palabras++;

    printf("Lineas: %u\n", lineas);
    printf("Palabras: %u\n", palabras);
    printf("Caracteres: %u\n", caracteres);
    return 0;
}