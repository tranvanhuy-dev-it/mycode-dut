using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DotNET
{
    public class DClass : IFile1, IFile3
    {
        void IFile1.A1()
        {
            Console.WriteLine("A1-I1");
        }

        void IFile3.A1()
        {
            Console.WriteLine("A1-I3");
        }
        
        public void DC()
        {
            Console.WriteLine("DC-DClass");
        }

        public void B1()
        {
            Console.WriteLine("B1-I1");
        }
        public void B3()
        {
            Console.WriteLine("B3-I3");
        }
    }
}