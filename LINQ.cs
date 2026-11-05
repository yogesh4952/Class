using System;
using System.Collections.Generic;
using System.Linq;


class Employee{
  public string Name {get;set;}
  public int Age {get;set;}
  public int Salary {get;set;}
}

class Person{
  private List<Employee> data = new List<Employee>
    {
        new Employee { Name = "randi", Age = 13, Salary = 20000 },
        new Employee { Name = "randi", Age = 25, Salary = 25000 },
        new Employee { Name = "randi", Age = 20, Salary = 10000 }
    }; 
  public void Show(){
    var result = data.Where(e=>e.Salary > 20000);
    foreach (var e in result)
    {
      Console.WriteLine($"{e.Name} - {e.Age} - {e.Salary}");
    }        
  }
}

class Program{
  public static void Main(string[] args){
    Person p1 = new Person();
    p1.Show();
  }
}
