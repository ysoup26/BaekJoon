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
            //객체 지향

            //다형성
            //같은 함수라도 다른 출력 결과를 보임
            Animal animal = new Animal();
            animal.PlaySound();

            Dog d = new Dog();
            d.PlaySound();

            Owl o = new Owl();  
            o.PlaySound();

            Animal a = new Animal();
            a = new Dog(); //하위 클래스의 영향을 받음
            a.PlaySound();

            //반대는 안됨
            Dog d2 = new Dog();
            //d2 = new Animal();
        }

    }
    //Animal.cs
    class Animal
    {
        public virtual void PlaySound()
        {
            Console.WriteLine("동물 소리를 냅니다.");
        }
    }
    //Dog.cs
    class Dog : Animal
    {
        public override void PlaySound()
        {
            Console.WriteLine("강아지는 멍멍");
        }
    }
    //Owl.cs
    class Owl : Animal
    {
        public override void PlaySound()
        {
            Console.WriteLine("부엉이는 부엉부엉");
        }
    }
}

