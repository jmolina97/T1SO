#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

void views(){
    DIR *dir;
    struct dirent *sd;

    if((dir = opendir(".")) == NULL){
        //printf("Error, el directorio no existe.");
        //return 1;
        perror("opendir() error");
        printf("asdf");
    }
    else{
        while((sd=readdir(dir)) != NULL){
            printf(">> %s\n", sd->d_name);
        }
    }
    
    closedir(dir);
}
//función que crea todo las cartas en y las guarda en la carpeta mazo.
void createCards(){
    FILE *fp;
	fp = fopen ( "Mazo/0 rojo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/1 rojo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/2 rojo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/3 rojo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/4 rojo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/5 rojo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/6 rojo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/7 rojo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/8 rojo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/9 rojo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/0 rojo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/1 rojo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/2 rojo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/3 amarillo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/4 amarillo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/5 amarillo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/6 amarillo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/7 amarillo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/8 amarillo.txt", "a" );        
	fclose ( fp );
    fp = fopen ( "Mazo/9 amarillo.txt", "a" );        
	fclose ( fp );

}


void draw(int player){
    if (player==1){
        
    }

}

int listdir(const char *path) {
  struct dirent *entry;
  DIR *dp;

  dp = opendir(path);
  if (dp == NULL) 
  {
    perror("opendir");
    return -1;
  }

  while((entry = readdir(dp)))
    puts(entry->d_name);

  closedir(dp);
  return 0;
}