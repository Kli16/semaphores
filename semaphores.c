#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define KEY 1242392

int set_semaphore(int id, int val){
  return semctl(id, 0, SETVAL, val);
}

int get_semaphore(){
  int semid;
  semid = semget(KEY, 1, 0664);
  printf("semaphore value: %d\n", semctl(semid, 0, GETVAL));
  return semid;
}

void remove_semaphore() {
  int sem_id = semget(KEY, 1, 0664);
  printf("semaphore removed: %d\n", semctl(sem_id, 0, IPC_RMID));
}

int create_semaphore(int val){
  int semid;
  semid = semget(KEY, 1,  IPC_CREAT | IPC_EXCL | 0664);
  //printf("semid after semget: %d\n", semid);
  //printf("error :( %s\n", strerror(errno));
  if (semid != -1){
    printf("semaphore created: %d\n", semid);
    set_semaphore(semid, val);
    printf("value set: %d\n", val);
  }
  else {
    printf("semaphore already exists!\n");
  }
  return semid;
}

int main(int numargs, char ** args){
  if (numargs < 2){
    printf("You need more arguments!\n");
  }
  else {
    if (strcmp(args[1], "-c") == 0){
      create_semaphore(atoi(args[2]));
    }
    if (strcmp(args[1], "-v") == 0){
      get_semaphore();
    }
    if (strcmp(args[1], "-r") == 0){
      remove_semaphore();
    }
  }
}
