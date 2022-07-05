#include <stdio.h>
#include <stdlib.h>
// file imports
#include "./include/cpu.h"
// struct def
struct CPU cpu;

int main()
{
    // make our cpu
    // now our cpu cant do anything withotu memory because it needs the SP to point to somewhere and it needs the lot of page need the zero page. to execute anything you need zero page and stackpointer.
    // reset cpu
    cpu.Reset();
    return 0;
}
