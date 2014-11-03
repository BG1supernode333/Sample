class TestObject
{
    private int x;
    private string str;
    public void Set(int x, string str)
    {
        this.x = x;
        this.str = str;
    }
    public void Show()
    {
        System.Console.WriteLine("x = " + x + ", str = " + str);
    }
}

class Object
{
    static void Main()
    {
        int x = 10;
        int y;
        object obj;
        TestObject testobj;

        obj = x;

        System.Console.WriteLine("x = " + x);
        System.Console.WriteLine("obj = " + obj);

        System.Console.WriteLine();

        System.Console.WriteLine("x.ToString() = " + x.ToString());
        System.Console.WriteLine("obj.ToString() = " + obj.ToString());

        System.Console.WriteLine();

        y = (int)obj;

        System.Console.WriteLine("y = " + y);

        System.Console.WriteLine();

        testobj = new TestObject();
        testobj.Set(100, "ABCDE");
        testobj.Show();
        System.Console.WriteLine("testobj.ToString() = " + testobj.ToString());
    }
}