#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//fonction qui affiche un tableau d'entiers de taille n
void afficher(int t[], int n)
{
	int i;

    for(i = 0; i < n - 1; i++)
    {
		printf("%d ",t[i]);
	}
	
}
/*fonctions qui trient un tableau d'entiers de taille n*/
//algorithme 1 : tri par selection
void tri_selec(int t[], int n)
{
    int i, j,imin,tmp;

    for(i = 0; i < n - 1; i++)
    {
		imin=i;
        for(j = i+1; j < n; j++)
        {
            if(t[j] <t[imin])
            {
                imin=j;
            }
        }
        tmp = t[i];
        t[i] = t[imin];
        t[imin] = tmp;
    }
}
//algorithme 2 : tri par permutation
void tri_permut(int t[], int n)
{
    int i, j, tmp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(t[j] > t[j + 1])
            {
                tmp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = tmp;
            }
        }
    }
}
//algorithme 3 : Quick sort
/// fonction qui partitionne le tableau
int partition(int t[], int debut, int fin)
{
    int pivot = t[fin];
    int i = debut - 1;
    int j;
    int tmp;

    for(j = debut; j < fin; j++)
    {
        if(t[j] < pivot)
        {
            i++;

            tmp = t[i];
            t[i] = t[j];
            t[j] = tmp;
        }
    }

    tmp = t[i + 1];
    t[i + 1] = t[fin];
    t[fin] = tmp;

    return i + 1;
}
///fonction qui trie récursivement
void quick_sort(int t[], int debut, int fin)
{
    int p;

    if(debut < fin)
    {
        p = partition(t, debut, fin);

        quick_sort(t, debut, p - 1);
        quick_sort(t, p + 1, fin);
    }
}
//fonction principale
int main()
{
	//n=taille du tableau : modifier pour tester plusieurs tailles
    int n = 20000;
    int *t1;
    int *t2;
    int *t3;
    int i;
    clock_t debut, fin;
    
    //création de 3 tableaux identiques 
    t1 = malloc(n * sizeof(int));
    t2 = malloc(n * sizeof(int));
    t3 = malloc(n * sizeof(int));

    srand(time(NULL));

    for(i = 0; i < n; i++)
    {
        t1[i] = rand();
        t2[i] = t1[i];
        t3[i]=t1[i];
    }
	
	//exécution des algorithmes de tri avec mesure et affichage des temps d'exécution
	debut = clock();
    tri_selec(t1, n);
    fin = clock();
    //afficher(t1,n);

    printf("\nTri par selection : %.3f s\n",
           (double)(fin - debut) / CLOCKS_PER_SEC);

    debut = clock();
    tri_permut(t1, n);
    fin = clock();
    //afficher(t1,n);

    printf("\nTri par permutation : %.3f s\n",
           (double)(fin - debut) / CLOCKS_PER_SEC);

    debut = clock();
    quick_sort(t2, 0, n - 1);
    fin = clock();
    //afficher(t1,n);

    printf("\nQuick sort   : %.3f s\n",
           (double)(fin - debut) / CLOCKS_PER_SEC);

    //libération des tableaux
    free(t1);
    free(t2);
    free(t3);

    return 0;
}
