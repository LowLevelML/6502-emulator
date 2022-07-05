#ifndef MEM_DOT_H
#define MEM_DOT_H

typedef struct MEM
{

    // get some memory
    static constexpr u32 MAX_MEM = 1024 * 64;
    u8 data[MAX_MEM];
    
    void initialize()
    {
        for (u32 i = 0; i < MAX_MEM; i++)
        {
            data[i] = 0;
        }
    }

    // read 1 byte
    u8 operator[](u32 address) const
    {
        // asset here address is < MAX_MEM
        return data[address];
    }

    // write 1 byte
    u8& operator[](u32 address)
    {
        // asset here address is < MAX_MEM
        return data[address];
    }

} MEM;

extern MEM mem;

#endif