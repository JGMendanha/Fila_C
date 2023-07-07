#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

int main()
{
    TFila fila, fila2;
    TProduto produto;
    FFVazia(&fila);
    FFVazia(&fila2);
    MENU(&fila,&fila2);
    return 0;
}
