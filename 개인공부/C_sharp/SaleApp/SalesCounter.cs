using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace SaleApp
{
    
    public class SalesCounter
    {
        private IEnumerable<Sale> _sales;
        public SalesCounter(string filepath)
        {
            _sales = ReadSales(filepath);
        }
        //dict를 이용하여 각 매장의 매출액을 구함 
        public IDictionary<string, int> GetPerStoreSales()
        {
            Dictionary<string,int> dict = new Dictionary<string,int>();
            foreach (Sale sale in _sales) 
            {
                if (dict.ContainsKey(sale.ShopName))
                    dict[sale.ShopName] += sale.Amount;
                else
                    dict[sale.ShopName] = sale.Amount; // 최초값 설정
            }

            return dict;
        }
        private static IEnumerable<Sale> ReadSales(string filePath)
        {
            List<Sale> sales = new List<Sale>();
            string[] lines = File.ReadAllLines(filePath);
            foreach (string line in lines)
            {
                string[] items = line.Split(',');
                Sale sale = new Sale
                {
                    ShopName = items[0],
                    ProductCategory = items[1],
                    Amount = int.Parse(items[2])
                };
                sales.Add(sale);
            }
            return sales;
        }
    }
}
