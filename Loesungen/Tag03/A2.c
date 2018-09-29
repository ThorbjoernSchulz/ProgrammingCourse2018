#include <stdio.h>

int getJahr(){
    int jahr = 0;
    printf ("Geben Sie ein Jahr ein : ");
    scanf ("%d" ,&jahr );
    return jahr;
}

void checkJahr(int jahr){
    if(jahr%4==0) {
        if(jahr%100==0) {
            if ( jahr %400==0) {
                printf ("Schaltjahr !\n");
            }
            else {
                printf ("Kein Schaltjahr !\n");
            }
        }
        else {
            printf ("Schaltjahr !\n");
        }
    }
    else {
        printf ("Kein Schaltjahr !\n");
    }
}


int main (void){
    int jahr = getJahr();

    checkJahr(jahr);
    return 0;

}
