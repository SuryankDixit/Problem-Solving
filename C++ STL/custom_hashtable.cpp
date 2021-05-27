#include<bits/stdc++.h>

using namespace std;

class student{
public:
	string firstname;
	string lastname;
	int rollno;

	student(string a, string b,int c){
		firstname= a;
		lastname=b;
		rollno=c;
	}

	// Make this function const because we are not changing any data member of class inside function


	bool operator==(const student &s) const{
		return rollno==s.rollno;
	}
};

class Hashfunc{
public:
	// Making function const;

	unsigned int operator()(const student &s) const{
		return (s.firstname.length()+s.lastname.length());
	}
};

 
int main()
{
	unordered_map<student,int,Hashfunc> student_map;

	student s1("Suryank","Dixit", 01);
	student s2("Deepank","Dixit", 02);
	student s3("Suri","Dixit", 03);
	student s4("Deepu","Dixit", 04);
	student s5("Suri","Dixit", 05);

	student_map[s1]=100;
	student_map[s2]=200;
	student_map[s3]=200;
	student_map[s4]=30;
	student_map[s5]=20;

	for(auto x:student_map)
		cout<<x.first.firstname<<" "<<x.first.lastname<<"->"<<x.second<<endl;
}
