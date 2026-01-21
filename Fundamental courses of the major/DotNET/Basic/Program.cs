using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DotNET
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            SV sv1 = new SV {MSSV = "102240259", Name = "Nguyen Thai An", Gender = true, BirthDay = new DateTime(2006, 3, 26), GPA = 3.5};
            (QLSV.Instance).Add(sv1);
            Console.WriteLine((QLSV.Instance).ToString());
            Console.WriteLine("-----");

            SV[] arr = new SV[]
            {
                new SV {MSSV = "102240551", Name = "Tran Van Cuong", Gender = true, BirthDay = new DateTime(2006, 3, 26), GPA = 3.5},
                new SV {MSSV = "102240277", Name = "Le Thi Tam", Gender = false, BirthDay = new DateTime(2005, 3, 26), GPA = 3.8}
            };
            (QLSV.Instance).AddRange(arr);
            Console.WriteLine((QLSV.Instance).ToString());
            Console.WriteLine("-----");

            Console.WriteLine("Index: " + (QLSV.Instance).IndexOf(sv1));

            Console.WriteLine("-----");
            if ((QLSV.Instance).RemoveAt(3))
            {
                Console.WriteLine("Remove: Sucessful");
            } else
            {
                Console.WriteLine("Remove: Error");
            }


            Console.WriteLine("-----");
            SV sv2 = new SV {MSSV = "102240251", Name = "Tran Van Huy", Gender = true, BirthDay = new DateTime(2006, 3, 26), GPA = 3.9};
            if ((QLSV.Instance).Update(sv2))
            {
                Console.WriteLine("Update: Sucessful");
            } else
            {
                Console.WriteLine("Update: Error");
            }
        }
    }
}