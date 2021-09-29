#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "mapa.h"

void alocaMapa(MAPA* m){
    m->matriz=malloc(sizeof(char*) * m->linhas);
 
    for(int i = 0; i < m->linhas; i++) {
        m->matriz[i]=malloc(sizeof(char) * m->colunas + 1);
    }
}

void lerMapa(MAPA *m) {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if(f == 0) {
        printf("Erro na leitura do mapa");
        exit(1);
    }
 
    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
    alocaMapa(m);
    
    for(int i = 0; i < m->linhas; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f);
}

void exibeMapa(MAPA* m){
	for(int i = 0; i < m->linhas; i++) 
	{
    printf("%s\n", m->matriz[i]);
  }
}

int encontraMapa(MAPA* m,POS* pos,char c){
	for(int i=0;i<m->linhas;i++){
		for(int j=0;j<m->colunas;j++){
			if(m->matriz[i][j]==c){
				pos->x=i;
				pos->y=j;
				return 1;
			}
		}
	}
	return 0;
}

void liberaMapa(MAPA* m) {
    for(int i = 0; i < m->linhas; i++) {
        free(m->matriz[i]);
    }
 
    free(m->matriz);
}

int podeIr(MAPA* m, int x, int y){
	if(x >= m->linhas) 
		return 0;
	if(y >= m->colunas) 
		return 0;
	return 1;
}
int ehParede(MAPA* m, int x, int y){
	return m->matriz[x][y]==PAREDE_HORIZONTAL||
			m->matriz[x][y]==PAREDE_VERTICAL;
}

int ehPersonagem(MAPA* m,char personagem,int x,int y){
	return m->matriz[x][y]==personagem;
}

void copiaMapa(MAPA* destino,MAPA* origem){
	destino->linhas=origem->linhas;
	destino->colunas=origem->colunas;
	alocaMapa(destino);
	for(int i=0;i<origem->linhas;i++){
		strcpy(destino->matriz[i],origem->matriz[i]);
	}
}

void andaMapa(MAPA* m, int xOrigem, int yOrigem, int xDest, int yDest){
	char aux;
	aux = m->matriz[xDest][yDest];
	m->matriz[xDest][yDest]=m->matriz[xOrigem][yOrigem];
	m->matriz[xOrigem][yOrigem]=aux;
}

int podeAndar(MAPA* m,char personagem,int x, int y){
	return 
		!ehParede(m,x,y) &&
		podeIr(m,x,y) &&
		!ehPersonagem(m,personagem,x,y);
}