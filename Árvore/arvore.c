#include <stdio.h>
#include <stdlib.h>

struct no{
    int dado;
    struct no *esq, *dir;
};

void mostrarMenu(int*);
struct no* cria_arvore(int, struct no*, struct no*);
struct no* insere_no(int, struct no*);
void mostra_arvore(struct no*);
int conta_nos(struct no*);
int altura(struct no*);
struct no* limparArvore(struct no*);

int main(){
    int acao;
    struct no* arvore = 0;

    do {
        mostrarMenu(&acao);
        switch (acao) {
            case 1:
                int num;
                printf("Qual valor deseja inserir?");
                scanf("%d", &num);
                arvore = insere_no(num, arvore);
                break;
            case 2:
                mostra_arvore(arvore);
                break;
            case 3:
                printf("Essa árvore tem: %d nos\n", conta_nos(arvore));
                break;
            case 4:
                printf("Essa árvore tem: %d de altura\n", altura(arvore));
                break;
            case 5:
                arvore = limparArvore(arvore);
                break;
        }

        if (acao != 0) {
            acao = -1;
        }

    } while (acao != 0);

    return 0;
}

void mostrarMenu(int *acao){
    printf("\n");
    printf("--- Menu ---\n");
    printf("1. Inserir na árvore\n");
    printf("2. Mostrar a árvore \n");
    printf("3. Contar nós da árvore \n");
    printf("4. Mostrar altura da árvore\n");
    printf("5. Limpar a árvore \n");

    printf_s("\nSelecione uma opcao (digite 0 para sair): ");
    scanf_s("%d", acao);
    printf("\n");
}

struct no* cria_arvore(int valor, struct no *fesq, struct no *fdir){
    struct no *novo;
    novo = (struct no*)malloc(sizeof(struct no));
    if(!novo){ 
        exit; 
    }
    novo->dado = valor;
    novo->esq = fesq;
    novo->dir = fdir;
    printf("\nNó inserido\n");
    return (novo);
}

struct no* insere_no(int valor, struct no *raiz){
    if (raiz){
        if(valor>raiz->dado){
            raiz->dir = insere_no(valor, raiz->dir);
            }else{
                 raiz->esq = insere_no(valor, raiz->esq);
                 }
        }else{
            return(cria_arvore(valor,0,0));
        }
        return (raiz);
} 

void mostra_arvore(struct no *raiz){
    if (raiz == NULL){
        return;
    }
        mostra_arvore(raiz->esq);
        printf("%d\n", raiz->dado);
        mostra_arvore(raiz->dir);
}

int conta_nos(struct no *raiz){
    if(!raiz){
        return (0);
    }
    return(1+ conta_nos(raiz->esq)+ conta_nos(raiz->dir));
}   

int altura(struct no *raiz) {
    if ((raiz == NULL) || ((raiz->esq == NULL) && (raiz->dir) == NULL))
        return 0;
    
    int a = altura(raiz->esq);
    int b = altura(raiz->dir);

    if (a > b)
        return (1 + a);
    else
        return (1 + b);
}

struct no* limparArvore(struct no *raiz) {
    if (raiz == NULL)
        return NULL;
    
    limparArvore(raiz->esq);
    limparArvore(raiz->dir);
    free(raiz);

    return NULL;
}