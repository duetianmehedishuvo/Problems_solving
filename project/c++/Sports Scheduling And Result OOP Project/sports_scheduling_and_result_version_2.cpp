//                           Header File in Project
//************************************************************
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
///                   CLASS USED IN PROJECT
//****************************************************************
class Item
{
public:
    char id[6];
    char name[20];
};
class Team : public Item
{
    int winODI;
    int lostODI;
    int winTest;
    int lostTest;
    int winT20;
    int lostT20;
    friend std::ostream &operator<<(std::ostream &out, const Team &team);
    friend std::istream &operator>>(std::istream &in, Team &team);

public:
    void modifyTeam()
    {
        cout << "\nTeam ID: " << id;
        cout << "\nName: ";
        cin.ignore();
        cin.getline(name, 20, '\n');
        cout << "\nWin ODI?: ";
        cin >> winODI;
        cout << "\nLost ODI?: ";
        cin >> lostODI;
        cout << "\nWin TEST?: ";
        cin >> winTest;
        cout << "\nLost TEST?: ";
        cin >> lostTest;
        cout << "\nWin T20?: ";
        cin >> winT20;
        cout << "\nLost T20?: ";
        cin >> lostT20;
    }
    void modifyTeamAfterResult(bool win, int statusODI, int statusTEST, int statusT20)
    {

        if (win == true)
        {
            winODI += statusODI;
            winTest += statusTEST;
            winT20 += statusT20;
        }
        else
        {
            lostODI += statusODI;
            lostTest+= statusTEST;
            lostT20 += statusT20;
        }
    }

    char *getTeamID()
    {
        return id;
    }

    void report()
    {
        cout << setw(6) << left << id
             << " * " << setw(20) << left << name
             << " * " << setw(7) << left << winODI
             << " * " << setw(9) << left << lostODI
             << " * " << setw(8) << left << winTest
             << " * " << setw(9) << left << lostTest
             << " * " << setw(7) << left << winT20
             << " * " << setw(8) << left << lostT20
             << " * " << endl;
    }
};
class Schedulling : public Team
{
    char schedulingID[6];
    char teamA[6];
    char teamB[6];
    char teamAName[15];
    char teamBName[15];
    char date[12];
    char result[20];
    int isODI;
    int isTEST;
    int isT20;
    friend std::ostream &operator<<(std::ostream &out, const Schedulling &schedulling);
    friend std::istream &operator>>(std::istream &in, Schedulling &schedulling);

public:
    char *getTeamAID()
    {
        return teamA;
    }
    char *getTeamBID()
    {
        return teamB;
    }
    int getODIStatus()
    {
        return isODI;
    }
    int getTESTStatus()
    {
        return isTEST;
    }
    int getT20Status()
    {
        return isT20;
    }

    void modifySchedullingResult()
    {

        cout << "\nSchedulling ID: " << schedulingID;
        cout << "\nResult: ";
        cin.ignore();
        cin.getline(result, 20, '\n');
    }
    char *getSchedullingID()
    {
        return schedulingID;
    }

    void report()
    {
        string odiStatus=isODI?"Yes":"No";
        string testStatus=isTEST?"Yes":"No";
        string t20Status=isT20?"Yes":"No";

        cout << setw(10) << left << schedulingID
             << " * " << setw(6) << left << teamA
             << " * " << setw(15) << left << teamAName
             << " * " << setw(6) << left << teamB
             << " * " << setw(15) << left << teamBName
             << " * " << setw(12) << left << date
             << " * " << setw(20) << left << result
             << " * " << setw(3) << left << odiStatus
             << " * " << setw(4) << left << testStatus
             << " * " << setw(3) << left << t20Status
             << " * " << endl;
    }
};

///    	Operating Overloading section
//****************************************************************
ostream &operator<<(ostream &out, const Team &team)
{
    out << "\nId: " << team.id;
    out << "\nName: " << team.name;
    out << "\nWin ODI: " << team.winODI;
    out << "\nLost ODI: " << team.lostODI;
    out << "\nWin Test: " << team.winTest;
    out << "\nLost Test: " << team.lostTest;
    out << "\nWin T20: " << team.winT20;
    out << "\nLost T20: " << team.lostT20;
    return out;
}
istream &operator>>(istream &in, Team &team)
{
    cout << "\nNew Team Entry.....\n";
    cout << "\nEnter The Team ID: ";
    in >> team.id;
    cout << "\nName: ";
    in.ignore();
    in.getline(team.name, sizeof(team.name), '\n');
    cout << "\nWin ODI?: ";
    in >> team.winODI;
    cout << "\nLost ODI?: ";
    in >> team.lostODI;
    cout << "\nWin TEST?: ";
    in >> team.winTest;
    cout << "\nLost TEST?: ";
    in >> team.lostTest;
    cout << "\nWin T20?: ";
    in >> team.winT20;
    cout << "\nLost T20?: ";
    in >> team.lostT20;
    cout << "\n\nTeam Created Successfully..";

    return in;
}
ostream &operator<<(ostream &out, const Schedulling &schedulling)
{

    string odiStatus=schedulling.isODI?"Yes":"No";
        string testStatus=schedulling.isTEST?"Yes":"No";
        string t20Status=schedulling.isT20?"Yes":"No";

    out << "\nId: " << schedulling.schedulingID;
    out << "\nTeam A ID: " << schedulling.teamA;
    out << "\nTeam A NAME: " << schedulling.teamAName;
    out << "\nTeam B ID: " << schedulling.teamB;
    out << "\nTeam B NAME: " << schedulling.teamBName;
    out << "\nDate: " << schedulling.date;
    out << "\nResult: " << schedulling.result;
    out << "\nIs Odi: " << odiStatus;
    out << "\nIS Test: " << testStatus;
    out << "\nIS T20: " << t20Status;

    return out;
}
istream &operator>>(istream &in, Schedulling &schedulling)
{

    cout << "\nNew Schedulling Entry.....\n";
    cout << "\nEnter The Schedulling ID: ";
    in >> schedulling.schedulingID;
    cout << "\nTeam A ID: ";
    in >> schedulling.teamA;
    cout << "\nTeam A Name: ";
    in.ignore();
    in.getline(schedulling.teamAName,15,'\n');
    cout << "\nTeam B ID: ";
    in >> schedulling.teamB;
    cout << "\nTeam B Name: ";
    in.ignore();
    in.getline(schedulling.teamBName,15,'\n');
    cout << "\nDate: ";
    in.clear();
    in.getline(schedulling.date,12,'\n');
    cout << "\nResult: ";
    in.clear();
    in.getline(schedulling.result, sizeof(schedulling.result), '\n');
    cout << "\nIS ODI?: ";
    in >> schedulling.isODI;
    cout << "\nIS TEST?: ";
    in >> schedulling.isTEST;
    cout << "\nIS T20?: ";
    in >> schedulling.isT20;
    cout << "\n\nSchedulling Created Successfully..";

    return in;
}

///    	global declaration for stream object, object
//****************************************************************
fstream fp, fp1;
class PointTable : public Team, public Schedulling
{
    Team team;
    Schedulling schedulling;

public:

    ///    	function to write in file
//****************************************************************
    void insertTeam()
    {
        char ch;
        fp.open("team.dat", ios::out | ios::app);
        do
        {
            cin >> team;
            fp.write((char *)&team, sizeof(Team));
            cout << "\n\nDo you Want to add more record..(y/n?): ";
            cin >> ch;
        }
        while (ch == 'y' || ch == 'Y');
        fp.close();
    }

    void createSchedulling()
    {
        char ch;
        fp.open("schedulling.dat", ios::out | ios::app);
        do
        {
            cin >> schedulling;
            fp.write((char *)&schedulling, sizeof(Schedulling));
            cout << "\n\nDo you Want to add more record..(y/n?): ";
            cin >> ch;
        }
        while (ch == 'y' || ch == 'Y');
        fp.close();
    }

    ///   	function to read specific record from file
//****************************************************************
    void displaySpecificTeam(char n[])
    {
        cout << "\nTeam Details\n";
        int flag = 0;
        fp.open("team.dat", ios::in);
        while (fp.read((char *)&team, sizeof(Team)))
        {
            if (strcmpi(team.getTeamID(), n) == 0)
            {
                cout << team;
                flag = 1;
            }
        }
        fp.close();
        if (flag == 0)
            cout << "\n\nTeam does not exist.";
    }
    void displaySpecificSchedulling(char n[])
    {
        cout << "\nSchedulling Details\n";
        int flag = 0;
        fp.open("schedulling.dat", ios::in);
        while (fp.read((char *)&schedulling, sizeof(Schedulling)))
        {
            if (strcmpi(schedulling.getSchedullingID(), n) == 0)
            {
                cout << schedulling;
                flag = 1;
            }
        }
        fp.close();
        if (flag == 0)
            cout << "\n\nSchedullingdoes not exist.";
    }
    void modifyTeam()
    {
        char n[6];
        int found = 0;
        cout << "\n\nModify Team Recorded Section......";
        cout << "\n\nEnter the Team ID: ";
        cin >> n;
        fp.open("team.dat", ios::in | ios::out);
        while (fp.read((char *)&team, sizeof(Team)) && found == 0)
        {
            if (strcmpi(team.getTeamID(), n) == 0)
            {
                cout << team;
                cout << "\nEnter The New Details of Team\n";
                team.modifyTeam();
                int pos = -1 * sizeof(Team);
                fp.seekp(pos, ios::cur);
                fp.write((char *)&team, sizeof(Team));
                cout << "\n\n\t Record Updated...";
                found = 1;
            }
        }
        fp.close();
        if (found == 0)
            cout << "\n\n Record Not Found";
    }
    void modifyTeamAfterResult(char n[6], int odi, int test, int t20, bool isWin,int found )
    {
        fp.open("team.dat", ios::in | ios::out);
        while ((fp.read((char *)&team, sizeof(Team))) && found == 0)
        {
            if (strcmpi(team.getTeamID(), n) == 0)
            {
                team.modifyTeamAfterResult(isWin, odi, test, t20);
                int pos = -1 * sizeof(Team);
                fp.seekp(pos, ios::cur);
                fp.write((char *)&team, sizeof(Team));
                cout << "\n\n Record Found User ..." << n << endl;
                found = 1;
            }
        }
        fp.close();
        if (found == 0)
            cout << "\n\n Record Not Found\n\n";
    }
    void modifySchedullingResult()
    {
        char n[6];
        int found = 0;
        cout << "\n\nModify Schedulling Result Recorded Section......";
        cout << "\n\nEnter the Schedulling ID: ";
        cin >> n;
        fp1.open("schedulling.dat", ios::in | ios::out);
        while ((fp1.read((char *)&schedulling, sizeof(Schedulling))) && found == 0)
        {
            if (strcmpi(schedulling.getSchedullingID(), n) == 0)
            {
                int isWinTeamA;
                cout << "Win Team A (0 or 1)?: ";
                cin >> isWinTeamA;

                if (isWinTeamA == 0)
                {

                    modifyTeamAfterResult(schedulling.getTeamAID(), schedulling.getODIStatus(), schedulling.getTESTStatus(), schedulling.getT20Status(), true, 0);
                    modifyTeamAfterResult(schedulling.getTeamBID(), schedulling.getODIStatus(),  schedulling.getTESTStatus(), schedulling.getT20Status(), false, 0);
                }
                else
                {
                    modifyTeamAfterResult(schedulling.getTeamAID(), schedulling.getODIStatus(), schedulling.getTESTStatus(), schedulling.getT20Status(), false, 0);
                    modifyTeamAfterResult(schedulling.getTeamBID(), schedulling.getODIStatus(), schedulling.getTESTStatus(), schedulling.getT20Status(), true, 0);
                }

                schedulling.modifySchedullingResult();
                int pos = -1 * sizeof(Schedulling);
                fp1.seekp(pos, ios::cur);
                fp1.write((char *)&schedulling, sizeof(Schedulling));
                cout << "\n\n\t Record Updated...";
                found = 1;
            }
        }
        fp1.close();
        if (found == 0)
            cout << "\n\n Record Not Found";
    }

    ///    	function to delete record of file
    //****************************************************************
    void deleteTeam()
    {
        char n[6];
        cout << "\n\n\n\tDelete Team.............";
        cout << "\n\nEnter the Team ID: ";
        cin >> n;
        fp.open("team.dat", ios::in | ios::out);
        fstream fp2;
        fp2.open("temp.dat", ios::out);
        fp.seekg(0, ios::beg);
        while (fp.read((char *)&team, sizeof(Team)))
        {
            if (strcmpi(team.getTeamID(), n) != 0)
            {
                fp2.write((char *)&team, sizeof(Team));
            }
        }
        fp2.close();
        fp.close();
        remove("team.dat");
        rename("temp.dat", "team.dat");
        cout << "\n\n\tRecord Deleted ..";
    }

    ///    	function to display all list
    //****************************************************************
    void displayAllTeam()
    {
        fp.open("team.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! File Could not be OPEN";
            return;
        }
        cout << "\n\n\t\t Team List\n\n";
        cout << setw(6) << left << "ID"
             << " * " << setw(20) << left << "Name"
             << " * " << setw(7) << left << "Win ODI"
             << " * " << setw(8)<< left << "Lost ODI"
             << " * " << setw(9) << left << "Win TEST"
             << " * " << setw(9) << left << "Lost TEST"
             << " * " << setw(7) << left << "Win T20"
             << " * " << setw(9) << left << "Lost T20"
             << " * " << endl;

        while (fp.read((char *)&team, sizeof(Team)))
        {
            team.report();
        }
        fp.close();
    }
    void displayAllSchedulling()
    {
        fp.open("schedulling.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! File Could not be OPEN";
            return;
        }
        cout << "\n\n\t\t Schedulling List\n\n";
        cout << "=================================================================================================================================\n";
        cout << setw(10) << left << "ID"
             << " | " << setw(6) << left << "Team A"
             << " | " << setw(15) << left << "Team A NAME"
             << " | " << setw(6) << left << "Team B"
             << " | " << setw(15) << left << "Team B NAME"
             << " | " << setw(12) << left << "Date"
             << " | " << setw(20) << left << "Result"
             << " | " << setw(3) << left << "ODI"
             << " | " << setw(4) << left << "TEST"
             << " | " << setw(3) << left << "T20"
             << " | " << endl;

        cout << "==================================================================================================================================\n";

        while (fp.read((char *)&schedulling, sizeof(Schedulling)))
        {
            schedulling.report();
        }
        fp.close();
    }
};
///    	INTRODUCTION FUNCTION
//****************************************************************
void adminMenuTeam()
{
    int ch2;
    PointTable poinTable;
    cout << "\n\n\n\tTEAM MENU";
    cout << "\n\n\t1.CREATE TEAM RECORD";
    cout << "\n\n\t2.DISPLAY ALL TEAM RECORD";
    cout << "\n\n\t3.DISPLAY SPECIFIC TEAM RECORD ";
    cout << "\n\n\t4.MODIFY TEAM RECORD";
    cout << "\n\n\t5.DELETE TEAM RECORD";
    cout << "\n\n\t6.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-6) ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        poinTable.insertTeam();
        break;
    case 2:
        poinTable.displayAllTeam();
        break;
    case 3:
        char num[6];
        cout << "\n\n\tPlease Enter The Team ID: ";
        cin >> num;
        poinTable.displaySpecificTeam(num);
        break;
    case 4:
        poinTable.modifyTeam();
        break;
    case 5:
        poinTable.deleteTeam();
        break;
    case 6:
        return;
    default:
        cout << "\a";
    }
    adminMenuTeam();
}
void adminMenuSchedulling()
{

    int ch2;
    PointTable poinTable;

    cout << "\n\n\n\tSCHEDULLING MENU";
    cout << "\n\n\t1.CREATE SCHEDULLING RECORD";
    cout << "\n\n\t2.DISPLAY ALL SCHEDULLING RECORD";
    cout << "\n\n\t3.DISPLAY SPECIFIC SCHEDULLING RECORD ";
    cout << "\n\n\t4.MODIFY SCHEDULLING RECORD";
    cout << "\n\n\t5.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-5) ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        poinTable.createSchedulling();
        break;
    case 2:
        poinTable.displayAllSchedulling();
        break;
    case 3:
        char num[6];
        cout << "\n\n\tPlease Enter The Schedulling ID: ";
        cin >> num;
        poinTable.displaySpecificSchedulling(num);
        break;
    case 4:
        poinTable.modifySchedullingResult();
        break;
    case 5:
        return;
    default:
        cout << "\a";
    }
    adminMenuSchedulling();
}
///    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
    char ch;
    do
    {
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. TOUNERMENT SCHEDULLINNG MENU";
        cout << "\n\n\t02. TEAM MENU";
        cout << "\n\n\t03. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        ch = getche();
        switch (ch)
        {
        case '2':
            adminMenuTeam();
            break;
        case '1':
            adminMenuSchedulling();
            break;
        case '3':
            exit(0);
        default:
            cout << "\a";
        }
    }
    while (ch != '3');
    return 0;
}
///    			END OF PROJECT
//****************************************************************
