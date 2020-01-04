using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace postfix_notation
{
    class Program
    {
        private static Stack<char> operators = new Stack<char> ();
        private static Queue<char> result = new Queue<char> ();

        static void Main(string[] args)
        {
            int oprandSize = Int32.Parse(Console.ReadLine());
            string expression = Console.ReadLine();

            for(int i = 0; i < expression.Length; i++)
            {
                result.Enqueue(expression[i]);
            }

            List<int> values = new List<int>();

            for(int i = 0; i < oprandSize; i++)
            {
                values.Add(Int32.Parse(Console.ReadLine()));
            }

            // makeStack(expression);
            // writeResult();
            calculResult(values);

            System.Console.ReadKey();
        }

        static void makeStack(string expression)
        {
            for(int i = 0; i < expression.Length; i++)
            {
                char c = expression[i];

                if (c == '+' || c == '-')
                {
                    while(operators.Count > 0 && operators.Peek() != '(')
                    {
                        result.Enqueue(operators.Pop());
                    }
                    
                    operators.Push(c);
                }
                else if (c == '*' || c == '/')
                {
                    while (operators.Count > 0 && operators.Peek() != '(' && operators.Peek() != '+' && operators.Peek() != '-')
                    {
                        result.Enqueue(operators.Pop());
                    }
                    operators.Push(c);
                }
                else if (c == '(')
                {
                    operators.Push(c);
                }
                else if (c == ')')
                {
                    while(operators.Peek() != '(')
                    {
                        result.Enqueue(operators.Pop());
                    }
                    operators.Pop();
                }
                else
                {
                    result.Enqueue(c);
                }
            }

            while(operators.Count > 0)
            {
                result.Enqueue(operators.Pop());
            }
        }

        static void calculResult(List<int> values)
        {
            Stack<double> nums = new Stack<double>();
            List<char> alpha = new List<char>();

            while (result.Count > 0)
            {
                char c = result.Dequeue();

                if (c == '+')
                {
                    double one = nums.Pop();
                    double two = nums.Pop();
                    double answer = two + one;
                    nums.Push(answer);
                }
                else if (c == '-')
                {
                    double one = nums.Pop();
                    double two = nums.Pop();
                    double answer = two - one;
                    nums.Push(answer);
                }
                else if (c == '*')
                {
                    double one = nums.Pop();
                    double two = nums.Pop();
                    double answer = two * one;
                    nums.Push(answer);
                }
                else if (c == '/')
                {
                    double one = nums.Pop();
                    double two = nums.Pop();
                    double answer = two / one;
                    nums.Push(answer);
                }
                else
                {
                    if(alpha.Contains(c) == true)
                    {
                        nums.Push(values[alpha.IndexOf(c)]);
                    }
                    else
                    {
                        nums.Push(values[alpha.Count]);
                        alpha.Add(c);
                    }
                }
            }

            while(nums.Count > 0)
                Console.Write("{0:0.00}", nums.Pop());
        }

        static void writeResult()
        {
            while (result.Count > 0)
                Console.Write("{0}", result.Dequeue());
        }
    }
}
