abstract class TempProfile
{
    private string name = "Test";
    private int age = 20;
    private string address = "Tokyo";
    public void SetName(string name)
    {
        this.name = name;
    }
    public string GetName()
    {
        return name;
    }
    public void SetAge(int age)
    {
        this.age = age;
    }
    public int GetAge()
    {
        return age;
    }
    public void SetAddress(string address)
    {
        this.address = address;
    }
    public string GetAddress()
    {
        return address;
    }
    public void Show()
    {
        System.Console.WriteLine("name: " + name + ", age: " + age + ", address: " + address);
    }
}

class Profile : TempProfile
{
    public void Set(string name, int age, string address)
    {
        SetName(name);
        SetAge(age);
        SetAddress(address);
    }
    new public void Show()
    {
        System.Console.WriteLine("name: " + GetName());
        System.Console.WriteLine("age: " + GetAge());
        System.Console.WriteLine("address: " + GetAddress());
    }
}

class Abstract
{
    static void Main()
    {
        TempProfile temp;
        Profile prof = new Profile();

        temp = prof;
        temp.Show();

        System.Console.WriteLine();

        prof.Set("Taro", 25, "Shibuya");
        temp.Show();

        System.Console.WriteLine();

        prof.Show();
    }
}