enum Sex
{
    NONE,
    MALE,
    FEMALE
}

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
    private Sex sex;
    public Sex Sex
    {
        get
        {
            return this.sex;
        }
        set
        {
            this.sex = value;
        }
    }
    public void Show()
    {
        System.Console.WriteLine("name: " + name);
        System.Console.WriteLine("age: " + age);
        System.Console.WriteLine("address: " + address);
        if (sex == Sex.MALE)
        {
            System.Console.WriteLine("sex: MALE");
        }
        else if (sex == Sex.FEMALE)
        {
            System.Console.WriteLine("sex: FEMALE");
        }
        else
        {
            System.Console.WriteLine("sex: NONE");
        }
    }
}

class Enum
{
    static void Main()
    {
        Profile prof = new Profile();

        prof.Name = "Taro";
        prof.Age = 20;
        prof.Address = "Tokyo";
        prof.Sex = Sex.MALE;

        prof.Show();
    }
}