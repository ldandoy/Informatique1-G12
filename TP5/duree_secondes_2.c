// inclusion de la librairie stdio pour utiliser les fonction de saisie et d'affichage
#include <stdio.h>

int main() {
    int heures,minutes,secondes;
    int duree_secondes;
    int reste;
    int choix;
    /*affichage d'un menu et récupération du choix de l'utilisateur*/
    printf("\n1. convertir des h,m,s en secondes ");
    printf("\n2. convertir des secondes en h,m,s\n");
    scanf("%d",&choix);
    /*orientation du programme en fonction du choix*/
    if(choix==1){
        printf("nombre d'heures : ");
        scanf("%d",&heures);
        printf("nombre de minutes : ");
        scanf("%d",&minutes);
        printf("nombre de secondes : ");
        scanf("%d",&secondes);
        duree_secondes=heures*3600+minutes*60+secondes;
        printf("\nla duree totale en secondes est : %d\n",duree_secondes);
    }
    else{
        if(choix==2){
		/* A COMPLETER */
            
            
            
            
            
            

        }
        else printf("choix invalide");
    }
    return 0;
}
