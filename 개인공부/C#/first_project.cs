using System; //System 네임스페이스 사용
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1 //네임스페이스 선언
    //공간 선언을 통해 중복되는 이름을 피할 수 있다. 다른 네임스페이스에서 같은 클래스 이름을 지정할 수 있다.
{
    class Car
    {
        private string handle = "AMODEL";
        
        public void carRun()
        {
            Console.WriteLine("자동차를 움직인다.");
        }
    }
    //what is internal?
    internal class Program
    {
        static void Main(string[] args)
        {
            //System네임스페이스의 Console클래스의 writeLine호출ㄹ
            Console.WriteLine("글자찍기");
            //Console.WriteLine("그대로 찍기");
            Car c = new Car();
            c.carRun();
        }
    }
}
