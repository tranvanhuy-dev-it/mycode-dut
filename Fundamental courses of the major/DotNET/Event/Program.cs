using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Net.WebSockets;
using System.Threading.Tasks;

namespace DotNET
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            Clock c = new Clock();
            AnalogClock ac = new AnalogClock();
            DigitalClock dc = new DigitalClock();

            c.OnSecondChanged += new Clock.EventHandler(ac.ShowAC);
            c.OnSecondChanged += new Clock.EventHandler(dc.ShowDC);

            c.Run();
            }
    }
}