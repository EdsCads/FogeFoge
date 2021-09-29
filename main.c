#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "heroi.h"
#include "fantasma.h"

int main() {
  char comand;
  lerMapa(&m);
	encontraMapa(&m,&p,HEROI);
  do{
		system("clear");
		exibeMapa(&m);
		scanf(" %c", &comand);

		move(comand,&p);
		printf("Atual posição do heroi: %d %d\n",p.x,p.y);
    andaFantasma();
  }while (!sair());
	
  liberaMapa(&m);
}