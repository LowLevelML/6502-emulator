#ifndef CPU_DOT_H
#define CPU_DOT_H

typedef struct CPU
{

    /*Define Program Counter*/
    u16 PC; // program counter which is 16 bit register

    /*Define Stack Pointer*/
    // stack is a small piece of resuable memory for executing you push and pop things of the stack. It is just a small piece of memory that gets reused.
    // https://en.wikipedia.org/wiki/Stack_register
    u16 SP;

    /*Define The 3 8bit registers*/
    // since the registers are 8 bit the cpu (6502) is 8 bit
    u8 A, X, Y;

    /*Define the processor status*/
    // the processor status is a 1 u8 with a bunch of bits with flags in it that gets set deppending on what instrutions happen (same thing on modern processor with differnt flags and etc.)
    // look at readme image for video 1 for the flags
    // c++ and c supports bitfield
    u8 C : 1; // carry
    u8 Z : 1; // zero
    u8 I : 1; // irq disable
    u8 D : 1; // decimal mode
    u8 B : 1; // break command
    u8 V : 1; // overflow
    u8 N : 1; // negative

    /*Reset CPU*/
    void reset(MEM& memory)
    {
        /*
            what it doess

            ; MOS 6510 System Reset routine[3]
            ; Reset vector (Kernal address $FFFC) points here.
            ; 
            ; If cartridge is detected then cartridge cold start routine is activated.
            ; If no cartridge is detected then I/O and memory are initialised and BASIC cold start routine is activated.

            FCE2   A2 FF      LDX #$FF        ; 
            FCE4   78         SEI             ; set interrupt disable
            FCE5   9A         TXS             ; transfer .X to stack
            FCE6   D8         CLD             ; clear decimal flag
            FCE7   20 02 FD   JSR $FD02       ; check for cart
            FCEA   D0 03      BNE $FCEF       ; .Z=0? then no cart detected
            FCEC   6C 00 80   JMP ($8000)     ; direct to cartridge cold start via vector
            FCEF   8E 16 D0   STX $D016       ; sets bit 5 (MCM) off, bit 3 (38 cols) off
            FCF2   20 A3 FD   JSR $FDA3       ; initialise I/O
            FCF5   20 50 FD   JSR $FD50       ; initialise memory
            FCF8   20 15 FD   JSR $FD15       ; set I/O vectors ($0314..$0333) to kernal defaults
            FCFB   20 5B FF   JSR $FF5B       ; more initialising... mostly set system IRQ to correct value and start
            FCFE   58         CLI             ; clear interrupt flag
            FCFF   6C 00 A0   JMP ($A000)     ; direct to BASIC cold start via vector
        */
        // to reset 
        // just get a cpu to boot that is LIKE commodore 64
        // to make a commodore 64 is another project
        // www.c64-wiki.com/wiki/Reset_(Process)
        // initalize values
        // PC value to reset value
        PC = 0xFFFC;
        // SP sets to 0x00FF
        SP = 0x00FF;
        // clear all flags to zero
        C = Z = I = D = B = V = N = 0;
        // registers to 0
        A = X = Y = 0;
        // initalize memory
        memory.initialize();
    }

    u8 fetchByte(u32& cycles, MEM& memory)
    {
       u8 data = memory[PC];
       PC++;
       cycles--;
       return data;
    }

    // opcodes
    // instruction load accumaltor immediate mode
    // this according to https://web.archive.org/web/20210501043555/http://www.obelisk.me.uk/6502/reference.html#LDA as an op code of $A9 = 0xA9
    // Loads a byte of memory into the accumulator setting the zero and negative flags as appropriate.
    static constexpr u8 INS_LDA_IM = 0xA9;

    void execute(u32 cycles, MEM& memory)
    {
        // to execute read more in https://web.archive.org/web/20210514033221/http://obelisk.me.uk/6502/instructions.html

        /*load accumaltor*/
        // https://web.archive.org/web/20210501043555/http://www.obelisk.me.uk/6502/reference.html#LDA
        // fetches  bytes, and fetches instructions and decrement cycles to stop executing
        while (cycles > 0)
        {
            u8 ins = fetchByte(cycles, memory); // ins = instruction
            switch(ins)
            {
                case INS_LDA_IM:
                {
                    // Loads a byte of memory into the accumulator setting the zero and negative flags as appropriate.
                    // get another byte and store it in value
                    u8 value = fetchByte(cycles, memory);
                    // set the A register with the value
                    A = value;
                    // set the 0 and negative flags as appopriate as show here
                    // set Z = 1 if A = 0
                    // smaller c code
                    // Z = (A == 0)
                    if (A == 0)
                    {
                        Z = 1;
                    }
                    else
                    {
                        Z = 0;
                    }
                    // set if bit 7 of A is set
                    // 0b... is the symbol for binary
                    // smaller c code
                    // N = (A & 0b10000000) > 0
                    // testing if A : 7 > 0 -> fails
                    if (A & 0b10000000 > 0)
                    {
                        N = 1;
                    }
                    else
                    {
                        N = 0;
                    }
                } 
                break;
            }
        }
    }

} CPU;

extern CPU cpu;

#endif