using System;
using System.IO;

class LambdaExpression
{
    delegate int SquareDelegate(int x);
    delegate bool FileCheckDelegate(string filename);
    static void Main()
    {
        Console.WriteLine("-----AnonymousMethod-----");

        int y = 0;

        SquareDelegate sd1 = delegate(int x)
        {
            return x * x;
        };

        y = sd1(5);

        Console.WriteLine("y = sd1(5) = " + y);

        Console.WriteLine("-----LambdaExpression(ExpressionStyle)-----");

        int z = 0;

        SquareDelegate sd2 = x => x * x;

        z = sd2(10);

        Console.WriteLine("z = sd2(10) = " + z);

        Console.WriteLine("-----LambdaExpression(StatementStyle)-----");

        FileCheckDelegate fcd = (filename) =>
        {
            if (File.Exists(filename))
            {
                Console.WriteLine(filename + " is Exists.");
                return true;
            }
            else
            {
                Console.WriteLine(filename + " is not Exists!");
                return false;
            }
        };

        if (fcd("test.txt"))
        {
            Console.WriteLine("Check OK.");
        }
        else
        {
            Console.WriteLine("Check NG!");
        }

        if (fcd("dummy.txt"))
        {
            Console.WriteLine("Check OK.");
        }
        else
        {
            Console.WriteLine("Check NG!");
        }
    }
}