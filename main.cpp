#include <iostream>
#include <string>

using namespace std;

enum Ram{ R2GB,R4GB,R6GB,R8GB,R12GB,R16GB,R32GB,R64GB};
enum Storage{S16GB,S32GB,S64GB,S128GB,S256GB,S512GB,S1TB,S2TB};
enum OS{iOS,Android,windowsPhon};
enum Color{white,black,silver,gold};

struct phone{
    string name;
    string company;
    Ram ram;
    Storage storage;
    OS os;
    int price;
    Color color;
    int existingcount;
    int soldcount;
};

void menu(phone **,int&);
bool add_phone(phone **,int &,string ,string );
bool add_phone(phone **,int &,phone);
int  search(phone *,int &,string &,string &);
bool change_mobile_info(phone **,int &,string ,string );
void sort_by_price(phone*,int &);
void swap(phone&,phone&);
void sort_by_mostsoldcount(phone**,int&);
bool sell(phone ** ptr,int &size,string,string);
void print_phone( phone );
void print_phones( phone*,int&);
bool remove_phone(phone**,int &,int&);

int main()
{    int size=0;
     phone * ptr= new phone[size];
    menu(&ptr,size);
      delete []ptr;
    return 0;
}

bool add_phone(phone ** ptr,int &size,string name,string company){
    int index= 0;
    int option=0;
    phone temp;
    index=search(*ptr,size,name,company);
    if (index == -1){
        temp.name=name;
        temp.company=company;
        cout<<"lets add other details"<<"\n";
        cout<<"choose the number of OS \n 1.iOS \n 2.Android \n 3.windows Phon"<<"\n";
        cin>> option;
        if(option==1){temp.os=iOS;}
        if(option==2){temp.os=Android;}
        if(option==3){temp.os=windowsPhon;}
        if(option>3){cerr<<"error"<<"\n"; return false;}
        cout<<"choose the number of Ram\n 1.2GB\n 2.4GB\n 3.6GB\n 4.8GB\n 5.12GB\n 6.16GB\n 7.32GB\n 8.64GB"<<"\n";
        cin>> option;
        if(option==1){temp.ram=R2GB;}
        if(option==2){temp.ram=R4GB;}
        if(option==3){temp.ram=R6GB;}
        if(option==4){temp.ram=R8GB;}
        if(option==5){temp.ram=R12GB;}
        if(option==6){temp.ram=R16GB;}
        if(option==7){temp.ram=R32GB;}
        if(option==8){temp.ram=R64GB;}
        if(option>8){cerr<<"error"; return false;}
        cout<<"choose the number of Storage\n 1.16GB\n 2.32GB\n 3.64GB\n 4.128GB\n 5.256GB\n 6.512GB\n 7.1TB\n 8.2TB"<<"\n";
        cin>> option;
        if(option==1){temp.storage=S16GB;}
        if(option==2){temp.storage=S32GB;}
        if(option==3){temp.storage=S64GB;}
        if(option==4){temp.storage=S128GB;}
        if(option==5){temp.storage=S256GB;}
        if(option==6){temp.storage=S512GB;}
        if(option==7){temp.storage=S1TB;}
        if(option==8){temp.storage=S2TB;}
        if(option>8){cerr<<"error"; return false;}
        cout<<"enter price:"<<"\n";
        cin>> temp.price;
        cout<<"choose the number of color \n 1.white \n 2.black \n 3.silver  \n 4.gold"<<"\n";
        cin>> option;
        if(option==1){temp.color=white;}
        if(option==2){temp.color=black;}
        if(option==3){temp.color=silver;}
        if(option==4){temp.color=gold;}
        if(option>4){cerr<<"error"; return false;}
        cout<<"enter existing count:"<<"\n";
        cin>> temp.existingcount;
        temp.soldcount=0;
       if( add_phone(ptr,size,temp)==true){
        cout<<"done, ";
        return true;}
    }

    return false;
}

bool add_phone(phone ** ptr,int &size,phone tempphone){
      phone *a=*ptr;
      phone *temp=new phone[size+1];
      for(int i=0;i<size;i++){
          *(temp+i)=*(a+i);
      }
      *(temp+size)=tempphone;
       *ptr=temp;
         size++;
         delete []a;
        return true;
}

bool remove_phone(phone **ptr,int & size,int & index){
    phone *a=*ptr;
    phone *temp=new phone[size-1];
    for(int i=0;i<index;i++){
        *(temp+i)=*(a+i);
    }
    for(int i=index;i<size-1;i++){
        *(temp+i)=*(a+i+1);
    }
      *ptr=temp;
    size--;
    delete []a;
      cout<<"\n"<<"size:  "<<size<<"\n";
      return true;
}

int search(phone * ptr,int &size,string &name,string &company){
    for(int i=0;i<size;i++){
        if( ptr[i].name ==name){
            if(ptr[i].company== company){
                return i;
            }
        }

    }

    return -1;}

bool change_mobile_info(phone ** ptr,int &size,string name,string company){
    phone* aptr=*ptr;
    int index=-1;
    int op=0;
    int option=0;
    bool flag=true;
    phone temp;
    index=search(*ptr,size,name,company);

    if(index==-1){return false;}
    if (index!=-1 ){
        temp=aptr[index];
        while(flag){
           flag=false;
        cout<<"which item do you want to change?"<<"\n";
        cout<<"1.OS"<<"\n";
        cout<<"2.Ram"<<"\n";
        cout<<"3.storage"<<"\n";
        cout<<"4.price"<<"\n";
        cout<<"5.color"<<"\n";
        cout<<"6.existing count"<<"\n";
        cout<<"7.sold count"<<"\n";
        cin>>op;

    if(op>7){cerr<<"there isn't this option:"<<op<<"\n";}
    if(op==1){cout<<"choose the number of OS \n 1.iOS \n 2.Android \n 3.windows Phon"<<"\n";
    cin>> option;
    if(option==1){temp.os=iOS;}
    if(option==2){temp.os=Android;}
    if(option==3){temp.os=windowsPhon;}
    if(option>3){cerr<<"error"<<"\n"; return false;}
    }
    if(op==2){cout<<"choose the number of Ram\n 1.2GB\n 2.4GB\n 3.6GB\n 4.8GB\n 5.12GB\n 6.16GB\n 7.R32GB\n 8.64GB"<<"\n";
    cin>> option;
    if(option==1){temp.ram=R2GB;}
    if(option==2){temp.ram=R4GB;}
    if(option==3){temp.ram=R6GB;}
    if(option==4){temp.ram=R8GB;}
    if(option==5){temp.ram=R12GB;}
    if(option==6){temp.ram=R16GB;}
    if(option==7){temp.ram=R32GB;}
    if(option==8){temp.ram=R64GB;}
    if(option>8){cerr<<"error"; return false;}
    }
    if(op==3){cout<<"choose the number of Storage\n 1.16GB\n 2.32GB\n 3.64GB\n 4.128GB\n 5.256GB\n 6.512GB\n 7.1TB\n 8.2TB"<<"\n";
    cin>> option;
    if(option==1){temp.storage=S16GB;}
    if(option==2){temp.storage=S32GB;}
    if(option==3){temp.storage=S64GB;}
    if(option==4){temp.storage=S128GB;}
    if(option==5){temp.storage=S256GB;}
    if(option==6){temp.storage=S512GB;}
    if(option==7){temp.storage=S1TB;}
    if(option==8){temp.storage=S2TB;}
    if(option>8){cerr<<"error"; return false;}
    }
    if(op==4){cout<<"price:"<<"\n";
    cin>> temp.price;
    }
    if(op==5){cout<<"choose the number of color \n 1.white \n 2.black \n 3.silver  \n 4.gold"<<"\n";
    cin>> option;
    if(option==1){temp.color=white;}
    if(option==2){temp.color=black;}
    if(option==3){temp.color=silver;}
    if(option==4){temp.color=gold;}
    if(option>4){cerr<<"error"; return false;}
    }
    if(op==6){cout<<"existing count:"<<"\n";
    cin>> temp.existingcount; }
    if(op==7){cout<<"sold count:"<<"\n";
        cin>> temp.soldcount;}

    cout<<"do you want to channge other features?"<<"\n";
    cout<<"1.yes"<<"\n";
    cout<<"2.no"<<"\n";
    cin>>op;
    if(op==1){flag=true;}
    if(op==2){}
        }
   }

    phone*a=*ptr;
    phone *tempptr=new phone[size];
    for(int i=0;i<index;i++){
        tempptr[i]=a[i];}
    tempptr[index]=temp;
    for(int i=index+1;i<size;i++){
        tempptr[i]=a[i];}
      *ptr=tempptr;
       delete []a;


    return true;
}

void sort_by_price(phone* ptr,int& size){
    //bubble sort
    bool flag=true;
    for(int i=0;i<size &&flag;i++){
        flag=false;
        for(int j=size-1;j>i;j--){
            if( ptr[j].price < ptr[j-1].price){
                swap(*(ptr+j),*(ptr+j-1));
                flag=true;
            }
        }
    }

}

void swap(phone& ph1,phone& ph2){
   phone flag= ph1;
   ph1=ph2;
   ph2=flag;
}

void sort_by_mostsoldcount(phone** ptr,int& size){
    //bubble sort call by poiter
    phone*a=*ptr;
    phone * temp=new phone[size];
    for(int i=0;i<size;i++){
     temp[i]=a[i];
    }
    bool flag=true;
    for(int i=0;i<size &&flag;i++){
        flag=false;
        for(int j=size-1;j>i;j--){
            if( temp[j].soldcount > temp[j-1].soldcount){
                swap(*(temp+j),*(temp+j-1));
                flag=true;
            }
        }
    }
    print_phones(temp,size);
    delete [] temp;
}

bool sell(phone ** ptr,int &size,string name,string company){
    phone *aptr=*ptr;
    int index=-1;
    int op = 0;
    phone temp;
    bool flag=true;
    index=search(*ptr,size,name,company);
   while(flag){
       flag=false;
    if (index!=-1 ){
        temp=*(aptr+index);
        print_phone(temp);
        if(temp.existingcount>0){
        temp.existingcount --;
        temp.soldcount ++;
            aptr[index]=temp;}

        else if(temp.existingcount<1){
            cout<<" sorry,Inventory is 0"<<"\n";
        }

        cout<<"Do you want to buy another one?"<<"\n";
        cout<<"1.yes"<<"\n";
        cout<<"2.no"<<"\n";
        cin>>op;
       if(op==1){flag=true;}
        if(op==2){}
            }
    }
    return  true;
    }



void print_phone( phone flag){

    cout <<"company is :"<<flag.company << "\n";
    cout <<"name is :"<< flag.name << "\n";
    if (flag.os==0){cout <<"OS is : " "Ios" << "\n";}
    if (flag.os==1){cout <<"OS is : " "Android" << "\n";}
    if (flag.os==2){cout <<"OS is : " "windowsPhon" << "\n";}
    if (flag.ram==0){cout <<"Ram is : " "2GB" << "\n";}
    if (flag.ram==1){cout <<"Ram is : " "4GB" << "\n";}
    if (flag.ram==2){cout <<"Ram is : " "6GB" << "\n";}
    if (flag.ram==3){cout <<"Ram is : " "8GB" << "\n";}
    if (flag.ram==4){cout <<"Ram is : " "12GB" << "\n";}
    if (flag.ram==5){cout <<"Ram is : " "16GB" << "\n";}
    if (flag.ram==6){cout <<"Ram is : " "32GB" << "\n";}
    if (flag.ram==7){cout <<"Ram is : " "64GB" << "\n";}
    if (flag.storage==0){cout <<"Storage is : " "16GB" << "\n";}
    if (flag.storage==1){cout <<"Storage is : " "32GB" << "\n";}
    if (flag.storage==2){cout <<"Storage is : " "64GB" << "\n";}
    if (flag.storage==3){cout <<"Storage is : " "128GB" << "\n";}
    if (flag.storage==4){cout <<"Storage is : " "256GB" << "\n";}
    if (flag.storage==5){cout <<"Storage is : " "512GB" << "\n";}
    if (flag.storage==6){cout <<"Storage is : " "1TB" << "\n";}
    if (flag.storage==7){cout <<"Storage is : " "2TB" << "\n";}
    if (flag.color==0){cout <<"Color is : " "white" << "\n";}
    if (flag.color==1){cout <<"Color is : " "black" << "\n";}
    if (flag.color==2){cout <<"Color is : " "silver" << "\n";}
    if (flag.color==3){cout <<"Color is : " "gold" << "\n";}
    cout <<"price is : "  <<flag.price << "\n";
    cout <<"existingcount is : " << flag.existingcount <<"\n";
    cout<<"soldcount is :  "<< flag.soldcount<<"\n"<<"\n";

}

void print_phones(phone *ptr,int& size){
            for (int i=0 ; i<size ; i++){
                int j=i+1;
                cout <<"phone "<< j <<"\n";
            print_phone(ptr[i]);
            }
}





void menu(phone**ptr,int & size){
    int index=-1;
    phone temp;
    int option=-1;
    int adition=0;
    int op=1;
    cout<<"\n"<<"              --**| In the name of Gad |**--              "<<"\n";
    cout<<"   welcome to this project;This project has been prepared by:"<<"\n"<< "   Mohammad Mahdi Sheikhzadeh & Maryam Mortazavi Sefat"<<"\n"<<"\n";
    while(op==1){
    cout<<"choose the numer"<<"\n";
    cout<<"1.Add a phone"<<"\n";
    cout<<"2.Remove a phone"<<"\n";
    cout<<"3.Sort phones by price"<<"\n";
    cout<<"4.seach a phone"<<"\n";
    cout<<"5.change phone info"<<"\n";
    cout<<"6.sell a phone"<<"\n";
    cout<<"7.print phones"<<"\n";
    cout<<"8.print phones by the most sold to the list"<<"\n";
    cout<<"9.Quit"<<"\n";
    cin>>option;
    cout<<"\n";

     if(option>9){ cout<<"there isn't this option:  "<<option<<"\n";}  //control option up to 9
     if(option==1){
         cout<<"enter the name of phone, please"<<"\n";
         cin>>temp.name;
         cout<<"enter the phone company,please"<<"\n";
         cin>>temp.company;
         if(add_phone(ptr,size,temp.name,temp.company)==true){cout<<"added made successfully (*_*) "<<"\n";}
         else {
                 index=search(*ptr,size,temp.name,temp.company);
                 phone * aptr=* ptr;
                 temp=*(aptr+index);
                 cout<<"phone existed"<<"\n"<<"enter added nambers of phones"<<"\n";
                 cin>> adition;
                temp.existingcount += adition;
                *(aptr+index)=temp;
                 cout << "numbers of phone updated"<<"\n";
                 print_phone(temp);
     }}

     if(option==2){
         cout<<"enter the name of phone, please"<<"\n";
         cin>>temp.name;
         cout<<"enter the phone company,please"<<"\n";
         cin>>temp.company;
          index=search(*ptr,size,temp.name,temp.company);
          if(index!=-1){
              phone * aptr=* ptr;
              temp=*(aptr+index);
              print_phone(temp);cout<<"\n";
              remove_phone(ptr,size,index);
              cout<<"removed made successfully (*_*)"<<"\n";}
          else {
              cout<<"there isnt this phone!"<<"\n";
          }
     }
     if(option==3){
     sort_by_price(*ptr,size);
     print_phones(*ptr,size);
     }
     if(option==4){
         cout<<"enter the name of phone, please"<<"\n";
         cin>>temp.name;
         cout<<"enter the phone company,please"<<"\n";
         cin>>temp.company;
         cout<<"\n";
         index=search(*ptr,size,temp.name,temp.company);
        if(index!=-1){
            phone * aptr=* ptr;
            temp=*(aptr+index);
            cout<<"index:"<<index<<"\n";
            print_phone(temp); }
        else{cout<<"not found"<<"\n";}
        }

     if(option==5){
         cout<<"enter the name of phone, please"<<"\n";
         cin>>temp.name;
         cout<<"enter the phone company,please"<<"\n";
         cin>>temp.company;
         if(change_mobile_info(ptr,size,temp.name,temp.company)==true){cout<<"changes made successfully (*_*) "<<"\n";}
        }
     if(option==6){
         cout<<"enter the name of phone, please"<<"\n";
         cin>>temp.name;
         cout<<"enter the phone company,please"<<"\n";
         cin>>temp.company;
        if(sell(ptr,size,temp.name,temp.company)==true){cout<<"  Thank you for your purchase(*_*)"<<"\n";}
     }
     if(option==7){ print_phones(*ptr,size);}
     if(option==8){ sort_by_mostsoldcount(ptr,size);}
     if(option==9){op=2; cout<<"thank's for choose us";}
     else{
    cout<<"Do you want to go back to the main menu?"<<"\n";
    cout<<"1.yes"<<"\n";
    cout<<"2.no"<<"\n";
    cin>>op;
     cout<<"\n";}

    }



}


