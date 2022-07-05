#ifndef MEM_DOT_H
#define MEM_DOT_H

typedef struct MEM
{

    // get some memory
    static constexpr u32 MAX_MEM = 1024 * 64;
    u8 Data[MAX_MEM];
    
    void initialize()
    {
        for (u32 i = 0; i < MAX_MEM; i++)
        {
            Data[i] = 0;
        }
    }

} MEM;

extern MEM mem;

#endif