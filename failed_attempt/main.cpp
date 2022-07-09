#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <byteswap.h>
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

    // start - testing little program by hardcoding
    // 0xFFFC as that is where we are going to start executing memory I think mentioned here https://www.c64-wiki.com/wiki/Reset_(Process) or in the 6502 booklet previous page
    mem[0xFFFC] = CPU::INS_LDA_ZP;
    mem[0xFFFC] = 0x42; // in decimel it is 66
    mem[0x0042] = 0x84; // take value 84 and put into the accumaltor
    /*
    current output: 
    Error: Instruction not handled or present. Instruction in decimel: 66 or in hex: 42
    Error: Instruction not handled or present. Instruction in decimel: 0 or in hex: 0
    */
    // end - testing little program

    cpu.execute(3, mem);

    return 0;
}
