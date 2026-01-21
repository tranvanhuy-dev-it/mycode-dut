using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DotNET
{
    public class BClass : IFile1, IFile2
    {
        public void A1()
        {
            Console.WriteLine("A1-I1");
        }
        public void B1()
        {
            Console.WriteLine("B1-I1");
        }
        public void A2()
        {
            Console.WriteLine("A2-I2");
        }
        public void B2()
        {
            Console.WriteLine("B2-I2");
        }
        public void BC()
        {
            Console.WriteLine("BC-BClass");
        }
    }
}