#define BPLUSLIB_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
// #define M atoi(argv[1])// ordem da arvore

typedef struct tp_pag{
	int nItens; // saber o numero de itens da pagina/nó
	unsigned int folha; // saber se a pagina é uma folha 
	struct tp_lista_word *palavras; // lista contendo as palavras da pagina 
	// struct tp_pag *filhos;
	struct tp_pag *irmaoD; // vai ter irmao a direita somente se a pagina for uma folha
	struct tp_word *pai;
}TpPagina;

typedef struct tp_lista_word{
	int nItens; /*
				 * nItens nao pode ser maior do que 2*M, sendo M o numero de registros ou palavras por pagina
				 * nItens tbm nao pode ser menore do que M. 
				 */
	struct tp_word *first;
	struct tp_word *last;	
}TpListaWord;

typedef struct tp_word{
	char *word;
	struct tp_pag *myPage;
	struct tp_word *ant;
	struct tp_word *prox;
	struct tp_pag *filhoEsquerda; // sempre terá filho a esquerda, que são os valores menores 
	struct tp_pag *filhoDireita; // terá filho a direita somente se for o ultimo nodo da lista daquela pagina
}TpWord;

typedef struct tp_lista{
    int nItens;
    TpPagina *last;
    TpPagina *first;
}TpLista;

typedef struct tp_tree{
	TpPagina *raiz;	
	TpPagina *folhaE; // primeira folha a esquerda na arvore
}TpTree;

//--------------------------

TpPagina *insereWord(TpTree *arv, TpPagina *raiz, char *word, int ordemArvore);

void split(TpTree *arv,TpPagina *pagSplitar, int ordemArvore);


TpPagina *novaPag(); // cria uma nova pagina
TpListaWord *novaListaWord(); // cria uma lista de palavras "vetor de palavras dentro da pagina"
TpWord *novaWord(); // nova palavra, que pertence a ListaWord que esta dentro da pagina
TpLista *novaLista(); // cria lista das folhas encadeadas
TpTree *novaArv(); // cria uma nova B+ tree

void imprimeArvore(TpPagina *raiz);
void imprimePaginas(TpTree *arv, TpPagina *folhaE);
