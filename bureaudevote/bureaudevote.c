#include<stdio.h>
#include<stdlib.h>
#include "bureaudevote.h"
void ajouterBureauDeVote(BureauDeVote bureauDeVote){
	FILE *f;
	f=fopen("bureaudevote.txt","a+");
	if(f==NULL){
		printf("erreur");
	}
	else{
		fprintf(f,"%d %d %d %d %s %d %d/%d/%d\n"   ,bureauDeVote.identifiant,
													bureauDeVote.capacite_electeurs,
													bureauDeVote.capacite_observateurs,
													bureauDeVote.nb_salle,
													bureauDeVote.adresse,
													bureauDeVote.id_agent_bureau_vote,
													bureauDeVote.dateCreationBureauDeVote.jour,
													bureauDeVote.dateCreationBureauDeVote.mois,
													bureauDeVote.dateCreationBureauDeVote.annee);

	}
	fclose(f);
}
void modifierBureauDeVote(int id,BureauDeVote bureauDeVoteModifier){
	if(recherBureauDeVoteParId(id)==0){
		printf("Bureau de vote introuvable!!\n");
		return;
	}
	BureauDeVote bureauDeVote;
	FILE *f,*f1;
	f=fopen("bureaudevote.txt","a+");
	f1=fopen("tmp.txt","a+");
	if(f==NULL || f1==NULL){
		printf("erreur");
	}
	else{
		while(fscanf(f,"%d %d %d %d %s %d %d/%d/%d\n",&bureauDeVote.identifiant,
													&bureauDeVote.capacite_electeurs,
													&bureauDeVote.capacite_observateurs,
													&bureauDeVote.nb_salle,
													bureauDeVote.adresse,
													&bureauDeVote.id_agent_bureau_vote,
													&bureauDeVote.dateCreationBureauDeVote.jour,
													&bureauDeVote.dateCreationBureauDeVote.mois,
													&bureauDeVote.dateCreationBureauDeVote.annee)!=EOF)
		{
			if(bureauDeVote.identifiant==id){
				fprintf(f1,"%d %d %d %d %s %d %d/%d/%d\n",bureauDeVoteModifier.identifiant,
													bureauDeVoteModifier.capacite_electeurs,
													bureauDeVoteModifier.capacite_observateurs,
													bureauDeVoteModifier.nb_salle,
													bureauDeVoteModifier.adresse,
													bureauDeVoteModifier.id_agent_bureau_vote,
													bureauDeVoteModifier.dateCreationBureauDeVote.jour,
													bureauDeVoteModifier.dateCreationBureauDeVote.mois,
													bureauDeVoteModifier.dateCreationBureauDeVote.annee);
			}
			else{
				fprintf(f1,"%d %d %d %d %s %d %d/%d/%d\n"   ,bureauDeVote.identifiant,
													bureauDeVote.capacite_electeurs,
													bureauDeVote.capacite_observateurs,
													bureauDeVote.nb_salle,
													bureauDeVote.adresse,
													bureauDeVote.id_agent_bureau_vote,
													bureauDeVote.dateCreationBureauDeVote.jour,
													bureauDeVote.dateCreationBureauDeVote.mois,
													bureauDeVote.dateCreationBureauDeVote.annee);
			}
		}
		
	}
	fclose(f);
	fclose(f1);
	remove("bureaudevote.txt");
	rename("tmp.txt","bureaudevote.txt");
}
void supprimerBureauDeVote(int id){
	if(recherBureauDeVoteParId(id)==0){
		printf("Bureau de vote introuvable!!\n");
		return;
	}
	BureauDeVote bureauDeVote;
	FILE *f,*f1;
	f=fopen("bureaudevote.txt","a+");
	f1=fopen("tmp.txt","a+");
	if(f==NULL || f1==NULL){
		printf("erreur");
	}
	else{
		while(fscanf(f,"%d %d %d %d %s %d %d/%d/%d\n",&bureauDeVote.identifiant,
													&bureauDeVote.capacite_electeurs,
													&bureauDeVote.capacite_observateurs,
													&bureauDeVote.nb_salle,
													bureauDeVote.adresse,
													&bureauDeVote.id_agent_bureau_vote,
													&bureauDeVote.dateCreationBureauDeVote.jour,
													&bureauDeVote.dateCreationBureauDeVote.mois,
													&bureauDeVote.dateCreationBureauDeVote.annee)!=EOF)
		{
			if(bureauDeVote.identifiant!=id){
				fprintf(f1,"%d %d %d %d %s %d %d/%d/%d\n",bureauDeVote.identifiant,
													bureauDeVote.capacite_electeurs,
													bureauDeVote.capacite_observateurs,
													bureauDeVote.nb_salle,
													bureauDeVote.adresse,
													bureauDeVote.id_agent_bureau_vote,
													bureauDeVote.dateCreationBureauDeVote.jour,
													bureauDeVote.dateCreationBureauDeVote.mois,
													bureauDeVote.dateCreationBureauDeVote.annee);
			}
		}
		
	}
	fclose(f);
	fclose(f1);
	remove("bureaudevote.txt");
	rename("tmp.txt","bureaudevote.txt");
}
void afficherBureauDeVote(char *nom_fichier){
	BureauDeVote bureauDeVote;
	FILE *f;
	f=fopen(nom_fichier,"a+");
	
	if(f==NULL){
		printf("erreur");
	}
	else{
		while(fscanf(f,"%d %d %d %d %s %d %d/%d/%d\n",&bureauDeVote.identifiant,
													&bureauDeVote.capacite_electeurs,
													&bureauDeVote.capacite_observateurs,
													&bureauDeVote.nb_salle,
													bureauDeVote.adresse,
													&bureauDeVote.id_agent_bureau_vote,
													&bureauDeVote.dateCreationBureauDeVote.jour,
													&bureauDeVote.dateCreationBureauDeVote.mois,
													&bureauDeVote.dateCreationBureauDeVote.annee)!=EOF)
		{
			printf("%d %d %d %d %s %d %d/%d/%d\n",bureauDeVote.identifiant,
													bureauDeVote.capacite_electeurs,
													bureauDeVote.capacite_observateurs,
													bureauDeVote.nb_salle,
													bureauDeVote.adresse,
													bureauDeVote.id_agent_bureau_vote,
													bureauDeVote.dateCreationBureauDeVote.jour,
													bureauDeVote.dateCreationBureauDeVote.mois,
													bureauDeVote.dateCreationBureauDeVote.annee);
			
		}
		
	}
	fclose(f);
}
int recherBureauDeVoteParId(int id){
	BureauDeVote bureauDeVote;
	FILE *f;
	f=fopen("bureaudevote.txt","a+");
	int trouve=0;
	if(f==NULL){
		printf("erreur");
	}
	else{
		while(fscanf(f,"%d %d %d %d %s %d %d/%d/%d\n",&bureauDeVote.identifiant,
													&bureauDeVote.capacite_electeurs,
													&bureauDeVote.capacite_observateurs,
													&bureauDeVote.nb_salle,
													bureauDeVote.adresse,
													&bureauDeVote.id_agent_bureau_vote,
													&bureauDeVote.dateCreationBureauDeVote.jour,
													&bureauDeVote.dateCreationBureauDeVote.mois,
													&bureauDeVote.dateCreationBureauDeVote.annee)!=EOF)
		{
			if(bureauDeVote.identifiant==id)
				trouve =1;
			
		}
		
	}
	fclose(f);
	return trouve;
	
}
int nbTotalObservateur(char *nom_fichier){
	BureauDeVote bureauDeVote;
	int s=0;
	FILE *f;
	f=fopen(nom_fichier,"r");
	if(f==NULL)
		return 0;
	else{
		while(fscanf(f,"%d %d %d %d %s %d %d/%d/%d\n",&bureauDeVote.identifiant,
							      &bureauDeVote.capacite_electeurs,
							      &bureauDeVote.capacite_observateurs,
								&bureauDeVote.nb_salle,
								bureauDeVote.adresse,
								&bureauDeVote.id_agent_bureau_vote,
								&bureauDeVote.dateCreationBureauDeVote.jour,
								&bureauDeVote.dateCreationBureauDeVote.mois,
								&bureauDeVote.dateCreationBureauDeVote.annee)!=EOF)
		{
			s+=bureauDeVote.capacite_observateurs;
		}
		fclose(f);
		return s;
	}
}
void triBureauDeVoteParNbObservateur(char *nom_fichier){
	//fichier==>tableau
	BureauDeVote bureauDeVotes[999],bureauDeVote,auxbureauDeVote;
	int n=0,i,j,min;
	FILE *f;
	f=fopen(nom_fichier,"r");
	if(f==NULL)
		return;
	else{
		while(fscanf(f,"%d %d %d %d %s %d %d/%d/%d\n",&bureauDeVote.identifiant,
							      &bureauDeVote.capacite_electeurs,
							      &bureauDeVote.capacite_observateurs,
								&bureauDeVote.nb_salle,
								bureauDeVote.adresse,
								&bureauDeVote.id_agent_bureau_vote,
								&bureauDeVote.dateCreationBureauDeVote.jour,
								&bureauDeVote.dateCreationBureauDeVote.mois,
								&bureauDeVote.dateCreationBureauDeVote.annee)!=EOF)
		{
			bureauDeVotes[n]=bureauDeVote;
			n++;
		}
		fclose(f);
	}
	//tri par selection
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(bureauDeVotes[min].capacite_observateurs>bureauDeVotes[j].capacite_observateurs){
				min=j;
			}
		}
		if(min!=i){
			auxbureauDeVote=bureauDeVotes[i];
			bureauDeVotes[i]=bureauDeVotes[min];
			bureauDeVotes[min]=auxbureauDeVote;
		}
	}
	//tableau==>fichier
	FILE *f1;
	f1=fopen("bureaudevotetriee.txt","w");
	if(f1==NULL)
		return;
	else{
		for(i=0;i<n;i++){
			fprintf(f1,"%d %d %d %d %s %d %d/%d/%d\n",bureauDeVotes[i].identifiant,
								bureauDeVotes[i].capacite_electeurs,
								bureauDeVotes[i].capacite_observateurs,
								bureauDeVotes[i].nb_salle,
								bureauDeVotes[i].adresse,
								bureauDeVotes[i].id_agent_bureau_vote,
								bureauDeVotes[i].dateCreationBureauDeVote.jour,
								bureauDeVotes[i].dateCreationBureauDeVote.mois,
								bureauDeVotes[i].dateCreationBureauDeVote.annee);
		}
		fclose(f1);
	}
	
	
}
void taux (char *nomficher,float *tn,float *te)
{
observateur o;
    int totale=0,n=0,e=0;
    FILE * f=fopen(nomficher, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %d %d %s %s\n",o.Nom,o.Prenom,&o.d.jour,&o.d.mois,&o.d.annee,&o.cin,&o.id,o.nationalite,o.professione)!=EOF)
        {totale++;
            if(strcmp(o.nationalite,"tunisienne")==0)
                n++;
else
           e++;
        }
*tn=(float )n/totale;
*te=(float) e/totale;
fclose(f);
    }
}





























