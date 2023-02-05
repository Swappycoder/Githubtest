#include <iostream>
using namespace std;


class Student{
public:
	int roll;
	string name;
	string email;
	string dob;
	char panel;


	Student();
	Student(int r, string n, string e, string d, char p);
	void display();
	void getdata();
};

void search(Student S[100], int key, int n);

int main(){
	int n, key;
	cout<<"How many students do you wish to add? "<<endl;
	cin>>n;

	Student S[n];
	for(int i = 0;i<n;i++){
		S[i].getdata();
	}

    for(int i = 0;i<n;i++){
		S[i].display();
	}

	cout<<"Enter roll number to search for: "<<endl;
	cin>>key;

	search(S, key, n);
	return 0;
}



Student::Student(){
	roll = 53;
	name = "Mohit";
	email = "mohitkhade11@gmail.com";
	dob = "May 11";
	panel = 'C';
	cout<<"I am default Constructor"<<endl;
}
Student::Student(int r, string n, string e, string d, char p){
	roll = r;
	name = n;
	email = e;
	dob = d;
	panel = p;
	cout<<"I am Parameterized Constructor"<<endl;
}

void Student::display(){
	cout<<"Name : "<<name<<"\nRoll No. : "<<roll<<"\nEmail : "<<email<<"\nDate of Birth : "<<dob<<"\nPanel : "<<panel<<endl;
}

void Student::getdata(){
	cout<<"Enter Name"<<endl;
	cin>>name;
	cout<<"Enter Roll No."<<endl;
	cin>>roll;
	cout<<"Enter Email"<<endl;
	cin>>email;
	cout<<"Enter Date of Birth"<<endl;
	cin>>dob;
	cout<<"Enter Panel"<<endl;
	cin>>panel;
}

void search(Student S[100], int key, int n){
	int x, flag = 0;
	for(int i=0;i<n;i++){
		if (S[i].roll == key){
			flag = 1;
			x = i;
		}
	}
	if(flag == 1){
		S[x].display();
	}
	else cout<<"Entry not found"<<endl;
}