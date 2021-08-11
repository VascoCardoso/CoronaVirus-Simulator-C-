/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simulacao.h
 * Author: vascocardoso
 *
 * Created on 3 June 2020, 04:23
 */

#ifndef SIMULACAO_H
#define SIMULACAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Espaco.h"
#include "Pessoas.h"
#include "utils.h"

void taxaDisseminacao(ppessoa pplSim, int nrLoc, int *vet);
void probRecuperacao(ppessoa pplSim, int nrLoc, int *vet);

#endif /* SIMULACAO_H */

