namespace ProblemSolvingWithCSharp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine());
            while(t > 0) {
                int n = Convert.ToInt32(Console.ReadLine());
                if (n == 1) Console.WriteLine(1);
                else if (n % 2 != 0) Console.WriteLine(-1);
                else
                {
                    Console.Write(n + " " + (n - 1) + " ");
                    for (int i = 2; i < n - 1; i += 2)
                    {
                        Console.Write(i + " " + (n - 1 - i) + " ");
                    }
                    Console.WriteLine();
                }
                t--;
            }
        }
    }
}
