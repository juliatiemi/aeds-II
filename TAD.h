#ifndef _TAD_H_
#define _TAD_H_

#include <stdio.h>
#include <stdlib.h>

/*---------------------------------------------------------------
Estrutura: PGM
Função: armazenar os dados de uma imagem do formato PGM
Variáveis:
  -c: número de colunas da imagem em pixels
  -l: número de linhas da imagem em pixels
  -maximo: valor maximo de cada pixel
  -dados: matriz de armazenamento dos pixels
---------------------------------------------------------------*/
typedef struct {
  int c;
  int l;
  unsigned char maximo;
  unsigned char **dados;
} PGM;

/*---------------------------------------------------------------
Estrutura: Ponto
Função: armazenar as coordenadas de um ponto
Variáveis:
  -x: coordenada do eixo das abscissas
  -y: coordenada do eixo das ordenadas
---------------------------------------------------------------*/
typedef struct {
  int x;
  int y;
} Ponto;

/*---------------------------------------------------------------
Protótipo: PGM *LePGM(char* entrada)
Função: ler a imagem no formato PGM do arquivo entrada e armazenar seus dados em uma variável do tipo PGM
Entrada: um dos argumentos de entrada dados na execução do programa
Saída: um ponteiro para uma estrutura PGM com os dados da imagem
---------------------------------------------------------------*/
PGM *LePGM(char* entrada);

/*---------------------------------------------------------------
Protótipo: int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p)
Função: calcular a correlação cruzada entre a imagem da cena na posiçao p = (x, y) e a imagem do objeto e retorna este valor
Entrada: a estrutura PGM da cena e do objeto contendo seus respectivos dados e a estrutura Ponto que dá a posição a ser analisada
Saída: um inteiro contendo o valor da correlação cruzada
---------------------------------------------------------------*/
int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p);

/*---------------------------------------------------------------
Protótipo: Ponto JanelaDeslizante(PGM *cena, PGM *obj)
Função: aplicar o algorítmo da janela deslizante de modo a percorrer os pixels da imagem cena e aplicar nela o algorítmo da correlação cruzada, retornando no final o ponto onde houver o maior valor
Entrada: a estrutura PGM da cena e do objeto contendo seus respectivos dados
Saída: uma estrutura ponto da região de maior valor segundo a correlação cruzada
---------------------------------------------------------------*/
Ponto JanelaDeslizante(PGM *cena, PGM *obj);

/*---------------------------------------------------------------
Protótipo: void Saida(char* entrada, Ponto p)
Função: imprimir no arquivo as coordenadas y x do ponto onde foi encontrado o maior valor pela correlação cruzada
Entrada: um dos argumentos de entrada na execução do programa e uma estrutura Ponto contendo as coordenadas do ponto retornado pela função JanelaDeslizante
Saída: não se aplica
---------------------------------------------------------------*/
void Saida(char* entrada, Ponto p);

void Desaloca(PGM *imagem);

#endif
