/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Pessoas.h"

ppessoa carregaFichtxt(char *nomefich) {
    FILE *fp;
    ppessoa pers = NULL;
    fp = fopen(nomefich, "r");

    if (fp == NULL) {
        printf("Erro no acesso ao ficheiro pessoas\n");
        return pers;
    }


    while (1) {
        if (pers == NULL) {
            pers = malloc(sizeof (pessoa));
            int read = fscanf(fp, " %s %d %c %d", pers->nome, &pers->idade, &pers->estado, &pers->Ndias);

            if (read == EOF || !read) {
                //printf("Fihceiro lido\n");
                break;
            }
            pers ->prox = NULL;
        } else {
            ppessoa atual = pers;
            ppessoa temp = malloc(sizeof (pessoa));
            while (atual->prox != NULL) {
                atual = atual->prox;
            }
            int reads = fscanf(fp, " %s %d %c %d", temp->nome, &temp->idade, &temp->estado, &temp->Ndias);
            if (reads == EOF || !reads) {
                printf("Ficheiro lido\n");
                break;
            }

            atual->prox = temp;
            temp->prox = NULL;
        }
    }
    fclose(fp);
    return pers;
}

void imprimeLista(ppessoa pers) {
    ppessoa atual = pers;
    while (atual != NULL) {
        printf("Nome: %s Idade: %d Estado: %c \n", atual->nome, atual->idade, atual->estado);
        if (atual->estado == 'D') {
            printf("Dias infetado: %d \n", atual->Ndias);
        }
        atual = atual->prox;
    }
    return;
}

ppessoa pplSimu(ppessoa aCopiar, plocal randLoc, int *numLoc, int *vet) {
    int cont = 0;
    //int vet[*numLoc];
    int rand = 0;
    ppessoa listaSim = NULL; //criaçao da nova lista  
    //printf("teste");

    for (int i = 0; i< *numLoc; i++) {
        vet[i] = 0;
    }

    while (aCopiar != NULL) {
        rand = intUniformRnd(0, (*numLoc)-1);
        printf("%d\n", rand);
        while (vet[rand] == randLoc[rand].capacidade) //verificar capacidade do espaco com nr de pessoas
            rand = intUniformRnd(0, (*numLoc)-1);

        if (listaSim == NULL) {
            listaSim = malloc(sizeof (pessoa));

            listaSim->idlocal = randLoc[rand].id;
            strcpy(listaSim->nome, aCopiar->nome);
            listaSim->idade = aCopiar->idade;
            listaSim->estado = aCopiar->estado;
            listaSim->Ndias = aCopiar->Ndias;

            listaSim->prox = NULL;
        } else {
            ppessoa ultimo = listaSim;
            while (ultimo->prox != NULL)
                ultimo = ultimo->prox;

            ppessoa temp = malloc(sizeof (pessoa));

            temp->idlocal = randLoc[rand].id;
            strcpy(temp->nome, aCopiar->nome);
            temp->idade = aCopiar->idade;
            temp->estado = aCopiar->estado;
            temp->Ndias = aCopiar->Ndias;

            ultimo->prox = temp;
            temp->prox = NULL;

        }
        vet[rand]++;
        aCopiar = aCopiar->prox;
    }
    return listaSim;
}

void imprimeListaSim(ppessoa pers) {
    ppessoa atual = pers;
    while (atual != NULL) {
        printf("Nome : %s || Idade : %d || Estado : %c || Local : %d\n", atual->nome, atual->idade, atual->estado, atual->idlocal);
        if (atual->estado == 'D') {
            printf("Dias infetado : %d \n", atual->Ndias);
        }
        atual = atual->prox;
    }
    printf("Fim\n");
    return;
}

void addPessoa(ppessoa pers) {

    ppessoa novo = malloc(sizeof (pessoa));

    printf("Nome >>> ");
    getchar();
    scanf("%99[^\n]", novo->nome);

    printf("Idade >>> ");
    scanf("%d", &novo->idade);

    novo->estado = 'D';


    printf("Nr dia doente >>> ");
    scanf("%d", &novo->Ndias);

    //verificar capacidade do local    
    printf("ID do Local >>> ");
    scanf("%d", &novo->idlocal);

    novo->prox = NULL;

    if (!pers)
        return;

    ppessoa ultimo = pers;

    while (ultimo->prox)
        ultimo = ultimo->prox;

    ultimo->prox = novo;

    return;
}

//transfere pessoas