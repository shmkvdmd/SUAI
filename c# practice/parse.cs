using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hmaz2123
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string name;
            int age;
            double height, score_h,score_m,score_r,score;
            string pattern = "Имя: {0}\nВозраст: {1}\nРост: {2}\nСредний балл: {3}";
            Console.WriteLine("Введите имя пользователя: ");
            name = Console.ReadLine();
            Console.WriteLine("Введите возраст пользователя: ");
            age = int.Parse(Console.ReadLine());
            Console.WriteLine("Введите рост пользователя: ");
            height = double.Parse(Console.ReadLine());
            Console.WriteLine("Введите балл по истории: ");
            score_h = double.Parse(Console.ReadLine());
            Console.WriteLine("Введите балл по математике: ");
            score_m = double.Parse(Console.ReadLine());
            Console.WriteLine("Введите балл по русскому языку: ");
            score_r = double.Parse(Console.ReadLine());
            score = (score_h + score_m + score_r) / 3;
            string score_format = score.ToString("#.###");
            int screenWidth = Console.WindowWidth;
            int screenHeight = Console.WindowHeight;
            string[] lines = string.Format(pattern, name, age, height, score_format).Split('\n');
            int topMargin = (screenHeight - lines.Length) / 2;
            foreach (string line in lines)
            {
                int leftMargin = (screenWidth - line.Length) / 2;
                Console.SetCursorPosition(leftMargin, topMargin);
                Console.WriteLine(line);
                topMargin++;
            }
            Console.ReadKey();
        }
    }
}
