#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void signalHandler(int signum){
    int status;
    wait(&status);
    printf("mi hijo termino \n");
}

int main(int arg0, char *arg[]) {
    signal(17, signalHandler);
    unsigned pid = fork();
    if (pid == 0) {
        sleep(5);
        char *newargv[] = { NULL };
        char *newenviron[] = { NULL };
        newargv[0] = arg[1];
        printf("Soy el proceso hijo\n");
        //execve(arg[1], &arg[1], newenviron);
        //perror("execve");
        //exit(EXIT_FAILURE);
        return 10;
    }
    else {
        printf("Soy el proceso padre y mi hijo es %u\n", pid);
        while(1) {
            sleep(2);
            printf("trabajando \n");
        }
        //wait(&status);
        //printf("Terminando despues del hijo y estatus %d \n", status);
    }
    printf("Hola mundo\n");
    return 0;
}