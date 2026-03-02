
using System;

class Program
{
    static void Main()
    {
        Console.Write("Write a: ");
        double a = double.Parse(Console.ReadLine());
        
        Console.Write("Write b: ");
        double b = double.Parse(Console.ReadLine());
        
        Console.Write("Write c: ");
        double c = double.Parse(Console.ReadLine());

        double D = b * b - 4 * a * c;
        if (D < 0)
        {
            Console.WriteLine("No solutions");
        }
        else if (D == 0)
        {
            double x = -b / (2 * a);
            Console.WriteLine("x = " + x);
        }
        else
        {
            double x1 = (-b + Math.Sqrt(D)) / (2 * a);
            double x2 = (-b - Math.Sqrt(D)) / (2 * a);
            Console.WriteLine("x1 = " + x1);
            Console.WriteLine("x2 = " + x2);
        }
    }
}
