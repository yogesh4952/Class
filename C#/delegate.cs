using System;

delegate void MyDelegate();
class Parent{
  public void Display(){
    Console.WriteLine("I am parent");
  }
}
class Program
{
  public static void Main(string[] args){
    Parent obj1 = new Parent();
    MyDelegate del= obj1.Display;
    del();
  }
    
}
