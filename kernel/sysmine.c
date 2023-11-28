#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "syscall.h"
#include "defs.h"

// Obtiene el id del padre del proceso actual
int getppid()
{
    struct proc *my_proc = myproc();
    return my_proc->parent->pid;
}

// Obtiene el ancestro del proceso actual en la posición "a"
int getancestor(int a)
{
    struct proc *p = myproc();
    int pid = (a == 0) ? p->pid : -1; // Si "a" es cero, devuelve el PID del proceso actual

    // Itera hacia arriba en la jerarquía del proceso hasta el ancestro en la posición "a"
    while (p != 0 && a > 0)
    {
        p = p->parent;
        a--;
    }

    // Si se encontro el ancestro en la posicion "a", actualiza el PID
    pid = (p != 0) ? p->pid : pid;

    return pid;
}

// Llamada al sistema para obtener el ID del padre
int sys_getppid()
{
    return getppid();
}

// Llamada al sistema para obtener el ancestro en la posición "a"
int sys_getancestor()
{
    int g;
    argint(0, &g);
    return getancestor(g);
}
