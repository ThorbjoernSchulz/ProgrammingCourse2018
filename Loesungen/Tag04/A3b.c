#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//definitionen
double fibonacci(double fib );

int main(int args, char * argv []){

    int eingang              = 0;
    int check                = 0;
    double tmp               = 0;

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
    
    printf("FibZahl ist %.0f\n",tmp);

    for(int i = 0;i <= eingang; i++){
        tmp = fibonacci(i);
        if(fmod(tmp,2) == 0){
            printf("%.0f\n", tmp);
        }
    }

    return 0;
}

double fibonacci(double fib )
{
    if( fib == 0 ) return 0;
    if( fib == 1 ) return 1;
 
    double prepre = 0;
    double pre = 1;
    double current;
 
    for( long i = 1; i < fib; i++ )
    {
        current = pre + prepre;
 
        prepre = pre;
        pre = current;

    }
  return current;
}

