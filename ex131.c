#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{

char Nom [20] ;
char Prenom [20];
short age ;

} FICHE;

typedef struct 
{
	char Nom[20];
	int position;
	
}INDEX;


void affichage(int );
//void affichageindex(INDEX *,int , FILE *);
int  encodage(FICHE * );
//void cible(FICHE *, int );
//void tri(FICHE *,int );
//void trindex(int ,INDEX *, FILE *);
//void affichagetrie(FICHE *, INDEX *, int  );

int Ecriture(int );

int main()
{
	
	int nbel;
	//FICHE membre[20];
	//INDEX vec[20];

	nbel = Ecriture(nbel);

	printf("nombre element :%d\n",nbel );
	if (nbel != 0)
	{
		printf("\nFiche :\n");
		affichage(nbel);
	}
	

//	printf("\nindex :\n");
	//affichageindex(&vec[0],nbel,fp);
	//cible(&membre[0],nbel);
//	printf("\nindex trie :\n");
	//trindex(nbel,vec);
	//affichageindex(&vec[0],nbel,fp);

	//affichage(&membre[0],nbel,fp);

	//printf("\nFiche :\n");
	//affichagetrie(&membre[0],vec,nbel);

	//affichage(&membre[0],nbel);
	


	return 0;
}


/*
I : le vecteur membre
p : permet d'ecrire dans les nbel membre
o : renvoie la valeur nbel
int verif;
	fp = fopen("C:\\Users\\Maelm\\OneDrive\\Documents\\dossier bureau\\Cours\\Quettier\\exercices\\fichier\\ex liste",r+b);
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

/*
void affichageindex(INDEX *p,int nbel)
{
	for (int i = 0; i < nbel; i++)
	{
		printf("\n");
		printf("nom :%s position :%d",p->Nom,p->position);
		p++;
	}
	printf("\n");

}*/


/*
I : le vecteur membre, et les nbel membres
p : permet de chercher la cible
o : /
*/
/*
void cible(FICHE *p, int nbel)
{	
	int verif = 1;
	int i ;
	char cible[20];

	printf("\nEntrez votre cible : ");
	fflush(stdin);
	gets(cible);
	
	for ( i = 0; i < nbel && verif != 0; i++)
	{
		verif = strcmp(p->Nom,cible);
		p++;
	}

	if (verif == 0)
	{
		printf("La cible existe ligne : %d\n",i-1);
	}
	else
	{
		printf("La cible n'est pas presente.\n");
	}
}
*/


/*
I : le vecteur membre, et les nbel membres
p : permet de trier
o : /
*/
/*
void tri(FICHE *p, int nbel)
{
	int i;
	FICHE sauv;

	for (int j = 1; j < nbel; j++)
	{
		i=j-1;
		sauv=*(p+j); 
		while(i>=0 && strcmp((p+i)->Nom,sauv.Nom)==1)
		{
			*(p+i+1)=*(p+i);
			i--;
		}
		*(p+i+1)=sauv;
	}

}
*/



/*
I : le vecteur membre, et les nbel membres
p : permet de trier par index
o : /
*/
/*void trindex(int nbel,INDEX *pindex, FILE * fp)
{
	int i;
	INDEX sauv;
	

		
	for (int j = 1; j < nbel; j++)
	{
		i=j-1;
		sauv=*(pindex+j); 
		while(i>=0 && strcmp((pindex+i)->Nom,sauv.Nom)==1)
		{
			*(pindex+i+1)=*(pindex+i);
			i--;
		}
		*(pindex+i+1)=sauv;
	}


}*/



/*void affichagetrie(FICHE *pfiche, INDEX *pindex, int nbel)
{
	int var;
	FICHE *p;






	for (int i = 0; i < nbel; i++)
	{
		var = (pindex+i)->position;
		p = (pfiche+var);



		printf("\n");
		printf("%s %s %d",p->Nom,p->Prenom,p->age);
		
	}
	printf("\n");

}*/