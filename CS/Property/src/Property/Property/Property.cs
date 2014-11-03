class Profile
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
    public void Show()
    {
        System.Console.WriteLine("name: " + name);
        System.Console.WriteLine("age: " + age);
        System.Console.WriteLine("address: " + address);
    }
}

class Detail : Profile
{
    private string phonenumber;
    public string PhoneNumber
    {
        get
        {
            return phonenumber;
        }
        set
        {
            phonenumber = value;
        }
    }
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
    new public void Show()
    {
        System.Console.WriteLine("Name: " + Name);
        System.Console.WriteLine("Age: " + Age);
        System.Console.WriteLine("Address: " + Address);
        System.Console.WriteLine();
        System.Console.WriteLine("phonenumber: " + phonenumber);
        System.Console.WriteLine("sex: " + sex);
        System.Console.WriteLine("height: " + height);
        System.Console.WriteLine("weight: " + weight);
    }
}

class Property
{
    static void Main()
    {

        System.Console.WriteLine("-----");

        Profile prof = new Profile();

        prof.Name = "Taro";
        prof.Age = 20;
        prof.Address = "Tokyo";

        prof.Show();

        System.Console.WriteLine("-----");

        Detail det = new Detail();

        det.Name = "Jiro";
        det.Age = 18;
        det.Address = "Osaka";
        det.PhoneNumber = "22222222";
        det.Sex = 1;
        det.Height = 170;
        det.Weight = 65;

        det.Show();

        System.Console.WriteLine("-----");
    }
}