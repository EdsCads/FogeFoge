#ifndef MAPA_H
#define MAPA_H

#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

typedef struct{
	char** matriz;
	int linhas;
	int colunas; 
}MAPA;

MAPA m;

void alocaMapa(MAPA* m);
void lerMapa(MAPA* m);
void liberaMapa(MAPA* m);
void exibeMapa(MAPA* m);
void andaMapa(MAPA* m,
							int xOrigem,
							int yOrigem,
							int xdestino,
							int destino);
							
int podeAndar(MAPA* m,char personagem,int x, int y);
int podeIr(MAPA* m, int x, int y);
int ehParede(MAPA* m, int x, int y);
void copiaMapa(MAPA* destino,MAPA* origem);
int ehPersonagem(MAPA* m,char personagem,int x,int y);

typedef struct{
	int x;
	int y;
}POS;

POS p;

int  encontraMapa(MAPA* m, POS* p, char c);



#endif