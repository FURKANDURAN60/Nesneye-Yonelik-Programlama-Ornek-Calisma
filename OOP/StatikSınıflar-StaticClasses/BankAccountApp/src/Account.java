import java.util.ArrayList;
import java.util.List;

public class Account {
    private String accountNumber;
    private String owner;
    private double balance;

    public static List<Account> accounts = new ArrayList<>();

    public Account(String accountNumber, String owner, double balance) {
        this.accountNumber = accountNumber;
        this.owner = owner;
        this.balance = balance;
        accounts.add(this);
    }

    public void deposit(double amount) {
        if (amount <= 0) {
            System.out.println("Yatırılacak tutar 0'dan büyük olmalıdır.");
            return;
        }

        this.balance += amount;
        Bank.trackTransaction(owner + " hesabına " + amount + " TL yatırıldı.");
        System.out.println(amount + " TL hesaba yatırıldı.");
    }

    public void withdraw(double amount) {
        if (amount <= 0) {
            System.out.println("Çekilecek tutar 0'dan büyük olmalıdır.");
            return;
        }

        if (amount > balance) {
            System.out.println("Yetersiz bakiye! İşlem gerçekleştirilemedi.");
            return;
        }

        this.balance -= amount;
        Bank.trackTransaction(owner + " hesabından " + amount + " TL çekildi.");
        System.out.println(amount + " TL hesaptan çekildi.");
    }

    public void viewBalance() {
        System.out.println("Hesap Sahibi: " + owner);
        System.out.println("Hesap Numarası: " + accountNumber);
        System.out.println("Bakiye: " + balance + " TL");
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public String getOwner() {
        return owner;
    }

    public double getBalance() {
        return balance;
    }
}
