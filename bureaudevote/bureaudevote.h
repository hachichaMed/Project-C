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
typedef struct
{
    char Nom [20];
    char Prenom [20];
    DateBureauDeVote d;
    int  cin;
    int id;
    char nationalite[20];
    char professione[20];

  
} observateur;

void ajouterBureauDeVote(BureauDeVote bureauDeVote);
void modifierBureauDeVote(int id,BureauDeVote bureauDeVoteModifier);
void supprimerBureauDeVote(int id);
void afficherBureauDeVote(char *nom_fichier);
int recherBureauDeVoteParId(int id);
int nbTotalObservateur(char *nom_fichier);
void triBureauDeVoteParNbObservateur(char *nom_fichier);
void taux (char *nomficher,float *tn,float *te);
