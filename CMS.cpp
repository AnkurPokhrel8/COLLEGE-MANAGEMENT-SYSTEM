#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;
class student
{
    public:
        long int reg;
        char name[100],branch[50];
        void input()
        {
            cout<<"\n Enter Name:";
            gets(name);
            cout<<"\n Enter Registration number:";
            cin>>reg;
            fflush(stdin);
            cout<<"\n Enter Branch:";
            gets(branch);
        }
        void display()
        {
            system("CLS");
            cout<<"Display Record\n";
            cout<<"\nName= "<<name;
            cout<<"\nRegistration number= "<<reg;
            cout<<"\nBranch Enrolled= "<<branch;
            system("PAUSE");
            system("CLS");

        }
        bool operator==(student a)
        {
            if(reg==a.reg)
                return true;
            else
                return false;
        }

};
vector <student>v;
int search_reg(long int reg,int &i);
void get_file()
{
    student x;
    int i=0;
    fstream f;
    f.open("College,txt",ios::in);
    if(f)
    {
        f.read((char *)&x,sizeof(class student));
        while(!f.eof())
        {
            v.push_back(x);
            f.read((char *)&x,sizeof(class student));

        }
    }
    else
    f.close();
}
void bubblesort()
{
    int i,j;
    student x;
    for(i=0;i<v.size();i++)
        for(j=0;j<v.size()-i-1;j++)
    if(v[j].reg>v[j+1].reg)
    {
        x=v[j];
        v[j]=v[j+1];
        v[j+1]=x;
    }
}
void insert_new()
{
    char ch='y';
    int ta;
    while(ch=='y')
    {
        fflush(stdin);
        student x;
        x.input();
        if(search_reg(x.reg,ta)==0)
            v.push_back(x);
        else
            cout<<"\nREGISTRATION NO. ALREADY EXIST!!!\t CAN'T ADD U AGAIN";
            cout<<"\n Press [Y] to Enter Again!!";
            cin>>ch;
            fflush(stdin);
    }

}
void write_file()
{
    bubblesort();
    fstream f;
    f.open("College.txt",ios::out);
    for(int i=0;i<v.size();i++)
       {

        student x=v[i];
    f.write((char *)&x,sizeof(class student));

}
f.close();
}
int search_reg(long int reg,int &i)
{
    int ta=0;
    for(i=0;i<v.size();i++)
        if(v[i].reg==reg)
    {
        ta=1;
        break;
    }
    return ta;
}
int search_name(char name[],vector<int>&vi)
{
    int i,ta=0;
    for(i=0;i<v.size();i++)
        if(strcmp(v[i].name,name)==0)
    {
        ta=1;
        vi.push_back(i);
    }
    return ta;
}
int search_branch(char branch[],vector<int>&vj)
{
    int i,ta=0;
    for(i=0;i<v.size();i++)
        if(strcmp(v[i].branch,branch)==0)
    {
        ta=1;
        vj.push_back(i);
    }
    return ta;
}
void search_and_show()
{
    int ch,i,ta=0;
    char name[100],branch[50];
    vector<int>vi;
    vector<int>vj;
    long int reg;
    poi:
        cout<<"\n PRESS 1 to Search Reg No.:"
        <<"\n Press 2 to Search Name: "
        <<"\n Press 3 to Search Branch Enrolled:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\n Enter Name:";
            fflush(stdin);
            gets(name);
            if(search_name(name,vi)==1)
            {
                for(int j=0;j<vi.size();j++)
                    v[vi[j]].display();
            }
            else
                cout<<"\n Record Not Found!!!";
                break;
        case 3:
            cout<<"\n Enter Branch:";
            fflush(stdin);
            gets(branch);
            if(search_branch(branch,vj)==1)
            {
                for(int j=0;j<vj.size();j++)
                    v[vj[j]].display();
            }
            else
                cout<<"\n Record Not Found:";
            break;
        default:
            cout<<"\n!!!WRONG CHOICE OF INPUT!!!";
            goto poi;

        }
}
void show()
{
    int i;
    for(i=0;i<v.size();i++)
        v[i].display();
}
void delete_data()
{
    int i,j;
    long int reg;
    vector<student>::iterator p=v.begin();
    cout<<"\n Enter Reg no.:";
    cin>>reg;
    if(search_reg(reg,i)==1)
    {
        student x=v[i];
        cout<<"\n The Following Data Is Deleted:";
        x.display();
        p+=i;
        v.erase(p,p+1);

    }

}
void edit_data()
{
    int i,j;
    long int reg;
    vector<student>vi;
    cout<<"\n Enter reg no.:";
    cin>>reg;
    if(search_reg(reg,i)==1)
    {
        cout<<"\n Enter New Data:";
        fflush(stdin);
        v[i].input();
    }
}
int main()
{
    int i=1;
    get_file();
    while(i)
          {
            system("CLS");
            cout<<"\t\t\t-------------------------------------\n";
            cout<<"\t\t\t  Simple College Management System \n";
            cout<<"\t\t\t--------------------------------------\n";
            cout<<"\n\t\tENTER <1> TO ADD NEW STUDENT DATA"
            <<"\n\t\tENTER <2> TO DISPLAY ALL STUDENTS DATA"
            <<"\n\t\tENTER <3> TO REMOVE STUDENT DATA"
            <<"\n\t\tENTER <4> TO EDIT STUDENT DATA"
            <<"\n\t\tENTER <5> TO SEARCH EXISTING STUDENT"
            <<"\n\t\tENTER <0> TO EXIT \n>";
            cout<<"\n\t\tENTER YOUR CHOICE:";
            cin>>i;
            switch(i)
            {
          case 1:
            insert_new();
            break;
            case 2:
            show();
            break;
            case 3:
            delete_data();
            break;
            case 4:
                edit_data();
                break;
            case 5:
                search_and_show();
                break;
            case 0:
                write_file();
                break;
            default:
                cout<<"\n !!!WRONG CHOICE!!!\t TRY AGAIN!!!";
            }

          }
          return 0;
}
