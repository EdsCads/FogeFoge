#ifndef HEROI_H
#define HEROI_H

#define CIMA 'W'
#define BAIXO 'S'
#define DIREITA 'D'
#define ESQUERDA 'A'

int getPilula();
int setPilula(int valor);
void explodePilula();
void explodePilula2(int x,int y,int somax,int somay,int qtd);
int ehBomba(char bomba);

int sair();
void move(char direcao,POS* p);

int ehDirecao(char direcao);

#endif