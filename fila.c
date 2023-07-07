#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void FFVazia (TFila *Fila) {
    Fila->frente = (TCelula *) malloc (sizeof (TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int Vazia (TFila Fila) {
    return (Fila.frente == Fila.tras);
}

void Enfileirar (TProduto x, TFila *Fila) {
    Fila->tras->prox = (TCelula *) malloc (sizeof (TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Desenfileirar (TFila *Fila, TProduto *Item) {
    TCelula *Aux;
    if (!Vazia (*Fila)){
        Aux = Fila->frente->prox;
        Fila->frente->prox = Aux->prox;
        *Item = Aux->item;
        free (Aux);
        if (Fila->frente->prox == NULL)
            Fila->tras = Fila->frente;
    Fila->tamanho--;
    }
}

void ImprimirProduto(TProduto x){
    printf("\ncodigo: %d\n", x.codigo);
    printf("quantidade: %d\n", x.quantidade);
    printf("peco: %f\n", x.preco);
    printf("nome: ");
    puts(x.nome);
    printf("descricao: ");
    puts(x.descricao);
    printf("prioridade: ");
    puts(x.prio);
    printf("\n==========================================\n");
}

void LerProduto(TProduto *x){
    printf("\ndigite o codigo do produto: ");
    scanf("%d",&x->codigo);
    printf("digite a quantidade do produto: ");
    scanf("%d",&x->quantidade);
    printf("digite o peco do produto: ");
    scanf("%f",&x->preco);
    printf("digite a descricao do produto (ate 100 letras): ");
    fflush(stdin);
    scanf ("%s", x->descricao);
    printf("digite o nome do produto (ate 10 letras): ");
    fflush(stdin);
    scanf ("%s", x->nome);
    printf("digite a prioridade do produto: ");
    scanf("%f",&x->prio);
    printf("==========================================\n");

}

void Imprimir1(TFila *fila){
    int j = fila->tamanho;
    TProduto x;
    for(int i = 0; i < j; i++){
        Desenfileirar(fila, &x);
        ImprimirProduto(x);
        Enfileirar(x, fila);
    }
}

void Imprimir2(TFila *fila){
    TProduto x;
    TFila fila2;
    FFVazia(&fila2);
    while(!Vazia(*fila)){
        Desenfileirar(fila,&x);
        ImprimirProduto(x);
        Enfileirar(x, &fila2);
    }
    while(!Vazia(fila2)){
        Desenfileirar(&fila2,&x);
        Enfileirar(x, fila);
    }
}

int Pesquisar(TFila *fila, TProduto *x){
    TProduto produto;
	TFila Aux;
	FFVazia(&Aux);
	int i = 0;

	while(!Vazia(*fila)){
		Desenfileirar(fila, &produto);
		if(strcmp(x->nome, produto.nome) == 0){
			i = 1;
			*x = produto;
		}
		Enfileirar(produto, &Aux);
	}

	while(!Vazia(Aux)){
		Desenfileirar(&Aux, &produto);
		Enfileirar(produto, fila);
	}

    free(Aux.frente);

	if(i == 1)
        return i;

    x->codigo = -1;
    return 0;
}

int Comparar(TFila *fila, TFila *fila2){
    TProduto produto, produto2;
    TFila Aux, Aux2;
    FFVazia(&Aux);
    FFVazia(&Aux2);
    int cont = 0;

    if(fila->tamanho != fila2->tamanho)
        return 0;

    while(!Vazia(*fila)){
        Desenfileirar(fila, &produto);
        while(!Vazia(*fila2)){
            Desenfileirar(fila2, &produto2);
            if(produto.codigo == produto2.codigo)
                cont++;
            Enfileirar(produto2, &Aux2);
        }
        Enfileirar(produto, &Aux);
    }

    while(!Vazia(Aux2)){
        Desenfileirar(&Aux2, &produto2);
        Enfileirar(produto2, fila2);
    }

    while(!Vazia(Aux)){
        Desenfileirar(&Aux, &produto);
        Enfileirar(produto, fila);
    }

    free(Aux.frente);
    free(Aux2.frente);

    if(cont == fila->tamanho)
        return 1;

    return 0;
}

void Desencadear(TFila *fila, int n){
    TProduto x;
    TFila Aux;
	FFVazia(&Aux);
	int cont = 1;

	while(!Vazia(*fila)){
        Desenfileirar(fila, &x);
        if(cont != n)
            Enfileirar(x, &Aux);
        cont++;
	}

	while(!Vazia(Aux)){
        Desenfileirar(&Aux, &x);
        Enfileirar(x, fila);
	}

	free(Aux.frente);
}

void Intersecao(TFila *fila, TFila *fila2, TFila fila3){
    TProduto produto, produto2;
    TFila Aux, Aux2;
    FFVazia(&Aux);
    FFVazia(&Aux2);

    while(!Vazia(*fila)){
        Desenfileirar(fila, &produto);
        while(!Vazia(*fila2)){
            Desenfileirar(fila2, &produto2);
            if(produto.codigo == produto2.codigo){
                Enfileirar(produto, &fila3);
            }
            Enfileirar(produto2, &Aux2);
        }
        Enfileirar(produto, &Aux);
    }

    while(!Vazia(Aux)){
        Desenfileirar(&Aux, &produto);
        Enfileirar(produto, fila);
    }

    while(!Vazia(Aux2)){
        Desenfileirar(&Aux2, &produto2);
        Enfileirar(produto2, fila2);
    }

    printf("Intersecao das duas filas\n");
    Imprimir1(&fila3);

    free(Aux.frente);
    free(Aux2.frente);
}

void Diferenca(TFila *fila, TFila *fila2, TFila fila3){
    TProduto produto, produto2;
    TFila Aux, Aux2;
    FFVazia(&Aux);
    FFVazia(&Aux2);

    if(fila->tamanho <= fila2->tamanho){
        while(!Vazia(*fila)){
            Desenfileirar(fila, &produto);
            while(!Vazia(*fila2)){
                Desenfileirar(fila2, &produto2);
                if(produto.codigo != produto2.codigo)
                    Enfileirar(produto, &fila3);
                Enfileirar(produto2, &Aux2);
            }
            Enfileirar(produto, &Aux);
        }
    }
    else{
        while(!Vazia(*fila2)){
            Desenfileirar(fila2, &produto);
            while(!Vazia(*fila)){
                Desenfileirar(fila, &produto2);
                if(produto.codigo != produto2.codigo)
                    Enfileirar(produto2, &fila3);
                Enfileirar(produto, &Aux2);
            }
            Enfileirar(produto2, &Aux);
        }
    }

    while(!Vazia(Aux2)){
        Desenfileirar(&Aux2, &produto2);
        Enfileirar(produto2, fila2);
    }

    while(!Vazia(Aux)){
        Desenfileirar(&Aux, &produto);
        Enfileirar(produto, fila);
    }

    printf("Diferenca das duas filas\n");
    Imprimir1(&fila3);

    free(Aux.frente);
    free(Aux2.frente);
}
