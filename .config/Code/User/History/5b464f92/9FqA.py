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
        
        pass