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
        static void Main(string[] args)
        {
           
            try
            {
                Ultrabrowse ub= new Ultrabrowse();
                ub.init();
                ub.Links = "https://www.google.com/";
                ub.browsetolink();
                while (!ub.LinksLoaded())
                {
                   ub.updates();
                }
                ub.takescreenshot();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
           
                
            Console.ReadKey();
        }
    }
}
