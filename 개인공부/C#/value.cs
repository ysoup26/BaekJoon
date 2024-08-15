using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*자료형 종류
            int, long, short, byte, float, double, string, char 
            */
            float f1 = 0.0005F; //or 0.0005f
            double d1 = 0.000005d; //or 0.000005; or 0.000005D;

            int a = 5 ; 
            int b = 6;
            b = a;
            string c = "";
            //형 변환을 통해 문자타입에 숫자를 저장
            c = a.ToString();
            Console.WriteLine(c);
            //문자를 숫자타입으로 변경해서 저장
            a = Int32.Parse(c);
            Console.WriteLine(a);
        }
    }
}

