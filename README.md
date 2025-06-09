# SecureBank ATM Simulator

A comprehensive ATM simulator with complete banking operations, security features, and user account management.

## Key Features

- **User Authentication System**
  - Secure PIN-based login with attempt limits
  - Account blocking after multiple failed attempts
  - Age verification (18+ only)

- **Banking Operations**
  - Cash withdrawal with balance validation
  - Fund transfers between accounts
  - Cash deposits
  - Bill payments (electricity, gas, internet, telephone)
  - Balance inquiries

- **Account Management**
  - New account creation with auto-generated account numbers
  - PIN change functionality
  - Transaction receipts with timestamps
  - Secure logout process

- **Data Persistence**
  - Binary file storage for customer data
  - Persistent account information across sessions
  - Transaction history tracking

## Technical Implementation

- **Core Components**
  - Structured data storage using C structs
  - File I/O operations for data persistence
  - Random number generation for account numbers and bills
  - System time integration for receipts

- **Security Features**
  - PIN verification with confirmation
  - Three-attempt login limit
  - Balance validation before transactions
  - Secure data handling

- **User Interface**
  - Console-based menu system
  - Formatted input/output
  - Clear transaction feedback
  - System status messages

## How to Use

1. Compile the program using a C compiler (tested with gcc)
2. Run the executable
3. Choose between:
   - Creating a new account (requires personal details)
   - Logging into an existing account
4. Use the menu system to perform banking operations

### Sample Workflow

1. Create account → Enter details → Receive account number
2. Login with account number and PIN
3. Perform transactions (withdraw, transfer, deposit, pay bills)
4. View balance or print receipt
5. Securely logout

## Code Structure

```plaintext
SecureBank-ATM/
├── Main Program
│   ├── Account creation system
│   ├── Login authentication
│   ├── Transaction processing
│   └── File operations
│
└── Data Structure
    ├── Customer database struct
    │   ├── Personal information
    │   ├── Account details
    │   └── Transaction records
    └── Temporary variables
        ├── Transaction amounts
        ├── PIN verification
        └── System time
```
