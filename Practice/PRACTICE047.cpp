#include<iostream>
#include<string>

class Account
{
private:
    std::string name;
    std::string password;
    double banlance;
public:
    Account(){name=password=banlance='\0';}
    Account(std::string,std::string,double);
    void show() const;
    Account& operator+(const Account& );
    friend Account& operator*(double ,const Account& );
    Account& operator*(double );
    void deposit(double );
    bool withdrawal(double );
};
Account& Account::operator*(double a)
{
    this->banlance*=a;
    return *this;
}
Account& operator*(double a,Account& b)
{
    return b*a;
}
Account& Account::operator+(const Account& temp)
{
    banlance=banlance+temp.banlance;
    return *this;
}

void Account::show() const
{
    std::cout<<name<<' '<<password<<' '<<banlance<<std::endl;
}

Account::Account(std::string name,std::string password,double banlance)
{
    this->name=name;
    this->password=password;
    this->banlance=banlance;
}

void Account::deposit(double money)
{
    banlance+=money;
}

bool Account::withdrawal(double money)
{
    if(banlance>money)
    {
        banlance-=money;
        return true;
    }
    else 
        return false;
}

int main()
{
    Account clerk1("qiuruoyu","1234",99999);
    Account clerk2("zzjjyy","121",11111);
    clerk1.show();
    clerk1.deposit(200);
    clerk1.show();
    clerk1.withdrawal(500);
    clerk1.show();
    clerk2=clerk2+clerk1;
    clerk2.show();
    Account clerk3=clerk2*2;
    clerk3.show();

    return 0;
}