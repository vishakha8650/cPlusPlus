#include<iostream>
#include<fstream>
using namespace std;
class info{
    private:
        string name,id;
        long long no;
    public:
        void get_data();
        void show_data();
}i;
void info::get_data(){
    cout<<"Enter Name : ";
    cin.ignore();
    getline(cin,name);
    cout<<"\n Enter Email ID:";
    cin.ignore();
    getline(cin, id);
    cout<<"Enter your no:";
    cin>>no;
}
void info::show_data(){
    cout<<"Name = "<<name<<endl;
    cout<<"Email Id= "<<id<<endl;
    cout<<"No="<<no<<endl;
}
void add(){
    ofstream myfile("useless.txt",ios::app|ios::out);
    myfile<<i.get_data();
    myfile.close();
}
void display(){
    ifstream file1 ("useless.txt",ios::in);
    if(file1.is_open()){
        cout << "The data is as follows:" ;
        string line;
        while(getline(file1,line)){
            cout<<line<<endl;
        }
    }
    
    file1.close();
}
int main(){
    int ch;
    while(1){
        cout<<"1.To add new data:"<<endl;
        cout<<"2.To show data:"<<endl;
        cout<<"0.To end:"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch) {
            case 1:add();break;
            case 2:display();break;
            case 3:exit(1);break;
        }
    }
    return 0;
}