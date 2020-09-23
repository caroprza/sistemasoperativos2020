#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int arg0, char *arg[]) {
    unsigned pid = fork();
    if (pid == 0) {
        char *newargv[] = { NULL };
        char *newenviron[] = { NULL };
        newargv[0] = arg[1];
        printf("Soy el proceso hijo\n");
        execve(arg[1], &arg[1], newenviron);
        perror("execve");
        exit(EXIT_FAILURE);
        return 10;
    }
    else {
        int status;
        printf("Soy el proceso padre y mi hijo es %u\n", pid);
        //sleep(4);
        wait(&status);
        printf("Terminando despues del hijo y estatus %d \n", status);
    }
    printf("Hola mundo\n");
    return 0;
}