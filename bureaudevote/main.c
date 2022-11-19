#include<stdio.h>
#include<stdlib.h>
#include "bureaudevote.h"
int main(){
	int choix,id_modifer,id_supprimer;
	BureauDeVote bureauDeVote,bureauDeVoteModifier;
	do{
		do{
			printf("\n---------------------MENU----------------------\n");
			printf("1)-Ajouter Bureau de vote\n");
			printf("2)-Modifier Bureau de vote\n");
			printf("3)-Supprimer Bureau de vote\n");
			printf("4)-Afficher les bureaux de vote\n");
			printf("5)-Donner nombre des observateur + trier bureau de vote par nbObservateur\n");
			printf("0)-Quitter\n");
			printf("Donner votre choix:");
			scanf("%d",&choix);
		}while(choix<0 || choix>5);
		switch(choix){
			case 1:
				printf("Donner identifiant:");
				scanf("%d",&bureauDeVote.identifiant);
				printf("Donner capacite electeurs:");
				scanf("%d",&bureauDeVote.capacite_electeurs);
				printf("Donner capacite observateurs:");
				scanf("%d",&bureauDeVote.capacite_observateurs);
				printf("Donner nb_salle:");
				scanf("%d",&bureauDeVote.nb_salle);
				printf("Donner adresse:");
				fflush(stdin);
				scanf("%s",bureauDeVote.adresse);
				printf("Donner id_agent_bureau_vote:");
				scanf("%d",&bureauDeVote.id_agent_bureau_vote);
				printf("Donner la date de creation du bureau de vote:\n");
				printf("jour:");
				scanf("%d",&bureauDeVote.dateCreationBureauDeVote.jour);
				printf("mois:");
				scanf("%d",&bureauDeVote.dateCreationBureauDeVote.mois);
				printf("annee:");
				scanf("%d",&bureauDeVote.dateCreationBureauDeVote.annee);
				ajouterBureauDeVote(bureauDeVote);
				break;
			case 2:
				printf("Donner identifiant du bureau de vote a modifier:");
				scanf("%d",&id_modifer);
				printf("Donner capacite electeurs:");
				scanf("%d",&bureauDeVoteModifier.capacite_electeurs);
				printf("Donner capacite observateurs:");
				scanf("%d",&bureauDeVoteModifier.capacite_observateurs);
				printf("Donner nb_salle:");
				scanf("%d",&bureauDeVoteModifier.nb_salle);
				printf("Donner adresse:");
				fflush(stdin);
				scanf("%s",bureauDeVoteModifier.adresse);
				printf("Donner id_agent_bureau_vote:");
				scanf("%d",&bureauDeVoteModifier.id_agent_bureau_vote);
				printf("Donner la date de creation du bureau de vote:\n");
				printf("jour:");
				scanf("%d",&bureauDeVoteModifier.dateCreationBureauDeVote.jour);
				printf("mois:");
				scanf("%d",&bureauDeVoteModifier.dateCreationBureauDeVote.mois);
				printf("annee:");
				scanf("%d",&bureauDeVoteModifier.dateCreationBureauDeVote.annee);
				bureauDeVoteModifier.identifiant=id_modifer;
				modifierBureauDeVote(id_modifer,bureauDeVoteModifier);
				break;
			case 3:
				printf("Donner identifiant du bureau de vote a supprimer:");
				scanf("%d",&id_supprimer);
				supprimerBureauDeVote(id_supprimer);
				break;
			case 4:
				afficherBureauDeVote("bureaudevote.txt");
				break;
			case 5:
				triBureauDeVoteParNbObservateur("bureaudevote.txt");
				afficherBureauDeVote("bureaudevotetriee.txt");
				printf("\n le nombre totale des observateurs est:%d\n",nbTotalObservateur("bureaudevote.txt"));
				break;
		}
	}while(choix!=0);
	return 0;
}
