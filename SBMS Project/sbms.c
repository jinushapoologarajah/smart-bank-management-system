#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50


struct Customer {
    int customerID;
    char name[50];
    char phone[15];
    char email[50];
};

struct Account {
    int accountNo;
    int customerID;
    char accountType[20]; // "Savings" or "Current"
    double balance;
};

struct Transaction {
    int transactionID;
    int accountNo;
    char type[20];        // "Deposit" or "Withdrawal"
    double amount;
};

struct Loan {
    int loanID;
    int customerID;
    double loanAmount;
    double balanceAmount; // Remaining money to pay back
    char status[20];      // "Pending", "Approved", or "Paid"
};


struct Customer customers[MAX];
int customerCount = 0;

struct Account accounts[MAX];
int accountCount = 0;

struct Transaction transactions[MAX];
int transactionCount = 0;

struct Loan loans[MAX];
int loanCount = 0;


int nextCustomerID = 101;
int nextAccountNo = 501;
int nextTransactionID = 901;
int nextLoanID = 201;



//MODULE 1: CUSTOMER MANAGEMENT
void addCustomer();
void viewCustomers();
void searchCustomer();
void updateCustomer();
void deleteCustomer();

//MODULE 2: ACCOUNT MANAGEMENT
void createAccount();
void viewAccounts();
void searchAccount();
void updateAccount();
void deleteAccount();

//MODULE 3: TRANSACTION SYSTEM
void depositMoney();
void withdrawMoney();
void viewAllTransactions();
void searchTransactions();
void clearTransactionHistory();

//MODULE 4: LOAN SYSTEM
void applyLoan();
void viewLoans();
void searchLoan();
void approveLoan();
void payLoan();


int main() {
    int choice;


    customers[0].customerID = 101;
    strcpy(customers[0].name, "Nimal Perera");
    strcpy(customers[0].phone, "0771234567");
    strcpy(customers[0].email, "nimal@gmail.com");
    customerCount = 1;
    nextCustomerID = 102;

    accounts[0].accountNo = 501;
    accounts[0].customerID = 101;
    strcpy(accounts[0].accountType, "Savings");
    accounts[0].balance = 5000.0;
    accountCount = 1;
    nextAccountNo = 502;

    while (1) {
        printf("\n=================================");
        printf("\n   SMART BANK MANAGEMENT SYSTEM  ");
        printf("\n=================================");
        printf("\n1. Customer Management");
        printf("\n2. Account Management");
        printf("\n3. Transaction System");
        printf("\n4. Loan Management");
        printf("\n5. Exit System");
        printf("\n---------------------------------");
        printf("\nEnter Main Choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("\nExiting program... Thank you!\n");
            break;
        }

        switch (choice) {
            case 1: {
                int subChoice = 0;
                printf("\n--- CUSTOMER MODULE ---");
                printf("\n1. Add Customer\n2. View Customers\n3. Search Customer\n4. Update Customer\n5. Delete Customer");
                printf("\nEnter Operation (1-5): ");
                scanf("%d", &subChoice);

                switch(subChoice) {
                    case 1: addCustomer(); break;
                    case 2: viewCustomers(); break;
                    case 3: searchCustomer(); break;
                    case 4: updateCustomer(); break;
                    case 5: deleteCustomer(); break;
                    default: printf("\nInvalid Choice!\n");
                }
                break;
            }
            case 2: {
                int subChoice = 0;
                printf("\n--- ACCOUNT MODULE ---");
                printf("\n1. Create Account\n2. View Accounts\n3. Search Account\n4. Update Account\n5. Delete Account");
                printf("\nEnter Operation (1-5): ");
                scanf("%d", &subChoice);

                switch(subChoice) {
                    case 1: createAccount(); break;
                    case 2: viewAccounts(); break;
                    case 3: searchAccount(); break;
                    case 4: updateAccount(); break;
                    case 5: deleteAccount(); break;
                    default: printf("\nInvalid Choice!\n");
                }
                break;
            }
            case 3: {
                int subChoice = 0;
                printf("\n--- TRANSACTION MODULE ---");
                printf("\n1. Deposit Money\n2. Withdraw Money\n3. View Transaction History\n4. Search Transactions\n5. Clear All History");
                printf("\nEnter Operation (1-5): ");
                scanf("%d", &subChoice);

                switch(subChoice) {
                    case 1: depositMoney(); break;
                    case 2: withdrawMoney(); break;
                    case 3: viewAllTransactions(); break;
                    case 4: searchTransactions(); break;
                    case 5: clearTransactionHistory(); break;
                    default: printf("\nInvalid Choice!\n");
                }
                break;
            }
            case 4: {
                int subChoice = 0;
                printf("\n--- LOAN MODULE ---");
                printf("\n1. Apply for Loan\n2. View All Loans\n3. Search Loan\n4. Approve Loan\n5. Pay Loan Installment");
                printf("\nEnter Operation (1-5): ");
                scanf("%d", &subChoice);

                switch(subChoice) {
                    case 1: applyLoan(); break;
                    case 2: viewLoans(); break;
                    case 3: searchLoan(); break;
                    case 4: approveLoan(); break;
                    case 5: payLoan(); break;
                    default: printf("\nInvalid Choice!\n");
                }
                break;
            }
            default:
                printf("\nInvalid choice code! Try again.\n");
        }
    }
    return 0;
}


// MODULE 1: CUSTOMER MANAGEMENT MODULE

void addCustomer() {
    if (customerCount >= MAX) {
        printf("\nDatabase Full!\n");
        return;
    }
    printf("\n--- Add New Customer ---");
    customers[customerCount].customerID = nextCustomerID++;

    printf("\nEnter Customer Name (No Spaces): ");
    scanf("%s", customers[customerCount].name);
    printf("Enter Phone Number: ");
    scanf("%s", customers[customerCount].phone);
    printf("Enter Email Address: ");
    scanf("%s", customers[customerCount].email);

    printf("\nCustomer Registered! Assigned ID: %d\n", customers[customerCount].customerID);
    customerCount++;
}

void viewCustomers() {
    if (customerCount == 0) {
        printf("\nNo customer profiles found.\n");
        return;
    }
    printf("\n--- Customer Records Matrix ---\n");
    printf("%-10s %-20s %-15s %-20s\n", "ID", "Name", "Phone", "Email");
    for (int i = 0; i < customerCount; i++) {
        printf("%-10d %-20s %-15s %-20s\n",
               customers[i].customerID, customers[i].name, customers[i].phone, customers[i].email);
    }
}

void searchCustomer() {
    int id, found = 0;
    printf("\nEnter Customer ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].customerID == id) {
            printf("\nCustomer Found:");
            printf("\nID   : %d", customers[i].customerID);
            printf("\nName : %s", customers[i].name);
            printf("\nPhone: %s", customers[i].phone);
            printf("\nEmail: %s\n", customers[i].email);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nCustomer ID %d not found.\n", id);
    }
}

void updateCustomer() {
    int id, found = 0;
    printf("\nEnter Customer ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].customerID == id) {
            printf("\nEnter New Name (No Spaces): ");
            scanf("%s", customers[i].name);
            printf("Enter New Phone: ");
            scanf("%s", customers[i].phone);
            printf("Enter New Email: ");
            scanf("%s", customers[i].email);
            printf("\nCustomer info updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("\nCustomer not found.\n");
}

void deleteCustomer() {
    int id, found = 0;
    printf("\nEnter Customer ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].customerID == id) {
            // Shift elements backward to remove the row entry
            for (int j = i; j < customerCount - 1; j++) {
                customers[j] = customers[j + 1];
            }
            customerCount--;
            printf("\nCustomer record erased successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("\nCustomer record not located.\n");
}


// MODULE 2: ACCOUNT MANAGEMENT MODULE

void createAccount() {
    if (accountCount >= MAX) {
        printf("\nAccount records database full!\n");
        return;
    }
    int checkID, validUser = 0;
    printf("\nEnter Associated Customer Owner ID: ");
    scanf("%d", &checkID);

    // Verify if customer actually exists first
    for(int i = 0; i < customerCount; i++) {
        if(customers[i].customerID == checkID) {
            validUser = 1;
            break;
        }
    }

    if(validUser == 0) {
        printf("\nError: Cannot create account. Customer ID does not exist.\n");
        return;
    }

    accounts[accountCount].accountNo = nextAccountNo++;
    accounts[accountCount].customerID = checkID;

    int typeChoice;
    printf("Select Account Type (1 for Savings, 2 for Current): ");
    scanf("%d", &typeChoice);
    if (typeChoice == 1) {
        strcpy(accounts[accountCount].accountType, "Savings");
    } else {
        strcpy(accounts[accountCount].accountType, "Current");
    }

    printf("Enter Initial Opening Balance Amount: ");
    scanf("%lf", &accounts[accountCount].balance);

    printf("\nAccount Setup Complete! Account No: %d\n", accounts[accountCount].accountNo);
    accountCount++;
}

void viewAccounts() {
    if (accountCount == 0) {
        printf("\nNo accounts registered yet.\n");
        return;
    }
    printf("\n--- Account List File ---");
    printf("\n%-12s %-12s %-15s %-12s\n", "Account No", "Owner ID", "Type", "Balance");
    for (int i = 0; i < accountCount; i++) {
        printf("%-12d %-12d %-15s %-12.2f\n",
               accounts[i].accountNo, accounts[i].customerID, accounts[i].accountType, accounts[i].balance);
    }
}

void searchAccount() {
    int accNo, found = 0;
    printf("\nEnter Account Number to search: ");
    scanf("%d", &accNo);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNo == accNo) {
            printf("\nAccount Data Located:");
            printf("\nAccount No: %d", accounts[i].accountNo);
            printf("\nCustomer ID: %d", accounts[i].customerID);
            printf("\nType       : %s", accounts[i].accountType);
            printf("\nBalance    : %.2f LKR\n", accounts[i].balance);
            found = 1;
            break;
        }
    }
    if (!found) printf("\nAccount number %d not found.\n", accNo);
}

void updateAccount() {
    int accNo, found = 0;
    printf("\nEnter Account Number to change type config: ");
    scanf("%d", &accNo);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNo == accNo) {
            printf("\nEnter New Account Type String (Savings/Current): ");
            scanf("%s", accounts[i].accountType);
            printf("\nAccount configuration changed details updated.\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("\nAccount not found.\n");
}

void deleteAccount() {
    int accNo, found = 0;
    printf("\nEnter Account Number to close down: ");
    scanf("%d", &accNo);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNo == accNo) {
            for (int j = i; j < accountCount - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            accountCount--;
            printf("\nAccount removed completely from system balances.\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("\nAccount target not found.\n");
}


// MODULE 3: TRANSACTION MANAGEMENT MODULE

void depositMoney() {
    int accNo, found = 0;
    double amount;
    printf("\nEnter Account Number for Cash Deposit: ");
    scanf("%d", &accNo);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNo == accNo) {
            printf("Enter Deposit Amount: ");
            scanf("%lf", &amount);

            if (amount <= 0) {
                printf("\nInvalid entry amount value.\n");
                return;
            }

            accounts[i].balance += amount; // Add money to balance


            transactions[transactionCount].transactionID = nextTransactionID++;
            transactions[transactionCount].accountNo = accNo;
            strcpy(transactions[transactionCount].type, "Deposit");
            transactions[transactionCount].amount = amount;
            transactionCount++;

            printf("\nSuccess! Deposited %.2f LKR. New Balance: %.2f LKR\n", amount, accounts[i].balance);
            found = 1;
            break;
        }
    }
    if (!found) printf("\nAccount missing target entry routing path failed.\n");
}

void withdrawMoney() {
    int accNo, found = 0;
    double amount;
    printf("\nEnter Account Number for Withdrawal: ");
    scanf("%d", &accNo);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNo == accNo) {
            printf("Enter Withdrawal Amount: ");
            scanf("%lf", &amount);

            if (amount > accounts[i].balance) {
                printf("\nInsufficient balances transaction declined!\n");
                return;
            }

            accounts[i].balance -= amount; // Deduct money from balance

            // Log the tracking history element
            transactions[transactionCount].transactionID = nextTransactionID++;
            transactions[transactionCount].accountNo = accNo;
            strcpy(transactions[transactionCount].type, "Withdrawal");
            transactions[transactionCount].amount = amount;
            transactionCount++;

            printf("\nSuccess! Withdrew %.2f LKR. New Balance: %.2f LKR\n", amount, accounts[i].balance);
            found = 1;
            break;
        }
    }
    if (!found) printf("\nAccount records matching targeted ID not found.\n");
}

void viewAllTransactions() {
    if (transactionCount == 0) {
        printf("\nNo banking transactions logged yet.\n");
        return;
    }
    printf("\n--- Global Core Transaction History Logs ---");
    printf("\n%-10s %-12s %-15s %-10s\n", "TX ID", "Account No", "Type", "Amount");
    for (int i = 0; i < transactionCount; i++) {
        printf("%-10d %-12d %-15s %-10.2f\n",
               transactions[i].transactionID, transactions[i].accountNo, transactions[i].type, transactions[i].amount);
    }
}

void searchTransactions() {
    int accNo, flag = 0;
    printf("\nEnter Account Number to view its history logs: ");
    scanf("%d", &accNo);

    printf("\n--- Filtered Results for Account %d ---", accNo);
    printf("\n%-10s %-15s %-10s\n", "TX ID", "Type", "Amount");
    for(int i = 0; i < transactionCount; i++) {
        if(transactions[i].accountNo == accNo) {
            printf("%-10d %-15s %-10.2f\n", transactions[i].transactionID, transactions[i].type, transactions[i].amount);
            flag = 1;
        }
    }
    if(flag == 0) printf("\nNo transactions recorded matching this specific index.\n");
}

void clearTransactionHistory() {
    transactionCount = 0;
    printf("\nTransaction tracking files reset cleared completely.\n");
}


// MODULE 4: CREDIT & LOAN MANAGEMENT SYSTEM

void applyLoan() {
    if (loanCount >= MAX) {
        printf("\nLoan applications queue limit ceiling achieved!\n");
        return;
    }
    int id, found = 0;
    printf("\nEnter Customer ID applying for loan: ");
    scanf("%d", &id);

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].customerID == id) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nInvalid applicant customer baseline index missing profiles!\n");
        return;
    }

    loans[loanCount].loanID = nextLoanID++;
    loans[loanCount].customerID = id;
    printf("Enter Requested Loan Principal Amount: ");
    scanf("%lf", &loans[loanCount].loanAmount);

    loans[loanCount].balanceAmount = loans[loanCount].loanAmount;
    strcpy(loans[loanCount].status, "Pending");

    printf("\nApplication filed! Tracking Reference Loan ID: %d\n", loans[loanCount].loanID);
    loanCount++;
}

void viewLoans() {
    if (loanCount == 0) {
        printf("\nNo loans filed on the master system registry sheet.\n");
        return;
    }
    printf("\n--- Master Credit File Sheet ---");
    printf("\n%-10s %-10s %-12s %-12s %-10s\n", "Loan ID", "Cust ID", "Principal", "Remaining", "Status");
    for (int i = 0; i < loanCount; i++) {
        printf("%-10d %-10d %-12.2f %-12.2f %-10s\n",
               loans[i].loanID, loans[i].customerID, loans[i].loanAmount, loans[i].balanceAmount, loans[i].status);
    }
}

void searchLoan() {
    int id, found = 0;
    printf("\nEnter Loan ID reference token to locate profile: ");
    scanf("%d", &id);

    for(int i = 0; i < loanCount; i++) {
        if(loans[i].loanID == id) {
            printf("\nLoan Record File Match Matrix:");
            printf("\nLoan ID        : %d", loans[i].loanID);
            printf("\nCustomer ID    : %d", loans[i].customerID);
            printf("\nPrincipal Loan : %.2f", loans[i].loanAmount);
            printf("\nRemaining Debt : %.2f", loans[i].balanceAmount);
            printf("\nApproval Status: %s\n", loans[i].status);
            found = 1;
            break;
        }
    }
    if(!found) printf("\nLoan ID reference code not located.\n");
}

void approveLoan() {
    int id, found = 0;
    printf("\nEnter Loan ID reference code for underwriting decision: ");
    scanf("%d", &id);

    for (int i = 0; i < loanCount; i++) {
        if (loans[i].loanID == id) {
            if (strcmp(loans[i].status, "Pending") != 0) {
                printf("\nLoan is already processed previously!\n");
                return;
            }
            strcpy(loans[i].status, "Approved");
            printf("\nSuccess! Loan ID %d tracking flags marked as APPROVED.\n", id);
            found = 1;
            break;
        }
    }
    if (!found) printf("\nLoan target structure entry row reference not located.\n");
}

void payLoan() {
    int id, found = 0;
    double payment;
    printf("\nEnter Loan ID profile reference for settlement payment: ");
    scanf("%d", &id);

    for (int i = 0; i < loanCount; i++) {
        if (loans[i].loanID == id) {
            if (strcmp(loans[i].status, "Approved") != 0) {
                printf("\nCannot make installment payments on unauthorized or inactive loan logs.\n");
                return;
            }
            printf("Current Remaining Obligation Debt Balance: %.2f\n", loans[i].balanceAmount);
            printf("Enter Your Repayment Payment Amount: ");
            scanf("%lf", &payment);

            if (payment <= 0 || payment > loans[i].balanceAmount) {
                printf("\nInvalid calculation boundary parameters entry.\n");
                return;
            }

            loans[i].balanceAmount -= payment;
            printf("\nInstallment Payment Posted! Balance Due Left: %.2f LKR\n", loans[i].balanceAmount);

            if (loans[i].balanceAmount <= 0) {
                strcpy(loans[i].status, "Paid");
                printf("Congratulations! The liability has been completely paid off.\n");
            }
            found = 1;
            break;
        }
    }
    if (!found) printf("\nLoan mapping lookup file search failure.\n");
}
