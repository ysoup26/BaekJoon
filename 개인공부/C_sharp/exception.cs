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
            //예외처리
            string a = "";
            a = Console.ReadLine();
            //Console.WriteLine(a);

            try //오류가 발생할 가능성이 높거나 중요한 부분에
            {
                int[] asd = { 0, 1, 2, 3 };

                Console.WriteLine(asd[Int32.Parse(a)]); //범위를 넘어서면 오류발생(처리되지 않은 예외 발생)
                throw new Exception("임의로 예외를 넣어주는 방법"); //강제로 예외처리 발생
            }
            catch(IndexOutOfRangeException e) //특정 오류만을 catch할 수 있음
            {
                //index아웃이 발생했을때는 이곳이 실행
                Console.WriteLine("오류가 발생했을때 실행되는 영역!");
                Console.WriteLine("" + e.ToString());
            }
            catch (Exception e)
            {
                Console.WriteLine("오류가 발생했을때 실행되는 영역");
                Console.WriteLine("" + e.ToString());
            }
            finally
            {
                Console.WriteLine("오류가 발생하든 안하든 실행되는 영역");
            }
            
        }
    }
}

