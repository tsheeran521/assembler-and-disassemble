enum BinIns
{
    binHalt, binIn, binOut, binAdd, binSub, binMul, binDiv,
    binDup,
    binLd, binSt, binLdc, binJlt, binJle, binJgt, binJge, binJeq, binJne, binJmp,
    binInvalid
};

// 二进制指令结构体
// 指令码+操作数
struct Instruction
{
    BinIns op;  // 指令码只占一个字节
    int    arg; // 操作数，占四个字节
};
