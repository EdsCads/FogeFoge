#ifndef FANTASMA_H
#define FANTASMA_H

typedef struct
{
    int x,y;
}FANTAS;

FANTAS f;

int fantasmaVai(int xAtual,int yAtual,int* xDestino,int* yDestino);

void andaFantasma();

#endif