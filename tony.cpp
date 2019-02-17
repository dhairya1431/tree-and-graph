#include<iostream>
using namespace std;

void convert(string str)
{
	int h1 = (int)str[1] - '0';
	int h2 = (int)str[0] - '0';
	int hh = (h2 * 10 + h1 % 10);
	//cout<<"hh="<<hh<<endl;

	// If time is in "AM"
	if (str[8] == 'A')
	{
	if (hh == 12)
		{
		    hh=0;
		}

	}

	// If time is in "PM"
	else if(str[8] == 'P')
	{
		if (hh == 12)
		{
			hh=12;
		}
		else
		{
			hh = hh + 12;
		}
	}
	//cout<<"\n";
	int r=hh+2;
	if(r>=24)  //if it exceed 24hr
    {
        int x=r-24;
        cout<<"0"<<x;
        for (int i=2; i <= 7; i++)
				cout << str[i];

     cout<<endl;
    }
    else
    {

        if(r>10)
        {
            cout<<r;
            for (int i=2; i <= 7; i++)
				cout << str[i];

        cout<<endl;
       }
    else
{
        cout<<"0"<<r;
        for (int i=2; i <= 7; i++)
				cout << str[i];

        cout<<endl;
}
}
}

int main()
{
int t;
cin>>t;
cin.ignore();
while(t--)
{
string str;
getline(cin,str);
if(str[1]=='8'&&str[8]=='A')
{
    cout<<"1"<<"0"<<":"<<str[3]<<str[4]<<str[5]<<str[6]<<str[7]<<endl;continue;

}
convert(str);
}
}
