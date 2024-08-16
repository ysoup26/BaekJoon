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
            //비교연산자를 이용하여, 코드를 선택 실행
            int a = 5;
            int b = 10;

            Console.WriteLine(a < b);
            if (a < b)
            {
                Console.WriteLine("if문 실행");
            }else if (a < b) 
            {
                Console.WriteLine("if문 실행");
            }else
                Console.WriteLine("if문 실행");
            //하나의 조건문에 걸리면 나머지는 실행되지 않고 아래로 옴

            //삼항연산자도 if문을 이용하는 것에 가까움
            string text = (a < b) ? "a는 b보다 작습니다." : "a는 b보다 큽니다.";
            Console.WriteLine(text);

            //switch문

            int week = 3;
            switch (week)
            {
                case 1: 
                    Console.WriteLine("월요일");
                    break;
                case 2:
                    Console.WriteLine("화요일");
                    break;
                case 3:
                    Console.WriteLine("수요일");
                    break;
                case 4:
                    Console.WriteLine("목요일");
                    break;
                default:
                    Console.WriteLine("해당 x");
                    break;
            }
        }
    }
}

