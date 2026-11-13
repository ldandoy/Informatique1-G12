/*

Exercice 6 : qu’affiche ce programme ?

Sans l’exécuter, donner ce qu’affiche ce programme. Faire un schéma des cases mémoire et des flèches à chaque ligne.

#include <stdio.h>

int main()
{
    int u = 3, v = 8;
    int *p = &u;
    int *q = &v;

    *p = *p + 2;
    q = p;
    *q = *q * 10;
    p = &v;
    *p = *q + 1;

    printf("u = %d, v = %d, *p = %d, *q = %d\n", u, v, *p, *q);

    return 0;
}

*/