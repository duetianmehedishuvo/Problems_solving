#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

/// **************************  Item class Start here ****************
class Item
{
public:
    char id[6];
    char title[20];
};

/// **************************  Item class ends here ****************
/// **************************  Budget class Start here ****************
class Budget : public Item
{
    int expenseMoney;
    int incomeMoney;
    friend std::ostream &operator<<(std::ostream &out, const Budget &budget);
    friend std::istream &operator>>(std::istream &in, Budget &budget);

public:
    int getExpenseMoney() { return expenseMoney; }
    int getIncomeMoney() { return incomeMoney; }
    // expense section
    void reportExpenseMoney()
    {
        cout << id << setw(10) << title << setw(20) << expenseMoney << endl;
    }

    // income sectiom

    friend void addIncomeMoney(Budget &budget);
    void reportIncomeMoney()
    {
        cout << id << setw(10) << title << setw(20) << incomeMoney << endl;
    }
};

/// **************************  Budget class ends here ****************
/// **************************  Reminder class Start here ****************

class Reminder : public Item
{
    char description[30];
    friend std::ostream &operator<<(std::ostream &out, const Reminder &reminder);
    friend std::istream &operator>>(std::istream &in, Reminder &reminder);

public:
    char *getReminderID() { return id; };

    void modifyReminder()
    {
        cout << "\nReminder ID: " << id;
        cout << "\nModify Title: ";
        cin.ignore();
        cin.getline(title, sizeof(title), '\n');
        cout << "\nModify Message: ";
        cin.getline(description, sizeof(description), '\n');
    }

    void reportReminder()
    {
        cout << id << setw(10) << title << setw(20) << description << endl;
    }
};

/// **************************  Reminder class ends here ****************

//***************************************************************
///                   Operator Overloading IN PROJECT
//****************************************************************

/// input section
istream &operator>>(istream &in, Budget &budget)
{
    cout << "\nAdd ExpenSe Money Entry.....\n";
    cout << "\nEnter the Expense ID: ";
    in >> budget.id;

    cout << "\nEnter Expense Title: ";
    in.ignore();
    in.getline(budget.title, 20, '\n');
    cout << "\nEnter Expense Money: ";
    
    in >> budget.expenseMoney;
    cout << "\n\nExpense Money Added Successfully.....";
    return in;
}

istream &operator>>(istream &in, Reminder &reminder)
{
    cout << "\nAdd Reminder Section Entry......\n";
    cout << "\nEnter Reminder ID: ";
    in >> reminder.id;
    cout << "\nEnter Reminder Title: ";
    in.ignore();
    in.getline(reminder.title, sizeof(reminder.title), '\n');
    cout << "\nMessage: ";
    
    in.getline(reminder.description, sizeof(reminder.description), '\n');
    cout << "\n\nReminder Added Successfully\n";
    return in;
}

void addIncomeMoney(Budget &budget)
{

    cout << "\nAdd Income Money Entry.....\n";
    cout << "\nEnter the Income ID: ";
    cin >> budget.id;

    cout << "\nEnter Income Title: ";
    cin.ignore();
    cin.getline(budget.title, 20, '\n');
    cout << "\nEnter Income Money: ";
    cin >> budget.incomeMoney;
    cout << "\n\nIncome Added Successfully.....";
}

// output section

ostream &operator<<(ostream &out, const Budget &budget)
{
    out << "\nBudget ID: " << budget.id;
    cout << "\nBudget Title: " << budget.title;
    out << "\nExpense Money: " << budget.expenseMoney;
    return out;
}

ostream &operator<<(ostream &out, const Reminder &reminder)
{
    out << "\nReminder ID: " << reminder.id;
    out << "\nTitle: " << reminder.title;
    out << "\nMessage: " << reminder.description;
    return out;
}

//***************************************************************
///    	global declaration for stream object, object
//****************************************************************
fstream fp, fp1;

//***************************************************************
///    	Control Function
//****************************************************************

class Controller : public Budget, public Reminder
{
    Budget budget;
    Reminder reminder;
    int haveMoney = 0;
    int expenseMoney = 0;
    int incomeMoney = 0;

public:
    // write expense money and income money
    void writeExpenseMoney()
    {
        char ch;
        fp.open("expense_money.dat", ios::out | ios::app);
        do
        {
            cin >> budget;
            fp.write((char *)&budget, sizeof(Budget));
            cout << "\n\nDo you Want to add more Record..(Y/n): ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
        fp.close();
    }

    void writeIncomeMoney()
    {
        char ch;
        fp.open("income_money.dat", ios::out | ios::app);
        do
        {
            addIncomeMoney(budget);
            fp.write((char *)&budget, sizeof(Budget));
            cout << "\n\nDo you Want to add more Record..(Y/n): ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
        fp.close();
    }

    // view all Income and Expesnse Money Section:

    void viewAllExpenseMoney()
    {
        fp.open("expense_money.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! FIle could not be open";
            return;
        }
        cout << "\n\n\t\t Expense Money List\n\n";
        cout << "=========================================================================\n";
        cout << "ID" << setw(10) << "Title" << setw(20) << "Money" << endl;
        cout << "=========================================================================\n";
        while (fp.read((char *)&budget, sizeof(Budget)))
        {
            budget.reportExpenseMoney();
        }
        fp.close();
    }

    void viewAllIncomeMoney()
    {
        fp.open("income_money.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! FIle could not be open";
            return;
        }
        cout << "\n\n\t\t Income Money List\n\n";
        cout << "=========================================================================\n";
        cout << "ID" << setw(10) << "Title" << setw(20) << "Money" << endl;
        cout << "=========================================================================\n";
        while (fp.read((char *)&budget, sizeof(Budget)))
        {
            budget.reportIncomeMoney();
        }
        fp.close();
    }

    // calculation Budget

    void calculationExpenseMoney()
    {
        fp.open("expense_money.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! FIle could not be open";
            return;
        }
        while (fp.read((char *)&budget, sizeof(Budget)))
        {
            expenseMoney += budget.getExpenseMoney();
        }
        fp.close();
    }

    void calculationIncomeMoney()
    {
        fp.open("income_money.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! FIle could not be open";
            return;
        }
        while (fp.read((char *)&budget, sizeof(Budget)))
        {

            incomeMoney += budget.getIncomeMoney();
        }
        fp.close();
    }

    int totalBudgetCalculation()
    {
        calculationExpenseMoney();
        calculationIncomeMoney();
        haveMoney = incomeMoney - expenseMoney;
        return haveMoney;
    }

    int getExpenseMoney() { return expenseMoney; }
    int getIncomeMoney() { return incomeMoney; }

    //***************************************************************
    ///    	Reminder Section
    //****************************************************************

    // add reminder section:
    void writeReminder()
    {
        char ch;
        fp.open("reminder.dat", ios::out | ios::app);
        do
        {
            cin >> reminder;
            fp.write((char *)&reminder, sizeof(Reminder));
            cout << "\n\nDo you Want to add more Record..(Y/n): ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
        fp.close();
    }

    // display Specific Reminder section
    void displaySpecificReminder(char n[])
    {
        cout << "\nReminder Details\n";
        int flag = 0;
        fp.open("reminder.dat", ios::in);
        while (fp.read((char *)&reminder, sizeof(Reminder)))
        {
            if (strcmpi(reminder.getReminderID(), n) == 0)
            {
                cout << reminder;
                flag = 1;
            }
        }
        fp.close();
        if (flag == 0)
            cout << "\n\nReminder does not exist.";
    }

    // modify Reminder Section
    void modifyReminder()
    {
        char n[6];
        int found = 0;
        cout << "\n\nModify Reminder Section..........";
        cout << "\n\nEnter the Reminder ID: ";
        cin >> n;
        fp.open("reminder.dat", ios::in | ios::out);
        while ((fp.read((char *)&reminder, sizeof(Reminder))) && found == 0)
        {
            if (strcmpi(reminder.getReminderID(), n) == 0)
            {
                cout << reminder;
                cout << "\nEnter The New Details Of Reminder\n";
                reminder.modifyReminder();
                int pos = -1 * sizeof(Reminder);
                fp.seekp(pos, ios::cur);
                fp.write((char *)&reminder, sizeof(Reminder));
                cout << "\n\n\t Record Updated...";
                found = 1;
            }
        }
        fp.close();
        if (found == 0)
            cout << "\n\n Record Not Found";
    }

    // delete reminder section
    void deleteReminder()
    {
        char n[6];
        int flag = 0;
        cout << "\n\n\n\t Delete Reminder Section: ................";
        cout << "\n\nEnter the reminder id of the reminder do you want to delete: ";
        cin >> n;
        fp.open("reminder.dat", ios::in | ios::out);
        fstream fp2;
        fp2.open("temp.dat", ios::out);
        fp.seekg(0, ios::beg);
        while (fp.read((char *)&reminder, sizeof(Reminder)))
        {
            if (strcmpi(reminder.getReminderID(), n) != 0)
            {
                fp2.write((char *)&reminder, sizeof(Reminder));
            }
            else
                flag = 1;
        }
        fp2.close();
        fp.close();
        remove("reminder.dat");
        rename("temp.dat", "reminder.dat");
        if (flag == 1)
            cout << "\n\n\tRecord Deleted ..";
        else
            cout << "\n\nRecord not found";
    }

    // view all reminder section
    void viewAllReminder()
    {
        fp.open("reminder.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! FIle could not be open";
            return;
        }
        cout << "\n\n\t\t Income Money List\n\n";
        cout << "=========================================================================\n";
        cout << "ID" << setw(10) << "Title" << setw(20) << "Money" << endl;
        cout << "=========================================================================\n";
        while (fp.read((char *)&reminder, sizeof(Reminder)))
        {
            reminder.reportReminder();
        }
        fp.close();
    }
};

//***************************************************************
///    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{

    cout << "\n\nProject : Personal Expenses App";
    cout << "\n\nMADE BY : MEHEDI HASAN SHUVO";
    cout << "\n\nUniversity : Dhaka University & Engineering Technology";
}

//***************************************************************
///    	Admin Contrll Function
//****************************************************************

void adminMenuBudget()
{
    int ch2;
    Controller controller;

    cout << "\n\n\t Budget MENU";
    cout << "\n\n\t 1.Add Expense Budget: ";
    cout << "\n\n\t 2.View All Expense: ";
    cout << "\n\n\t 3.Calculate Expense: ";
    cout << "\n\n\t 4.Add Income Budget: ";
    cout << "\n\n\t 5.View All Income: ";
    cout << "\n\n\t 6.Calculate Income: ";
    cout << "\n\n\t 7.Total Calculation: ";
    cout << "\n\n\t 8.BACK TO MAIN MENU";
    cout << "\n\n\t Please Enter Your Choice (1-8) ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        controller.writeExpenseMoney();
        break;
    case 2:
        controller.viewAllExpenseMoney();

        break;
    case 3:
        controller.calculationExpenseMoney();
        cout << "\nTotal Expense: " << controller.getExpenseMoney() << endl;
        break;
    case 4:
        controller.writeIncomeMoney();
        break;
    case 5:
        controller.viewAllIncomeMoney();
        break;
    case 6:
        controller.calculationIncomeMoney();
        cout << "\nTotal Income: " << controller.getIncomeMoney() << endl;
        break;
    case 7:

        cout << "\nTotal: " << controller.totalBudgetCalculation() << endl;
        break;
    case 8:
        return;
    default:
        cout << "\a";
    }
    adminMenuBudget();
}

void adminMenuReminder()
{

    int ch2;
    Controller controller;

    cout << "\n\n\t Reminder MENU";
    cout << "\n\n\t 1.ADD REMINDER: ";
    cout << "\n\n\t 2.DISPLAY ALL REMINDER: ";
    cout << "\n\n\t 3.DISPLAY SPECIFIC REMINDER RECORD ";
    cout << "\n\n\t 4.MODIFY REMINDER RECORD";
    cout << "\n\n\t 5.DELETE REMINDER RECORD";
    cout << "\n\n\t 6.BACK TO MAIN MENU";
    cout << "\n\n\t Please Enter Your Choice (1-6): ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        controller.writeReminder();
        break;
    case 2:
        controller.viewAllReminder();

        break;
    case 3:
        char id[6];

        cout << "\n\n\tPlease Enter The Reminder ID: ";
        cin >> id;
        controller.displaySpecificReminder(id);
        break;
    case 4:
        controller.modifyReminder();
        break;
    case 5:
        controller.deleteReminder();
        break;
    case 6:
        return;
    default:
        cout << "\a";
    }
    adminMenuReminder();
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
        cout << "\n\n\t01. Open Budget Section";
        cout << "\n\n\t02. Open Reminder Section";
        cout << "\n\n\t03. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        ch = getche();
        switch (ch)
        {
        case '1':
            adminMenuBudget();
            break;
        case '2':
            adminMenuReminder();
            break;
        case '3':
            exit(0);
        default:
            cout << "\a";
        }
    } while (ch != '3');
    return 0;
}

//***************************************************************
///    			END OF PROJECT
//***************************************************************
