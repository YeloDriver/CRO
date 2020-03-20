#include <stdio.h>
#include "pile.h"
#include "pile_type.h"
#include "hanoi.h"

int deplacer(PILE *psource, PILE *pdest){
    PILE src = *psource;
    PILE dest = *pdest;

    if (src == NULL)
    {
        return error1("Source vide");
    }
    
    if (dest != NULL && src->elem > dest->elem){
        return error1("Impossible taille ");
    } 

    int elem = Depiler(psource);
    *pdest = Empiler(*pdest, elem);
    return 0;
}

int hanoi(PILE *depart, PILE *passage, PILE *arrive, int N){
    if (N != 0)
    {
        hanoi(depart, arrive, passage, N - 1);
        deplacer(depart, arrive);
        hanoi(passage, depart, arrive, N - 1);
    }
    return (0);
}