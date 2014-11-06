using System;

static class Add
{
    public static int DoAdd(this Calc c, int x, int y)
    {
        return x + y;
    }
}

static class Sub
{
    public static int DoSub(this Calc c, int x, int y)
    {
        return x - y;
    }
}

class Calc
{

}

class ExtensionMethod
{
    static void Main()
    {
        var c = new Calc();
        
        var add = c.DoAdd(2, 3);
        var sub = c.DoSub(10, 4);

        Console.WriteLine("add(2, 3) = " + add);
        Console.WriteLine("sub(10, 4) = " + sub);
    }
}