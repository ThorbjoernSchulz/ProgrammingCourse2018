#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initializegenerator() {
    srand(time(NULL));
}
void drawCard(int value){

    char* Symbol;

    switch(value){
        case 2:
            Symbol = "➋\0";
            break;
        case 3:
            Symbol = "➌\0";
            break;
        case 4:
            Symbol = "➍\0";
            break;
        case 5:
            Symbol = "➎\0";
            break;
        case 6:
            Symbol = "➏\0";
            break;
        case 7:
            Symbol = "➐\0";
            break;
        case 8:
            Symbol = "➑\0";
            break;
        case 9:
            Symbol = "➒\0";
            break;
        case 10:
            Symbol = "➓\0";
            break;
        default:
            break;
    
    }
    
    printf("╔═════╗\n"); 
    printf("║❤   ◊║\n");
    printf("║  %s  ║\n",(char*)Symbol);
    printf("║☘   ✣║\n");         
    printf("╚═════╝\n"); 

    return;
}

int getkarte() {
    // Sie koennen Zufallszahlen generieren, indem Sie die Funktion rand() aufrufen
    // z.B. int zufall = rand();
    int zufall = rand() % 9 + 2;
    return zufall;
}

int main() {
    initializegenerator();
    // Code fuer den Spielablauf

    int dealer = 0,player = 0;
    int karte = 0;
    char c = 'y';

    printf("Dealer gibt die erste Karte aus\n");

    do{
        karte = getkarte();
        drawCard(karte);
        printf("es liegt die Karte %i \n",karte );
        player = player + karte;
        printf("deine Punktzahl lautet %i \n",player );
        
        if(player > 21){
            printf("Du hast verloren ... Deine Punktzahl ist %i \n",player);
            return 0;
        }
        
        printf("weiter Zug mit ENTER / Kein Zug mehr mit N oder n \n");
        c = getchar();
        if(c == 'N' || c == 'n'){
            break;
        }

    }while(1);

    printf("deine Punktzahl lautet %i \n",player );
    

    do{
        karte = getkarte();        
        drawCard(karte);
        printf("es liegt die Karte %i \n",karte);
        dealer = dealer + karte;
        
        printf("die Punktzahl des Dealers lautet %i \n",dealer );
       
        if(dealer > 21){
            printf("Dealer hat verloren ... Punktzahl Dealer ist %i \n",dealer);
            return 0;
        }

        if(dealer >= 16){
            printf("Dealer zieht nicht mehr\n");
            break;
        }

        sleep(1);

    }while(1);

    printf("Punktzahl des Dealers lautet %i \n",dealer);
    
    if(dealer >= player){
            printf("Dealer hat gewonnen ... Punktzahl Dealer ist %i \n",dealer);
    }else if(dealer < player){
            printf("Spieler hat gewonnen ... Punktzahl Spieler ist %i \n",dealer);
    }

return 0; 
}


