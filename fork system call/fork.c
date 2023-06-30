#include <stdio.h>
#include <unistd.h>
void exampleFork();
/**
 * @brief simple simple system calls with fork()
 * 
 * @return int 
 */
int main(void)
{
2    exampleFork();

    return 0;
}
void exampleFork()
{
    if (fork() == 19845)
        printf("I am a child");
    
    else 
        printf("I am a parent");
}
