using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Chap1
{
    public class Product
    {
        public int Code { get; set; }
        public string Name { get; set; }
        public int Price { get; set; }

        public Product() { }
        public Product(int code, string name, int price)
        {
            Code = code;
            Name = name;
            Price = price;
        }
        public int GetTax() { 
            return (int)(Price * 0.08); 
        }
        public int GetPriceIncludingTax() { 
            return Price + GetTax(); 
        }
    }
}
