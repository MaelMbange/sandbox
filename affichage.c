#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <malloc.h>


void print_time(const char *, float   );
char *encodage(char *);

int main()
{
	char *vec;
	float time;
	char verif[4];
	int i=1;
	while(i)
	{
		printf("Entrez la duree d'affichage (en seconde): ");
		fflush(stdin);
		scanf("%f",&time); 

		vec = encodage(vec);
		print_time(vec, time);


		printf("Voulez vous relancer le programme ? (oui / non) : ");
		fflush(stdin);
		gets(verif);

		do
		{
			if (strcmp(verif,"oui") == 0 )
			{
				i = 1;
				system("cls");
			}
			else
			{
				if (strcmp(verif,"non")== 0)
				{
					i = 0;
					printf("\n-fin-\n");
					getchar();
					system("cls");
				}
				else
				{
					printf("Veuillez recommencer :\n");
					i = 2;
				}
			}
		} while (i == 2);

		
		
	}	


	free(vec);
	return 0;
}
char *encodage(char *vec)
{
	

	char temp[128];
	printf("Entrez une phrase: ");
	fflush(stdin);
	gets(temp);

	

	vec = (char *)malloc(strlen(temp)+1);

	if (vec == NULL)
	{
		perror("Erreur ");
	}
	else
	{
		strcpy(vec,temp);
	}

	

	return vec;
}


void print_time(const char *msg, float  time)
{
	time = time*1000 / strlen(msg);

	while(*msg)
	{
		printf("%c",*msg);
		Sleep(time);
		msg++;
	}
	printf("\n");
	
}