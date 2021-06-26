///***********************************************************
//                           Header File in Project
//************************************************************

#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

//***************************************************************
///                   CLASS USED IN PROJECT
//****************************************************************
class User
{
    char id[6];
    char name[20];
    double salary;
    int age;
    int experence;
    friend std::ostream &operator<<(std::ostream &out, const User &user);
    friend std::istream &operator>>(std::istream &in, User &user);

public:
    void modifyUser()
    {
        cout << "\nEmployee ID: " << id;
        cout << "\nName: ";
        cin.ignore();
        cin.getline(name, 20, '\n');
        cout << "\nSalary: ";
        cin >> salary;
        cout << "\nAge: ";
        cin >> age;
        cout << "\nExperience: ";
        cin >> experence;
    }

    char *getUserID() { return id; }
    void reportUser()
    {
        cout << setw(6) << left << id
             << " | " << setw(20) << left << name
             << " | " << setw(6) << left << salary
             << " | " << setw(9) << left << experence
             << " | " << setw(3) << left << age
             << " | " << endl;
    }
};

class Leave : public User
{
    int casualStatus;
    int sickStatus;
    int studyStatus;
    int perentalStatus;
    char startDate[10];
    char endDate[10];
    int days;
    char leaveID[6];

    friend std::ostream &operator<<(std::ostream &out, const Leave &leave);
    friend std::istream &operator>>(std::istream &in, Leave &leave);

public:
    void modifyLeaveStatus()
    {
        cout << "\nLeave ID: " << leaveID;
        cout << "\nUser ID: " << getUserID();
        cout << "\nCasual Status: ";
        cin >> casualStatus;
        cout << "Sick Status: ";
        cin >> sickStatus;
        cout << "Study Status: ";
        cin >> studyStatus;
        cout << "Parental Status: ";
        cin >> perentalStatus;
        cout << "Start Date: ";
        cin >> startDate;
        cout << "End Date: ";
        cin >> endDate;
        cout << "Days: ";
        cin >> days;
    }
    char *getLeaveID() { return leaveID; }
    void reportLeave()
    {
        cout << setw(6) << left << leaveID
             << " | " << setw(7) << left << getUserID()
             << " | " << setw(13) << left << casualStatus
             << " | " << setw(11) << left << sickStatus
             << " | " << setw(12) << left << studyStatus
             << " | " << setw(15) << left << perentalStatus
             << " | " << setw(10) << left << startDate
             << " | " << setw(8) << left << endDate
             << " | " << setw(4) << left << days
             << " | " << endl;
    }
};

//***************************************************************
///                   Operator Overloading IN PROJECT
//****************************************************************

ostream &operator<<(ostream &out, const User &user)
{
    out << "\nEmployee ID: " << user.id;
    out << "\nName: " << user.name;
    out << "\nSalary: " << user.salary;
    out << "\nAge: " << user.age;
    out << "\nExperence: " << user.experence;

    return out;
}

istream &operator>>(istream &in, User &user)
{

    cout << "\nNew User Entry.....\n";
    cout << "\nEnter The User ID: ";
    in >> user.id;
    cout << "\nEnter the name of the Employee: ";
    in.ignore();
    in.getline(user.name, 20, '\n');
    cout << "\nSalary: ";
    in >> user.salary;
    cout << "\nAge: ";
    in >> user.age;
    cout << "\nExperience: ";
    in >> user.experence;

    cout << "\n\nUser Created Successfully..";

    return in;
}

ostream &operator<<(ostream &out, const Leave &leave)
{

    out << "\nCasual Leave Status: " << leave.casualStatus;
    out << "\nSick Leave Status: " << leave.sickStatus;
    out << "\nStudy Leave Status: " << leave.studyStatus;
    out << "\nParental Leave Status: " << leave.perentalStatus;
    out << "\nStart Date: " << leave.startDate;
    out << "\nEnd Date: " << leave.endDate;
    out << "\nDays: " << leave.days;

    return out;
}

istream &operator>>(istream &in, Leave &leave)
{

    cout << "\nLeave ID: ";
    in >> leave.leaveID;
    cout << "\nUser ID: ";
    in >> leave.getUserID();
    cout << "\nCasual Status: ";
    in >> leave.casualStatus;
    cout << "\nSick Status: ";
    in >> leave.sickStatus;
    cout << "\nStudy Status: ";
    in >> leave.studyStatus;
    cout << "\nParental Status: ";
    in >> leave.perentalStatus;
    cout << "\nStart Date: ";
    in >> leave.startDate;
    cout << "\nEnd Date: ";
    in >> leave.endDate;
    cout << "\nDays: ";
    in >> leave.days;

    cout << "\n\nLeave Created Successfully..";

    return in;
}

//***************************************************************
///    	global declaration for stream object, object
//****************************************************************

fstream fp, fp1;

//***************************************************************
///    	Database Section Start In This Class
//****************************************************************

class Adminestrator : public Leave, public User
{
    User user;
    Leave leave;

public:
    //***************************************************************
    ///    	function to write in file
    //****************************************************************

    void insertUser()
    {
        char ch;
        fp.open("user.dat", ios::out | ios::app);
        do
        {
            cin >> user;
            fp.write((char *)&user, sizeof(User));
            cout << "\n\nDo you Want to add more record..(y/n?): ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
        fp.close();
    }

    void applyLeave()
    {
        char ch;
        fp.open("leave.dat", ios::out | ios::app);
        do
        {
            cin >> leave;
            fp.write((char *)&leave, sizeof(Leave));
            cout << "\n\nDo you Want to add more record..(y/n?): ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
        fp.close();
    }

    //***************************************************************
    ///   	function to read specific record from file
    //****************************************************************

    void displaySpecificUser(char n[])
    {
        cout << "\nUser Details\n";
        int flag = 0;
        fp.open("user.dat", ios::in);
        while (fp.read((char *)&user, sizeof(User)))
        {
            if (strcmpi(user.getUserID(), n) == 0)
            {
                cout << user;
                flag = 1;
            }
        }
        fp.close();
        if (flag == 0)
            cout << "\n\nUser does not exist.";
    }

    void displaySpecificLeave(char n[])
    {
        cout << "\nLeave Details\n";
        int flag = 0;
        fp.open("leave.dat", ios::in);
        while (fp.read((char *)&leave, sizeof(Leave)))
        {
            if (strcmpi(leave.getLeaveID(), n) == 0)
            {
                cout << leave;
                flag = 1;
            }
        }
        fp.close();
        if (flag == 0)
            cout << "\n\nUser does not exist.";
    }

    //***************************************************************
    ///    	function to modify record of file
    //****************************************************************

    void modifyUser()
    {
        char n[6];
        int found = 0;
        cout << "\n\nModify User Recorded Section......";
        cout << "\n\nEnter the User ID: ";
        cin >> n;
        fp.open("user.dat", ios::in | ios::out);
        while ((fp.read((char *)&user, sizeof(User))) && found == 0)
        {
            if (strcmpi(user.getUserID(), n) == 0)
            {
                cout << user;
                cout << "\nEnter The New Details of User\n";
                user.modifyUser();
                int pos = -1 * sizeof(user);
                fp.seekp(pos, ios::cur);
                fp.write((char *)&user, sizeof(User));
                cout << "\n\n\t Record Updated...";
                found = 1;
            }
        }
        fp.close();
        if (found == 0)
            cout << "\n\n Record Not Found";
    }

    void modifyLeave()
    {
        char n[6];
        int found = 0;
        cout << "\n\nModify Leave Recorded Section......";
        cout << "\n\nEnter the Leave ID: ";
        cin >> n;
        fp.open("leave.dat", ios::in | ios::out);
        while ((fp.read((char *)&leave, sizeof(Leave))) && found == 0)
        {
            if (strcmpi(leave.getLeaveID(), n) == 0)
            {
                cout << leave;
                cout << "\nEnter The New Details of Leave\n";
                leave.modifyLeaveStatus();
                int pos = -1 * sizeof(leave);
                fp.seekp(pos, ios::cur);
                fp.write((char *)&leave, sizeof(Leave));
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

    void deleteUser()
    {
        char n[6];
        cout << "\n\n\n\tDelete User.............";
        cout << "\n\nEnter the User ID: ";
        cin >> n;
        fp.open("user.dat", ios::in | ios::out);
        fstream fp2;
        fp2.open("temp.dat", ios::out);
        fp.seekg(0, ios::beg);
        while (fp.read((char *)&user, sizeof(User)))
        {
            if (strcmpi(user.getUserID(), n) != 0)
            {
                fp2.write((char *)&user, sizeof(User));
            }
        }
        fp2.close();
        fp.close();
        remove("user.dat");
        rename("temp.dat", "user.dat");
        cout << "\n\n\tRecord Deleted ..";
    }

    void deleteLeave()
    {
        char n[6];
        cout << "\n\n\n\tDelete Leave.............";
        cout << "\n\nEnter the Leave ID: ";
        cin >> n;
        fp.open("leave.dat", ios::in | ios::out);
        fstream fp2;
        fp2.open("temp.dat", ios::out);
        fp.seekg(0, ios::beg);
        while (fp.read((char *)&leave, sizeof(Leave)))
        {
            if (strcmpi(leave.getLeaveID(), n) != 0)
            {
                fp2.write((char *)&leave, sizeof(Leave));
            }
        }
        fp2.close();
        fp.close();
        remove("leave.dat");
        rename("temp.dat", "leave.dat");
        cout << "\n\n\tRecord Deleted ..";
    }

    //***************************************************************
    ///    	function to display all students list
    //****************************************************************

    void displayAllUser()
    {
        fp.open("user.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! File Could not be OPEN";
            return;
        }
        cout << "\n\n\t\t User List\n\n";

        cout << "=================================================================================================================================\n";
        cout << setw(6) << left << "ID"
             << " | " << setw(20) << left << "Name"
             << " | " << setw(6) << left << "Salary"
             << " | " << setw(9) << left << "Experence"
             << " | " << setw(3) << left << "Age"
             << " | " << endl;

        cout << "==================================================================================================================================\n";

        while (fp.read((char *)&user, sizeof(User)))
        {
            user.reportUser();
        }
        fp.close();
    }

    void displayAllLeave()
    {
        fp.open("leave.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! File Could not be OPEN";
            return;
        }
        cout << "\n\n\t\t Leave Status List\n\n";

        cout << "=================================================================================================================================\n";
        cout << setw(6) << left << "ID"
             << " | " << setw(7) << left << "User ID"
             << " | " << setw(13) << left << "Casual Status"
             << " | " << setw(11) << left << "Sick Status"
             << " | " << setw(12) << left << "Study Status"
             << " | " << setw(15) << left << "Parental Status"
             << " | " << setw(10) << left << "Start Date"
             << " | " << setw(8) << left << "End Date"
             << " | " << setw(4) << left << "Days"
             << " | " << endl;

        cout << "==================================================================================================================================\n";

        while (fp.read((char *)&leave, sizeof(Leave)))
        {
            leave.reportLeave();
        }
        fp.close();
    }
};

//***************************************************************
///    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
    cout << "\n\nProject : Leave Management System";
    cout << "\n\nMADE BY : MEHEDI HASAN SHUVO";
    cout << "\n\nUniversity : Dhaka University & Engineering Technology";
}

//***************************************************************
///    	ADMINISTRATOR MENU FUNCTION
//****************************************************************

void admin_menu()
{

    int ch2;
    Adminestrator adminestrator;

    cout << "\n\n\n\tADMINISTRATOR MENU";
    cout << "\n\n\t1.CREATE EMPLOYEE RECORD";
    cout << "\n\n\t2.DISPLAY ALL EMPLOYEE RECORD";
    cout << "\n\n\t3.DISPLAY SPECIFIC EMPLOYEE RECORD ";
    cout << "\n\n\t4.MODIFY EMPLOYEE RECORD";
    cout << "\n\n\t5.DELETE EMPLOYEE RECORD";
    cout << "\n\n\t6.CREATE LEAVE ";
    cout << "\n\n\t7.DISPLAY ALL LEAVE ";
    cout << "\n\n\t8.DISPLAY SPECIFIC LEAVE ";
    cout << "\n\n\t9.MODIFY LEAVE ";
    cout << "\n\n\t10.DELETE LEAVE ";
    cout << "\n\n\t11.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-11) ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        adminestrator.insertUser();
        break;
    case 2:
        adminestrator.displayAllUser();

        break;
    case 3:
        char num[6];

        cout << "\n\n\tPlease Enter The Employee ID: ";
        cin >> num;
        adminestrator.displaySpecificUser(num);
        break;
    case 4:
        adminestrator.modifyUser();
        break;
    case 5:
        adminestrator.deleteUser();
        break;
    case 6:
        adminestrator.applyLeave();
        break;
    case 7:
        adminestrator.displayAllLeave();
        break;
    case 8:
    {
        char num[6];

        cout << "\n\n\tPlease Enter The Leave ID: ";
        cin >> num;
        adminestrator.displaySpecificLeave(num);
        break;
    }
    case 9:
        adminestrator.modifyLeave();
        break;
    case 10:
        adminestrator.deleteLeave();
        break;
    case 11:
        return;
    default:
        cout << "\a";
    }
    admin_menu();
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
        cout << "\n\n\t01. ADMINISTRATOR MENU";
        cout << "\n\n\t02. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-1) ";
        ch = getche();
        switch (ch)
        {
        case '1':
            admin_menu();
            break;
        case '2':
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
