using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace qwebBridge
{
    class Program
    {
    
        [DllImport("qweb.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        static extern void loadlink([MarshalAs(UnmanagedType.LPStr)] string link,IntPtr ultrainstance);

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

        [STAThread]
        static void Main(string[] args)
        {
            try
            {
                IntPtr ultrin= ultraInstance();
                start(ultrin);
                loadlink("https://www.google.com/",ultrin);
                while (!loaded(ultrin))
                {
                    update(ultrin);
                }
                takescreenshoot(ultrin);
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.ReadKey();
        }
    }
}
