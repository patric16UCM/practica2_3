
#include <sched.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using namespace std;
int main(int argc, char *argv[]){
/*
 Escribir un programa que realice el borrado programado del propio ejecutable.
El programa tendrá como argumento el número de segundos que esperará antes de borrar el fichero. 
El borrado del fichero se podrá detener si se recibe la señal SIGUSR1.
*/
int pid;
pid = getpid();
//coger el pid

char *num;
asprintf(&num,"%d",pid);
char buffer[125];
char *str1= "kill ";
strcat(strcpy(buffer, str1), num);//crear el comando
int tiempo = atoi(argv[1]);
sleep(tiempo); 
kill(pid,SIGUSR1);
system(buffer);//borrar el ejecutable
    return 0;
}
