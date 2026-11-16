#include <stdio.h>

void afficherMenu() {
	printf("Que voulez-vous faire ?\n");
	printf("1 - Consulter le solde\n");
	printf("2 - Déposer de l'argent\n");
	printf("3 - Retirer de l'argent\n");
	printf("0 - Quitter\n");
}

void afficherSolde(float solde) {
	printf("Votre solde est de: %.2f Euros\n", solde);
}

float deposer(float solde, float montant) {
	if (montant <= 0) {
		printf("Montant invalide\n");
		return solde;
	}

	return montant+solde;
}

int retirer(float *solde, float *montant) {
	int successed = 0;
	if (*montant <= 0) {
		printf("Montant invalide\n");
		return successed;
	}

	if (*montant > *solde) {
		printf("Solde insuffisant\n");
		return successed;
	}

	successed = 1;
	*solde = *solde - *montant;

	return successed;
}

int main(void) {
	float solde = 0, montant = 0;
	int choix = -1;

	do {
		afficherMenu();
		scanf("%d", &choix);

		switch(choix) {
			case 0:
				break;
			case 1:
				afficherSolde(solde);
				break;
			case 2:
				printf("Combien voulez-vous déposer ?");
				scanf("%f", &montant);
				solde = deposer(solde, montant);
				afficherSolde(solde);
				break;
			case 3:
				printf("Combien voulez-vous retirer ?");
				scanf("%f", &montant);
				if (retirer(&solde, &montant) == 0) {
					printf("Retrait refusé");
				} else {
					printf("Retrait effectué");
				}
				afficherSolde(solde);
				break;
			default:
				printf("Choix invalide");
		}
	} while(choix != 0);

	return 0;
}