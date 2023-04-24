#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void intro();
void mainmenu();
void create_a_record();
void viewall();
void view_Specific(string id);
void modify(string id);
void delete_record (string id);
void deleted();
void restore(string id);
string repeat(string id_no);
string grading(int marks);

struct student
{
    string firstname, secondname;
    string id;
    int roll_no, pf,ict,eng,math,phy;
    string gradepf,gradeict,gradeEng,grademath,gradephy;

};



int main()
{
system("cls");
 system ("color F4");
 int choice;

 intro();
    Sleep(300);
    cout<<"\t\t\t\t<============Student Report Card Management System============>    "<<endl<<endl;
    Sleep(300);
    cout<<"\t\t\t\t                        1.Main Menu                                "<<endl<<endl;
    Sleep(300);
    cout<<"\t\t\t\t                        2.Exit                                     "<<endl<<endl;
    Sleep(300);
    cout<<"\t\t\t\t<=============================================================>    "<<endl<<endl;

    cout<<"\t\t\t\t                     Enter Your Choice ==> ";cin>>choice;
    if (choice == 1 )
    {
        mainmenu();
    }
    else
        exit(0);

    return 0;
}

void intro()
{
    system("cls");
    cout << "\n\n\n";
    Sleep(2000);
    cout << "\t\t\t\t\t * * *  ****   *      ****   ***   ***   ****      "<< endl;
    Sleep(300);
    cout << "\t\t\t\t\t * * *  *      *     *      *   * * * *  *         "<< endl;
    Sleep(300);
    cout << "\t\t\t\t\t * * *  ****   *     *      *   * * * *  ****      "<< endl;
    Sleep(300);
    cout << "\t\t\t\t\t * * *  *      *     *      *   * * * *  *         "<< endl;
    Sleep(300);
    cout << "\t\t\t\t\t  ***   ****   ****   ****   ***  * * *  ****      "<< endl;
    Sleep(300);
    cout<<endl;

}
 void mainmenu()
 {

     int choice;
     string idNo;
     do{
    system ("cls");
     cout<<"\n\n\n";
     Sleep(100);
     cout<<"\t\t\t\t\t   <===========================>"<<endl<<endl;
     Sleep(100);
     cout<<"\t\t\t\t\t            MAIN MENU         "<<endl;
     Sleep(100);
     cout<<"\t\t\t\t\t   <===========================>"<<endl<<endl;
     Sleep(100);
     cout<<"\t\t\t\t\t 1. Create a Record                  "<<endl<<endl;
     Sleep(100);
     cout<<"\t\t\t\t\t 2. View Result of All  Students     "<<endl<<endl;
     Sleep(100);
     cout<<"\t\t\t\t\t 3. View Result of a Specific Student"<<endl<<endl;
     Sleep(100);
     cout<<"\t\t\t\t\t 4. Modify a Record                  "<<endl<<endl;
     Sleep(100);
     cout<<"\t\t\t\t\t 5. Delete a Record                  "<<endl<<endl;
     Sleep(100);
     cout<<"\t\t\t\t\t 6. Recycle Bin                      "<<endl<<endl;
     Sleep(100);
     cout<<"\t\t\t\t\t 7. Exit                             "<<endl<<endl;
     Sleep(100);
     cout<<"\t\t\t\t\t  <===========================>"<<endl<<endl;


     cout<<"\t\t\t\t\t        Enter Your Choice ==> "; cin>>choice;
     cout<<endl;

     switch (choice)
     {
     case 1:
        create_a_record();
        break;
     case 2:
        viewall();
        break;
     case 3:
         cout<<"\t\t\t\tEnter ID No: ";
         cin>>idNo;
        view_Specific(idNo);
        break;
        case 4:
         cout<<"\t\t\t\tEnter ID No: ";
         cin>>idNo;
         modify(idNo);
        break;
        case 5:
         cout<<"\t\t\t\tEnter ID No: ";
         cin>>idNo;
         delete_record(idNo);
        break;
         case 6:
         deleted();
        break;

     }
     }while(choice!=7);

 }
 void create_a_record()
 {
     system("cls");
    student s;
    ofstream outfile;
    outfile.open("Report.txt",ios::app);
    if(outfile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPEN...press enter key";
        cin.ignore();
        cin.get();
    }
    cout<<"\n\n";
    cout<<"\t\t\t\t=======CREATE A REPORT CARD========\n\n";
    cout<<"\t\t\t\tENTER YOUR FIRST NAME  :";
    cin.ignore();
    getline(cin,s.firstname);
    cout<<"\t\t\t\tENTER YOUR SECOND NAME :";
    getline(cin,s.secondname);
    cout<<"\t\t\t\tENTER YOUR ID NUMBER   :";
    getline(cin,s.id);
    s.id = repeat(s.id);
    cout<<"\t\t\t\tENTER YOUR ROLL NUMBER :";
    cin>>s.roll_no;
    cout<<"\t\t\t\tENTER YOUR PF MARKS(OUT OF 100)       :";
    cin>>s.pf;
    s.gradepf = grading(s.pf);
    cout<<"\t\t\t\tENTER YOUR ICT MARKS(OUT OF 100)      :";
    cin>>s.ict;
    s.gradeict = grading(s.ict);
    cout<<"\t\t\t\tENTER YOUR ENGLISH MARKS(OUT OF 100)  :";
    cin>>s.eng;
    s.gradeEng = grading(s.eng);
    cout<<"\t\t\t\tENTER YOUR MATH MARKS(OUT OF 100)     :";
    cin>>s.math;
    s.grademath = grading(s.math);
    cout<<"\t\t\t\tENTER YOUR PHYSICS MARKS(OUT OF 100)  :";
    cin>>s.phy;
    s.gradephy = grading(s.phy);
    outfile<<s.firstname<<"\t"<<s.secondname<<"\t"<<s.id<<"\t"<<s.roll_no<<"\t"<<s.pf<<"\t"<<s.gradepf<<"\t"<<s.ict<<"\t"<<s.gradeict<<"\t"<<s.eng<<"\t"<<s.gradeEng<<"\t"<<s.math<<"\t"<<s.grademath<<"\t"<<s.phy<<"\t"<<s.gradephy<<endl;
    outfile.close();
    cout<<endl;
    cout<<"\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED"<<endl;
    cout<<endl;
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();

 }

 void viewall()
 {
     system("cls");
    student s;
    ifstream infile;
    bool check = true;
    infile.open("Report.txt",ios::app);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED.....press enter key...";
        cin.ignore();
        cin.get();
    }
     cout<<"\n\n";
     cout<<"\t\t\t\t\tALL STUDENTS REPORT CARDS"<<endl;
     cout<<"\t\t\t\t================================================"<<endl;
    while(infile>>s.firstname>>s.secondname>>s.id>>s.roll_no>>s.pf>>s.gradepf>>s.ict>>s.gradeict>>s.eng>>s.gradeEng>>s.math>>s.grademath>>s.phy>>s.gradephy)
    {
        cout<<"\t\t\t\tSTUDENT NAME          : "<<s.firstname<<' '<<s.secondname<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER     : "<<s.id<<endl;
        cout<<"\t\t\t\tSTUDENT ROLL NUMBER   : "<<s.roll_no<<endl;
        cout<<"\t\t\t\tSTUDENT PF MARKS      : "<<s.pf<<"\tGRADE: "<<s.gradepf<<endl;
        cout<<"\t\t\t\tSTUDENT ICT MARKS     : "<<s.ict<<"\tGRADE: "<<s.gradeict<<endl;
        cout<<"\t\t\t\tSTUDENT ENGLISH MARKS : "<<s.eng<<"\tGRADE: "<<s.gradeEng<<endl;
        cout<<"\t\t\t\tSTUDENT MATH MARKS    : "<<s.math<<"\tGRADE: "<<s.grademath<<endl;
        cout<<"\t\t\t\tSTUDENT PHYSICS MARKS : "<<s.phy<<"\tGRADE: "<<s.gradephy<<endl;

        cout<<"\t\t\t\t================================================"<<endl;
        check=false;
    }
    infile.close();
    if(check)
    cout<<"\t\t\t\tNO RECORD FOUND..."<<endl<<endl;
    cout<<"press any key to continue....";
    cin.ignore();
    cin.get();
     }

void view_Specific(string id)

{
    student s;
    bool check=false;
    ifstream infile;
    infile.open("Report.txt",ios::app);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";
        cout<<"press any key to continue....";
        cin.ignore();
        cin.get();
    }

    cout<<"\t\t\t\t==========VIEW A SINGLE STUDENT REPORT==========\n\n";
    while(infile>>s.firstname>>s.secondname>>s.id>>s.roll_no>>s.pf>>s.gradepf>>s.ict>>s.gradeict>>s.eng>>s.gradeEng>>s.math>>s.grademath>>s.phy>>s.gradephy)
    {
        if(s.id==id)
        {
        cout<<"\t\t\t\tSTUDENT NAME          : "<<s.firstname<<' '<<s.secondname<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER     : "<<s.id<<endl;
        cout<<"\t\t\t\tSTUDENT ROLL NUMBER   : "<<s.roll_no<<endl;
        cout<<"\t\t\t\tSTUDENT PF MARKS      : "<<s.pf<<"\tGRADE: "<<s.gradepf<<endl;
        cout<<"\t\t\t\tSTUDENT ICT MARKS     : "<<s.ict<<"\tGRADE: "<<s.gradeict<<endl;
        cout<<"\t\t\t\tSTUDENT ENGLISH MARKS : "<<s.eng<<"\tGRADE: "<<s.gradeEng<<endl;
        cout<<"\t\t\t\tSTUDENT MATH MARKS    : "<<s.math<<"\tGRADE: "<<s.grademath<<endl;
        cout<<"\t\t\t\tSTUDENT PHYSICS MARKS : "<<s.phy<<"\tGRADE: "<<s.gradephy<<endl;
        cout<<"\t\t\t\t================================================"<<endl;
        check=true;
        }
    }
        infile.close();
        if(check==false)
            cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}
void modify (string id)
{
    student s;
    bool check = true;
    ifstream infile("Report.txt");
    ofstream outfile("Temp.txt");
    while (infile>>s.firstname>>s.secondname>>s.id>>s.roll_no>>s.pf>>s.gradepf>>s.ict>>s.gradeict>>s.eng>>s.gradeEng>>s.math>>s.grademath>>s.phy>>s.gradephy)
    {
        if (s.id == id)
        {
    cout<<"\n\n";
    cout<<"\t\t\t\t=======MODIFY REPORT CARD========\n\n";
    cout<<"\t\t\t\tENTER YOUR FIRST NAME  :";
    cin.ignore();
    getline(cin,s.firstname);
    cout<<"\t\t\t\tENTER YOUR SECOND NAME :";
    getline(cin,s.secondname);
    cout<<"\t\t\t\tENTER YOUR ID NUMBER   :";
    getline(cin,s.id);
    s.id = repeat(s.id);
    cout<<"\t\t\t\tENTER YOUR ROLL NUMBER :";
    cin>>s.roll_no;
    cout<<"\t\t\t\tENTER YOUR PF MARKS(OUT OF 100)       :";
    cin>>s.pf;
    s.gradepf = grading(s.pf);
    cout<<"\t\t\t\tENTER YOUR ICT MARKS(OUT OF 100)      :";
    cin>>s.ict;
    s.gradeict = grading(s.ict);
    cout<<"\t\t\t\tENTER YOUR ENGLISH MARKS(OUT OF 100)  :";
    cin>>s.eng;
    s.gradeEng = grading(s.eng);
    cout<<"\t\t\t\tENTER YOUR MATH MARKS(OUT OF 100)     :";
    cin>>s.math;
    s.grademath = grading(s.math);
    cout<<"\t\t\t\tENTER YOUR PHYSICS MARKS(OUT OF 100)  :";
    cin>>s.phy;
    s.gradephy = grading(s.phy);
    outfile<<s.firstname<<"\t"<<s.secondname<<"\t"<<s.id<<"\t"<<s.roll_no<<"\t"<<s.pf<<"\t"<<s.gradepf<<"\t"<<s.ict<<"\t"<<s.gradeict<<"\t"<<s.eng<<"\t"<<s.gradeEng<<"\t"<<s.math<<"\t"<<s.grademath<<"\t"<<s.phy<<"\t"<<s.gradephy<<endl;
    check = false;
        }
        else {
            outfile<<s.firstname<<"\t"<<s.secondname<<"\t"<<s.id<<"\t"<<s.roll_no<<"\t"<<s.pf<<"\t"<<s.gradepf<<"\t"<<s.ict<<"\t"<<s.gradeict<<"\t"<<s.eng<<"\t"<<s.gradeEng<<"\t"<<s.math<<"\t"<<s.grademath<<"\t"<<s.phy<<"\t"<<s.gradephy<<endl;
        }
    }
    if (check)
    {
        cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
        cout<<endl;
    }
    else
    {
        cout<<"\t\t\t\tTHE FILE IS UPDATED SUCCESSFULLY "<<endl;
    cout<<endl;
    }

    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
    infile.close();
    outfile.close();
    remove ("Report.txt");
    rename ("Temp.txt", "Report.txt");


}
void delete_record (string id)
{
    char choice;
    student s;
    bool check = true;
    ifstream infile("Report.txt");
    ofstream outfile("Temp.txt");
    ofstream outfile1 ("bin.txt",ios::app);
    while (infile>>s.firstname>>s.secondname>>s.id>>s.roll_no>>s.pf>>s.gradepf>>s.ict>>s.gradeict>>s.eng>>s.gradeEng>>s.math>>s.grademath>>s.phy>>s.gradephy)
    {

        if (s.id != id)
        {

    outfile<<s.firstname<<"\t"<<s.secondname<<"\t"<<s.id<<"\t"<<s.roll_no<<"\t"<<s.pf<<"\t"<<s.gradepf<<"\t"<<s.ict<<"\t"<<s.gradeict<<"\t"<<s.eng<<"\t"<<s.gradeEng<<"\t"<<s.math<<"\t"<<s.grademath<<"\t"<<s.phy<<"\t"<<s.gradephy<<endl;

        }
       else {
        check = false;
    outfile1<<s.firstname<<"\t"<<s.secondname<<"\t"<<s.id<<"\t"<<s.roll_no<<"\t"<<s.pf<<"\t"<<s.gradepf<<"\t"<<s.ict<<"\t"<<s.gradeict<<"\t"<<s.eng<<"\t"<<s.gradeEng<<"\t"<<s.math<<"\t"<<s.grademath<<"\t"<<s.phy<<"\t"<<s.gradephy<<endl;       }
    }
    if (check)
    {
        cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
        cout<<endl;
    }
    else
    {
        cout<<"\t\t\t\tRECORD DELETED SUCCESSFULLY..."<<endl;
        cout<<endl;
    }
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();

    infile.close();
    outfile.close();
    outfile1.close();
    remove ("Report.txt");
    rename ("Temp.txt", "Report.txt");
}
string repeat(string id_no)
{
    int position = 0;
    student s;
    ifstream infile("Report.txt");
     while (infile>>s.firstname>>s.secondname>>s.id>>s.roll_no>>s.pf>>s.gradepf>>s.ict>>s.gradeict>>s.eng>>s.gradeEng>>s.math>>s.grademath>>s.phy>>s.gradephy)
     {
        if (id_no == s.id)
         {
             cout<<"\t\t\t\tID No. already exists!"<<endl;
             cout<<"\t\t\t\tEnter again:";
             getline(cin, id_no);
             id_no = repeat(id_no);
         }
     }
     return id_no;
}
void deleted()
{
    int choice;
    bool check = true;
    system("cls");
    student s;
    ifstream infile ("bin.txt",ios::app);
    cout<<"\t\t\t\t\t\t RECYCLE BIN "<<endl<<endl;
 cout<<"\t\t\t\t================================================"<<endl;
    while (infile>>s.firstname>>s.secondname>>s.id>>s.roll_no>>s.pf>>s.gradepf>>s.ict>>s.gradeict>>s.eng>>s.gradeEng>>s.math>>s.grademath>>s.phy>>s.gradephy)
     {
        cout<<"\t\t\t\tSTUDENT NAME          : "<<s.firstname<<' '<<s.secondname<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER     : "<<s.id<<endl;
        cout<<"\t\t\t\tSTUDENT ROLL NUMBER   : "<<s.roll_no<<endl;
        cout<<"\t\t\t\tSTUDENT PF MARKS      : "<<s.pf<<"\tGRADE: "<<s.gradepf<<endl;
        cout<<"\t\t\t\tSTUDENT ICT MARKS     : "<<s.ict<<"\tGRADE: "<<s.gradeict<<endl;
        cout<<"\t\t\t\tSTUDENT ENGLISH MARKS : "<<s.eng<<"\tGRADE: "<<s.gradeEng<<endl;
        cout<<"\t\t\t\tSTUDENT MATH MARKS    : "<<s.math<<"\tGRADE: "<<s.grademath<<endl;
        cout<<"\t\t\t\tSTUDENT PHYSICS MARKS : "<<s.phy<<"\tGRADE: "<<s.gradephy<<endl;
        cout<<"\t\t\t\t================================================"<<endl;
        check = false;
     }
     infile.close();
     if (check == true)
     {
          cout<<"\t\t\t\t\t\t NO RECORDS"<<endl;
          cout<<"press any key to continue...";
          cin.ignore();
          cin.get();

     }
     else
    {
     cout<<endl;
     cout<<"\t\t\t\t\Press 1 to restore data.\n\t\t\t\t\Press any key to exit"<<endl;
     cout<<"\t\t\t\tEnter your choice ==> ";
     cin>>choice;
     if (choice == 1)
     {
         string id_no;
         cout<<"\t\t\t\tEnter ID No: ";cin>>id_no;
         restore(id_no);
     }
     else
        exit(0);
     }

}
void restore(string id)
{
    bool check = false;
    student s;
    ifstream infile("bin.txt");
    ofstream outfile("Report.txt", ios::app);
    ofstream outfile2("Temp.txt");
    while (infile>>s.firstname>>s.secondname>>s.id>>s.roll_no>>s.pf>>s.gradepf>>s.ict>>s.gradeict>>s.eng>>s.gradeEng>>s.math>>s.grademath>>s.phy>>s.gradephy)
    {
        if (s.id == id)
        {
        outfile<<s.firstname<<"\t"<<s.secondname<<"\t"<<s.id<<"\t"<<s.roll_no<<"\t"<<s.pf<<"\t"<<s.gradepf<<"\t"<<s.ict<<"\t"<<s.gradeict<<"\t"<<s.eng<<"\t"<<s.gradeEng<<"\t"<<s.math<<"\t"<<s.grademath<<"\t"<<s.phy<<"\t"<<s.gradephy<<endl;
        check = true;
        }
         else
         outfile2<<s.firstname<<"\t"<<s.secondname<<"\t"<<s.id<<"\t"<<s.roll_no<<"\t"<<s.pf<<"\t"<<s.gradepf<<"\t"<<s.ict<<"\t"<<s.gradeict<<"\t"<<s.eng<<"\t"<<s.gradeEng<<"\t"<<s.math<<"\t"<<s.grademath<<"\t"<<s.phy<<"\t"<<s.gradephy<<endl;
    }
    if (check)
    {
     cout<<"\t\t\t\tData is Restored Successfully!"<<endl;
     cout<<"\t\t\t\t\t\t NO RECORDS"<<endl;
     cout<<"press any key to continue...";
     cin.ignore();
     cin.get();
    }
    infile.close();
    outfile.close();
    outfile2.close();
    remove("bin.txt");
    rename("Temp.txt", "bin.txt");

}

string grading(int marks)
{
    string grade;

    if(marks >= 90)
        grade = "A+";
    else if (marks >= 85)
        grade = "A";
    else if (marks >= 80)
        grade = "A-";
    else if (marks >= 70)
        grade = "B";
    else if (marks >= 60)
        grade = "C";
    else if (marks >= 50)
        grade = "D";
    else
        grade = "F";
    return grade;
}




