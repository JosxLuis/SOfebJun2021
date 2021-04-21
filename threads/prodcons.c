#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_RECORDS 20

int buffer[MAX_RECORDS];
sem_t empty;
sem_t fill;

void *producer(void *d) {
  int pos = 0;
  while (1) {
    sem_wait(&empty); // decrementar empty
    buffer[pos] = pos;
    pos = ((pos + 1) % MAX_RECORDS);
    sleep(1);        // Tiempo para producir el valor
    sem_post(&fill); // incrementar fill
  }
  pthread_exit(NULL);
};

void *consumer(void *d) {
  int pos = 0;
  int valor;
  while (1) {
    sem_wait(&fill); // decrementar fill
    valor = buffer[pos];
    pos = ((pos + 1) % MAX_RECORDS);
    sleep(2); // Tiempo para consumir el valor
    printf("valor = %d \n", valor);
    sem_post(&empty); // incrementar empty
  }
  pthread_exit(NULL);
};

int main() {
  sem_init(&empty, 0, MAX_RECORDS);
  sem_init(&fill, 0, 0);
  pthread_t producerThread, consumerThread;
  pthread_create(&producerThread, NULL, producer, NULL);
  pthread_create(&consumerThread, NULL, consumer, NULL);
  pthread_exit(NULL);
}
