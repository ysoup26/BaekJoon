using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//OOP: 캡슐화와 상속
namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //객체 지향
            Car c1 = new Car();
            Car c2 = new Car();
            
            c1.getHandle();
            c2.handle = "2024HANDLE";
            c2.getHandle();
            
            //캡슐화: 데이터 은닉
            Console.WriteLine(c1.getModel2()); //함수를 통해 private 변수에 접근가능 
            //이런식으로 직접 접근은 x c1.model = "test"; 
        
            //상속
            NewCar  nc1 = new NewCar(); //car로부터 함수와 변수를 상속받았기에
            nc1.getHandle();
            //protect는 상속된 클래스에서만 접근 가능 Console.WriteLine(nc1.a);
            nc1.getA();
        }

    }

    //Car.cs
    class Car
    {
        private string model = "PMODEL";
        public string handle = "ABCMODEL";
        protected string a = "ABC";

        public void getModel()
        {
            Console.WriteLine(model);
        }
        public string getModel2()
        {
            return model;
        }
        public void getHandle()
        {
            Console.WriteLine(handle);
        }

    }
    //NewCar.cs
    class NewCar : Car
    {
        public void getA()
        {
            Console.WriteLine(a);
        }
        public void getM()
        {
            //이와 같이 private는 상속 클래스가 직접 호출할 수 없음
            //Console.WriteLine(model);
        }
    }
}

