#include<bits/stdc++.h>
#include<iostream>
#define limit 101
using namespace std;
int total;
queue<string> nameA;
queue<string> fromA;
queue<string> destinationA;
queue<bool> visitedA;
queue<string> nameB;
queue<string> fromB;
queue<string> destinationB;
queue<bool> visitedB;
queue<string> nameC;
queue<string> fromC;
queue<string> destinationC;
queue<bool> visitedC;
int trainpos;
int traincnt;
int traintot;
struct train
{
  public:
  string name;
  string from;
  string dest;	
} tr[limit],tr1[limit];

void feeddata()
{
	char choice='y';
	cout<<"\n";
	cout<<"\n";
	cout<<":::::::::::Welcome to Ticket Reservation Counter::::::::::"<<"\n";
	cout<<"\n";
	cout<<"Enter Name of the person and its Destination(eg. abhishek(First Name Only)(space)Delhi(Destination Address)(space)Amritsar): "<<"\n";
	string name="",address="",from="";
	cout<<"Start Feeding"<<"\n";
	int count=0;
	while(choice && count<=4)
	{
		A:;
		cin>>name>>from>>address;
		if(address!="Ranchi" && address!="Prayagraj" && address!="Delhi"&& from!="Ranchi" && from!="Prayagraj" && from!="Delhi")
		{
		cout<<"You have either miss-spelt the address or your destination do not match with the Train destination(Enter the detail once again--): "<<"\n";
		goto A;
	    }
	    
	    total++;
		if(from=="Ranchi")
		{
			while(!visitedA.empty()&& trainpos<=1 &&traintot<100)
			{
			  if(visitedA.front()==false)
  	             {
  	               tr[traintot].name=nameA.front();
				   tr[traintot].from=fromA.front();
				   tr[traintot].dest=destinationA.front();
  	              visitedA.pop();
	              nameA.pop();
	              fromA.pop();
	              destinationA.pop();
				  traintot++;	
	            }
	         else
	           break;	
			}
			
			if(trainpos<=1)
			{
				cout<<"Train is already standing at the Platform(Hurry Up:::)"<<"\n";
				nameA.push(name);
				fromA.push(from);
				destinationA.push(address);
				
				if(traintot<100)
				{
				tr[traintot].name=name;
				tr[traintot].from=from;
				tr[traintot].dest=address;
				visitedA.push(true);
				traintot++;
				}
				else
				visitedA.push(false);
			}
			else
			{
				cout<<traincnt<<" Train has already departed you have to wait for the next train"<<"\n";
				nameA.push(name);
				fromA.push(from);
				destinationA.push(address);
				visitedA.push(false);
			}
		}
		else if(from=="Prayagraj")
		{
			if(trainpos<2)
			{
				cout<<"Train has left the previous station: Ranchi"<<"\n";
				nameB.push(name);
				fromB.push(from);
				destinationB.push(address);
				visitedB.push(false);
			}
			else if(trainpos==2)
			{
				cout<<"Train is already standing at the Platform(Hurry Up:::)"<<"\n";
				nameB.push(name);
				fromB.push(from);
				destinationB.push(address);
				
				/*if(traintot<100)
				{
				tr[traintot].name=name;
				tr[traintot].from=from;
				tr[traintot].dest=address;
				visitedB.push(true);
				traintot++;
				}
				else*/
				visitedB.push(false);
			}
			else
			{
				cout<<traincnt<<" Train has already departed you have to wait for the next train"<<"\n";
				nameB.push(name);
				fromB.push(from);
				destinationB.push(address);
				visitedB.push(false);
			}
		}
		else if(from=="Delhi")
		{
			if(trainpos<3)
			{
				if(trainpos==1)
			    cout<<"Train has left the previous station: Ranchi"<<"\n";
			    else
			    cout<<"Train has left the previous station: Prayagraj"<<"\n";
				nameC.push(name);
				fromC.push(from);
				destinationC.push(address);	
				visitedC.push(false);
			}
			else if(trainpos==3)
			{
				cout<<"Train is already standing at the Platform(Hurry Up:::)"<<"\n";
				nameC.push(name);
				fromC.push(from);
				destinationC.push(address);
				
				/*if(traintot<100)
				{
				tr[traintot].name=name;
				tr[traintot].from=from;
				tr[traintot].dest=address;
				visitedC.push(true);
				traintot++;
				}
				else*/
				visitedC.push(false);
			}
			else
			{
				cout<<traincnt<<" Train has already departed you have to wait for the next train"<<"\n";
				nameC.push(name);
				fromC.push(from);
				destinationC.push(address);
				visitedC.push(false);
			}
		}
		count++;
		//cout<<"Enter your choice if you want to enter more passenger data y/n(y to continue and n to exit): ";
		//cin>>choice;
	}
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
}
void stationA()
{	
  int countpass=0; 
  cout<<"Welcome to Ranchi Passenger Data: "<<"\n";
  cout<<"\n";
  cout<<"\n";
  queue<string> name=nameA;
  queue<string> from=fromA;
  queue<string> destination=destinationA;
  queue<bool> visited=visitedA;
  
  cout<<"Total Person boarded on Train............."<<"\n";
  for(int i=0;i<=traintot;i++)
  {
  	cout<<tr[i].name<<" "<<tr[i].from<<" "<<tr[i].dest<<"\n";
  }
  
  while(!visitedA.empty())
  {
  	if(visitedA.front()==true)
  	{
  	  visitedA.pop();
	  nameA.pop();
	  fromA.pop();
	  destinationA.pop();	
	}
	else
	break;
  }
  
  cout<<"\n";
  cout<<"\n";
}
////////////////////////////////////BBBBBBBBBBBBBBBBBBBBBBBBBb
void stationB()
{	
  int countpass=0; 
  cout<<"\n";
  cout<<"Welcome to Prayagraj Passenger Data: "<<"\n";
  cout<<"\n";
  cout<<"\n";
  /*queue<string> name=nameA;
  queue<string> from=fromA;
  queue<string> destination=destinationA;
  queue<bool> visited=visitedA;*/
  
  cout<<"Total Person leaving(whose destination is Prayagraj)............."<<"\n";
  int k=0,t=0;
  for(int i=0;i<traintot;i++)
  {
  	if(tr[i].dest=="Prayagraj")
  	{
  	t++;
  	total--;
  	cout<<tr[i].name<<" "<<tr[i].from<<" "<<tr[i].dest<<"\n";
	  //tr[i].name="";
	  //tr[i].from="";
	  //tr[i].name="";	
	}
  	else
  	{
  	 tr1[k].dest=tr[i].dest;
	 tr1[k].name=tr[i].name;
	 tr1[k].from=tr[i].from;
	 //tr[i].name="";
	 //tr[i].from="";
	 //tr[i].name="";
	 k++;	
	}
  }
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  //cout<<"Ohhh yes"<<"\n";
  traintot=0;
  int i=0;
  for(int j=0;j<k;j++)
  {
  	traintot;
  	 tr[traintot].dest=tr1[j].dest;
	 tr[traintot].name=tr1[j].name;
	 tr[traintot].from=tr1[j].from;
	 traintot++;
	 //i++;	
  }
  //cout<<traintot<<" "<<k<<"\n";
  //cout<<"Ohhh yes"<<"\n";
  
  while(!visitedB.empty())
  {
  	if(visitedB.front()==false)
  	{
  	  if(traintot<100)
		{
		tr[traintot].name=nameB.front();
		tr[traintot].from=fromB.front();
		tr[traintot].dest=destinationB.front();
		traintot++;
		visitedB.pop();
	    nameB.pop();
	    fromB.pop();
	    destinationB.pop();
		}
		else
		break;	
	}
	else break;
  }
  cout<<"Total Person boarded on Train............."<<"\n";
  for(int i=0;i<=traintot;i++)
  {
  	cout<<tr[i].name<<" "<<tr[i].from<<" "<<tr[i].dest<<"\n";
  }
}
////////////////////////////////CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCcc
void stationC()
{	
  int countpass=0; 
  cout<<"\n";
  cout<<"Welcome to Delhi Passenger Data: "<<"\n";
  cout<<"\n";
  cout<<"\n";
  /*queue<string> name=nameA;
  queue<string> from=fromA;
  queue<string> destination=destinationA;
  queue<bool> visited=visitedA;*/
  
  cout<<"Total Person leaving(whose destination is Delhi)............."<<"\n";
  int k=0,t=0;
  for(int i=0;i<traintot;i++)
  {
  	if(tr[i].dest=="Delhi")
  	{
  	t++;
  	total--;
  	cout<<tr[i].name<<" "<<tr[i].from<<" "<<tr[i].dest<<"\n";
	  //tr[i].name="";
	  //tr[i].from="";
	  //tr[i].name="";	
	}
  	else
  	{
  	 tr1[k].dest=tr[i].dest;
	 tr1[k].name=tr[i].name;
	 tr1[k].from=tr[i].from;
	 //tr[i].name="";
	 //tr[i].from="";
	 //tr[i].name="";
	 k++;	
	}
  }
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  //cout<<"Ohhh yes"<<"\n";
  traintot=0;
  int i=0;
  for(int j=0;j<k;j++)
  {
  	traintot;
  	 tr[traintot].dest=tr1[j].dest;
	 tr[traintot].name=tr1[j].name;
	 tr[traintot].from=tr1[j].from;
	 traintot++;
	 //i++;	
  }
  //cout<<traintot<<" "<<k<<"\n";
  //cout<<"Ohhh yes"<<"\n";
  
  while(!visitedC.empty())
  {
  	if(visitedC.front()==false)
  	{
  	  if(traintot<100)
		{
		tr[traintot].name=nameC.front();
		tr[traintot].from=fromC.front();
		tr[traintot].dest=destinationC.front();
		traintot++;
		visitedC.pop();
	    nameC.pop();
	    fromC.pop();
	    destinationC.pop();
		}
		else
		break;	
	}
	else break;
  }
  cout<<"Total Person boarded on Train............."<<"\n";
  for(int i=0;i<=traintot;i++)
  {
  	cout<<tr[i].name<<" "<<tr[i].from<<" "<<tr[i].dest<<"\n";
  }
}
//////////////////////////////DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
void stationD()
{
  cout<<"\n";
  cout<<"Welcome to Amritsar Passenger Data: "<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"Total Person leaving(whose destination is Amritsar)............."<<"\n";
  int k=0,t=0;
  for(int i=0;i<traintot;i++)
  {
  	if(tr[i].dest=="Amritsar")
  	{
  	t++;
  	total--;
  	cout<<tr[i].name<<" "<<tr[i].from<<" "<<tr[i].dest<<"\n";
	  tr[i].name="";
	  tr[i].from="";
	  tr[i].dest="";	
	}
  }
}
int main()
{
	//struct train tr[101];
	cout<<"=======================Welcome To Indian Railway======================="<<"\n";
	cout<<"Current Information About Your Rajdhani Express:->"<<"\n";
	cout<<"Total seats: 100"<<"\n";
	cout<<"Starts from Ranchi and will go all the way to Amritsar"<<"\n";
	cout<<"Currently Your train is about to start from Ranchi"<<"\n";
	cout<<"\n";
	cout<<"\n";
	
	cout<<"Its InterMediate Station are --Prayagraj--New Delhi-->Amritsar";
	cout<<"\n";
	//total=100;----------------------------> important
	char choice='y';
	trainpos=1;
	traincnt=1;
	traintot=0;
	while(choice=='y')
	{
		//cout<<total<<"\n";
		feeddata(); // this will be called only if the train is between any two station. the Passenger cannot book the train if the train has already reached the station.
		cout<<"Train is leaving from the station: Ranchi--->>"<<"\n";
		trainpos++;
		stationA();
		feeddata();
		cout<<"Train has arrived to the station: Prayagraj--->>"<<"\n";
		trainpos++;
		stationB();
		cout<<"Train is leaving from the station: Prayagraj--->>"<<"\n";
		////-->>>>>>>>>>> today.........30.03.2020
		feeddata();
		cout<<"Train has arrived to the station: New Delhi--->>"<<"\n";
		stationC();
		cout<<"Train is leaving from the station: New Delhi--->>"<<"\n";
		trainpos++;
		feeddata();
		cout<<"Train has reached its destination: Amritsar--->>"<<"\n";
		stationD();
		total-=traintot;
		traintot=0;
		trainpos=1;
		
		// sleep of 5 sec----------------->>>>>>>>>>>> here
		cout<<"Enter your choice if you want to run more Train y/n (y to continue and n to exit): ";
		traincnt++;
		cin>>choice;
	}
	
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"Thank you for using--->>>>>>>>>>>>>>>>>>>>>>>>>>"<<"\n";
}
