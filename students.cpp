#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>
using namespace std;
int o,i=0,countstudent,b;
char id[100][5],name[100][25],project[3];
float english[10],c[10],java[10],total[10],average[10],tm;
string path = "D:\\Programming Learning\\C++ Programming\\mystudent.txt";
void menu(){
	cout<<"\n\t========MENU========\n";
	cout<<"\t1. Add Student\n";
	cout<<"\t2. Update Student\n";
	cout<<"\t3. Delete Student\n";
	cout<<"\t4. View\n";
	cout<<"\t5. Exit\n";
}
void addstudent(int i){
	countstudent++;
	cout<<"\t=========Add Students=========\n";
	fflush(stdin);
	cout<<"\tInput Students ID: ";
	cin.getline(id[i],5,'\n');
	cout<<"\tInput Students Name: ";
	cin.getline(name[i],25,'\n');
	do{
		cout<<"\tInput Score English: ";
		cin>>english[i];
	}while(english[i]>100 || english[i]<0);
	do{
		cout<<"\tInput Score C: ";
		cin>>c[i];
	}while(c[i]>100 || c[i]<0);
	do{
		cout<<"\tInput Score Java: ";
		cin>>java[i];	
	}while(java[i]>100 || java[i]<0);
	total[i] = english[i] + c[i] + java[i];
	average[i] = total[i]/3;
}
void updatestudent(){
	char tmp[5];
	cout<<"\t=========Update Student===========\n";
	cout<<"\tInput Student ID to Update: ";
	cin>>tmp;
	for(int i=0; i<countstudent; i++){
		if(strcmp(tmp,id[i])==0){
			fflush(stdin);
			cout<<"\tInput New Students ID: ";
			cin.getline(id[i],5,'\n');
			cout<<"\tInput New Students Name: ";
			cin.getline(name[i],25,'\n');
			cout<<"\tInput New Score English: ";
			cin>>english[i];
			cout<<"\tInput New Score C: ";
			cin>>c[i];
			cout<<"\tInput New Score Java: ";
			cin>>java[i];
			total[i] = english[i] + c[i] + java[i];
			average[i] = total[i]/3;
		}
	}
	cout<<"\tUpdate Success.........\n";
}
void deletestudent(){
	char tmp[5];
	cout<<"\t==========Delete Student===========\n";
	cout<<"\tInput Student ID to Delete: ";
	cin>>tmp;
	for(int i=0; i<countstudent; i++){
		if(strcmp(tmp,id[i])==0){
			for(int j=i; j<countstudent; j++){
				strcpy(id[j],id[j+1]);
				strcpy(name[j],name[j+1]);
				english[j] = english[j+1];
				c[j] = c[j+1];
				java[j] = java[j+1];
				total[j] = total[j+1];
				average[j] = average[j+1];
			}
		}
	}
	countstudent--;
	b--;
	cout<<"\tDelete Success..........\n";
}
void view(){
	cout<<"\t========View Students=========\n";
	cout<<"\tID\tName\t\tEnglish\t\tC Pro\tJava\tTotal\tAverage\n";
		for(int i=0; i<countstudent; i++){
			cout<<"\t"<<id[i]<<"\t"<<name[i]<<"\t"<<english[i]<<"\t\t"<<c[i]<<"\t"<<java[i]<<"\t"<<total[i]<<"\t"<<average[i]<<endl;
		}
}
int main(){
	while(1){
		menu();
		cout<<"\tChoose Option: ";
		cin>>o;
		switch(o){
			case 1:
				addstudent(i);
				i++;
				break;
			case 2:
				updatestudent();
				break;
			case 3:
				deletestudent();
				break;
			case 4:
				view();
				break;
			case 5:
				exit(0);
				break;
		}
	}
	return 0;
}
