using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DotNET
{
    public class QLSV
    {
        private static QLSV _Instance;
        SV[] list;
        int _Count;

        public int Count
        {
            get
            {
                return this._Count;
            }
            private set {}
        }

        public static QLSV Instance
        {
            get
            {
                if (_Instance == null) _Instance = new QLSV();
                return _Instance;
            }
            private set {}
        }

        private QLSV()
        {
            list = new SV[]
            {
                new SV {MSSV = "102240251", Name = "Tran Van Huy", Gender = true, BirthDay = new DateTime(2006, 3, 26), GPA = 3.5},
                new SV {MSSV = "102240252", Name = "Tran Thi Huy", Gender = true, BirthDay = new DateTime(2006, 9, 25), GPA = 3.5},
                new SV {MSSV = "102240284", Name = "Que Thi Anh Tu", Gender = true, BirthDay = new DateTime(2006, 11, 28), GPA = 3.5}
            };
            _Count = 3;
        }

        public void Add(SV s)
        {
            SV[] newlist = new SV[_Count + 1];
            for (int i = 0; i < _Count; i++)
            {
                newlist[i] = list[i];
            }
            newlist[_Count] = s;
            list = newlist;
            _Count++;
        }

        public void AddRange(SV[] arr)
        {
            int n = arr.Length;
            SV[] newlist = new SV[_Count + n];
            for (int i = 0; i < _Count; i++)
            {
                newlist[i] = list[i];
            }
            for (int i = 0; i < n; i++)
            {
                newlist[_Count + i] = arr[i];
            }

            list = newlist;
            _Count += n;
        }

        public int IndexOf(SV sv)
        {
            int index = -1;
            for (int i = 0; i < _Count; i++)
            {
                if (sv.MSSV == list[i].MSSV)
                {
                    index = i;
                }
            }
            return index;
        }

        public bool RemoveAt(int index)
        {
            int n = list.Length;
            if (index >= n || index < 0)
            {
                return false;
            }    
            for (int i = index; i < n - 1; i++)
            {
                list[i] = list[i+1];
            }
            list[n - 1] = null;
            _Count--;
            return true;
            
        }

        public bool Update(SV s)
        {
            for (int i = 0; i < list.Length; i++)
            {
                if (list[i].MSSV == s.MSSV)
                {
                    list[i] = s;
                    return true;
                }
            }
            return false;
        }

        public string ToString()
        {
            string res = "";
            foreach(SV s in list) 
            {
                res += s.ToString() + "\n";    
            }
            return res;
        }
    }
}