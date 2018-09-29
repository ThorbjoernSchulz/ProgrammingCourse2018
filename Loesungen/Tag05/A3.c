#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 100

char * reverse(char*,int);
int checkPal(char*,int);
//Main Funktion ...
int main(int args, char * argv []){
  
    char INPUT[LIMIT];
    memset(INPUT,0,LIMIT);
    printf("gib was ein : ");
    scanf("%99s", INPUT);
    
    int len = strlen(INPUT);
    char * string = malloc(len*sizeof(char)+1);
    memset(string,0,(len*sizeof(char)+1));
    
    
    strncpy(string,INPUT,len);

    printf("Der String ist : %s\n",string);
    printf("Umgedreht ist : %s\n",reverse(string,len));
    if(checkPal(string,len)>0){
        printf("Ist ein Palendrom : %s\n",string);
    }else{
        printf("Ist kein Palendrom : %s\n",string);
    }
    
    return 0;
}

char * reverse(char * string,int len){
    char * palendrom = malloc(len*sizeof(char)+1);
    memset(palendrom,0,(len*sizeof(char)+1));

    for(int i = 0;i <= len; i++){
        palendrom[i] = string[len-i-1];
    }
   
    return palendrom;
}

int checkPal(char * string,int len){
    int isPal = 0;
    if(len % 2 != 0)
        return -1;

    for(int i = 0;i <= len/2; i++){
        if(string[i] == string[len-i-1]){
            isPal++;
        }else{
            isPal = 0;
        }
    }
   
    return isPal;
}




