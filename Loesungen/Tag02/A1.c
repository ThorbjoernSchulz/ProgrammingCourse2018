#include <stdio.h>
#include <stdlib.h>

int Karten_ID = 1234;
int Kontostand = 10000;

int main() {
    int input;

    while(1){

        printf("Karte ID eingeben: ");
        int check = scanf("%i",&input);
        if(check != 1){
            printf("Vorgang abgebrochen ..\n");
            return 0;
        }

        // Prüfen der Karten-ID
        if(input != 1234){
            printf("falsche Karten-ID.. \n");
            return 0;
        }

        input = 0;

        printf("10 €\n");
        printf("25 €\n");
        printf("50 €\n");
        printf("100 €\n");
        printf("200 €\n");
        printf("500 €\n");
        printf("Betrag auswählen :\n");
        printf("(Alle anderen Eingaben führen zum Abbruch)\n");
        check = scanf("%i",&input);
        
        if(check != 1){
            printf("Sie haben keine Zahl eingegeben\n");
            printf("Vorgang abgebrochen ...\n");
            return 0;
        }
        
        if( input != 10 &&
            input != 25 &&
            input != 50 &&
            input != 100 &&
            input != 200 &&
            input != 500){
        
            printf("Sie haben ein falschen Betrag eingegeben\n");
            printf("Vorgang abgebrochen ...\n");
            return 0;
        
        }


        if(Kontostand < 0){
            printf("kein Geld mehr auf dem Konto\n");
            return 0;
        }else{
            Kontostand = Kontostand-input;
            printf("Der aktuelle Kontostand ist: %i \n",Kontostand);
        }

    }
    
    return 0; 
}
