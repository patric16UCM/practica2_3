#include <signal.h>
#include <string>
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>


using namespace std;
int main(){
sigset_t conjunto ;
sigemptyset(&conjunto);
sigaddset(&conjunto,SIGINT);
sigaddset(&conjunto,SIGTSTP); 
int resultado = sigprocmask(SIG_BLOCK,&conjunto,NULL);
sleep(getenv("SLEEP_SECS"));
sigprocmask(SIG_UNBLOCK,&conjunto,NULL);
return 0;
}
