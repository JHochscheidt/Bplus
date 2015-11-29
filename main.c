#include "bpluslib.h"
#include <stdio.h>
#include <stdlib.h>


/*
 * ./a.out
 *  numero_do_atributo 
 * 	numero_caracteres_indexados
 *  ordem_arvore
 *	
 * */
int main(int argc, char **argv){
	
	//printf("M [%d]\n", M);
	
	int arg1 = atoi(argv[1]);// numero_do_atributo
	int arg2 = atoi(argv[2]);// numero_caracteres_indexados
	int M = atoi(argv[3]);// ordem da arvore
	//int a;
	TpTree *arv = novaArv();
	char *buffer = malloc(sizeof(char)*512);
	char *pch = NULL;
	char *reg =NULL;
	FILE *pFile = fopen("arquivo_teste.csv", "r");
	int campo = 1;
	
	fgets(buffer, 150, pFile); // pula a primeira linha onde tem o nome dos atributos
	while(fgets(buffer, 511, pFile)!= NULL){

		pch = strtok (buffer, ",\"");//vai até a info do primeiro campo
		if(pch[0] == '\n' || pch[0] == EOF || pch == NULL){
			break;
		}
		else{
			campo = 1;
			do{
				if(campo == arg1){// copiar os n(param) caracter aq strncpy() 
					if(arg2 < (int)(strlen(pch)-1)){
						reg = malloc(sizeof(char)*(arg2+1));
						strncpy(reg, pch, arg2);
						insereWord(arv, arv->raiz, pch, M);
					}else//pch é menor doq o tamanho de caracterres à serem indexados
						insereWord(arv, arv->raiz, pch, M);
				}
				if(pch[0] == ' '){
					
					pch = strtok (buffer,  "\"");
					while(pch[0]==','){
						campo++; //
						pch = strtok (NULL,  "\"");						
					}
				}
				while(!isalnum(pch[0]) &&  pch[0] != '\n');{			
					pch = strtok (NULL,  "\"");//vai p/ prox iterração apenas qnd 
					if(pch != NULL){
						while(pch[0]==','){							
							campo++; //
							pch = strtok (NULL,  "\"");
						}	
					}
				}
				if(pch == NULL)
					break;	
			}while(pch[0] != '\n' || pch[0] == EOF || pch == NULL);
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
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
	/*
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "a", M);
	insereWord(arv, arv->raiz, "b", M);
	insereWord(arv, arv->raiz, "b", M);
	insereWord(arv, arv->raiz, "b", M);
	insereWord(arv, arv->raiz, "c", M);
	insereWord(arv, arv->raiz, "c", M);
	insereWord(arv, arv->raiz, "c", M);
	insereWord(arv, arv->raiz, "d", M);
	insereWord(arv, arv->raiz, "d", M);
	insereWord(arv, arv->raiz, "d", M);
	insereWord(arv, arv->raiz, "e", M);
	insereWord(arv, arv->raiz, "e", M);
	insereWord(arv, arv->raiz, "e", M);
	insereWord(arv, arv->raiz, "f", M);
	insereWord(arv, arv->raiz, "f", M);
	insereWord(arv, arv->raiz, "f", M);
	insereWord(arv, arv->raiz, "g", M);
	insereWord(arv, arv->raiz, "g", M);
	insereWord(arv, arv->raiz, "g", M);
	insereWord(arv, arv->raiz, "h", M);
	insereWord(arv, arv->raiz, "h", M);
	insereWord(arv, arv->raiz, "h", M);
	insereWord(arv, arv->raiz, "i", M);
	insereWord(arv, arv->raiz, "i", M);
	insereWord(arv, arv->raiz, "i", M);
	insereWord(arv, arv->raiz, "j", M);
	insereWord(arv, arv->raiz, "j", M);
	insereWord(arv, arv->raiz, "j", M);
	insereWord(arv, arv->raiz, "k", M);
	insereWord(arv, arv->raiz, "k", M);
	insereWord(arv, arv->raiz, "k", M);
	insereWord(arv, arv->raiz, "l", M);
	insereWord(arv, arv->raiz, "l", M);
	insereWord(arv, arv->raiz, "l", M);
	insereWord(arv, arv->raiz, "m", M);
	insereWord(arv, arv->raiz, "m", M);
	insereWord(arv, arv->raiz, "m", M);
	insereWord(arv, arv->raiz, "n", M);
	insereWord(arv, arv->raiz, "n", M);
	insereWord(arv, arv->raiz, "n", M);
	insereWord(arv, arv->raiz, "o", M);
	insereWord(arv, arv->raiz, "o", M);
	insereWord(arv, arv->raiz, "o", M);
	insereWord(arv, arv->raiz, "p", M);
	insereWord(arv, arv->raiz, "p", M);
	insereWord(arv, arv->raiz, "p", M);
	insereWord(arv, arv->raiz, "q", M);
	insereWord(arv, arv->raiz, "q", M);
	insereWord(arv, arv->raiz, "q", M);
	insereWord(arv, arv->raiz, "r", M);
	insereWord(arv, arv->raiz, "r", M);
	insereWord(arv, arv->raiz, "r", M);
	insereWord(arv, arv->raiz, "s", M);
	insereWord(arv, arv->raiz, "s", M);
	insereWord(arv, arv->raiz, "s", M);
	insereWord(arv, arv->raiz, "t", M);
	insereWord(arv, arv->raiz, "t", M);
	insereWord(arv, arv->raiz, "t", M);
	insereWord(arv, arv->raiz, "u", M);
	insereWord(arv, arv->raiz, "u", M);
	insereWord(arv, arv->raiz, "u", M);
	insereWord(arv, arv->raiz, "v", M);
	insereWord(arv, arv->raiz, "v", M);
	insereWord(arv, arv->raiz, "v", M);
	insereWord(arv, arv->raiz, "w", M);
	insereWord(arv, arv->raiz, "w", M);
	insereWord(arv, arv->raiz, "w", M);
	insereWord(arv, arv->raiz, "x", M);
	insereWord(arv, arv->raiz, "x", M);
	insereWord(arv, arv->raiz, "x", M);
	insereWord(arv, arv->raiz, "y", M);
	insereWord(arv, arv->raiz, "y", M);
	insereWord(arv, arv->raiz, "y", M);
	insereWord(arv, arv->raiz, "z", M);
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





