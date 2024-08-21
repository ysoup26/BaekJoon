using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Declare variables and then initialize to zero.
            double num1 = 0; double num2 = 0;

            //Display title as the C# console calculator app.
            Console.WriteLine("Console Calculator in C#\r");
            Console.WriteLine("------------------------\r");

            //Ask the user to type the first number.
            Console.WriteLine("Type a number, and then press Enter");
            num1 = Convert.ToDouble(Console.ReadLine()); //double32.Parse(a)

            //Ask the user to type the first number.
            Console.WriteLine("Type a number, and then press Enter");
            num2 = Convert.ToDouble(Console.ReadLine());

            //Ask the user to choose an option
            Console.WriteLine("Choose an option from the following list:");
            Console.WriteLine("\ta - Add");
            Console.WriteLine("\ts -subtract");
            Console.WriteLine("\tm - Multiply");
            Console.WriteLine("\td - Divide");
            Console.Write("Your  option? ");

            //Use a switch statement to do the math.
            switch(Console.ReadLine())
            {
                case "a":
                    Console.WriteLine($"Your result: {num1} + {num2} = "+(num1+num2));
                    break;
                case "s":
                    Console.WriteLine($"Your result: {num1} - {num2} = "+(num1-num2));
                    break;
                case "m":
                    Console.WriteLine($"Your result: {num1} * {num2} = "+(num1*num2));
                    break;
                case "d":
                    Console.WriteLine($"Your result: {num1} / {num2} = "+(num1/num2));
                    break;
            }

            //wait for the user to respond before closing.
            Console.Write("Press any key to close the Calculator console app...");
            Console.ReadKey();
        }
    }
}
