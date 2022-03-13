#include<iostream>
using namespace std;

int main()
{
    char name[20]{0};
    char dessert[20]{0};
    cout<<dessert<<endl;
    cin.get(dessert,20).get();
    cout<<dessert<<endl;
    cin.getline(name,20);
    cout<<name<<endl;
    return 0;
}