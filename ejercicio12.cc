
#include <sched.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using namespace std;
int volatile senalesInt=0;
int volatile senalesStp=0;
void sumador(int sen){
   if(sen == SIGINT)
    senalesInt++;
    if(sen == SIGTSTP)
    senalesStp++;
}


int main(){
/*
 Escribir un programa que instale un manejador para las señales SIGINT y SIGTSTP. 
 El manejador debe contar las veces que ha recibido cada señal. 
 El programa principal permanecerá en un bucle que se detendrá cuando 
 se hayan recibido 10 señales. El número de señales de cada tipo se mostrará 
 al finalizar el programa. 
*/

int contadorSenales =0;
struct sigaction act;
memset(&act,0, sizeof(struct sigaction));
/*actInt.sa_handler = {
    senalesInt++;
    contadorSenales++};*/
sigaction(SIGINT, NULL, &act); //Get handler
act.sa_handler = sumador;
sigaction(SIGINT, &act, NULL); //Set sa_handler
//Sigtstp
sigaction(SIGTSTP, NULL, &act); //Get handler
act.sa_handler = sumador;
sigaction(SIGTSTP, &act, NULL); //Set sa_handler

sigset_t conjunto;
sigemptyset(&conjunto);
sigaddset(&conjunto, SIGINT);	
sigaddset(&conjunto, SIGTSTP);


while(contadorSenales<10){
    contadorSenales = senalesInt+senalesStp;
    sigsuspend( &conjunto);
}
printf("Señales SIGINT  %d \n",senalesInt);
printf("Señales SIGTSTP  %d \n",senalesStp);

return 0;
}
