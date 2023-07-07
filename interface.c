#include <stdio.h>
#include <stdlib.h>

#include "interface.h"


void MSG_MENU( )
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. ENFILEIRAR");
    printf("  \n\t2. DESENFILEIRAR");
    printf("  \n\t3. IMPRIMIR");
    printf("  \n\t4. PESQUISAR");
    printf("  \n\t5. SABER SE AS FILAS SAO IGAUIS");
    printf("  \n\t6. DESENCADEAR O ITEM QUE DESEJA PELA SUA POSICAO");
    printf("  \n\t7. INTERSECAO DE DUAS FILAS");
    printf("  \n\t8. DIFERENCA DE DUAS FILAS");
    printf("  \n\t9. SAIR");
}

void MENU(TFila *fila, TFila *fila2){
    TProduto x;
    TFila fila3;
    FFVazia(&fila3);
    int opcao=0;
    int j, i;
    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                LerProduto(&x);
                printf("\nDeseja inserir em qual fila ? (1 ou 2) ");
                scanf("%d",&j);
                if(j == 1)
                    Enfileirar(x,fila);
                else
                    Enfileirar(x,fila2);
                printf("Produto inserido com sucesso \n");
                system("PAUSE");
                break;
            case 2:
                printf("\nDeseja desenfileirar em qual fila ? (1 ou 2) ");
                scanf("%d",&j);
                printf("Desenfileirando um produto...");
                if(j == 1)
                    Desenfileirar(fila,&x);
                else
                    Desenfileirar(fila2,&x);
                system("PAUSE");
                break;
            case 3:
                printf("\nDeseja imprimir qual lista ? (1 ou 2) ");
                scanf("%d",&j);
                if(j == 1)
                    Imprimir1(fila);
                else
                    Imprimir1(fila2);
                system("PAUSE");
                break;
            case 4:
                printf("digite o nome do produto que deseja procurar ");
                scanf ("%s", x.nome);
                printf("\nDeseja pesquisar em qual fila ? (1 ou 2) ");
                scanf("%d",&j);
                if(j == 1){
                    j = Pesquisar(fila,&x);
                    if(j == 1){
                        printf("Produto existente na fila\n");
                        ImprimirProduto(x);
                    }
                    else{
                        printf("O produto nao existe na fila\n");
                        ImprimirProduto(x);
                    }
                }
                else{
                    Pesquisar(fila2,&x);
                    if(j == 1){
                        printf("Produto existente na fila\n");
                        ImprimirProduto(x);
                    }
                    else{
                        printf("O produto nao existe na fila\n");
                        ImprimirProduto(x);
                    }
                }
                system("PAUSE");
                break;
            case 5:
                j = Comparar(fila, fila2);
                if(j == 1)
                    printf("As filas sao igauis\n");
                else
                    printf("As filas sao diferentes\n");
                system("PAUSE");
                break;
            case 6:
                printf("\nDeseja desencadear qual elemento ? ");
                scanf("%d",&i);
                printf("\nDeseja desencadear o elemento de qual lista ? (1 ou 2) ");
                scanf("%d",&j);
                if(j == 1){
                    Desencadear(fila, i);
                    printf("Elemento desencadeado\n");
                }
                else{
                    Desencadear(fila2, i);
                    printf("Elemento desencadeado\n");
                }
                system("PAUSE");
                break;
            case 7:
                Intersecao(fila, fila2, fila3);
                system("PAUSE");
                break;
             case 8:
                Diferenca(fila, fila2, fila3);
                system("PAUSE");
                break;
            case 9:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 9);
}
