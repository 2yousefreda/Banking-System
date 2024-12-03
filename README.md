# Banking Management System

## Project Overview
The Banking Management System is a comprehensive application designed for efficient management of banking operations. This system allows users to manage client accounts, handle financial transactions, and administrate user accounts with different permission levels. The project leverages Object-Oriented Programming principles and employs C++ for robust application design.

## Key Features

### 1. Client Management
- Add, update, delete, and search for clients
- Secure storage of client information (account number, PIN code, balance)
- Deposit, withdrawal, and fund transfer capabilities
- Complete transfer transaction logging
- Client data encryption for security

### 2. User Management
- Login and registration system
- Multiple user permission levels
- User administration (add, modify, delete, search)
- Login activity tracking
- Secure storage of user credentials

### 3. Currency Exchange Service
- Display available currencies and exchange rates
- Currency conversion functionality
- Support for USD and other currencies
- Exchange rate updates by authorized users

### 4. Security Features
- Data encryption for client and user information
- Secure encryption and decryption keys
- Protection of sensitive data
- Validation checks for data integrity

### 5. User Interface
- Command-line based interface
- Organized and clear menus
- Input validation for data integrity
- Consistent screen layout and formatting

## Technical Implementation
- Programming Language: C++
- Object-Oriented Programming (OOP) principles
- Classes include:
  - ClsBankClient
  - ClsUser
  - ClsCurrency
- File-based storage system
- Data encryption mechanisms

## Project Purpose
The system is designed to provide a secure and efficient platform for:
- Managing banking operations
- Handling client accounts
- Processing currency exchanges
- Maintaining transaction records
- User access control

## Security Measures
- Encrypted storage of sensitive information
- Secure user authentication
- Permission-based access control
- Transaction logging and monitoring

## Target Users
- Bank employees
- System administrators
- Client service representatives
- Financial managers

## Setup and Installation
1. **Clone the repository:**
   ```bash
   git clone <repository-url>
   ```

2. **Navigate to the project directory:**
   ```bash
   cd BankingManagementSystem
   ```

3. **Compile the source files:**
   Use a C++ compiler (like g++) to compile the files into an executable.
   ```bash
   g++ -o BankingSystem src/*.cpp
   ```

4. **Run the application:**
   ```bash
   ./BankingSystem
   ```

## Usage
After running the application, users will see a command-line interface (CLI) prompting them to choose from various options. The following is a brief guide to some common operations:

- **UserName**:Admin
- **Password**:000

- **Adding a New Client**: Select the option to add a client, and follow the prompts to input details.
- **Viewing Client Information**: Choose to view clients and enter an account number when prompted.
- **Conducting Transactions**: Access the transaction menu to deposit, withdraw, or transfer money between accounts.
  
### Example:
```plaintext
Welcome to the Banking Management System
===============================
Choose What do you want to do?
[1] Show Client List.
[2] Add New Client.
[3] Delete Client.
...
```

This banking management system combines robust functionality with security features to create a reliable platform for banking operations. The object-oriented design ensures maintainability and scalability, while the security measures protect sensitive financial data.
