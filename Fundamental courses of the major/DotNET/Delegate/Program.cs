using System;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.Linq;
using System.Runtime.Intrinsics.Arm;
using System.Threading.Tasks;

namespace DotNET
{
    public static class Program
    {
        // public delegate int M(int a, int b);
        // public static int Sum(int a, int b)
        // {
        //     return a + b;
        // }

        // public static int Sub(int a, int b)
        // {
        //     return a - b;
        // }

        // public static int TT(int a, int b, M m)
        // {
        //     return m(a, b);
        // } 

        // public delegate void M1(int a, int b);
        // public static void Sum1(int a, int b)
        // {
        //     Console.WriteLine("Sum: " + (a + b));
        // }

        // public static void Sub1(int a, int b)
        // {
        //     Console.WriteLine("Sub: " + (a - b));
        // }

        // public static void TT1(int a, int b, M1 m)
        // {
        //     m(a, b);
        // } 

        public delegate bool N(object o1, object o2);
        public static void SX(object[] arr, N cmp)
        {
            for (int i = 0; i < arr.Length - 1; i++)
            {
                for (int j = i + 1; j < arr.Length; j++)
                {
                    if (cmp(arr[i], arr[j]))
                    // if (SV.Cmp_Name(arr[i], arr[j]))
                    {
                        object temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
        public static void Main(string[] args)
        {
            // M1 d1 = new M1(Sum1);
            // d1 += new M1(Sub1);
            // d1 += new M1(Sub1);

            // d1 -= new M1(Sub1);

            // TT1(10, 5, d1);
            // Console.WriteLine("Sum: " + d1(10, 5) + " " + d1(10, 5) + " " + d1.Invoke(10, 5));
            // Console.WriteLine("{0} {1} {2} ", TT(10, 5, d1), TT(10, 5, Sum), TT(10, 5, Sub));
            SV[] A = new SV[]
            {
                new SV {MSSV = "102240251", Name = "Tran Van Huy", Gender = true, BirthDay = new DateTime(2006, 3, 26), GPA = 3.0},
                new SV {MSSV = "102240252", Name = "Tran Thi Huy", Gender = true, BirthDay = new DateTime(2006, 9, 25), GPA = 3.1},
                new SV {MSSV = "102240284", Name = "Que Thi Anh Tu", Gender = true, BirthDay = new DateTime(2006, 11, 28), GPA = 3.5},
                new SV {MSSV = "102240284", Name = "Mai Van Hung", Gender = true, BirthDay = new DateTime(2004, 11, 28), GPA = 2.5}
            };

            SX(A, SV.Cmp_GPA);
            foreach(SV i in A)
            {
                Console.WriteLine(i.ToString());
            }
        }
    }
}