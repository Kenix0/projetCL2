#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "node.h"
#include "node.c"
#include "tree.h"
#include "tree.c"


int main() {
    t_tree noms, verbes, adverbes, adjectifs;
    noms.root = verbes.root = adverbes.root = adjectifs.root = createNode('0');
    RemplirArbre(&noms, &adverbes, &adjectifs, &verbes);
    /*FILE* fichier = NULL;
    fichier = fopen("C:\\Users\\Elliott\\CLionProjects\\untitled35\\texte.txt", "r");
    for(int i=0; i<15; i++){
        printf("%d\n", fgetc(fichier));
    }*/
}