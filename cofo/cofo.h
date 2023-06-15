#ifndef __COFO_H
#define __COFO_H

struct Cofo{};

// sucesso -> Cofo *  |  erro -> NUll
struct Cofo *criarCofo( int maxItens);

// sucesso -> 1  |  erro -> 0
int adicionaNumCofo(struct Cofo* c, int num);

// está no cofo -> (retorna posição do primeiro igual ao valor passado) |  não está no cofo -> -1
int verificaNumCofo(struct Cofo* c, int num);

// sucesso em remover -> 1  |  erro -> 0
int removerNumCofo(struct Cofo* c, int num);

// sucesso  -> 1  |  erro -> 0
int destruircofo(struct Cofo* c);

void imprimeItens(struct Cofo* c);

#endif // __COFO_H
