#include<bits/stdc++.h>
using namespace std;    
class donor
{
public:
    string name;
    string mobileNumber;
    string bloodgroup;
    string hospitalName;
    string city;
    donor(string name,string mobilenumber,string bg,string hn,string city)
    {
        this->name=name;
        mobileNumber=mobilenumber;
        bloodgroup=bg;
        hospitalName=hn;
        this->city=city;

    }
    

};

void add_donor(string name,string mn,string bg,string hospitalname,string city,vector <donor*> *alldonors)
{
    donor* d1= new donor(name,mn,bg,hospitalname,city);
    alldonors->push_back(d1);
    cout<<"Donor Added!!\n";
}

void raise_request(string bloodGroup,vector <donor*> *alldonors)
{
    bool availability=false;
    for(int i=0;i<alldonors->size();i++)
    {
        if(((*alldonors)[i])->bloodgroup==bloodGroup)
        {
            cout<<"\nBlood is Available!!\n";
            availability=true;
        }
        continue;
    }
    for(int i=0;i<alldonors->size();i++)
    {
        if(((*alldonors)[i])->bloodgroup==bloodGroup)
        {
            cout<<"Hospital Name:"<<((*alldonors)[i])->hospitalName<<endl<<"City:"<<((*alldonors)[i])->city<<endl;
        }   
    }
    if(availability==false)
    {
        cout<<"Blood not Available!!\n";
    }
    
}


void search_bg(string bg,vector <donor*> *alldonors)
{
    bool availability=false;
    for(int i=0;i<alldonors->size();i++)
    {
        if(((*alldonors)[i])->bloodgroup==bg)
        {
            cout<<"\nBlood is Available!!\n";
            availability=true;
        }
        continue;
    }
    for(int i=0;i<alldonors->size();i++)
    {
        if(((*alldonors)[i])->bloodgroup==bg)
        {
            cout<<"Name of donor:"<<((*alldonors)[i])->name<<endl<<"Conatct number:"<<((*alldonors)[i])->mobileNumber<<endl;
        }
    }
    if(availability==false)
    {
        cout<<"Blood not Available!!\n";
    }
    return;
}


void search_city(string city,vector <donor*> *alldonors)
{
    bool availability=false;
    for(int i=0;i<alldonors->size();i++)
    {
        if(((*alldonors)[i])->city==city)
        {
            cout<<"\nBlood is Available!!\n";
            availability=true;
        }
        continue;
    }

    for(int i=0;i<alldonors->size();i++)
    {
        if(((*alldonors)[i])->city==city)
        {
            cout<<"Name:"<<((*alldonors)[i])->name<<endl<<"Conatct number:"<<((*alldonors)[i])->mobileNumber<<endl;
        }
        cout<<endl;
    }
    if(availability==false)
    {
        cout<<"Blood not Available!!\n";
    }
}

void send_request(vector <donor*> *alldonors)
{
    for(int i=0;i<alldonors->size();i++)
    {
        cout<<"Notification send successfully to MobileNumber:"<<((*alldonors)[i])->mobileNumber<<endl;      
    }
  cout<<endl;
  
}

int main()
{
    int n;
    string name,bg,hospitalname,mn,city;
    vector <donor*> *alldonors= new vector <donor*>();

    donor* d1= new donor("ramesh","1234","a+","max","noida");
    alldonors->push_back(d1);
    d1= new donor("suresh","121554","b+","fortis","noida");
    alldonors->push_back(d1);
    d1= new donor("steve","4845542","b-","yashodra","noida");
    alldonors->push_back(d1);
    d1= new donor("peter","118934","a-","devnandini","noida");
    alldonors->push_back(d1);
    d1= new donor("alan","1284534","ab+","aims","noida");
    alldonors->push_back(d1);
    d1= new donor("kent","1234774","ab-","fortis","delhi");
    alldonors->push_back(d1);
    d1= new donor("raju","183484","o+","aims","mumbai");
    alldonors->push_back(d1);
    d1= new donor("rick","981552","o-","max","noida");
    alldonors->push_back(d1);
    while(1)
    {
        cout<<"Press 1 if you are Admin\nPress 2 if you are User\nPress 3 to exit"<<endl;
        cin>>n;
        switch(n)
        {
            case 1:
            cout<<"Press 1 to Add donor\nPress 2 to Search database\nPress 3 to send Notifications\n"<<endl;
            cin>>n;
            switch(n)
            {
                case 1:
                cout<<"Enter Donor's Name\n";
                cin>>name;
                cout<<"Enter your MobileNumber\n";
                cin>>mn;
                cout<<"Enter the blood group of Donor\n";
                cin>>bg;
                cout<<"Enter the Hospital Name\n";
                cin>>hospitalname;
                cout<<"Enter the city's name\n";
                cin>>city;
                add_donor(name,mn,bg,hospitalname,city,alldonors);
                cout<<endl;
                break;

                case 2:
                cout<<"Press 1 to search by blood group\nPress 2 to search by city\n";
                cin>>n;
                switch(n)
                {
                    case 1:
                    cout<<"Enter the blood group of Donor\n";
                    cin>>bg;
                    search_bg(bg,alldonors);
                    cout<<endl;
                    break;

                    case 2:
                    cout<<"Enter the city's name\n";
                    cin>>city;
                    search_city(city,alldonors);
                    cout<<endl;
                }    
                break;

                case 3:
                send_request(alldonors);
                cout<<endl;
            }
            continue;




            case 2:
            cout<<"I want to\n1.Raise request for Blood\n2.Donate Blood"<<endl;
            cin>>n;
            switch(n)
            {
                case 1:
                cout<<"Enter Your Blood Group"<<endl;
                cin>>bg;
                raise_request(bg,alldonors);
                cout<<endl;
                break;

                case 2:
                cout<<"1. Want to donate willingly\n2. Received an invitation"<<endl;
                cin>>n;
                switch(n)
                {
                    case 1:
                    cout<<"Enter your city\n";
                    cin>>city;
                    cout<<"Nearby Available Hospitals\n";
                    for(int i=0;i<alldonors->size();i++)
                    {
                        if(((*alldonors)[i])->city==city)
                        {
                            cout<<((*alldonors)[i])->hospitalName<<endl;
                        }
                    }
                    cout<<endl;
                    break;

                    case 2:
                    cout<<"Do you approve of the request?"<<endl;
                    string response;
                    cin>>response;
                    if(response=="Yes")
                    {
                        cout<<"Enter your city\n";
                        cin>>city;
                        cout<<"Nearby Available Hospitals\n";
                        for(int i=0;i<alldonors->size();i++)
                        {
                            if(((*alldonors)[i])->city==city)
                            {
                                cout<<((*alldonors)[i])->hospitalName<<endl;
                            }
                        }
                        cout<<"Thanks!your appointment is fixed."<<endl;
                    }
                    else
                    {
                        cout<<"Response recorded!sorry for inconvenience."<<endl;
                    }
                    cout<<endl;
                }
                

            }
            continue;


            case 3:
            break;  
        }
        break;
    }
    return 0; 
}
