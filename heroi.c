#include<stdio.h>
#include "mapa.h"
#include "heroi.h"
#include "fantasma.h"

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
		direcao == DIREITA;
}

void move(char direcao,POS* pos) {
	if(!ehDirecao(direcao))	
		return;

	int proximox = pos->x;
	int proximoy = pos->y;

	switch(direcao) {
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
	if (!ehPersonagem(&m,PILULA,proximox,proximoy)){
		tempilula=1;
	}
	andaMapa(&m, pos->x, pos->y, proximox, proximoy);
	pos->x = proximox;
	pos->y = proximoy;
}