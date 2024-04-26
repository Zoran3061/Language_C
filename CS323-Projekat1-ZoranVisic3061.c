#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MAXL 15
typedef struct kontakti
{
char ime[15];
char prezime[15];
char adresa[15];
char tel[15];
	
}Kontakti;
int getBrKon();
void ucitajKontakte(Kontakti *kontakt);
void ispisi(Kontakti *kontakt);
void pocetniEkran(Kontakti *kontakt);
void obrisi(Kontakti *kontakt, int indeks);
void dodaj(Kontakti *kontakt);
void izmeni(Kontakti *kontakt, int indeks);
void stampajKon(Kontakti *kontakt, int i);
void sortiraj(Kontakti *kontakt);
void snimi(Kontakti *kontakt);

int brKon;

int main(void){
brKon = getBrKon();
Kontakti *kontakt;
kontakt = (Kontakti*)malloc(sizeof(Kontakti)*brKon);
ucitajKontakte(kontakt);
pocetniEkran(kontakt);
return 1;
}
void ucitajKontakte(Kontakti *kontakt){
FILE *pf;
int p=0;
char line[256];
pf=fopen("Kontakti.txt","r");
if (pf == NULL){
printf("Pri otvaranju ove datoteke doslo je do greske!\n");
exit(EXIT_SUCCESS);
}
fgets(line, sizeof(line), pf);
brKon = atoi(line);  
while (fgets(line, sizeof(line), pf)) { 
strcpy(kontakt[p].ime, line); 
strtok(kontakt[p].ime, "\n");   	
fgets(line, sizeof(line), pf);
strcpy(kontakt[p].prezime, line);
strtok(kontakt[p].prezime, "\n");
fgets(line, sizeof(line), pf);
strcpy(kontakt[p].adresa, line); 
strtok(kontakt[p].adresa, "\n");       
fgets(line, sizeof(line), pf);
strcpy(kontakt[p].tel, line);
strtok(kontakt[p].tel, "\n");		
p++;
}
fclose(pf);
}
void ispisi(Kontakti *kontakt){
int i, k;
ucitajKontakte(kontakt);
for(i = 0; i < brKon; i++)
{
	printf("Kontakt br. %d\n", (i+1));
	printf("Ime: %s\n", kontakt[i].ime);
	printf("Prezime: %s\n", kontakt[i].prezime);
	printf("Adresa: %s\n", kontakt[i].adresa);
	printf("Telefon: %s\n\n", kontakt[i].tel);
}
printf("1 - Obrisi kontakt\n2 - Dodaj novi kontakt\n3 - Izmeni kontakt\n4 - Povratak na pocetni meni\n");
printf("Unos: ");
scanf("%d", &k);
printf("\n");
if(k==1)
{
	printf("Unesite broj kontakta koga zelite da obrisete: ");
	scanf("%d", &k);
	system("cls");
	obrisi(kontakt, k);
}
else if(k==2)
{
	system("cls");
	dodaj(kontakt);
}
else if(k==3)
{
	printf("Unesite broj kontakta koji zelite da promenite: ");
	scanf("%d", &k);
	system("cls");
	izmeni(kontakt, k);
}
else if(k==4)
{
	system("cls");
	pocetniEkran(kontakt);
}
else
{
	system("cls");
	printf("Los unos!\n\n");
	ispisi(kontakt);
}	
}
void pocetniEkran(Kontakti *kontakt){
int k;
printf("\t\t\t\t\t\t  Telefonski imenik\n");
printf("1 - Ispisi kontakte\n");
printf("2 - Sortiraj kontakte po prezimenu");
printf("\t\t\t\t\t\t\t\t3 - Izadji iz programa\n");
printf("Unos: ");
scanf("%d", &k);
printf("\n");
if(k==1)
{
system("cls");
ispisi(kontakt);
}
else if(k==2)
{
	system("cls");
	sortiraj(kontakt);
}
else if(k==3)
{
	exit(EXIT_SUCCESS);
}
else
{
	printf("Los unos! Probajte ponovo.\n");
	pocetniEkran(kontakt);
}
}
void obrisi(Kontakti *kontakt, int indeks){
char str[2];
int i;
FILE *pf;
indeks--;
pf=fopen("kontakti.txt","w");	
if (pf == NULL){
printf("Greska pri otvaranju datoteke!\n");
exit(EXIT_SUCCESS);
}
brKon--;
itoa(brKon, str, 10);
fputs (str,pf);
fputs ("\n",pf);
for(i = 0; i <= brKon; i++)
{
if(i != indeks)
{
	fputs (kontakt[i].ime,pf);
	fputs ("\n",pf);
	fputs (kontakt[i].prezime,pf);
	fputs ("\n",pf);
	fputs (kontakt[i].adresa,pf);
	fputs ("\n",pf);
	fputs (kontakt[i].tel,pf);
	fputs ("\n",pf);
}
}
fclose(pf);
ispisi(kontakt);
}
void dodaj(Kontakti *kontakt){
kontakt = (Kontakti*)realloc(kontakt, sizeof(Kontakti)*(brKon+1));
printf("\nUnesite ime novog kontakta: ");
scanf("%s", &kontakt[brKon].ime);
getchar();
printf("Unesite prezime novog kontakta: ");
scanf("%s", &kontakt[brKon].prezime);
getchar();
printf("Unesite adresu novog kontakta: ");
fgets(kontakt[brKon].adresa, sizeof(kontakt[brKon].adresa), stdin);
strtok(kontakt[brKon].adresa, "\n");
printf("Unesite telefon novog kontakta: ");
scanf("%s", &kontakt[brKon].tel);
getchar();
brKon++;
snimi(kontakt);
ispisi(kontakt);
}
int getBrKon(){
FILE *pf;
char line[256];
pf=fopen("kontakti.txt","r");
if (pf == NULL)
{	
	printf("Greska pri otvaranju datoteke!\n");
	exit(EXIT_SUCCESS);
} 
fgets(line, sizeof(line), pf);
brKon = atoi(line);
fclose(pf);
return brKon;
}
void izmeni(Kontakti *kontakt, int indeks){
int i, k;
indeks = indeks - 1;
for(i = 0; i < brKon; i++)
{
if(i==indeks)
{
	printf("1 - Promenite ime\n2 - Promenite prezime\n3 - Promenite adresu\n4 - Promenite broj telefona\n");
	printf("Unos: ");
	scanf("%d", &k);
	getchar();
	if(k==1)
{
	printf("\nUnesite ime novog kontakta: ");
	scanf("%s", &kontakt[i].ime);
	getchar();
}
else if(k==2)
{
	printf("Unesite prezime novog kontakta: ");
	scanf("%s", &kontakt[i].prezime);
	getchar();
}
else if(k==3)
{
	printf("Unesite adresu novog kontakta: ");
	fgets(kontakt[i].adresa, sizeof(kontakt[i].adresa), stdin);
	strtok(kontakt[i].adresa, "\n");
}
else if(k==4)
{
	printf("Unesite telefon novog kontakta: ");
	scanf("%s", &kontakt[i].tel);
	getchar();
}
else
{
	printf("\nLos unos!\n");
	izmeni(kontakt, indeks);
}
}
}
snimi(kontakt);
ispisi(kontakt);
}
void stampajKon(Kontakti *kontakt, int i){
int k;
printf("\nIme: %s\n", kontakt[i].ime);
printf("Prezime: %s\n", kontakt[i].prezime);
printf("Adresa: %s\n", kontakt[i].adresa);
printf("Telefon: %s\n\n", kontakt[i].tel);	
}
void sortiraj(Kontakti *kontakt){
char tempIme[10], tempPrezime[10], tempAdresa[20], tempTelefon[15];
int i, j;
for(i=0;i<brKon;i++)
{
    for(j=i+1;j<brKon;j++)
	{
        if((strcmp(kontakt[i].prezime, kontakt[j].prezime))>0)
		{
         	strcpy(tempIme,kontakt[i].ime);
            strcpy(tempPrezime,kontakt[i].prezime);
            strcpy(tempAdresa,kontakt[i].adresa);
            strcpy(tempTelefon,kontakt[i].tel);
            strcpy(kontakt[i].ime,kontakt[j].ime);
            strcpy(kontakt[i].prezime,kontakt[j].prezime);
            strcpy(kontakt[i].adresa,kontakt[j].adresa);
            strcpy(kontakt[i].tel,kontakt[j].tel);
            strcpy(kontakt[j].ime,tempIme);
            strcpy(kontakt[j].prezime,tempPrezime);
            strcpy(kontakt[j].adresa,tempAdresa);
            strcpy(kontakt[j].tel,tempTelefon);
    	}
    }
}	
snimi(kontakt);
ispisi(kontakt);
}
void snimi(Kontakti *kontakt){
char str[2];
int i;
FILE *pf;
pf=fopen("kontakti.txt","w");
if (pf == NULL)
{
	printf("Greska pri otvaranju datoteke!\n");
	exit(EXIT_SUCCESS);
}
kontakt = (Kontakti*)realloc(kontakt, sizeof(Kontakti)*brKon);
if(kontakt == NULL)
{
	printf("Realloc nije uspeo\n");
}
itoa(brKon, str, 10);
fputs (str,pf);
fputs ("\n",pf);
for(i = 0; i < brKon; i++)
{
	fputs (kontakt[i].ime,pf);
	fputs ("\n",pf);
	fputs (kontakt[i].prezime,pf);
	fputs ("\n",pf);
	fputs (kontakt[i].adresa,pf);
	fputs ("\n",pf);
	fputs (kontakt[i].tel,pf);
	fputs ("\n",pf);
}
fclose(pf);
ispisi(kontakt);
}
