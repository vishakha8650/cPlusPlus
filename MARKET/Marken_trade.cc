#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<cstdlib>
#include<cmath>
#include "mobile.hh"
#include<windows.h>
using namespace std;
void superadmin(string name,string pass);
class info{
    private:
       string name,id;
       long long no;
    public:
       void get_data1();
       void show_data1();
}i;
class model{
    private:
       string mode,processor,battery,feature;
       int price,storage,ram,os,m_no;
    public:
        void get_data2();
        void show_data2();
        int model1(){
            return m_no;
        }
        float pric(){
            return price;
        }
        void show_list();
}m;
class purchase{
    private:
        string address,state,name;
        int pin;
        char gender;
    public:
        void get_data3();
        void show_data3();
}p;
class admin{
    private:
        string name,pass;
        long long no;
    public:
        void get_data4();
        void show_data4();
        string ad_name(){
            return name;
        }
        string ad_pass(){
            return pass;
        }
        int no1(){
            return no;
        }
}a;
class check_out{
    private:
       string items;
       float price;
    public:
       void getdata5(float pr,string model);
       void showdata5();
}c;
/*=======================================================================================================*/
void info::get_data1(){
    system("Color 0D");
    cout<<"***********INFO********"<<endl;
    cout<<"=========================="<<endl;
    cout<<"Enter your good name:";
    cin>>name;
    cout<<"Enter your E-mail ID:";
    cin>>id;
    cout<<"Enter your Mobile No:";
    cin>>no;
}
void info::show_data1(){
    system("Color 09");
    cout<<endl<<"############################################################"<<endl;
    cout<<"NAME: "<<name<<"\t\t\tMOBILE NO: "<<no<<endl;
    cout<<"E-MAIL ID: "<<id<<endl; 
    cout<<"############################################################"<<endl;
    cout<<endl;
}
void visit_info(){
    ofstream myfile1("visit_info.dat",ios::binary|ios::app|ios::out);
    if(myfile1.is_open()){
        i.get_data1();
        myfile1.write((char*)&i,sizeof(i));
    }
    else{
        cerr<<"-----------ERROR---------"<<endl;
    }
    myfile1.close();
}
void display_visit(){
    system("Color 0E");
    ifstream myfile("visit_info.dat",ios::binary|ios::in);
    while(myfile.read((char*)&i,sizeof(i))){
        i.show_data1();
    }
    myfile.close();
}

/*=======================================================================================================*/
void model::get_data2(){
    system("Color 0D");
    cout<<endl<<"***********WORKING ON MODELS*********"<<endl;
    cout<<"================================================"<<endl;
    cout<<"Enter Name and Model: ";getline(cin>>ws,mode);
    cout<<"Enter the Model No:";cin>>m_no;
    cout<<"Enter processor name: ";getline(cin>>ws,processor);
    cout<<"Enter battery strength: ";getline(cin>>ws,battery);
    cout<<"Enter the price of given model:";cin>>price;
    cout<<"Enter the storage : ";cin>>storage;
    cout<<"Enter the ram of this given model: ";cin>>ram;
    cout<<"Enter the version of operating system: ";cin>>os;
    cin.ignore();
    cout<<"Enter the extra features about model:";getline(cin>>ws,feature);
    cout<<"========================================================="<<endl;
}
void model::show_data2(){
    system("Color 09");
    cout<<endl<<"****************************************************************"<<endl;
    cout<<"---------------------------------BRINGING THE CHANGE----------------------------------------"<<endl;
    cout<<"Model: "<<setw(20)<<mode<<"\t\t\tPrice: "<<setw(5)<<price<<endl;
    cout<<"processor: "<<setw(10)<<processor<<"\t\t\tBattery:"<<setw(10)<<battery<<endl;
    cout<<"Storage: "<<setw(5)<<storage<<"\t\t\tRam: "<<setw(5)<<ram<<endl;
    cout<<"Operating system in given Android: "<<os<<"\t\t\tModel no:"<<m_no<<endl;
    cout<<"Presenting Some Mind Blowing Features: "<<feature<<endl;
    cout<<"--------------------------------------------------------------------------------------------------"<<endl;
}

void add_model(){
    ofstream myfile("mobile.dat",ios::binary|ios::app|ios::out);
    if(myfile.is_open()){
        m.get_data2();
        myfile.write((char*)&m,sizeof(m));
    }
    else{
        cerr<<"--------------ERROR----------------"<<endl;
    }
    myfile.close();
}
void model::show_list(){
    cout<<"``````````````RECIPT`````````````"<<endl;
    cout<<"MODEL NO: "<<setw(10)<<m_no<<"\t\t\tPrice: "<<price<<endl;
}
float search_model(){
    int no,count=0,ch;
    cout<<"Enter the model NO:";
    cin>>no;
    ifstream myfile("mobile.dat",ios::binary|ios::in);
    ofstream myfile2("personal.dat",ios::binary|ios::app|ios::out);
    while(myfile.read((char*)&m,sizeof(m))){
        if(no==m.model1()){
            m.show_data2();
            count++;
            cout<<"Data found successfully....."<<endl;
            cout<<"For yes press 1:"<<endl;
            cout<<"Do you want to add this item in your cart?";
            cin>>ch;
            if(ch==1){
                m.show_list();
                myfile2.write((char*)&m,sizeof(m));
                return m.pric();   
            }
        }
    }
    myfile.close();
    if(count==0){
        cout<<"No such data found...."<<endl;
        return 0;
    }

}
void display_model(){
    system("Color 0E");
    ifstream myfile("models.dat",ios::binary|ios::in);
    if(myfile.is_open()){
        while(!myfile.eof()){
            m.show_data2();
            myfile.read((char*)&m,sizeof(m));
        }
    }
    system("pause");
    myfile.close();
}
/*=======================================================================================================*/
void purchase::get_data3(){
    system("Color 0D");
    cout<<"**********Enter the addresss*********"<<endl;
    cout<<"Enter your full name:";getline(cin>>ws,name);
    cout<<"Enter your address:";getline(cin>>ws,address);
    cout<<"Enter the state:";getline(cin>>ws,state);
    cout<<"Enter pin code:";cin>>pin;
    cout<<"Enter your gender:";cin>>gender;
    cout<<endl<<"-------------------------------------------"<<endl;
}
void purchase::show_data3(){
    system("Color 09");
    cout<<endl<<"****************Details**************"<<endl;
    cout<<"Full Name: "<<setw(20)<<name<<"\t\t\tGender: "<<gender<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"State: "<<setw(20)<<state<<"\t\t\tPin Code: "<<pin<<endl;
    cout<<"****************************************"<<endl;
}
void display_purchase(){
    ifstream myfile("purchase.dat",ios::binary|ios::in);
    while(myfile.read((char*)&p,sizeof(p))){
        p.show_data3();
    }
    myfile.close();
}
/*=======================================================================================================*/
/*=======================================================================================================*/
void admin::get_data4(){
    system("Color 0D");
    cout<<endl<<"===========SECREAT=========="<<endl;
    cout<<"Enter your username:";cin>>name;
    cout<<"Enter your password:";cin>>pass;
    cout<<"Enter your mobile no:";cin>>no;
    cout<<"==================================="<<endl;
}
void admin::show_data4(){
    system("Color 09");
    cout<<endl<<"--------------------------------------------------"<<endl;
    cout<<"Username -> "<<setw(20)<<name<<"\t\t\tPassword -> "<<pass<<endl;
    cout<<"Mobile no -> "<<no;
    cout<<endl;
}
void add_admin(){
    ofstream myfile("admin.dat",ios::binary|ios::app|ios::out);
    a.get_data4();
    myfile.write((char*)&a,sizeof(a));
    myfile.close();
}
void display_admin(){
    system("Color 0E");
    ifstream myfile("admin.dat",ios::binary|ios::in);
    while(myfile.read((char*)&a,sizeof(a))){
        a.show_data4();
    }
    system("pause");
    myfile.close();
}
int check_admin(){
    string user,password;
    int count=0;
    cout<<"Enter Username:";
    cin>>user;
    cout<<"Enter Password:";
    cin>>password;
    string str1,str2;
    ifstream myfile("admin.dat",ios::binary|ios::in);
    superadmin(user,password);
    while(myfile.read((char*)&a,sizeof(a))){
        str1=a.ad_name();
        str2=a.ad_pass();
        if(strcmp(user.c_str(),str1.c_str())==0 && strcmp(password.c_str(),str2.c_str())==0){
            cout<<"Login successfully:"<<endl;
            count++;
            return true;
        }
        else if(strcmp(user.c_str(),"vishakha")==0 && strcmp(password.c_str(),"pear123")==0){
            cout<<"Login successfully:"<<endl;
            count++;
            return true;   
        }
    }
    if(count==0){
        cout<<"Login failed......"<<endl;
        return false;
    }
}
void modify_admin(){
    long long no;
    int pos,count=0;
    fstream myfile("admin.dat",ios::binary|ios::in|ios::out);
    cout<<"Enter the no. of the data you want to modify:";
    cin>>no;
    while(myfile.read((char*)&a,sizeof(a))){
        pos=myfile.tellg();
        if(no==a.no1()){
            cout<<"The previous data:"<<endl;
            a.show_data4();
            cout<<"Enter New details:"<<endl;
            a.get_data4();
            myfile.seekg(pos-sizeof(a));
            myfile.write((char*)&a,sizeof(a));
            count++;
        }
    }
    if(count==0){
        cout<<"The given no. is invalid"<<endl;
    }
    myfile.close();
}
void delete_admin(){
    long long no;
    int count=0;
    cout<<"Enter the mobile no. of data you wanna delete:";
    cin>>no;
    ifstream myfile1("admin.dat",ios::binary|ios::in);
    ofstream myfile2("old_user.dat",ios::binary|ios::out|ios::app);
    ofstream myfile3("original.dat",ios::binary|ios::out|ios::app);
    if(myfile1.is_open()){
        while(myfile1.read((char*)&a,sizeof(a))){
            if(no==a.no1()){
                cout<<"The following data has been removed:"<<endl;
                a.show_data4();
                myfile2.write((char*)&a,sizeof(a));
                count++;
            }
            else{
                myfile3.write((char*)&a,sizeof(a));
            }
        }
    }
    else{
        cerr<<endl<<"-------------Error-----------"<<endl;
    }
    myfile1.close();
    myfile2.close();
    myfile3.close();
    if(count==0){
        cout<<"The following No. is not found"<<endl;
    }
    remove("admin.dat");
    rename ("original.dat","admin.dat");
}
/*=======================================================================================================*/
void check_out::getdata5(float pr,string model){
    system("Color 0D");
    items=model;
    price=pr;
}
void check_out::showdata5(){
    system("Color 09");
    cout<<items<<": Rs."<<price<<endl;
}
/*=======================================================================================================*/
void superadmin(string name,string pass){
    system("Color 06");
    int ch;
    if(name=="vishakha"&& pass=="pear123"){
        cout<<"1.To display all admin of this store:"<<endl;
        cout<<"2.To delete any admin:"<<endl;
        cout<<"3.To modify any data of any admin:"<<endl;
        cout<<"4.To add a new admin:"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch){
            case 1:display_admin();break;
            case 2:delete_admin();break;
            case 3:modify_admin();break;
            case 4:add_admin();break;
            default:cout<<"please choose valid output"<<endl;
        }
    }
}
float sum(float s){
    static float result=0;
    result+=s+80;
    cout<<"Your total is :"<<result;
    return result;
}
void recipt(){
    system("Color 0D");
    ifstream myfile("personal.dat",ios::binary|ios::in);
    while(myfile.read((char*)&m,sizeof(m))){
        m.show_list();
    }
    myfile.close();
}
int cart(){
    system("Color 0D");
    int x=0;
    float p=search_model();
    if(p==0){
        return x;
    }
    else{
        x++;
        recipt();
        sum(p);
        return x;
    }
}
void payment(){
    system("Color 09");
    int ch;
    cout<<"1.By credit card:"<<endl;
    cout<<"2.By upi:"<<endl;
    cout<<"Enter your choice:";
    cin>>ch;
    if(ch==1){
        long long card_no;
        cout << "Enter your credit card number: ";
        cin >> card_no;
        if (is_valid_card_no(card_no)) {
            cout << "HOORAY!! ORDER CONFIRMED" <<endl;
        } 
        else {
            cout << "The credit card number is not valid." <<endl;
        }
    }
    else if(ch==2){
        string upi;
        cout<<"Enter your upi id:";
        cin>>upi;
        cout<<"ALL DONE!"<<endl;
        cout<<"HOORAY!! ORDER CONFIRMED" <<endl;
    }
}
void program(){
    pattern();
    cout<<endl;
    int ch;
    float price;
    cout<<"1.As a Customer:"<<endl;
    cout<<"2.As a Admin:"<<endl;
    cout<<"Enter your choice:";
    cin>>ch;
    if(ch==1){
        system("cls");
        int dh1,y,x;
        cout<<"To get excellent service:"<<endl;
        visit_info();
        display_model();
        cout<<"Do you want to buy anything?"<<endl;
        cout<<"WE GOT YOU!"<<endl;
        cout<<"Please type m_no of any model to see the details:";
        while(1){
            cout<<"1.Search any model:";
            if(cart()==1){
                cout<<"Press 1. for chcekout:";
                cin>>y;
                if(y==1){
                    p.get_data3();
                    cout<<endl<<"############################################################"<<endl;
                    p.show_data3();
                    cout<<"Please confirm by pressing 1 again:";
                    cin>>x;
                    payment();
                }
            }
            else{
                cout<<endl<<"OPPS! ERROR OCCURED"<<endl;
                cout<<"VISIT AGAIN!!!!!"<<endl;
            }
            
        }
    }
    else if(ch==2){
        system("cls");
        system("Color 06");
        int dh2;
        if(check_admin()){
            while(1){
                cout<<"0.To exit:"<<endl;
                cout<<"1.To add a new model:"<<endl;
                cout<<"2.To change your password"<<endl;
                cout<<"3.To view no. of customer visited:"<<endl;
                cout<<"4.To view total customer purchase:"<<endl;
                cout<<"5.To view total no. of models available at shop:"<<endl;
                cout<<"Enter your choice:";
                cin>>dh2;
                if(dh2==0){
                    cout<<"Have a great day ahaead!"<<endl;
                    break;
                }
                else if(dh2==1){
                    add_model();
                }
                else if(dh2==2){
                    modify_admin();
                }
                else if(dh2==3){
                    display_visit();
                }
                else if(dh2==4){
                    display_purchase();
                }
                else if(dh2==5){
                    display_model();
                }
                else{
                    cout<<"Please enter a valid input:"<<endl;
                }
            }
        }
        else{
            cout<<"OOPS! YOU CHOOSE WRONG OPTION!"<<endl;
        }
        
    }
}
int main(){
    program();
    return 0;
}
