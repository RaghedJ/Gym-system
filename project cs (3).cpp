//Raghed Ibrahim Al Jassim
//nouf hysein alshanbari
//Hawra Hussain Fardan
//badriah marzooq alotibi
#include<iostream>
#include<string>
#include<cstring>
#include <ctype.h>
#include<cctype>
#include<fstream>
using namespace std;

    double bill;
	bool found;
	int payes, ncustomer=0;
	int subs=0;
	
	
// struct for basic information for employees and customers
	
	struct card{
	char  name[20];
	int num,date,CVV;
		
	};
    struct names{
		
		string first;
		string last;
	};
	struct services{
	int train;
	int equipment;
	int swimming_pool;
	int basket_ball;
	int running_track;
    };
	struct person{
		
		char gender, sub;
		names name;
		double id;
		int age ;
		int phoneNumber;
		double length,  weight;
		char diseases [20];
		services service;
		card info;
		};		

char continu;

void pay(person pr[],int index);		
void add(person pr[],int &index, double &id);
void delet(person pr[], double id,int &index);	
void update(person pr[], double id,int &index);
void sort (person pr[],int &index);
void view(person pr[],int index);
void service(person pr[],int index,char a);

int main(){

// CID is array for customer 
// id It is an identifier that the user enters in order to find an item and perform a task for it
// eingex The number of employees entered, cindex The number of customers entered

	const int size=500;
	int cindex=0, choose;
	person Cpr[size];
	double CID, id;
	CID=331000;

	
//Display the options menu and call the functions
	do{
		cout<<"\n Choose the operation. \n"
		<<"\t1.Add a customer.\n"
		<<"\t2.Delete a customer.\n"
		<<"\t3.Update a customer.\n"
		<<"\t4.View a customer.\n"
		<<"\t5.Sort customers by age groups.\n"
		<<"\t6.View the number of customers\n"
		<<"\t7.To pay.\n"
		<<"\t0.End the program.\n";

	cin>>choose;
	
	switch (choose) {
		//add
		case 1:{
		
		if(ncustomer<size){
		add(Cpr,cindex,CID);
		char needed;
	    cout<<"\nnow...determain what services you need(each srvice costs +50 a time)"<<endl<<endl<<"-training"<<endl;
	    cout<<"-equipments"<<endl<<"-swimming pool"<<endl<<"-basket ball"<<endl<<"-running track"<<endl<<endl;
	    do{
	    cout<<"enter the first letter from the service you need: ";
    	cin>>needed;
    	service(Cpr,cindex,needed);
		cout<<"you want more?(press y)";
		cin>>continu;}
		while(continu=='y'||continu=='Y');
		CID++;
		ncustomer++;
	}
		else
		cout<<"The number of subscribers has reached the maximum, there is no space to add a new customer\n";
		break;}
		
		//delete
		case 2:{
		
		if(ncustomer>0){
		cout<<"Enter the customer ID : ";
		cin>>id;
		delet(Cpr,id,cindex);	
		}
		else 
		cout<<"There are no items\n";	
		
		break;}
		
		//update
	case 3:{
		
		if(ncustomer>0){
		cout<<"Enter the customer ID : ";
		cin>>id;
		update(Cpr,id,cindex);
		}
		else 
		cout<<"There are no items\n";
		
		break;}
			
    	//view
	case 4:{
		
		if(ncustomer>0)
		view(Cpr,cindex);
		else 
		cout<<"There are no items\n";
		
		break;
	}
	
	//sort
	case 5:{
	
	if(ncustomer>0)
	sort(Cpr,cindex);
	else 
	cout<<"There are no items\n";
	
		break;
	}
	
	//number of customers
	case 6:{
		cout<<"The number of customers is "<<ncustomer;
		break;
	}
	case 7:{
		pay(Cpr,cindex);	
		break;
	}
	case 0:{
	cout<<"The program is over.";	
		break;}
	
	default:
	cout << "Invalid choice!!\n\n";
	}
	}while(choose!=0);
	
	return 0;
}
void pay(person pr[],int index){
	ofstream outFile;
	outFile.open("bill.txt");
	if(outFile.is_open()){
		
	bill = subs + ((pr[index].service.train*50)+(pr[index].service.equipment*50)+(pr[index].service.swimming_pool*50)+(pr[index].service.basket_ball*50)+(pr[index].service.running_track*50));
	outFile<<"the bill:"<<endl
	<<"subscribtion: "<<subs<<endl
	<<"services: "<<endl
	<<"training: "<<pr[index].service.train<<" times a week"<<endl
	<<"equipment: "<<pr[index].service.equipment<<" times a week"<<endl
	<<"swimming pool: "<<pr[index].service.swimming_pool<<" times a week"<<endl
	<<"basket ball: "<<pr[index].service.basket_ball<<" times a week"<<endl
	<<"running track: "<<pr[index].service.running_track<<" times a week"<<endl
	<<"bill: "<<bill<<endl
	<<"total: "<<(bill+(bill*0.15))<<endl;
	outFile.close();}
	else
    cout << "The file could not be opened.";
    
	card x[20];
	cout<<"choose: 1 for credit card , 2 for visa , 3 for cash\t";
    cin>>payes;
    switch (payes){
    case 1 :
		for (int i =0 ; i<=index  ; i++){
			
		cout<<"Enter The card name:  "<<endl;
		cin>>x[i].name;
		
		cout<<"Enter The card number: "<<endl;
		cin>>x[i].num;
		cout<<"Enter the date MM YY: "<<endl;
		cin>>x[i].date;
		cout<<"Enter the CVV: "<<endl;
		cin>>x[i].CVV;
		cout<<"payment succeeded! "<<endl;
		}
		break;
		
    case 2:

		for (int i =0 ; i<index  ; i++){
			
		cout<<"Enter The card name:  "<<endl;
		cin>>x[i].name;
		
		cout<<"Enter The card number: "<<endl;
		cin>>x[i].num;
		cout<<"Enter the date MM YY: "<<endl;
		cin>>x[i].date;
		cout<<"Enter the CVV: "<<endl;
		cin>>x[i].CVV;
		cout<<"payment succeeded! "<<endl;	
		}
		break;
	
    case 3:
	cout<<"you should go to the accounting department in the gym to pay with cash "<<endl;
	break;
	default:
	cout<<"choose number ";
}}
//A function to add an employee or a customer	
void add(person pr[],int &index, double &id){
	bool letter=false;
	cout<<"Enter the name: ";
	cin>>pr[index].name.first>>pr[index].name.last;
	
	cout<<"Enter the gender (F or M): ";
	cin>>pr[index].gender;
	if(isalpha(pr[index].gender))
	letter=true;
	if(letter==false){ 
	cout<<"wrong enter again: ";
	cin>>pr[index].gender;
	}
	cout<<"Enter the age: ";
	cin>>pr[index].age;
	
	cout<<"Enter the phone number: ";
	cin>>pr[index].phoneNumber;
	
	cout<<"Enter the length and weight: ";
	cin>>pr[index].length >> pr[index].weight;
	
	cout<<"Do you have any diseases? If yes, enter the name of the disease: ";
	cin>>pr[index].diseases;
	
	cout<<"\nwhat subscribtion would you like?:"<<endl
	<<"yearly--> you would get 3 months free...and the subscribtion = 600 + services indavidually"<<endl
	<<"half a year--> you would get a free month...and the subscribtion = 400 + srvices indavidually"<<endl
	<<"monthly--> 100 + services indavidually\n"<<endl
	<<"enter first charecter(Y or H or M): ";
	cin>>pr[index].sub;
	if(pr[index].sub=='y'||pr[index].sub=='Y')
	subs=600;
	else if(pr[index].sub=='h'||pr[index].sub=='H')
	subs=400;
	else
	subs=100;	
		
	pr[index].id=id;
	
	index++;
}
	
	
//Function to delete an employee or a customer
void delet(person pr[], double id,int &index){
	found=false;
	for (int i =0 ; i<=index ; i++){
		if (id==pr[i].id){
			
			for (int i =0 ; i<=index  ; i++)
			pr[i]=pr[i+1];
			
		index--;
		found=true;
		ncustomer--;
		cout<<"Dleted succssfully\n";
		break;
		}}
	if (!found)
	cout<<"not found\n";}

	
//A function to update the name of an employee or a customer
void update(person pr[], double id,int &index){
	found=false;
	for (int i =0 ; i<=index  ; i++){
		if (id==pr[i].id){
			
			cout<<"Enter new name: ";
			cin>>pr[i].name.first>>pr[i].name.last;
			found=true;}}
			
	if(found)
	cout<<"name was update\n";
	else
	cout<<"not found\n";}
	
void sort (person pr[],int &index){
	typedef int* intPon;
	//array  to calculate the number of customers by age group
	intPon arr=new int [5];
	
	for(int i=0;i<5;i++)
	arr[i]=0;

	//array to copy the ages of customers
	int Sage[index];
	
	int temp;
	bool ordered=false;
	
	// loop to copy the ages of customers
	for(int i=0;i<index;i++)
		Sage[i]=pr[i].age;
	
	// array to to arrange ages
	for(int i=0;i< index && ordered==false ;i++){
		ordered=true;
	
	for(int j=0; j<index ;j++)
		if(Sage[j]>Sage[j+1] ){
		
		ordered=false;
		temp=Sage[j];
		Sage[j]=Sage[j+1];
		Sage[j+1]=temp;
			}}
			
{
		for(int i=0;i<=index;i++){
		if ((Sage[i] >= 6) && (Sage[i] <=12))
		arr[0]++;
		else if((Sage[i]>=12) && (Sage[i] <=18))
		arr[1]++;
		else if ((Sage[i]>=19) && (Sage[i]<=35))
		arr[2]++;
		else if ((Sage[i]>=36) && (Sage[i]<=65))
		arr[3]++;
		else if (Sage[i]>=66)
		arr[4]++;
	}
	
	cout<<"\n\n**sorted succssfully**\n\n";
	
	cout<<"The number of childern is: "<<arr[0]<<endl
	<<"The number of teenagers is: "<<arr[1]<<endl
	<<"The number of young people is: "<<arr[2]<<endl
	<<"The number of middle-aged people is: "<<arr[3]<<endl
	<<"The number of elderly people is: "<<arr[4]<<endl;

}}

//A function to display the names of employees or customers and their ID
void view(person pr[],int index){
	if (index>=0){
	for(int i=0 ;i<index;i++)
	cout<<"\n"<<i+1<< ".\nname: "<<pr[i].name.first<<pr[i].name.last<<"\nID: "<<pr[i].id;
	}
	else
	cout<<"There are no items.";}

//these functions are for determening what kind of services the user wants to include after choosing a subscription 
void service(person pr[],int index,char a){

	char type;
	int times;
	if (a=='t'||a=='T'){
	cout<<"with a couch\n";
	cout<<"enter how many times a week: ";
	cin>>pr[index].service.train;
}
	else if(a=='e'||a=='E'){

	cout<<"you have"<<endl<<"-back equepment"<<endl<<"-arms equepment"<<endl<<"-legs equepment"<<endl<<"-full body equepment"<<endl;
	do
	{
	cout<<"witch do you want?: ";
	cin>>type;
	cout<<"enter how many times a week: ";
	cin>>pr[index].service.equipment;
	cout<<"you want more from equepment?(press y)";
	cin>>continu;
}
while(continu=='y'||continu=='Y');
	
}
	else if(a=='s'||a=='S'){
	cout<<"enter how many times a week: ";
	cin>>pr[index].service.swimming_pool;
	}
	else if(a=='r'||a=='R'){
	cout<<"enter how many times a week: ";
	cin>>pr[index].service.running_track;
	}
	else if(a=='b'||a=='B'){
	cout<<"enter how many times a week: ";
	cin>>pr[index].service.basket_ball;
	}
	}