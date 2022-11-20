//
// Created by Elliott on 03/11/2022.
//

#include "node.h"

// creation des noeuds avec 26 fils
p_node createNode(char lettre)
{
    p_node nouv;

    nouv = (p_node)malloc(sizeof(t_node));
    nouv->lettre = lettre;
    for(int i=0; i<28; i++){
        nouv->sons[i]=NULL;
    }

    nouv->nb_flechies=0;
    return nouv;
}