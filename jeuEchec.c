
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* --- Définitions de constantes --- */
#define CHOIX_NON_DEFINI 99

/* --- Variables globales --- */
char plateau[8][8];
char coupSuivant;
char tour[10]="Blanc";
int coupJeu=1;
char bidon;
int c1, c2, l1, l2;
int cptR=0, cptT1=0, cptT2=0;
int cptr=0, cptt1=0, cptt2=0;
int a_sauvegarder = 0;
int ifroq=0;
int ifcheckmat=0;
int null=1;

/* --- Déclarations préliminaires --- */
/* - Procédures principales - */
void nouvellePartie();
void sauvegarde();
void chargement();
void quitter();
/* - Fonction de vérification générale- */
int checkPiece(int paramc, int paraml);
int ifnoir();
int verificationEntree(char colonne, int ligne);
int verifoccupe(int paramla, int paramca);
int finLigne_pion(int paramla);
int checkRoi();
int haspiece();
int checkmat();
int partieNull();
/* - Procedure pour nouvelle partie - */
void initialisation();
void mouvement();
void departToArrivee(int paramcd, int paramld, int paramca, int paramla);
void roq();
void doubledeplacement(int paramcd, int paramld, int paramca, int paramla, int paramCheckRoi);
void doubledeplacementRoi(int paramcd, int paramld, int paramca, int paramla, int paramCheckRoi);
/* - Fonction de verification des mouvements possibles- */
int mouvementsPossibles(int paramcd, int paramld, int paramca, int paramla);
int deplacementCavalier(int paramcd, int paramld, int paramca, int paramla);
int deplacementHorVer(int paramcd, int paramld, int paramca, int paramla);
int deplacementDiagonale(int paramcd, int paramld, int paramca, int paramla);
/* - Fonction Convertir Char to Int- */
int conv_colonne_ChartoInt(char paramc);

/* ===========PROGRAMME PRINCIPAL============ */
main()
{
	int choix = CHOIX_NON_DEFINI;

	/* -- boucle de menu -- */
	while(choix!=0)
	{
		/* -- Affichage du menu -- */
		printf("\n");
		printf(" Bienvenue dans le jeu d'echec!\n");
		printf(" -1-Nouvelle partie\n");
		printf(" -2-Charger une partie\n");
		printf(" -0-Quitter\n");
		/* -- saisie du choix -- */
		printf(" Votre choix : ");
		scanf("%d", &choix);
		printf("\n");
		/* -- Appel des sous-programmes selon le choix saisi -- */
		switch(choix)
		{
		case 1:
			coupJeu=1;
			initialisation();
			nouvellePartie();
			break;
		case 2:
		    chargement();
            break;
		case 0:
            printf(" Au revoir!\n");
            break;
		default:
			printf(" Choix ERRONE!!\n");
			break;
		}/* fin du switch */
	}/* fin du while */
}/* fin du main */
/* ============================================================================= */

/* ===========PROCEDURES PRINCIPALES============ */
/* ==Procedure pour demarrer une nouvelle partie de jeu== */
void nouvellePartie()
{

	/*Initialiser la variable*/
	coupSuivant = CHOIX_NON_DEFINI;
	/* Sortir la boucle apres avoir tape q */
	while(coupSuivant!='q')
	{

		/* Quel tour */
		if(ifnoir())
		{
			strcpy(tour, "Noir");
		}
		else
		{
			strcpy(tour, "Blanc");
        }

		/* L'affichage de plateau de jeu */
	    printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  8 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n", plateau[7][0], plateau[7][1], plateau[7][2], plateau[7][3], plateau[7][4], plateau[7][5], plateau[7][6], plateau[7][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  7 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n", plateau[6][0], plateau[6][1], plateau[6][2], plateau[6][3], plateau[6][4], plateau[6][5], plateau[6][6], plateau[6][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  6 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n", plateau[5][0], plateau[5][1], plateau[5][2], plateau[5][3], plateau[5][4], plateau[5][5], plateau[5][6], plateau[5][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  5 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n", plateau[4][0], plateau[4][1], plateau[4][2], plateau[4][3], plateau[4][4], plateau[4][5], plateau[4][6], plateau[4][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  4 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n", plateau[3][0], plateau[3][1], plateau[3][2], plateau[3][3], plateau[3][4], plateau[3][5], plateau[3][6], plateau[3][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  3 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n", plateau[2][0], plateau[2][1], plateau[2][2], plateau[2][3], plateau[2][4], plateau[2][5], plateau[2][6], plateau[2][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  2 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n", plateau[1][0], plateau[1][1], plateau[1][2], plateau[1][3], plateau[1][4], plateau[1][5], plateau[1][6], plateau[1][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  1 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n",  plateau[0][0], plateau[0][1], plateau[0][2], plateau[0][3], plateau[0][4], plateau[0][5], plateau[0][6], plateau[0][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("        a       b       c       d       e       f       g       h    \n");
        printf("\n");
        printf("                                                 Tour de jeu : %s \n", tour);
        printf("                                                 Coup : %d \n", coupJeu);
        printf("\n");


		/* Si le tour = blanc, le roi blanc est en echec */
	    if((checkRoi()==1)&&(!ifnoir()))
	    {
            printf(" Echec au roi!!!\n");
        }
		/* Si le tour = noir, le roi noir est en echec */
		else if((checkRoi()==2)&&(ifnoir()))
	    {
            printf(" Echec au roi!!!\n");
        }

		/* L'appellation de procedure roq() */
		roq();

		/* Si l'utilisateur a effectué un roq => tour suivant*/
		if(ifroq)
		{
			coupJeu++;
			a_sauvegarder=1;
		}
		/* Sinon, demander le coup*/
		else
		{

            printf(" Sauvegarder(s)\n");
            printf(" Quitter(q)\n");
            printf(" Coup suivant: ");
            while((bidon=getchar())!='\n');
            scanf("%c", &coupSuivant);

            switch(coupSuivant)
            {
                /* Les mêmes procedures que pour le menu */
                case 's': sauvegarde(); break;
                case 'q': quitter(); break;

                /* Le procedure mouvement() si l'utilisateur a saisi une piece */
                case 'T': case 'C': case 'F': case 'D': case 'R': case 'P':
                    //Tour de jeu : blanc => coup : 1, 3, 5, 7 ...
                    if(!ifnoir())
                    {
                        if(haspiece()){
                            mouvement();
                        }
                        else{
                            printf(" La piece n'existe plus dans le plateau. \n");
                        }
                    }
                    else
                    {
                        printf(" Vous ne pouvez pas bouger une piece blanche.\n");
                    }
                    break;

                case 't': case 'k': case 'f': case 'd': case 'r': case 'i':
                    //Tour de jeu : noir => coup : 2, 4, 6, 8 ...
                    if(ifnoir())
                    {
                        if(haspiece()){
                            mouvement();
                        }
                        else{
                            printf(" La piece n'existe plus dans le plateau.\n");
                        }
                    }
                    else
                    {
                        printf(" Vous ne pouvez pas bouger une piece noire.\n");
                    }
                    break;

                default:
                    printf(" Commande incorrecte.\n");break;
            }/* fin du switch */
        }/* fin du if */
    }/* fin du switch */

	/*L'affichage de plateau après Partie Nulle et Echec et Mat*/
	if(coupSuivant=='q'){
		/* L'affichage de plateau de jeu */
	    printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  8 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n", plateau[7][0], plateau[7][1], plateau[7][2], plateau[7][3], plateau[7][4], plateau[7][5], plateau[7][6], plateau[7][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  7 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n", plateau[6][0], plateau[6][1], plateau[6][2], plateau[6][3], plateau[6][4], plateau[6][5], plateau[6][6], plateau[6][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  6 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n", plateau[5][0], plateau[5][1], plateau[5][2], plateau[5][3], plateau[5][4], plateau[5][5], plateau[5][6], plateau[5][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  5 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n", plateau[4][0], plateau[4][1], plateau[4][2], plateau[4][3], plateau[4][4], plateau[4][5], plateau[4][6], plateau[4][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  4 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n", plateau[3][0], plateau[3][1], plateau[3][2], plateau[3][3], plateau[3][4], plateau[3][5], plateau[3][6], plateau[3][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  3 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n", plateau[2][0], plateau[2][1], plateau[2][2], plateau[2][3], plateau[2][4], plateau[2][5], plateau[2][6], plateau[2][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  2 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n", plateau[1][0], plateau[1][1], plateau[1][2], plateau[1][3], plateau[1][4], plateau[1][5], plateau[1][6], plateau[1][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("  1 +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +   %c   +\n",  plateau[0][0], plateau[0][1], plateau[0][2], plateau[0][3], plateau[0][4], plateau[0][5], plateau[0][6], plateau[0][7]);
        printf("    +       +       +       +       +       +       +       +       +\n");
        printf("    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("        a       b       c       d       e       f       g       h    \n");
        printf("\n");
	}/* fin du if */

}/* ==FinProcedure - nouvellePartie ==*/

/* ==Procedure - sauvegarde ==*/
void sauvegarde()
{
    int i, j ;
    FILE *f1              ;
    char nomfichier[100]  ;

    if (coupJeu == 1)
    {
        printf(" Aucune partie a sauvegarder\n");
    }/* fin du if */
    else
    {
        printf(" Nom du fichier a sauvegarder : ");
        scanf("%s",nomfichier);

        f1=fopen(nomfichier,"w");
		/* Sauvegarder aussi le tour et le coup de jeu.*/
        fprintf(f1, "%s\n", tour);
        fprintf(f1, "%d\n", coupJeu);
		/* Pour savoir si l'utilisateur a déjà bouger le roi et les tours.*/
		fprintf(f1, "%d %d %d %d %d %d\n", cptR, cptT1, cptT2, cptr, cptt1, cptt2);
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++){
					/* La fonction "fscanf" ne peut pas lire des espaces*/
					/* elle va passer des espaces jusuqu'à il y a une donnée à lire*/
					/* Pour cette raison, nous convertissons l'espace en '9'*/
                    if(plateau[i][j]==' '){
                        plateau[i][j]= '9';
                        fprintf(f1,"%c\n",plateau[i][j]);
                        plateau[i][j]=' ';
                    }
                    fprintf(f1,"%c\n",plateau[i][j]);
            }
        }
        fclose(f1);
        printf(" Partie sauvegardee. \n");
        a_sauvegarder = 0;
    }/* fin du else */
}/* ==FinProcedure - sauvegarde ==*/

/* ==Procedure - chargement ==*/
void chargement()
{
    int i, j;
    FILE *f1              ;
    char nomfichier[100];
    printf(" Nom du fichier a lire : ");
    scanf("%s",nomfichier);
    f1 = fopen(nomfichier,"r");

    if(f1==NULL){
	printf(" Pas de donnees a lire.\n");
    }/* fin du if */
    else
    {
	    fscanf(f1, "%s\n", tour);
	    fscanf(f1, "%d\n", &coupJeu);
		fscanf(f1, "%d %d %d %d %d %d\n", &cptR, &cptT1, &cptT2, &cptr, &cptt1, &cptt2);
	    while(!feof(f1))
        {
            for(i=0; i<8; i++)
            {
                for(j=0; j<8; j++){
                    fscanf(f1, "%c\n", &plateau[i][j]);
					/* convertir '9' en espace*/
                    if(plateau[i][j] == '9'){
                        plateau[i][j] = ' ';
                    }
                }
            }
        }/* fin du while */
        fclose(f1);
        printf(" Partie chargee\n");
        nouvellePartie();
    }/* fin du else */
}/* ==FinProcedure - chargement ==*/

/* ==Procedure - quitter ==*/
void quitter(){
	char reponse;

	if(a_sauvegarder==1)
	{
		while((reponse!='o')&&(reponse!='n'))
        {
			printf(" Voulez-vous sauvegarder la partie (o/n) : ");
			while((bidon=getchar())!='\n');
			scanf("%c", &reponse);
			reponse = tolower(reponse);
			if(reponse=='o'){
				sauvegarde();
			}
			else{
                printf(" Partie nulle.\n");
				a_sauvegarder=0;
			}
		}/* fin du while */
	}/* fin du if */
}/* ==FinProcedure - quitter ==*/
/* ============================================================================= */

/* ===========FONCTION VERIFICATION GENERALE============ */
/* == Fonction pour verifier le (coupSuivant) et la piece dans la case depart sont identiques == */
int checkPiece(int paramc, int paraml)
{
	int trouve=0;
	if(plateau[paraml][paramc]==coupSuivant)
	{
		trouve = 1;
	}
	return trouve;
}/* ==FinFonction - checkPiece== */

/* ==Fonction pour verifier si la piece est noire ou pas== */
int ifnoir(){
    int noir;
    if((coupJeu%2)==0)
        noir=1;
    else
        noir=0;
    return noir;
}/* ==FinFonction - Ifnoir== */

/* ==Fonction pour verifier si l'utilisateur a bien saisi la case== */
int verificationEntree(char colonne, int ligne){
	int verif = 0;

	/* Au cas où l’utilisateur rentre la colonne en majuscule */
	colonne = tolower(colonne);

	switch(colonne){
	case 'a': case 'b': case 'c': case 'd':
	case 'e': case 'f': case 'g': case 'h':
		verif = 1;
		break;
	default : verif=0; break;
	}

	if(verif){
		switch(ligne){
		case 1: case 2: case 3: case 4:
		case 5: case 6: case 7: case 8:
			verif = 1;
			break;
		default : verif=0; break;
		}
	}
	return verif;
}/* ==FinFonction - verificationEntree== */

/* ==Fonction pour verifier si la case est vide ou pas== */
int verifoccupe(int paramla, int paramca)
{
	int verif = 0;
	if(plateau[paramla][paramca]==' ')
	{
		verif = 1;
	}
	else if(plateau[paramla][paramca]!=' ')
	{
		switch(plateau[paramla][paramca]){
		case 'T': case 'C': case 'F': case 'D': case 'R': case 'P': verif=3; break;
		case 't': case 'k': case 'f': case 'd': case 'r': case 'i': verif=5; break;
		}
	}
	return verif;
}/* ==FinFonction - verifoccupe == */

/* ==Fonction pour verifier si la pion atteint la fin de ligne == */
int finLigne_pion(int paramla)
{
    int fin=0;
    if(((paramla)==7)||((paramla)==0))
    {
        return 1;
    }
    return fin;
}
/* ==FinFonction - finLigne_pion == */

/* ==Fonction pour verifier si la piece saisie n'est pas encore mange == */
int haspiece(){
    int i, j;
    int hasPiece = 0;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            if(plateau[i][j]==coupSuivant)
            {
                hasPiece = 1;
		j=8;
		i=8;
            }
        }
    }
    return hasPiece;
}
/* ==FinFonction - haspiece == */

/* ==Fonction pour verifier si le roi est en échec ou pas == */
/* ==Renvoie 1 si le roi blanc est en échec == */
/* ==Renvoie 2 si le roi noir est en échec == */
/* ==Renvoie 0 si les deux rois ne sont pas en échec == */
int checkRoi()
{
    int ifcheckRoi=0;
    int i, j, k;

	/* Deux boucle pour parcourir tous les cases de plateau */
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
			/* Si la case n'est pas vide */
            if(plateau[i][j]!=' ')
            {
                switch(plateau[i][j])
                {
                    case 'P':
                        if(plateau[i+1][j+1]=='r'){
                            ifcheckRoi=2;
                        }
                        if(plateau[i+1][j-1]=='r'){
                            ifcheckRoi=2;
                        }
                        break;
                    case 'i':
                        if(plateau[i-1][j+1]=='R'){
                            ifcheckRoi=1;
                        }
                        if(plateau[i-1][j-1]=='R'){
                            ifcheckRoi=1;
                        }
                        break;

                    case 'T':
                        for(k=1; k<8; k++){
                            if((plateau[i+k][j]!=' ')&&((i+k)<8)){
                                if(plateau[i+k][j]=='r')
                                {
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }
                        for(k=1; k<8; k++){
                            if((plateau[i-k][j]!=' ')&&((i-k)>=0)){
                                if(plateau[i-k][j]=='r')
                                {
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }
                        for(k=1; k<8; k++){
                            if((plateau[i][j+k]!=' ')&&((j+k)<8)){
                                if(plateau[i][j+k]=='r')
                                {
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<8; k++){
                            if((plateau[i][j-k]!=' ')&&((j-k)>=0)){
                                if(plateau[i][j-k]=='r')
                                {
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }
                        break;
                    case 't':
                        for(k=1; k<8; k++){
                            if((plateau[i+k][j]!=' ')&&((i+k)<8))
                            {
                                if(plateau[i+k][j]=='R')
                                {
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<8; k++){
                            if((plateau[i-k][j]!=' ')&&((i-k)>=0)){
                                if(plateau[i-k][j]=='R')
                                {
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<8; k++){
                            if((plateau[i][j+k]!=' ')&&((j+k)<8)){
                                if(plateau[i][j+k]=='R'){
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<8; k++){
                            if((plateau[i][j-k]!=' ')&&((j-k)>=0)){
                                if(plateau[i][j-k]=='R'){
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }

                        break;

                    case 'C':
                        if(plateau[i+1][j-2]=='r')
                            ifcheckRoi=2;
                        if(plateau[i+2][j-1]=='r')
                            ifcheckRoi=2;
                        if(plateau[i+2][j+1]=='r')
                            ifcheckRoi=2;
                        if(plateau[i+1][j+2]=='r')
                            ifcheckRoi=2;
                        if(plateau[i-1][j+2]=='r')
                            ifcheckRoi=2;
                        if(plateau[i-2][j+1]=='r')
                            ifcheckRoi=2;
                        if(plateau[i-2][j-1]=='r')
                            ifcheckRoi=2;
                        if(plateau[i-1][j-2]=='r')
                            ifcheckRoi=2;
                        break;
                    case 'k':
                        if(plateau[i+1][j-2]=='R')
                            ifcheckRoi=1;

                        if(plateau[i+2][j-1]=='R')
                            ifcheckRoi=1;

                        if(plateau[i+2][j+1]=='R')
                            ifcheckRoi=1;

                        if(plateau[i+1][j+2]=='R')
                            ifcheckRoi=1;

                        if(plateau[i-1][j+2]=='R')
                            ifcheckRoi=1;

                        if(plateau[i-2][j+1]=='R')
                            ifcheckRoi=1;

                        if(plateau[i-2][j-1]=='R')
                            ifcheckRoi=1;

                        if(plateau[i-1][j-2]=='R')
                            ifcheckRoi=1;

                        break;

                    case 'F':
                        for(k=1; k<8; k++){
                            if((plateau[i+k][j+k]!=' ')&&((i+k)<8)&&((j+k)<8))
                            {
                                if(plateau[i+k][j+k]=='r')
                                {
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<=8; k++){
                            if((plateau[i-k][j+k]!=' ')&&((i-k)>=0)&&((j+k)<8)){
                                if(plateau[i-k][j+k]=='r')
                                {
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<=8; k++){
                            if((plateau[i+k][j-k]!=' ')&&((i+k)<8)&&((j-k)>=0)){
                                if(plateau[i+k][j-k]=='r'){
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<=8; k++){
                            if((plateau[i-k][j-k]!=' ')&&((i-k)>=0)&&((j-k)>=0)){
                                if(plateau[i-k][j-k]=='r'){
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }

                        break;

                    case 'f':
                        for(k=1; k<=8; k++){
                            if((plateau[i+k][j+k]!=' ')&&((i+k)<8)&&((j+k)<8))
                            {
                                if(plateau[i+k][j+k]=='R')
                                {
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<=8; k++){
                            if((plateau[i-k][j+k]!=' ')&&((i-k)>=0)&&((j+k)<8)){
                                if(plateau[i-k][j+k]=='R')
                                {
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<=8; k++){
                            if((plateau[i+k][j-k]!=' ')&&((i+k)<8)&&((j-k)>=0)){
                                if(plateau[i+k][j-k]=='R'){
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<=8; k++){
                            if((plateau[i-k][j-k]!=' ')&&((i+k)>=0)&&((j-k)>=0)){
                                if(plateau[i-k][j-k]=='R'){
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }
                        break;

                    case 'D':
                        for(k=1; k<8; k++){
                            if((plateau[i+k][j]!=' ')&&((i+k)<8)){
                                if(plateau[i+k][j]=='r')
                                {
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }
                        for(k=1; k<8; k++){
                            if((plateau[i-k][j]!=' ')&&((i-k)>=0)){
                                if(plateau[i-k][j]=='r')
                                {
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }
                        for(k=1; k<8; k++){
                            if((plateau[i][j+k]!=' ')&&((j+k)<8)){
                                if(plateau[i][j+k]=='r')
                                {
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<8; k++){
                            if((plateau[i][j-k]!=' ')&&((j-k)>=0)){
                                if(plateau[i][j-k]=='r')
                                {
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }

						for(k=1; k<8; k++){
                            if((plateau[i+k][j+k]!=' ')&&((i+k)<8)&&((j+k)<8))
                            {
                                if(plateau[i+k][j+k]=='r')
                                {
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<=8; k++){
                            if((plateau[i-k][j+k]!=' ')&&((i-k)>=0)&&((j+k)<8)){
                                if(plateau[i-k][j+k]=='r')
                                {
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<=8; k++){
                            if((plateau[i+k][j-k]!=' ')&&((i+k)<8)&&((j-k)>=0)){
                                if(plateau[i+k][j-k]=='r'){
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<=8; k++){
                            if((plateau[i-k][j-k]!=' ')&&((i-k)>=0)&&((j-k)>=0)){
                                if(plateau[i-k][j-k]=='r'){
                                    ifcheckRoi=2;
                                }
                                k = 9;
                            }
                        }

                        break;

                    case 'd':
						for(k=1; k<8; k++){
                            if((plateau[i+k][j]!=' ')&&((i+k)<8))
                            {
                                if(plateau[i+k][j]=='R')
                                {
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<8; k++){
                            if((plateau[i-k][j]!=' ')&&((i-k)>=0)){
                                if(plateau[i-k][j]=='R')
                                {
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<8; k++){
                            if((plateau[i][j+k]!=' ')&&((j+k)<8)){
                                if(plateau[i][j+k]=='R'){
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<8; k++){
                            if((plateau[i][j-k]!=' ')&&((j-k)>=0)){
                                if(plateau[i][j-k]=='R'){
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }

						for(k=1; k<=8; k++){
                            if((plateau[i+k][j+k]!=' ')&&((i+k)<8)&&((j+k)<8))
                            {
                                if(plateau[i+k][j+k]=='R')
                                {
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<=8; k++){
                            if((plateau[i-k][j+k]!=' ')&&((i-k)>=0)&&((j+k)<8)){
                                if(plateau[i-k][j+k]=='R')
                                {
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<=8; k++){
                            if((plateau[i+k][j-k]!=' ')&&((i+k)<8)&&((j-k)>=0)){
                                if(plateau[i+k][j-k]=='R'){
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }

                        for(k=1; k<=8; k++){
                            if((plateau[i-k][j-k]!=' ')&&((i+k)>=0)&&((j-k)>=0)){
                                if(plateau[i-k][j-k]=='R'){
                                    ifcheckRoi=1;
                                }
                                k = 9;
                            }
                        }

                        break;

                    case 'R': case 'r':

                        if(((j-1)>=0)&&(plateau[i][j-1]=='r'))
                            ifcheckRoi=2;
						else if(((j-1)>=0)&&(plateau[i][j-1]=='R'))
							ifcheckRoi=1;

                        if(((j+1)<8)&&(plateau[i][j+1]=='r'))
                            ifcheckRoi=2;
						else if(((j+1)<8)&&(plateau[i][j+1]=='R'))
							ifcheckRoi=1;

                        if(((i+1)<8)&&(plateau[i+1][j]=='r'))
                            ifcheckRoi=2;
						else if(((i+1)<8)&&(plateau[i+1][j]=='R'))
                            ifcheckRoi=1;

						if(((i-1)>=0)&&(plateau[i-1][j]=='r'))
                            ifcheckRoi=2;
						else if(((i-1)>=0)&&(plateau[i-1][j]=='R'))
                            ifcheckRoi=1;

						if(((j-1)>=0)&&((i-1)>=0)&&(plateau[i-1][j-1]=='r'))
                            ifcheckRoi=2;
						else if(((j-1)>=0)&&((i-1)>=0)&&(plateau[i-1][j-1]=='R'))
                            ifcheckRoi=1;

						if(((i+1)<8)&&((j-1)>=0)&&(plateau[i+1][j-1]=='r'))
                            ifcheckRoi=2;
						else if(((i+1)<8)&&((j-1)>=0)&&(plateau[i+1][j-1]=='R'))
                            ifcheckRoi=1;

                        if(((i+1)<8)&&((j+1)<8)&&(plateau[i+1][j+1]=='r'))
                            ifcheckRoi=2;
						else if(((i+1)<8)&&((j+1)<8)&&(plateau[i+1][j+1]=='R'))
                            ifcheckRoi=1;

                        break;
				}/* fin du switch */
			}/* fin du if */
		}/* fin du for */
	}/* fin du for */
    return ifcheckRoi;
}/* ==FinFonction - checkRoi == */

/* ==Fonction pour vérifier si le roi adverse est en échec et mat ou pas== */
/* ==Pour chaque case du plateau, si la case n'est pas vide, switch(pièce)== */
/* ==Pour chaque pièce, vérifier si après tous les mouvements possibles */
/*   le roi est toujours en échec ou pas== */
/* ==Si après un mouvement, le roi n'est plus en échec, ifcheckmat = false == */
int checkmat()
{
    int i, j, k;
	ifcheckmat=1;
	/* Si le tour = noir, le roi blanc est en echec */
	char ValeurCoupSuivant;
	ValeurCoupSuivant = coupSuivant;

	if((ifnoir())&&(checkRoi()==1)){
		for(i=0; i<8; i++)
		{
			for(j=0; j<8; j++)
			{
				if(plateau[i][j]!=' ')
				{
					coupSuivant = plateau[i][j];
					switch(plateau[i][j])
					{
						case 'P':
							if(mouvementsPossibles(j, i, j+1, i+1)){
								/* Procédure pour la vérification */
								doubledeplacement(j, i, j+1, i+1, 1);
							}
							if(mouvementsPossibles(j, i, j-1, i+1)){
								doubledeplacement(j, i, j-1, i+1, 1);
							}

							break;
						case 'T':
							for(k=1; k<8; k++){
								if((i+k)<8){
									if(mouvementsPossibles(j, i, j, i+k)){
										doubledeplacement(j, i, j, i+k, 1);
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((i-k)>=0){
									if(mouvementsPossibles(j, i, j, i-k)){
										doubledeplacement(j, i, j, i-k, 1);
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((j+k)<8){
									if(mouvementsPossibles(j, i, j+k, i)){
										doubledeplacement(j, i, j+k, i, 1);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<8; k++){
								if((j-k)>=0){
									if(mouvementsPossibles(j, i, j-k, i)){
										doubledeplacement(j, i, j-k, i, 1);
									}
									else{
										k=8;
									}
								}
							}
							break;
						case 'C':
							if(mouvementsPossibles(j, i, j-2, i+1)){
								doubledeplacement(j, i, j-2, i+1, 1);
							}

							if(mouvementsPossibles(j, i, j-1, i+2)){
								doubledeplacement(j, i, j-1, i+2, 1);
							}

							if(mouvementsPossibles(j, i, j+1, i+2)){
								doubledeplacement(j, i, j+1, i+2, 1);
							}

							if(mouvementsPossibles(j, i, j+2, i+1)){
								doubledeplacement(j, i, j+2, i+1, 1);
							}

							if(mouvementsPossibles(j, i, j+2, i-1)){
								doubledeplacement(j, i, j+2, i-1, 1);
							}

							if(mouvementsPossibles(j, i, j+1, i-2)){
								doubledeplacement(j, i, j+1, i-2, 1);
							}


							if(mouvementsPossibles(j, i, j-1, i-2)){
								doubledeplacement(j, i, j-1, i-2, 1);
							}

							if(mouvementsPossibles(j, i, j-2, i-1)){
								doubledeplacement(j, i, j-2, i-1, 1);
							}
							break;

						case 'F':
							for(k=1; k<8; k++){
								if(((i+k)<8)&&((j+k)<8))
								{
									if(mouvementsPossibles(j, i, j+k, i+k)){
										doubledeplacement(j, i, j+k, i+k, 1);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j+k)<8)){
									if(mouvementsPossibles(j, i, j+k, i-k)){
										doubledeplacement(j, i, j+k, i-k, 1);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i+k)<8)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i+k)){
										doubledeplacement(j, i, j-k, i+k, 1);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i-k)){
										doubledeplacement(j, i, j-k, i-k, 1);
									}
									else{
										k=8;
									}
								}
							}
						case 'D':
							for(k=1; k<8; k++){
								if((i+k)<8){
									if(mouvementsPossibles(j, i, j, i+k)){
										doubledeplacement(j, i, j, i+k, 1);
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((i-k)>=0){
									if(mouvementsPossibles(j, i, j, i-k)){
										doubledeplacement(j, i, j, i-k, 1);
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((j+k)<8){
									if(mouvementsPossibles(j, i, j+k, i)){
										doubledeplacement(j, i, j+k, i, 1);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<8; k++){
								if((j-k)>=0){
									if(mouvementsPossibles(j, i, j-k, i)){
										doubledeplacement(j, i, j-k, i, 1);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<8; k++){
								if(((i+k)<8)&&((j+k)<8))
								{
									if(mouvementsPossibles(j, i, j+k, i+k)){
										doubledeplacement(j, i, j+k, i+k, 1);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j+k)<8)){
									if(mouvementsPossibles(j, i, j+k, i-k)){
										doubledeplacement(j, i, j+k, i-k, 1);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i+k)<8)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i+k)){
										doubledeplacement(j, i, j-k, i+k, 1);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i-k)){
										doubledeplacement(j, i, j-k, i-k, 1);
									}
									else{
										k=8;
									}
								}
							}
							break;
						case 'R':

							if(mouvementsPossibles(j, i, j-1, i)){
								doubledeplacement(j, i, j-1, i, 1);
							}

							if(mouvementsPossibles(j, i, j+1, i)){
								doubledeplacement(j, i, j+1, i, 1);
							}

							if(mouvementsPossibles(j, i, j, i+1)){
								doubledeplacement(j, i, j, i+1, 1);
							}

							if(mouvementsPossibles(j, i, j, i-1)){
								doubledeplacement(j, i, j, i-1, 1);
							}

							if(mouvementsPossibles(j, i, j-1, i-1)){
								doubledeplacement(j, i, j-1, i-1, 1);
							}


							if(mouvementsPossibles(j, i, j+1, i-1)){
								doubledeplacement(j, i, j+1, i-1, 1);
							}

							if(mouvementsPossibles(j, i, j-1, i+1)){
								doubledeplacement(j, i, j-1, i+1, 1);
							}

							if(mouvementsPossibles(j, i, j+1, i+1)){
								doubledeplacement(j, i, j+1, i+1, 1);
							}
							break;
					}/* fin du switch */
				}/* fin du if */
			}/* fin du if */
		}/* fin du for */
	}/* fin du if */
	/* Si le tour = noir, le roi blanc est en echec */
	else if((!ifnoir())&&(checkRoi()==2)){
		for(i=0; i<8; i++)
		{
			for(j=0; j<8; j++)
			{
				if(plateau[i][j]!=' ')
				{
					coupSuivant = plateau[i][j];
					switch(plateau[i][j])
					{
						case 'i':
							if(mouvementsPossibles(j, i, j+1, i-1)){
								doubledeplacement(j, i, j+1, i-1, 2);
							}
							if(mouvementsPossibles(j, i, j-1, i-1)){
								doubledeplacement(j, i, j-1, i-1, 2);
							}

							break;
						case 't':
							for(k=1; k<8; k++){
								if((i+k)<8){
									if(mouvementsPossibles(j, i, j, i+k)){
										doubledeplacement(j, i, j, i+k, 2);
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((i-k)>=0){
									if(mouvementsPossibles(j, i, j, i-k)){
										doubledeplacement(j, i, j, i-k, 2);
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((j+k)<8){
									if(mouvementsPossibles(j, i, j+k, i)){
										doubledeplacement(j, i, j+k, i, 2);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<8; k++){
								if((j-k)>=0){
									if(mouvementsPossibles(j, i, j-k, i)){
										doubledeplacement(j, i, j-k, i, 2);
									}
									else{
										k=8;
									}
								}
							}
							break;
						case 'c':
							if(mouvementsPossibles(j, i, j-2, i+1)){
								doubledeplacement(j, i, j-2, i+1, 2);
							}

							if(mouvementsPossibles(j, i, j-1, i+2)){
								doubledeplacement(j, i, j-1, i+2, 2);
							}

							if(mouvementsPossibles(j, i, j+1, i+2)){
								doubledeplacement(j, i, j+1, i+2, 2);
							}

							if(mouvementsPossibles(j, i, j+2, i+1)){
								doubledeplacement(j, i, j+2, i+1, 2);
							}

							if(mouvementsPossibles(j, i, j+2, i-1)){
								doubledeplacement(j, i, j+2, i-1, 2);
							}

							if(mouvementsPossibles(j, i, j+1, i-2)){
								doubledeplacement(j, i, j+1, i-2, 2);
							}


							if(mouvementsPossibles(j, i, j-1, i-2)){
								doubledeplacement(j, i, j-1, i-2, 2);
							}

							if(mouvementsPossibles(j, i, j-2, i-1)){
								doubledeplacement(j, i, j-2, i-1, 2);
							}

							break;

						case 'f':
							for(k=1; k<8; k++){
								if(((i+k)<8)&&((j+k)<8))
								{
									if(mouvementsPossibles(j, i, j+k, i+k)){
										doubledeplacement(j, i, j+k, i+k, 2);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j+k)<8)){
									if(mouvementsPossibles(j, i, j+k, i-k)){
										doubledeplacement(j, i, j+k, i-k, 2);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i+k)<8)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i+k)){
										doubledeplacement(j, i, j-k, i+k, 2);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i-k)){
										doubledeplacement(j, i, j-k, i-k, 2);
									}
									else{
										k=8;
									}
								}
							}

							break;
						case 'd':
							for(k=1; k<8; k++){
								if((i+k)<8){
									if(mouvementsPossibles(j, i, j, i+k)){
										doubledeplacement(j, i, j, i+k, 2);
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((i-k)>=0){
									if(mouvementsPossibles(j, i, j, i-k)){
										doubledeplacement(j, i, j, i-k, 2);
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((j+k)<8){
									if(mouvementsPossibles(j, i, j+k, i)){
										doubledeplacement(j, i, j+k, i, 2);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<8; k++){
								if((j-k)>=0){
									if(mouvementsPossibles(j, i, j-k, i)){
										doubledeplacement(j, i, j-k, i, 2);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<8; k++){
								if(((i+k)<8)&&((j+k)<8))
								{
									if(mouvementsPossibles(j, i, j+k, i+k)){
										doubledeplacement(j, i, j+k, i+k, 2);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j+k)<8)){
									if(mouvementsPossibles(j, i, j+k, i-k)){
										doubledeplacement(j, i, j+k, i-k, 2);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i+k)<8)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i+k)){
										doubledeplacement(j, i, j-k, i+k, 2);
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i-k)){
										doubledeplacement(j, i, j-k, i-k, 2);
									}
									else{
										k=8;
									}
								}
							}

							break;
						case 'r':

							if(mouvementsPossibles(j, i, j-1, i)){
								doubledeplacement(j, i, j-1, i, 2);
							}

							if(mouvementsPossibles(j, i, j+1, i)){
								doubledeplacement(j, i, j+1, i, 2);
							}

							if(mouvementsPossibles(j, i, j, i+1)){
								doubledeplacement(j, i, j, i+1, 2);
							}

							if(mouvementsPossibles(j, i, j, i-1)){
								doubledeplacement(j, i, j, i-1, 2);
							}

							if(mouvementsPossibles(j, i, j-1, i-1)){
								doubledeplacement(j, i, j-1, i-1, 2);
							}


							if(mouvementsPossibles(j, i, j+1, i-1)){
								doubledeplacement(j, i, j+1, i-1, 2);
							}

							if(mouvementsPossibles(j, i, j-1, i+1)){
								doubledeplacement(j, i, j-1, i+1, 2);
							}

							if(mouvementsPossibles(j, i, j+1, i+1)){
								doubledeplacement(j, i, j+1, i+1, 2);
							}

							break;


					}/* fin du switch */
				}/* fin du if */
			}/* fin du for */
		}/* fin du for */
	}/* fin du else */
	coupSuivant = ValeurCoupSuivant;
    return ifcheckmat;
}/*==FinFonction checkmat()==*/

/*==Fonction partieNull==*/
/* ==Le roi n'est pas en échec== */
/* ==Mais tous les mouvements du roi peut produire une menace== */
/* ==Et il n'y a pas de possibilité de déplacer d'autre pièce== */
int partieNull()
{
	/* Le technique : */
	/* Parcourir tous les cases */
	/* Si il comprend une pièce : vérifier si il y a des mouvements possibles pour cette pièce, si il exite au moins un mouvement possible => partieNull = false */
	/* Si il comprend un roi : tous les mouvements possibles peut NE PAS causer une menance => partieNull = false*/
    int i, j, k;
	int null=1;
	char ValeurCoupSuivant;
	ValeurCoupSuivant = coupSuivant;
	
	if((ifnoir())&&(checkRoi()!=1)){
		for(i=0; i<8; i++)
		{
			for(j=0; j<8; j++)
			{
				if(plateau[i][j]!=' ')
				{
					coupSuivant = plateau[i][j];
					switch(plateau[i][j])
					{
						case 'P':
							if(mouvementsPossibles(j, i, j+1, i+1)){
								null = 0;
							}
							if(mouvementsPossibles(j, i, j-1, i+1)){
								null = 0;
							}
							
							if(mouvementsPossibles(j, i, j, i+1)){
								null = 0;
							}

							break;
						case 'T':
							for(k=1; k<8; k++){
								if((i+k)<8){
									if(mouvementsPossibles(j, i, j, i+k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((i-k)>=0){
									if(mouvementsPossibles(j, i, j, i-k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((j+k)<8){
									if(mouvementsPossibles(j, i, j+k, i)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<8; k++){
								if((j-k)>=0){
									if(mouvementsPossibles(j, i, j-k, i)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}
							break;
						case 'C':
							if(mouvementsPossibles(j, i, j-2, i+1)){
								null = 0;
							}

							if(mouvementsPossibles(j, i, j-1, i+2)){
								null = 0;
							}

							if(mouvementsPossibles(j, i, j+1, i+2)){
								null = 0;
							}

							if(mouvementsPossibles(j, i, j+2, i+1)){
								null = 0;
							}

							if(mouvementsPossibles(j, i, j+2, i-1)){
								null = 0;
							}

							if(mouvementsPossibles(j, i, j+1, i-2)){
								null = 0;
							}


							if(mouvementsPossibles(j, i, j-1, i-2)){
								null = 0;
							}

							if(mouvementsPossibles(j, i, j-2, i-1)){
								null = 0;
							}

							break;

						case 'F':
							for(k=1; k<8; k++){
								if(((i+k)<8)&&((j+k)<8))
								{
									if(mouvementsPossibles(j, i, j+k, i+k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j+k)<8)){
									if(mouvementsPossibles(j, i, j+k, i-k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i+k)<8)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i+k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i-k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							break;
						case 'D':
							for(k=1; k<8; k++){
								if((i+k)<8){
									if(mouvementsPossibles(j, i, j, i+k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((i-k)>=0){
									if(mouvementsPossibles(j, i, j, i-k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((j+k)<8){
									if(mouvementsPossibles(j, i, j+k, i)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<8; k++){
								if((j-k)>=0){
									if(mouvementsPossibles(j, i, j-k, i)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<8; k++){
								if(((i+k)<8)&&((j+k)<8))
								{
									if(mouvementsPossibles(j, i, j+k, i+k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j+k)<8)){
									if(mouvementsPossibles(j, i, j+k, i-k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i+k)<8)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i+k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i-k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							break;
						case 'R':

							if(mouvementsPossibles(j, i, j-1, i)){
								doubledeplacementRoi(j, i, j-1, i, 1);
							}

							if(mouvementsPossibles(j, i, j+1, i)){
                                doubledeplacementRoi(j, i, j+1, i, 1);
							}

							if(mouvementsPossibles(j, i, j, i+1)){
								doubledeplacementRoi(j, i, j, i+1, 1);
							}

							if(mouvementsPossibles(j, i, j, i-1)){
								doubledeplacementRoi(j, i, j, i-1, 1);
							}

							if(mouvementsPossibles(j, i, j-1, i-1)){
								doubledeplacementRoi(j, i, j-1, i-1, 1);
							}


							if(mouvementsPossibles(j, i, j+1, i-1)){
								doubledeplacementRoi(j, i, j+1, i-1, 1);
							}

							if(mouvementsPossibles(j, i, j-1, i+1)){
								doubledeplacementRoi(j, i, j-1, i+1, 1);
							}

							if(mouvementsPossibles(j, i, j+1, i+1)){
								doubledeplacementRoi(j, i, j+1, i+1, 1);
							}
							break;
					}/* fin du switch */
				}/* fin du if */
			}/* fin du for */
		}/* fin du for */
	}/* fin du if */

	else if((!ifnoir())&&(checkRoi()!=2))
	{
		for(i=0; i<8; i++)
		{
			for(j=0; j<8; j++)
			{
				if(plateau[i][j]!=' ')
				{
					coupSuivant = plateau[i][j];
					switch(plateau[i][j])
					{
						case 'i':
							if(mouvementsPossibles(j, i, j+1, i-1)){
								null = 0;
							}
							if(mouvementsPossibles(j, i, j-1, i-1)){
								null = 0;
							}
							
							if(mouvementsPossibles(j, i, j, i-1)){
								null = 0;
							}

							break;
						case 't':
							for(k=1; k<8; k++){
								if((i+k)<8){
									if(mouvementsPossibles(j, i, j, i+k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((i-k)>=0){
									if(mouvementsPossibles(j, i, j, i-k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((j+k)<8){
									if(mouvementsPossibles(j, i, j+k, i)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<8; k++){
								if((j-k)>=0){
									if(mouvementsPossibles(j, i, j-k, i)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}
							break;
						case 'k':
							if(mouvementsPossibles(j, i, j-2, i+1)){
								null = 0;
							}

							if(mouvementsPossibles(j, i, j-1, i+2)){
								null = 0;
							}

							if(mouvementsPossibles(j, i, j+1, i+2)){
								null = 0;
							}

							if(mouvementsPossibles(j, i, j+2, i+1)){
								null = 0;
							}

							if(mouvementsPossibles(j, i, j+2, i-1)){
								null = 0;
							}

							if(mouvementsPossibles(j, i, j+1, i-2)){
								null = 0;
							}


							if(mouvementsPossibles(j, i, j-1, i-2)){
								null = 0;
							}

							if(mouvementsPossibles(j, i, j-2, i-1)){
								null = 0;
							}

							break;

						case 'f':
							for(k=1; k<8; k++){
								if(((i+k)<8)&&((j+k)<8))
								{
									if(mouvementsPossibles(j, i, j+k, i+k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j+k)<8)){
									if(mouvementsPossibles(j, i, j+k, i-k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i+k)<8)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i+k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i-k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							break;
						case 'd':
							for(k=1; k<8; k++){
								if((i+k)<8){
									if(mouvementsPossibles(j, i, j, i+k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((i-k)>=0){
									if(mouvementsPossibles(j, i, j, i-k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}
							for(k=1; k<8; k++){
								if((j+k)<8){
									if(mouvementsPossibles(j, i, j+k, i)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<8; k++){
								if((j-k)>=0){
									if(mouvementsPossibles(j, i, j-k, i)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<8; k++){
								if(((i+k)<8)&&((j+k)<8))
								{
									if(mouvementsPossibles(j, i, j+k, i+k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j+k)<8)){
									if(mouvementsPossibles(j, i, j+k, i-k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i+k)<8)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i+k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							for(k=1; k<=8; k++){
								if(((i-k)>=0)&&((j-k)>=0)){
									if(mouvementsPossibles(j, i, j-k, i-k)){
										null = 0;
									}
									else{
										k=8;
									}
								}
							}

							break;
						case 'r':

							if(mouvementsPossibles(j, i, j-1, i)){
								doubledeplacementRoi(j, i, j-1, i, 2);
							}

							if(mouvementsPossibles(j, i, j+1, i)){
								doubledeplacementRoi(j, i, j+1, i, 2);
							}

							if(mouvementsPossibles(j, i, j, i+1)){
								doubledeplacementRoi(j, i, j, i+1, 2);
							}

							if(mouvementsPossibles(j, i, j, i-1)){
								doubledeplacementRoi(j, i, j, i-1, 2);
							}

							if(mouvementsPossibles(j, i, j-1, i-1)){
								doubledeplacementRoi(j, i, j-1, i-1, 2);
							}


							if(mouvementsPossibles(j, i, j+1, i-1)){
								doubledeplacementRoi(j, i, j+1, i-1, 2);
							}

							if(mouvementsPossibles(j, i, j-1, i+1)){
								doubledeplacementRoi(j, i, j-1, i+1, 2);
							}

							if(mouvementsPossibles(j, i, j+1, i+1)){
								doubledeplacementRoi(j, i, j+1, i+1, 2);
							}
							break;
					}/* fin du switch */
				}/* fin du if */
			}/* fin du for */
		}/* fin du for */
	}/* fin du else */
	coupSuivant = ValeurCoupSuivant;
	return null;
}/*==FinFonction partieNull==*/
/* ============================================================================= */


/* ===========PROCEDURES POUR NOUVELLE PARTIE============ */
/* ==Procedure pour initialiser le plateau avec les pieces== */
void initialisation()
{
	int i, j;

	for(i=0; i<8; i++){
		switch(i){
		case 0:
			for(j=0;j<8; j++){
				switch(j){
				case 0:case 7: plateau[i][j] = 'T'; break;
				case 1:case 6: plateau[i][j] = 'C'; break;
				case 2:case 5: plateau[i][j] = 'F'; break;
				case 3: plateau[i][j] = 'D'; break;
				case 4: plateau[i][j] = 'R'; break;
				}
			}
			break;
		case 1:
			for(j=0;j<8; j++){
				plateau[i][j] = 'P';
			}
			break;
		case 6:
			for(j=0;j<8; j++){
				plateau[i][j] = 'i';
			}
			break;
		case 7:
			for(j=0;j<8; j++){
				switch(j){
				case 0:case 7: plateau[i][j] = 't'; break;
				case 1:case 6: plateau[i][j] = 'k'; break;
				case 2:case 5: plateau[i][j] = 'f'; break;
				case 3: plateau[i][j] = 'd'; break;
				case 4: plateau[i][j] = 'r'; break;
				}
			}
			break;
		default:
			for(j=0; j<8; j++){
				plateau[i][j] = ' ';
			}
			break;
		}/* fin du switch */
	}/* fin du for */
}/* ==Procedure - initialisation== */


/* ==Procedure pour deplacer la piece==*/
void mouvement()
{
	/* Si la piece a des mouvements autorises a ce niveau-la. Si non, reboucler a « coupSuivant » */
	int ligneD, ligneA, trouve=0;
	char colonneD, colonneA;
	char valeurInit;

	/* Premier boucle */
	while(!trouve)
	{
	    /* Demander a l'utilisateur de saisir la case depart */
		printf(" Case depart (ex: a1): ");
		while((bidon=getchar())!='\n');
		scanf("%c%d", &colonneD, &ligneD);

        /* Verifier si l'utilisateur a bien saisi la case*/
		if(verificationEntree(colonneD, ligneD)==1)
		{

			c1 = conv_colonne_ChartoInt(colonneD);
			l1 = ligneD-1;
            /* Verifier si la piece dans la case depart conforme a la piece saisie dans (CoupSuivant)*/
			trouve = checkPiece(c1, l1);

			/* Message d'erreur si la piece saisie ne conforme pas a la piece dans CoupSuivant */
			if(!trouve)
			{
				printf(" Il n'y a pas de %c en %c%d.\n", coupSuivant, colonneD, ligneD);
			}
		}

		/* Message d'erreur si l'utilisateur a mal saisi la case */
		else
		{
			printf(" Erreur de saisie.\n");
		}
	} /* fin du while */ /* Fin Premier boucle */

    /* Demander a l'utilisateur de saisir la case arrivee */
	printf(" Case d'arrivee (ex: a4): ");
	while((bidon=getchar())!='\n');
	scanf("%c%d", &colonneA, &ligneA);

	 /* Verifier si l'utilisateur a bien saisi la case*/
	if(verificationEntree(colonneA, ligneA)==1)
	{
		c2 = conv_colonne_ChartoInt(colonneA);
		l2 = ligneA-1;

		 /* Verifier si c'est possible de deplarcer la piece vers la case d'arrivee*/
		if(mouvementsPossibles(c1, l1, c2, l2))
		{
		     /* Si oui, appeler la precedure de deplacement*/
			valeurInit = plateau[l2][c2];
			departToArrivee(c1, l1, c2, l2);

			printf(" Deplacement de %c de %c%d en %c%d\n", coupSuivant, colonneD, ligneD, colonneA, ligneA);

			/* Condition si le pion (i et P) atteint la ligne la plus eloignee de sa position*/
            if(((coupSuivant=='i')||(coupSuivant=='P'))&&(finLigne_pion(l2)))
            {
                printf(" Le pion atteint la ligne la plus eloignee de sa position. \n");
                if(ifnoir())
                {
                    while((coupSuivant!='d')&&(coupSuivant!='f')&&(coupSuivant!='k')&&(coupSuivant!='t')){
                        printf(" Choisissez (reine(d), fou(f), cavalier(k), ou tour (t)): ");
                        while((bidon=getchar())!='\n');
                        scanf("%c", &coupSuivant);
                    }
                    plateau[l2][c2] = coupSuivant;
                }
                else
                {
                    while((coupSuivant!='D')&&(coupSuivant!='F')&&(coupSuivant!='C')&&(coupSuivant!='T')){
                        printf(" Choisissez (reine(D), fou(F), cavalier(C), ou tour (T)): ");
                        while((bidon=getchar())!='\n');
                        scanf("%c", &coupSuivant);
                    }
                    plateau[l2][c2] = coupSuivant;
                }
            } /* Fin condition finLigne_pion*/

			/* Si le tour = blanc, le roi blanc est en échce après le mouvement */
			/* Afficher un messager d'erreur, remettre le mouvement*/
			if(!ifnoir()&&(checkRoi()==1)){
			    printf(" Attention, le roi blanc est en echec!\n");
                departToArrivee(c2, l2, c1, l1);
				plateau[l2][c2] = valeurInit;
			}
			/* Idem pour le tour = noir */
			else if(ifnoir()&&(checkRoi()==2)){
			    printf(" Attention, le roi noir est en echec!\n");
                departToArrivee(c2, l2, c1, l1);
				plateau[l2][c2] = valeurInit;
			}
			/* Sinon */
            else
            {
				/* Si le tour = blanc, le roi NOIR est en échce après le mouvement */
				/* Si le tour = noir, le roi BLANC est en échce après le mouvement */
				if((ifnoir()&&(checkRoi()==1))||(!ifnoir()&&(checkRoi()==2))){
					/* Vérifier si le roi est en echec et mat */
					if(checkmat()){
						printf(" Echec et mat !!!\n");
						printf(" Le %s a gagne !!!\n", tour);
						a_sauvegarder = 0;
						coupSuivant = 'q';
					}
					else
					{
						/* Pour savoir si l'utilisateur a déjà déplacer le roi et les tours */
						/* Utiliser dans le procédure roq() */
						switch(coupSuivant)
						{
							case 'R' : cptR = 1; break;
							case 'r' : cptr = 1; break;
							case 'T' :
								if((c1==7)&&(l1==0)){
									cptt1=1;
								}
								else if((c1==0)&&(l1==0)){
									cptt2=1;
								}
								break;
							case 't' :
								if((c1==7)&&(l1==7)){
									cptt1=1;
								}
								else if((c1==0)&&(l1==7)){
									cptt2=1;
								}
								break;
						}

						coupJeu++;
						a_sauvegarder = 1;
					}
				}/* fin du if */
				else
				{
					/* Si les rois ne sont pas en echec */
					if(partieNull()){
						printf(" Partie nulle !!!\n");
						a_sauvegarder = 0;
						coupSuivant = 'q';
					}/* fin du if */
					else{
						switch(coupSuivant)
						{
							case 'R' : cptR = 1; break;
							case 'r' : cptr = 1; break;
							case 'T' :
								if((c1==7)&&(l1==0)){
									cptt1=1;
								}
								else if((c1==0)&&(l1==0)){
									cptt2=1;
									}
								break;
								case 't' :
								if((c1==7)&&(l1==7)){
									cptt1=1;
								}
								else if((c1==0)&&(l1==7)){
										cptt2=1;
								}
								break;
						}
						coupJeu++;
						a_sauvegarder = 1;
					}/* fin du else */
				}/* fin du else */
			}/* fin du switch */
		}/* fin du if */
		/*Message d'erreur si ce n'est pas possible*/
		else
		{
			printf(" Mouvement impossible.\n");
		}
	}/* fin du if */
	/* Message d'erreur si l'utilisateur a mal saisi la case */
	else
	{
		printf(" Erreur de saisie.\n");
	}
}
/* ==FinProcedure - Mouvement == */

/* == Procedure pour deplacer la piece de case depart a case d'arrivee== */
void departToArrivee(int paramcd, int paramld, int paramca, int paramla)
{
	plateau[paramld][paramcd]=' ';
	plateau[paramla][paramca]=coupSuivant;
}/* ==FinProcedure - departToArrivee== */

/* == Procedure pour vérifier la possibilité de roq et effectuer un roq== */
void roq()
{
	/* Vérifier si les cases entre les tours et le roi sont vides ou pas */
	/* Vérifier si jamais l'utilisateur a bougé le roi ou les tours */
	/* Si il est possible d'effectuer un roq avec tour à droit et à gauche */
	/* Demander d'abord si l'utilisateur veut faire un roq droit */
	/* Si la reponse = Non, demander ensuite roq gauche */
	char reponse;
	ifroq = 0;
	if(ifnoir())
	{
		if((plateau[7][6]==' ')&&(plateau[7][5]==' ')&&(!cptr)&&(!cptt1))
        {
            while((reponse!='o')&&(reponse!='n'))
			{
				printf(" Voulez vous faire un roq droit (o/n): ");
				while((bidon=getchar())!='\n');
				scanf("%c", &reponse);
				reponse = tolower(reponse);
				if(reponse=='o')
				{
					plateau[7][7] = ' ';
					plateau[7][6] = 'r';
					plateau[7][5] = 't';
					plateau[7][4] = ' ';
					ifroq = 1;
					cptr=1;

					if(checkRoi()==2){
						printf(" Attention, le roi noir est en echec!\n");
						plateau[7][7] = ' ';
						plateau[7][6] = 'r';
						plateau[7][5] = 't';
						plateau[7][4] = ' ';
						ifroq = 0;
						cptr=0;
					}/* fin du if */

				}/* fin du if */
				else
				{
					if((plateau[7][3]==' ')&&(plateau[7][2]==' ')&&(plateau[7][1]==' ')&&(!cptr)&&(!cptt2))
					{
						reponse = 'A';
						while((reponse!='o')&&(reponse!='n'))
						{
							printf(" Voulez vous faire un roq gauche (o/n) : ");
							while((bidon=getchar())!='\n');
							scanf("%c", &reponse);
							reponse = tolower(reponse);
							if(reponse=='o')
							{
								plateau[7][4]= ' ';
								plateau[7][3]= 't';
								plateau[7][2]= 'r';
								plateau[7][0]= ' ';
								ifroq = 1;
								cptr=1;

								if(checkRoi()==2){
									printf(" Attention, le roi noir est en echec!\n");
									plateau[7][4]= ' ';
									plateau[7][3]= 't';
									plateau[7][2]= 'r';
									plateau[7][0]= ' ';
									ifroq = 0;
									cptr=0;
								}/* fin du if */
							}/* fin du if */
						}/* fin du while */
					}/* fin du if */
				}/* fin du else */
			}/* fin du while */
		}/* fin du if */
		else if((plateau[7][3]==' ')&&(plateau[7][2]==' ')&&(plateau[7][1]==' ')&&(!cptr)&&(!cptt2))
		{
			while((reponse!='o')&&(reponse!='n'))
			{
				printf(" Voulez vous faire un roq gauche (o/n) : ");
				while((bidon=getchar())!='\n');
				scanf("%c", &reponse);
				reponse = tolower(reponse);
				if(reponse=='o')
				{
					plateau[7][4]= ' ';
					plateau[7][3]= 't';
					plateau[7][2]= 'r';
					plateau[7][0]= ' ';
					ifroq = 1;
					cptR=1;

					if(checkRoi()==2){
						printf(" Attention, le roi noir est en echec!\n");
						plateau[7][4]= ' ';
						plateau[7][3]= 't';
						plateau[7][2]= 'r';
						plateau[7][0]= ' ';
						ifroq = 0;
						cptR=0;
					}/* fin du if */
				}/* fin du if */
			}/* fin du while */
		}/* fin du else if */
	}/* fin du if */
	else{
		if((plateau[0][6]==' ')&&(plateau[0][5]==' ')&&(!cptR)&&(!cptT2))
		{
			while((reponse!='o')&&(reponse!='n'))
			{
                printf(" Voulez vous faire un roq droit (o/n) : ");
                while((bidon=getchar())!='\n');
                scanf("%c", &reponse);
                reponse = tolower(reponse);
                if(reponse=='o')
                {
                    plateau[0][7] = ' ';
                    plateau[0][6] = 'R';
                    plateau[0][5] = 'T';
                    plateau[0][4] = ' ';
					ifroq = 1;
					cptR=1;

					if(checkRoi()==1){
						printf(" Attention, le roi blanc est en echec!\n");
						plateau[0][7] = ' ';
						plateau[0][6] = 'R';
						plateau[0][5] = 'T';
						plateau[0][4] = ' ';
						ifroq = 0;
						cptR=0;
					}/* fin du if */
                }/* fin du if */
				else
				{
					if((plateau[0][1]==' ')&&(plateau[0][2]==' ')&&(plateau[0][3]==' ')&&(!cptR)&&(!cptT1))
					{
						reponse = 'A';
						while((reponse!='o')&&(reponse!='n'))
						{
							printf(" Voulez vous faire un roq gauche (o/n) : ");
							while((bidon=getchar())!='\n');
							scanf("%c", &reponse);
							reponse = tolower(reponse);
							if(reponse=='o')
							{
								plateau[0][4]= ' ';
								plateau[0][3]= 'T';
								plateau[0][2]= 'R';
								plateau[0][0]= ' ';
								ifroq = 1;
								cptR=1;

								if(checkRoi()==1){
									printf(" Attention, le roi blanc est en echec!\n");
									plateau[0][4]= ' ';
									plateau[0][3]= 'T';
									plateau[0][2]= 'R';
									plateau[0][0]= ' ';
									ifroq = 0;
									cptR=0;
								}/* fin du if */
							}/* fin du if */
						}/* fin du while */
					}/* fin du if */
				}/* fin du else */
            }/* fin du while */
        }/* fin du if */
		else if((plateau[0][1]==' ')&&(plateau[0][2]==' ')&&(plateau[0][3]==' ')&&(!cptR)&&(!cptT1))
		{
			while((reponse!='o')&&(reponse!='n'))
			{
                printf(" Voulez vous faire un roq (o/n) gauche: ");
                while((bidon=getchar())!='\n');
                scanf("%c", &reponse);
                reponse = tolower(reponse);
                if(reponse=='o')
                {
                    plateau[0][4]= ' ';
					plateau[0][3]= 'T';
					plateau[0][2]= 'R';
					plateau[0][0]= ' ';
					ifroq = 1;
					cptR=1;

					if(checkRoi()==1){
						printf(" Attention, le roi blanc est en echec!\n");
						plateau[0][4]= ' ';
						plateau[0][3]= 'T';
						plateau[0][2]= 'R';
						plateau[0][0]= ' ';
						ifroq = 0;
						cptR=0;
					}/* fin du if */
                }/* fin du if */
            }/* fin du while */
		}/* fin du else if */
	}/* fin du else */
}/* == FInProcedure roq== */

/* == Procedure utilisée dans CheckRoi== */
/* == déplacer la pièce, vérifier si le roi n'est plus en echec après le déplacement == */
/* == Si oui, ifcheckmat = False == */
/* == Redéplacer la pièce vers la case d'origine == */
void doubledeplacement(int paramcd, int paramld, int paramca, int paramla, int paramCheckRoi)
{
    char valeurOrigine;
	valeurOrigine = plateau[paramla][paramca];
	departToArrivee(paramcd, paramld, paramca, paramla);
	if(checkRoi()!=paramCheckRoi)
	{
		ifcheckmat=0;
	}
	departToArrivee(paramca, paramla, paramcd, paramld);
	plateau[paramla][paramca] = valeurOrigine;
}
/* == FinProcedure doubledeplacement== */

/* == Procedure utilisée dans partieNull== */
/* == Même technique que doubledeplacement== */
/* == Mais il vérifiee si le roi est en echec ou pas après le déplacement == */
void doubledeplacementRoi(int paramcd, int paramld, int paramca, int paramla, int paramCheckRoi)
{
    char valeurOrigine;
	valeurOrigine = plateau[paramla][paramca];
	departToArrivee(paramcd, paramld, paramca, paramla);
	if(checkRoi()==paramCheckRoi)
	{
		null=0;
	}
	departToArrivee(paramca, paramla, paramcd, paramld);
	plateau[paramla][paramca] = valeurOrigine;
}/* == FinProcedure doubledeplacement== */
/* ============================================================================= */

/* ===========FONCTION VERIFICATION MOUVEMENT============ */

/* ==Fonction pour vérififer le mouvement possible de piece entrée== */
/* ==En utilisant la fonction verifoccupe()== */
int mouvementsPossibles(int paramcd, int paramld, int paramca, int paramla)
{
	int possible = 0;
	switch(coupSuivant)
	{
	    case 'P':
			if(paramld==1)
			{
				if((paramla==paramld+1)&&(paramca==paramcd))
				{
					if(verifoccupe(paramla, paramca)==1)
                        possible = 1;
				}
				else if((paramla==paramld+1)&&((paramca==paramcd-1)||(paramca==paramcd+1)))
				{
					if(verifoccupe(paramla, paramca)==5)
                        possible = 1;
				}
				else if((paramla==paramld+2)&&(paramca==paramcd))
				{
					if(verifoccupe(paramld+1, paramca)==1)
					{
						if(verifoccupe(paramla, paramca)==1)
                            possible = 1;
					}
				}
			}/* fin du if */
			else
			{
				if((paramla==paramld+1)&&(paramca==paramcd))
				{
					if(verifoccupe(paramla, paramca)==1)
                        possible = 1;
				}
				else if((paramla==paramld+1)&&((paramca==paramcd-1)||(paramca==paramcd+1)))
				{
					if(verifoccupe(paramla, paramca)==5)
                        possible = 1;
				}

			}/* fin du else */
			break;
		case 'i':
			if(paramld==6)
                {
				if((paramla==paramld-1)&&(paramca==paramcd))
				{
					if(verifoccupe(paramla, paramca)==1)
                        possible = 1;
				}
				else if((paramla==paramld-1)&&((paramca==paramcd-1)||(paramca==paramcd+1)))
				{
					if(verifoccupe(paramla, paramca)==3)
                        possible = 1;
				}
				else if((paramla==paramld-2)&&(paramca==paramcd))
				{
					if(verifoccupe(paramld-1, paramca)==1)
					{
						if(verifoccupe(paramla, paramca)==1)
                        possible = 1;
					}
				}
			}/* fin du if */
			else{
				if((paramla==paramld-1)&&(paramca==paramcd))
				{
					if(verifoccupe(paramla, paramca)==1)
                        possible = 1;
				}
				else if((paramla==paramld-1)&&((paramca==paramcd-1)||(paramca==paramcd+1)))
				{
					if(verifoccupe(paramla, paramca)==3)
                        possible = 1;
				}
			}/* fin du else */
			break;

		case 'T':
		    possible = deplacementHorVer(paramcd, paramld, paramca, paramla);
			break;
        case 't':
		    possible = deplacementHorVer(paramcd, paramld, paramca, paramla);
			break;

		case 'C': case 'k':
            possible = deplacementCavalier(paramcd, paramld, paramca, paramla);
		    break;

		case 'F': case 'f':
            /*Ligne +/- 1...7  et  Colonne +/- 1...7*/
            possible =  deplacementDiagonale(paramcd, paramld, paramca, paramla);
		    break;

		case 'D':  case 'd':
		    /* Verifier le mouvement horizon et vertical*/
		    if(deplacementHorVer(paramcd, paramld, paramca, paramla))
				possible =1;
			else if(deplacementDiagonale(paramcd, paramld, paramca, paramla))
				possible =1;
		    break;

		case 'R': case 'r':
		    if((paramla==paramld)&&((paramca==paramcd+1)||(paramca==paramcd-1)))
            {
                switch(verifoccupe(paramla, paramca))
                {
                    case 1: possible=1; break;
                    case 3:
                        if(ifnoir()){possible = 1; }
                        break;
                    case 5:
                        if(!ifnoir()){possible = 1; }
                        break;
                    default: possible = 0;
                }
            }/* fin du if */
            else if((paramla==paramld+1)&&((paramca==paramcd+1)||(paramca==paramcd-1)||(paramca==paramcd)))
            {
                switch(verifoccupe(paramla, paramca))
                {
                    case 1: possible=1; break;
                    case 3:
                        if(ifnoir()){possible = 1; }
                        break;
                    case 5:
                        if(!ifnoir()){possible = 1; }
                        break;
                    default: possible = 0;
                }

            }/* fin du else */
            else if((paramla==paramld-1)&&((paramca==paramcd+1)||(paramca==paramcd-1)||(paramca==paramcd)))
            {
                switch(verifoccupe(paramla, paramca))
                {
                    case 1: possible=1; break;
                    case 3:
                        if(ifnoir()){possible = 1; }
                        break;
                    case 5:
                        if(!ifnoir()){possible = 1; }
                        break;
                    default: possible = 0;
                }
            }/* fin du else */

			break;
	}/* fin du switch */
	return possible;
}/* ==FinFonction - mouvementsPossibles== */

/* ==Fonction pour verifier les mouvements possibles de cavalier== */
int deplacementCavalier(int paramcd, int paramld, int paramca, int paramla){
    int possible = 0;
    if((paramca==paramcd-2)&&((paramla==paramld+1)||(paramla==paramld-1)))
    {
        switch(verifoccupe(paramla, paramca)){
            case 1: possible = 1; break;
            case 3:
                if(ifnoir()){
					possible =1;
				}
				break;
            case 5: if(!ifnoir()){
				possible =1;
				}
				break;
            }
    }/* fin du if */
    else if((paramca==paramcd+2)&&((paramla==paramld+1)||(paramla==paramld-1)))
    {
        switch(verifoccupe(paramla, paramca)){
            case 1: possible = 1; break;
            case 3:
                if(ifnoir()){
					possible =1;
				}
				break;
            case 5: if(!ifnoir()){
				possible =1;
				}
				break;
            }
    }/* fin du else if */
    else if((paramla==paramld-2)&&((paramca==paramcd+1)||(paramca==paramcd-1)))
    {
        switch(verifoccupe(paramla, paramca)){
            case 1: possible = 1; break;
            case 3:
                if(ifnoir()){
					possible =1;
				}
				break;
            case 5: if(!ifnoir()){
				possible =1;
				}
				break;
            }
    }/* fin du else if */
    else if((paramla==paramld+2)&&((paramca==paramcd+1)||(paramca==paramcd-1)))
    {
        switch(verifoccupe(paramla, paramca)){
            case 1:
				possible = 1;
				break;
            case 3:
                if(ifnoir()){
					possible =1;
				}
				break;
            case 5: if(!ifnoir()){
				possible =1;
				}
				break;
            }
    }/* fin du else if */

    return possible;
}/* ==Fonction - deplacementCavalier== */

/* ==Fonction pour verifier le deplacement hortizon et vertical == */
int deplacementHorVer(int paramcd, int paramld, int paramca, int paramla)
{
	int possible = 0;

	if(paramla==paramld)
	{
	    if(paramca>paramcd)
	    {
	        paramcd++;
            while(paramcd<=paramca)
            {
                switch(verifoccupe(paramla, paramcd))
                {
                    case 1:
						possible=1;
						paramcd++;
						break;
                    case 3:
                        if((ifnoir())&&(paramca==paramcd)){
							possible = 1;
							paramcd = paramca+1;
						}
                        else{
							possible = 0;
							paramcd = paramca+1;
						}
                        break;
                    case 5:
                        if((!ifnoir())&&(paramcd==paramca)){
							possible = 1;
							paramcd = paramca+1;
						}
                        else{
							possible = 0;
							paramcd = paramca+1;
						}
                        break;
                    default:
						possible = 0;
						paramcd = paramca+1;
						break;
                }/* fin du switch */
            }/* fin du while */
	    }/* fin du if */
	    else if(paramca<paramcd)
	    {
	        paramcd--;
            while(paramcd>=paramca)
            {
                switch(verifoccupe(paramla, paramcd))
                {
                    case 1:
						possible=1;
						paramcd--;
						break;
                    case 3:
                        if((ifnoir())&&(paramca==paramcd)){
							possible = 1;
							paramcd = paramca-1;
						}
                        else{
							possible = 0;
							paramcd = paramca-1;
						}
                        break;
                    case 5:
                        if((!ifnoir())&&(paramcd==paramca)){
							possible = 1;
							paramcd = paramca-1;
						}
                        else{
							possible = 0;
							paramcd = paramca-1;
						}
                        break;
                    default:
						possible = 0;
						paramcd = paramca-1;
						break;
                }/* fin du switch */
            }/* fin du while */
	    }/* fin du else */
	}/* fin du if */
	else if(paramcd==paramca)
	{
	    if(paramla>paramld)
	    {
	        paramld++;
            while(paramld<=paramla)
            {
                switch(verifoccupe(paramld, paramcd))
                {
                    case 1:
						possible=1;
						paramld++;
						break;
                    case 3:
                        if((ifnoir())&&(paramla==paramld)){
							possible = 1;
							paramld = paramla+1;
						}
                        else{
							possible = 0;
							paramld = paramla+1;
						}
                        break;
                    case 5:
                        if((!ifnoir())&&(paramld==paramla)){
							possible = 1;
							paramld = paramla+1;
						}
                        else{
							possible = 0;
							paramld = paramla+1;
						}
                        break;
                    default:
						possible = 0;
						paramld = paramla+1;
						break;
                }/* fin du switch */
            }/* fin du while */
	    }/* fin du if */
	    else if(paramla<paramld)
	    {
	        paramld--;
            while(paramld>=paramla)
            {
                switch(verifoccupe(paramld, paramcd))
                {
                    case 1:
						possible=1;
						paramld--;
						break;
                    case 3:
                        if((ifnoir())&&(paramla==paramld)){
							possible = 1;
							paramld = paramla-1;
						}
                        else{
							possible = 0;
							paramld = paramla-1;
						}
                        break;
                    case 5:
                        if((!ifnoir())&&(paramld==paramla)){
							possible = 1;
							paramld = paramla-1;
						}
                        else{
							possible = 0;
							paramld = paramla-1;
						}
                        break;
                    default:
						possible = 0;
						paramld = paramla-1;
						break;
                }/* fin du switch */
            }/* fin du while */
	    }/* fin du else if */
	}/* fin du else if */
    return possible;
}/* ==FinFonction - deplacementHorVer == */

/* ==Fonction pour verifier le deplacement diagonale== */
int deplacementDiagonale(int paramcd, int paramld, int paramca, int paramla)
{
	int possible = 0;
	if(paramla>paramld)
	{
	    paramld++;
	    if(paramca<paramcd)
	    {
	        paramcd--;
            while((paramld<=paramla)&&(paramcd>=paramca))
            {
                switch(verifoccupe(paramld, paramcd))
                {
                    case 1:
						possible=1;
						paramld++;
						paramcd--;
						break;
                    case 3:
                        if((ifnoir())&&(paramcd==paramca)){
							possible = 1;
							paramcd = paramca-1;
						}
                        else{
							possible = 0;
							paramcd = paramca-1;
						}
                        break;
                    case 5:
                        if((!ifnoir())&&(paramcd==paramca)){
							possible = 1;
							paramcd = paramca-1;
						}
                        else{
							possible = 0;
							paramcd = paramca-1;
						}
                        break;
                    default:
						possible = 0;
						paramcd = paramca-1;
						break;
                }/* fin du switch */
            }/* fin du while */
	    }/* fin du if */
	    else if(paramca>paramcd)
	    {
	        paramcd++;
            while((paramld<=paramla)&&(paramcd<=paramca))
            {
                switch(verifoccupe(paramld, paramcd))
                {
                    case 1:
						possible=1;
						paramld++;
						paramcd++;
						break;
                    case 3:
                        if((ifnoir())&&(paramcd==paramca)){
							possible = 1;
							paramcd = paramca+1;
						}
                        else{
							possible = 0;
							paramcd = paramca+1;
						}
                        break;
                    case 5:
                        if((!ifnoir())&&(paramcd==paramca)){
							possible = 1;
							paramcd = paramca+1;
						}
                        else{
							possible = 0;
							paramcd = paramca+1;
						}
                        break;
                    default:
						possible = 0;
						paramcd = paramca+1;
						break;
                }/* fin du switch */
            }/* fin du while */
	    }/* fin du else if */
	}/* fin du if */
	else if(paramla<paramld)
	{
	    paramld--;
	    if(paramca<paramcd)
	    {
	        paramcd--;
            while((paramld>=paramla)&&(paramcd>=paramca))
            {
                switch(verifoccupe(paramld, paramcd))
                {
                    case 1:
						possible=1;
						paramld--;
						paramcd--;
						break;
                    case 3:
                        if((ifnoir())&&(paramcd==paramca)){
							possible = 1;
							paramcd = paramca-1;
						}
                        else{
							possible = 0;
							paramcd = paramca-1;
						}
                        break;
                    case 5:
                        if((!ifnoir())&&(paramcd==paramca)){
							possible = 1;
							paramcd = paramca-1;
						}
                        else{
							possible = 0;
							paramcd = paramca-1;
						}
                        break;
                    default:
						possible = 0;
						paramcd = paramca-1;
						break;
                }/* fin du switch */
            }/* fin du while */
	    }/* fin du if */
	    else if(paramca>paramcd)
	    {
	        paramcd++;
            while((paramld>=paramla)&&(paramcd<=paramca))
            {
                switch(verifoccupe(paramld, paramcd))
                {
                    case 1:
						possible=1;
						paramld--;
						paramcd++;
						break;
                    case 3:
                        if((ifnoir())&&(paramcd==paramca)){
							possible = 1;
							paramcd = paramca+1;
						}
                        else{
							possible = 0;
							paramcd = paramca+1;
						}
                        break;
                    case 5:
                        if((!ifnoir())&&(paramcd==paramca)){
							possible = 1;
							paramcd = paramca+1;
						}
                        else{
							possible = 0;
							paramcd = paramca+1;
						}
                        break;
                    default:
						possible = 0;
						paramcd = paramca+1;
						break;
                }/* fin du switch */
            }/* fin du while */
	    }/* fin du else if */
	}/* fin du else if */
    return possible;
}/* ==FinFonction - deplacementDiagonale== */

/* ================================= */

/* ===========FONCTION CONVERTISSEMENT============ */
/* ==Fonction pour convertir la colonne entrée par l'utilisateur en int == */
int conv_colonne_ChartoInt(char paramc){
	int c1;
	paramc = tolower(paramc);
	switch(paramc){
			case 'a': c1=0; break;
			case 'b': c1=1; break;
			case 'c': c1=2; break;
			case 'd': c1=3; break;
			case 'e': c1=4; break;
			case 'f': c1=5; break;
			case 'g': c1=6; break;
			case 'h': c1=7; break;
	}
	return c1;
}/* ==FinFonction - conv_colonne_ChartoInt== */
/* ============================================================================= */
