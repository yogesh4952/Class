using System;

class Person{
  private string[] name = {"Rame","Shyame","Hari"};

  public string this[int index]{
    get{
      return name[index];
    }
    set{
      name[index]=value;
    }
  }
}
class Program{
  public static void Main(string[]args){
    Person p1 = new Person();
    Console.WriteLine(p1[1]);
  }
}
