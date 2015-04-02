using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using System.Xml.Serialization;
using System.Runtime.Serialization;
using System.IO;
using System.Diagnostics;

namespace Cerealization
{
    public partial class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("            -=Coffee and cerealization=-\n                 ( ) ;\n                ;)( ;\n               :----:     o8Oo./\n              C|====| ._o8o8o8Oo_.\n               |    |  \\========/\n               `----'   `------'\n");
            int HighOrder = RandNumber(10, 101); // 100 students as the maximum
            Console.WriteLine("Generating {0} students...", HighOrder);
            CStudent students = new CStudent();

            for (int i = 0; i < HighOrder; i++)
            {
                // do the thing.
                students.Add(new Student(i + 1, GenerateFirstName(), GenerateFirstName(), GenerateLastName(), GenerateSSN(), GenerateAddr(), "", GenerateCity(), GenerateState(), GenerateZipCode(), GeneratePhoneNumber(), GeneratePhoneNumber()));
            }

            XmlSerializer serializer = new XmlSerializer(typeof(CStudent));
            TextWriter writer = new StreamWriter("Students.xml");
            serializer.Serialize(writer, students);
            writer.Close();
            Console.WriteLine("Students.xml written!");
            Console.WriteLine("Press enter to open in Notepad++");
            Console.ReadLine();
            Process.Start("notepad++", string.Format("\"{0}\\{1}\"", Directory.GetCurrentDirectory(), "Students.xml"));
        }
    }
}
