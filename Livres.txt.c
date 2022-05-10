// Mon projet fin d annee 
// realise par : Younes sghyer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#define t_l 30
typedef struct 
{
	char titre[t_l];
	char genre[t_l];
	char date[t_l];
	int id;
}Livre;
// La premier fonction d ajout 
//--------Debut de la fonction d ajout -----------
void Ajouter()
{
	
	FILE *ptr;
	ptr=fopen("Livres.txt" ,"a+");
	if (ptr!=NULL)printf("Le fichier bien ouvrit \n\n");
	Livre lv;
		printf(".........Remplir ce qui suit........ :\n\n");
		printf("Ecrire le titre \n");
		scanf("%s" ,lv.titre);
		printf("Ecrire le genre  \n");
		scanf("%s" ,lv.genre);
		printf("Ecrire la date de edition (jj//mm//aa):\n");
		scanf("%s" ,lv.date);
		printf("Ecrire l id :\n");
		scanf("%d" ,&lv.id);
		fprintf(ptr , "%s ; %s ; %s ; %d ;\n" ,lv.titre ,lv.genre ,lv.date ,lv.id );
	fclose(ptr);
}
//------------Fin de la fonction d ajout------------
//La deuxieme fonction de modification
//------------Debut de la fonction de modification------ 
void Modifier()
{
	
	FILE *ptr,*pt;
	char nch[t_l];
	Livre lv;
	printf(".....Ecrire le titre  de livre que tu veux modifier ..... : \n");
	scanf("%s" ,&nch);
	ptr=fopen("Livres.txt" ,"r+");
	pt=fopen("Liv.txt" ,"w+");// on utilse w+ par ce que on veut ecraser le contenu  
	if (ptr!=NULL)printf("Bien ouvrit \n");
	do
	{
		fscanf(ptr , "%s ; %s ; %s ; %d ;\n" ,lv.titre ,lv.genre ,lv.date ,&lv.id );
		fflush(stdin);//mettre a jour le flux d’entree standard en transferant les caracteres du tampon clavier au flux stdin, tout en vidant ce tampon.
		if (strcmp(nch, lv.titre)==0)
		{
			printf("Modifier le titre de livre :\n");
			scanf("%s" ,&lv.titre);
			printf("Modifier le genre de livre :\n");
			scanf("%s" ,&lv.genre);
			printf("Modifier la date edition de livre (jj//mm//aa):\n");
			scanf("%s" ,&lv.date);
			printf("Modifier le id de livre : \n ");
			scanf("%d" ,&lv.id);
		}
		fprintf(pt, "%s ; %s ; %s ; %d ;\n" ,lv.titre ,lv.genre ,lv.date ,lv.id);
	}while(!feof(ptr));
	fclose(ptr);
	fclose(pt);
	remove("Livres.txt");
	rename("Liv.txt","Livres.txt");
    printf("la modification est reussi");
}
//------------Fin de la fonction de modification -----------
//la troixieme fonction d affichage
// ------------Debut de la fonction affichage---------------
void Affichage(void)
{

	FILE *ptr;
	ptr=fopen("Livres.txt" ,"r");
	if (ptr!=NULL)printf("Bien ouvrit \n");
	printf("........Voila la liste des auteurs ..........\n\n");
	Livre lv;
	while(1)
	{
		int c = fscanf(ptr , "%s ; %s ; %s ; %d ;\n" ,lv.titre ,lv.genre ,lv.date ,&lv.id );
		if(c==EOF)break;
		fflush(stdin);
		printf(" Titre :(%s) || Genre :(%s) || date edition :(%s) || id : (%d) \n" ,lv.titre,lv.genre,lv.date,lv.id);
	}
	fclose(ptr);
}
//------------Fin de la fonction d'affichage ---------------
//La quatrieme fonction de recherche 
//------------Debut de la fonction de la recherche ----------
void Rechercher(void)
{
	FILE *ptr;
	ptr=fopen("Livres.txt" ,"r+");
	if (ptr!=NULL)printf("Bien ouvrit \n");
	Livre lv;
	int trouver=0;
	int i=0;
	int nch;
	printf("........ Entrer l id de livre que tu veux rechercher......... :\n"); 
	scanf("%d" ,&nch);
	 while(!feof(ptr))
	 {
	    fscanf(ptr , "%s ; %s ; %s ; %d ;\n" ,lv.titre ,lv.genre ,lv.date ,&lv.id );
		{
	 	if (nch == lv.id) 
	 	{
	 		printf("Existe \n");
	 		printf(" Titre :(%s) || Genre :(%s) || date edition :(%s) || id :(%d) \n" ,lv.titre,lv.genre,lv.date,lv.id);
	 		break;
		} 
		}
	 }
	 if (nch!=lv.id)
	 {
	 	printf("Ne existe pas\n");
	 }	 
}
//----------Fin de la fonction de recherche ---------------
//la cinquieme fonction de suppression 
//----------Debut de la fonction de la suppression---------
void Supprimer(void)
{
	
	int nch;
	printf("......... Entrer id de livre que tu veux supprimer .......... :\n");
	scanf("%d" ,&nch);
	fflush(stdin);
	FILE *ptr,*pt;
	ptr=fopen("Livres.txt" ,"r");
	if (ptr!=NULL)printf("Bien ouvrit \n");
	pt=fopen("Liv.txt" ,"a");
	if (ptr!=NULL)printf("Bien ouvrit \n");
	Livre lv;
	do
	{
		fscanf(ptr , "%s ; %s ; %s ; %d ;\n" ,lv.titre ,lv.genre ,lv.date ,&lv.id );		
	 	if (nch != lv.id) 
	 	{
	 		fprintf(pt, "%s ; %s ; %s ; %d ;\n" ,lv.titre ,lv.genre ,lv.date ,lv.id);
		}
	}while(!feof(ptr));
	fclose(pt);
	fclose(ptr);
	remove("Livres.txt");
	rename("liv.txt","livres.txt");
	printf("Suppression effectuee \n");
}
//----------Fin de la fonction de la suppression--------------
//la sixiéme fonction de sorir du programme 
// -------------Début de la fonction quiter -----------------------
void Quiter(void)
{
	printf("\n        \t-----FIN de programme -----------\n");
 	printf("\n        \t----------MERCI-----------\n");
 	return(-1);
}
//------------Fin de la fonction quiter  --------
int main()
{
	int choix;
	do
	{
		printf("$$$$$$$$$$$$$$$$$-----Menu---$$$$$$$$$$$$$$$$$$\n");
		printf("$$ Pour ajouter un livre .......... ....... : 1\n");
		printf("$$ Pour afficher la liste des livres .....  : 2\n");
		printf("$$ Pour modifier un livre .......... ...... : 3\n");
		printf("$$ Pour supprimer un livre ................ : 4\n");
		printf("$$ Pour Rechercher un livre ............... : 5\n");
		printf("$$ pour quiter le programme ............... : 0\n");
		printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\n \n");
		printf("........... Donnez votre choix s.v.p ?........:  ");
		scanf("%d" ,&choix);
		printf("\n \n");
		switch (choix)
		{
			case 1 : Ajouter();
			break;
			case 2 : Affichage();
			break;
			case 3 : Modifier();
			break;
			case 4 : Supprimer();
			break;
			case 5 : Rechercher();
			break;
			case 0 : Quiter();
			break;
		}		
	}while(choix!=0);		
	return(0);
}
  
