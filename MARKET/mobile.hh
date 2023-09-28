#include<iostream>
#include<cstdlib>
using namespace std;
void pattern(){
    system("Color 06");
    for(int i=0;i<=11;i++){
        for(int j=0;j<2;j++){
            cout<<"* ";
        }
        for(int k=1;k<=5;k++){
            if(i>9&&i<=11){
                cout<<" * *";
            }
            else{
                cout<<"  ";
            }
        }
        for(int j=1;j<=8;j++){
            if(i>=0&&i<2||i>4&&i<7||i>=2&&i<=4&&j==1||i>6&&i<=9&&j==1||i>9&&i<=11){
                cout<<" * *";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    cout<<"LEMON EMON............"<<endl;
}
bool is_valid_card_no(long long card_no){
    int sum=0;
    int temp;
    int num_digits=0;
    while(card_no>0) {
        temp=card_no%10;
        num_digits++;
        if(num_digits %2==0){
            temp*=2;
            if(temp>9){
                temp-=9;
            }
        }
        sum+=temp;
        card_no/=10;
    }
    return (sum%10==0);
}