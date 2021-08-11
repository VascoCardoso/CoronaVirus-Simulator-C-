/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: vascocardoso
 *
 * Created on 2 April 2020, 01:13
 */

#include <stdio.h>
#include <stdlib.h>
#include "Espaco.h"
#include "Pessoas.h"
#include "utils.h"
#include "Simulacao.h"

/*
 * 
 */

int main(int argc, char** argv) {
    plocal esp_local=NULL; 
    ppessoa ppl=NULL;
    ppessoa pplSim=NULL;
    ppessoa pess=NULL;
    
    char nomefichloc[25], nomefichtxt[25];
    int tambin;
    
    initRandom();
    

    printf("\t\t ---------- FASE PREPARACAO ---------- \n");
    
    printf("\nIntroduza o nome do ficheiro a carregar para os espacos \n");
    scanf("%s",nomefichloc);
    
    esp_local = carregaFichbin(nomefichloc,&tambin);
    
    listaEsp(esp_local,&tambin);
    
    int vet[tambin];
    
    printf("\n\nIntroduza o nome do ficheiro a carregar para as pessoas \n");
    scanf("%s",nomefichtxt);
    
    ppl = carregaFichtxt(nomefichtxt);
    //imprimeLista(ppl);
    
    pplSim = pplSimu(ppl, esp_local, &tambin, vet);
    printf("\n\t --->> Pessoas Participantes na Simulacao \n\n");
    imprimeListaSim(pplSim);
    
  /*  addPessoa(pplSim);
    imprimeListaSim(pplSim); */
    
    taxaDisseminacao(pplSim, tambin, vet);
    imprimeListaSim(pplSim);
    
    taxaDisseminacao(pplSim, tambin, vet);
    imprimeListaSim(pplSim); 
    
    return (EXIT_SUCCESS);
}

