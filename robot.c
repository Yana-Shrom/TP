#include "robot.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#define MAX_X 5
#define MAX_Y 3

int XA=2;           
int YA=2; 


void afficheBord()
{
    for(int i=0; i<=MAX_X+1; i++)
    {
        printf("+");
    }
    printf("\n");
}

void afficheLigne(int pos, char c)
{
	for(int i=0; i<=MAX_X; i++)
	{
		if(i==pos) printf("%c",c);
		else printf(" ");
	}
	printf("+\n");
}
/*
	d'abord tester le d'afficher les ligne 0 et MAX_X
	inspiré de afficheLigne
	modifier le affichebord
*/
void affiche()
{
	afficheBord();
	for(int i=0; i<MAX_Y; i++)
	{
		for(int j=0; j<=MAX_X+1; j++)
		{
			if(j==0 || j==MAX_X+1)
			{
				printf("+");
			}
			else if(i==YA && j==XA)
			{
				printf("X");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	afficheBord();
}

void pause()
{
    system("sleep 1");
    system("clear");
}

void demo()
{
    system("clear");  
    affiche(); 
    for(int i=0; i<50; i++)
    {
        pause();
        randomStepA();
		affiche();
    }
}

void randomStepA()
{
	srand(time(NULL));
	int min=-1;
    int max=1;
	//direction 1=horizontale et 2=verticale
	int direction = 1 + rand() % (2 + 1 - 1);
	//sens -1=négatif et 1=positif
	int sens = min + rand() % (max + 1 - min);
	if(direction == 1 && (XA+sens)>0 && (sens+XA)<MAX_X-1)
	{
		XA = XA + sens;
	}
	if(direction == 2 && (YA+sens)>0 && (sens+YA)<MAX_Y-1)
	{
		YA = YA + sens;
	}
				
}