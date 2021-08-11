/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Espaco.h"

void validarLoc(plocal espaco, int *total) {
    int i, j, k, l;
    int id_espaco;
    int flag = 0;
    
    
    //espaco->liga[2] = 2; teste
    
    for (i = 0; i < (*total); i++) {
        if(espaco[i].id<0){
            printf("\nID Invalido");
        }
        for (j = 0; j < 3; j++) {
            if (espaco[i].liga[j] != -1) {
                id_espaco = espaco[i].liga[j];
                for (k = 0; k < (*total); k++) {
                    if (espaco[k].id == id_espaco) {
                        for (l = 0; l < 3; l++) {
                            if (espaco[k].liga[l] == espaco[i].id) {
                                flag = 1;
                            }
                        }
                    }
                }
                if (flag == 0) {
                    printf("Ligacao nao compativel\n");
                    exit(0);
                }
                flag = 0;
            }

        }
    }
}

plocal carregaFichbin(char *nomefich, int *total) {
    int res;
    plocal aux_l;
    local esp;
    *total = 0;
    FILE *f;

    f = fopen(nomefich, "rb+");
    if (f == NULL) {
        printf("Erro no acesso ao ficheiro dos espaços\n");
        return NULL;
    }

    //aux_l = malloc(sizeof(local)*(*total+1));
    /*if (aux_l == NULL) {
        printf("\tAVISO: Erro ao alocar memoria!");
     */

    aux_l = NULL;
    //aux_l->ocupacao=0;
    while (fread(&esp, sizeof (local), 1, f) == 1) {

        aux_l = realloc(aux_l, sizeof (local) * (*total + 1));

        if (aux_l == NULL) {
            printf("\tAVISO: Erro ao alocar memoria!");
            return NULL;
        }
        aux_l[*total].id = esp.id;
        aux_l[*total].capacidade = esp.capacidade;
        
        for (int i = 0; i < 3; i++) {
            aux_l[*total].liga[i] = esp.liga[i];

        }

        (*total)++;
    }

    fclose(f);

    validarLoc(aux_l, total);

    return aux_l;
}

void listaEsp(plocal esp, int *tam) {
    //printf("\nola");
    for (int i = 0; i < *tam; i++) {
        printf("\nLocal %d : %d %d ", i + 1, esp[i].id, esp[i].capacidade);
        for (int k = 0; k < 3; k++) {
            printf(" %d", esp[i].liga[k]);
        }
    }
}