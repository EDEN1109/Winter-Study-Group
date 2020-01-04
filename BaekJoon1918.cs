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
            string expression = Console.ReadLine();

            makeStack(expression);

            writeResult();

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

        static void writeResult()
        {
            while (result.Count > 0)
                Console.Write("{0}", result.Dequeue());
        }
    }
}
