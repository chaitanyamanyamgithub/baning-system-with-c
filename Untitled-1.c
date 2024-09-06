class BankAccount:
    def __init__(self, account_number, holder_name, balance=0):
        self.account_number = account_number
        self.holder_name = holder_name
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"Deposited ${amount:.2f}. New balance: ${self.balance:.2f}")
        else:
            print("Invalid deposit amount. Please enter a positive number.")

    def withdraw(self, amount):
        if 0 < amount <= self.balance:
            self.balance -= amount
            print(f"Withdrew ${amount:.2f}. New balance: ${self.balance:.2f}")
        else:
            print("Invalid withdrawal amount or insufficient balance.")

    def get_balance(self):
        return self.balance

    def transfer(self, other_account, amount):
        if 0 < amount <= self.balance:
            self.balance -= amount
            other_account.balance += amount
            print(f"Transferred ${amount:.2f} to {other_account.holder_name}")
        else:
            print("Insufficient balance for the transfer or invalid amount.")

def main():
    accounts = {}

    while True:
        print("\nBanking System Menu:")
        print("1. Create Account")
        print("2. Deposit")
        print("3. Withdraw")
        print("4. Check Balance")
        print("5. Transfer Funds")
        print("6. Exit")

        choice = input("Enter your choice: ").strip()

        if choice == '1':
            account_number = input("Enter account number: ").strip()
            if account_number in accounts:
                print("Account already exists.")
                continue
            holder_name = input("Enter account holder name: ").strip()
            new_account = BankAccount(account_number, holder_name)
            accounts[account_number] = new_account
            print("Account created successfully.")
        elif choice == '2':
            account_number = input("Enter account number: ").strip()
            if account_number in accounts:
                try:
                    amount = float(input("Enter deposit amount: $").strip())
                    accounts[account_number].deposit(amount)
                except ValueError:
                    print("Please enter a valid amount.")
            else:
                print("Account not found.")
        elif choice == '3':
            account_number = input("Enter account number: ").strip()
            if account_number in accounts:
                try:
                    amount = float(input("Enter withdrawal amount: $").strip())
                    accounts[account_number].withdraw(amount)
                except ValueError:
                    print("Please enter a valid amount.")
            else:
                print("Account not found.")
        elif choice == '4':
            account_number = input("Enter account number: ").strip()
            if account_number in accounts:
                balance = accounts[account_number].get_balance()
                print(f"Account balance for {accounts[account_number].holder_name}: ${balance:.2f}")
            else:
                print("Account not found.")
        elif choice == '5':
            account_number1 = input("Enter your account number: ").strip()
            account_number2 = input("Enter recipient's account number: ").strip()
            if account_number1 in accounts and account_number2 in accounts:
                try:
                    amount = float(input("Enter transfer amount: $").strip())
                    accounts[account_number1].transfer(accounts[account_number2], amount)
                except ValueError:
                    print("Please enter a valid amount.")
            else:
                print("One or both accounts not found.")
        elif choice == '6':
            print("Thank you for using the Banking System. Goodbye!")
            break
        else:
            print("Invalid choice. Please select a valid option.")

if __name__ == "__main__":
    main()

