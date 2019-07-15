#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct _carro_{
	char marca[50];
	char placa[10];
	int id;
}Carro;

void listaMenu(Sllist *l);
int compPlacaCarro(void *a, void *b);
int compMarcaCarro(void *a, void *b);
int compIdCarro(void *a, void *b);
void imprimeData(void* a);

int main()
{
	Sllist* l=NULL;

	listaMenu(l);
	return 0;
}

// funcao que cria uma lista
Sllist* criarLista()
{
	Sllist *l;

	l = sllCreate();
    printf("SUCCEFUL!");
	return l;
}

//funcao que cria e insere na lista o elemento criado
void inserirLista(Sllist *l)
{
	Carro *c;
	if(l!=NULL){
	 c = (Carro *)malloc(sizeof(Carro));
	 if(c!=NULL){
	 	printf("Insira a marca do veiculo: \n");
	 	scanf("%s",c->marca);
	 	printf("Insira os digitos da placa: \n");
	 	scanf("%s",c->placa);
	 	printf("Insira a sua id: \n");
	 	scanf("%d",&c->id);

	 	if(sllInsertFirst(l,(void*)c) == TRUE){
	 		printf("Carro inserido com sucesso!z\n");
	 	}else{
	 		printf("Erro na insercao!\n");
	 	}
	 }else{
	 	free(c);
	 }

	}
}
// o famoso inserir depois do maldito spec
void insetirDepoisSpec(Sllist *l)
{
    Carro *c;
    char placa;
    if(l!=NULL){
	 c = (Carro *)malloc(sizeof(Carro));
	 if(c!=NULL){
        // inserindo informacoes do carro
	 	printf("Insira a marca do veiculo: \n");
	 	scanf("%s",c->marca);
	 	printf("Insira os digitos da placa: \n");
	 	scanf("%s",c->placa);
	 	printf("Insira a sua id: \n");
	 	scanf("%d",&c->id);
	 	// inserindo informacoes sobre o spec
	 	printf("\n\nInforme a placa do spec: \n");
        scanf("%s",&placa);
        //agora a insercao
        if(sllInsertAfterSpec(l,(void*)&placa,compPlacaCarro,c)==TRUE){
            printf("Carro inserido com sucesso!\n");
            printf("\n----------------------------------\n");

        }else{

            printf("Carro nao encontrado!\n");
            printf("\n----------------------------------\n");

        }
	 }
    }

}
// funcao remove da lista um elemento especificado
void removerLista(Sllist *l)
{
	int id;
	printf("Informe o seu id: \n");
	scanf("%d",&id);
	if(sllRemoveSpec(l,(void*)id,compIdCarro)!=NULL){
		printf("Carro removido com sucesso!\n");
	}else{
		printf("ERRO! Informe um id valido!\n");
	}
}
// procura um elemento na lista
//void procurarElementoLista(Sllist *l)
//{
    //char placa;
	//if(l!=NULL){
		//printf("Informe a placa do veiculo: \n");
		//scanf("%s",&placa);
		//if(sllQuery(l,(void*)&placa,compPlacaCarro)!=NULL){
            //printf("\n veiculo achado com sucesso\n");
		//}else{
            //printf("\n veiculo nao encontrado\n");
		//}

    //}
//}

//funcao que imita um arraylist

void listarLista(Sllist *l)
{
    void *data;
    if(l!=NULL){
    data = sllFirst(l);
        while(data!=NULL){
            imprimeData(data);
            data=sllGetNext(l);
        }
    }
}

// MENU LISTA
void listaMenu(Sllist *l)
{
	char opc;
	char ch;
	char placa;
    void *aux;
    int id;
	while(opc!=7){
		//if(l==NULL){
			//printf("Erro na lista");
		//}
		printf("\n===== LISTA DE CARROS ======\n");
		printf("1 - Criar uma lista\n");
		printf("2 - Inserir na lista um carro\n");
		printf("3 - Remover da lista um carro\n");
		printf("4 - Procurar na lista um carro\n");
		printf("5 - listar carros\n");
		printf("6 - Destruir lista\n");
		//printf("7 - Inserir carro depois do spec\n");
		printf("7 - EXIT\n");
		scanf("%s",&opc);

		switch(opc)
		{
			case '1':
				if(l==NULL){
					system("cls");
					l = criarLista();
					//printf("\nLista criada\n");
				}else{
					printf("Ja existe uma LISTA\n");
				}
				break;

			case '2':
				system("cls");
				inserirLista(l);
				break;

			case '3':
				system("cls");
				removerLista(l);
			break;

			case'4':
			    system("cls");
				printf("\n ====== SISTEMA DE BUSCAS =======\n\n");
				printf("1 - Placa\n");
				printf("2 - ID\n");
				printf("Enter your choice\n");
				scanf("%s",&ch);
				switch(ch)
				{
                case '1':
                    system("cls");
                    printf("Informe a placa do carro: ");
                    scanf("%s",&placa);
                    aux = sllQuery(l,(void*)&placa,compPlacaCarro);
                    if(aux!=NULL){
                       Carro *c;
                       c=(Carro*)aux;
                       printf("\n --------------- \n");
                       printf("\nPLACA: ""%s",c->placa);
                       printf("\nMARCA: ""%s",c->marca);
                       printf("\nID: ""%d",c->id);
                       printf("\n --------------- \n");
                    }else{
                        printf("\nInforme uma placa valida\n");
                    }
                    break;
                case '2':
                    system("cls");
                    printf("Informe o ID do carro: \n");
                    scanf("%d",&id);
                    aux=sllQuery(l,(void*)id,compIdCarro);
                    if(aux!=NULL){
                        imprimeData(aux);
                    }else{
                        printf("\nInforme um ID valido\n");
                    }
                    break;
                default:
                    printf("\nOpcao invalida\n");
				}
				break;
            case '5':
                system("cls");
                listarLista(l);
                break;
			case '6':
				system("cls");
				if(sllDestroy(l) == TRUE){
					free(l);
					printf("Lista destruida\n");
				}else{
                    printf("\nLista encontra-se com elementos\n");
				}
				break;
           // case '7':
               // system("cls");
                //insetirDepoisSpec(l);
                //break;
			case '8':
				exit(0);
			default:
				if(opc!='8'){
					printf("\nOpcao invalida, por favor redigite\n");
				}
			break;

		}
	}
}
// funcao que compara a marca do carro
int compMarcaCarro(void *a, void *b)
{
	char* pa; Carro *pb;
	pa=(char*)a;
	pb=(Carro*)b;
	if(strcmp(pa, pb->marca) == 0){
		return TRUE;
	}else{
		return FALSE;
	}
}
//funcao que compara o id do cliente
int compIdCarro(void *a, void *b)
{
	int *pa; Carro *pb;
	pa=(int*)a;
	pb=(Carro*)b;
	if(pb->id==pa){
		return TRUE;
	}else{
		return FALSE;
	}
}
// funcao que compara a placa
int compPlacaCarro(void *a, void *b)
{
	char *pa; Carro *pb;
	pa=(char*)a;
	pb=(Carro*)b;
	if(strcmp(pa, pb->placa) == 0){
		return TRUE;
	}else{
		return FALSE;
	}
}

//funcao imprime dados da lista

void imprimeData(void* a)
{
    Carro *pb;
    pb=(Carro*)a;
        printf("\n Marca: ""%s",pb->marca);
        printf("\n Placa: ""%s",pb->placa);
        printf("\n ID: ""%d",pb->id);
        printf("\n---------------------\n");

}


