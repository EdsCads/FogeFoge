#include <time.h>
#include <stdlib.h>
#include "mapa.h"
#include "fantasma.h"

int fantasmaVai(int xAtual,int yAtual,int* xDestino,int* yDestino){
  int opcoes[4][2]={
    {xAtual,yAtual+1},
    {xAtual+1,yAtual},
    {xAtual,yAtual-1},
    {xAtual-1,yAtual}
  };

	srand(time(0));

  for(int i=0;i<10;i++){
    int posicao = rand() % 4;

		if(podeAndar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) if(podeAndar(&m, PILULA, opcoes[posicao][0], opcoes[posicao][1])){
			*xDestino = opcoes[posicao][0];
			*yDestino = opcoes[posicao][1];
			return 1;
		}
  }

  return 0;
}

void andaFantasma(){
  MAPA copia;
  copiaMapa(&copia,&m);
  for(int i=0;i<copia.linhas;i++){
    for(int j=0;j<copia.colunas;j++){
      if(copia.matriz[i][j] == FANTASMA) {

				int xdestino;
				int ydestino;

				int encontrou = fantasmaVai(i, j, &xdestino, &ydestino);

				if(encontrou) {
					andaMapa(&m, i, j, xdestino, ydestino);
				}
      }
    }
  }
	liberaMapa(&copia);
}
