#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void* increment_counter(void *arg){
    for(int i =0; i < 1000000; ++i){
        pthread_mutex_lock(&counter_mutex);
        counter++;
        pthread_mutex_unlock(&counter_mutex);
    }
    return NULL;
}

int main(){
    pthread_t t_one, t_two;

    pthread_create(&t_one, NULL, increment_counter, NULL);
    pthread_create(&t_two, NULL, increment_counter, NULL);

    pthread_join(t_one, NULL);
    pthread_join(t_two, NULL);

    printf("Counter: %d\n", counter);
    return 0;
}
