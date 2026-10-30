
/* PROGRAMME DE TEST DE L'UTILISATION MEMOIRE*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Ce programme tente de reserver successivement un tableau d'entiers de plus en plus grand.\n");
    printf("Apres chaque reservation(allocation), observez la memoire utilisee par le programme.\n");
    printf("Cherchez le programme dans le gestionnaire des taches ou le moniteur d'activite.\n\n");
    printf("Appuyez sur Entree pour commencer...");
    getchar();
	//les différentes tailles testées
    size_t tailles[] = {
        100000000,    /* 100 millions d'entiers = environ 400 Mo */
        500000000,    /* environ 2 Go */
        1000000000,   /* environ 4 Go */
        4000000000,   /* environ 16 Go*/
        8000000000    /* 8 milliards d'entiers = environ 32 Go*/
    };
	//calcul du nombre de tailles testées
    int nb_tests = sizeof(tailles) / sizeof(tailles[0]);
	//boucle pour tester les différentes tailles
    for (int t = 0; t < nb_tests; t++) {
        size_t n = tailles[t];

        printf("\n----------------------------------------\n");
        printf("Test %d / %d\n", t + 1, nb_tests);
        printf("Allocation d'un tableau de %zu entiers.\n", n);

        double memoire_mio = (n * sizeof(int)) / (1024.0 * 1024.0);
        double memoire_gio = memoire_mio / 1024.0;

        printf("Memoire theorique du tableau : %.2f Mio, soit %.2f Gio\n",
               memoire_mio, memoire_gio);
		//tentative de réservation du tableau
        int *tableau = malloc(n * sizeof(int));
		// si échec
        if (tableau == NULL) {
            printf("Echec de l'allocation memoire.\n");
            printf("Le tableau demande probablement trop de memoire disponible.\n");
            return 1;
        }
		//remplissage du tableau
        printf("Allocation reussie.\n");
        printf("Remplissage du tableau en cours...\n");
        for (size_t i = 0; i < n; i++) {
            tableau[i] = (int)(i % 100);
        }
		//calcul sur les valeurs du tableau
        printf("Remplissage termine.\n");
        long long somme = 0;
        for (size_t i = 0; i < n; i += n / 10 + 1) {
            somme = somme + tableau[i];
        }
		printf("\nDans le gestionnaire des taches ou dans le moniteur d'activite,");
        printf("\nobservez maintenant la memoire utilisee par le programme.");
        printf("\nAppuyez ensuite sur Entree pour continuer...");
        getchar();
		
		//libération de la mémoire
        free(tableau);

        printf("\nMemoire liberee.");
        printf("\nAppuyez sur Entree pour passer au test suivant...");
        getchar();
    }

    printf("\nFin du programme.\n");
    return 0;
}
