#ifndef HEROI_H
#define HEROI_H

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define PILULA 'P'

int sair();
void move(char direcao,POS* p);

int ehDirecao(char direcao);

#endif