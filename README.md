# Banking Management System

## Overview
The Banking Management System (BMS) is a robust application designed to streamline and automate various banking operations. This system caters to both bank personnel and clients, providing a user-friendly interface to manage bank accounts, process transactions, and maintain comprehensive records. The application is built using C++ and adheres to Object-Oriented Programming (OOP) principles, ensuring scalability and maintainability.

## Key Features
### 1. Client Management
- **Add New Client:** 
  - Input required fields including `Name`, `Email`, `Phone Number`, `Account Type (Savings/Current)`, and `Initial Deposit`.
  - Example of Input Command:
    ```
    Add New Client:
    Name: John Doe
    Email: johndoe@example.com
    Phone: +1234567890
    Account Type: Savings
    Initial Deposit: $1000
    ```

- **Update Client Information:**
  - Modify current details of existing clients based on user input.
  - Ensure data validation to maintain consistency (e.g., valid email format).

- **Delete Client Accounts:**
  - Permanently remove a client account. Requires confirmation to prevent accidental deletions.

- **Search for Clients:**
  - Retrieve details via account number or name.
  - Display information including balance and transaction history.

### 2. Transaction Management
- **Deposit Funds:**
  - Prompt the user for the account number and deposit amount.
  - Example of Deposit Interaction:
    ```
    Deposit Funds:
    Account Number: 123456
    Amount: $200
    ```

- **Withdraw Funds:**
  - Verify account balance before processing the withdrawal.
  - Example Withdrawal Interaction:
    ```
    Withdraw Funds:
    Account Number: 123456
    Amount: $150
    ```

- **Transfer Money:**
  - Specify both the sender's and receiver's account numbers and the transfer amount.
  - Ensure sufficient balance in the sender's account.

- **Transaction History:**
  - View a detailed log of all transactions performed by clients including timestamps, amounts, and transaction types.

### 3. User Management
- **User Roles:**
  - Define different user roles including Admin, Teller, and Manager, each with specific access levels.
  
- **Add New Users:**
  - Create user profiles with required details such as `Username`, `Password`, and `Role`.

- **Update User Information:**
  - Allow changes to user details and permissions.

- **Delete Users:**
  - Remove inactive or obsolete user accounts from the system.

### 4. Currency Management
- **Add/Update Currency Rates:**
  - Maintain real-time currency values for efficient conversions and transactions.

- **Currency Conversion:**
  - Allow clients to convert currencies based on the latest rates.
  - Example Conversion Prompt:
    ```
    Convert Currency:
    Amount: $100
    From: USD
    To: EUR
    ```

### 5. Record Keeping
- **Login History:**
  - Track all login attempts for security purposes with timestamps and IP addresses.

- **Financial Transaction Logs:**
  - Maintain detailed records of all deposits, withdrawals, and transfers for audit purposes.

## Technologies Used
- **Programming Language:** C++
- **Data Handling:** File I/O for data persistence using text files.
- **Development Environment:** Supported on any platform with a C++ compiler (e.g., g++, MSVC).

## Installation Instructions
1. **Clone the Repository:**
   ```bash
   git clone <repository-url>
   ```

2. **Navigate to the Project Directory:**
   ```bash
   cd BankingManagementSystem
   ```

3. **Compile the Source Files:**
   - Use a C++ compiler to compile all `*.cpp` files.
   ```bash
   g++ -o BankingSystem src/ClsBankClient.cpp src/ClsUser.cpp src/ClsTransactionScreen.cpp src/ClsCurrency.cpp src/ClsMainScreen.cpp main.cpp
   ```

4. **Run the Application:**
   - Execute the compiled program to launch the application.
   ```bash
   ./BankingSystem
   ```

## Usage
- Upon launching the application, users will encounter a menu-driven interface. Below are example commands for typical interactions:

### Example Commands
1. **To Add a New Client:**
   - Select option from the main menu:
     ```
     1. Add New Client
     Enter details as prompted.
     ```

2. **To Perform a Transaction:**
   - Choose the transaction type (Deposit, Withdraw, Transfer), and follow prompts:
     ```
     2. Deposit Funds
     Account Number: 123456
     Amount: $500
     ```

3. **To View Client Information:**
   - Select option to view details and enter the client’s account number.

### Example Main Menu Display:
```plaintext
Welcome to the Banking Management System
===============================
Choose an option:
[1] Client Management
[2] Transaction Management
[3] User Management
[4] Currency Management
[5] Exit
```

## Contribution Guidelines
- Contributions are always welcome! 
- If you wish to contribute, please follow these steps:
  1. Fork the repository.
  2. Create a new branch (`git checkout -b feature-branch-name`).
  3. Make your changes and commit (`git commit -m 'Add a new feature'`).
  4. Push to your branch (`git push origin feature-branch-name`).
  5. Create a Pull Request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Acknowledgments
- Special thanks to mentors, peers, and resources that contributed knowledge and support for developing this project.
- Inspired by various banking management systems and best practices in software development.