#include<stdio.h>
#include "mapa.h"
#include "heroi.h"
#include "fantasma.h"

int pilula=0;

int sair() {
	POS p;
	int perdeu = !encontraMapa(&m,&p,HEROI);
	int ganhou = !encontraMapa(&m,&p,FANTASMA);

	return ganhou||perdeu;
}

int ehDirecao(char direcao) {
	return
		direcao == ESQUERDA ||
		direcao == CIMA ||
		direcao == BAIXO ||
		direcao == DIREITA
		;
}
int getPilula(){
	return pilula;
}
int setPilula(int valor){
	if(valor>0)	pilula+=valor;
	else pilula-=1;
	return pilula;
}

void explodePilula(int x,int y){
	if(!getPilula()) return;
	int i;
	for(i=1;i<=3;i++){
		if(!podeAndar(&m, HEROI, x,y+i)) break;
		m.matriz[x][y+i]=VAZIO;
	}for(i=1;i<=3;i++){
		if(!podeAndar(&m, HEROI, x,y-i)) break;
		m.matriz[x][y-i]=VAZIO;
	}for(i=1;i<=3;i++){
		if(!podeAndar(&m, HEROI, x+i,y)) break;
		m.matriz[x+i][y]=VAZIO;
	}for(i=1;i<=3;i++){
		if(!podeAndar(&m, HEROI, x-i,y)) break;
		m.matriz[x-i][y]=VAZIO;
	}
	setPilula(0);
}

int ehBomba(char bomba){
	return bomba==BOMBA;
};

void move(char comando,POS* pos) {
	if(!ehDirecao(comando)){
		if(ehBomba(comando)){
			explodePilula(pos->x,pos->y);
		}
		return;
	}

	int proximox = pos->x;
	int proximoy = pos->y;

	switch(comando) {
		case ESQUERDA:
			proximoy--;
			break;
		case CIMA:
			proximox--;
			break;
		case BAIXO:
			proximox++;
			break;
		case DIREITA:
			proximoy++;
			break;
	}

	if (!podeAndar(&m,HEROI,proximox,proximoy)) {return;}
	if (ehPersonagem(&m,PILULA,proximox,proximoy)){
		setPilula(1);
	}
	andaMapa(&m, pos->x, pos->y, proximox, proximoy);
	pos->x = proximox;
	pos->y = proximoy;
}