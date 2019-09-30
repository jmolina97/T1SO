#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

//Funcion que mueve un archivo de una carpeta a otra
void moveCards(char *src, char *card, char *dest){
	FILE *fp;
	char aux1[50];
	char aux2[50];
	char aux3[50];

	strcpy(aux1, src);
	strcpy(aux2, card);
	strcpy(aux3, dest);


	strcat(aux3, "/");
	strcat(aux3, aux2);
	fp = fopen(aux3, "a");
	fclose(fp);

	strcat(aux1, "/");
	strcat(aux1, aux2);
	remove(aux1);
}

//Funcion que nos ejecuta todo un turno de un jugador(sin robar).
void turno(char *folder){
	DIR *dir; 
	struct dirent *sd; 
	char *cartmano, optstr[2], *descarte, cartdes[50] = "ult_descarte/", mano[100][50], cartjug[50] = "";
	int cont = 0, optint;
 
	printf("En tu mano tienes:\n");
	if ((dir = opendir(folder)) == NULL){
		perror ("opendir() error.");
	}
	else {
		while((sd = readdir(dir)) != NULL){
			if ( !strcmp(sd->d_name, ".") || !strcmp(sd->d_name, "..") ){
			}
			else{
				cartmano = sd->d_name;
				strcpy(mano[cont], cartmano);
				cartmano = strtok(sd->d_name, ".");
				cartmano = strtok(cartmano, "_");
				cont+=1;
				printf("%d) %s\n", cont, cartmano);
			}
		}
	}
	closedir(dir);

	printf("La ultima carta descartada fue:");
	if ((dir = opendir("ult_descarte")) == NULL){
		perror ("opendir() error.");
	}
	else {
		while((sd = readdir(dir)) != NULL){
			if ( !strcmp(sd->d_name, ".") || !strcmp(sd->d_name, "..") ){
			}
			else{
				descarte = sd->d_name;
				if( strlen(descarte)>5){
					strcat(cartdes, descarte);
					descarte = strtok(sd->d_name, ".");
					descarte = strtok(descarte, "_");
				}
			}
		}
	}
	closedir(dir);

	printf("Indique el numero de la carta que desea jugar: \n");
	scanf("%s", optstr);
	optint = atoi(optstr);
	while(optint < 0 || optint > cont){
		printf("Opcion incorrecta\n");
		printf("Indique el numero de la carta que desea jugar: \n");
		scanf("%s", optstr);
		optint = atoi(optstr);
	}
	strcpy(cartjug, mano[optint-1]);
	remove(cartdes);
	moveCards(folder, cartjug, "ult_descarte");	
}

//funcion que crea todas las cartas y las guarda en la carpeta mazo.
void createCards(){
	FILE *fp;
	char Nombre[50] = {0};
	int i;

	for (i = 0; i < 10; i++){
		sprintf(Nombre, "mazo/%d rojo.txt", i);
		fp = fopen(Nombre, "a");
		fclose ( fp );
		if (i >= 1){
			sprintf(Nombre, "mazo/%d rojo_1.txt", i);
			fp = fopen(Nombre, "a");
			fclose ( fp );
		}
	}

	for (i = 0; i < 10; i++){
		sprintf(Nombre, "mazo/%d amarillo.txt", i);
		fp = fopen(Nombre, "a");
		fclose ( fp );
		if (i >= 1){
			sprintf(Nombre, "mazo/%d amarillo_1.txt", i);
			fp = fopen(Nombre, "a");
			fclose ( fp );
		}
	}

	for (i = 0; i < 10; i++){
		sprintf(Nombre, "mazo/%d verde.txt", i);
		fp = fopen(Nombre, "a");
		fclose ( fp );
		if (i >= 1){
			sprintf(Nombre, "mazo/%d verde_1.txt", i);
			fp = fopen(Nombre, "a");
			fclose ( fp );
		}
	}

	for (i = 0; i < 10; i++){
		sprintf(Nombre, "mazo/%d azul.txt", i);
		fp = fopen(Nombre, "a");
		fclose ( fp );
		if (i >= 1){
			sprintf(Nombre, "mazo/%d azul_1.txt", i);
			fp = fopen(Nombre, "a");
			fclose ( fp );
		}
	}

	fp = fopen ( "mazo/+2 amarillo.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/+2 amarillo_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa amarillo.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa amarillo_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto amarillo.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto amarillo_1.txt", "a" );        
	fclose ( fp );

	fp = fopen ( "mazo/+2 azul.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/+2 azul_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa azul.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa azul_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto azul.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto azul_1.txt", "a" );        
	fclose ( fp );

	fp = fopen ( "mazo/+2 rojo.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/+2 rojo_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa rojo.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa rojo_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto rojo.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto rojo_1.txt", "a" );        
	fclose ( fp );

	fp = fopen ( "mazo/+2 verde.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/+2 verde_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa verde.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa verde_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto verde.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto verde_1.txt", "a" );        
	fclose ( fp );

	fp = fopen ( "mazo/cambio color.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/cambio color_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/cambio color_2.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/cambio color_3.txt", "a" );        
	fclose ( fp );

	fp = fopen ( "mazo/+4.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/+4_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/+4_2.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/+4_3.txt", "a" );        
	fclose ( fp );


}

//Esta funcion retorna una carta del mazo de forma aleatoria.
void getCard(char *card, int random){
	DIR *dir; 
	struct dirent *sd;
	int i=0;
	char *cart, mano[108][50];
	printf("%d\n", random);

	if ((dir = opendir("mazo")) == NULL){
		perror ("opendir() error.");
	}
	else {
		while((sd = readdir(dir)) != NULL){
			if ( !strcmp(sd->d_name, ".") || !strcmp(sd->d_name, "..") ){
			}
			else{
				cart = sd->d_name;
				strcpy(mano[i], cart);
				i +=1;
			}
		}
	}
	closedir(dir);
	strcpy(card, mano[random]);
}

//Crea las cartas del mazo y reparte las primeras 7 cartas a los 4 jugadores.
void startGame(){
	char card[50] = "";
	int random, i;
	createCards();
	for (i = 0; i < 7; i++){
		random = rand() % (108-i); 
		getCard(card, random);
		moveCards("mazo", card, "jugador1");
	}
	for (i = 0; i < 7; i++){
		random = rand()%(101-i);
		getCard(card, random);
		moveCards("mazo", card, "jugador2");
	}
	for (i = 0; i < 7; i++){
		random = rand()%(94-i);
		getCard(card, random);
		moveCards("mazo", card, "jugador3");
	}
	for (i = 0; i < 7; i++){
		random = rand()%(87-i);
		getCard(card, random);
		moveCards("mazo", card, "jugador4");
	}
}

