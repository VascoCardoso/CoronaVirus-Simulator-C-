/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pessoas.h
 * Author: vascocardoso
 *
 * Created on 2 April 2020, 01:13
 */



#ifndef PESSOAS_H
#define PESSOAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Espaco.h"
#include "utils.h"

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct Pessoas{
        char nome[20];
        int idade;
        char estado;
        int Ndias;
        struct Pessoas *prox; //ptr p prox pessoa
        //plocal loc;
        int idlocal;
    }pessoa, *ppessoa;

    ppessoa carregaFichtxt(char *nomefich);
    void imprimeLista(ppessoa pers);
    ppessoa pplSimu(ppessoa aCopiar, plocal randLoc, int *numLoc, int *vet);
    void imprimeListaSim(ppessoa pers);
    void addPessoa(ppessoa pers);

#ifdef __cplusplus
}
#endif

#endif /* PESSOAS_H */

