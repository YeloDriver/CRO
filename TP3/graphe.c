#include "graphe_adj_type.h"
#include "graphe_poids_type.h"
#include "util_adj.h"
#include "util_poids.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GRAPHE fermeture_transistive(GRAPHE g)
{
    GRAPHE g1, g2;
    int modif = 1, N;
    N = g.nb_sommets;
    /* attention, si on travaille sur g, on va mofidier l'argument */
    g1 = init_adj_mat(N);
    g2 = init_adj_mat(N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            g1.adj[i][j] = g.adj[i][j];
            g2.adj[i][j] = g.adj[i][j];
        }
    while (modif != 0)
    {
        modif = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (g1.adj[i][j] == 1)
                    for (int k = 0; k < N; k++)
                        if ((g1.adj[j][k] == 1) && (g2.adj[i][k] != 1))
                        {
                            g2.adj[i][k] = 1;
                            modif = 1;
                            /* printf("modif: %d -> %d\n",i,k); */
                        }
            }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                g1.adj[i][j] = g2.adj[i][j];
            }
    }
    return g1;
}