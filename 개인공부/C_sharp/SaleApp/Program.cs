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
            SalesCounter sales = new SalesCounter("sales.csv");
            Dictionary<string,int> amountPerStore  = sales.GetPerStoreSales();
            foreach(KeyValuePair<string,int> obj in amountPerStore)
            {
                Console.WriteLine("{0} {1}",obj.Key,obj.Value);
            }
        }
        
    }
    
}
