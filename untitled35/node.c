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
    for(int j=0; j<20; j++){
        for(int k=0; k<30; k++){
            nouv->flechies[j][k]=NULL;
        }
    }

    return nouv;
}