using System;

public class Hello{
    public static void Main(){
        var line = Console.ReadLine();
        var str = line.Split(' ');
        int x = int.Parse(str[0]);
        int a = int.Parse(str[1]);
        int b = int.Parse(str[2]);
        int dist_a = Math.Abs(x-a);
        int dist_b = Math.Abs(x-b);
        if(dist_a > dist_b)Console.WriteLine("B");
        else Console.WriteLine("A");
    }
}
