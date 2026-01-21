using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DotNET
{
    public class AClass : IFile1
    {
        public void A1()
        {
            Console.WriteLine("A1-I1");
        }
        public void B1()
        {
            Console.WriteLine("B1-I1");
        }
        public void AC()
        {
            Console.WriteLine("AC-AClass");
        }
    }
}