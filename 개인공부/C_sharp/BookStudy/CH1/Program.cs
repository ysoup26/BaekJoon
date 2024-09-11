namespace Chap1
{
    using System;

    class Program
    {
        static void Main(string[] args)
        {
            // 문제 1.1
            Console.WriteLine("[문제 1.1]");
            Product pulbbang = new Product(98, "풀빵", 210);
            Console.WriteLine("{0} : {1}", pulbbang.Name, pulbbang.GetPriceIncludingTax());

            // 문제 1.2
            Console.WriteLine("\n[문제 1.2]");
            MyClass c = new MyClass { X = 10, Y = 10 };
            MyStruct s = new MyStruct { X = 10, Y = 10 };
            PrintObjects(c, s);
            Console.WriteLine("MyClass: {0}, {1}", c.X, c.Y);
            Console.WriteLine("MyStruct: {0}, {1}", s.X, s.Y); // struct는 함수에 의해 변하지 않았음. 값 자체가 저장되어 있기 때문에

            // 문제 1.3
            Console.WriteLine("\n[문제 1.3]");
            Student s1 = new Student { Name = "홍길동", Birthday = new DateTime(1992, 4, 5), Grade = 5, ClassNumber = 1 };
            Console.WriteLine("이름: {0} 생일: {1} 학년: {2} 반: {3}", s1.Name, s1.Birthday, s1.Grade, s1.ClassNumber);
            Person p = s1; // Student의 부모 클래스이고
            object o = s1; // 클래스의 부모 클래스이기 때문에
        }
        static void PrintObjects(MyClass c, MyStruct s)
        {
            c.X *= 2;
            c.Y *= 2;
            s.X *= 2;
            s.Y *= 2;
            Console.WriteLine("MyClass: {0}, {1}", c.X, c.Y);
            Console.WriteLine("MyStruct: {0}, {1}", s.X, s.Y);
        }
        
        /*상속*/

        // 공통적인 모듈의 특징을 big_module에
        class big_module
        {
            int id;
        }
        // 세부적인 내용을 자식 클래스에서
        class samll_module : big_module
        {
            int other_id;


        }

    }
}
