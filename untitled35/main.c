#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "node.c"
#include "tree.h"
#include "tree.c"


int main() {
    t_tree noms, verbes, adverbes, adjectifs;
    noms.root = createNode('0');
    verbes.root = createNode('0');
    adverbes.root = createNode('0');
    adjectifs.root = createNode('0');
    noms.depth = verbes.depth = adverbes.depth = adjectifs.depth = 0;
    /*tab_chaine = calloc(20, sizeof(char));
    for(int i=0; i<20; i++){
        tab_chaine[i] = calloc(30, sizeof(char));
    }*/
    RemplirArbre(&noms, &adverbes, &adjectifs, &verbes);
    //noms.root->sons[18]->flechies[0][0]='a';
    //printf("%c", noms.root->sons[18]->flechies[0][0]='a');
    /*p_node temp = noms.root->sons[18]->sons[19]->sons[0]->sons[1]->sons[8]->sons[11]->sons[8]->sons[12]->sons[4]->sons[19]->sons[17]->sons[4];
    p_node temp2 = noms.root->sons[18]->sons[19]->sons[0]->sons[1]->sons[8]->sons[11]->sons[8]->sons[18]->sons[0]->sons[13]->sons[19];
    printf("%s\n", temp2->flechies[0]);*/
    return 0;
}