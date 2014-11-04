class Names
{
    private string[] names;
    public Names(string[] names)
    {
        this.names = names;
    }
    public int Length
    {
        get
        {
            return this.names.Length;
        }
    }
    public string this[int index]
    {
        get
        {
            return names[index];
        }
        set
        {
            names[index] = value;
        }
    }
}

class Indexer
{
    static void Main()
    {
        string[] str = new string[3];
        
        str[0] = "Taro";
        str[1] = "Jiro";
        str[2] = "Saburo";

        Names names = new Names(str);

        for (int i = 0; i < names.Length; i++)
        {
            System.Console.WriteLine("names[" + i + "]: " + names[i]);
        }
    }
}