// This code uses the find function to solve the problem.
// We can change the format of massage in lines 14 and 15.
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef string str;

class message{
    private:
        str mess;
        const str pre_mess="LQ "; 
        const str suf_messB="B"; // Ex: "BOY"
        const str suf_messG="G"; // Ex: "GIRL" 
        str messB=pre_mess+suf_messB;
        str messG=pre_mess+suf_messG;
    public:
        void input();
        bool check_front(ll &i,ll tmp);
        bool check_back(ll &i);
        void check_valid_mess();
};

void message::input(){
    getline(cin,mess);
}

bool message::check_front(ll &i,ll tmp){
    if(i-1<0){
        i+=tmp-1;
        return true;
    }
    if((mess[i-1]>='a'&&mess[i-1]<='z')||(mess[i-1]>='A'&&mess[i-1]<='Z')){
        mess.erase(0,i+tmp);
        i=0;
        return false;
    }
    else{
        i+=tmp-1;
        return true;
    }
}

bool message::check_back(ll &i){
    if(i+1>mess.size())
        return true;
    if((mess[i+1]>='a'&&mess[i+1]<='z')||(mess[i+1]>='A'&&mess[i+1]<='Z')){
        mess.erase(0,i+1);
        i=0;
        return false;
    }
    return true;
}

void message::check_valid_mess(){
    while(mess.size()){
        ll x=mess.find(messB);
        ll y=mess.find(messG);
        if((x==-1&&y==-1)){
            cout<<"Invalid Message"<<endl;
            return;
        }
        if(y!=-1){
            if(check_front(y,messG.size())&&check_back(y)){
                cout<<"Valid Message"<<endl;
                return;
            }  
        }
        else
            if(check_front(x,messB.size())&&check_back(x)){
                cout<<"Valid Message"<<endl;
                return;
            }  
    }
    cout<<"Invalid Message"<<endl;
}

int main(){
    message ms;  
    ms.input();
    ms.check_valid_mess();
    return 0;
}
