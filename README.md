# Bank and ATM Management System

## Introduction

This project is a command-line application simulating a bank and ATM management system. It allows users to manage bank accounts, perform transactions, and handle ATM operations. The application uses file handling for data storage and retrieval.

## Features

### Bank Management
1. **New User Registration**: Create a new bank account.
2. **Existing User Management**: Access existing user details.
3. **Deposit**: Deposit money into an account.
4. **Withdraw**: Withdraw money from an account.
5. **Transfer**: Transfer money between accounts.
6. **Bill Payment**: Pay bills using account balance.
7. **Search User Record**: Search and display user details.
8. **Edit User Record**: Update user details like phone number and address.
9. **Delete User Record**: Remove user records from the system.
10. **Show All Records**: Display all user records.
11. **Show All Payments**: Display all payment transactions.

### ATM Management
1. **User Login & Balance Inquiry**: Check account balance.
2. **Withdraw**: Withdraw money from an account.
3. **Account Details**: View detailed account information.

## How to Use

### Main Menu
When the application starts, the main menu provides the following options:
1. Bank management
2. ATM management
3. Exit

### Bank Management Menu
Choose `1` from the main menu to access the bank management menu, where you can select from various options to manage user accounts and transactions.

### ATM Management Menu
Choose `2` from the main menu to access the ATM management menu, where you can perform ATM-specific operations such as balance inquiries and withdrawals.

### Exiting the Application
Choose `3` from the main menu to exit the application.

## File Structure

The application uses text files to store data:
- **bank.txt**: Stores user account information.
- **bill.txt**: Stores bill payment records.

## Installation and Compilation

1. Ensure you have a C++ compiler installed.
2. Download the source code files.
3. Compile the code using the following command:
   ```bash
   g++ -o bank_atm_management main.cpp
   ```
4. Run the compiled program:
   ```bash
   ./bank_atm_management
   ```

## Dependencies

The project depends on standard C++ libraries:
- `<iostream>`
- `<conio.h>`
- `<stdio.h>`
- `<fstream>`
- `<windows.h>`
- `<ctime>`

## Notes

- The application is designed to run on systems supporting the `conio.h` library, typically Windows systems.
- Ensure the text files (`bank.txt`, `bill.txt`) are in the same directory as the executable for proper file handling.

## Contribution

Feel free to fork this project and submit pull requests for any enhancements or bug fixes. Your contributions are welcome!

## License

This project is licensed under the MIT License. Feel free to use, modify, and distribute the code as per the license terms.

---

Enjoy using the Bank and ATM Management System! If you encounter any issues or have suggestions for improvement, please reach out.