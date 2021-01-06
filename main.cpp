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
        cout<<"which you wannna run 1:assembler 2:disassemble 0 exit"<<endl; 
        string select=" ";
        cin>>select;
        if(select=="1"){
            cout<<"Please input the assembly instruction !(Such as: in,out... end with #) "<<endl;
            assembler();
        }
        else if(select=="2"){
            cout<<"Please input the machine instruction!(Such as: 1,7...  end with #)"<<endl;
            disassemble();
        }else if(select=="0"){
            flag=0;
        }
    }
    return 0;
}
