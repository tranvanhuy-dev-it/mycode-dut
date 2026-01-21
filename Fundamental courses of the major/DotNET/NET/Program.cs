using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Threading.Tasks;

namespace NET
{
    public static class Program
    {
        //dung ref khi da khoi tao gia tri
        // public static void HV(ref int a, ref int b)
        // {
        //     int temp = a;
        //     a = b;
        //     b = temp;
        // }
        // //dung out khi chua khoi tao gia tri
        // public static void A(out int t) 
        // {
        //     t = 5;
        // }
        public static void Main(string[] args)
        {
            // int x, y;
            // Console.Write("Nhap x: ");
            // x = Convert.ToInt32(Console.ReadLine());
            // Console.Write("Nhap y: ");
            // y = Convert.ToInt32(Console.ReadLine());
            // HV(ref x, ref y);
            // Console.WriteLine("x = {0}, y = {1}", x, y);
            // int z;
            // A(out z);
            // Console.WriteLine("z = {0}", z);

            //MANG MOT CHIEU
            // string[] D = new string[4];
            // for (int i = 0; i < 4; i++)
            // {
            //     Console.Write("D[{0}] = ", i);
            //     D[i] = Console.ReadLine();
            // }

            // for (int i = 0; i < 4; i++)
            // {
            //     Console.Write("{0} ", D[i]);
            // }

            // Console.WriteLine();

            // foreach(string i in D)
            // {
            //     Console.Write("{0} ", i);
            // }

            //MANG HAI CHIEU
            // string[][] softwares = new string[3][];
            // softwares[0] = new string[] {"a", "b", "c"};
            // softwares[1] = new string[] {"d", "e", "f"};
            // softwares[2] = new string[] {"g", "h", "i"};
            // for (int i = 0; i < softwares.GetLength(0); i++)
            // {
            //     for (int j = 0; j < softwares[i].GetLength(0); j++)
            //     {
            //         Console.WriteLine(softwares[i][j]);
            //     }
            // }
            // foreach(string[] arr in softwares)
            // {
            //     foreach(string s in arr)
            //     {
            //         Console.WriteLine(s);
            //     }
            // }

            // double[,] matrix = new double[10, 10];
            // int count = 0;
            // for (int i = 0; i < 10; i++)
            // {
            //     for (int j = 0; j < 10; j++)
            //     {
            //         matrix[i, j] = ++count;
            //     }
            // }
            // foreach(double d in matrix)
            // {
            //     Console.Write(d + " ");
            // }
        }
    }
}