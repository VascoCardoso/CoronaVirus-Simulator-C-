/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Simulacao.h"

void taxaDisseminacao(ppessoa pplSim, int nrLoc, int *vet) {
    int totPess = 0, randPess = 0, cont = 0, txdiss=0;
    ppessoa aux = pplSim;
    
    while (pplSim != NULL) {
        printf("Aqui2\n");
        if (pplSim->estado == 'D') {
            printf("Aqui3\n");
            
            
         /*  for (int i = 1; i < nrLoc+1; i++) {
                if (pplSim->idlocal == i)
                    totPess = vet[i];
            } */
            
            totPess = vet[pplSim->idlocal];
            
            printf("totPess : %d\n", totPess);
            printf("Aqui4\n");
            
            randPess = intUniformRnd(1, totPess);
            
            printf("randPess : %d\n", randPess);

            txdiss = probEvento(0.05);
            
            printf("taxa : %d\n", txdiss);
            
            

        //    for (int j = 0; j < txdiss; j++) {
            if(txdiss==1){
                printf("Aqui5\n");
                while (aux != NULL) {
                  //  printf("Aqui6\n");
                    if (pplSim->idlocal == aux->idlocal)
                        cont++;
                  //  printf("Aqui7\n");
                    if (cont == randPess) {
                        if (aux->estado == 'S') {
                            aux->estado = 'D';
                            aux->Ndias = 1;
                        }
                    }
                    aux = aux->prox;
                }
            }
            //}
        }
        pplSim = pplSim->prox;
    }
}

void probRecuperacao(ppessoa pplSim, int nrLoc, int *vet) {
    
}