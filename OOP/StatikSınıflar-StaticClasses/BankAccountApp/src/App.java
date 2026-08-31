public class App {
    public static void main(String[] args) {
        System.out.println("Banka Hesap Yönetim Sistemi\n");

        Account ahmet = new Account("TR1001", "Ahmet", 2500.0);
        Account ayse = new Account("TR1002", "Ayşe", 4500.0);

        ahmet.deposit(500);
        ahmet.withdraw(200);
        ayse.deposit(1000);

        System.out.println("\nHesap Bakiyesi");
        ahmet.viewBalance();
        ayse.viewBalance();

        System.out.println("\nBanka Bilgileri");
        Bank.displayBankInfo();

        System.out.println("\nİşlem Geçmişi");
        for (String transaction : Bank.transactionHistory) {
            System.out.println(transaction);
        }
    }
}
