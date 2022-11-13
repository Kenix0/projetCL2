//
// Created by Elliott on 01/11/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"



void RemplirArbre(p_tree arbre_nom, p_tree arbre_adv, p_tree arbre_adj, p_tree arbre_vrb){
    FILE* fichier = NULL;
    fichier = fopen("C:\\Users\\Elliott\\CLionProjects\\untitled35\\mini_dico.txt", "r");
    char mot_flechi[30], mot_base[30], type[30], l[1000];
    int compteur=0;
    while(fgets(l, 1000, fichier)!=NULL){
        int i=0, j=0, k=0;
        mot_flechi[0]=mot_base[0]=type[0]='\0';
        while((l[i]!=' ')&&(l[i]!=9)){
            if((64<(int)l[i]) && ((int)l[i]<123)) {
                //printf("%c\n", l[i]);
                strncat(mot_flechi, &l[i], 1);
            }
            i++;
        }
        j=i+1;
        while(j==' ')
            j++;
        while((l[j]!=' ')&&(l[j]!=9)){
            strncat(mot_base, &l[j], 1);
            j++;
        }
        k=j+1;
        while(k==' ')
            k++;
        while(l[k]!='\n'){
            strncat(type, &l[k], 1);
            k++;
        }
        //printf("%s  %s  %s\n", mot_base, mot_flechi, type);
        if(strcmp(mot_base, mot_flechi)==0){
            int code_asc;
            if(ReconnaitreType(type)==1){
                p_node temp = arbre_nom->root;
                for(i=0; i<strlen(mot_base); i++){
                    code_asc = mot_base[i];
                    if(temp->sons[code_asc - 97]==NULL) {
                        temp->sons[code_asc - 97] = createNode(mot_base[i]);
                        arbre_nom->depth++;
                    }
                    else{
                        temp->sons[code_asc - 97]->lettre=mot_base[i];
                    }
                    //printf("%c\n", temp->sons[code_asc - 97]->lettre);
                    temp = temp->sons[code_asc - 97];
                }
            }
            else if(ReconnaitreType(type)==2){
                p_node temp = arbre_vrb->root;
                for(i=0; i<strlen(mot_base); i++) {
                    code_asc = mot_base[i];
                    if(temp->sons[code_asc - 97]==NULL) {
                        temp->sons[code_asc - 97] = createNode(mot_base[i]);
                        arbre_vrb->depth++;
                    }
                    else{
                        temp->sons[code_asc - 97]->lettre=mot_base[i];
                    }
                    temp = temp->sons[code_asc - 97];
                }
            }
            else if(ReconnaitreType(type)==3){
                p_node temp = arbre_adj->root;
                for(i=0; i<strlen(mot_base); i++) {
                    code_asc = mot_base[i];
                    if(temp->sons[code_asc - 97]==NULL) {
                        temp->sons[code_asc - 97] = createNode(mot_base[i]);
                        arbre_adj->depth++;
                    }
                    else
                        temp->sons[code_asc - 97]->lettre=mot_base[i];
                    temp = temp->sons[code_asc - 97];
                }
            }
            else{
                p_node temp = arbre_adv->root;
                for(i=0; i<strlen(mot_base); i++) {
                    code_asc = mot_base[i];
                    if(temp->sons[code_asc - 97]==NULL) {
                        temp->sons[code_asc - 97] = createNode(mot_base[i]);
                        arbre_adv->depth++;
                    }
                    else{
                        temp->sons[code_asc - 97]->lettre=mot_base[i];
                    }
                    temp = temp->sons[code_asc - 97];
                }
            }
        }
        else{
            if(ReconnaitreType(type)==1){
                AjouterFlechie(arbre_nom, mot_base, mot_flechi);
            }
            else if(ReconnaitreType(type)==2){
                AjouterFlechie(arbre_vrb, mot_base, mot_flechi);
            }
            else if(ReconnaitreType(type)==3){
                AjouterFlechie(arbre_adj, mot_base, mot_flechi);
            }
            else if(ReconnaitreType(type)==4){
                AjouterFlechie(arbre_adv, mot_base, mot_flechi);
            }
        }
    }
    fclose(fichier);
}


int ReconnaitreType(char* type){
    if(type[0]=='N')
        return 1;
    else if(type[0]=='V')
        return 2;
    else if(type[2]=='j')
        return 3;
    else if(type[2]=='v')
        return 4;
}




/*char CaracSpecial(char carac_spe){
    //printf("%s", carac_spe);
    if((carac_spe=="á")||(carac_spe=="ó")||(carac_spe=="ñ"))
        return 'a';
    else if((strcmp(carac_spe[0], "®")==0)||(strcmp(carac_spe[0], "¿")==0)||(strcmp(carac_spe[0], "¬")==0)||(strcmp(carac_spe[0], "½")==0))
        return 'e';
    else if((strcmp(carac_spe[0], "«")==0)||(strcmp(carac_spe[0], "»")==0))
        return 'i';
    else if((strcmp(carac_spe[0], "╣")==0)||(strcmp(carac_spe[0], "╝")==0)||(strcmp(carac_spe[0], "╗")==0))
        return 'u';
    else if((strcmp(carac_spe[0], "º")==0))
        return 'c';

}*/

void displayTree(p_node tree){
    if(tree==NULL){
        return;
    }
    for(int i=0; i<26; i++){
        displayTree(tree->sons[i]);
    }
    printf("%c", tree->lettre);
}

void AjouterFlechie(p_tree tree, char *mot_base, char *mot_flechi){
    p_node temp = tree->root;
    for(int i=0; i<strlen(mot_base); i++){
        int code_asc = mot_base[i];
        temp = temp->sons[code_asc-97];
    }
    for(int j=0; j< strlen(mot_flechi); j++){
        temp->flechies[temp->nb_flechies][j] = mot_flechi[j];
    }
    temp->nb_flechies++;
}

/*t_tree CreateTree(){

}*/