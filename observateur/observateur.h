#ifndef OBSERVATEUR_H_INCLUDED
#define OBSERVATEUR_H_INCLUDED
#include <stdio.h>
typedef struct 
{ 
    int  jj;
    int  mm;
    int  aa;		
}Date;
typedef struct
{
    char Nom [20];
    char Prenom [20];
    Date d;
    int  cin;
    int id;
    char nationalite[20];
    char professione[20];

  
} observateur;

int ajouter(char *, observateur );
int modifier( char *, int, observateur);
int supprimer(char *, int );
observateur chercher(char *, int);



#endif // OBSERVATEUR_H_INCLUDED