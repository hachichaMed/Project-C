#ifndef UTILISATEUR_H_INCLUDED
#define UTILISATEUR_H_INCLUDED

typedef struct 
{
    int jj,mm,aa;
}Date;

typedef struct 
{
    char nom[30];
    char prenom[30];
    Date d;
    int sexe;/* !!! 0 si homme !=0 si femme !!! */
    int role;/* !!! 1 si observateur  2 si agent bureau de vote 3 si électeur 4 si candidat !!! */
    int nationalite;  /* !!! 0 si local  !=0 si étranger !!! */
    int cin;
    int numBV;
    int vote ;/* !!! 1 si observateur  2 si agent bureau de vote 3 si électeur 4 si candidat !!! */
    int apartenance ;/* !!! -1 si gauche 0 si centre 1 si droite !!! */
    char login[40] ;
    char mdp[20];
}utilisateur;



int ajouter(char *, utilisateur);
int modifier( char *, int, utilisateur );
int supprimer(char *, int );
utilisateur chercher(char *, int);
void afficher(char *,int);

#endif 
