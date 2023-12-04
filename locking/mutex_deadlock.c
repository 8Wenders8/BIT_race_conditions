#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t first_mutex;
pthread_mutex_t second_mutex;

void *function1(){
    pthread_mutex_lock(&first_mutex);
    printf("Thread ONE acquired first_mutex\n");
    sleep(1);
    pthread_mutex_lock(&second_mutex);
    printf("Thread ONE acquired second_mutex\n");
    pthread_mutex_unlock(&second_mutex);
    printf("Thread ONE released second_mutex\n");
    pthread_mutex_unlock(&first_mutex);
    printf("Thread ONE released first_mutex\n");
}

void *function2(){
    pthread_mutex_lock(&second_mutex);
    printf("Thread TWO acquired second_mutex\n");
    sleep(1);
    pthread_mutex_lock(&first_mutex);
    printf("Thread TWO acquired first_mutex\n");
    pthread_mutex_unlock(&first_mutex);
    printf("Thread TWO released first_mutex\n");
    pthread_mutex_unlock(&second_mutex);
    printf("Thread TWO released second_mutex\n");
}


int main(){
    pthread_mutex_init(&first_mutex, NULL);
    pthread_mutex_init(&second_mutex, NULL);

    pthread_t t_one, t_two;
    pthread_create(&t_one, NULL, function1, NULL);
    pthread_create(&t_two, NULL, function2, NULL);

    pthread_join(t_one, NULL);
    pthread_join(t_two, NULL);

    printf("Thread joined\n");
    return 0;
}

