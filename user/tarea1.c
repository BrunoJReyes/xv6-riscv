#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int p = atoi(argv[1]);
    int ancestor = getancestor(p);
    getppid();
    printf("%d\n", ancestor);
    return 0;
}