/*
	Aluno: Eduardo Nunes Cadilhe
	Programa: Foge_Foge
	Versão: 0.3
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mapa.h"
#include "heroi.h"
#include "fantasma.h"
#include "interface.h"

int main() {
  char comand;
  lerMapa(&m);
	encontraMapa(&m,&p,HEROI);
  do{
		system("clear");
		printf("PILULA: %s\n",getPilula() ? "SIM" : "NAO");
		exibeMapa(&m);
		scanf(" %c", &comand);

		move(toupper(comand),&p);
    andaFantasma();
  }while (!sair());
	
  liberaMapa(&m);
}