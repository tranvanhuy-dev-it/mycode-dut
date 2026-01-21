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

        public static bool Cmp_GPA(object o1, object o2)
        {
            return ((SV)o1).GPA > ((SV)o2).GPA;
        }

        public static bool Cmp_Name(object o1, object o2)
        {
            if (String.Compare(((SV)o1).Name, ((SV)o2).Name) > 0)
            {
                return true;
            }
            return false;
        }
        // public override bool Equals(object? obj)
        // {
        //     if (obj is SV)
        //     {
        //         SV other = (SV)obj;
        //         return this.MSSV == other.MSSV;
        //     }
        //     return false;
        // }

    }
}