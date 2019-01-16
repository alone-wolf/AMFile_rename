#include<iostream>
#include<windows.h>
#include<io.h>
#include<fstream>
#include<conio.h>
#include<string>

//#define DATA_FILE_NAME "download.txt"

//version 1.2

using namespace std;

//import two char set and the function will rename it auto*ly
void rename_part(char source_address_target[],char new_name_target[]){
    if(!_access(source_address_target,0)){
        if(!rename(source_address_target,new_name_target)){
            cout<<"renamed "<<source_address_target<<" to "<<new_name_target<<endl;
        }
    }
}

//trans one string to char set
void string_to_char_set(string source,char target[]){
    strcpy(target,source.c_str());
}

//facing to the two method from file and con
void file_rename(string source_address,string new_name){
    char source_address_target[256];
    char new_name_target[256];
    string_to_char_set(source_address,source_address_target);
    string_to_char_set(new_name,new_name_target);
    rename_part(source_address_target,new_name_target);
}

void fromcon(){
    cout<<"please input the correct format data"<<endl;
    string num,source_address,new_name;
    cin>>num>>source_address>>new_name;
    while(num!="E"){
        file_rename(source_address,new_name);
        cin>>num>>source_address>>new_name;
    }
}

//read data from the file and
void fromfile(char data_filename[]="download.txt"){
    cout<<"data will import from file"<<endl;
    string num="1",source_address,new_name;
    ifstream infile(data_filename,ios::in);
    infile>>num>>source_address>>new_name;
    while(num!="E"){
        infile>>num>>source_address>>new_name;
        file_rename(source_address,new_name);
    }
    infile.close();
}

//just for the user to know how to operate
int main(){
    cout<<"================================================================"<<endl;
    cout<<"chose which method"<<endl;
    cout<<"1.from file"<<endl;
    cout<<"2.input data"<<endl;
    cout<<"any other char to stop"<<endl;
    cout<<"notice: format must be \" num source_address new_name.* \" "<<endl;
    cout<<"and num E means to stop the addition line must be E O F"<<endl;
    cout<<"================================================================"<<endl;
    char a;
    switch(a=getch()-'0'){
        case 1:{
            cout<<"input 1 to define your own file name"<<endl;
            char a=getch()-'0';
            if(a==1){
                cout<<"input you own file name"<<endl;
                string data_file_name;
                cin>>data_file_name;
                char name[256];
                file_rename(data_file_name,name);
                fromfile(name);
            }
            else{
                fromfile();
            }
            break;
        }
        case 2:{
            fromcon();
            break;
        }
        default:{
            exit(0);
        }
    }
}
