#ifndef CPU_DOT_H
#define CPU_DOT_H

// for c++ data types values take a look at https://www.tutorialspoint.com/cprogramming/c_data_types.htm and 

/*Define byte and 2 bytes*/
//using Byte = unsigned char; // that is a byte or 8 bits
//using Word = unsigned short; // 2 bytes or 16 bits
/*for c*/
typedef unsigned char Byte;
typedef unsigned short Word;
// For the registers and why I am using a certain amount of bits or bytes take a look at: https://web.archive.org/web/20210501031403/http://www.obelisk.me.uk/6502/registers.html

typedef struct CPU
{
    /*Define Program Counter*/
    Word PC; // program counter which is 16 bit register

    /*Define Stack Pointer*/
    // stack is a small piece of resuable memory for executing you push and pop things of the stack. It is just a small piece of memory that gets reused.
    // https://en.wikipedia.org/wiki/Stack_register
    Word SP;

    /*Define The 3 8bit registers*/
    // since the registers are 8 bit the cpu (6502) is 8 bit
    Byte A, X, Y;

    /*Define the processor status*/
    // the processor status is a 1 byte with a bunch of bits with flags in it that gets set deppending on what instrutions happen (same thing on modern processor with differnt flags and etc.)
    // look at readme image for video 1 for the flags
    // c++ and c supports bitfield
    Byte C : 1; // carry
    Byte Z : 1; // zero
    Byte I : 1; // irq disable
    Byte D : 1; // decimal mode
    Byte B : 1; // break command
    Byte V : 1; // overflow
    Byte N : 1; // negative

    // to reset cpu
    void Reset()
    {
        printf("Hello World\n");
    }

} CPU;

extern CPU cpu;

#endif