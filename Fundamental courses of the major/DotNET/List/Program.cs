using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Intrinsics.Arm;
using System.Threading.Tasks;

namespace DotNET
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            List<SV> l2 = new List<SV>();
            SV s1 = new SV {MSSV = "102240251", Name = "Tran Van Huy", Gender = true, BirthDay = new DateTime(2006, 3, 26), GPA = 3.0};
            SV s2 = new SV {MSSV = "102240252", Name = "Tran Thi Huy", Gender = true, BirthDay = new DateTime(2006, 9, 25), GPA = 3.1};
            SV s3 = new SV {MSSV = "102240284", Name = "Que Thi Anh Tu", Gender = true, BirthDay = new DateTime(2006, 11, 28), GPA = 3.5};
            SV s4 = new SV {MSSV = "102240284", Name = "Mai Van Hung", Gender = true, BirthDay = new DateTime(2004, 11, 28), GPA = 2.5};

            l2.Add(new SV {MSSV = "102240251", Name = "Tran Van Huy", Gender = true, BirthDay = new DateTime(2006, 3, 26), GPA = 3.0});
            l2.Add(s1);
            l2.AddRange(new SV[] {s2, s3});

            foreach(SV i in l2)
            {
                Console.WriteLine(i.ToString());
            }

            Console.WriteLine("Index of s1: " + l2.IndexOf(s1));
        }
    }
}