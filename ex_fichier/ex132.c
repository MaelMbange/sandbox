#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h> 
#include <windows.h>


typedef struct 
{

char Nom [20] ;
char Prenom [20];
short age ;

} FICHE;


void affichage();
int  encodage(FICHE *,int nbel);
void Ecriture(char *);

char *FichierVerif();


int main()
{
	char *alloc;	
	int i, j = 1;
	int x = 1,y;

	do
	{
		alloc = NULL;
		system("cls");
		printf("Que voulez vous faire:\nChoix:\n1 => ecrire dans/sur un fichier\n2 => quitter\nchoix: ");
		fflush(stdin);
		scanf("%d",&y);
		switch(y)
		{
			case 2: x = 0;
			break; 
			case 1: alloc = FichierVerif();
			break;
		}
		if(alloc != NULL && x != 0)
		{
			do
			{	system("cls");
				printf("Choix:\n1 => supprimer fichier\n2 => encoder\n3 => lire\n4 => Retout en arriere\nchoix: ");
				fflush(stdin);
				scanf("%d",&i);
				printf("\n");
				switch(i)
				{
					case 1: remove(alloc);
							perror(NULL);
							system("cls");
					break;

					case 2: Ecriture(alloc);
					break;

					case 3: affichage();					
					break;

					case 4: j = 0;
					break;			
				}
				if (i!=1)
				{
					printf("\n-ENTER-");
					fflush(stdin);
					getchar();
					system("cls");
				}
			} while (j);
		}
		else
		{
			if(x!=0)printf("Reboot :\n");			
		}

	}while(x);

	free(alloc);

	return 0;
}

char *FichierVerif()
{
	FILE *fp;
	int nbencoded,nbel = 0;
	int test;
	char vec[128];
	char *alloc;

	system("dir read *.test");
	printf("\nQuel est le nom du fichier?\n(existant ou un nouveau pour un nouveau fichier)\nNom fichier: ");
	fflush(stdin);
	gets(&vec[0]);
	alloc = (char *)calloc(strlen(vec)+1,sizeof(char));
	strcpy(alloc,vec);

	fp = fopen(alloc,"r+b");
	if (fp == NULL)
	{
		fp = fopen(alloc,"w+b");
		if (fp == NULL)
		{
			perror("Erreur de fichier: ");
			return NULL;
		}
		else
		{
			nbencoded = fwrite(&nbel,sizeof(int),1,fp);
			printf("Nombre de valeur pre-encode: %d\n",nbencoded);
			if (fclose(fp)!=0) perror("Erreur de fermeture: ");
			return alloc;
		}
	}
	else
	{
		if (fclose(fp)!=0) perror("Erreur de fermeture: ");
		return alloc;
	}


}


void Ecriture(char *alloc)
{ 
	FILE *fp;
	int test, nbel = 0;
	int i;
	FICHE membre;

	fp = fopen(alloc,"r+b");//rajouter une condition
	if(fp!=NULL)
	{
		test = fread(&nbel,sizeof(int),1,fp);
		nbel = encodage(&membre,nbel);
		test = fseek(fp,0,SEEK_SET);
		test = fwrite(&nbel,4,1,fp);

		printf("nbel dans le fichier ==> %d\n",nbel);
		test = fseek(fp, 0, SEEK_END);
		printf("test deplacement = %d\n",test);
		test = fwrite(&membre,sizeof(FICHE),1,fp);
		printf("test ouverture 1(membre) = %d\n\n",test);

		test = fclose(fp);
		if (test !=0) perror("test close ouverture = bien fermé\n\n");
	}
	else
	{
		perror("Erreur d'ouverture :");
	}	
	
}

int encodage(FICHE *p, int nbel)
{
	fflush(stdin);
	printf("Nom : ");
	gets(p->Nom);
	
	fflush(stdin);
	printf("Prenom : ");
	gets(p->Prenom);
	fflush(stdin);
	printf("age : ");
	fflush(stdin);
	scanf("%d",&p->age);
	printf("\n");
 	nbel = nbel + 1;

return nbel;
}

/*
I : le vecteur membre, et les nbel membres
p : permet d'afficher les nbel membres
o : /
*/

void affichage()
{
	FICHE *vec;
	FILE *fp;
	int test;
	int nbel;

	int verif ;

	fp = fopen("./doc.test","r+b");
	if (fp == NULL) perror(NULL);
	else
	{
		//test = fseek(fp,0,SEEK_SET);
		test = fread(&nbel,sizeof(int),1,fp);
		vec = (FICHE *)malloc(sizeof(FICHE)*nbel);
		test = fread(vec,sizeof(FICHE),nbel,fp);
		test = fclose(fp);

		printf("nbel : %d\n",nbel);
		for (int i = 0; i < nbel; i++)
		{			
			printf("%-20s  %-20s\t%d\n",(vec+i)->Nom,(vec+i)->Prenom,(vec+i)->age);
		}
		remove("./doc.test");

		fp = fopen("./doc.test","w+b");
		if (fp == NULL) perror(NULL);
		else
		{
			
			test = fwrite(&nbel,4,1,fp);
			test = fwrite(vec,sizeof(FICHE),nbel,fp);

			test = fclose(fp);
		} 

		free(vec);
	}
	

}
