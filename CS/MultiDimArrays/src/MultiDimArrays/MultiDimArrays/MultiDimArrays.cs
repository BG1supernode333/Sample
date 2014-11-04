class MultiDimArrays
{
    static void Main()
    {
        string[,] addresses = new string[3, 2];

        addresses[0, 0] = "Taro";
        addresses[0, 1] = "Tokyo";
        addresses[1, 0] = "Jiro";
        addresses[1, 1] = "Osaka";
        addresses[2, 0] = "Saburo";
        addresses[2, 1] = "Nagoya";

        for (int i = 0; i < 3; i++)
        {
            System.Console.WriteLine("addresses[" + i + "]: name = " + addresses[i, 0] + ", address = " + addresses[i, 1]);
        }
    }
}