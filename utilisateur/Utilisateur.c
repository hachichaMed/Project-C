#include "Utilisateur.h"
#include <stdio.h>

int ajouter(char * nom, utilisateur p)
{
    FILE * f=fopen(nom,"a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %i %i %i %i %i %i %i %i %i %i %s %s\n",p.nom,p.prenom,p.d.jj,p.d.mm,p.d.aa,p.sexe,p.role,p.nationalite,p.cin,p.numBV,p.vote,p.apartenance,p.login,p.mdp);
        return 1;
    }
    else    return 0;
}
int modifier( char * filename, int cin, utilisateur nouv )
{
    int tr=0;
    utilisateur p;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %i %i %i %i %i %i %i %i %i %i %s %s\n",p.nom,p.prenom,&p.d.jj,&p.d.mm,&p.d.aa,&p.sexe,&p.role,&p.nationalite,&p.cin,&p.numBV,&p.vote,&p.apartenance,p.login,p.mdp)!=EOF)
        {
            if(p.cin== cin)
            {
                fprintf(f2,"%s %s %i %i %i %i %i %i %i %i %i %i %s %s\n",nouv.nom,nouv.prenom,nouv.d.jj,nouv.d.mm,nouv.d.aa,nouv.sexe,nouv.role,nouv.nationalite,nouv.cin,nouv.numBV,nouv.vote,nouv.apartenance,nouv.login,nouv.mdp);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %i %i %i %i %i %i %i %i %i %i %s %s\n",p.nom,p.prenom,p.d.jj,p.d.mm,p.d.aa,p.sexe,p.role,p.nationalite,p.cin,p.numBV,p.vote,p.apartenance,p.login,p.mdp);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}

int supprimer(char * filename, int cin)
{
    int tr=0;
    utilisateur p;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %i %i %i %i %i %i %i %i %i %i %s %s\n",p.nom,p.prenom,&p.d.jj,&p.d.mm,&p.d.aa,&p.sexe,&p.role,&p.nationalite,&p.cin,&p.numBV,&p.vote,&p.apartenance,p.login,p.mdp)!=EOF)
        {
            if(p.cin== cin)
                tr=1;
            else
                fprintf(f2,"%s %s %i %i %i %i %i %i %i %i %i %i %s %s\n",p.nom,p.prenom,p.d.jj,p.d.mm,p.d.aa,p.sexe,p.role,p.nationalite,p.cin,p.numBV,p.vote,p.apartenance,p.login,p.mdp);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
utilisateur chercher(char * filename, int cin)
{
    utilisateur p;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %i %i %i %i %i %i %i %i %i %i %s %s\n",p.nom,p.prenom,&p.d.jj,&p.d.mm,&p.d.aa,&p.sexe,&p.role,&p.nationalite,&p.cin,&p.numBV,&p.vote,&p.apartenance,p.login,p.mdp)!=EOF)        {
            if(p.cin== cin)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        p.cin=-1;
    return p;

}
void affiche(char * filename,int cin)
{
    utilisateur p;
    int i;
    FILE * f=fopen(filename, "r");
    if(f==NULL)
        printf("erreur");
    else
    {
        for(i=0;i!=cin && fscanf(f,"%s %s %i %i %i %i %i %i %i %i %i %i %s %s\n",p.nom,p.prenom,&p.d.jj,&p.d.mm,&p.d.aa,&p.sexe,&p.role,&p.nationalite,&p.cin,&p.numBV,&p.vote,&p.apartenance,p.login,p.mdp)!=EOF;i++);
        if(p.cin==cin)
        {
          printf("nom : %s \nprenom :%s  \ndate de naissance %i/%i/%i\nsexe : %i\nrole : %i \n%i \nnationalité :%i \ncin:%i \nnuméro bureau de vote :%i \napartenance:%i \nlogin:%s \nmot de passe:%s\n",p.nom,p.prenom,p.d.jj,p.d.mm,p.d.aa,p.sexe,p.role,p.nationalite,p.cin,p.numBV,p.vote,p.apartenance,p.login,p.mdp);
        }
        else printf("introuvable");

    }
}

