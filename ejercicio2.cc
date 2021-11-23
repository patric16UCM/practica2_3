
#include <sched.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;
int main(){
    int pid = getpid();
    int prioridadMax;
    int prioridadMin;
    int prioridadActual;
    int policy = sched_getscheduler(pid);
   sched_get_priority_max(prioridadMax);
   sched_get_priority_min(prioridadMin);
   prioridadActual = getpriority(PRIO_PROCESS,pid);

   printf("Prioridad del proceso actual: %d \n",prioridadActual);
   printf("Prioridad  maxima: %d \n",prioridadMax);
   printf("Prioridad minima: %d \n",prioridadMin);
   printf("Politica de planificacion: %d \n",policy);

    return 0;
}
