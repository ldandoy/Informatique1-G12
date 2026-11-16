/*

Exercice 1 : premier pointeur

Déclarer un entier age qui vaut 20 et un pointeur p qui 
pointe sur age. Afficher la valeur de age, son adresse, la 
valeur de p et la valeur pointée par p. 
Ensuite, passer age à 21 en passant par p, puis réafficher 
age.

*/

#include <stdio.h>

int main(void) {
    int age = 20;
    int *p = &age;

    printf("Valeur de age: %d\n", age);
    printf("Adresse de age: %p\n", &age);
    printf("Valeur de p: %p\n", p);
    printf("Valeur pointer par p: %d\n", *p);
    printf("Adresse de p: %p\n", &p);

    *p = 21;

    printf("Valeur de age: %d\n", age);
    
    return 0;
}