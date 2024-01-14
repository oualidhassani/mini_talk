#include <stdio.h>
#include <unistd.h>

int main (int ac,  char **av)
{
    int i;
    printf("input :");
    scanf("%d", &i);

    printf("RESULT : %d * 5 = %d\n",i, i * 5);
}