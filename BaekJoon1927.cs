using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace heap
{
    class Program
    {
        private static int size;
        private static int heapSize = 0;
        private static int[] heap;
        private static int[] enters;
        static void Main(string[] args)
        {
            size = Int32.Parse(Console.ReadLine());
            heap = new int[size + 1];
            enters = new int[size];

            initEnters();
            process();

            Console.ReadKey();
        }

        static void initEnters()
        {
            for (int i = 0; i < size; i++)
                enters[i] = Int32.Parse(Console.ReadLine());
        }

        static void process()
        {
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < size; i++)
            {
                if (enters[i] == 0)
                {
                    if (heapSize == 0)
                    {
                        sb.Append(heap[0]+"\n");
                    }
                    else
                    {
                        sb.Append(heap[1] + "\n");
                        removeHeap();
                    }
                }
                else
                {
                    createHeap(enters[i]);
                }
            }
            Console.WriteLine(sb.ToString());
        }

        static void createHeap(int num)
        {
            heap[++heapSize] = num;

            int parent = heapSize / 2;
            int now = heapSize;

            while (heap[now] < heap[parent])
            {
                int temp = heap[now];
                heap[now] = heap[parent];
                heap[parent] = temp;

                now = parent;
                parent = parent / 2;
            }
        }

        static void removeHeap()
        {
            heap[1] = heap[heapSize--];

            int count = 1;

            while (count * 2 <= heapSize)
            {
                int left = heap[count * 2];
                int right = -1;

                if (count * 2 + 1 <= heapSize)
                    right = heap[count * 2 + 1];

                if (right == -1 || left < right)
                {
                    if (heap[count] > left)
                    {
                        heap[count * 2] = heap[count];
                        heap[count] = left;
                        count = count * 2;
                    }
                    else
                        break;
                }
                else
                {
                    if (heap[count] > right)
                    {
                        heap[count * 2 + 1] = heap[count];
                        heap[count] = right;
                        count = count * 2 + 1;
                    }
                    else
                        break;
                }
            }

        }
    }
}