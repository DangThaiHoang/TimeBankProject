#ifndef _BLOCKMEM_H_
#define _BLOCKMEM_H_

#include <iostream>
#include <string>

using std::string;

class BlockMem{
public:
        string blockedMem;
        string MemBlock;

        //Constuctor
        BlockMem(string blockedMem = "", string MemBlock = "");
};

#endif