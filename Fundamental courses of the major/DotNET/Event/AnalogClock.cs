//Sub
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DotNET
{
    public class AnalogClock
    {
        public void ShowAC(object o, TimeEventArgs e)
        {
            Console.WriteLine("AC: {0}:{1}:{2}:{3}", e.t.Hour, e.t.Minute, e.t.Second, e.t.Millisecond);
        }
    }
}