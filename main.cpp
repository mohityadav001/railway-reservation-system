#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <unistd.h>
using namespace std;
int n = 40;
int k = 5, u = 0;
class train
{
    int train_no, price;
    int seat = 50 + rand() % 51;
    char d_time[10], a_time[10];
    char train_name[20];
    char start_pl[20];
    char dest_pl[20];

public:
    int num;
    friend class admin;
    friend class passenger;
    void search_by_number();
    void search_by_name();
};

class passenger : public train
{
    string name, phone;
    int sitno, trainno;
    int age;

public:
    void getdata();
    void bookticket();
    void cancelticket();
    void modify();
    friend class admin;
    friend class train;
};

class admin
{
    int train_no;
    string pass;
    int seat;

public:
    void password();
    void startpg();
    train *addtrain();
    void viewpsg();
    void outdata();
    friend class train;
    friend class passenger;
};

admin a;
train t[10];
passenger p[20];
passenger psg;

void admin::password()
{
    system("cls");
    string passw;
    pass = "OOPS";
    cout << "____________________________________________________________________" << endl;
    cout << "Login to Admin mode";
    cout << "\nEnter Password:";
    cin >> passw;
    if (passw == pass)
    {
        cout << "-----Login Successful !-----" << endl;
        cout << "\n____________________________________________________________________" << endl;
        startpg();
    }
    else
    {
        cout << "-----Incorrect Password !-----" << endl;
        cout << "----------Try Again!!---------" << endl;
        getch();
        password();
    }
}

void admin::startpg()
{
    admin a1;
    system("cls");
    int ch;
    char ch1;
    cout << "\n                  Welcome to the Admin mode                       " << endl;
    cout << "____________________________________________________________________" << endl;
    do
    {
        cout << "\nEnter your choice:" << endl;
        cout << " 1. Add Train\n 2. View Trains\n 3. View Passengers\n 4. Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            addtrain();
            break;
        case 2:
            outdata();
            break;
        case 3:
            viewpsg();
            break;
        case 4:
            exit(0);
        default:
            cout << "Error!!" << endl;
        }
        cout << "\nDo you want to continue? (type 'y' to continue)";
        cin >> ch1;
    } while (ch1 == 'y' || ch1 == 'Y');
}

train *admin ::addtrain()
{
    int i, no;
    char ch1;
    cout << "Scheduled Trains are:" << endl;
    a.outdata();
    cout << "\nDo you want to add more trains ?(Y/N)";
    cin >> ch1;
    if (ch1 == 'Y' || ch1 == 'y')
    {
        cout << "\nHow many trains you want to add ?";
        cin >> no;
        for (i = n; i < n + no; i++)
        {
            cout << "\nEnter Data for Train " << endl;
            cout << "\nEnter Train number:";
            cin >> t[i].train_no;
            cout << "\nEnter Train name:";
            gets(t[i].train_name);
            gets(t[i].train_name);
            cout << "\nEnter Boarding Place:";
            gets(t[i].start_pl);
            cout << "\nEnter Destination Place:";
            gets(t[i].dest_pl);
            cout << "\nEnter Fare:";
            cin >> t[i].price;
            cout << "\nEnter the total number of seats:";
            cin >> t[i].seat;
            cout << "\nEnter the arrival time:";
            gets(t[i].a_time);
            gets(t[i].a_time);
            cout << "\nEnter the departure time:";
            gets(t[i].d_time);
        }
        n = n + no;
        k = k + no;
    }
    return t;
}

void admin::outdata()
{
    t[0].train_no = 1;
    strcpy(t[0].train_name, "Deccan_Exp");
    strcpy(t[0].start_pl, "Mumbai");
    strcpy(t[0].dest_pl, "Pune");
    t[0].price = 250;
    t[0].seat = 800;
    strcpy(t[0].a_time, "7:30 PM");
    strcpy(t[0].d_time, "12:30 PM");

    t[1].train_no = 2;
    strcpy(t[1].train_name, "FlyingBullet");
    strcpy(t[1].start_pl, "CST");
    strcpy(t[1].dest_pl, "Surat");
    t[1].price = 1200;
    t[1].seat = 2000;
    strcpy(t[1].a_time, "11:30 PM");
    strcpy(t[1].d_time, "23:45 PM");

    t[2].train_no = 3;
    strcpy(t[2].train_name, "Rajdhani_express");
    strcpy(t[2].start_pl, "DELHI");
    strcpy(t[2].dest_pl, "MUMBAI");
    t[2].price = 1250;
    t[2].seat = 1800;
    strcpy(t[2].a_time, "9:30 AM");
    strcpy(t[2].d_time, "12:30 PM");

    t[3].train_no = 4;
    strcpy(t[3].train_name, "CITY_EXPRESS");
    strcpy(t[3].start_pl, "ALWAR");
    strcpy(t[3].dest_pl, "DELHI");
    t[3].price = 200;
    t[3].seat = 1500;
    strcpy(t[3].a_time, "5:30 AM");
    strcpy(t[3].d_time, "9:45 AM");

    t[4].train_no = 5;
    strcpy(t[4].train_name, "Duronto Express");
    strcpy(t[4].start_pl, "KOLKATA");
    strcpy(t[4].dest_pl, "CHENNAI");
    t[4].price = 1550;
    t[4].seat = 1900;
    strcpy(t[4].a_time, "5:30 AM,");
    strcpy(t[4].d_time, "11:30 PM");

    t[5].train_no = 6;
    strcpy(t[5].train_name, "Shatabdi Express");
    strcpy(t[5].start_pl, "JAIPUR");
    strcpy(t[5].dest_pl, "BHOPAL");
    t[5].price = 1800;
    t[5].seat = 2000;
    strcpy(t[5].a_time, "11:30 AM");
    strcpy(t[5].d_time, "9:45 PM");

    t[6].train_no = 7;
    strcpy(t[6].train_name, "Jan Shatabdi Express");
    strcpy(t[6].start_pl, "MUMBAI");
    strcpy(t[6].dest_pl, "PATNA");
    t[6].price = 1900;
    t[6].seat = 2200;
    strcpy(t[6].a_time, "7:30 AM");
    strcpy(t[6].d_time, "12:30 PM");

    t[7].train_no = 8;
    strcpy(t[7].train_name, "Flying_Jet");
    strcpy(t[7].start_pl, "PATNA");
    strcpy(t[7].dest_pl, "SURAT");
    t[7].price = 1200;
    t[7].seat = 2000;
    strcpy(t[7].a_time, "1:30 PM");
    strcpy(t[7].d_time, "3:45 AM");

    t[8].train_no = 9;
    strcpy(t[8].train_name, "Garib Rath Express");
    strcpy(t[8].start_pl, "DELHI");
    strcpy(t[8].dest_pl, "PATNA");
    t[8].price = 1110;
    t[8].seat = 1100;
    strcpy(t[8].a_time, "4:30 AM");
    strcpy(t[8].d_time, "9:30 PM");

    t[9].train_no = 10;
    strcpy(t[9].train_name, "Humsafar Express");
    strcpy(t[9].start_pl, "CST");
    strcpy(t[9].dest_pl, "BANGALORE");
    t[9].price = 1200;
    t[9].seat = 2000;
    strcpy(t[9].a_time, "12:39 AM");
    strcpy(t[9].d_time, "3:41 PM");

    t[10].train_no = 11;
    strcpy(t[10].train_name, "South_Exp");
    strcpy(t[10].start_pl, "Mumbai");
    strcpy(t[10].dest_pl, "Pune");
    t[10].price = 250;
    t[10].seat = 800;
    strcpy(t[10].a_time, "7:30 PM");
    strcpy(t[10].d_time, "12:30 PM");

    t[11].train_no = 12;
    strcpy(t[11].train_name, "Bullet5");
    strcpy(t[11].start_pl, "CST");
    strcpy(t[11].dest_pl, "Surat");
    t[11].price = 1200;
    t[11].seat = 2000;
    strcpy(t[11].a_time, "11:30 PM");
    strcpy(t[11].d_time, "23:45 PM");

    t[12].train_no = 13;
    strcpy(t[12].train_name, "dhani_express");
    strcpy(t[12].start_pl, "DELHI");
    strcpy(t[12].dest_pl, "MUMBAI");
    t[12].price = 1250;
    t[12].seat = 1800;
    strcpy(t[12].a_time, "9:30 AM");
    strcpy(t[12].d_time, "12:30 PM");

    t[13].train_no = 14;
    strcpy(t[13].train_name, "TOWN_EXPRESS");
    strcpy(t[13].start_pl, "ALWAR");
    strcpy(t[13].dest_pl, "DELHI");
    t[13].price = 200;
    t[13].seat = 1500;
    strcpy(t[13].a_time, "5:30 AM");
    strcpy(t[13].d_time, "9:45 AM");

    t[14].train_no = 15;
    strcpy(t[14].train_name, "Rat Express");
    strcpy(t[14].start_pl, "KOLKATA");
    strcpy(t[14].dest_pl, "CHENNAI");
    t[14].price = 1550;
    t[14].seat = 1900;
    strcpy(t[14].a_time, "5:30 AM,");
    strcpy(t[14].d_time, "11:30 PM");

    t[15].train_no = 16;
    strcpy(t[15].train_name, "Link Express");
    strcpy(t[15].start_pl, "JAIPUR");
    strcpy(t[15].dest_pl, "BHOPAL");
    t[15].price = 1800;
    t[15].seat = 2000;
    strcpy(t[15].a_time, "11:30 AM");
    strcpy(t[15].d_time, "9:45 PM");

    t[16].train_no = 17;
    strcpy(t[16].train_name, "Jan  Express");
    strcpy(t[16].start_pl, "MUMBAI");
    strcpy(t[16].dest_pl, "PATNA");
    t[16].price = 1900;
    t[16].seat = 2200;
    strcpy(t[16].a_time, "7:30 AM");
    strcpy(t[16].d_time, "12:30 PM");

    t[17].train_no = 18;
    strcpy(t[17].train_name, "CERIN EXP");
    strcpy(t[17].start_pl, "PATNA");
    strcpy(t[17].dest_pl, "SURAT");
    t[17].price = 1200;
    t[17].seat = 2000;
    strcpy(t[17].a_time, "1:30 PM");
    strcpy(t[17].d_time, "3:45 AM");

    t[18].train_no = 19;
    strcpy(t[18].train_name, "Rath Express");
    strcpy(t[18].start_pl, "DELHI");
    strcpy(t[18].dest_pl, "PATNA");
    t[18].price = 1110;
    t[18].seat = 1100;
    strcpy(t[18].a_time, "4:30 AM");
    strcpy(t[18].d_time, "9:30 PM");

    t[19].train_no = 20;
    strcpy(t[19].train_name, "safar Express");
    strcpy(t[19].start_pl, "CST");
    strcpy(t[19].dest_pl, "BANGALORE");
    t[19].price = 1200;
    t[19].seat = 2000;
    strcpy(t[19].a_time, "12:39 AM");
    strcpy(t[19].d_time, "3:41 PM");

    t[20].train_no = 21;
    strcpy(t[20].train_name, "North_Exp");
    strcpy(t[20].start_pl, "Mumbai");
    strcpy(t[20].dest_pl, "Pune");
    t[20].price = 250;
    t[20].seat = 800;
    strcpy(t[20].a_time, "7:30 PM");
    strcpy(t[20].d_time, "12:30 PM");

    t[21].train_no = 22;
    strcpy(t[21].train_name, "Karim_Express");
    strcpy(t[21].start_pl, "CST");
    strcpy(t[21].dest_pl, "Surat");
    t[21].price = 1200;
    t[21].seat = 2000;
    strcpy(t[21].a_time, "11:30 PM");
    strcpy(t[21].d_time, "23:45 PM");

    t[22].train_no = 23;
    strcpy(t[22].train_name, "Rajarani_express");
    strcpy(t[22].start_pl, "DELHI");
    strcpy(t[22].dest_pl, "MUMBAI");
    t[22].price = 1250;
    t[22].seat = 1800;
    strcpy(t[22].a_time, "9:30 AM");
    strcpy(t[22].d_time, "12:30 PM");

    t[23].train_no = 24;
    strcpy(t[23].train_name, "TreeEXPRESS");
    strcpy(t[23].start_pl, "ALWAR");
    strcpy(t[23].dest_pl, "DELHI");
    t[23].price = 200;
    t[23].seat = 1500;
    strcpy(t[23].a_time, "5:30 AM");
    strcpy(t[23].d_time, "9:45 AM");

    t[24].train_no = 25;
    strcpy(t[24].train_name, "Daman Express");
    strcpy(t[24].start_pl, "KOLKATA");
    strcpy(t[24].dest_pl, "CHENNAI");
    t[24].price = 1550;
    t[24].seat = 1900;
    strcpy(t[24].a_time, "5:30 AM,");
    strcpy(t[24].d_time, "11:30 PM");

    t[25].train_no = 26;
    strcpy(t[25].train_name, "Shatabdi Express");
    strcpy(t[25].start_pl, "JAIPUR");
    strcpy(t[25].dest_pl, "BHOPAL");
    t[25].price = 1800;
    t[25].seat = 2000;
    strcpy(t[25].a_time, "11:30 AM");
    strcpy(t[25].d_time, "9:45 PM");

    t[26].train_no = 27;
    strcpy(t[26].train_name, "Jan Shatabdi Express");
    strcpy(t[26].start_pl, "MUMBAI");
    strcpy(t[26].dest_pl, "PATNA");
    t[26].price = 1900;
    t[26].seat = 2200;
    strcpy(t[26].a_time, "7:30 AM");
    strcpy(t[26].d_time, "12:30 PM");

    t[27].train_no = 28;
    strcpy(t[27].train_name, "Flying_Jet");
    strcpy(t[27].start_pl, "PATNA");
    strcpy(t[27].dest_pl, "SURAT");
    t[27].price = 1200;
    t[27].seat = 2000;
    strcpy(t[27].a_time, "1:30 PM");
    strcpy(t[27].d_time, "3:45 AM");

    t[28].train_no = 29;
    strcpy(t[28].train_name, "Garib Rath Express");
    strcpy(t[28].start_pl, "DELHI");
    strcpy(t[28].dest_pl, "PATNA");
    t[28].price = 1110;
    t[28].seat = 1100;
    strcpy(t[28].a_time, "4:30 AM");
    strcpy(t[28].d_time, "9:30 PM");

    t[29].train_no = 30;
    strcpy(t[29].train_name, "Humsafar Express");
    strcpy(t[29].start_pl, "CST");
    strcpy(t[29].dest_pl, "BANGALORE");
    t[29].price = 1200;
    t[29].seat = 2000;
    strcpy(t[29].a_time, "12:39 AM");
    strcpy(t[29].d_time, "3:41 PM");

    t[30].train_no = 31;
    strcpy(t[30].train_name, "Deccan_Exp");
    strcpy(t[30].start_pl, "Mumbai");
    strcpy(t[30].dest_pl, "Pune");
    t[30].price = 250;
    t[30].seat = 800;
    strcpy(t[30].a_time, "7:30 PM");
    strcpy(t[30].d_time, "12:30 PM");

    t[31].train_no = 32;
    strcpy(t[31].train_name, "FlyingBullet");
    strcpy(t[31].start_pl, "CST");
    strcpy(t[31].dest_pl, "Surat");
    t[31].price = 1200;
    t[31].seat = 2000;
    strcpy(t[31].a_time, "11:30 PM");
    strcpy(t[31].d_time, "23:45 PM");

    t[32].train_no = 33;
    strcpy(t[32].train_name, "Rajdhani_express");
    strcpy(t[32].start_pl, "DELHI");
    strcpy(t[32].dest_pl, "MUMBAI");
    t[32].price = 1250;
    t[32].seat = 1800;
    strcpy(t[32].a_time, "9:30 AM");
    strcpy(t[32].d_time, "12:30 PM");

    t[33].train_no = 34;
    strcpy(t[33].train_name, "CITY_EXPRESS");
    strcpy(t[33].start_pl, "ALWAR");
    strcpy(t[33].dest_pl, "DELHI");
    t[33].price = 200;
    t[33].seat = 1500;
    strcpy(t[33].a_time, "5:30 AM");
    strcpy(t[33].d_time, "9:45 AM");

    t[34].train_no = 35;
    strcpy(t[34].train_name, "Duronto Express");
    strcpy(t[34].start_pl, "KOLKATA");
    strcpy(t[34].dest_pl, "CHENNAI");
    t[34].price = 1550;
    t[34].seat = 1900;
    strcpy(t[34].a_time, "5:30 AM,");
    strcpy(t[34].d_time, "11:30 PM");

    t[35].train_no = 36;
    strcpy(t[35].train_name, "Shatabdi Express");
    strcpy(t[35].start_pl, "JAIPUR");
    strcpy(t[35].dest_pl, "BHOPAL");
    t[35].price = 1800;
    t[35].seat = 2000;
    strcpy(t[35].a_time, "11:30 AM");
    strcpy(t[35].d_time, "9:45 PM");

    t[36].train_no = 37;
    strcpy(t[36].train_name, "Jan Shatabdi Express");
    strcpy(t[36].start_pl, "MUMBAI");
    strcpy(t[36].dest_pl, "PATNA");
    t[36].price = 1900;
    t[36].seat = 2200;
    strcpy(t[36].a_time, "7:30 AM");
    strcpy(t[36].d_time, "12:30 PM");

    t[37].train_no = 38;
    strcpy(t[37].train_name, "Flying_Jet");
    strcpy(t[37].start_pl, "PATNA");
    strcpy(t[37].dest_pl, "SURAT");
    t[37].price = 1200;
    t[37].seat = 2000;
    strcpy(t[37].a_time, "1:30 PM");
    strcpy(t[37].d_time, "3:45 AM");

    t[38].train_no = 39;
    strcpy(t[38].train_name, "Garib Rath Express");
    strcpy(t[38].start_pl, "DELHI");
    strcpy(t[38].dest_pl, "PATNA");
    t[38].price = 1110;
    t[38].seat = 1100;
    strcpy(t[38].a_time, "4:30 AM");
    strcpy(t[38].d_time, "9:30 PM");

    t[39].train_no = 40;
    strcpy(t[39].train_name, "Humsafar Express");
    strcpy(t[39].start_pl, "CST");
    strcpy(t[39].dest_pl, "BANGALORE");
    t[39].price = 1200;
    t[39].seat = 2000;
    strcpy(t[39].a_time, "12:39 AM");
    strcpy(t[39].d_time, "3:41 PM");
    cout << "\n---------------------------Train Schedule-------------------------------" << endl;
    cout << setw(5) << "TNo" << setw(30) << "Name" << setw(20) << "Boarding" << setw(20) << "Destination" << setw(10) << "Fare" << setw(10) << "Seats" << setw(10) << "ATime" << setw(10) << "Dtime";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << t[i].train_no << setw(30) << t[i].train_name << setw(20) << t[i].start_pl << setw(20) << t[i].dest_pl << setw(10) << t[i].price << setw(10) << t[i].seat << setw(10) << t[i].a_time << setw(10) << t[i].d_time << endl;
    }
}

void train::search_by_number()
{
    int ts;
    cout << "Enter the train number you want to search: ";
    cin >> ts;
    for (int i = 0; i + 1 < n; i++)
    {
        if (t[i].train_no == ts)
        {
            cout << "Train Found" << endl;
            cout << "Name =" << t[i].train_name << ", Boarding =" << t[i].start_pl << ", Destination =" << t[i].dest_pl << endl;
        }
    }
}

void train ::search_by_name()
{
    char sn[50];
    cout << "Enter the train name you want to search: ";
    gets(sn);
    gets(sn);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(t[i].train_name, sn) == 0)
        {
            cout << "Train Found" << endl;
            cout << "Name =" << t[i].train_name << ", Boarding =" << t[i].start_pl << ", Destination =" << t[i].dest_pl << endl;
        }
    }
}

int main()
{
    srand((unsigned)getpid());
    // clrscr();
    int ch;
    cout << "************************************************************" << endl;
    cout << "=============== RAILWAY  RESERVATION  SYSTEM ===============" << endl;
    cout << "************************************************************" << endl;
    train t[10];
    do
    {
        cout << "\t MAIN  MENU:" << endl;
        cout << "\t 1.Admin mode \n\t 2.User mode \n\t 3.Exit" << endl;
        cout
            << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            a.password();
            break;
        case 2:
            psg.getdata();
            break;
        case 3:
            exit(0);

        default:
            cout << "Please enter right choice!!" << endl;
        }
    } while (ch != 4);
    return (0);
}

void passenger::getdata()
{
    int ch;
    char ch1;
    do
    {
        system("cls");
        cout << "<=============== USER MENU ===============>\n"
             << endl;
        cout << "\t(1)Book Ticket \n\t(2)Modify Details \n\t(3)Cancel Ticket\n\t(4)View Train\n\t(5)Search by name\n\t(6)Search by number\n\t(7)Back to Main Menu\n\t(8)Exit \n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            bookticket();
            break;
        case 2:

            modify();
            break;
        case 3:

            cancelticket();
            break;
        case 4:
            a.outdata();

            break;
        case 5:
            t->search_by_name();

            break;
        case 6:
            t->search_by_number();

            break;
        case 7:
            system("cls");
            main();
            break;
        case 8:
            exit(0);
        default:
            cout << "\nPlease enter right choice: ";
        }
        cout << "\nDo you want to continue? ";
        cin >> ch1;
    } while (ch1 == 'y' || ch1 == 'Y');
}

void passenger::modify()
{
    string new_name, tak;
    int new_age, location = -1;
    cout << "What do you want to change:";
    cout << "\n1. Name\n2. Age" << endl;
    int take;
    cin >> take;
    switch (take)
    {
    case 1:
        cout << "Phone number: ";
        cin >> tak;
        cout << "Enter new name:";
        cin >> new_name;
        for (int i = 0; i < num; i++)
        {
            if (p[i].phone == tak)
            {
                p[i].name = new_name;
            }
        }
        break;
    case 2:
        cout << "Phone number: ";
        cin >> tak;
        cout << "Enter new age:";
        cin >> new_age;
        for (int i = 0; i < num; i++)
        {
            if (p[i].phone == tak)
            {
                // location = i;
                p[i].age = new_age;
            }
        }
        break;
    }
}

void passenger::bookticket()
{
    int seatno;
    char c, found = -1;
    char v;

    int train_num;
    system("cls");
    cout << "============================================\n";
    cout << "\n How many tickets do you want to book:";
    cin >> num;
    // n = num;
    for (int j = 0; j < num; j++)
    {
        cout << "\nEnter train number: ";
        cin >> train_num;

        if (t[j].seat == 0)
        {
            cout << "\n Not available seat";
            getch();
            system("cls");
            main();
        }
        else
        {
            p[j].trainno = train_num;
            seatno = t[j].seat;

            cout << "\nEnter your name:";
            // gets(p[j].name);
            cin >> p[j].name;
            cout << "Enter your Age(in years): ";
            cin >> p[j].age;
            cout << "Enter your phone number:";
            cin >> p[j].phone;
            cout << "Ticket Booked successfully !!";
            cout << "\nDo the payments and collect your ticket.";
            cout << " \nYour Seat number is: " << seatno;
            cout << "\n(: WE WISH YOU A HAPPY JOURNEY :)" << endl;
            p[j].sitno = seatno;
            t[j].seat--;
            seatno--;
            u++;
            found = 1;
        }

        if (found == -1)
        {
            cout << "\nTrain not found!!";
            getch();
            system("cls");
            main();
        }
    }
    cout << "\n Enter '1' for main menu & press any key to exit:";
    cin >> c;
    if (c == '1')
    {
        system("cls");
        main();
    }
    else
        exit(0);
}

void passenger::cancelticket()
{
    char NM[15];
    int location = -1;
    int ch;
    cout << "\n Enter Phone number:";
    cin >> NM;
    for (int i = 0; i < u; i++)
    {
        if (p[i].phone == NM)
        {
            location = i;
            cout << "Your details are: " << endl;
            cout << "Name: " << p[i].name << "\nAge: " << p[i].age << "\nPhone Number: " << p[i].phone << "\nTrain no.: " << p[i].trainno << "\nSeat no.: " << p[i].sitno << endl;
            cout << "Do you want to continue?(press 1 to continue): ";
            cin >> ch;
            if (ch == 1)
                break;
            else
                main();
        }
    }
    if (location == -1)
    {
        cout << "\n Record not found!!";
        getch();
        system("cls");
        main();
    }
    else
    {
        for (int i = location; i < u; i++)
        {
            p[i].name = p[i + 1].name;
            p[i].age = p[i + 1].age;
            p[i].sitno = p[i + 1].sitno;
            p[i].trainno = p[i + 1].trainno;
        }
        u--;
        cout << "\nTicket  cancelled  successfully!!";
        getch();
        system("cls");
        main();
    }
}

void admin::viewpsg()
{
    int a, j;
    system("cls");
    cout << "=============== Passenger Details ===============\n"
         << endl;
    cout << setw(10) << "Train no." << setw(15) << "Name" << setw(7) << "Age" << setw(10) << "seat no" << endl;
    for (j = 0; j < u; j++)
    {
        cout << setw(10) << p[j].trainno << setw(15) << p[j].name << setw(7) << p[j].age << setw(10) << p[j].sitno << endl;
        seat++;
    }
    cout << "\n enter'1'for main menu & enter'0' for back:";
    cin >> a;
    if (a == 1)
    {
        system("cls");
        main();
    }
    if (a == 0)
    {
        system("cls");
        startpg();
    }
}