class Test
{
    private int i;
    private string str;
    public void Set(int n, string s)
    {
        i = n;
        str = s;
    }
    public void Show()
    {
        System.Console.WriteLine("i: " + i + ", str: " + str);
    }
}

class Class
{
    static void Main()
    {
        Test t = new Test();
        t.Set(100, "ABCDE");
        t.Show();
    }
}