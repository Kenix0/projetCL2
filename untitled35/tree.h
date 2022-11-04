//
// Created by Elliott on 01/11/2022.
//

#ifndef PROJETGÉNÉRATEURPHRASES_TREE_H
#define PROJETGÉNÉRATEURPHRASES_TREE_H

#include "node.h"

typedef struct s_tree
{
    p_node root;
} t_tree, *p_tree;

void RemplirArbre(p_tree, p_tree, p_tree, p_tree);
int ReconnaitreType(char*);
char CaracSpecial(char);

#endif //PROJETGÉNÉRATEURPHRASES_TREE_H