#include <stdio.h>
#include <stdlib.h>

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
        while(fscanf(f,"%s %s %i %i %i %i %i %i %i %i %i %i %s %s\n",p.nom,p.prenom,&p.d.jj,&p.d.mm,&p.d.aa,&p.sexe,&p.role,&p.nationalite,&p.cin,&p.numBV,&p.vote,&p.apartenance,p.login,p.mdp)!=EOF)        
        {
            if(p.cin==cin)
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
          printf("nom : %s \nprenom :%s  \ndate de naissance %i/%i/%i\nsexe : %i\nrole : %i \nnationalité :%i \ncin:%i \nnuméro bureau de vote :%i\nvote %i \napartenance:%i \nlogin:%s \nmot de passe:%s\n",p.nom,p.prenom,p.d.jj,p.d.mm,p.d.aa,p.sexe,p.role,p.nationalite,p.cin,p.numBV,p.vote,p.apartenance,p.login,p.mdp);
        }
        else printf("introuvable");

    }
}

int main()
{
    int x ;
    utilisateur u1={"hachicha","mohamed",8,8,2001,0,3,0,111,3,1,0,"login1","mdp1"};
    utilisateur u2={"mehdi","attafi",7,7,2002,0,2,0,222,3,1,0,"login2","mdp2"};
    utilisateur u3;
    char name[20]="utilisateur.txt";
    x =ajouter(name,u1);
    if(x==1)
        printf("\najout Utilisateur avec succés\n");
    else printf("\nechec ajout");
    /*x=modifier(name,111,u2 );

    if(x==1)
        printf("\nModification d'Utilisateur avec succés\n");
    else printf("\nechec Modification");*/
    
    /*x=supprimer(name,222);
    if(x==1)
        printf("\nSuppression d'Utilisateur avec succés\n");
    else printf("\nechec Suppression");*/
    
    u3=chercher(name,111);
    if(u3.cin==-1)
        printf("introuvable\n");
        else printf("trouvée\n");
    affiche(name,111);
    return 0;
}
