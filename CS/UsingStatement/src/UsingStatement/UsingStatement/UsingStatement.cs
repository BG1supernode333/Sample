using System;
using System.IO;

class FileLoading : IDisposable
{
    private string filename;
    private StreamReader sr = null;
    private string content;
    public FileLoading(string filename)
    {
        this.filename = filename;
        sr = new StreamReader(this.filename);
    }
    public string LoadAll()
    {
        content = sr.ReadToEnd();
        return content;
    }
    public virtual void Dispose()
    {
        sr.Close();
        sr.Dispose();
    }
}

class UsingStatement
{
    static void Main()
    {
        string txt;

        using (FileLoading fl = new FileLoading("test.txt"))
        {
            txt = fl.LoadAll();
        }

        Console.WriteLine("-----start-----");
        Console.WriteLine(txt);
        Console.WriteLine("------end------");
    }
}