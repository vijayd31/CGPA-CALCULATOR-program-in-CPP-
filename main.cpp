/*********--HEADER-FILES--*********/

#include<iostream>
#include<string>
using namespace std;

/*************--CLASS--************/

class CGPA{
	int nsub;
	int c[10],g[10];
	string lg[10];
	int sum_cg=0;
	float credits=0;
	float sgpa=0;
	
	public:
	void read();
	void grad_to_point();
	void calc();
	void display_sgpa();
	int sump();
	int sumq();
};

/********--CLASS-METHODS--*********/

	void CGPA::read(){
		cin>>nsub;
		for(int i=0;i<nsub;i++){
			cout<<"Sub"<<i+1<<" Credits & Grade(O,A+,A,B) = ";
			cin>>c[i]>>lg[i];
		}
	}
	
	void CGPA::grad_to_point(){
		for(int i=0;i<nsub;i++){
			g[i]=(lg[i]=="O")?10:(lg[i]=="A+")?9:(lg[i]=="A")?8:(lg[i]=="B+")?7:(lg[i]=="B")?6:0;
		}
	}
	
	void CGPA::calc(){
		for(int i=0;i<nsub;i++){
			credits+=c[i];
			sum_cg+=c[i]*g[i];
		}
		sgpa=sum_cg/credits;
	}
	
	void CGPA::display_sgpa(){
		if(sgpa>10){
			cout<<"Oops... Something went wrong...";
		}
		else{
			cout<<sgpa;
		}
	}
	
	int CGPA::sump(){
		return sum_cg;
	}
	int CGPA::sumq(){
		return credits;
	}

/********--MAIN-FUNCTION--*********/
	
int main(){
	
	cout<<"\t\t----- CGPA CALCULATOR -----\t\t\n\n";
	
	CGPA x[8];
	
	int n;
	cout<<"How many Semesters completed? ";
	cin>>n;
	
	for(int i=0;i<n;i++){
		
		cout<<endl<<"Enter the number of subjects followed by Credits and the Grade you earned, in each subject of Semester "<<i+1<<""<<endl<<endl;
		
		cout<<"No. of subjects in Sem "<<i+1<<": ";
		
		x[i].read();
		
		x[i].grad_to_point();
		
		x[i].calc();
		
		cout<<"  SGPA"<<i+1<<" => ";
		x[i].display_sgpa();
		
		cout<<endl;
	}
	
	float p=0,q=0;
	
	for(int i=0;i<n;i++){
		p+=x[i].sump();
		q+=x[i].sumq();
	}
	
	float cgpa=p/q;
	
	cout<<"\n-----------------------------------";
	cout<<"\n   Your CGPA =>> "<<cgpa<<endl;
	cout<<"-----------------------------------\n";
	
	return 0;
}

/********---END-OF-PROJECT--********/
