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
            //단항연산자
            int a = 5;
            a--;
            Console.WriteLine(-a);
            
            //이항연산자
            int b = 3;
            int c = 0;

            c = a - b;
            Console.WriteLine(c);
            
            //삼항연산자
            int d = (5 > 3) ? 2 : 0;
            Console.WriteLine(d);

            //대입연산자
            a = b;
            Console.WriteLine(a);

            //사칙연산자
            c = a + b;
            c = a - b;
            c = a * b;
            c = a / b;
            //+)나머지연산자
            c = a % b;

            //증감연산자(전위후위)
            Console.WriteLine(a++);
            Console.WriteLine(a);

            //복합대입연산자
            a += 1;
            b *= 3;

            //비교연산자
            bool result = a == b;
            Console.WriteLine(result);
            result = a > b;
            Console.WriteLine(result);
            result = a < b;
            Console.WriteLine(result);
            result = a != b; 
            Console.WriteLine(result);

            //조건연산자
            c = (a>b) ? 1 : 0;
            Console.WriteLine(c);

            //논리연산자
            bool result1 = true;
            bool result2 = false;
            Console.WriteLine(!result1);
            Console.WriteLine(result1 && result2);
            Console.WriteLine(result1 || result2);

            //비트연산자: 2진수로 계산
            a = 2; // 0010
            b = 5; // 0101
            c = 7; // 0111
            Console.WriteLine(a << 1); //곱하기 나누기 효과가 나온다
            Console.WriteLine(b >> 1);
            Console.WriteLine(a & b); //(and)
            Console.WriteLine(a | b); //or
            Console.WriteLine(a ^ b); //nor
        }
    }
}

