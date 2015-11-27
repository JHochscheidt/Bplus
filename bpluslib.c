#include "bpluslib.h"


/*
TpPagina *insere(TpTree *tree, TpPagina *root, char *str){
	//if(root == NULL) return;
	
	TpPagina *auxr = tree->raiz;
	TpPagina *aux = root;
	int i;
	
	if(strcmp(str, aux->reg[0]) < 0){ //str < aux, descendo à esuqerda
		
		insere(auxr, aux->filhos[0], str);
	
	}else if(strcmp(str, aux->reg[aux->nItens - 1]) > 0){//str < aux, descendo à direita
		
		insere(auxr, aux->filhos[aux->nItens], str);
		
	}else if(strcmp(str, aux->reg[0]) > 0 && strcmp(str, aux->reg[aux->nItens - 1]) < 0){ //pertence a esse nodo
		if(folha){//é folha? senao, chamar folha //correr vetor e inserir 
			
			//precisa split? se sim,
			
			
			if(aux->nItens < MM){// não precisa de split
				//escrever primeiro o caso de não precisa de split
			}else{ // precisa de split   (verificar em algum lugar se o pai precisa de split
				if(){// da pra jogar pro irmao?
				
				//joga pro irmao
				
				}else{
				
					//splita e joga pro pai, confere se o pai suporta ou precisa de split tb(verificar se o pai pode jogar pro seu irmao
				}
			}
			
			
			
			
		}else{//chamar folha
		
			for(i=0;i < aux->nItens;i++){//talvez um busca binaria antes de entrar nesse laço
				if(strcmp(str, aux->reg[i]) > 0 && strcmp(str, aux->reg[i+1 */ /*verificar se isso n da seg. faulth*/ /*]) < 0)){
					insere(auxr, aux->filhos[i???], str);
				}	
			}
		}		
	}	
	*/	
		/*	
	if(auxr == NULL){//ARVORE VAZIA
		auxr = novaPag();
		auxr->nItens++;
		strcpy(auxr->reg[0], str);
		return auxr;
	}else if(auxr == aux){//nodo passado é raiz
		if(aux->nItens < M){// há espaço para inserir na raiz
			
			aux->nItens++;
		}else{//split, verificar se ouve overflow na folha
			
		
		}
	
	}
	*//*
	
	
		
	
	return aux;
}
*/


TpPagina *insereWord(TpTree *arv, TpPagina *raiz, char *word, int ordemArvore){
	//puts("INS");
	//arvore vazia
	if(arv->raiz == NULL){
		//puts("INSERCAO ARVORE VAZIA"); 
		arv->raiz = novaPag();
		if(arv->raiz != NULL){
			arv->raiz->folha = TRUE;
			arv->folhaE = arv->raiz;
			arv->raiz->palavras = novaListaWord();
			
			if(arv->raiz->palavras != NULL){
				arv->raiz->palavras->first = novaWord();
				if(arv->raiz->palavras->first != NULL){
					arv->raiz->palavras->first->myPage = raiz;
					
					arv->raiz->palavras->first->word = malloc(sizeof(char) * ((int) strlen(word) + 1));
					if(arv->raiz->palavras->first->word != NULL){
						strcpy(arv->raiz->palavras->first->word, word);
						arv->raiz->palavras->last = arv->raiz->palavras->first;
						arv->raiz->palavras->nItens++;
					}else{
						puts("error word");
					}
				}else{
					puts("error first");
				}
			}else{
				puts("error palavras");
			}
		}else{
			puts("error raiz");
		}
	} // fim do caso que a arvore esta vazia. insercao da primeira palavra
	
	// caso a arvore ja exista
	else{ // arvore ja existe
		//puts("INSERCAO NORMAL");
		TpPagina *aux = arv->raiz;
		int cmp = 0;
		//int cmp2 = 0;
		// desce na arvore ate achar o lugar na folha
		while(!aux->folha){
			// comparar com o ultimo elemento da lista
				// se for maior ja desce
			cmp = strcmp(word, aux->palavras->last->word);
			if(cmp >= 0){
				// word é maior ou é a mesma que a ultima palavra da pagina
				// anda pra direita na arvore
				aux = aux->palavras->last->filhoDireita;
				
			}else{
				// se nao for maior ou igual a ultima palavra da pagina
				// percorre a lista da pagina em ordem crescente ate achar o lugar pra descer na arvore
				TpWord *auxLista = aux->palavras->first;
				int cmpLista = 0;
				while(auxLista != NULL){
					cmpLista = strcmp(word, auxLista->word);
					if(cmpLista < 0){
						// desce pra proxima pagina a esquerda
						aux = auxLista->filhoEsquerda;
						break;
					}else if(auxLista->prox != NULL){
						auxLista = auxLista->prox;
					}else if(auxLista->prox == NULL){
						aux = auxLista->filhoDireita;
						break;
						// talvez essa verificacao ja nao seja necessaria
						//pois acima ja esta verificando se a WORD é maior que a ultima palavra da lista.
						// verificar isso posteriormente
						// de qualquer forma, se chegou aqui deve-se alocar uma nova pagina
					}
				} // fim do while que percorre a lista da pagina
			  
			}
			// falta fazer o incremento do AUX para descer na arvore
		} // fim do while que percorre a arvore
		
		// aux é folha
		//verificar o tamanho atual da pagina folha
		//encontrar o lugar da nova WORD na pagina
		if(aux->palavras->nItens <= (2*ordemArvore)){
			//puts("FOLHA"); 
			/*aux->palavras->nItens <= (2*ordemArvore)
			 *permite que se insira uma palavra a mais do que o tamanho permitido para a pagina
			 *e ai faz o split caso estoure o limite
			 */
			 
			// pagina nao está cheia. Faz a insercao simples
			// procura posicao na lista da pagina e insere
			TpWord *auxWord = aux->palavras->first;
			int cmp = 0;
			//if(aux->folha) puts("aux é FOLHA");
			while(auxWord != NULL){
				//puts("laço auxWord");
				cmp = strcmp(word, auxWord->word);
				if(cmp < 0){
					//puts("cmp");
					//inserir antes do atual
					TpWord *nWord = novaWord();
					nWord->word = (char*) malloc(sizeof(char) * ((int) strlen(word) + 1));
					if(nWord->word != NULL){
						strcpy(nWord->word, word);
						if(auxWord->ant == NULL){ // caso o atual seja o primeiro da lista
							aux->palavras->first = nWord;
						}else if(auxWord->ant != NULL){ // caso o atual seja um nodo intermediario
							auxWord->ant->prox = nWord;
							nWord->ant = auxWord->ant; 
						}
						auxWord->ant = nWord;
						nWord->prox = auxWord;
						aux->palavras->nItens++;
						nWord->myPage = aux;
					
						//printf("pagina [%s]\n",nWord->myPage->palavras->first->word);	
						// verificar se estourou o tamanho da pagina
						// se estourou fazer split
						if(aux->palavras->nItens > (2*ordemArvore)){
							//puts("SPLIT");
							split(arv, aux ,ordemArvore);
							//alocar nova pagina para o filho e irmaos direito do eleito 
							//atualizar ponteiros de lista das paginas splitadas/
							//inserir a WORD eleita no pai
							// anexar nova pagina como filho a direita 
							//verificar se estourou o limite da pagina do pai com a insercao do ELEITO
						}
										
						break;						
					}
				}else if(auxWord->prox != NULL){
					auxWord = auxWord->prox;
				}else{
					//puts("final da lista");
					// nao tem proximo
					// insere no final da lista
					TpWord *nWord = novaWord();
					nWord->word = (char*) malloc(sizeof(char) * ((int) strlen(word) + 1));
					if(nWord->word != NULL){
						strcpy(nWord->word, word);
						
						auxWord->prox = nWord;
						nWord->ant = auxWord;
						aux->palavras->last = nWord;
						aux->palavras->nItens++;
						
						nWord->myPage = aux;	
						// verificar se estourou o tamanho da pagina
						// se estourou fazer split
						//puts("fez insercao");
						if(aux->palavras->nItens > (2*ordemArvore)){
							//puts("SPLIT");
							//printf("%d", aux->palavras->nItens);
							split(arv, aux ,ordemArvore);
							
							//alocar nova pagina para o filho e irmaos direito do eleito 
							//atualizar ponteiros de lista das paginas splitadas/
							//inserir a WORD eleita no pai
							// anexar nova pagina como filho a direita 
							//verificar se estourou o limite da pagina do pai com a insercao do ELEITO
						}
						//break;						
					}
					break;
				}
			}
		}else{ // pagina folha esta cheia
			puts("pagina folha esta cheia");
			// inserir na folha, porem devemos quebra-la
			// ou verificar se um irmao tem disponibilidade de receber um nodo ROTACAO :XXXXXX
		}
	}
	//puts("FIM INSERRRRRRRRRRRRRRRRRRRRRR");	
	return NULL;
}

void split(TpTree *arv, TpPagina *pagSplitar, int ordemArvore){
	int pos = 0;
	TpWord *wSplit = pagSplitar->palavras->first;
	while(pos < ordemArvore){
		wSplit = wSplit->prox;
		pos++;
	}
	puts("SPLIT");
	TpWord *nWord = novaWord();
	nWord->word = (char*) malloc(sizeof(char) * ((int) strlen(wSplit->word) + 1));
	strcpy(nWord->word, wSplit->word); // clone - verificar o tamanho - possivel problema
	
	
	// casos de split
	// pai null
	if(pagSplitar->pai == NULL){
		puts("pai null");
		TpPagina *nPag = novaPag();
		arv->raiz = nPag;
		nPag->palavras = (TpListaWord*) malloc(sizeof(TpListaWord));
		if(nPag->palavras != NULL){
			nPag->palavras->first = nWord;
			nPag->palavras->last = nWord;
			nPag->palavras->nItens++;
			nWord->myPage = nPag;
			TpPagina *nPagDir = novaPag();
			nPagDir->palavras = (TpListaWord*) malloc(sizeof(TpListaWord));
			nPagDir->palavras->first = wSplit;
			nPagDir->palavras->nItens = ordemArvore + 1;
			nPagDir->folha = TRUE;	
			
			TpWord *atual = nPagDir->palavras->first;
			while(atual != NULL){
				atual->myPage = nPagDir;
				atual = atual->prox;
			}
			
					
			nPag->palavras->first->filhoEsquerda = pagSplitar;	
			
			pagSplitar->pai = nWord;
			pagSplitar->palavras->last = wSplit->ant;
			pagSplitar->palavras->nItens = ordemArvore;
			pagSplitar->irmaoD = nPagDir;
			pagSplitar->folha = TRUE;
			arv->folhaE = pagSplitar;
			wSplit->ant->prox = NULL; /* o proximo doanterior ao wSplit ( que agora é o ultimo da lista) aponta para NULL
										* separando a lista da pagina SPLIT
										*/
			wSplit->ant = NULL;
			
			nPagDir->pai = nWord;
			nWord->filhoDireita = nPagDir;
			
			TpWord *aux = nPagDir->palavras->first;
			while(aux->prox != NULL){
				aux = aux->prox;
			}
			nPagDir->palavras->last = aux;				
			
			// a pagina a ser splitada vai ficar sempre sendo a pagina a direita do split
			// entao criar nova pagina para ser o filho a esquerda do split					
		}
		puts("sai null");		
	}
	// paginaSplit é filho esquerda
	else if(pagSplitar == pagSplitar->pai->filhoEsquerda){
		// paginar a splitar é filho esquerdo do pai
		if(pagSplitar->pai->ant == NULL){
			// pai é o FIRST
			nWord->myPage = pagSplitar->pai->myPage;
			
			nWord->myPage->palavras->first = nWord;
			nWord->prox = pagSplitar->pai;
			pagSplitar->pai->ant = nWord;
			nWord->myPage->palavras->nItens++;
			
			nWord->filhoEsquerda = pagSplitar;
			pagSplitar->pai = nWord;
			pagSplitar->palavras->last = wSplit->ant;
			pagSplitar->palavras->nItens = ordemArvore;
			pagSplitar->folha = TRUE;
			arv->folhaE = pagSplitar;
			
			TpPagina *nPag = novaPag();
			nPag->palavras = novaListaWord();
			if(nPag->palavras != NULL){
				nPag->palavras->first = wSplit;
				nPag->pai = nWord->prox;
				nWord->prox->filhoEsquerda = nPag;
				nPag->palavras->nItens = ordemArvore + 1;
				wSplit->ant->prox = NULL;
				wSplit->ant = NULL; 
				nPag->folha = TRUE;
				TpWord *aux = nPag->palavras->first;
				while(aux->prox != NULL){
					aux = aux->prox;
				}
				nPag->palavras->last = aux;	
				pagSplitar->irmaoD = nPag;
				if(nPag->pai->prox != NULL){
					nPag->irmaoD = nPag->pai->prox->filhoEsquerda;
				}else{
					nPag->irmaoD = nPag->pai->filhoDireita;
				}
				TpWord *atual = nPag->palavras->first;
				while(atual != NULL){
					atual->myPage = nPag;
					atual = atual->prox; 
				}
				//nItens atualizar				
			}
		}else if(pagSplitar->pai->ant != NULL){
			// pagina Split é filho esquerdo e pai nao é FIRST
			nWord->myPage = pagSplitar->pai->myPage;
			
			nWord->ant = pagSplitar->pai->ant->prox;
			pagSplitar->pai->ant->prox = nWord;
			
			pagSplitar->pai->ant = nWord;
			nWord->prox = pagSplitar->pai;
			
			nWord->filhoEsquerda = pagSplitar;
			pagSplitar->pai = nWord;
			nWord->myPage->palavras->nItens++;
			
			TpPagina *nPag = novaPag();
			nPag->palavras = novaListaWord();
			if(nPag->palavras != NULL){
				nPag->palavras->first = wSplit;
				nWord->prox->filhoEsquerda = nPag;
				nPag->pai = nWord->prox;
				
				pagSplitar->palavras->last = wSplit->ant;
				pagSplitar->irmaoD = nPag;
				wSplit->ant->prox = NULL;
				wSplit->ant = NULL;
				nPag->palavras->first = wSplit;
				pagSplitar->palavras->nItens = ordemArvore;
				if(nPag->pai->prox != NULL){
					nPag->irmaoD = nPag->pai->prox->filhoEsquerda;
				}else if(nPag->pai->prox == NULL){
					nPag->irmaoD = nPag->pai->prox->filhoDireita;
				}
				TpWord *aux = nPag->palavras->first;
				while(aux->prox != NULL){
					aux = aux->prox;
				}
				nPag->palavras->last = aux;	
				nPag->palavras->nItens = ordemArvore + 1;
				TpWord *atual = nPag->palavras->first;
				while(atual != NULL){
					atual->myPage = nPag;
					atual = atual->prox;
				}
				
								
			}		
		}
	// paginaSplit é filho direita	
	}else if(pagSplitar == pagSplitar->pai->filhoDireita){
		puts("paginaSplit é filho direita");
	}
	// pai last
	// pai meio
	puts("FIM S");
}



void imprimePaginas(TpTree *arv){
	//puts("imprimeeeee");
	TpPagina *lista = arv->folhaE;
	while(lista != NULL){
		TpWord *palavra = lista->palavras->first;
		//printf("\t\tPAAAAI first[%s]", lista->pai->word);
		
		if(lista->pai != NULL){
			//puts("pai");
			if(lista->pai->myPage != NULL){
				//puts("myPage");
				if(lista->pai->myPage->palavras != NULL){
					//puts("palavras");
					if(lista->pai->myPage->palavras->first != NULL){
						//puts("first");
						printf("PAAAAI FIRST[%s]", lista->pai->word);
					}
				}
			}
		}
		
		/*if(lista->pai != NULL  && lista->pai->myPage != NULL && lista->pai->myPage->palavras->first != NULL){
			printf("\t\tPAAAAI FIRST[%s]", lista->pai->myPage->palavras->first->word);
		}*/
		printf(" |");
		printf("/[%d]\\", lista->palavras->nItens);
		while(palavra != NULL){
			printf("[%s]", palavra->word);
			palavra = palavra->prox;
		}
		printf("| \n");
		lista = lista->irmaoD;
	}
	//puts("fim IMPRIMIR");
}

TpPagina *novaPag(){
	TpPagina *nPag = (TpPagina*) malloc(sizeof(TpPagina));
	nPag->nItens = 0;
	nPag->folha = FALSE;
	nPag->palavras = NULL;
	nPag->irmaoD = NULL;
	nPag->pai = NULL;
	return nPag;
}
 
TpListaWord *novaListaWord(){
	TpListaWord *newListaWord = (TpListaWord*) malloc(sizeof(TpListaWord));
	newListaWord->nItens = 0;
	newListaWord->first = NULL;
	newListaWord->last = NULL;
	return newListaWord;
}

TpWord *novaWord(){
	TpWord *nWord = (TpWord*) malloc(sizeof(TpWord));
	nWord->word = NULL;
	nWord->ant = NULL;
	nWord->prox = NULL;
	nWord->filhoEsquerda = NULL;
	nWord->filhoDireita = NULL;
	return nWord;
}

TpLista *novaLista(){
	TpLista *lista = (TpLista*) malloc(sizeof(TpLista));
	lista->nItens = 0;
	lista->first = NULL;
	lista->last = NULL;
	return lista;
}

TpTree *novaArv(){
	TpTree *arv = (TpTree*) malloc(sizeof(TpTree));
	arv->raiz = NULL;
	arv->folhaE = NULL; // aponta para a primeira pagina folha
	return arv;
}
