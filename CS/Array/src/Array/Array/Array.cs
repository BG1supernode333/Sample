class Array
{
    static void Main()
    {
        string[] names = new string[5];

        names[0] = "Taro";
        names[1] = "Hanako";
        names[2] = "Jiro";
        names[3] = "Kaori";
        names[4] = "Saburo";

        for (int i = 0; i < 5; i++)
        {
            System.Console.WriteLine("names[" + i + "]: " + names[i]);
        }
    }
}