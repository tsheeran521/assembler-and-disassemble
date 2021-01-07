#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "interface.h"
using namespace std;
void InitAssembleInstructions(vector<string>& assIns)
{
    assIns.clear();
    assIns.push_back("HALT");
    assIns.push_back("IN");
    assIns.push_back("OUT");
    assIns.push_back("ADD");
    assIns.push_back("SUB");
    assIns.push_back("MUL");
    assIns.push_back("DIV");
    assIns.push_back("DUP");
    assIns.push_back("LD");
    assIns.push_back("ST");
    assIns.push_back("LDC");
    assIns.push_back("JLT");
    assIns.push_back("JLE");
    assIns.push_back("JGT");
    assIns.push_back("JGE");
    assIns.push_back("JEQ");
    assIns.push_back("JNE");
    assIns.push_back("JMP");
    assIns.push_back("AND");
    assIns.push_back("OR");
    assIns.push_back("XOR");
    assIns.push_back("NOT");
    assIns.push_back("SHL");
    assIns.push_back("SAL");
    assIns.push_back("SHR");
    assIns.push_back("SAR");
    assIns.push_back("ROL");
    assIns.push_back("ROR");
    assIns.push_back("RCL");
    assIns.push_back("RCR");
    assIns.push_back("LODS");
}

void InitInstrctionArgNumber(map<BinIns, int>& insArgNum)
{
    insArgNum.clear();
    insArgNum[binHalt] = 0;
    insArgNum[binIn]   = 0;
    insArgNum[binOut]  = 0;
    insArgNum[binAdd]  = 0;
    insArgNum[binSub]  = 0;
    insArgNum[binMul]  = 0;
    insArgNum[binDiv]  = 0;
    insArgNum[binDup]  = 0;
    insArgNum[binLd]   = 0;
    insArgNum[binSt]   = 0;
    insArgNum[binLdc]  = 1;
    insArgNum[binJlt]  = 1;
    insArgNum[binJle]  = 1;
    insArgNum[binJgt]  = 1;
    insArgNum[binJge]  = 1;
    insArgNum[binJeq]  = 1;
    insArgNum[binJne]  = 1;
    insArgNum[binJmp]  = 1;
    insArgNum[binAnd]  = 1;
    insArgNum[binOr]   = 1;
    insArgNum[binXor]  = 1;
    insArgNum[binNot]  = 1;
    insArgNum[binShl]  = 1;
    insArgNum[binSal]  = 1;
    insArgNum[binShr]  = 1;
    insArgNum[binSar]  = 1;
    insArgNum[binRol]  = 1;
    insArgNum[binRor]  = 1;
    insArgNum[binRcl]  = 1;
    insArgNum[binRcr]  = 1;
    insArgNum[binLods]  = 1;
    insArgNum[binInvalid] = 1;
}

void InitAssembleToBinary(const vector<string>& assIns, map<string, BinIns>& assToBin)
{
    assToBin.clear();
    for (auto i = 0; i != assIns.size(); ++i)
    {
        // assIns和BinIns的指令次序一致
        assToBin[assIns[i]] = static_cast<BinIns>(i);
    }
}

void ReadAssemble(vector<string>& ass)
{
    ass.clear();
    string line;
    while (getline(cin, line)&&line!="#")
    {
        ass.push_back(line);
    }
}

void Display(const vector<string>& bar)
{
    for (auto i = 0; i != bar.size(); ++i)
    {
        cout << bar[i] << endl;
    }
}

string StringToUpper(const string& str)
{
    string ret;
    for (auto i = 0; i != str.size(); ++i)
    {
        ret += toupper(str[i]);
    }
    return ret;
}

void AssembleToBinary(const vector<string>& ass,
                      vector<Instruction>& bin,
                      const map<string, BinIns>& assToBin,
                      map<BinIns, int>& insArgNum,
                      vector<string>& order)
{
    string assline;
    // 将ass汇总
    for (auto i = 0; i != ass.size(); ++i)
    {
        assline += StringToUpper(ass[i]) + '\t';
    }

    istringstream sin(assline);
    string strOp, strArg;
    Instruction ins;
    BinIns op;
    int    arg;
    while (sin >> strOp)
    {
        order.push_back(strOp);
        auto cit = assToBin.find(strOp);
        if (cit == assToBin.end())
        {
            cout<<"the order "<<strOp<<" is not in the list!"<<endl;
            // 没有找到对应的指令码
            // 忽略处理
            ;
            break;
        }
        op = cit->second;
        // insArgNum为非const型
        // assToBin const型保障了insArgNum[]不会存在更新的情况
        int argNum = insArgNum[op];
        if (argNum > 0)
        {
            sin >> strArg;
            arg = atoi(strArg.c_str());
        }
        else
        {
            arg = 0;
        }
        ins.op = op;
        ins.arg = arg;
        bin.push_back(ins);
    }
}

string IntToString(int n, int sizeofbytes)
{
    string ret;
    ret.resize(sizeofbytes * 8, '0');
    for (int i = ret.size() - 1; i >= 0 && n != 0; --i, n /= 2)
    {
        ret[i] = n % 2 + '0';
    }
    return ret;
}

void OutputBinary(const vector<Instruction>& bin,
                  const map<BinIns, int>& insArgNum,
                  vector<string> &order)
{
    for (auto i = 0; i != bin.size(); ++i)
    {
        cout<<order[i]<<"  ";
        cout << bin[i].op;
        cout << '\t' << IntToString(bin[i].op, 1);
        auto cit = insArgNum.find(bin[i].op);
        if (cit == insArgNum.end())
        {
            // 如果没有找到
            // 不做处理
            ;
            break;
        }
        if (cit->second > 0)
        {
            cout << '\t' << bin[i].arg;
            cout << '\t' << IntToString(bin[i].arg, 4);
        }
        cout << endl;
    }
}

void assembler()
{
    // 汇编指令集
    vector<string> assIns;
    InitAssembleInstructions(assIns);

    // 二进制指令-操作数个数
    map<BinIns, int> insArgNum;
    InitInstrctionArgNumber(insArgNum);

    // 汇编指令到二进制的映射
    map<string, BinIns> assToBin;
    InitAssembleToBinary(assIns, assToBin);

    vector<string> ass; // 保持读入的汇编指令
    ReadAssemble(ass);
    cout << endl;
    vector<Instruction> bin; // 保存二进制指令
    vector<string> order;
    AssembleToBinary(ass, bin, assToBin, insArgNum,order);

    OutputBinary(bin, insArgNum,order);

    cout << endl;

    //return 0;
}

void InitBinaryToAssemble(const vector<string>& assIns, map<BinIns, string>& binToIns)
{
    binToIns.clear();
    for (auto i = 0; i != assIns.size(); ++i)
    {
        // assIns和BinIns的指令次序一致
        binToIns[static_cast<BinIns>(i)] = assIns[i];
    }
}

void ReadBinary(vector<string>& bin)
{
    bin.clear();
    string line;
    while (getline(cin, line)&&line!="#")
    {
        bin.push_back(line);
    }
}

void OutputAssemble(const vector<string>& bar,vector<string> &order){
     for (auto i = 0; i != bar.size(); ++i)
    {
        cout<<order[i]<<"  ";
        cout << bar[i] << endl;
    }
}

void BinaryToAssemble(const vector<string>& bin,
                      vector<string>& ass,
                      const map<BinIns, string>& binToIns,
                      map<BinIns, int>& insArgNum,
                      vector<string>& order)
{
    ass.clear();
    string binLine;
    for (auto i = 0; i != bin.size(); ++i)
    {
        binLine += bin[i] + '\t';
    }
    
    istringstream sin(binLine);
    string strOp, strArg;
    string op;
    string arg;
    string assIns;
    BinIns opBin;
    while (sin >> strOp)
    {
        order.push_back(strOp);
        opBin = static_cast<BinIns>(atoi(strOp.c_str()));
        auto cit = binToIns.find(opBin);
        if (cit == binToIns.end())
        {
            cout<<"the order: "<<strOp<<" is not in the list!"<<endl;
            // 非法二进制指令
            // 忽略处理
            ;
            break;
        }
        op = cit->second;
        int argNum = insArgNum[cit->first];
        if (argNum > 0)
        {
            sin >> strArg;
            arg = strArg;
        }
        else
        {
            arg = "";
        }
        assIns = op + '\t' + arg;
        ass.push_back(assIns);
    }
}

string StringToNum(const string& str)
{
    string ret;
    int num = 0;
    for (auto i = 0; i != str.size(); ++i)
    {
        num = num * 2 + str[i] - '0';
    }
    char tmp[101];
    itoa(num, tmp, 10);
    ret = tmp;
    return ret;
}

void BinaryToDec(vector<string>& bin)
{
    for(auto i = 0; i != bin.size(); ++i)
    {
        istringstream sin(bin[i]);
        string tmp, ins;
        while (sin >> tmp)
        {
            ins += StringToNum(tmp) + '\t';
        }
        bin[i] = ins;
    }
}

void disassemble()
{
    // 汇编指令集
    vector<string> assIns;
    InitAssembleInstructions(assIns);

    // 二进制指令-操作数个数
    map<BinIns, int> insArgNum;
    InitInstrctionArgNumber(insArgNum);

    // 汇编指令到二进制的映射
    map<BinIns, string> binToAss;
    InitBinaryToAssemble(assIns, binToAss);

    vector<string> bin; // 保存读入的二进制指令
    ReadBinary(bin);
    cout << endl;
    vector<string> ass; // 保存转换后的汇编指令
    vector<string> order;
    BinaryToAssemble(bin, ass, binToAss, insArgNum,order);
    OutputAssemble(ass,order);
    cout << endl;
}

