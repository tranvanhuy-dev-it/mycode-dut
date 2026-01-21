using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DotNET
{
    public class SV
    {
        public string MSSV {get; set;}
        public string Name {get; set;}
        public bool Gender {get; set;}
        public DateTime BirthDay {get; set;}
        public double GPA {get; set;}
        public override string ToString()
        {
            return "MSSV: " + MSSV + ", Name: " + Name + ", Gender: " + Gender + ", BirthDay: " + BirthDay + ", GPA: " + GPA;
        }
        public override bool Equals(object? obj)
        {
            if (obj is SV)
            {
                SV other = (SV)obj;
                return this.MSSV == other.MSSV;
            }
            return false;
        }

    }
}