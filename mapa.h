#ifndef MAPA_H
#define MAPA_H

#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define FANTASMA 'F'
#define BOMBA 'B'
#define PILULA 'P'

typedef struct{
	char** matriz;
	int linhas;
	int colunas; 
}MAPA;

MAPA m;

typedef struct{
	int x;
	int y;
}POS;

POS p;

void alocaMapa(MAPA* m);
void lerMapa(MAPA* m);
void liberaMapa(MAPA* m);	
void copiaMapa(MAPA* destino,MAPA* origem);		

int podeIr(MAPA* m, int x, int y);
int ehParede(MAPA* m, int x, int y);
int ehPersonagem(MAPA* m,char personagem,int x,int y);
int podeAndar(MAPA* m,char personagem,int x, int y);
int encontraMapa(MAPA* m, POS* p, char c);
void andaMapa(MAPA* m,
							int xOrigem,
							int yOrigem,
							int xDestino,
							int yDestino);



#endif