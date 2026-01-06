#include <stdio.h>
#include "input.h"
int main(){

    printf("hola mundo");
    int numero;

    int_number_input(&numero);

    printf("Número ingresado: %d\n", numero);


    int_number_input(&numero);

    printf("Número ingresado: %d\n", numero);
    
    return 0;


}