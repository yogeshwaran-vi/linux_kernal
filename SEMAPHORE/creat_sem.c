#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

int main()
{
    key_t key;
    int semid;

    // Generate unique key
    key = ftok("semfile", 65);

    // Create 1 semaphore
    semid = semget(key, 1, 0666 | IPC_CREAT);

    if (semid == -1) {
        perror("semget failed");
        return 1;
    }

    printf("System-V Semaphore created\n");
    printf("Semaphore ID = %d\n", semid);

    printf("Press ENTER to exit (semaphore will stay)...\n");
    getchar();   // keep program running

    return 0;
}

