class JaggedArray
{
    static void Main()
    {
        string[][] profiles = new string[3][];

        profiles[0] = new string[] { "Taro", "20", "Tokyo" };
        profiles[1] = new string[] { "Jiro", "Osaka" };
        profiles[2] = new string[] { "Saburo", "17", "Nagoya", "00000000", "180" };

        for (int i = 0; i < profiles.Length; i++)
        {
            for (int j = 0; j < profiles[i].Length; j++)
            {
                System.Console.Write(profiles[i][j]);
                System.Console.Write(" ");
            }
            System.Console.WriteLine();
        }
    }
}