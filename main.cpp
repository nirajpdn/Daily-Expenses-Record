#include<iostream>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#define N 100
using namespace std;
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void messagebox()
{
	gotoxy(35,5);
	cout<<"\xc9";
	for(int i=1;i<=45;i++)
	{
		cout<<"\xcd";
	}
	gotoxy(80,5);
	cout<<"\xbb";
	for(int i=1;i<=15;i++)
	{
		gotoxy(35,5+i);
		cout<<"\xba";
		gotoxy(80,5+i);
		cout<<"\xba";
	}
	gotoxy(35,21);
    cout<<"\xc8";
	for(int i=1;i<=44;i++)
	{
		cout<<"\xcd";
	}
	cout<<"\xbc";
}
class My_Daily
{
	private:
		string name,date;
		long int amount;
	public:
		void getData();
		void total();
		void rec();	
		void scan();
		void home();
		void readData();
		void mainMenu();	
};
void My_Daily::mainMenu()
{
	system("cls");
	messagebox();
	gotoxy(40,3);
	cout<<"-----> WELCOME TO MY-DAILY <-----";
	gotoxy(41,13);
	cout<<"Enter your name:";
	gotoxy(59,13);
	cin>>name;
	home();

}
void My_Daily::home()
{	
	system("cls");
	messagebox();
	gotoxy(40,3);
	cout<<"-----> WELCOME TO MY-DAILY <-----";
	gotoxy(41,10);
	cout<<"Enter 1 to add expenses to account";
	gotoxy(41,13);
	cout<<"Enter 2 to view expences in detail";
	gotoxy(41,16);
	cout<<"Enter 3 to go main menu";
	switch(getch())
	{
		case '1':
			getData();
			break;
		case '2':
			readData();
			break;
		case '3':
			Sleep(500);
			mainMenu();
			break;
		default:
			home();
	}
}
void My_Daily::getData()
{
	system("cls");
	messagebox();
	gotoxy(42,11);
	cout<<"Enter date:";
	gotoxy(42,15);
	cout<<"Amount you expenses today:";
	gotoxy(54,11);
	cin>>date;
	gotoxy(69,15);
	cin>>amount;
	rec();	
}
void My_Daily::readData()
{
	int i=0;
	string detail;
	ifstream nfile;
	nfile.open(name.c_str());
	if(!nfile)
	{
		system("cls");
		gotoxy(35,6);
		cout<<"No records found";
		getch();
		home();
	}
	else
	{
		system("cls");
		while(getline(nfile,detail))
		{
			gotoxy(32,5+i);
			cout<<detail;
			i++;
		}
	}
	scan();
}
void My_Daily::rec()
{
	system("cls");
	messagebox();
	gotoxy(40,3);
	cout<<"-----> WELCOME TO MY-DAILY <-----";
	ofstream myfile,pfile;
	myfile.open(name.c_str(),ios::app);
	pfile.open((name+"-amount").c_str(),ios::app);
	myfile<<"Date:"<<date;
	myfile<<"\t"<<"Amount:"<<amount<<endl;
	pfile<<amount<<endl;
	gotoxy(42,12);
	cout<<"Added Successfully";
	gotoxy(42,14);
	cout<<"Enter 1 for back";
	gotoxy(42,15);
	cout<<"Enter 2 for next entry";
	gotoxy(42,16);
	cout<<"Enter any key for exit";
	switch(getch())
	{
		case '1':
			home();
			break;
		case '2':
			getData();
			break;
		default:
			exit(0);
	}
}
void My_Daily::scan()
{
	int sum=0,n;
	int arr[N],k=0;
	ifstream myfile;
	myfile.open((name+"-amount").c_str());
	if(!myfile)
	{
		system("cls");
		gotoxy(35,6);
		cout<<"No records found";
		n=0;
	}
	while(!myfile.eof())
	{
		myfile>>n;
		arr[k] = n;
		k++;
	}

	for(int j=0;j<k-1;j++)
	{
		sum =sum+arr[j];
	}
	cout<<endl;
	cout<<"\t\t\t\t";
	for(int m=1;m<=50;m++)
	{
		cout<<"\xcd";
	}
	cout<<endl<<"\t\t\t\t"<<name<<", Your all time total expenses is: "<<sum;
	cout<<endl<<"\t\t\t\t";
	for(int a=1;a<=50;a++)
	{
		cout<<"\xcd";
	}
	cout<<endl<<endl<<"\t\t\t\t"<<"Enter 1 for back";
	cout<<endl<<"\t\t\t\t"<<"Enter 2 for next entry";
	cout<<endl<<"\t\t\t\t"<<"Enter any key for exit";
	switch(getch())
	{
		case '1':
			home();
			break;
		case '2':
			getData();
			break;
		default:
			exit(0);
	}	
}

int main()
{
	My_Daily n;
	n.mainMenu();
	getch();
}
