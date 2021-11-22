#include <unistd.h>
#include <string.h>
#include <stdio.h>
using namespace std;
int main(){
pid_t id;
pid_t idP;
pid_t idG;
pid_t idS;
id = getpid();
idP=getppid();
idG = getpgid(0);
idS = getsid(id);
printf("PID del proceso  : %i \n",id);
printf("PID del padre del proceso : %i \n",idP);
printf("PID del grupo del proceso : %i \n",idG);
printf("PID de la sesion del proceso : %i \n",idS);
return 0;
}
