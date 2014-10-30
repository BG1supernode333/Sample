class RefOut
{
    public static void Swap(ref int a, ref int b)
    {
        int tmp;

        tmp = a;
        a = b;
        b = tmp;
    }
    public static void Return100(out int c)
    {
        c = 100;
    }
    static void Main()
    {
        int a = 10;
        int b = 20;
        int c;

        System.Console.WriteLine("a = " + a + ", b = " + b);

        Swap(ref a, ref b);

        System.Console.WriteLine("a = " + a + ", b = " + b);

        Return100(out c);

        System.Console.WriteLine("c = " + c);
    }
}