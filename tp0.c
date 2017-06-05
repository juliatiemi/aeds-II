#include "TAD.h"

int main(int argc, char *argv[]) {
  PGM *cena, *obj;
  Ponto posicao;
  cena = LePGM(argv[1]);
  obj = LePGM(argv[2]);
  posicao = JanelaDeslizante(cena, obj);
  Saida(argv[3], posicao);
  Desaloca(cena);
  Desaloca(obj);
  return 0;
}
