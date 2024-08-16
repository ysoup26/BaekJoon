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
            int[] a = { 1, 2, 3, 4 };
            //int b[4] = { 1, 2, 3, 4 }; //c++은 이렇게
            Console.WriteLine(a.Length);
            Console.WriteLine(a[a.Length-1]); //마지막 값

            //2차원 배열: 1차원 배열 여러개로 구성됨
            int[,] abc = { { 1, 2, 3, }, { 4, 5, 6 } };
            Console.WriteLine(abc[0, 0]);

            //2차원 배열과 가변 배열은 참조 방식이 다르다

            //가변배열: 열 크기가 변할 수 있다.
            int[][] ab = new int[3][]; //앞자리는 알려줘야함
            ab[0] = new int[4]; //값이 아닌 열의 갯수를 알려준 것
            ab[1] = new int[4];
            ab[2] = new int[3];
            ab[0][0] = 1; //초기화 전에는 0이 들어가 있음
            Console.WriteLine(ab[0][0]);// 
            Console.WriteLine("길이는? " + ab[0].Length);

        }
    }
}

