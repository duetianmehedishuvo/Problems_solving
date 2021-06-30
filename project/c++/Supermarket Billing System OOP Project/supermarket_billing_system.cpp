#include <bits/stdc++.h>
#include <conio.h>

using namespace std;
//global variable declaration
fstream fp, fp1;

class Date
{
public:
    int mm, dd, yy;
};

class Item : public Date
{

public:
    char itemno[6];
    char name[25];
    float price;
    int quanity;
    int tax;
    int discount;

    friend std::ostream &operator<<(std::ostream &out, const Item &item);
    friend std::istream &operator>>(std::istream &in, Item &item);

    void modifyItem()
    {
        cout << "\nItem ID: " << itemno;
        cout << "\nName: ";
        cin.ignore();
        cin.getline(name, 25, '\n');
        cout << "\nManufacturing Date(dd-mm-yy): ";
        cin >> mm >> dd >> yy;
        cout << "\nPrice: ";
        cin >> price;
        cout << "\nQuantity: ";
        cin >> quanity;
        cout << "\nTax: ";
        cin >> tax;
        cout << "\nDiscound: ";
        cin >> discount;
    }

    void modifyItemForInvoice()
    {
        cout << "\nItem ID: " << itemno;
        cout << "\nQuantity: ";
        cin >> quanity;
    }

    void report()
    {
        cout << setw(7) << left << itemno
             << " | " << setw(25) << left << name
             << " | " << setw(2) << left << dd << setw(2) << left << "/" << mm << setw(16) << left << "/" << yy
             << " | " << setw(5) << left << price
             << " | " << setw(8) << left << quanity
             << " | " << setw(3) << left << tax
             << " | " << setw(8) << left << discount
             << " | " << endl;
    }
    char *getItemNo()
    {
        return itemno;
    }

    float getPrice()
    {
        return price;
    }
    int getQuantity() { return quanity; }
    int getDiscount() { return discount; }
};

ostream &operator<<(ostream &out, const Item &item)
{
    out << "=======================================================================================================================================================================\n";
    out << setw(7) << left << "Item No"
        << " | " << setw(25) << left << "Name"
        << " | " << setw(20) << left << "Manufacturing Date"
        << " | " << setw(5) << left << "Price"
        << " | " << setw(8) << left << "Quantity"
        << " | " << setw(3) << left << "Tax"
        << " | " << setw(8) << left << "Discount"
        << " | " << endl;
    out << "=======================================================================================================================================================================\n";
    out << setw(7) << left << item.itemno
        << " | " << setw(25) << left << item.name
        << " | " << setw(2) << left << item.dd << setw(2) << left << "/" << item.mm << setw(16) << left << "/" << item.yy
        << " | " << setw(5) << left << item.price
        << " | " << setw(8) << left << item.quanity
        << " | " << setw(3) << left << item.tax
        << " | " << setw(8) << left << item.discount
        << " | " << endl;

    return out;
}

istream &operator>>(istream &in, Item &item)
{

    cout << "\nNew Item Entry.....\n";
    cout << "\n\n\tItem No: ";
    in >> item.itemno;
    cout << "\nName of the item: ";
    in.ignore();
    in.getline(item.name, 50, '\n');
    cout << "\nManufacturing Date(dd-mm-yy): ";
    in >> item.mm >> item.dd >> item.yy;
    cout << "\nPrice: ";
    in >> item.price;
    cout << "\nQuantity: ";
    in >> item.quanity;
    cout << "\nTax: ";
    in >> item.tax;
    cout << "\nDiscound: ";
    in >> item.discount;
    cout << "\n\nItem Created Successfully..";

    return in;
}

class Adminestrator : public Item
{
    Item item;

public:
    void writeItem()
    {
        char ch;
        fp.open("item.dat", ios::out | ios::app);
        do
        {
            cin >> item;
            fp.write((char *)&item, sizeof(Item));
            cout << "\n\nDo you Want to add more record..(y/n?): ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
        fp.close();
    }

    void displaySpecificItem(char n[])
    {
        cout << "\nItem Details\n";
        int flag = 0;
        fp.open("item.dat", ios::in);
        while (fp.read((char *)&item, sizeof(Item)))
        {
            if (strcmpi(item.getItemNo(), n) == 0)
            {
                cout << item;
                flag = 1;
            }
        }
        fp.close();
        if (flag == 0)
            cout << "\n\nItem does not exist.";
    }

    void modifyItem()
    {
        char n[6];
        int found = 0;
        cout << "\n\nModify Item Recorded Section......";
        cout << "\n\nEnter the Item number: ";
        cin >> n;
        fp.open("item.dat", ios::in | ios::out);
        while ((fp.read((char *)&item, sizeof(Item))) && found == 0)
        {
            if (strcmpi(item.getItemNo(), n) == 0)
            {
                cout << item;
                cout << "\nEnter The New Details of Item\n";
                item.modifyItem();
                long long unsigned int pos = -1 * sizeof(Item);
                fp.seekp(pos, ios::cur);
                fp.write((char *)&item, sizeof(Item));
                cout << "\n\n\t Record Updated...";
                found = 1;
            }
        }
        fp.close();
        if (found == 0)
            cout << "\n\n Record Not Found";
    }

    void deleteItem()
    {
        char n[6];
        cout << "\n\n\n\tDelete Item.............";
        cout << "\n\nEnter the Item number: ";
        cin >> n;
        fp.open("item.dat", ios::in | ios::out);
        fstream fp2;
        fp2.open("temp.dat", ios::out);
        fp.seekg(0, ios::beg);
        while (fp.read((char *)&item, sizeof(Item)))
        {
            if (strcmpi(item.getItemNo(), n) != 0)
            {
                fp2.write((char *)&item, sizeof(Item));
            }
        }
        fp2.close();
        fp.close();
        remove("item.dat");
        rename("temp.dat", "item.dat");
        cout << "\n\n\tRecord Deleted ..";
    }

    void displayAllItems()
    {
        fp.open("item.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! File Could not be OPEN";
            return;
        }
        cout << "\n\n\t\t Item List\n\n";
        cout << "================================================================================================================\n";
        cout << setw(7) << left << "Item No"
             << " | " << setw(25) << left << "Name"
             << " | " << setw(20) << left << "Manufacturing Date"
             << " | " << setw(5) << left << "Price"
             << " | " << setw(8) << left << "Quantity"
             << " | " << setw(3) << left << "Tax"
             << " | " << setw(8) << left << "Discount"
             << " | " << endl;
        cout << "================================================================================================================\n";

        while (fp.read((char *)&item, sizeof(Item)))
        {
            item.report();
        }
        fp.close();
    }
};

class Customer : public Item
{
    Item item;
    int amount;
    int discount;
    int total;

public:
    void invoice()
    {
        char n[6];
        int found = 0;
        cout << "\n\nEnter the Item number: ";
        cin >> n;
        fp.open("item.dat", ios::in | ios::out);
        while ((fp.read((char *)&item, sizeof(Item))))
        {
            if (strcmpi(item.getItemNo(), n) == 0)
            {

                item.modifyItemForInvoice();
                long long unsigned int pos = -1 * sizeof(Item);
                fp.seekp(pos, ios::cur);
                fp.write((char *)&item, sizeof(Item));
            }
        }
        fp.close();

        fp1.open("item.dat", ios::in | ios::out);
        while ((fp1.read((char *)&item, sizeof(Item))) && found == 0)
        {
            if (strcmpi(item.getItemNo(), n) == 0)
            {
                amount = item.getPrice() * item.getQuantity();
                discount = amount - (amount / 100 * item.getDiscount());
                total += discount;

                cout << "\n\n********************************INVOICE************************\n";

                cout << setw(7) << left << "Item No"
                     << " | " << setw(25) << left << "Name"
                     << " | " << setw(20) << left << "Manufacturing Date"
                     << " | " << setw(5) << left << "Price"
                     << " | " << setw(8) << left << "Quantity"
                     << " | " << setw(8) << left << "Discount"
                     << " | " << setw(11) << left << "Total Price"
                     << " | " << endl;

                cout << setw(7) << left << item.itemno
                     << " | " << setw(25) << left << item.name
                     << " | " << setw(20) << left << item.dd << "/" << item.mm << "/" << item.yy
                     << " | " << setw(5) << left << item.price
                     << " | " << setw(8) << left << item.quanity
                     << " | " << setw(8) << left << item.discount
                     << " | " << setw(11) << left << total
                     << " | " << endl;
                found = 1;
            }
        }
        fp1.close();

        if (found == 0)
            cout << "\n\n Record Not Found";
    }
};

///    	INTRODUCTION FUNCTION

void intro()
{
    cout << "\n\n\t\tProject : SUPERMARKET BILLING SYSTEM";
    cout << "\n\n\t\tMADE BY : ABDUALLAH AL MAMUN";
    cout << "\n\t\tID : 194011";
    cout << "\n\t\tUniversity : Dhaka University of Engineering & Technology";
}

void admin_menu()
{

    int ch2;
    Adminestrator adminestrator;

    cout << "\n\n\n\tADMINISTRATOR MENU";
    cout << "\n\n\t1.CREATE ITEM RECORD";
    cout << "\n\n\t2.DISPLAY ALL ITEM RECORD";
    cout << "\n\n\t3.DISPLAY SPECIFIC ITEM RECORD ";
    cout << "\n\n\t4.MODIFY ITEM RECORD";
    cout << "\n\n\t5.DELETE ITEM RECORD";
    cout << "\n\n\t6.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-6): ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        adminestrator.writeItem();
        break;
    case 2:
        adminestrator.displayAllItems();

        break;
    case 3:
        char num[6];
        cout << "\n\n\tPlease Enter The Item No: ";
        cin >> num;
        adminestrator.displaySpecificItem(num);
        break;
    case 4:
        adminestrator.modifyItem();
        break;
    case 5:
        adminestrator.deleteItem();
        break;
    case 6:
        return;
    default:
        cout << "\a";
    }
    admin_menu();
}

void customer_menu()
{

    int ch2;
    Customer customer;

    cout << "\n\n\n\tCUSTOMER MENU";
    cout << "\n\n\t1.Sale Product";
    cout << "\n\n\t2.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-2): ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        customer.invoice();
        break;
    case 2:
        return;
    default:
        cout << "\a";
    }
    customer_menu();
}

///    	THE MAIN FUNCTION OF PROGRAM

int main()
{
    char ch;
    Adminestrator adminestrator;
    intro();
    do
    {

        cout << "\n\n\n\tControl Panel";
        cout << "\n\n\t01. ADMIN";
        cout << "\n\n\t02. Customer";
        cout << "\n\n\t03. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-3): ";
        ch = getche();
        switch (ch)
        {
        case '1':
            admin_menu();
            break;
        case '2':
            customer_menu();
            break;
        case '3':
            exit(0);
        default:
            cout << "\a";
        }
    } while (ch != '3');
    return 0;
}

///    			END OF PROJECT
