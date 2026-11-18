#include <stdio.h>

#define PV_MAX 100
#define PRIX_POTION 15

// Étape 2 : pas de pointeur, on ne fait que lire
void afficherPerso(int pv, int pieces, int potions, int xp, int niveau)
{
    printf("\n--- HEROS ---\n");
    printf("Niveau %d (%d/100 xp)\n", niveau, xp);
    printf("PV : %d/%d\n", pv, PV_MAX);
    printf("Pieces : %d  |  Potions : %d\n", pieces, potions);
}

// Étape 3 : deux pointeurs, on modifie deux variables
void boirePotion(int *pv, int *potions)
{
    if (*potions == 0)
    {
        printf("Plus de potion !\n");
        return;
    }
    *potions = *potions - 1;
    *pv = *pv + 30;
    if (*pv > PV_MAX)
        *pv = PV_MAX;
}

// Étape 4 : un pointeur pour modifier, un return pour informer
int subirDegats(int *pv, int degats)
{
    *pv = *pv - degats;
    if (*pv <= 0)
    {
        *pv = 0;
        return 1;      // mort
    }
    return 0;          // vivant
}

// Étape 5 : même schéma, avec deux variables modifiées
int acheterPotion(int *pieces, int *potions)
{
    if (*pieces < PRIX_POTION)
        return 0;
    *pieces = *pieces - PRIX_POTION;
    *potions = *potions + 1;
    return 1;
}

// Étape 6 : pointeurs + boucle
int gagnerXp(int *xp, int *niveau, int gain)
{
    int niveauxGagnes = 0;

    *xp = *xp + gain;
    while (*xp >= 100)
    {
        *xp = *xp - 100;
        *niveau = *niveau + 1;
        niveauxGagnes++;
    }
    return niveauxGagnes;
}

int main()
{
    int pv = PV_MAX, pieces = 50, potions = 1, xp = 0, niveau = 1;
    int choix = -1, degats, mort = 0, n;

    while (choix != 0 && !mort)
    {
        afficherPerso(pv, pieces, potions, xp, niveau);
        printf("1 - Combattre  2 - Boire une potion  3 - Acheter une potion  0 - Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        if (choix == 1)
        {
            printf("Degats subis : ");
            scanf("%d", &degats);
            mort = subirDegats(&pv, degats);
            if (mort)
                printf("Votre heros est mort...\n");
            else
            {
                pieces = pieces + 10;
                n = gagnerXp(&xp, &niveau, 40);
                if (n > 0)
                    printf("Niveau superieur ! (+%d)\n", n);
            }
        }
        else if (choix == 2)
            boirePotion(&pv, &potions);
        else if (choix == 3)
        {
            if (acheterPotion(&pieces, &potions))
                printf("Potion achetee\n");
            else
                printf("Pas assez d'or\n");
        }
        else if (choix != 0)
            printf("Choix invalide\n");
    }

    printf("Fin de la partie\n");
    return 0;
}