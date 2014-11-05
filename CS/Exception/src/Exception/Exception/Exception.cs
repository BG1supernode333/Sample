class MinusException : System.Exception
{
    private string message = "Can't use Minus!";
    new public string Message
    {
        get
        {
            return message;
        }
    }
}

class Exception
{
    static void Main()
    {
        int x;
        int y;
        int z;

        System.Console.WriteLine("[Start]");

        try
        {
            System.Console.Write("x: ");
            x = int.Parse(System.Console.ReadLine());

            System.Console.Write("y: ");
            y = int.Parse(System.Console.ReadLine());

            System.Console.WriteLine("x = " + x);
            System.Console.WriteLine("y = " + y);

            if (x < 0 || y < 0)
            {
                MinusException ex = new MinusException();
                throw ex;
            }

            z = x / y;

            System.Console.WriteLine("z = x / y = " + z);
        }
        catch (System.FormatException ex)
        {
            System.Console.WriteLine("FormatException: " + ex.Message);
        }
        catch (System.OverflowException ex)
        {
            System.Console.WriteLine("OverflowException: " + ex.Message);
        }
        catch (System.DivideByZeroException ex)
        {
            System.Console.WriteLine("DivideByZeroException: " + ex.Message);
        }
        catch (MinusException ex)
        {
            System.Console.WriteLine("MinusException: " + ex.Message);
        }
        catch (System.Exception ex)
        {
            System.Console.WriteLine("Other Exception: " + ex.Message);
        }
        finally
        {
            System.Console.WriteLine("[End]");
        }
    }
}