#include <stdio.h>
#include <stdlib.h>
#include "observateur.h"

int ajouter(char * filename, observateur  o )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
      fprintf(f,"%s %s %d %d %d %d %d %s %s\n",o.Nom,o.Prenom,o.d.jj,o.d.mm,o.d.aa,o.cin,o.id,o.nationalite,o.professione);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int id, observateur nouv )
{
    int tr=0;
    observateur o;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %d %d %s %s\n",o.Nom,o.Prenom,&o.d.jj,&o.d.mm,&o.d.aa,&o.cin,&o.id,o.nationalite,o.professione)!=EOF)
        {
            if(o.id== id)
            {
                fprintf(f2,"%s %s %d %d %d %d %d %s %s\n",nouv.Nom,nouv.Prenom,nouv.d.jj,nouv.d.mm,nouv.d.aa,nouv.cin,nouv.id,nouv.nationalite,nouv.professione);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %d %d %d %d %d %s %s\n",o.Nom,o.Prenom,o.d.jj,o.d.mm,o.d.aa,o.cin,o.id,o.nationalite,o.professione);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimer(char * filename, int id)
{
    int tr=0;
    observateur o;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %d %d %s %s\n",o.Nom,o.Prenom,&o.d.jj,&o.d.mm,&o.d.aa,&o.cin,&o.id,o.nationalite,o.professione)!=EOF)
        {
            if(o.id== id)
                tr=1;
            else
                fprintf(f2,"%s %s %d %d %d %d %d %s %s\n",o.Nom,o.Prenom,o.d.jj,o.d.mm,o.d.aa,o.cin,o.id,o.nationalite,o.professione);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
observateur chercher(char * filename, int id)
{
    observateur o;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %d %d %s %s\n",o.Nom,o.Prenom,&o.d.jj,&o.d.mm,&o.d.aa,&o.cin,&o.id,o.nationalite,o.professione)!=EOF)
        {
            if(o.id==id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        o.id=-1;
    return o;
}

int main()
{
    int x ;
    observateur o1={"hachicha","mohamed",8,8,2001,111,1,"tunisian","etudiant"};
    observateur o2={"mehdi","attafi",7,7,2002,222,2,"étranger","jouranaliste"};
    observateur o3;
    char name[20]="observateur.txt";
    x =ajouter(name,o1);
    if(x==1)
        printf("\najout de point avec succés\n");
    else printf("\nechec ajout");
    x=modifier(name,1,o2 );

    if(x==1)
        printf("\nModification de point avec succés\n");
    else printf("\nechec Modification");
    x=supprimer(name,2);
    if(x==1)
        printf("\nSuppression de point avec succés\n");
    else printf("\nechec Suppression");
    
    o3=chercher(name,1);
    if(o3.cin==-1)
        printf("introuvable\n");
        else printf("trouvée\n");
}