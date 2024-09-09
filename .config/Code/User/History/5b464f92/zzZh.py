class BankAccount:
    def __init__(self: BankAccount, account_no, name, balance) -> None:
        self.account_no = account_no
        self.name = name
        self.balance = balance

    def deposit(self, amount: float) -> None:
        self.balance += amount
    
    def withdraw(self, )