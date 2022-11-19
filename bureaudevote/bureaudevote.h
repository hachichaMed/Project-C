typedef struct DateBureauDeVote{
	int jour;
	int mois;
	int annee;
}DateBureauDeVote;
typedef struct BureauDeVote{
	int identifiant;
	int capacite_electeurs;
	int capacite_observateurs;
	int nb_salle;
	char adresse[50];
	int id_agent_bureau_vote;
	DateBureauDeVote dateCreationBureauDeVote;
}BureauDeVote;
void ajouterBureauDeVote(BureauDeVote bureauDeVote);
void modifierBureauDeVote(int id,BureauDeVote bureauDeVoteModifier);
void supprimerBureauDeVote(int id);
void afficherBureauDeVote(char *nom_fichier);
int recherBureauDeVoteParId(int id);
int nbTotalObservateur(char *nom_fichier);
void triBureauDeVoteParNbObservateur(char *nom_fichier);
