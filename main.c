#include "bpluslib.h"
#include <stdio.h>
#include <stdlib.h>

#define M atoi(argv[1])// ordem da arvore


int main(int argc, char **argv){
	
	printf("M [%d]\n", M);
	
	//int a;
	TpTree *arv = novaArv();
	
	/*insereWord(arv, arv->raiz, "ceéobichao", M);
	insereWord(arv, arv->raiz, "jackson", M);
	insereWord(arv, arv->raiz, "kurumim", M);
	insereWord(arv, arv->raiz, "xurupita", M);
	insereWord(arv, arv->raiz, "abacate", M);
	insereWord(arv, arv->raiz, "zicamemo", M);
	insereWord(arv, arv->raiz, "olokobicho", M);
	insereWord(arv, arv->raiz, "nozquevoaheripota", M);
	insereWord(arv, arv->raiz, "huehubr", M);
	insereWord(arv, arv->raiz, "brhue", M);	
	insereWord(arv, arv->raiz, "kkkkk", M);	
	insereWord(arv, arv->raiz, "neverends", M);
	*/
	
	insereWord(arv, arv->raiz, "ja", M);
	insereWord(arv, arv->raiz, "ba", M);
	insereWord(arv, arv->raiz, "ra", M);
	insereWord(arv, arv->raiz, "ta", M);
	insereWord(arv, arv->raiz, "za", M);
	insereWord(arv, arv->raiz, "aa", M);
	insereWord(arv, arv->raiz, "ca", M);
	insereWord(arv, arv->raiz, "za", M);
	insereWord(arv, arv->raiz, "qa", M);
	insereWord(arv, arv->raiz, "ha", M);
	insereWord(arv, arv->raiz, "ea", M);
	insereWord(arv, arv->raiz, "aaaa", M);
	insereWord(arv, arv->raiz, "zae", M);
	insereWord(arv, arv->raiz, "zak", M);
	insereWord(arv, arv->raiz, "zao", M);
	insereWord(arv, arv->raiz, "zau", M);
	insereWord(arv, arv->raiz, "ficaoca", M);
	insereWord(arv, arv->raiz, "facaoca", M);
	insereWord(arv, arv->raiz, "fucaoca", M);
	insereWord(arv, arv->raiz, "feoca", M);
	insereWord(arv, arv->raiz, "fioraeoca", M);
	insereWord(arv, arv->raiz, "canela", M);
	insereWord(arv, arv->raiz, "focanela", M);
	insereWord(arv, arv->raiz, "er", M);
	insereWord(arv, arv->raiz, "eq", M);
	insereWord(arv, arv->raiz, "ew", M);
	insereWord(arv, arv->raiz, "eoq", M);
	insereWord(arv, arv->raiz, "ej", M);
	insereWord(arv, arv->raiz, "easease", M);
	
	
	imprimePaginas(arv);
	//printf("\nRAIZ[%s] end[%p]\n", arv->raiz->palavras->first->word, arv->raiz);
	
	
	
	
	
	
	
	return 0;
}
