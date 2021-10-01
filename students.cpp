#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>
#include <conio.h>
using namespace std;
int o,i=0,countstudent,b,k;
char id[100][5],name[100][25],project[3],a;
float english[10],c[10],java[10],total[10],average[10],tm;
string path = "D:\\Programming Learning\\C++ Programming\\mystudent.txt";
void menu(){
	cout<<"\n\t========MENU========\n";
	cout<<"\t1. Add Student\n";
	cout<<"\t2. Update Student\n";
	cout<<"\t3. Delete Student\n";
	cout<<"\t4. View\n";
	cout<<"\t5. Exit\n";
	cout<<"\t6. Clear\n";
}
void addstudent(int i){
	countstudent++;
	cout<<"\t=========Add Students=========\n";
	fflush(stdin);
	cout<<"\tInput Students ID: ";
	cin>>id[i];
	fflush(stdin);
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
	char tmp[7];
	input:
	cout<<"\t===============================View Students==============================\n";
	cout<<"\tID\tName\t\tEnglish\t\tC Pro\tJava\tTotal\tAverage\n";
		for(int i=0; i<countstudent; i++){
			cout<<"\t"<<id[i]<<"\t"<<name[i]<<"\t"<<english[i]<<"\t\t"<<c[i]<<"\t"<<java[i]<<"\t"<<total[i]<<"\t"<<average[i]<<endl;
		}
	cout<<"\t==========================================================================\n";
	cout<<"\t=========Update Student===========\n";
	cout<<"\tPress 'Q' to exit\n";
	cout<<"\tInput Student ID to Update: ";
	cin>>tmp;
	for(int t=0; t<1; t++){
	if(tmp=="q" || tmp=="Q"){
		break;
	}
}
	for(int i=0; i<countstudent; i++){
		if(strcmp(tmp,id[i])==0){
			fflush(stdin);
			cout<<"\tInput New Students ID: ";
			cin>>id[i];
			fflush(stdin);
			cout<<"\tInput New Students Name: ";
			cin.getline(name[i],25,'\n');
			do{
				cout<<"\tInput New Score English: ";
				cin>>english[i];
			}while(english[i]>100 || english[i]<0);
			do{
				cout<<"\tInput New Score C: ";
				cin>>c[i];
			}while(c[i]>100 || c[i]<0);
			do{
				cout<<"\tInputNew Score Java: ";
				cin>>java[i];	
			}while(java[i]>100 || java[i]<0);
			total[i] = english[i] + c[i] + java[i];
			average[i] = total[i]/3;
			cout<<"\tUpdate Success.........\n";
		}
	}
		up:
		cout<<"\tPress 'I' to update agian, 'Q' to exit: ";
		cin>>a;
		if(a=='i' || a=='I'){
			goto input;
		}else if(a=='q' || a=='Q'){
			
		}else{
			cout<<"\tInvalid!\n";
			goto up;
		}
	
}
void deletestudent(){
	char tmp[5];
	input:
	cout<<"\t===============================View Students==============================\n";
	cout<<"\tID\tName\t\tEnglish\t\tC Pro\tJava\tTotal\tAverage\n";
		for(int k=0; k<countstudent; k++){
			cout<<"\t"<<id[k]<<"\t"<<name[k]<<"\t"<<english[k]<<"\t\t"<<c[k]<<"\t"<<java[k]<<"\t"<<total[k]<<"\t"<<average[k]<<endl;
		}
	cout<<"\t==========================================================================\n";
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
				countstudent--;
				b--;	
			}
		}
		cout<<"\tDelete Success............\n";	
		up:
		cout<<"\tPress 'I' to delete agian, 'Q' to exit: ";
		cin>>a;
		if(a=='i' || a=='I'){
			goto input;
		}else if(a=='q' || a=='Q'){
			
		}else{
			cout<<"\tInvalid!\n";
			goto up;
		}
}
void view(){
	cout<<"\t===============================View Students==============================\n";
	cout<<"\tID\tName\t\tEnglish\t\tC Pro\tJava\tTotal\tAverage\n";
		for(int i=0; i<countstudent; i++){
			cout<<"\t"<<id[i]<<"\t"<<name[i]<<"\t"<<english[i]<<"\t\t"<<c[i]<<"\t"<<java[i]<<"\t"<<total[i]<<"\t"<<average[i]<<endl;
		}
	cout<<"\t==========================================================================\n";
}
int main(){
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	h:
	while(1){
	SetConsoleTextAttribute(color,1);
		menu();
		cout<<"\tChoose Option: ";
		cin>>o;
		switch(o){
			case 1:
				SetConsoleTextAttribute(color,2);
				addstudent(i);
				i++;
				break;
			case 2:
				SetConsoleTextAttribute(color,3);
				updatestudent();
				break;
			case 3:
				SetConsoleTextAttribute(color,4);
				deletestudent();
				break;
			case 4:
				SetConsoleTextAttribute(color,5);
				view();
				break;
			case 5:
				SetConsoleTextAttribute(color,6);
				exit(0);
				break;
			case 6:
				SetConsoleTextAttribute(color,7);
				system("cls");
				goto h;
				break;
		}
	}
	return 0;
}
