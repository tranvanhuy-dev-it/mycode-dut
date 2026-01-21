using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DotNET
{
    public class CClass : IFile1, IFile3
    {
        public void A1()
        {
            Console.WriteLine("A1-I1_I3");
        }

        public void B1()
        {
            Console.WriteLine("B1-I1");
        }
        public void B3()
        {
            Console.WriteLine("B3-I3");
        }
        public void CC()
        {
            Console.WriteLine("CC-CClass");
        }

    }
}