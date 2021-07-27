#include<iostream>
#include<fstream>
#include<iomanip>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

// the class that stores data
class student{
private:
    string name,rollno,course,email,cell;
public:
    void menu();
    void insert_new();
    void display();
    void modify();
    void search();
    void delete_data();


};
void student::menu(){
    menustart:
    system("cls");
    int choice;
    char d;
    cout<<"---------------------| STUDENT DATA MANAGEMENT SYSTEM |-------------------------------"<<endl;
    cout<<"\t\t\t"<<"1.Enter New Record"<<endl;
    cout<<"\t\t\t"<<"2.Display Record"<<endl;
    cout<<"\t\t\t"<<"3.Modify Record"<<endl;
    cout<<"\t\t\t"<<"4.Search Record"<<endl;
    cout<<"\t\t\t"<<"5.Delete Record"<<endl;
    cout<<"\t\t\t"<<"6.Exit"<<endl;
    cout<<"---------------------| Choice Option[1/2/3/4/5/6] |-------------------------------"<<endl;
    cout<<"---------------------| Enter your Choice |-------------------------------"<<endl;
    cin>>choice;
    switch(choice){
    case 1:
        do{
            insert_new();
            cout<<"\t\t\t"<<"Do you want to add another student (Y/N) "<<endl;
            cin>>d;
        }while(d=='Y'||d=='y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        delete_data();
        break;
    case 6:
        exit(0);

    default:
        cout<<"\t\t\t"<<"Invalid choice"<<endl;
        break;
}
    cout<<"\t\t\t"<<"Enter any key to Continue "<<endl;
    getch();


    goto menustart;
}
void student::insert_new(){
    system("cls");
    cout<<"---------------------| Add Student Details |-------------------------------"<<endl;

    cout<<"---------------------| Enter Student Details  |-------------------------------"<<endl;
    cout<<"\t\t\t"<<"Enter the Full Name :";
    cin.ignore();
    getline(cin,name);
    cout<<"\t\t\t"<<"Enter the Roll number :";
    cin>>rollno;
    cout<<"\t\t\t"<<"Enter the Course :";
    cin>>course;
    cout<<"\t\t\t"<<"Enter the Email Id :";
    cin>>email;
    cout<<"\t\t\t"<<"Enter the Mobile Number :";
    cin>>cell;
    cout<<"---------------------| Successfully Added a Student |-------------------------------"<<endl;
    fstream file("StudentRecord.txt",ios::app|ios::out);
    file<<name<<" "<<rollno<<" "<<course<<" "<<email<<" "<<cell<<" "<<endl;
    file.close();

}
void student::display(){
    int total=1;
    system("cls");
     cout<<"-----------------------| Student Data Record |-------------------------------"<<endl;
    fstream file("StudentRecord.txt",ios::in);
    if(!file){
        cout<<"\t\t\t"<<"No data present "<<endl;
    }
    else {

        file>>name>>rollno>>course>>email>>cell;
        while(!file.eof()){
            cout<<"-----------------------| Student "<<total++<<" |-------------------------"<<endl;
            cout<<"\t\t\t"<<"Student Name :"<<name<<endl;
            cout<<"\t\t\t"<<"Student Rollno :"<<rollno<<endl;
            cout<<"\t\t\t"<<"Student Course :"<<course<<endl;
            cout<<"\t\t\t"<<"Student Email Id :"<<email<<endl;
            cout<<"\t\t\t"<<"Student Mobile Number:"<<cell<<endl;
            file>>name>>rollno>>course>>email>>cell;
            cout<<endl;
        }
        if(total==0){
            cout<<"\t\t\t"<<"NO data present "<<endl;
        }
    }
    file.close();
}
void student::modify(){
    system("cls");
    fstream file,file1;
    string s;
    int found=0;
    cout<<"\t\t\t"<<"Enter the Rollno of the Student : ";
    cin>>s;
    file.open("StudentRecord.txt",ios::in);
    cout<<"---------------------| Modify Record |-------------------------------"<<endl;
    if(!file){
        cout<<"\t\t\t"<<"NO data present "<<endl;
    }
    else{
        file1.open("Record.txt",ios::app|ios::out);
        file>>name>>rollno>>course>>email>>cell;
        while(!file.eof()){
            if(s!=rollno){
                file1<<name<<" "<<rollno<<" "<<course<<" "<<email<<" "<<cell<<" "<<endl;
            }
            else{
                cout<<"---------------------| Enter the details  |-------------------------------"<<endl;
                cout<<"\t\t\t"<<"Enter the Full Name :";
                cin.ignore();
                getline(cin,name);
                cout<<"\t\t\t"<<"Enter the Roll number :";
                cin>>rollno;
                cout<<"\t\t\t"<<"Enter the Course :";
                cin>>course;
                cout<<"\t\t\t"<<"Enter the Email Id :";
                cin>>email;
                cout<<"\t\t\t"<<"Enter the Mobile Number :";
                cin>>cell;
                file1<<name<<" "<<rollno<<" "<<course<<" "<<email<<" "<<cell<<" "<<endl;
                found++;


            }
            file>>name>>rollno>>course>>email>>cell;
        }
        if(found==0)
                    cout<<"\t\t\t"<<"NO data present "<<endl;
        file.close();
        file1.close();
        remove("StudentRecord.txt");
        rename("record.txt", "StudentRecord.txt");

    }

}
void student::search(){

    string s;
    int found=0;
    system("cls");
    fstream file;
    file.open("StudentRecord.txt",ios::in);
    if(!file){
         cout<<"\t\t\t"<<"NO data found"<<endl;
         return;
    }
    cout<<"---------------------| Student Record Search |-------------------------------"<<endl;
    cout<<"\t\t\t"<<"Enter the Roll Number of the Student : ";
    cin>>s;
    file>>name>>rollno>>course>>email>>cell;
    while(!file.eof()){
        if(rollno==s){
            cout<<"-----------------------| Student Record |-------------------------"<<endl;
            cout<<"\t\t\t"<<"Student Name :"<<name<<endl;
            cout<<"\t\t\t"<<"Student Rollno :"<<rollno<<endl;
            cout<<"\t\t\t"<<"Student Course :"<<course<<endl;
            cout<<"\t\t\t"<<"Student Email Id :"<<email<<endl;
            cout<<"\t\t\t"<<"Student Mobile Number:"<<cell<<endl;
            found++;
            return;
        }
        file>>name>>rollno>>course>>email>>cell;
    }
    if(found==0)
        cout<<"\t\t\t"<<"NO data found"<<endl;
    file.close();

}
void student::delete_data(){
    system("cls");
    cout<<"---------------------| Delete Record |-------------------------------"<<endl;
    fstream file,file1;
    string s;
    int found=0;
    cout<<"\t\t\t"<<"Enter the Rollno of the Student : ";
    cin>>s;
    file.open("StudentRecord.txt",ios::in);

    if(!file){
        cout<<"\t\t\t"<<"NO data present "<<endl;
    }
    else{
        file1.open("Record.txt",ios::app|ios::out);
        file>>name>>rollno>>course>>email>>cell;
        while(!file.eof()){
            if(s!=rollno){
                file1<<name<<" "<<rollno<<" "<<course<<" "<<email<<" "<<cell<<" "<<endl;
                found++;

            }

            file>>name>>rollno>>course>>email>>cell;
        }
        if(found==0)
            cout<<"\t\t\t"<<"NO data present "<<endl;
        else
            cout<<"\t\t\t"<<"Record Deleted Successfully "<<endl;
        file.close();
        file1.close();
        remove("StudentRecord.txt");
        rename("record.txt", "StudentRecord.txt");
}
}
int main(){
    student s1;
    s1.menu();
}
