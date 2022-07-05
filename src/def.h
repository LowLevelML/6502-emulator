#ifndef DEFBITS_DOT_H
#define DEFBITS_DOT_H

// for c++ data types values take a look at https://www.tutorialspoint.com/cprogramming/c_data_types.htm and 

/*Define byte and 2 bytes*/
//using Byte = unsigned char; // that is a byte or 8 bits
// using uint8_t for platform agnostic
//using Word = unsigned short; // 2 bytes or 16 bits
/*for c*/
// using uint16_t for platform agnostic
typedef uint8_t Byte;
typedef uint16_t Word;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
// For the registers and why I am using a certain amount of bits or bytes take a look at: https://web.archive.org/web/20210501031403/http://www.obelisk.me.uk/6502/registers.html

#endif