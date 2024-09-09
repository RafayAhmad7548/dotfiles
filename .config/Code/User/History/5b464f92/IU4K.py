class BankAccount:
    def __init__(self, account_no: str, name: str, balance: float) -> None:
        self.account_no = account_no
        self.name = name
        self.balance = balance

    def deposit(self, amount: float) -> None:
        self.balance += amount
    
    def withdraw(self, amount: float) -> None:
        self.balance -= amount
    
    def bank_fees(self) -> None:
        self.balance -= 0.05 * self.balance
    
    def display(self) -> None:
        print('account no: ', self.account_no)
        print('name: ', self.name)
        print('balance: ', self.balance)

def main():
    pass


if __name__ == '__main__':
    main()