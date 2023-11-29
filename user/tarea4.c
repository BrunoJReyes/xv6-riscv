#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int main(int argc, char *argv)
{
    int *ip = (int *)main;

    *ip = 42;

    printf("No existieron fallos\n");

    exit(0);
}