#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string openName="tmp";
string saveName;

void filer();
void openFile();
void insert();
void edit();
void del();
void saver();
void exiter();
void show();

int main(){
filer();
return 0;
}

void filer(){
//    cout<<"Open | New File = "<<endl;
//    getline(cin,fileName);
//    ofstream file1(openName.c_str(),ios::out);
int act;
    while(1){
        system("cls");
        cout<<"\""<<openName<<"\""<<endl;
        cout<<"\n"<<endl;
        show();
        cout<<"______________________________________________________"<<endl;
        cout<<"0:open 1:insert 2:edit 3:delete 4:save 5:exit"<<endl;
        /* cout<<"0 -> open | new  file"<<endl;
        cout<<"1 -> insert txt line"<<endl;
        cout<<"2 -> edit file"<<endl;
        cout<<"3 -> delete txt"<<endl;
        cout<<"4 -> save file"<<endl;
        cout<<"5 -> exit"<<endl;
        cout<<"6 -> show file"<<endl; */
        cout<<"______________________________________________________"<<endl;
        cout<<"command => ";
        cin>>act;
        switch (act){
            case 0:
                openFile();
                break;
            case 1:
                insert();
                break;
            case 2:
                edit();
                break;
            case 3:
                del();
                break;
            case 4:
                saver();
                break;
            case 5:
                exiter();
                break;
            default:
                act=1;
                break;
            
        }
    }
}

void openFile(){
    //___
    cin.get();
    string word;
    cout<<"Open | New File = ";
    getline(cin,openName);
    ifstream file1(openName.c_str(),ios::in);
}

void insert(){
cin.get();
cout<<"\ntype ^ to exit insert mode\n";
cout<<"=> ";
ofstream file1(openName.c_str(),ios::app);
char str;
do {
    cin.get(str);
    if (str=='^') break;
    if(str=='\n') file1<<endl;
    file1<<str;
}while(1);
}

void edit(){
    cout<<"in progress\n";
    cin.get();
    cin.get();
}

void del(){
    cout<<"in progress\n";
    cin.get();
    cin.get();
}

void saver(){
    cin.get();
    int flag;
    cout<<"1 -> save\n2 -> save as\n";
    cin>>flag;
    switch (flag){
        case 1:
            if(openName=="tmp") ofstream file1(openName.c_str(),ios::out);
            break;
        case 2:
            cin.get();
            string word;
            cout<<"Save As = ";
            getline(cin,saveName);
            ifstream file1;
            file1.open(openName.c_str(),ios::in);
            ofstream file2(saveName.c_str(),ios::out);
            while(file1 >> word)
            {
            file2<<word<<" ";
            }
            file1.close();
            file2.close();
            openName=saveName;
            break;
    }
    
}

void exiter(){
    char boolean;
    cout<<"Do you Want to Save "<<openName<<" (y/n)?";
    cin>>boolean;
    if(boolean=='y') {
        saver();
        exit(1);
    }
    else {
        exit(1);
    }
}

void show(){
    string line;
    ifstream file1(openName.c_str(),ios::in);
    while (getline(file1,line)){
        cout<<line<<'\n';
    }
    // cin.get();
    // cin.get();
}