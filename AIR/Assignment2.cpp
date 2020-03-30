#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Expert_System
{
	
	public: 
	char fever, hedache, vomiting, pain, wkns, nausea, rashes, itching, cough, chills, swetting, sore_throat, runny_nose, abdmnlpn, confusion;

	char name[50];
	char bgrp[5];
	char dob[10];
	void patient_details();
	void questions(char name[]);
	void rules(char name[]);
};	

void Expert_System::questions(char name[])
{
	cout<<"\n"<<"\n";
	cout<<name<<" do you have Fever(Y/N): ";
	cin>>fever;
	
	cout<<name<<" do you have Headache(Y/N): ";
	cin>>hedache;
	cout<<name<<" do you have Vomiting(Y/N): ";
	cin>>vomiting;
	cout<<name<<" do you have Pain(Y/N): ";
	cin>>pain;
	cout<<name<<" do you have Weakness(Y/N): ";
	cin>>wkns;
	cout<<name<<" do you have Nausea(Y/N): ";
	cin>>nausea;
	cout<<name<<" do you have Rashes(Y/N): ";
	cin>>rashes;
	cout<<name<<" do you have Itching(Y/N): ";
	cin>>itching;
	cout<<name<<" do you have Cough(Y/N): ";
	cin>>cough;
	cout<<name<<" do you have Chills(Y/N): ";
	cin>>chills;
	cout<<name<<" do you have Sweating(Y/N): ";
	cin>>swetting;
	cout<<name<<" do you have Runny Nose(Y/N): ";
	cin>>runny_nose;
	cout<<name<<" do you have Abdominal Pain(Y/N): ";
	cin>>abdmnlpn;
	cout<<name<<" do you have Sore Throat(Y/N)): ";
	cin>>sore_throat;
	cout<<name<<" do you feel like Confusion(Y/N): ";
	cin>>confusion;
}

void Expert_System::rules(char name[])
{
	if(fever == 'Y' && wkns == 'Y' && pain == 'Y' && vomiting == 'Y' && hedache == 'Y')
		cout<<name<<" you may have Dengue ";
	else if(fever == 'Y' && hedache == 'Y' && pain == 'Y' && vomiting == 'Y' && sore_throat == 'Y')
		cout<<name<<" you may have Cold Flue ";
	else if(fever == 'Y' && hedache == 'Y' && vomiting == 'Y'&& pain == 'Y')
		cout<<name<<" you may have Maleria ";
	else if(fever == 'Y' && vomiting == 'Y' && wkns == 'Y' && abdmnlpn == 'Y'&& hedache == 'Y')
		cout<<name<<" you may have Typhoid ";
	else if(fever == 'Y' && rashes == 'Y' && itching == 'Y' && wkns == 'Y')
		cout<<name<<"you may have Chicken Pox ";
	else if(fever == 'Y' && cough == 'Y' && wkns == 'Y' && sore_throat == 'Y' && nausea == 'Y')
		cout<<name<<" you may have Swine Flue ";
	else if(fever == 'Y' && pain == 'Y' && rashes == 'Y' && hedache == 'Y')
		cout<<name<<" you may have Chickun Guniya ";
	else if(fever  == 'Y' && chills == 'Y')
		cout<<name<<"you may have Septisemia ";
	else if(fever == 'Y' && pain == 'Y' && confusion == 'Y')
		cout<<name<<" you may have Hyperthermia ";
	else if(fever == 'Y' && pain == 'Y' && swetting == 'Y' && hedache == 'Y')
		cout<<name<<" you may have Hyperpyrexia ";
	else
		cout<<name<<" you have Normal Fever\n";
	cout<<"\n\n";
}

void Expert_System::patient_details()
{	
	cout<<"\n Enter the Name of Patient: ";
	cin>>name;
	cout<<"\n Enter the Date of Birth: ";
	cin>>dob;
	cout<<"\n Enter the Patient's Blood Group: "	;
	cin>>bgrp;
	cout<<"\n\n\n";
	cout<<"\n Details of Patient: ";
	cout<<"\nNAME: "<<name;
	cout<<"\nDATE OF BIRTH: "<<dob;
	cout<<"\nBLOOD GROUP: "<<bgrp;
	questions(name);
}
int main()
{
	Expert_System E;
	char ans;

	cout<<"\n\t\tWELCOME TO OUR EXPERT MEDICAL SYSTEM \n";
	while(1)
	{
		E.patient_details();
		cout<<"\n";
		E.rules(E.name);
		cout<<"\nDo you want to try for another patient(Y/N): ";
		cin>>ans;
		if(ans != 'Y')
			break;
	}
	return 0;
}
