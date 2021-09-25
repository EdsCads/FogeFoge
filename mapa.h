#define __COLUNA 10
#define __LINHA 5

void alocMapa(){
  int* mapa=malloc(sizeof(char*)*__LINHA);
  for (int i;i<__LINHA;i++){
    mapa=malloc(sizeof(char*)*__COLUNA+1);
  }


}

void lerMapa(){
  FILE* f;
  f=fopen("mapa.txt","a");
  if(f==0){
    printf("Deu ruim na abertura do aqrquivo");
    return 0;
  }
  
  fscanf(f, "%d %d", &__LINHA,&__COLUNA);
  alocMapa();
  fclose();
}

liberamapa(){
  for(int i;i<__LINHA;i++){
    free(mapa[i]);
  }

  
  free(mapa);
}