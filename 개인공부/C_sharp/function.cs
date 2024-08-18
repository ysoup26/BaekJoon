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
            //함수
            int a = 5;
            int b = 6;
            Class1 c1 = new Class1();
            int c = c1.addNumber(a, b);
            c1.soundF();
            Console.WriteLine(c);
        }
        class Class1 //클래스를 추가로 생성하여 함수를 실행시키는 방식
        {
            public int addNumber(int c, int d) //static 접근 제안자
            {
                return c + d;
            }
            public void soundF()
            {
                Console.WriteLine("소리를 냅니다!");
            }
        }

    }
}

