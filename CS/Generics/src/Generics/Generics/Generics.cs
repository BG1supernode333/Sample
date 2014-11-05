using System;

class Swap<T>
{
    private T x;
    public T X
    {
        get
        {
            return x;
        }
        set
        {
            x = value;
        }
    }
    private T y;
    public T Y
    {
        get
        {
            return y;
        }
        set
        {
            y = value;
        }
    }
    public void DoSwap()
    {
        T tmp;
        tmp = X;
        X = Y;
        Y = tmp;
    }
}

class Generics
{
    static void Main()
    {
        Swap<int> isw = new Swap<int>();

        isw.X = 10;
        isw.Y = 20;

        Console.WriteLine("X = " + isw.X + ", Y = " + isw.Y);
        isw.DoSwap();
        Console.WriteLine("X = " + isw.X + ", Y = " + isw.Y);

        Console.WriteLine();

        Swap<string> ssw = new Swap<string>();

        ssw.X = "ABCDE";
        ssw.Y = "XYZ";

        Console.WriteLine("X = " + ssw.X + ", Y = " + ssw.Y);
        ssw.DoSwap();
        Console.WriteLine("X = " + ssw.X + ", Y = " + ssw.Y);
    }
}