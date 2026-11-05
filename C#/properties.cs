using System;

class Person{
  private int age;
  public int Age{
    get{return age;}
    set{age=value;}
  }

  public void Show(){
    Console.WriteLine($"age: {age}");
  }
}

class Program{

  public static void Main(string[] args){
    Person p1 = new Person();
    p1.Age = 12;
    p1.Show();
  }
}
