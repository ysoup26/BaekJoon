using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace SaleApp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var sales = new SalesCounter("sales.csv");
            var amountPerStore  = sales.GetPerStoreSales();
            foreach(var obj in amountPerStore)
            {
                Console.WriteLine("{0} {1}",obj.Key,obj.Value);
            }
        }
        
    }
    
}
