///***********************************************************
//                           Header File in Project
//************************************************************

#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

//***************************************************************
///                   CLASS USED IN PROJECT
//****************************************************************

class Item
{
public:
    char id[6];
    char title[20];
};

class User
{
public:
    char userID[6];
    char name[20];
    char cause[15];
    char labID[6];
    int serviceCharge;
    friend std::istream &operator>>(std::istream &in, User &user);
};

class Report : public Item
{
public:
    char userID[6];
    char result[15];
    friend std::ostream &operator<<(std::ostream &out, const Report &report);

    void addReport(char nID[6], char nUserID[6], char nCause[15])
    {
        strcpy(id, nID);
        strcpy(title, nCause);
        strcpy(userID, nUserID);
        strcpy(result, "no Result");
    }

    void modifyReport()
    {
        cout << "\nReport ID: " << id;
        cout << "\nUser ID: " << userID;
        cout << "\nCases: " << title;
        cout << "\n\nEnter Result: ";
        cin.ignore();
        cin.getline(result, 15, '\n');
    }

    void reportAll()
    {
        cout << setw(6) << left << id
             << " | " << setw(7) << left << userID
             << " | " << setw(20) << left << title
             << " | " << setw(15) << left << result
             << " | " << endl;
    }
};

class Lab : public Item
{
    int roomNo;
    int fee;
    friend std::ostream &operator<<(std::ostream &out, const Lab &lab);
    friend std::istream &operator>>(std::istream &in, Lab &lab);

public:
    void modifyLab()
    {
        cout << "\nID: " << id;
        cout << "\nModify LAB Name: ";
        cin.ignore();
        cin.getline(title, 20, '\n');
        cout << "\nModify LAB Room No: ";
        cin >> roomNo;
        cout << "\nModify LAB Fee: ";
        cin >> fee;
    }

    void report()
    {
        cout << setw(6) << left << id
             << " | " << setw(20) << left << title
             << " | " << setw(7) << left << roomNo
             << " | " << setw(4) << left << fee
             << " | " << endl;
    }
};

//***************************************************************
///                   Operator Overloading IN PROJECT
//****************************************************************

ostream &operator<<(ostream &out, const Lab &lab)
{
    out << "===================================================================================================\n";
    out << setw(6) << left << "ID"
        << " | " << setw(20) << left << "Name"
        << " | " << setw(7) << left << "Room No"
        << " | " << setw(4) << left << "Fee"
        << " | " << endl;
    out << "=====================================================================================================\n";
    out << setw(6) << left << lab.id
        << " | " << setw(20) << left << lab.title
        << " | " << setw(7) << left << lab.roomNo
        << " | " << setw(4) << left << lab.fee
        << " | " << endl;

    return out;
}

ostream &operator<<(ostream &out, const Report &report)
{
    out << "===================================================================================================\n";
    out << setw(6) << left << "ID"
        << " | " << setw(7) << left << "USER ID"
        << " | " << setw(20) << left << "TITLE"
        << " | " << setw(15) << left << "RESULT"
        << " | " << endl;
    out << "=====================================================================================================\n";
    out << setw(6) << left << report.id
        << " | " << setw(7) << left << report.userID
        << " | " << setw(20) << left << report.title
        << " | " << setw(15) << left << report.result
        << " | " << endl;

    return out;
}

istream &operator>>(istream &in, Lab &lab)
{

    cout << "\nNew Lab Entry.....\n";
    cout << "\nEnter The Lab ID: ";
    in >> lab.id;
    cout << "\nLAB NAME: ";
    in.ignore();
    in.getline(lab.title, 20, '\n');
    cout << "\nLAB ROOM NO: ";
    in >> lab.roomNo;
    cout << "\nLAB Fee: ";
    in >> lab.fee;
    cout << "\n\nLAB Created Successfully..";

    return in;
}

istream &operator>>(istream &in, User &user)
{

    cout << "\nNew User Entry.....\n";
    cout << "\nEnter The User ID: ";
    in >> user.userID;
    cout << "\nUser NAME: ";
    in.ignore();
    in.getline(user.name, 20, '\n');
    cout << "\nCause: ";
    in.clear();
    in.getline(user.cause, 15, '\n');
    cout << "\nLAB ID: ";
    in >> user.labID;
    cout << "\nService Charge: ";
    in >> user.serviceCharge;
    cout << "\n\nUSER Created Successfully..";
    return in;
}

//***************************************************************
///    	global declaration for stream object, object
//****************************************************************
fstream fp, fp1;

//***************************************************************
///    Database Section Start Here
//****************************************************************

class Adminestrator : public Lab, public User, public Report
{
    Lab lab;
    User user;
    Report report;

public:
    //***************************************************************
    ///    	function to write in file
    //****************************************************************

    void insertLab()
    {
        char ch;
        fp.open("lab.dat", ios::out | ios::app);
        do
        {
            cin >> lab;
            fp.write((char *)&lab, sizeof(Lab));
            cout << "\n\nDo you Want to add more record..(y/n?): ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
        fp.close();
    }

    void addSLNo()
    {
        char ch;
        fp.open("user.dat", ios::out | ios::app);
        fp1.open("report.dat", ios::out | ios::app);
        do
        {
            cin >> user;
            report.addReport(user.labID, user.userID, user.cause);
            fp.write((char *)&user, sizeof(User));
            fp1.write((char *)&report, sizeof(Report));
            cout << "\n\nDo you Want to add more record..(y/n?): ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
        fp.close();
        fp1.close();
    }

    //***************************************************************
    ///   	function to read specific record from file
    //****************************************************************

    void displaySpecificLab(char n[])
    {
        cout << "\nLab Details\n";
        int flag = 0;
        fp.open("lab.dat", ios::in);
        while (fp.read((char *)&lab, sizeof(Lab)))
        {
            if (strcmpi(lab.id, n) == 0)
            {
                cout << lab;
                flag = 1;
            }
        }
        fp.close();
        if (flag == 0)
            cout << "\n\nLab does not exist.";
    }

    void displaySpecificReport(char n[])
    {
        cout << "\nReport Details\n";
        int flag = 0;
        fp.open("report.dat", ios::in);
        while (fp.read((char *)&report, sizeof(Report)))
        {
            if (strcmpi(report.id, n) == 0)
            {
                cout << report;
                flag = 1;
            }
        }
        fp.close();
        if (flag == 0)
            cout << "\n\nReport does not exist.";
    }

    //***************************************************************
    ///    	function to modify record of file
    //****************************************************************

    void modifyLab()
    {
        char n[6];
        int found = 0;
        cout << "\n\nModify Lab Recorded Section......";
        cout << "\n\nEnter the LAB number: ";
        cin >> n;
        fp.open("lab.dat", ios::in | ios::out);
        while ((fp.read((char *)&lab, sizeof(Lab))) && found == 0)
        {
            if (strcmpi(lab.id, n) == 0)
            {
                cout << lab;
                cout << "\nEnter The New Details of Lab\n";
                lab.modifyLab();
                int pos = -1 * sizeof(Lab);
                fp.seekp(pos, ios::cur);
                fp.write((char *)&lab, sizeof(Lab));
                cout << "\n\n\t Record Updated...";
                found = 1;
            }
        }
        fp.close();
        if (found == 0)
            cout << "\n\n Record Not Found";
    }

    void modifyReport()
    {
        char n[6];
        int found = 0;
        cout << "\n\nModify Report Recorded Section......";
        cout << "\n\nEnter the Report Number: ";
        cin >> n;
        fp.open("report.dat", ios::in | ios::out);
        while ((fp.read((char *)&report, sizeof(Report))) && found == 0)
        {
            if (strcmpi(report.id, n) == 0)
            {
                cout << report;
                cout << "\nEnter The New Details of Report\n";
                report.modifyReport();
                int pos = -1 * sizeof(Report);
                fp.seekp(pos, ios::cur);
                fp.write((char *)&report, sizeof(Report));
                cout << "\n\n\t Record Updated...";
                found = 1;
            }
        }
        fp.close();
        if (found == 0)
            cout << "\n\n Record Not Found";
    }

    //***************************************************************
    ///    	function to delete record of file
    //****************************************************************

    void deleteLab()
    {
        char n[6];
        int flag = 0;
        cout << "\n\n\n\tDelete LAB...";
        cout << "\n\nEnter the LAB NUMBER: ";
        cin >> n;
        fp.open("lab.dat", ios::in | ios::out);
        fstream fp2;
        fp2.open("temp.dat", ios::out);
        fp.seekg(0, ios::beg);
        while (fp.read((char *)&lab, sizeof(Lab)))
        {
            if (strcmpi(lab.id, n) != 0)
            {
                fp2.write((char *)&lab, sizeof(Lab));
            }
            else
                flag = 1;
        }
        fp2.close();
        fp.close();
        remove("lab.dat");
        rename("temp.dat", "lab.dat");
        if (flag == 1)
            cout << "\n\n\tRecord Deleted ..";
        else
            cout << "\n\nRecord not found";
    }

    //***************************************************************
    ///    	function to display all students list
    //****************************************************************

    void displayAllLABS()
    {
        fp.open("lab.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! File Could not be OPEN";
            return;
        }
        cout << "\n\n\t\t LAB List\n\n";
        cout << "===================================================================================================\n";
        cout << setw(6) << left << "ID"
             << " | " << setw(20) << left << "Name"
             << " | " << setw(7) << left << "Room No"
             << " | " << setw(4) << left << "Fee"
             << " | " << endl;
        cout << "=====================================================================================================\n";

        while (fp.read((char *)&lab, sizeof(Lab)))
        {
            lab.report();
        }
        fp.close();
    }

    void displayAllReport()
    {
        fp.open("report.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! File Could not be OPEN";
            return;
        }
        cout << "\n\n\t\t Report List\n\n";
        cout << "===================================================================================================\n";
        cout << setw(6) << left << "ID"
             << " | " << setw(7) << left << "USER ID"
             << " | " << setw(20) << left << "TITLE"
             << " | " << setw(15) << left << "RESULT"
             << " | " << endl;
        cout << "=====================================================================================================\n";

        while (fp.read((char *)&report, sizeof(Report)))
        {
            report.reportAll();
        }
        fp.close();
    }
};

//***************************************************************
///    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{

    cout << "\n\nProject : Pathology Lab Management System OOP Project";
    cout << "\n\nMADE BY : MEHEDI HASAN SHUVO";
    cout << "\n\nUniversity : Dhaka University & Engineering Technology";
}

//***************************************************************
///    	ADMINISTRATOR MENU FUNCTION
//****************************************************************

void adminMenuLAB()
{

    int ch2;
    Adminestrator adminestrator;

    cout << "\n\n\n\tLAB MENU";
    cout << "\n\n\t1.CREATE LAB RECORD";
    cout << "\n\n\t2.DISPLAY ALL LAB RECORD";
    cout << "\n\n\t3.DISPLAY SPECIFIC LAB RECORD ";
    cout << "\n\n\t4.MODIFY LAB RECORD";
    cout << "\n\n\t5.DELETE LAB RECORD";
    cout << "\n\n\t6.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-6) ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        adminestrator.insertLab();
        break;
    case 2:
        adminestrator.displayAllLABS();

        break;
    case 3:
        char num[6];

        cout << "\n\n\tPlease Enter The LAB ID: ";
        cin >> num;
        adminestrator.displaySpecificLab(num);
        break;
    case 4:
        adminestrator.modifyLab();
        break;
    case 5:
        adminestrator.deleteLab();
        break;
    case 6:
        return;
    default:
        cout << "\a";
    }
    adminMenuLAB();
}

void adminMenuREPORT()
{

    int ch2;
    Adminestrator adminestrator;

    cout << "\n\n\n\tREPORT MENU";
    cout << "\n\n\t1.DISPLAY ALL REPORT RECORD";
    cout << "\n\n\t2.DISPLAY SPECIFIC REPORT RECORD ";
    cout << "\n\n\t3.GIVE LAB REPORT";
    cout << "\n\n\t4.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-4) ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        adminestrator.displayAllReport();

        break;
    case 2:
        char num[6];

        cout << "\n\n\tPlease Enter The REPORT ID: ";
        cin >> num;
        adminestrator.displaySpecificReport(num);
        break;
    case 3:
        adminestrator.modifyReport();
        break;
    case 4:
        return;
    default:
        cout << "\a";
    }
    adminMenuREPORT();
}

//***************************************************************
///    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
    char ch;
    Adminestrator adminestrator;
    intro();
    do
    {

        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. LAB SECTION";
        cout << "\n\n\t02. REPORT SECTION";
        cout << "\n\n\t03. ADD APPOINTMENT";
        cout << "\n\n\t04. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-4) ";
        ch = getche();
        switch (ch)
        {
        case '1':
            adminMenuLAB();
            break;
        case '2':
            adminMenuREPORT();
            break;
        case '3':
            adminestrator.addSLNo();
            break;
        case '4':
            exit(0);
        default:
            cout << "\a";
        }
    } while (ch != '4');
    return 0;
}

//***************************************************************
///    			END OF PROJECT
//***************************************************************
