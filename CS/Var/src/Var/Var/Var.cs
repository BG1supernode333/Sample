using System;
using System.Collections.Generic;

class Var
{
    static void Main()
    {
        var ils = new List<int>();

        ils.Add(5);
        ils.Add(2);
        ils.Add(4);
        ils.Add(1);
        ils.Add(3);

        foreach (var e in ils)
        {
            Console.WriteLine("e = " + e);
        }
    }
}