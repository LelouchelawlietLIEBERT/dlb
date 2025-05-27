class BankAccount:
    def __init__(s, n, a, b, t, ad): s.n, s.a, s.b, s.t, s.ad = n, a, b, t, ad
    def withdraw(s, amt): s.b -= amt
    def deposit(s, amt): s.b += amt
    def display(s): print(s.n, s.a, s.b, s.t, s.ad)
a = BankAccount("Alice", 123, 5000, "SAV", "Blr"); a.deposit(500); a.withdraw(300); a.display()
