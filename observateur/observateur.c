#include "observateur.h"

int ajouter(char * filename, observateur  o )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
      fprintf(f,"%s %s %d %d %d %d %d %s %s\n",o.Nom,o.Prenom,o.d.jj,o.d.mm,o.d.aa,o.cin,o.idf,o.nationalite,o.professione);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int idf, observateur nouv )
{
    int tr=0;
    observateur o;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %d %d %s %s\n",o.Nom,o.Prenom,&o.d.jj,&o.d.mm,&o.d.aa,&o.cin,&o.idf,o.nationalite,o.professione)!=EOF)
        {
            if(o.idf== idf)
            {
                fprintf(f2,"%s %s %d %d %d %d %d %s %s\n",nouv.Nom,nouv.Prenom,nouv.d.jj,nouv.d.mm,nouv.d.aa,nouv.cin,nouv.idf,nouv.nationalite,nouv.professione);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %d %d %d %d %d %s %s\n",o.Nom,o.Prenom,o.d.jj,o.d.mm,o.d.aa,o.cin,o.idf,o.nationalite,o.professione);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimer(char * filename, int idf)
{
    int tr=0;
    observateur o;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %d %d %s %s\n",o.Nom,o.Prenom,&o.d.jj,&o.d.mm,&o.d.aa,&o.cin,&o.idf,o.nationalite,o.professione)!=EOF)
        {
            if(o.idf== idf)
                tr=1;
            else
                fprintf(f2,"%s %s %d %d %d %d %d %s %s\n",o.Nom,o.Prenom,o.d.jj,o.d.mm,o.d.aa,o.cin,o.idf,o.nationalite,o.professione);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
observateur chercher(char * filename, int idf)
{
    observateur o;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&&fscanf(f,"%s %s %d %d %d %d %d %s %s\n",o.Nom,o.Prenom,&o.d.jj,&o.d.mm,&o.d.aa,&o.cin,&o.idf,o.nationalite,o.professione)!=EOF)
        {
            if(o.idf== idf)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        o.idf=-1;
    return o;

}