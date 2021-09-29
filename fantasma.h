#ifndef FANTASMA_H
#define FANTASMA_H
#define FANTASMA 'F'

typedef struct
{
    int x,y;
}FANTAS;

FANTAS f;

int fantasmaVai(int xAtual,int yAtual,int* xDestino,int* yDestino);

void andaFantasma();

#endif