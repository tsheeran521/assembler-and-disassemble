#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "base.h"
using namespace std;
int main()
{   
    int flag=1;
    while(flag){
        cout<<"This project have 31 orders."<<endl;
        cout<<"which you wannna run 1:assembler 2:disassemble 0 exit"<<endl; 
        string select=" ";
        cin>>select;
        if(select=="1"){
            cout<<"Please input the assembly instruction !(Such as: in,out... end with #) "<<endl;
            cout<<"Halt,In,Out,Add,Sub without operand"<<endl;
            cout<<"And,Or,Xor,Not,Shl,Sal with operand"<<endl;
            assembler();
        }
        else if(select=="2"){
            cout<<"Please input the machine instruction!(Such as: 1,7...  end with #)"<<endl;
            cout<<"0-9 without operands ,10-30 with a operand"<<endl;
            disassemble();
        }else if(select=="0"){
            flag=0;
        }
    }
    return 0;
}
