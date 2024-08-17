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
            //while문
            int i = 0;
            while(i<6){ //괄호가 참일때 실행됨
                Console.WriteLine("i의 값 "+i);
                i++;
            }

            //do-while문: 한번은 무조건 실행
            i = 0;
            do{
                Console.WriteLine("출력");
                i++;
            }while(i<1);

            //for문
            for(i =0;i<6;i++){
                Console.WriteLine("i의 값 "+i);
            }

            //foreach
            string[] strs = {"바나나","사과","파인애플","망고"};

            foreach(string i in strs){
                Console.WriteLine(i);
            }
        }
    }
}

