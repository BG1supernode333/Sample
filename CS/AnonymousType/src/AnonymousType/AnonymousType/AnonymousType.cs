using System;

class AnonymousType
{
    static void Main()
    {
        var prof = new { Name = "Taro", Age = 20, Address = "Tokyo" };
        
        Console.WriteLine("prof.Name = " + prof.Name);
        Console.WriteLine("prof.Age = " + prof.Age);
        Console.WriteLine("prof.Address = " + prof.Address);
    }
}