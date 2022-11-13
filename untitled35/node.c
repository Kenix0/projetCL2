//
// Created by Elliott on 03/11/2022.
//

#include "node.h"


p_node createNode(char lettre)
{
    p_node nouv;

    nouv = (p_node)malloc(sizeof(t_node));
    nouv->lettre = lettre;
    for(int i=0; i<26; i++){
        nouv->sons[i]=NULL;
    }
    nouv->flechies = calloc(20, sizeof(char));
    for(int j=0; j<20; j++){
        nouv->flechies[j] = calloc(30, sizeof(char));
        for(int k=0; k<30; k++){
            nouv->flechies[j][k] = 'a';
        }
    }
    //printf("%c\n", nouv->flechies[0][0]);
    nouv->nb_flechies=0;
    return nouv;
}