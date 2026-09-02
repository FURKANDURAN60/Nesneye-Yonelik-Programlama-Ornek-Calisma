using  StackApp.Models;


var numbers = new int[]{ 1, 2, 3, 4, 5 };

var stack_numbers = new StackApp.Models.Stack<int>(numbers);
//stack_numbers.Push("FURKAN"); 
// // Farklı tip bir ekleme yaptım. generic yaptığımız için farklı tür ekleme yapapmayız.

System.Console.WriteLine(stack_numbers.Peek() + " ");

var cities = new List<String>() 
{ 
    "Ankara", "İstanbul", "İzmir", "Bursa" 
};

var stack_cities = new StackApp.Models.Stack<string>(cities); // LIFO MANTIĞI

foreach (var item in cities)
{
    System.Console.WriteLine(stack_cities.Pop() + " ");
}

var stack_employees = new StackApp.Models.Stack<Employee>(new Employee[] 
{ 
    new Employee("Furkan", "Duran", 1000), 
    new Employee("Şevval", "Duran", 2000), 
    new Employee("Salih", "Duran", 3000) 
});

foreach (var item in cities)
{
    System.Console.WriteLine(stack_employees.Pop() + " ");
}

