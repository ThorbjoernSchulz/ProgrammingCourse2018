#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//definitionen
long fibonacci_rec(long fib);

int main(int args, char * argv []){

    int eingang              = 0;
    int check                = 0;
    long tmp               = 0;

    printf("geben Sie eine Zahl ein: ");
    check = scanf("%d",&eingang);

    if(check != 1){
        printf("ungültige Eingabe ... \n");
        return -1;
    }
     
    if(eingang <= 0){
        printf("Zahl ist negativ ... \n");
        return -1;
    }
    
    printf("Die Fibonacci - Zahl an der Stelle  %i \n++++++++++++++++++++++++\n", eingang);
    
    tmp = fibonacci_rec(eingang);
    printf("FibZahl ist %li\n",tmp);

    return 0;
}

long fibonacci_rec(long fib){
    if( fib == 0 ) return 0;
    if( fib == 1 ) return 1;
    else{
        return fibonacci_rec( fib-1 ) + fibonacci_rec( fib-2 );
    }
}

