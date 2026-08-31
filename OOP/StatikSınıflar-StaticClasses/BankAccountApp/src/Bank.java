import java.util.ArrayList;
import java.util.List;

public class Bank {
    public static List<String> transactionHistory = new ArrayList<>();

    public static void displayBankInfo() {
        System.out.println("Banka Adı: Demo Bank");
        System.out.println("Şube: Merkez Şube");
        System.out.println("Toplam Hesap Sayısı: " + Account.accounts.size());
    }

    public static void trackTransaction(String description) {
        transactionHistory.add(description);
    }
}
