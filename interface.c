#include <stdio.h>
#include "interface.h"
#include "mapa.h"

char desParede[4][7]={ 
							{"......"},
							{"......"},
							{"......"},
							{"......"}
};
char desPilula[4][7]={ 
							{"      "},
							{"  .-. "},
							{"  '-' "},
							{"      "}
};
char desPersonagem[4][7]={ 
							{" .--. "},
							{" | /' "},
							{" | \\. "},
							{" \\__/ "}
};
char desFantasma[4][7]={ 
							{" .--. "},
							{"| O O|"},
							{"|    |"},
							{"'^^^^'"}
};
char desVazio[4][7]={
							{"      "},
							{"      "},
							{"      "},
							{"      "},
};


void substitui(char desenho[4][7], int parte) {
	printf("%s", desenho[parte]);
}

void exibeMapa(MAPA* m) {
	for(int i = 0; i < m->linhas; i++) {

		for(int parte = 0; parte < 4; parte++) {
			for(int j = 0; j < m->colunas; j++) {

				switch(m->matriz[i][j]) {
					case FANTASMA:
						substitui(desFantasma,parte);
						break;
					case HEROI:
						substitui(desPersonagem,parte);
						break;
					case PILULA:
						substitui(desPilula,parte);
						break;
					case PAREDE_VERTICAL:
					case PAREDE_HORIZONTAL:
						substitui(desParede,parte);
						break;
					case VAZIO:
						substitui(desVazio,parte);
						break;
				}
				
			}
			printf("\n");
		}

	}
}