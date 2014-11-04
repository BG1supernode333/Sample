class ForEach
{
    static void Main()
    {
        string[] array = new string[10];

        array[0] = "Tokyo";
        array[1] = "Osaka";
        array[2] = "Nagoya";
        array[3] = "Sapporo";
        array[4] = "Fukuoka";
        array[5] = "Hiroshima";
        array[6] = "Sendai";
        array[7] = "Niigata";
        array[8] = "Kyoto";
        array[9] = "Matsuyama";

        foreach (string str in array)
        {
            System.Console.WriteLine(str);
        }

        System.Console.WriteLine();

        System.Collections.ArrayList alist = new System.Collections.ArrayList();

        alist.Add("New York");
        alist.Add("London");
        alist.Add("Paris");

        foreach (string str in alist)
        {
            System.Console.WriteLine(str);
        }
    }
}