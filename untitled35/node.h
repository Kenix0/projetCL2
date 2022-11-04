//
// Created by Elliott on 03/11/2022.
//

#ifndef UNTITLED35_NODE_H
#define UNTITLED35_NODE_H


#include <stdio.h>
#include <stdlib.h>
#define MAX 26

struct s_node
{
    char lettre;
    char flechies[20][30];
    struct s_node   *sons[MAX];
    int depth;
};

typedef struct s_node t_node, *p_node;

p_node createNode(char);

#endif //UNTITLED35_NODE_H
