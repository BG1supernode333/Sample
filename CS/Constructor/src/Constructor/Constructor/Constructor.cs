class Profile
{
    private string name;
    private int age;
    private string address;
    public Profile()
    {
        name = "(no name)";
        age = 0;
        address = "(no address)";
    }
    public void SetProfile(string name, int age, string address)
    {
        this.name = name;
        this.age = age;
        this.address = address;
    }
    public string GetName()
    {
        return name;
    }
    public int GetAge()
    {
        return age;
    }
    public string GetAddress()
    {
        return address;
    }
}

class Constructor
{
    static void Main()
    {
        Profile prof = new Profile();

        System.Console.WriteLine("prof.name = " + prof.GetName());
        System.Console.WriteLine("prof.age = " + prof.GetAge());
        System.Console.WriteLine("prof.address = " + prof.GetAddress());

        System.Console.WriteLine("-----");

        prof.SetProfile("Tanaka", 20, "Tokyo");

        System.Console.WriteLine("prof.name = " + prof.GetName());
        System.Console.WriteLine("prof.age = " + prof.GetAge());
        System.Console.WriteLine("prof.address = " + prof.GetAddress());
    }
}