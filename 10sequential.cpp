#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

void addStudent(){
    ofstream f("db.txt", ios::app);

    string rn, name, div, address;

    cout<<"Enter student roll number:"<<endl;
    cin>>rn;
    cout<<"Enter student name :"<<endl;
    cin>>name;
    cout<<"Enter student division:"<<endl;
    cin>>div;
    cout<<"Enter student address :"<<endl;
    cin>>address;

    f << left <<setw(20)<< rn << setw(20)<< name << setw(20)<< div <<setw(20) <<address <<endl;
    
    cout<<"Student added successfully."<<endl;
    f.close();
}

void deleteStudent(){
    ifstream f("db.txt");
    string line, rn ;
    cout<<"Enter Roll number of the student to Delete:"<<endl;
    cin>>rn;

    string fileData;

    while(getline(f,line)){
        if(line.find(rn)==string::npos){
           fileData += line;
           fileData +="\n";    
        }
    } 
    f.close();

    ofstream f1("db.txt",ios::out);
    f1 << fileData;
    f1.close();
}

void searchStudent(){
    ifstream f("db.txt");
    string line, rn ;
    cout<<"Enter Roll number of the student to Search:"<<endl;
    cin>>rn;

    bool found= false;

    while(getline(f,line)){
        if(line.find(rn)!=string::npos){
            cout<<"Student Details"<<endl;
            cout<<line<<endl;
            found=true;
            break;
        }
    }
    
    f.close();

    if(!found){
        cout<<"Student doesn't exists"<<endl;
    }
}

void printStudent(){
    ifstream f("db.txt");
    string line;
    cout<<"Printing file Data..."<<endl;
    while(getline(f,line)){
        cout<<line<<endl;
    }
    cout<<"printing completed! "<<endl;
    f.close();
}

int main()
{
    ofstream f("db.txt",ios::out);
    f << left <<setw(20)<< "Roll Number" << setw(20)<<"Name"<< setw(20)<< "Division" <<setw(20) <<"Address" <<endl;
    
    f.close();

    int ch;
    while(ch!=-1){
        cout<<"____MENU____"<<endl;
        cout<<"\n1.Add Student \n2.Delete Student \n3.Search Student \n4.Print Data \n5.Exit \nEnter your choice:"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                addStudent();
                break;

            case 2:
                deleteStudent();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                printStudent();
                break;

            case 5:
                return 0;
                break;
        }
    }
    return 0;

}