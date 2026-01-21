#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int value = 16;

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) { /* child process */
        value += 4;
        return 0;
    } else if (pid > 0) { /* parent process */
        wait(NULL);
        printf("PARENT: value = %d", value); /* LINE X */
        return 0;
    }
}