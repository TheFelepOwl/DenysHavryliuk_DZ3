#include<iostream>
#include <fstream>

using namespace std;

class Student
{

string surname;
string name;

int scores_1;
int scores_2;
int scores_3;

public:
void Set(string surname,string name,int scores_1,int scores_2,int scores_3)
{
    this->surname = surname;
    this->name = name;
    this->scores_1 = scores_1;
    this->scores_2 = scores_2;
    this->scores_3 = scores_3;
}

string GetName()
{
return surname;
}


void Print()
{
    if(scores_1>3&&scores_2>3&&scores_3>3)
        cout <<"Student "<< surname <<" "<< name << " have " << scores_1<<" "<<scores_2 <<" "<<scores_3<< " baliv" << endl;
}
};


int main()
{
int kilkist = 0;

string str;

ifstream fin("hello.txt");

if (fin)
{
    while (!fin.eof())
    {
        getline(fin, str, '\n');
        kilkist++;
    }

    Student *P = new Student[kilkist];
    fin.clear();
    fin.seekg(0);
    for (int i = 0; i < kilkist; i++)
    {
        string surname;
        string name;
        int b,c,d;
        fin >> surname>> name;
        fin >> b>>c>>d;
        P[i].Set(surname,name, b ,c ,d);
    }

    for (int i = 0; i < kilkist - 1; i++)
    for (int j = i + 1; j < kilkist; j++)
     if (P[i].GetName() > P[j].GetName())
    {
        swap(P[i], P[j]);
    }

    for (int i = 0; i < kilkist; i++)
        P[i].Print();

    fin.close();
    delete []P;
}

else
cout << "Unable to open file";
}
