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

mahd_account = BankAccount('2587', 'Mahd', 0.0)
mahd_account.deposit(500.0)
mahd_account.withdraw(5.0)
mahd_account.bank_fees()
mahd_account.display()
