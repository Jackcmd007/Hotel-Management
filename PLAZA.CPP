#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

char roomname[20]={"__________"};
class cost
  {
  char name[10];
  char country[12];
  char city[12];
  int build; 
  int street;
  long num;
  long credit;
  char room[20];
  
 	public:
		void getdata();
		void putdata();
		void modify();
		int get_phoneno();
		void entroom();
}cust;

void cost::getdata()
{
	cout<<"Enter the Details \n";
    cout<<"Name- ";
	cin>>name;
	cout<<"----address----- \n";
	cout<<"Country - ";
	cin>>country;
	cout<<"\nCity- ";
	cin>>city;
	cout<<"\nStreet- ";
	cin>>street;
	cout<<"\nBuilding- ";
	cin>>build;
	cout<<"Mobile Number";
	cin>>num;
	cout<<"Credit Card Number";
	cin>>credit;
 }   

void cost::entroom()
{
 strcpy (room,roomname);
}

void cost::putdata()
{
	cout<<"-------------------------\n";
	cout<<"Name- "<<name<<endl;
	cout<<"Address- Building "<<build <<", Street " <<street <<", "<<endl;
                    cout<<city <<", "<<country  <<endl;
	cout<<"Mobile Number - "<<num<<endl;
	cout<<"Credit Card Number - **********321"<<endl;
	cout<<"Suite booked - "<<room <<"\n";
	
}

void cost::modify()
{
	char nm[20]=" ",nwcountry[12],nwcity[12];
  int nwbuild, nwstreet;
  long nwnum,nwcredit;
	cout<<"Enter the new details \n";
	cout<<"New Name \n";
    cin>>nm;
   	cout<<"----address----- \n";
	cout<<"Country - ";
	cin>>nwcountry;
	cout<<"\nCity- ";
	cin>>nwcity;
	cout<<"\nStreet- ";
	cin>>nwstreet;
	cout<<"\nBuilding- ";
	cin>>nwbuild;
	cout<<"Mobile Number";
	cin>>nwnum;
	cout<<"Credit Card Number";
	cin>>nwcredit;
    strcpy(name,nm);
    strcpy(city,nwcity);
    strcpy(country,nwcountry);
    street=nwstreet;
    build=nwbuild;
    credit=nwcredit;
    num=nwnum;
       
}


int cost::get_phoneno()
  {
   return num;
  }

void roominfo();
void admin();
void search();
void mod();
void delet();
void write();
void read();
void plaza();
void carn();
void ellin();
void studio();
void menu();
void junior();
void connecting();
void royal();
void book(int cost);

int main()
{
system("cls");
float phone;
char choice;
cout<<"\n--------------------------------------------------------------------------------\n";
cout<<"       WELCOME TO THE PLAZA HOTEL     \n";
cout<<"           www.theplazany.com     \n";
cout<<"Address: 768 5th Ave, New York, NY 10019, USA\n";
cout<<"Phone: +1 212-759-3000 \n";
cout<<"\n--------------------------------------------------------------------------------\n";
cout<<"Login to continue -\n";
cout<<"1- Admin \n";
cout<<"2- User \n";
cout<<"Enter your choice \n";
cin>>choice;
 char pass[10],user[10];
if(choice=='1')      
  admin();
 else
    {  
cout<<"\nEnter your username \n";
cin>>user;
cout<<"\nEnter your password (default password is your first name)\n";
cin>>pass;
cout<<"\n \nSigned In \n";
menu();
return 0;
}
}

void menu()
{
int ch;
do
	{
cout<<"\n--------------------------------------------------------------------------------\n";
cout<<"\n\t USER MODE";
cout<<"\n1. READ CUSTOMER INFO ";
cout<<"\n2. RESERVE OF ROOMS \n";
cout<<"\n3. RETURN TO MAIN MENU \n";
cout<<"  Enter your choice \n";
cin>>ch;
switch (ch)
{
	    case 1: write();
	     break;
	    case 2:roominfo();
	       break;
	    case 3:main();
	       break;
        default:cout<<"Invalid Input \n" ;
                 
}
	} while(ch<4);
	      
}


void admin()
{
char pass[10];
cout<<"\nEnter the password \n";
cin>>pass;
int y;
do
	{
cout<<"\n\t ADMIN MODE";
cout<<"\n1. READ CUSTOMER INFO ";
cout<<"\n2. DISPLAY CUSTOMER INFO ";
cout<<"\n3. RESERVE A ROOM ";
cout<<"\n4. MODIFY CUSTOMER INFO ";
cout<<"\n5. SEARCH CUSTOMER INFO ";
cout<<"\n6. DELETE CUSTOMER INFO ";
cout<<"\n7. RETURN TO MAIN MENU ";
cout<<"\n8. EXIT ";
cout<<"\n  Enter your choice \n";
cin>>y;
switch (y)
{
	    case 1: write();
	     break;
	    case 2:read();
	     break;
	    case 3:roominfo();
	    break;
        case 4:mod();
		 break;
		case 5:search();
	     break;
        case 6:delet();
	     break;
	    case 7:main();
	       break;
		case 8:exit(0);
		}
	} while(y <8);
	      
}


void roominfo()
{
int vq;
  cout<<"We have six different type of rooms & suites \n";
  cout<<"1. Carnegie Park Suite \n";
  cout<<"2. Ellington Park Suite \n";  
  cout<<"3. Studio Suite \n";
  cout<<"4. Junior Suite \n";
  cout<<"5. Connecting Deluxe \n";   
  cout<<"6. The Royal Suite \n";
  cout<<"Enter your choice \n";
cin>>vq;
switch (vq)
{
	   case 1: carn();
	     break;
	   case 2:ellin();
	     break;
	   case 3:junior();
	       break;
	   case 4: studio();
	     break;
	   case 5:connecting();
	      break;
	   case 6:royal();
	      break;
        default:cout<<"Invalid Input \n" ;
}
}


void write()
{
	char ch='y';
	ofstream ofile;
	ofile.open("hotel.dat",ios::binary|ios::out);
	while (ch=='y'|| ch=='Y')
	{
		cust.getdata();
		ofile.write((char*)&cust,sizeof(cust));
		cout<<"Do you want to continue (y/n) \n";
		cin>>ch;
		}
	ofile.close();
	cout<<"\n--------------------------------------------------------------------------------\n";

	
}


void read()
{
	ifstream ifile;
	ifile.open("hotel.dat");
	while(ifile.read((char*)&cust,sizeof(cust)))
	{
		cust.putdata();
	}
		ifile.close();
		cout<<"\n--------------------------------------------------------------------------------\n";
	
}


void carn()
{
int cb;     // Carnegie Park Suite (legacy)
cout<<"\n Carnegie Park Suite  \n";
cout<<"The Carnegie Park Suites offer a wonderful partial view of Central Park. Decorated with custom designed furnishings and rich fabrics, these luxurious and spacious (1,000 sq. ft.) one bedroom Legacy Suites offer a well-designed separate living room, Butler’s pantry and a powder room for guests. The bathroom is finished with inlaid “earth stone” mosaics in floral motifs, with a bathtub as well as separate shower. Bathroom details also include 24-karat gold plated Sherle Wagner faucets and accessories with hand crafted solid white marble vanities. The Carnegie Park Suites have 1 King bed and are located on floors 11 – 19.  \n";
cout<<"1. Book this room \n";
cout<<"Enter any other key to return to the previous menu \n";
cin>>cb;
switch (cb)
{
case 1: strncpy(roomname,"Carnegie",sizeof roomname);
        book(2500);
        
         break;
default:roominfo();
}
}

//Ellington Park Suite (legacy)
void ellin()
{
int z;
cout<<"\n Ellington Park Suite \n";
cout<<"Decorated with custom designed furnishings and rich fabrics,these luxurious and spacious (1,550 square feet) two bedroom and two bathroom suites offer a King size bed in each room, a well designed living room, Butler's pantry and a powder room for guests.  The one bedroom Legacy Suite connects to the second room via a private foyer. \n";
cout<<"1. Book this room \n";
cout<<"Enter any other key to return to the previous menu \n";
cin>>z;
switch (z)
{
case 1: strncpy(roomname,"EllingtonPark",sizeof roomname);
         book(3700);
      
	     break;
default:roominfo();
}
}




void studio()       // studio suits (junior)
{
int q;
cout<<"\n Studio Suite \n";
cout<<"Studio Suites are open concept rooms offering a spacious sitting area and a Butler's pantry.The bathroom is finished with inlaid earth stone” mosaics in floral motifs, with a bathtub and a separate shower. Bathroom details also include 24-carat gold plated Sherle Wagner faucets and accessories with hand crafted solid white marble vanities. Studio Suites are located on floors 11 to 16.\n";
cout<<"1. Book this room \n";
cout<<"Enter any other key to return to the previous menu \n";
cin>>q;
switch (q)
{
case 1: strncpy(roomname,"Studio",sizeof roomname);
        book(1000);
	     break;
default:roominfo();
}
}

void junior()   //junior suites
{
int ww;
cout<<"\n Junior Suite \n";
cout<<"Located on floors 11 to 19, the very spacious Junior Suite is an open concept room that offers a generously sized sitting area that is perfect for lounging with family and friends.A beautifully carved writing desk provides a discrete place to tend to business and personal affairs.  Generously sized baths are decorated with marble mosaic tile and adorned with 24-carat gold  plated Sherle Wagner fixtures. As a Junior Suite guest you will enjoy Butler Services. \n";
cout<<"1. Book this room \n";
cout<<"Enter any other key to return to the previous menu \n";
cin>>ww;
switch (ww)
{
case 1: strncpy(roomname,"Junior",sizeof roomname);
        book(1100);
	     break;
default:roominfo();
}
}

void connecting()   //connecting suits
{
int qp;
cout<<"\n Connecting Deluxe \n";
cout<<" The Connecting Deluxe are two spacious guestrooms that connect to create a unique space that is ideal for families.The master bedroom has a king bed and the second bedroom has two queen beds. Each bedroom has its own large bathroom featuring mosaic tiles and gold-plated Sherle Wagner fixtures, a comfortable sitting area, and a writing desk. \n";
cout<<"1. Book this room \n";
cout<<"Enter any other key to return to the previous menu \n";
cin>>qp;
switch (qp)
{
case 1: strncpy(roomname,"ConnectingDeluxe",sizeof roomname);
         book(2050);
	     break;
default:roominfo();
}
}
 
 

void royal()   //The Royal Suite
{
int tp;
cout<<"\n The Royal Suite \n";
cout<<" The one-of-a-kind Royal Suite is a magnificent, three-bedroom suite in a private area of the hotel overlooking Fifth Avenue and the Pulitzer Fountain.The elaborate array of private and social rooms, rich decorative style, sumptuous textiles and exquisite furnishings are all inspired by the ambiance of the royal court of Louis XV. The Royal Suite also offers a fitness room with state-of-the-art equipment, providing an additional measure of privacy for guests.As a guest of The Royal Suite you will enjoy personal Butler Services.Guests can host a party of twelve in the dining room after dinner is prepared in a state-of-the-art kitchen that  is ideal for guests who travel with a personal chef.  \n";
cout<<"1. Book this room \n";
cout<<"Enter any other key to return to the previous menu \n";
cin>>tp;
switch (tp)
{
case 1: strncpy(roomname,"Royal",sizeof roomname);
        book(30000);
	     break;
default:roominfo();
}
}

void book (int cost)
{
	
	ofstream ofile;
	ofile.open("hotel.dat",ios::binary|ios::out);
	{
		cust.entroom();
		ofile.write((char*)&cust,sizeof(cust));
	   	ofile.close();
		   
	}	
	
int adult,days,child,price,discount,home,total;
char ch;
cout<<"Enter number of adults \n" ;
cin>>adult;
cout<<"Enter number of children (below the age 12) \n";
cin>>child;
cout<<"Enter the number of days \n";
cin>>days;
int guests=adult+child;
price= cost+(50*child)+(150*adult);
discount=price/10;
total= price-discount;
cout<<"---------------------------------------------------------\n";
cout<<"\n Cost of suite for  "<<guests<<"guests for "<<days <<" days = $"<<total;
cout<<"\n Total amount to be paid \n= $ "<<total;
	cout<<"Do you want to reserve this room (y/n) \n";
		cin>>ch;
 if(ch=='y')      
  cout<<"Thank You \n We hope you enjoy your stay with us!  \n";

}


void search()
{
	long number;
	int found=0;
	ifstream ifile;
	ifile.open("hotel.dat");
	cout<<"\nEnter the phone number to be searched \n";
	cin>>number;
	while(!ifile.eof())
	{
	ifile.read((char*)&cust,sizeof(cust));
	if(cust.get_phoneno()==number)
       {
       	cust.putdata();
       	found=1;
       	break;
  	   }
    }
if(found==0)
cout<<"record not fouund \n";
ifile.close();
}
 

void mod()
{
	long no,found=0;
	long pos;
	fstream file;
	file.open("hotel.dat",ios::out|ios::in);
	cout<<"\n Enter the phone number of the customer to be modified \n";
	cin>>no;
    while(!file.eof())
	{
	int pos=file.tellg();
	file.read((char*)&cust,sizeof(cust));
	if(cust.get_phoneno()==no)
	   {
	   	cust.putdata();
	   	cout<<"Do you want to modify(y/n) \n";
		  char ch;
		  cin>>ch;
		  if(ch=='y')
		 { 
			cust.modify();
			file.seekp(pos);
			file.write((char*)&cust,sizeof(cust));
			found=1;
			break;
		 } 
		 
       }
    }
if (found==0)
cout<<"Record not found";
file.close();
}


void delet()
{
	ifstream ifile ("hotel.dat",ios::in);
	ofstream ofile ("temp.dat",ios::out);
	long pno;
	cout<<"\nEnter the phone number to be deleted \n";
	cin>>pno;
	while(!ifile.eof())
	   {
     	ifile.read((char*)&cust,sizeof(cust));
    	if(cust.get_phoneno()!=pno)
    	ofile.write((char*)&cust,sizeof(cust));
       }
    ifile.close();
    ofile.close();
    remove("hotel.dat");
    rename("temp.dat","hotel.dat");
}





























