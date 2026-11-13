#include <stdio.h>

void afficherMenu()
{
    printf("\n===== CINEMA LE REX =====\n");
    printf("1 - Horaires des seances\n");
    printf("2 - Tarifs\n");
    printf("3 - Prix d'une place\n");
    printf("4 - Prix pour un groupe\n");
    printf("0 - Quitter\n");
    printf("Votre choix : ");
}

void afficherHoraires()
{
    printf("Seances : 14h00, 17h30, 20h45\n");
}

void afficherTarifs()
{
    printf("Moins de 14 ans : 5 euros\n");
    printf("Adulte : 9 euros\n");
    printf("65 ans et plus : 7 euros\n");
    printf("Groupe de 5 personnes ou plus : -10 %% sur le total\n");
}

float prixPlace(int age)
{
    if (age < 14)
        return 5;
    else if (age >= 65)
        return 7;
    else
        return 9;
}

float prixGroupe(int nbPersonnes)
{
    int i, age;
    float total = 0;

    for (i = 1; i <= nbPersonnes; i++)
    {
        printf("Age de la personne %d : ", i);
        scanf("%d", &age);
        total = total + prixPlace(age);
    }

    if (nbPersonnes >= 5)
        total = total * 0.9;

    return total;
}

int main()
{
    int choix = -1, age, nb;

    while (choix != 0)
    {
        afficherMenu();
        scanf("%d", &choix);

        if (choix == 1)
            afficherHoraires();
        else if (choix == 2)
            afficherTarifs();
        else if (choix == 3)
        {
            printf("Age du client : ");
            scanf("%d", &age);
            printf("Prix : %.2f euros\n", prixPlace(age));
        }
        else if (choix == 4)
        {
            printf("Nombre de personnes : ");
            scanf("%d", &nb);
            printf("Total : %.2f euros\n", prixGroupe(nb));
        }
        else if (choix != 0)
            printf("Choix invalide\n");
    }

    printf("Au revoir !\n");
    return 0;
}