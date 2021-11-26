using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace qwebBridge
{

    public class Ultrabrowse
    {
        //pinvokes
        #region Pinvokes 

        [DllImport("qweb.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        static extern void loadlink([MarshalAs(UnmanagedType.LPStr)] string link, IntPtr ultrainstance);

        [DllImport("qweb.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        static extern void start(IntPtr ultrainstance);

        [DllImport("qweb.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        static extern void update(IntPtr ultrainstance);

        [DllImport("qweb.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr ultraInstance();

        [DllImport("qweb.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        static extern void takescreenshoot(IntPtr ultrainstance);

        [DllImport("qweb.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        static extern bool loaded(IntPtr ultrainstance);

        #endregion

        private string links; // field
        public string Links   // property
        {
            get { return links; }
            set { links = value; }
        }

        public bool LinksLoaded()   // property
        {
           return loaded(bridge);
        }

        private IntPtr bridge;
        public  Ultrabrowse()
        {
            bridge = ultraInstance();
        }

        public void browsetolink()
        {
            loadlink(links, bridge);
        }
        public void init()
        {
            start(bridge);
        }
        public void updates()
        {
            update(bridge);
        }
        public void takescreenshot()
        {
            takescreenshoot(bridge);
        }
    }
}
