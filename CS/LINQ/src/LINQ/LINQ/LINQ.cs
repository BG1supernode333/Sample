using System;
using System.Collections.Generic;
using System.Linq;

class Body
{
    private string name;
    public string Name
    {
        get
        {
            return name;
        }
        set
        {
            name = value;
        }
    }
    private int age;
    public int Age
    {
        get
        {
            return age;
        }
        set
        {
            age = value;
        }
    }
    private int height;
    public int Height
    {
        get
        {
            return height;
        }
        set
        {
            height = value;
        }
    }
    private int weight;
    public int Weight
    {
        get
        {
            return weight;
        }
        set
        {
            weight = value;
        }
    }
    public Body(string name, int age, int height, int weight)
    {
        this.name = name;
        this.age = age;
        this.height = height;
        this.weight = weight;
    }
}

class LINQ
{
    static void Main()
    {
        var bodies = new List<Body>();

        bodies.Add(new Body("Taro", 30, 170, 60));
        bodies.Add(new Body("Jiro", 28, 160, 68));
        bodies.Add(new Body("Saburo", 25, 180, 70));
        bodies.Add(new Body("Shiro", 19, 156, 50));
        bodies.Add(new Body("Goro", 17, 175, 65));

        var result = from p in bodies where p.Height >= 170 orderby p.Age descending select p.Name;
        
        Console.WriteLine("-----result-----");

        foreach (var s in result)
        {
            Console.WriteLine(s);
        }

        Console.WriteLine("-----result-----");
    }
}