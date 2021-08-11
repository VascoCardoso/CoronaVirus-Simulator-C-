/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Espaco.h
 * Author: vascocardoso
 *
 * Created on 2 April 2020, 01:13
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef ESPACO_H
#define ESPACO_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct Espacos{
        int id; //identificador unico do local
        int capacidade; //capacidade maxima de pessoas
        int liga[3]; //id das ligaçoes (-1) nos casos nao usados
        //int ocupacao; //nr de pessoas por sala
    }local, *plocal;
    
    typedef struct Espacos{
        int id; //identificador unico do local
        int capacidade; //capacidade maxima de pessoas
        int liga[3]; //id das ligaçoes (-1) nos casos nao usados
        int ocupacao; //nr de pessoas por sala
    }espaco, *pespaco;

    plocal carregaFichbin(char *nomefich, int *total);
    void listaEsp(plocal esp, int *tam);

#ifdef __cplusplus
}
#endif

#endif /* ESPACO_H */

