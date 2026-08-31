import java.util.Collections;
import java.util.List;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {

        List<Employee> employees = Arrays.asList(
                new Employee("Furkan Duran", 100000.0),
                new Employee("Musa Kağan Uzun", 160000.0),
                new Employee("Begümsu Başaran", 170000.0),
                new Employee("Enes Altıntaş", 180000.0)
        );
        writeList(employees);

        System.out.println("-----------");

        Collections.sort(employees);
        writeList(employees);
    }

    private static void writeList(Iterable collection) // arayüz Iterable 
    {
        for  (Object item : collection) {
            System.out.println(item);
        }
    }

}