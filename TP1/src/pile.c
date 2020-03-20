#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "pile_type.h"

int error1(char *message){
    fprintf(stderr, "%s\n", message);
    exit(-1);
}

PILE InitPile(){
    return NULL;
}

PILE Empiler(PILE pile, int elem){
    PILE new = malloc(sizeof(*new));
    new->elem = elem;
    new->suivant = pile;
    return new;
}

int Depiler(PILE* ppile){
    PILE pile = *ppile;
    if (pile == NULL)
    {
        return (error1("Empty tower!"));
    }
    int val = pile->elem;

    *ppile = pile->suivant;

    free(pile);
    return val;
}

void afficherPile(PILE pile){
    PILE i = pile;
    while (i != NULL)
    {
        printf("%d ", i->elem);
        i = i->suivant;
    }
    printf("\n");
}
