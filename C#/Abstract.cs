using System;

abstract class Animal{
  abstract public void Sound();
}

class Dog: Animal{
  override public void Sound(){
    Console.WriteLine("WOOF");
  }
}

class Cat: Animal{
  override public void Sound(){
    Console.WriteLine("MEOWW");
  }
}


class Program{
  static void Main(string[] args){
    Animal a1 = new Cat();

  }
}
