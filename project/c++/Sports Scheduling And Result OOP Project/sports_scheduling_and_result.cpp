#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

class Item
{
public:
    char id[6];
    char name[20];
};

class Player : public Item
{
    char teamID[6];
    int isAlrounder;
    int isTopBoller;
    int isTopBatsman;
    float battingAvg;
    float bollingAVg;
    friend std::ostream &operator<<(std::ostream &out, const Player &player);
    friend std::istream &operator>>(std::istream &in, Player &player);

public:
    void modifyPlayer()
    {
        cout << "\nPlayer ID: " << id;
        cout << "\nName: ";
        cin.ignore();
        cin.getline(name, sizeof(name), '\n');
        cout << "\nTeam ID: ";
        cin >> teamID;
        cout << "\nIs Alrounder? : ";
        cin >> isAlrounder;
        cout << "\nIs Top Batsman? : ";
        cin >> isTopBatsman;
        cout << "\nIs Top Boller? : ";
        cin >> isTopBoller;
        cout << "\nBatting Average: ";
        cin >> battingAvg;
        cout << "\nBolling Average: ";
        cin >> bollingAVg;
    }

    char *getPlayerID() { return id; }
    char *getTeamID() { return teamID; }

    void report()
    {
        cout << setw(6) << left << id << " | " << setw(20) << left << name << " | " << setw(7) << left << teamID << " | " << setw(9) << left << isAlrounder << " | " << setw(10) << left << isTopBatsman << " | " << setw(9) << left << isTopBoller << " | " << setw(11) << left << battingAvg << " | " << setw(11) << left << bollingAVg << " | " << endl;
    }
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
        cout << "\nTeam ID: " << id;
        cout<<"\nMan Power: "<<statusODI<<" "<<win<<endl;

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

    char *getTeamID() { return id; }

    void report()
    {
        cout << setw(6) << left << id
             << " | " << setw(20) << left << name
             << " | " << setw(7) << left << winODI
             << " | " << setw(8) << left << lostODI
             << " | " << setw(8) << left << winTest
             << " | " << setw(9) << left << lostTest
             << " | " << setw(7) << left << winT20
             << " | " << setw(8) << left << lostT20
             << " | " << endl;
    }
};

class Schedulling : public Team
{
    char schedulingID[6];
    char teamA[6];
    char teamB[6];
    char result[20];
    int isODI;
    int isTEST;
    int isT20;
    friend std::ostream &operator<<(std::ostream &out, const Schedulling &schedulling);
    friend std::istream &operator>>(std::istream &in, Schedulling &schedulling);

public:
    char *getTeamAID() { return teamA; }
    char *getTeamBID() { return teamB; }
    int getODIStatus() { return isODI; }
    int getTESTStatus() { return isTEST; }
    int getT20Status() { return isT20; }

    void modifySchedullingResult()
    {
        
        cout << "\nSchedulling ID: " << schedulingID;
        cout << "\nResult: ";
        cin.ignore();
        cin.getline(result, 20, '\n');
    }

    char *getSchedullingID() { return schedulingID; }

    void report()
    {
        cout << setw(6) << left << schedulingID
             << " | " << setw(6) << left << teamA
             << " | " << setw(6) << left << teamB
             << " | " << setw(20) << left << result
             << " | " << setw(3) << left << isODI
             << " | " << setw(4) << left << isTEST
             << " | " << setw(3) << left << isT20
             << " | " << endl;
    }
};

//***************************************************************
///    	Operating Ovellodin section
//****************************************************************

ostream &operator<<(ostream &out, const Player &player)
{
    out << "\nId: " << player.id;
    out << "\nName: " << player.name;
    out << "\nTeam ID: " << player.teamID;
    string checkAlrounder;
    if (player.isAlrounder == 0)
    {
        checkAlrounder = "False";
    }
    else
    {
        checkAlrounder = "True";
    }
    out << "\nAlrounder: " << checkAlrounder;

    string checkTopBatsman;
    if (player.isTopBatsman == 0)
    {
        checkTopBatsman = "False";
    }
    else
    {
        checkTopBatsman = "True";
    }
    out << "\nTop Batsman: " << checkTopBatsman;
    string checkTopBoller;
    if (player.isTopBoller == 0)
    {
        checkTopBoller = "False";
    }
    else
    {
        checkTopBoller = "True";
    }
    out << "\nTop Boller: " << checkTopBoller;

    return out;
}

istream &operator>>(istream &in, Player &player)
{

    cout << "\nNew Player Entry.....\n";
    cout << "\nEnter The Player ID: ";
    in >> player.id;
    cout << "\nName: ";
    in.ignore();
    in.getline(player.name, sizeof(player.name), '\n');
    cout << "\nTeam ID: ";
    in >> player.teamID;
    cout << "\nIs Alrounder? : ";
    in >> player.isAlrounder;
    cout << "\nIs Top Batsman? : ";
    in >> player.isTopBatsman;
    cout << "\nIs Top Boller? : ";
    in >> player.isTopBoller;
    cout << "\nBatting Average: ";
    in >> player.battingAvg;
    cout << "\nBolling Average: ";
    in >> player.bollingAVg;
    cout << "\n\nPlayer Created Successfully..";

    return in;
}

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
    out << "\nId: " << schedulling.schedulingID;
    out << "\nTeam A ID: " << schedulling.teamA;
    out << "\nTeam B ID: " << schedulling.teamB;
    out << "\nResult: " << schedulling.result;
    out << "\nIs Odi: " << schedulling.isODI;
    out << "\nIS Test: " << schedulling.isTEST;
    out << "\nIS T20: " << schedulling.isT20;

    return out;
}

istream &operator>>(istream &in, Schedulling &schedulling)
{

    cout << "\nNew Schedulling Entry.....\n";
    cout << "\nEnter The Schedulling ID: ";
    in >> schedulling.schedulingID;
    cout << "\nTeam A ID: ";
    in >> schedulling.teamA;
    cout << "\nTeam B ID: ";
    in >> schedulling.teamB;
    cout << "\nResult: ";
    in.ignore();
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

//***************************************************************
///    	global declaration for stream object, object
//****************************************************************
fstream fp, fp1;
class PointTable : public Player, public Team, public Schedulling
{
    Player player;
    Team team;
    Schedulling schedulling;

public:
    //***************************************************************
    ///    	function to write in file
    //****************************************************************
    void insertPlayer()
    {
        char ch;
        fp.open("player.dat", ios::out | ios::app);
        do
        {
            cin >> player;
            fp.write((char *)&player, sizeof(Player));
            cout << "\n\nDo you Want to add more record..(y/n?): ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
        fp.close();
    }

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
        } while (ch == 'y' || ch == 'Y');
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
        } while (ch == 'y' || ch == 'Y');
        fp.close();
    }

    //***************************************************************
    ///   	function to read specific record from file
    //****************************************************************

    void displaySpecificPlayer(char n[])
    {
        cout << "\nPlayer Details\n";
        int flag = 0;
        fp.open("player.dat", ios::in);
        while (fp.read((char *)&player, sizeof(Player)))
        {
            if (strcmpi(player.getPlayerID(), n) == 0)
            {
                cout << player;
                flag = 1;
            }
        }
        fp.close();
        if (flag == 0)
            cout << "\n\nPlayer does not exist.";
    }

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

    //***************************************************************
    ///    	function to modify record of file
    //****************************************************************

    void modifyPlayer()
    {
        char n[6];
        int found = 0;
        cout << "\n\nModify Player Recorded Section......";
        cout << "\n\nEnter the Player ID: ";
        cin >> n;
        fp.open("player.dat", ios::in | ios::out);
        while ((fp.read((char *)&player, sizeof(Player))) && found == 0)
        {
            if (strcmpi(player.getPlayerID(), n) == 0)
            {
                cout << player;
                cout << "\nEnter The New Details of Player\n";
                player.modifyPlayer();
                int pos = -1 * sizeof(player);
                fp.seekp(pos, ios::cur);
                fp.write((char *)&player, sizeof(Player));
                cout << "\n\n\t Record Updated...";
                found = 1;
            }
        }
        fp.close();
        if (found == 0)
            cout << "\n\n Record Not Found";
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

                if (isWinTeamA == 1)
                {
                    
                    modifyTeamAfterResult(schedulling.getTeamAID(), schedulling.getODIStatus(), schedulling.getTESTStatus(), schedulling.getT20Status(), true,0);
                    modifyTeamAfterResult(schedulling.getTeamBID(), 0, 0, 0, false,0);
                }
                else
                {
                    
                    modifyTeamAfterResult(schedulling.getTeamAID(), 0, 0, 0, false,0);
                    modifyTeamAfterResult(schedulling.getTeamBID(), schedulling.getODIStatus(), schedulling.getTESTStatus(), schedulling.getT20Status(), true,0);
                }


                schedulling.modifySchedullingResult();
                int pos = -1 * sizeof(Schedulling);
                fp1.seekp(pos, ios::cur);
                fp1.write((char *)&schedulling, sizeof(Schedulling));
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

    void deletePlayer()
    {
        char n[6];
        cout << "\n\n\n\tDelete Player.............";
        cout << "\n\nEnter the Player ID: ";
        cin >> n;
        fp.open("player.dat", ios::in | ios::out);
        fstream fp2;
        fp2.open("temp.dat", ios::out);
        fp.seekg(0, ios::beg);
        while (fp.read((char *)&player, sizeof(Player)))
        {
            if (strcmpi(player.getPlayerID(), n) != 0)
            {
                fp2.write((char *)&player, sizeof(Player));
            }
        }
        fp2.close();
        fp.close();
        remove("player.dat");
        rename("temp.dat", "player.dat");
        cout << "\n\n\tRecord Deleted ..";
    }

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

    //***************************************************************
    ///    	function to display all list
    //****************************************************************

    void displayAllPlayers()
    {
        fp.open("player.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! File Could not be OPEN";
            return;
        }
        cout << "\n\n\t\t Player List\n\n";
        cout << "=================================================================================================================================\n";
        cout << setw(6) << left << "ID"
             << " | " << setw(20) << left << "Name"
             << " | " << setw(7) << left << "TEAM ID"
             << " | " << setw(9) << left << "AlRounder"
             << " | " << setw(10) << left << "TopBatsman"
             << " | " << setw(9) << left << "TopBoller"
             << " | " << setw(11) << left << "Batting AVG"
             << " | " << setw(11) << left << "Bolling AVG"
             << " | " << endl;

        cout << "==================================================================================================================================\n";
        while (fp.read((char *)&player, sizeof(Player)))
        {
            player.report();
        }
        fp.close();
    }

    void displayAllTeam()
    {
        fp.open("team.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! File Could not be OPEN";
            return;
        }
        cout << "\n\n\t\t Team List\n\n";
        cout << "=================================================================================================================================\n";
        cout << setw(6) << left << "ID"
             << " | " << setw(20) << left << "Name"
             << " | " << setw(7) << left << "Win ODI"
             << " | " << setw(8) << left << "Lost ODI"
             << " | " << setw(8) << left << "Win TEST"
             << " | " << setw(9) << left << "Lost TEST"
             << " | " << setw(7) << left << "Win T20"
             << " | " << setw(8) << left << "Lost T20"
             << " | " << endl;

        cout << "==================================================================================================================================\n";

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
        cout << setw(6) << left << "ID"
             << " | " << setw(6) << left << "Team A"
             << " | " << setw(6) << left << "Team B"
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

//***************************************************************
///    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{

    cout << "\n\nProject : Sports Scheduling And Result OOP Project";
    cout << "\n\nMADE BY : MEHEDI HASAN SHUVO";
    cout << "\n\nUniversity : Dhaka University & Engineering Technology";
}

void adminMenuPlayer()
{

    int ch2;
    PointTable poinTable;

    cout << "\n\n\n\tPlayer MENU";
    cout << "\n\n\t1.CREATE PLAYER RECORD";
    cout << "\n\n\t2.DISPLAY ALL PLAYER RECORD";
    cout << "\n\n\t3.DISPLAY SPECIFIC PLAYER RECORD ";
    cout << "\n\n\t4.MODIFY PLAYER RECORD";
    cout << "\n\n\t5.DELETE PLAYER RECORD";
    cout << "\n\n\t6.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-6) ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        poinTable.insertPlayer();
        break;
    case 2:
        poinTable.displayAllPlayers();
        break;
    case 3:
        char num[6];
        cout << "\n\n\tPlease Enter The Player ID: ";
        cin >> num;
        poinTable.displaySpecificPlayer(num);
        break;
    case 4:
        poinTable.modifyPlayer();
        break;
    case 5:
        poinTable.deletePlayer();
        break;
    case 6:
        return;
    default:
        cout << "\a";
    }
    adminMenuPlayer();
}

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

//***************************************************************
///    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
    char ch;
    intro();
    do
    {

        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. PLAYER MENU";
        cout << "\n\n\t02. TEAM MENU";
        cout << "\n\n\t03. SCHEDULLINNG MENU";
        cout << "\n\n\t04. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-4) ";
        ch = getche();
        switch (ch)
        {
        case '1':
            adminMenuPlayer();
            break;
        case '2':
            adminMenuTeam();
            break;
        case '3':
            adminMenuSchedulling();
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
