namespace StackApp.Models; 

public class Employee
{
    public Employee(string firstName, string lastName, decimal salary)
    {
        FirstName = firstName;
        LastName = lastName;
        Salary = salary;
    }

    public String FirstName { get; set; }= string.Empty;
    public String LastName { get; set; }= string.Empty;
    public String FullName => FirstName + " " + LastName; // => getter fonksiyonu oluyor.
    public Decimal Salary { get; set; }= 0;

    public override string ToString()
    {
        return string.Concat("FullName: ", FullName, " Salary: ", Salary);
    }

}