using System;
using System.Collections;

class IntEnumerator : IEnumerator
{
    int index = 0;
    int max = 0;
    public IntEnumerator(int max)
    {
        this.max = max;
    }
    public object Current
    {
        get
        {
            return index;
        }
    }
    public bool MoveNext()
    {
        index++;
        if (index > max)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    public void Reset()
    {
        index = 0;
        max = 0;
    }
}

class IntEnumerable : IEnumerable
{
    int n;
    public IntEnumerable(int n)
    {
        this.n = n;
    }
    public IEnumerator GetEnumerator()
    {
        return new IntEnumerator(this.n);       
    }
}

class Yield
{
    public static IEnumerable GetIterator(int max)
    {
        int i = 0;
        while (true)
        {
            i++;
            if (i > max)
            {
                yield break;
            }
            yield return i;
        }
    }
    static void Main()
    {
        Console.WriteLine("-----IEnumerable and IEnumerator-----");

        IntEnumerable intEnum = new IntEnumerable(5);
        
        foreach (int ie in intEnum)
        {
            Console.WriteLine(ie);
        }

        Console.WriteLine("-----yield return and yield break-----");

        foreach (int itor in GetIterator(5))
        {
            Console.WriteLine(itor);
        }

        Console.WriteLine("-----MoveNext-----");

        IEnumerable mvnxtIE = GetIterator(5);
        IEnumerator mvnxtItor = mvnxtIE.GetEnumerator();

        mvnxtItor.MoveNext();
        Console.WriteLine(mvnxtItor.Current);

        mvnxtItor.MoveNext();
        Console.WriteLine(mvnxtItor.Current);

        mvnxtItor.MoveNext();
        Console.WriteLine(mvnxtItor.Current);

        mvnxtItor.MoveNext();
        Console.WriteLine(mvnxtItor.Current);

        mvnxtItor.MoveNext();
        Console.WriteLine(mvnxtItor.Current);
    }
}