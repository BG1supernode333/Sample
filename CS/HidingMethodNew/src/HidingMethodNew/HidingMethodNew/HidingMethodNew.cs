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
    public void Show()
    {
        System.Console.WriteLine("name = " + name);
        System.Console.WriteLine("age = " + age);
        System.Console.WriteLine("address = " + address);
    }
}

class Detail : Profile
{
    private string phonenumber;
    private byte sex;
    private int height;
    private int weight;
    public Detail()
    {
        phonenumber = "(no phonenumber)";
        sex = 0;
        height = 0;
        weight = 0;
    }
    public void SetDetail(string phonenumber, byte sex, int height, int weight)
    {
        this.phonenumber = phonenumber;
        this.sex = sex;
        this.height = height;
        this.weight = weight;
    }
    public string GetPhoneNumber()
    {
        return phonenumber;
    }
    public byte GetSex()
    {
        return sex;
    }
    public int GetHeight()
    {
        return height;
    }
    public int GetWeight()
    {
        return weight;
    }
    new public void Show()
    {
        
        System.Console.WriteLine("name = " + GetName());
        System.Console.WriteLine("age = " + GetAge());
        System.Console.WriteLine("address = " + GetAddress());
        System.Console.WriteLine("phonenumber = " + phonenumber);
        System.Console.WriteLine("sex = " + sex);
        System.Console.WriteLine("height = " + height);
        System.Console.WriteLine("weight = " + weight);
    }
}

class HidingMethodNew
{
    static void Main()
    {
        Profile prof = new Profile();
        Detail det = new Detail();

        prof.SetProfile("test1", 20, "tokyo");
        prof.Show();

        System.Console.WriteLine();

        det.SetProfile("test2", 30, "osaka");
        det.SetDetail("00000000", 1, 160, 50);
        det.Show();
    }
}