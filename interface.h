// 实现一个简单的汇编器
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "struct.h"

using namespace std;

/*
函数功能：初始化自定义汇编指令集
params：assIns传入字符型向量存储指令集
使用方法：创建新的向量传入即可对向量进行赋值
*/
void InitAssembleInstructions(vector<string>& assIns);

/*
函数功能：初始化指令是否带参数
params：insArgNum传入一个map存储枚举类型作为键，int类型为是否含参。 
使用方法：创建一个map对象传入即可
*/
void InitInstrctionArgNumber(map<BinIns, int>& insArgNum);

/*
函数功能：建立指令和其二进制对应的关系
params：assIns为初始化的指令集，assToBin为指令次序
使用方法：传入初始化后的assIns并创建新的map
*/
void InitAssembleToBinary(const vector<string>& assIns, map<string, BinIns>& assToBin);

/*
函数功能：读取用户输入的指令
params：ass为一个string类型空的vector
使用方法：创建vectoer传入即可
*/
void ReadAssemble(vector<string>& ass);

/*
函数功能：打印用户输入
params：ass为之前存储用户输入的vector
使用方法：传入存储用户输入的vector即可
*/
void Display(const vector<string>& ass);

/*
函数功能：字母转义大小写
params：str传入str
使用方法：函数内部调用
*/
string StringToUpper(const string& str);

/*
函数功能：汇编转机器码
params：ass用户输入 bin枚举类型 assToBin存储的映射关系 insArgNum是否带参 
使用方法：传入以上参数即可
*/
void AssembleToBinary(const vector<string>& ass,
                      vector<Instruction>& bin,
                      const map<string, BinIns>& assToBin,
                      map<BinIns, int>& insArgNum,
                      vector<string>& order);

/*
函数功能：将数字转换为string类型
params：n为数字 sizeofbytes为字节数
使用方法：函数掉用
*/
string IntToString(int n, int sizeofbytes);

/*
函数功能：
params:
使用方法：
*/
void OutputBinary(const vector<Instruction>& bin,
                  const map<BinIns, int>& insArgNum,
                  vector<string>& order);

/*
函数功能：汇编器的执行函数
params:无
使用方法：调用即可
*/
void assembler();

/*
函数功能：初始化二进制到指令集的映射
params：assIns为输入的二进制，binToIns
使用方法：调用即可
*/
void InitBinaryToAssemble(const vector<string>& assIns, map<BinIns, string>& binToIns);

/*
函数功能：读取用户输入
params：bin为存储用户的输入
使用方法：传入bin即可
*/
void ReadBinary(vector<string>& bin);

/*
函数功能：反汇编核心代码
params：bin传入指令 ass为存储指令集 binToIns为指令映射 insArgNum为是否含参 order 存储指令
使用方法：调用即可
*/
void BinaryToAssemble(const vector<string>& bin,
                      vector<string>& ass,
                      const map<BinIns, string>& binToIns,
                      map<BinIns, int>& insArgNum,
                      vector<string>& order);

/*
函数功能：将二进制字符串转换为十进制字符串
params：str为二进制字符
使用方法：传入二进制字符
*/
string StringToNum(const string& str);

/*
函数功能：将二进制转换为十进制
params：bin用户输入的vector
使用方法：传入bin即可
*/
void BinaryToDec(vector<string>& bin);

/*
函数功能：反汇编执行程序
params:
使用方法：直接调用
*/
int disassemble();

/*
函数功能：打印函数
params:
使用方法：直接调用
*/
void OutputAssemble(const vector<string>& bar,vector<string> &order);


