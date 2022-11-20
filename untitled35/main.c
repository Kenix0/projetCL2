#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "node.h"
#include "tree.h"
#include "menu.h"
#include "menu.c"
#include "tree.c"
#include "node.c"


int main() {
    //generation de la seed pour le rand()
    srand(time(NULL));
    //creation des arbres
    t_tree noms, verbes, adverbes, adjectifs;

    noms.root = createNode('0');
    verbes.root = createNode('0');
    adverbes.root = createNode('0');
    adjectifs.root = createNode('0');
    noms.depth = verbes.depth = adverbes.depth = adjectifs.depth = 0;
    //printf("%s", ExtraireMotHasard(noms.root));
    RemplirArbre(&noms, &adverbes, &adjectifs, &verbes);

    menu(noms, verbes, adverbes, adjectifs);

    //recherche de mot dans les arbres
    /*int present;
    char* recherche = "\0";
    scanf("%s", recherche);
    present = RechercheMot(noms.root, recherche);
    present = present + RechercheMot(verbes.root, recherche);
    present = present + RechercheMot(adverbes, recherche);
    present = present + RechercheMot(adjectifs.root, recherche);
    if (present >= 1) {
        printf("Le mot est bien present.");
    }
    else {
        printf("Le mot n'est pas present.");
    }



    char nom1[25]="\0";
    char nom2[25]="\0";
    char nom3[25]="\0";
    char nom4[25]="\0";
    char verbe1[25]="\0";
    char verbe2[25]="\0";
    char verbe3[25]="\0";
    char ajdectif1[25]="\0";
    char ajdectif2[25]="\0";

    int choix;
    printf("Quel modele de phrase voulez-vous generer ?\n");
    printf("      (entrer le numero associe)\n");
    printf(" \n");
    do {
        printf("1. nom - adjectif - verbe - nom\n");
        printf("2. nom - \"qui\" - verbe - verbe - nom - adjectif\n");
        printf("3. \n");
        scanf("%d", &choix);
    }while ((choix < 1) || (choix > 3));
    if (choix == 1){
        ExtraireMotHasard(noms.root, nom1);
        ExtraireMotHasard(noms.root, nom2);
        ExtraireMotHasard(verbes.root, verbe1);
        ExtraireMotHasard(adjectifs.root, ajdectif1);
        printf(" \n");
        printf("%s %s %s %s\n", nom1, ajdectif1, verbe1, nom2);
    }
    if (choix == 2){
        ExtraireMotHasard(noms.root, nom3);
        ExtraireMotHasard(noms.root, nom4);
        ExtraireMotHasard(verbes.root,verbe2);
        ExtraireMotHasard(verbes.root, verbe3);
        ExtraireMotHasard(adjectifs.root, ajdectif2);
        printf(" \n");
        printf("%s qui %s %s %s %s\n", nom3, verbe2, verbe3, nom4, ajdectif2);
    }

*/
    return 0;
}