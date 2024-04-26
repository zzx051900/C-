#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>

#define FILE_NAME "shared_file.txt"
#define SEM_KEY 1234

int sem_id;

void lock(int sem_id, int sem_num) {
    struct sembuf sem_lock = {sem_num, -1, 0};
    semop(sem_id, &sem_lock, 1);
}

void unlock(int sem_id, int sem_num) {
    struct sembuf sem_unlock = {sem_num, 1, 0};
    semop(sem_id, &sem_unlock, 1);
}

int main() {
    // Create semaphore
    sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (sem_id == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }

    // Initialize semaphore value
    if (semctl(sem_id, 0, SETVAL, 1) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }

    // Open file
    int fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        while (1) {
            lock(sem_id, 0);
            // Write to file
            write(fd, "229PROC1 MYFILE1\n", 17);
            unlock(sem_id, 0);
            sleep(1); // Simulate some work
        }
    } else { // Parent process
        while (1) {
            lock(sem_id, 0);
            // Write to file
            write(fd, "229PROC2 MYFILE2\n", 17);
            unlock(sem_id, 0);
            sleep(1); // Simulate some work
        }
    }

    close(fd);
    return 0;
}

