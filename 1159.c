#include <stdio.h>
#include <unistd.h>

int main()
{

    fork() && fork();
    printf("1");
    fork() || fork();
    printf("2");
    return 0;
}