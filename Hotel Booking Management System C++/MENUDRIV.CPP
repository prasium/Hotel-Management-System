#include<fstream.h>
#include<conio.h>
#include<iomanip.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
  struct date_
   { int dd,mm,yy;
    };
 void ed();     //Modification portal
 void menu();   //displays booking menu
 void organise();  //organises main menu
 int editmenu();   //displays editable options
 int confirm();     //asks for confirmation
  void roomtypes();  //shows types of rooms
  void pay();     // billing
  void check_rnocode(int rnum);

  class room
  {
    int room_type;
    float roomfare;
    public:
    room()
    {
    room_type=0;
    roomfare=0;
    }
    float fare_room();
    void roomsel();
    void allotment();
   };

 class hotel : public room
 { char name[30];
   int roomno;
   date_ doa;
   int day;
   int age;
   public:
  void getdet();
  void dis();
  int roomn();
  int verify(int);
  void bill(int);
  void filei();
  void modify();
  void roombkd();
  void del();
  hotel()
  {
   strcpy(name,"N/A");
   roomno=0;
   day=0;
   age=0;
   }
      }obj;
  void check_rnocode(int rnum)
  {
      cout<<endl;
     if(obj.fare_room()==300)
     {
       while(!(rnum>=101&&rnum<=199))
	{
	  cout<<"Enter room no. in the range of the selected room type ";
	  cin>>rnum;
	  }
       }
     else if(obj.fare_room()==600)
       {
       while(!(rnum>=201&&rnum<=299))
	 {
	  cout<<"Enter room no. in the range of the selected room type ";
	  cin>>rnum;
	  }
	}
      else if(obj.fare_room()==700)
    {
	while(!(rnum>=301&&rnum<=399))
       {
	  cout<<"Enter room no. in the range of the selected room type ";
	  cin>>rnum;
	  }
      }
      else if(obj.fare_room()==1400)
     {
	while(!(rnum>=401&&rnum<=499))
       {
	  cout<<"Enter room no. in the range of the selected room type ";
	  cin>>rnum;
	  }
      }
      else if(obj.fare_room()==2000)
	while(!(rnum>=501&&rnum<=599))
       {
	  cout<<"Enter room no. in the range of the selected room type ";
	  cin>>rnum;
	  }
       else
	 cout<<"This room no. doesn't exist in our hotel,enter valid room no.";
       }
  void room:: roomsel()
  {
   textcolor(YELLOW);
     clrscr();
     cout<<"\n\n"<<endl<<"\t\tROOM TYPES:  \t \t         PRICE  \t  ROOM NO CODE\n\n";
    cout<<"\n\t\t1.SINGLE ROOM (NON A.C)          -   300/-\t  101-199"<<
	  "\n\t\t2.SINGLE ROOM(A.C)               -   600/-\t  201-299"<<
	  "\n\t\t3.DOUBLE ROOM (NON A.C)          -   700/-\t  301-399"<<
	  "\n\t\t4.DOUBLE ROOM (A.C.)             -   1400/-\t  401-499"<<
	  "\n\t\t5.DELUXE SUITE                   -   2000/-\t  501-599";
	  cout<<"\n prices are as per day in INR ";
  }
  void room::allotment()
  {  start :
    cout<<"\n Select your choice : ";
    cin>>room_type;
    switch(room_type)
    {
    case 1 : roomfare=300;
		 break;
    case 2 : roomfare=600;
		 break;
    case 3 : roomfare=700;
	    break;
    case 4 : roomfare=1400;
		 break;
    case 5 : roomfare=2000;
		 break;
    default : {
		 cout<<"\n Oops Wrong choice , try again ";
		  goto start;
	       }
	 }
  }

  float room :: fare_room()
  {
   return roomfare;
   }
      void hotel :: getdet()
    {
       textcolor(LIGHTRED);
       clrscr();
	 ofstream fout;
	 fout.open("Hotel.dat",ios::app);
 char o;
       int flag=1;
       cout<<endl<<setw(45)<<"| GUEST DATA |";
     do{
    cout<<"\n Enter your name :" ;
    gets(name);
   for(int i=0;i<strlen(name);i++)
     {
     if(name[i]>='0'&&name[i]<='9')
      {
     cout<<"\n Please enter alphabets only ";
     flag=0;
     break;
       }
       else
       flag=1;
      }
     }while(flag!=1);
     do{
	 cout<<"\n Enter Age :";
	 cin>>age;
	 if(!(age>=1&&age<=99))
	 {
	  cout<<"Enter valid age try again";
	  continue;
	  }
       }while(!(age>=1&&age<=99));

		cout<<" Enter Check-in date (DD-MM-YY):";
     do{
       cout<<"\n date -";
       cin>>doa.dd;
       if(!(doa.dd>=1&&doa.dd<=31))
       cout<<"\n Invalid date range enter again";
       continue;
       }while(!(doa.dd>=1&&doa.dd<=31));

      do{
	cout<<"\n month -";
	cin>>doa.mm;
	if(!(doa.mm>=1&&doa.mm<=12))
     {
	cout<<"\n Invalid month range try again";
	continue;
      }
	}while(!(doa.mm>=1&&doa.mm<=12));
      do{
	  cout<<"\n year -";
	  cin>>doa.yy;
	   if(!(doa.yy>=18&&doa.yy<=19))
	    {
	     cout<<"\n Invalid year input try again";
	     continue;
	    }
	}while(!(doa.yy>=18&&doa.yy<=19));

	int temp=0;
	roomsel();
       allotment();
       cout<<"\n Room Number to be alloted :";
   do{
       cin>>temp;
       flag=verify(temp);
       if (!flag)
       {
       roomno=temp;
	}
	else
	cout<<"\n Room is already booked for someone else\nEnter another room no.:" ;
      }while(flag!=0);
       cout<<"\n Stay for how many days? :";
       cin>>day;
       cout<<"\n \t do you want to save these details?(y/n) :";
     cin>>o;
	if(o=='y'||o=='Y')
       {
	  fout.write((char *)&obj,sizeof(obj));
	  cout<<"Room Booked & Details saved";
	}
	else
     cout<<"Details not saved! ";
	 fout.close();
     getch();
  }

      int hotel :: roomn()
   {
   return roomno;
   }

   int hotel::verify(int rno)
{
    int flag=0;    hotel tempobj;
     check_rnocode(rno);
    ifstream fin("Hotel.dat",ios::in|ios::beg);
     if(!fin)
     cout<<"File doesn't exist, creating file... ";
     else
   {
     while(fin.read((char *)&tempobj,sizeof(tempobj)))
       {
	if(tempobj.roomn()==rno)
	   {
	       flag=1;
	       break;
	   }
       }
    }

    fin.close();
    return(flag);
}



    void hotel::roombkd()
{
    textcolor(CYAN);
    clrscr();
    ifstream fin("Hotel.dat",ios::in);
    cout<<"\n\t\t\tList Of Rooms Allotted";
    cout<<"\n\t\t\t*********************";
    cout<<"\n\n Room No.\tName\t\tAge\t\t Stay(in Days)\n";

    while(fin.read((char*)&obj,sizeof(obj)))
    {
	cout<<"\n\n "<<roomno<<"\t\t"<<name;
	cout<<"\t\t"<<age<<"\t\t"<<day;
    }

    cout<<"\n\n\n\t\tPress any key to continue!!";
    getch();
    fin.close();
}

  void hotel :: del()
  {    textcolor(LIGHTRED);
	   clrscr();
     int flag=0,rno=0;
     cout<<"\n Enter room no. :";
     cin>>rno;
     char ch;
    ifstream fin("Hotel.dat",ios::in|ios::beg);
    ofstream fout("temp.dat",ios::out);
    if(!fin)
    { cout<<"file not found ";
     exit(0);
     }
     else{
    while(fin.read((char*)&obj,sizeof(obj)))
    {
	if(obj.roomn()==rno)
	{
	    cout<<"\nRoom has been booked for "<<name;
	    cout<<"\n\n Do you want to delete this person's data? (y/n): ";
	    cin>>ch;
	    if(ch=='y'||'Y')
	    {
	     cout<<" Deleted ! ";
	     flag=1;
	     }
	    else if(ch=='N'||'n')
	   {
	    cout<<"not deleted ! ";
	   fout.write((char*)&obj,sizeof(obj));
	   }
	}
	else
	fout.write((char*)&obj,sizeof(obj));
    }

    fin.close();
    fout.close();
    if(flag==0)
	cout<<"\n Sorry room no. not found or vacant!!";
    else
    {
	remove("Hotel.dat");
	rename("temp.dat","Hotel.dat");
    }
   }
   getch();
  }

   void ed()
    {
       textcolor(CYAN);
       clrscr();
	cout<<setw(40)<<" WELCOME TO THE MODIFICATION PORTAL ";
      int flag=0,pos=0,mod=0;
      fstream fio;
      cout<<"\n\n Enter the room no. to modify details :";
      cin>>mod;
      fio.open("Hotel.dat",ios::beg|ios::in|ios::out);
       while(fio.read((char *)&obj,sizeof(obj)))
    {
	pos=fio.tellg();
       if(mod==obj.roomn())
       {
	 obj.modify();
	fio.seekg(pos);
	fio.write((char *)&obj,sizeof(obj));
		    flag=1;
	 break;
	 }
	else
	flag=0;
	}
     if(!flag)
     cout<<"\n Oops ,No booking for this room no. \n press any key to go back to main menu";
    fio.close();
   getch();
   }
   void hotel :: dis()
   {
      cout<<setw(50)<<"\n DISPLAY TAB";
      cout<<"\n NAME :"<<name<<"\n";
      cout<<"\n DATE CHECKED-IN :"<<doa.dd<<"-"<<doa.mm<<"-"<<doa.yy;
      cout<<"\n \n AGE :"<<age;
      cout<<"\n \n STAYING FOR "<<day<<" DAY/DAYS ";
      cout<<" IN ROOM NO.- "<<roomno;
    }

       void hotel::bill(int rno)
 {
   float pay=0; int  flag=0;
   date_ doco;
    ifstream fin;
      fin.open("Hotel.dat",ios::beg);
       while(fin.read((char *)&obj,sizeof(obj)))
    {
       if(rno==obj.roomn())
	{
	   flag=1;
  doco.dd=obj.doa.dd+day;
  doco.mm=obj.doa.mm;
  doco.yy=obj.doa.yy;
	   cout<<" \n Guest Details :- \n ";
	   dis();
	  pay=(day*fare_room());
	  cout<<"\n You've to pay Rs "<<pay<<" for your "<<day<<" day/days stay ";
	  cout<<"\n Checking out on :"<<doco.dd<<"-"<<doco.mm<<"-"<<doco.yy;
	  cout<<"\n THANK YOU, SEE YOU SOON :) ";
	    break;
	   }
	else
	flag=0;
     }
     if(!flag)
     cout<<"Oops ,No booking for this room no. \n press any key to go back to main menu";
     getch();
    fin.close();
  }

      int editmenu()
   {
	int temp=0;
    cout<<setw(30)<<"| Select what do you want to edit? |";
    cout<<"\n 1. Name \n 2.Age \n 3.Stay ";
    cout<<"\n Your choice :";
    cin>>temp;
    return temp;
   }
     void hotel :: modify ()
    {

	int choice=editmenu();
    cout<<"\n \n You've selected choice "<<choice;
    switch(choice)
    {
     case 1 : {  char nm[30];
		  cout<<"\n Enter new name ";
		  gets(nm);
		 if( confirm())
		  {
		  strcpy(name,nm);
		   }
		 }
		   break;
    case 2 :  {
		 cout<<" age ";
		 int a;
		 cout<<" \n correct age : ";
		 cin>>a;
	       if(confirm())
	       {	 age=a;
		}
	       }
	      break;
   case 3 : {
	      int d=0;
	     cout<<"no. of days to stay ";
	     cout<<"\n Enter new ";
	     cin>>d;
	       if(confirm())
	       {	day=d;
	       }
	     }
		break;
   default : cout<<"Wrong choice exiting modification portal ";
	 }
 }
    void main()
    {
     clrscr();
     textcolor(LIGHTRED);
     cout<<"\n\n"<<setw(40)<<"* * * * * * * * * * * * * * * * * * * * * * * ";
     cout<<"\n\n \t\t Project \n On \t \t \t \n Title : Hotel Booking Management  System \n";
     cout<<" for partial fulfilment of  AISSCE 2017-18 \n \n";
     cout<<"\t \t | GROUP MEMBERS | \n \t 1. Prasun Verma \n \t 2. E Priyangkar \n \t";
     cout<<"Tanvir Ahmed Laskar \n \n \t School : Kendriya Vidyalaya Silchar ";
     cout<<"\n Press Any Key To Continue ....";
     cout<<"\n \n \n \n"<<setw(40)<<"* * * * * * * * * * * * * * * * * * * * * * \n ";
     sleep(5);
     organise();
    }

void organise()
{
 clrscr();
  int choice=0;
do{
  textcolor(GREEN);
  clrscr();
  cout<<setw(60)<<"||| WELCOME TO THE GALAXY HOTEL ||| \n \n";
    cout<<setw(50)<<"1. BOOKING MENU \n \n ";
    cout<<setw(47)<<"2. ROOM TYPES \n \n ";
    cout<<setw(44)<<"3. BILLING \n \n " ;
    cout<<setw(41)<<"0. EXIT \n \n ";
    cout<<"\n Select from above  \n Your Choice : ";
    cin>>choice;
    switch(choice)
     {
     case 1: {
	       menu();
	      }
	   break;
      case 2 : {
		    textcolor(CYAN);
		   clrscr();
		    roomtypes();
		    cout<<"\n Press any key to continue ";
		    getch();
		}
	       break;
      case 3 :     {
			 textcolor(YELLOW);
			 clrscr();
			 pay();
		   }
		   break;
      case 0: exit(0);
	       break;
      default: cout<<"\n Wrong choice,try again ";
	}
    }while(choice!=0);
}

void menu()
{  int s=0;
  do
  {
   textcolor(MAGENTA);
   clrscr();
   cout<<setw(54)<<" -------BOOKING PORTAL------- \n \n";
   cout<<setw(55)<<" Select the operation to perform \n \n";
   cout<<setw(43)<<"1. To Book a New Room \n \n";
   cout<<setw(42)<<"2. To View a Booking \n \n";
   cout<<setw(40)<<"3. Edit a Booking \n \n ";
   cout<<setw(40)<<"4. Delete a Booking \n \n";
   cout<<setw(49)<<"5. To View all booked rooms \n \n";
   cout<<setw(35)<<"6. To Go Back \n \n";
   cout<<setw(29)<<"0. To Exit ";
   cout<<"\n Your Choice : ";
   cin>>s;
   switch(s)
   {
      case 0: exit(0);
		 break;
      case 1:  obj.getdet();
		break;
      case 2:  obj.filei();
	       break;
     case 3 : ed();
	      break;
     case 4:  obj.del();
		 break;
     case 5:   obj.roombkd();
		 break;
     case 6 :  organise();
	      break;
     default: {
	     cout<<" \n Oops wrong choice";
	     cout<<"\n press any key , try again ";
	     getch();
		}
     }
    }while(s!=0);
  }

void pay()
{
 int rno=0;
 cout<<setw(50)<<"| THIS IS PAYMENT PORTAL |";
 cout<<"\n \n  Enter the room no. :";
 cin>>rno;
 obj.bill(rno);
   }

void hotel:: filei()
 {
   textcolor(LIGHTBLUE);
   clrscr();
   int x=0,flag=0;
      cout<<"\n Enter room no. ";
      cin>>x;
      ifstream fin;
      fin.open("Hotel.dat",ios::in|ios::beg);
       while(fin.read((char *)&obj,sizeof(obj)))
    {
       if(x==obj.roomn())
	{
	 cout<<"\n \t  GUEST DETAILS \t \n ";
	 dis();
	 flag=1;
	 break;
	}
	else
	flag=0;
    }
     if(!flag)
     cout<<"\n Oops ,No booking for this room no. \n press any key to go back to main menu";
     getch();
     fin.close();
    }

  void roomtypes()
  {
   char arr[100];
    ifstream fin;
    fin.open("roomtype.dat",ios::in|ios::beg);
    if(!fin)
    cout<<"\n cannot open ,file doesn't exist";
    else
    {
      while(!fin.eof())
       {
       cout<<endl;
       for(int i=0;i<3;i++)
	 {
	  fin>>arr;
	  cout<<arr<<"\t ";
	 }
	   cout<<endl;
	}
     }
     fin.close();
  }
 int confirm()
 {
  char conf;
  cout<<"\n Are you sure (y/n): ";
  cin>>conf;
  if(conf=='y'||conf=='Y')
  {
   return 1;
   }
   else
   {
   cout<<"Unchanged ! ";
    return 0;
    }
 }

