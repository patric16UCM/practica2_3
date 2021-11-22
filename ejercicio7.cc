#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
int main(int argc, char * argv[]){
int resultado = system(argv[1]);
if(resultado == -1){
    printf("Ha habido un error durante la ejecucion. \n");
}
else {
    printf("El comando termino de ejecutarse. \n");
}
return 0;
}
