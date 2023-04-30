    using System;

    public class Program
    {
        // function to check if a number is strongly composite
        static void solve(int t)
        {
            for (int i = 0; i < t; i++)
            {
                int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
                string manager = "";
                int answer = 0;
                for (int j = 0; j < a[0]; j++)
                {
                    string s = Console.ReadLine();
                    if (j == 0) manager = s;
                    else
                    {
                        if (s == manager) answer++;
                    }
                }
                Console.WriteLine(answer + 1);
            }
        }
   
        public static void Main()
        {
            int t = int.Parse(Console.ReadLine());
            solve(t);

        }
    }
