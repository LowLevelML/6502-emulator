#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// file imports
// this is where the Byte and word stays
#include "./def.h"
// memory
#include "./mem.h"
// cpu
#include "./cpu.h"
// struct def
struct CPU cpu;
struct MEM mem;

int main()
{
    // make our cpu
    // now our cpu cant do anything withotu memory because it needs the SP to point to somewhere and it needs the lot of page need the zero page. to execute anything you need zero page and stackpointer.
    // first lets reset cpu
    // also set memory to 0
    cpu.reset(mem);
    // execute
    cpu.execute(2, mem);

    return 0;
}
