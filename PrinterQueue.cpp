#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
void printer(string device , string file){
       string sdevice = "\\\\localhost\\"+device;
       system(string("net use LPT1: ") + sdevice); 
       system(string("print /D:LPT1 ") + file);
}
int main (){ 
    
   string device,file;
   char ch ='y';
   string word;
   int flag = 0;
   while(ch =="y"){
        system(string("wmic printer list brief"));
        cout<<"\n Enter the name of the printer";
        cin>>device;
        system(string("lpstat -p "+device+"> pstat.txt"));
        ifstream fin;
        fin.open("pstat.txt")
        while(fin >> word ){
           if(strcmp("available",word) == 0)
                  flag =1;
        }
        if (flag == 1){
               cout<<"\n Enter file path";
               cin>>file;
               printer(device,file);
        }
        else{
               string file1;
               cout<<"\nThe entered printer is Unavailabe. Please enter details the below to pushed into the queue";
               cout<<"\n Enter file path";
               cin>>file1;
               while(flag =0){
                     system(string("lpstat -p "+"device > pstat.txt"));
                     fin.skeeg(0,ios:beg);
                     while(fin >> word ){
                         if(strcmp("available",word) == 0)
                             flag =1;
                     }
               }
               printer(device,file1);
             }
      cout<<"\n Do you want to continue (y/n)";
      cin>>ch;
    }
   fin.close();
   return 0;
 } 
                          

