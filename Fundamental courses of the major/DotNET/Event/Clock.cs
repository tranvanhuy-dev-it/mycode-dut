//Pub
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DotNET
{
    public class Clock
    {
        //Khai bao kieu delegate gan voi su kien
        public delegate void EventHandler(object o, TimeEventArgs e);
        //Khai bao su kien
        public event EventHandler OnSecondChanged;
        public void Run()
        {
            while(true)
            {
                Thread.Sleep(1000);
                OnSecondChanged(this, new TimeEventArgs() { t = DateTime.Now });
            }
        }
    }
}