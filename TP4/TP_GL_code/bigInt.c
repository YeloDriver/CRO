#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "type_bigInt.h"
#include "util_bigInt.h"
#include "io_bigInt.h"

#define DEBUG1



/*!
************************************************
* \brief Additionne deux Grands Entiers
* \param  bN1 Grand Entier
* \param  bN2 Grand Entier
* \param  res le Grand Entier résultat
* \return  0 si l'addition est OK, 1 en cas d'overflow
* \warning res doit être déjà alloué,
* ************************************************/
int addBigInt(bigInt bN1,bigInt bN2,bigInt res)
{
  int i, retenue;

  retenue = 0;
  for (i = 0; i < TAILLEMAX; i++)
  {
    //Attention, on peut écraser bN1[i] ou bN2[i] ici
    res[i] = bN1[i] + bN2[i] + retenue;
    if (res[i] >= 10)
    {
      retenue = 1;
      res[i] = res[i] - 10;
    }
    else
      retenue = 0;
  }

  if (retenue == 1)
    return 1;
  else
    return 0;
}





/*!
************************************************
* \brief Multiplie deux Grand Entiers avec l'algorithme suivant:
* stocker les 10 valeurs j*bN2 pour 1<=j<=9
* Pour chaque chiffre j=bN1[i] de bN1, partant de i=0,
* multiplier  j*bN2 par 10^i et l'ajouter au resultat
* \param  bN1 Grand Entier
* \param  bN2 Grand Entier
* \param  res le grand entier bN1*bN2
* \result Un entier: 1 en cas d'overflos, O sinon
* \warning res doit être déjà alloué,
* ************************************************/
int mulBigInt(bigInt bN1,bigInt bN2,bigInt res)
{
  int i, j, k, tailleN1, overflow = 0;
  bigInt bNT[10], bNTemp;
  ;

  bNTemp = initBigInt();
  // ne pas oublier de remettre le resultat à zero
  zeroBigInt(res);
  tailleN1 = getNbChiffreBigInt(bN1);

  for (i = 0; i < 10; i++)
  {
    bNT[i] = initBigInt();
    if (i > 0)
    { //bNT[i] contains i*bN2
      overflow = overflow || addBigInt(bNT[i - 1], bN2, bNT[i]);
    }
  }

  for (i = 0; i < tailleN1; i++)
  {
    //bN1[i]*bN2
    copyBigInt(bNT[bN1[i]], bNTemp);
    for (k = 1; k <= i; k++)
    { //10^i*bN1[i]*bN2
      overflow = overflow || times10BigInt(bNTemp, bNTemp);
    }
    overflow = overflow || addBigInt(res, bNTemp, res);
  }

  freeBigInt(bNTemp);
  for (j = 0; j < 10; j++)
    freeBigInt(bNT[j]);

  if (overflow)
  {
    fprintf(stderr, "Warning  overflow in multiplication\n");
    return (1);
  }
  else
    return 0;
}