class MainMethod
{
    static void Main()
    {
        bool b1 = true;
        bool b2 = false;

        System.Console.WriteLine(b1);
        System.Console.WriteLine(b2);

        b1 = false;
        b2 = true;

        System.Console.WriteLine(b1);
        System.Console.WriteLine(b2);

        System.Console.WriteLine("b1 || b2 = " + (b1 || b2));
        System.Console.WriteLine("b1 && b2 = " + (b1 && b2));
    }
}