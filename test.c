#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0;

void    *task()
{
    int i = 1;
    while (i++ <= 1000)
        counter++;
    return NULL;
}
int  main()
{
    pthread_t   thread1, thread2, thread3;

    pthread_create(&thread1, NULL, task, NULL);
    pthread_create(&thread2, NULL, task, NULL);
    pthread_create(&thread3, NULL, task, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("counter is : %d\n", counter);
}