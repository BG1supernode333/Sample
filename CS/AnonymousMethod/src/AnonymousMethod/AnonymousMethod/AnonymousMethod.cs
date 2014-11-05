using System;

class AnonymousMethod
{
    delegate long FactorialDelegate(long m);
    static void Main()
    {
        long result;

        result = Factorial(20);

        Console.WriteLine("Final result = " + result);
    }
    static long Factorial(long n)
    {
        long x = 1;

        FactorialDelegate fd = delegate (long m)
        {
                Console.WriteLine("Callback inner result = " + m);

                return m;
        };

        for (long i = 2; i <= n; i++)
        {
            x = x * i;
        }

        long t;

        t = fd(x);

        Console.WriteLine("Delegate after result = " + t);

        return t;
    }
}