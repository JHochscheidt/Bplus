#include "bpluslib.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/*
 * ./a.out
 *  numero_do_atributo 
 * 	numero_caracteres_indexados
 *  ordem_arvore
 *	
 * */
int main(int argc, char **argv){
	
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
					reg = malloc(sizeof(char)* (arg2+1));
					strncpy(reg, pch, arg2);
					printf("[%s]\n",reg);
					insereWord(arv, arv->raiz, reg, M);
					imprimePaginas(arv, arv->folhaE);
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
	
	imprimePaginas(arv, arv->folhaE);
	return 0;
}





