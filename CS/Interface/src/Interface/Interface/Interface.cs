interface IShowData
{
    void ShowData();
}

class Profile : IShowData
{
    private string name;
    public string Name
    {
        get
        {
            return name;
        }
        set
        {
            name = value;
        }
    }
    private int age;
    public int Age
    {
        get
        {
            return age;
        }
        set
        {
            age = value;
        }
    }
    private string address;
    public string Address
    {
        get
        {
            return address;
        }
        set
        {
            address = value;
        }
    }
    public void ShowData()
    {
        System.Console.WriteLine("prof.Name = " + Name);
        System.Console.WriteLine("prof.Age = " + Age);
        System.Console.WriteLine("prof.Address = " + Address);
    }
}

class Body : IShowData
{
    private byte sex;
    public byte Sex
    {
        get
        {
            return sex;
        }
        set
        {
            sex = value;
        }
    }
    private int height;
    public int Height
    {
        get
        {
            return height;
        }
        set
        {
            height = value;
        }
    }
    private int weight;
    public int Weight
    {
        get
        {
            return weight;
        }
        set
        {
            weight = value;
        }
    }
    public void ShowData()
    {
        System.Console.WriteLine("prof.Sex = " + Sex);
        System.Console.WriteLine("prof.Height = " + Height);
        System.Console.WriteLine("prof.Weight = " + Weight);
    }
}

class Interface
{
    static void Main()
    {
        Profile prof = new Profile();

        prof.Name = "Taro";
        prof.Age = 20;
        prof.Address = "Tokyo";
        
        prof.ShowData();

        System.Console.WriteLine();

        Body body = new Body();

        body.Sex = 1;
        body.Height = 170;
        body.Weight = 60;

        body.ShowData();
    }
}