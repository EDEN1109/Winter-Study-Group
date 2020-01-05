using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace heap
{
    class Program
    {
        static void Main(string[] args)
        {
            string nums = Console.ReadLine();
            int a = Int32.Parse(nums.Split(' ')[0]);
            int b = Int32.Parse(nums.Split(' ')[1]);
            
            Console.WriteLine("{0}", a + b);

            Console.ReadKey();
        }
    }
}
