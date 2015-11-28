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
	
	/*insereWord(arv, arv->raiz, "ja", M);
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
	*/
	
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "b", M);
	insereWord(arv, arv->raiz, "b", M);
	insereWord(arv, arv->raiz, "c", M);
	insereWord(arv, arv->raiz, "c", M);
	insereWord(arv, arv->raiz, "d", M);
	insereWord(arv, arv->raiz, "d", M);
	insereWord(arv, arv->raiz, "e", M);
	insereWord(arv, arv->raiz, "e", M);
	insereWord(arv, arv->raiz, "f", M);
	insereWord(arv, arv->raiz, "f", M);
	insereWord(arv, arv->raiz, "g", M);
	insereWord(arv, arv->raiz, "g", M);
	insereWord(arv, arv->raiz, "h", M);
	insereWord(arv, arv->raiz, "h", M);
	insereWord(arv, arv->raiz, "i", M);
	insereWord(arv, arv->raiz, "i", M);
	insereWord(arv, arv->raiz, "j", M);
	insereWord(arv, arv->raiz, "j", M);
	insereWord(arv, arv->raiz, "k", M);
	insereWord(arv, arv->raiz, "k", M);
	insereWord(arv, arv->raiz, "l", M);
	insereWord(arv, arv->raiz, "l", M);
	insereWord(arv, arv->raiz, "m", M);
	insereWord(arv, arv->raiz, "m", M);
	insereWord(arv, arv->raiz, "n", M);
	insereWord(arv, arv->raiz, "n", M);
	insereWord(arv, arv->raiz, "o", M);
	insereWord(arv, arv->raiz, "o", M);
	insereWord(arv, arv->raiz, "p", M);
	insereWord(arv, arv->raiz, "p", M);
	insereWord(arv, arv->raiz, "q", M);
	insereWord(arv, arv->raiz, "q", M);
	insereWord(arv, arv->raiz, "r", M);
	insereWord(arv, arv->raiz, "r", M);
	insereWord(arv, arv->raiz, "s", M);
	insereWord(arv, arv->raiz, "s", M);
	insereWord(arv, arv->raiz, "t", M);
	insereWord(arv, arv->raiz, "t", M);
	insereWord(arv, arv->raiz, "u", M);
	insereWord(arv, arv->raiz, "u", M);
	insereWord(arv, arv->raiz, "v", M);
	insereWord(arv, arv->raiz, "v", M);
	insereWord(arv, arv->raiz, "w", M);
	insereWord(arv, arv->raiz, "w", M);
	insereWord(arv, arv->raiz, "x", M);
	insereWord(arv, arv->raiz, "x", M);
	insereWord(arv, arv->raiz, "y", M);
	insereWord(arv, arv->raiz, "y", M);
	insereWord(arv, arv->raiz, "z", M);
	insereWord(arv, arv->raiz, "z", M);
	
	
	imprimePaginas(arv, arv->folhaE);
	//printf("\nRAIZ[%s] end[%p]\n", arv->raiz->palavras->first->word, arv->raiz);
	//printf("\nRAIZ[%s] end[%p]\n", arv->raiz->palavras->first->word, arv->raiz);
	//printf("\nRAIZ[%s] end[%p]\n", arv->raiz->palavras->first->word, arv->raiz);
	//printf("\nRAIZ[%s] end[%p]\n", arv->raiz->palavras->first->word, arv->raiz);
	//printf("\nRAIZ[%s] end[%p]\n", arv->raiz->palavras->first->word, arv->raiz);
	
	
	
	
	
	
	
	
	
	return 0;
}





