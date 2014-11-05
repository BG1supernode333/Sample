using System;

class Delegate
{
    delegate long FactorialDelegate(long n);
    static void Main()
    {
        long result;

        result = Factorial(20);

        Console.WriteLine("Final result = " + result);
    }
    static long Factorial(long n)
    {
        long x = 1;

        FactorialDelegate fd = new FactorialDelegate(FactorialCallback);
        
        for (long i = 2; i <= n; i++)
        {
            x = x * i;
        }

        long t;

        t = fd(x);

        Console.WriteLine("Delegate after result = " + t);

        return t;
    }
    static long FactorialCallback(Int64 result)
    {
        Console.WriteLine("Callback inner result = " + result);

        return result;
    }
}