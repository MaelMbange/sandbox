#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{

char Nom [20] ;
char Prenom [20];
short age ;

} FICHE;

void affichage(int );
int  encodage(FICHE * );
int Ecriture(int );

int main()
{
	
	int nbel;
	nbel = Ecriture(nbel);

	printf("nombre element :%d\n",nbel );
	if (nbel != 0)
	{
		printf("\nFiche :\n");
		affichage(nbel);
	}
	

	return 0;
}


/*
I : le vecteur membre
p : permet d'ecrire dans les nbel membre
o : renvoie la valeur nbel
int verif;
*/
int Ecriture(int nbel)
{ 
	FILE *fp;
	int recup;
	FICHE membre[20];

	fp = fopen("./doc.test","r+b");
	if ( fp == NULL)
	{
		fp = fopen("./doc.test","w+b");
		if (fp == NULL) perror(NULL);
		else
		{
			nbel = encodage(membre);

			recup = fwrite(&membre[0],sizeof(FICHE),nbel,fp);
			if (recup != nbel)
			{
				printf("Tous les elements n'ont pas ete encode\n");
				nbel = recup;
			}
			else
			{
				printf("fermeture bien effectuee\n");
			}
			recup = fclose(fp);
			if (recup != 0)
			{
				printf("probleme a la fermeture\n");
			}
		}
	}
	
	
	return nbel;
}

int encodage(FICHE *p )
{
	int nbel;

	do
	{
		printf("Entrez le nombre de membre : ");
		fflush(stdin);
		scanf("%d",&nbel);
		printf("\n");

	} while (nbel<0 || nbel > 20);


	for (int i = 0; i < nbel; i++)
		{
			fflush(stdin);
			printf("Nom : ");
			gets((p+i)->Nom);
			
			fflush(stdin);
			printf("Prenom : ");
			gets((p+i)->Prenom);
			fflush(stdin);
			printf("age : ");
			fflush(stdin);
			scanf("%d",&((p+i)->age));
			printf("\n");

		}	

return nbel;
}

/*
I : le vecteur membre, et les nbel membres
p : permet d'afficher les nbel membres
o : /
*/

void affichage(int nbel)
{
	FICHE vec[20];
	FILE *fp;
	int verif ;
	fp = fopen("./doc.test","r+b");
	if (fp == NULL)
	{
		perror(NULL);
	}
	else
	{
		verif = fread(vec,sizeof(FICHE),nbel, fp);

		for (int i = 0; i < verif; i++)
		{
			printf("%s\t%s\t%d\n",&vec[i].Nom,&vec[i].Prenom,vec[i].age);
		}
		nbel = verif;

		if(verif != nbel) printf("tout n'as pas ete lu\n");
		verif = fclose(fp);
		if (verif != 0) printf("erreur lors de la fermeture\n");
		

		remove("./doc.test");
		fp = fopen("./doc.test","w+b");
		if (fp == NULL) perror(NULL);
		else 
		{
			verif = fwrite(vec,sizeof(FICHE),nbel,fp);
			verif = fclose(fp);
			if (verif != 0) perror(NULL);
		}



	}
	

}

