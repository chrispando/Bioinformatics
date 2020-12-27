using System;
using System.Collections.Generic;
using System.IO;
using System.Windows;

namespace DNASEQUENCES
{
    class Program
    {
        public static void writeToFile(List<string>input)
        {
            Console.WriteLine("Writing to file...");
            using (StreamWriter writer = new StreamWriter("/Users/chrispando/Projects/sequences.txt"))
            {
                foreach (string s in input)
                {
                    writer.WriteLine(s);
                }
            }
            Console.WriteLine("Done.");
        }

        public static List<string> generate(int num, int len)
        {
            char [] nucleotides = {'A','C','G','T' };
            List<string> myVec = new List<string>();
            for(int i=0;i<num;i++)
            {
                string s = "";
                for(int j=0;j<len;j++)
                {
                    var rand = new Random();
                    int r = rand.Next(4);
                    s += nucleotides[r];
                }
                myVec.Add(s);

            }
            return myVec;
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Enter number of sequences:");
            int num = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter length of sequences:");
            int len = Convert.ToInt32(Console.ReadLine());


            List<string> sequences = generate(num, len);
            writeToFile(sequences);
        }
    }
}
