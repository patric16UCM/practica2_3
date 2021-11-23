
#include <sched.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;
int main(){
    pid_t demonio = setsid();
    int res = chdir("/tmp");
    id_t id;
    pid_t idP;
    pid_t idG;
    pid_t idS;
    idP=getppid();
    idG = getpgid(demonio);
    idS = getsid(demonio);
    printf("PID del proceso  : %i \n",id);
    printf("PID del padre del proceso : %i \n",idP);
    printf("PID del grupo del proceso : %i \n",idG);
    printf("PID de la sesion del proceso : %i \n",idS);

    return 0;
}
