#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
#include<ctime>
using namespace std;

class bank {
    private:
    int pin;
    float balance;
    string id, password, f_name, l_name, address, phone;

    public:
    void already_user();  
    void menu();
    void bank_management();
    void atm_management();
    void new_user();
    void deposit();
    void withdraw();
    void transfer();
    void payment();
    void search();
    void edit();
    void del();
    void show_records();
    void show_payment();
    void user_balance();
    void withdraw_atm();
    void check_detail();
};

void bank::menu() {
    while (true) {
        int c;
        cout << endl << endl << "\t\t\t";
        cout << endl << "1. Bank management";
        cout << endl << "2. ATM management";
        cout << endl << "3. Exit";
        cout << endl << endl << "Enter Your Choice: ";
        cin >> c;
        switch (c) {
            case 1:
                bank_management();
                break;
            case 2:
                atm_management();
                break;
            case 3:
                exit(0);
                break;
            default:
                cout << endl << endl << "Invalid Choice" << endl;
                break;
        }
        getch();
    }
}

void bank::bank_management() {
    while (true) {
        int c;
        cout << endl << endl << "\t\t\t";
        cout << endl << "\t\t\tBank Management";
        cout << endl << "1. New User ";
        cout << endl << "2. Existing User";
        cout << endl << "3. Deposit";
        cout << endl << "4. Withdraw";
        cout << endl << "5. Transfer";
        cout << endl << "6. Bill Payment";
        cout << endl << "7. Search User Record";
        cout << endl << "8. Edit User Record";
        cout << endl << "9. Delete User Record";
        cout << endl << "10. Show All Records";
        cout << endl << "11. All Payment Records";
        cout << endl << "12. Go To Menu";
        cout << endl << endl << "Enter Your Choice: ";
        cin >> c;
        switch (c) {
            case 1:
                new_user();
                break;
            case 2:
                already_user();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                transfer();
                break;
            case 6:
                payment();
                break;
            case 7:
                search();
                break;
            case 8:
                edit();
                break;
            case 9:
                del();
                break;
            case 10:
                show_records();
                break;
            case 11:
                show_payment();
                break;
            case 12:
                return; // exit the bank_management menu
            default:
                cout << endl << "Invalid Choice:: Please try again" << endl;
                break;
        }
        getch();
    }
}

void bank::atm_management() {
    while (true) {
        int c;
        cout << endl << endl << "\t\t\t";
        cout << endl << "\t\t\tATM Management";
        cout << endl << "1. User Login & Balance";
        cout << endl << "2. Withdraw";
        cout << endl << "3. Account Details";
        cout << endl << "4. Go To Menu";
        cout << endl << endl << "Enter Your Choice: ";
        cin >> c;
        switch (c) {
            case 1:
                user_balance();
                break;
            case 2:
                withdraw_atm();
                break;
            case 3:
                check_detail();
                break;
            case 4:
                return; // exit the atm_management menu
            default:
                cout << "Invalid Choice:: Please Try Again" << endl;
                break;
        }
        getch();
    }
}

void bank::new_user() {
    fstream file;
    int pi;
    float b;
    string fn, ln, pa, ph, i, a;
    cout << endl << endl << "\t\t\tAdd New User";
    cout << endl << "Enter User ID:";
    cin >> id;
    cout << endl << "Enter First Name :";
    cin >> f_name;
    cout << endl << "Enter Last Name :";
    cin >> l_name;
    cout << endl << "Enter Pin Code (5 digits) :";
    cin >> pin;
    cout << endl << "Enter Password (5 characters):";
    cin >> password;
    cout << endl << "Enter Phone Number :";
    cin >> phone;
    cout << endl << "Enter city :";
    cin >> address;
    cout << endl << "Enter balance :";
    cin >> balance;

    file.open("bank.txt", ios::in);
    if (!file) {
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << f_name << " " << l_name << " " << pin << " " << password << " " << phone << " " << address << " " << balance << endl;
        file.close();
    } else {
        file >> i >> fn >> ln >> pi >> pa >> ph >> a >> b;
        while (file) {
            if (i == id) {
                cout << endl << endl << "User ID already exists please try through another ID" << endl;
                getch();
                return;
            }
            file >> i >> fn >> ln >> pi >> pa >> ph >> a >> b;
        }
        file.close();
        file.open("bank.txt", ios::app | ios::out);
        file <<endl << id << " " << f_name << " " << l_name << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
        file.close();
    }
    cout << endl << "New user ID has been created" << endl;
}

void bank::already_user() {
    cout << endl << "\t\t\tExisting User Information";
    fstream file;
    int pi;
    float b;
    string fn, ln, pa, ph, i, a;
    string t_id;
    int found = 0;
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << endl << "File Opening Error" << endl;
    } else {
        cout << endl << "Enter User ID:";
        cin >> t_id;
        file >> i >> fn >> ln >> pi >> pa >> ph >> a >> b;

        while (file) {
            if (t_id == i) {
                cout << endl << endl << "User ID: " << i << endl << "Pin Code: " << pi << endl << "Password: " << pa;
                found++;
            }
            file >> i >> fn >> ln >> pi >> pa >> ph >> a >> b;
        }
        file.close();
        if (found == 0) {
            cout << endl << "No such User exists." << endl;
            cout << "To create an ID Please go to new User:" << endl;
        }
    }
}

void bank::deposit() {
    fstream file, file1;
    string t_id;
    int found = 0;
    float dep;
    cout << "\n \t\t\tDeposit Amount";
    file.open("bank.txt", ios::in);

    if (!file) {
        cout << endl << "File Opening Error" << endl;
    } else {
        cout << endl << "Enter User ID:";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);

        file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;

        while (file) {
            if (t_id == id) {
                cout << "\n Enter Amount to be deposited: ";
                cin >> dep;
                balance += dep;
                found++;
                cout << "\n Current updated balance: " << balance;
            }
            file1 << " " << id << " " << f_name << " " << l_name << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
            file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if (found == 0) {
            cout << endl << "No such User exists." << endl;
        }
    }
}

void bank::withdraw() {
    fstream file, file1;
    string t_id;
    int found = 0;
    float with;
    cout << "\n \t\t\tWithdraw Page";
    file.open("bank.txt", ios::in);

    if (!file) {
        cout << endl << "File Opening Error" << endl;
    } else {
        cout << endl << "Enter User ID:";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);

        file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;

        while (file) {
            if (t_id == id) {
                cout << "\n Enter Amount to be Withdraw: ";
                cin >> with;
                if (with > balance) {
                    cout << "\n Not Sufficient Balance in account:";
                    return;
                }
                balance -= with;
                found++;
                cout << "\n Current updated balance: " << balance;
            }
            file1 << endl << id << " " << f_name << " " << l_name << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
            file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if (found == 0) {
            cout << endl << "No such User exists." << endl;
        }
    }
}

void bank::transfer() {
    fstream file, file1;
    string t_id, id2;
    int found = 0;
    float amt;
    cout << "\n \t\t\tTransfer Amount";
    file.open("bank.txt", ios::in);

    if (!file) {
        cout << endl << "File Opening Error" << endl;
    } else {
        cout << endl << "Enter Sender User ID:";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);

        file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;

        while (file) {
            if (t_id == id) {
                cout << "\n Enter Amount to be Transferred: ";
                cin >> amt;
                if (amt > balance) {
                    cout << "\n Not Sufficient Balance in account:";
                    return;
                }
                balance -= amt;
                found++;
                cout << "\n Current updated balance: " << balance;
            }
            file1 << endl << id << " " << f_name << " " << l_name << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
            file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if (found == 0) {
            cout << endl << "No such User exists." << endl;
        }
    }

    // Receiver update
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::app | ios::out);
    found = 0;
    cout << endl << "Enter Receiver User ID:";
    cin >> id2;
    file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;

    while (file) {
        if (id2 == id) {
            balance += amt;
            found++;
            cout << "\n Current updated balance: " << balance;
        }
        file1 << endl << id << " " << f_name << " " << l_name << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
        file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");

    if (found == 0) {
        cout << endl << "No such User exists." << endl;
    }
}

void bank::payment() {
    fstream file, file1, bill;
    string t_id, name, month;
    int pay, found = 0;
    float amt;
    cout << "\n \t\t\tPayment Page";
    file.open("bank.txt", ios::in);

    if (!file) {
        cout << endl << "File Opening Error" << endl;
    } else {
        cout << endl << "Enter User ID:";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        bill.open("bill.txt", ios::app | ios::out);

        file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;

        while (file) {
            if (t_id == id) {
                cout << "\n Enter bill Name :";
                cin >> name;
                cout << "\n Enter the month:";
                cin >> month;
                cout << "\n Enter Amount to be Paid: ";
                cin >> amt;
                if (amt > balance) {
                    cout << "\n Not Sufficient Balance in account:";
                    return;
                }
                balance -= amt;
                found++;
                cout << "\n Current updated balance: " << balance;
                time_t now = time(0);
                tm *ltm = localtime(&now);
                bill << name << " " << month << " " << amt << " " << id << " " << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday << endl;
            }
            file1 << endl << id << " " << f_name << " " << l_name << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
            file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;
        }
        file.close();
        file1.close();
        bill.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if (found == 0) {
            cout << endl << "No such User exists." << endl;
        }
    }
}

void bank::search() {
    fstream file;
    string t_id;
    int found = 0;
    cout << "\n \t\t\tSearch Record";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << endl << "File Opening Error" << endl;
    } else {
        cout << endl << "Enter User ID:";
        cin >> t_id;
        file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;

        while (file) {
            if (t_id == id) {
                cout << endl << "User ID: " << id << "\nName: " << f_name << " " << l_name << "\nPin Code: " << pin << "\nPassword: " << password
                     << "\nPhone: " << phone << "\nCity: " << address << "\nBalance: " << balance << endl;
                found++;
            }
            file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;
        }
        file.close();

        if (found == 0) {
            cout << endl << "No such User exists." << endl;
        }
    }
}

void bank::edit() {
    fstream file, file1;
    string t_id, new_address, new_phone;
    int found = 0;
    cout << "\n \t\t\tEdit Record";
    file.open("bank.txt", ios::in);

    if (!file) {
        cout << endl << "File Opening Error" << endl;
    } else {
        cout << endl << "Enter User ID:";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);

        file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;

        while (file) {
            if (t_id == id) {
                cout << "\n Enter new Phone Number: ";
                cin >> new_phone;
                cout << "\n Enter new Address: ";
                cin >> new_address;
                phone = new_phone;
                address = new_address;
                found++;
                cout << "\n Current updated record: \nPhone: " << phone << "\nAddress: " << address;
            }
            file1 << " " << id << " " << f_name << " " << l_name << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
            file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if (found == 0) {
            cout << endl << "No such User exists." << endl;
        }
    }
}

void bank::del() {
    fstream file, file1;
    string t_id;
    int found = 0;
    cout << "\n \t\t\tDelete Record";
    file.open("bank.txt", ios::in);

    if (!file) {
        cout << endl << "File Opening Error" << endl;
    } else {
        cout << endl << "Enter User ID:";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);

        file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;

        while (file) {
            if (t_id != id) {
                file1 << endl << id << " " << f_name << " " << l_name << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
            } else {
                found++;
            }
            file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if (found == 0) {
            cout << endl << "No such User exists." << endl;
        } else {
            cout << endl << "User Deleted Successfully." << endl;
        }
    }
}

void bank::show_records() {
    fstream file;
    int found = 0;
    cout << "\n \t\t\tAll User Records";
    file.open("bank.txt", ios::in);

    if (!file) {
        cout << endl << "File Opening Error" << endl;
    } else {
        file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;

        while (file) {
            cout << "\nUser ID: " << id << "\nName: " << f_name << " " << l_name << "\nPin Code: " << pin << "\nPassword: " << password
                 << "\nPhone: " << phone << "\nCity: " << address << "\nBalance: " << balance << endl;
            file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;
            found++;
        }
        file.close();

        if (found == 0) {
            cout << endl << "No records found." << endl;
        }
    }
}

void bank::show_payment() {
    fstream bill;
    string bill_name, month, user_id, date;
    float amt;
    int found = 0;
    cout << "\n \t\t\tAll Payment Records";
    bill.open("bill.txt", ios::in);

    if (!bill) {
        cout << endl << "File Opening Error" << endl;
    } else {
        bill >> bill_name >> month >> amt >> user_id >> date;

        while (bill) {
            cout << "\nBill Name: " << bill_name << "\nMonth: " << month << "\nAmount: " << amt << "\nUser ID: " << user_id << "\nDate: " << date << endl;
            bill >> bill_name >> month >> amt >> user_id >> date;
            found++;
        }
        bill.close();

        if (found == 0) {
            cout << endl << "No records found." << endl;
        }
    }
}

void bank::user_balance() {
    fstream file;
    string t_id;
    int t_pin, found = 0;
    cout << "\n \t\t\tUser Login & Balance";
    file.open("bank.txt", ios::in);

    if (!file) {
        cout << endl << "File Opening Error" << endl;
    } else {
        cout << endl << "Enter User ID:";
        cin >> t_id;
        cout << endl << "Enter Pin Code (5 digits):";
        cin >> t_pin;
        file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;

        while (file) {
            if (t_id == id && t_pin == pin) {
                cout << "\n User ID: " << id << "\nName: " << f_name << " " << l_name << "\nBalance: " << balance << endl;
                found++;
            }
            file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;
        }
        file.close();

        if (found == 0) {
            cout << endl << "Invalid User ID or Pin." << endl;
        }
    }
}

void bank::withdraw_atm() {
    fstream file, file1;
    string t_id;
    int t_pin, found = 0;
    float with;
    cout << "\n \t\t\tWithdraw from ATM";
    file.open("bank.txt", ios::in);

    if (!file) {
        cout << endl << "File Opening Error" << endl;
    } else {
        cout << endl << "Enter User ID:";
        cin >> t_id;
        cout << endl << "Enter Pin Code (5 digits):";
        cin >> t_pin;
        file1.open("bank1.txt", ios::app | ios::out);

        file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;

        while (file) {
            if (t_id == id && t_pin == pin) {
                cout << "\n Enter Amount to be Withdraw: ";
                cin >> with;
                if (with > balance) {
                    cout << "\n Not Sufficient Balance in account:";
                    return;
                }
                balance -= with;
                found++;
                cout << "\n Current updated balance: " << balance;
            }
            file1 << endl << id << " " << f_name << " " << l_name << " " << pin << " " << password << " " << phone << " " << address << " " << balance;
            file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if (found == 0) {
            cout << endl << "Invalid User ID or Pin." << endl;
        }
    }
}

void bank::check_detail() {
    fstream file;
    string t_id;
    int t_pin, found = 0;
    cout << "\n \t\t\tAccount Details";
    file.open("bank.txt", ios::in);

    if (!file) {
        cout << endl << "File Opening Error" << endl;
    } else {
        cout << endl << "Enter User ID:";
        cin >> t_id;
        cout << endl << "Enter Pin Code (5 digits):";
        cin >> t_pin;
        file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;

        while (file) {
            if (t_id == id && t_pin == pin) {
                cout << "\n User ID: " << id << "\nName: " << f_name << " " << l_name << "\nPin Code: " << pin << "\nPassword: " << password
                     << "\nPhone: " << phone << "\nCity: " << address << "\nBalance: " << balance << endl;
                found++;
            }
            file >> id >> f_name >> l_name >> pin >> password >> phone >> address >> balance;
        }
        file.close();

        if (found == 0) {
            cout << endl << "Invalid User ID or Pin." << endl;
        }
    }
}

int main() {
    bank b;
    b.menu();
    return 0;
}
