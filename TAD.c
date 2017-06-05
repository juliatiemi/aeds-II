#include "TAD.h"

PGM *LePGM(char* entrada){
  PGM *imagem;
  int i, j;
  int aux;  //facilita a leitura do valor maximo
  FILE *arq;
  arq = fopen(entrada, "rt");   //abre arquivo como arquivo de texto para leitura
  if(arq == NULL) {  //teste se o arquivo é existente
      printf("Erro ao abrir arquivo.\n");
      exit(1);
  }
  imagem = malloc(1 * sizeof (PGM));
  fscanf(arq, "P2");  //Essa leitura ignora a linha P2 do arquivo de imagem
  fscanf(arq, "%d%d%d", &imagem->c, &imagem->l, &aux);
  imagem->maximo = (unsigned char)aux; //transferencia do valor maximo para sua varíavel unsigned char
  imagem->dados = malloc(imagem->l * sizeof (unsigned char *)); //alocação da matriz
  for(i = 0; i < imagem->l; i++){
    imagem->dados[i] = malloc(imagem->c * sizeof (unsigned char));
  } //fim da alocação
  for(i = 0; i < imagem->l; i++) {  //armazenamento de cada pixel na matriz
    for(j = 0; j < imagem->c; j++) {
      fscanf(arq, " %d", &aux);
      imagem->dados[i][j] = (unsigned char)aux;
    }
  } //fim do aramzenamento
  fclose(arq);  //fecha o arquivo
  return imagem;
}

int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p) {
  int resultado;
  int i, j;
  int x, y;
  resultado = 0;  //seta um valor minimo inicial; como todos o valores são positivos, foi determinado que este seria 0
  x = p.x;
  y = p.y;
  for(i = 0; i < obj->l; i++){
    for(j = 0; j < obj->c; j++) {
      resultado = cena->dados[x+i][y+j] * obj->dados[i][j] + resultado; //correlação cruzada
    }
  }
  return resultado;
}

Ponto JanelaDeslizante(PGM *cena, PGM *obj){
  Ponto p;  //ponto a ser analisado
  Ponto maximo;  //ponto que até o momento representa o maior valor pela correlação cruzada
  int max;
  int resultadoCC;  //resultado da correlação cruzada
  int i, j;
  max = 0;
  maximo.x = 0;
  maximo.y = 0;
  for(i = 0; i <= (cena->l - obj->l); i++){
    p.x = i;
    for(j = 0; j <= (cena->c - obj->c); j++) {
      p.y = j;
      resultadoCC = CorrelacaoCruzada(cena, obj, p);
      if(resultadoCC > max) { //se a correlação cruzada retornar um valor maior que o anteriormente registrado, o ponto é substituído, assim como o valor determinado como maior
        max = resultadoCC;
        maximo.x = i;
        maximo.y = j;
      }
    }
  }
  return maximo;
}

void Saida(char* entrada, Ponto p) {
  FILE *saida;
  saida = fopen(entrada, "w");  //abre o arquivo para escrita
  if(saida == NULL) {
      printf("Erro ao abrir arquivo.\n");
      exit(1);
  }
  fprintf(saida, "%d %d", p.y, p.x);  //imprime as coordenadas do ponto
  fclose(saida);  //fecha o arquivo
  return;
}

void Desaloca(PGM *imagem) {
  int i;
  for(i = 0; i < imagem->l; i++){
    free(imagem->dados[i]);
  }
  free(imagem->dados);
  free(imagem);
}
