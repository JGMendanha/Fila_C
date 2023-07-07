#ifndef Fila_HEADER
#define Fila_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    int codigo;
    char nome[80];
    char descricao[200];
    float preco;
    int quantidade;
    int prio;
} TProduto;

typedef struct celula {
    TProduto item;
    struct celula *prox;
} TCelula;

typedef struct fila {
    TCelula *frente;
    TCelula *tras;
    int tamanho;
} TFila;

void Enfileirar (TProduto x, TFila *Fila);

void FFVazia (TFila *Fila);

int Vazia (TFila Fila);

void Desenfileirar (TFila *Fila, TProduto *Item);

void ImprimirProduto(TProduto x);

void Imprimir1(TFila *fila);

void Imprimir2(TFila *fila);

void LerProduto(TProduto *x);

int Pesquisar(TFila *fila, TProduto *x);

int Comparar(TFila *Fila, TFila *Fila2);

void Desencadear(TFila *fila, int n);

void Intersecao(TFila *fila, TFila *fila2, TFila fila3);

void Diferenca(TFila *fila, TFila *fila2, TFila fila3);

#endif
