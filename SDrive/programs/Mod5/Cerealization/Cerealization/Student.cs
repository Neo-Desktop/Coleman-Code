using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.Serialization;
using System.Xml.Serialization;

namespace Cerealization
{
    /// <summary>
    /// Student class aggregates the following information:
    /// Student ID, First Name, Middle Name, Last Name,
    /// Social Secuirty Number, Address, City, State, Zipcode
    /// and 2 phone numbers
    /// </summary>
    [Serializable]
    public class Student
    {
        public int StudentID { get; set; }
        public string FirstName { get; set; }
        public string MiddleName { get; set; }
        public string LastName { get; set; }
        public SocialSecurityNumber SSN { get; set; }
        public string Address1 { get; set; }
        public string Address2 { get; set; }
        public string City { get; set; }
        public string State { get; set; }
        public ZipCode ZipCode { get; set; }
        public PhoneNumber Phone1 { get; set; }
        public PhoneNumber Phone2 { get; set; }

        public Student(int id, string fn, string mn, string ln, SocialSecurityNumber ssn, string addr1, string addr2, string city, string state, ZipCode zip, PhoneNumber phone1, PhoneNumber phone2)
        {
            StudentID = id;
            FirstName = fn;
            MiddleName = mn;
            LastName = ln;
            SSN = ssn;
            Address1 = addr1;
            Address2 = addr2;
            City = city;
            State = state;
            ZipCode = zip;
            Phone1 = phone1;
            Phone2 = phone2;
        }
        public Student() // default constructor for XMLSerialization
        {

        }
    }
    [Serializable]
    [XmlRoot("Students_XML")]
    public class CStudent
    {
        /// <summary>
        /// The CStudent class is here to allow the XMLSerilizer
        /// access to a List without having to loop thorugh the list
        /// before writing it to a file. - This is essentially a 
        /// glue class.
        /// </summary>

        [XmlAttribute("Count")]
        public int Count { get; set; }
        [XmlArray("Student_List")]
        [XmlArrayItem("Student")]
        public List<Student> Students;

        public CStudent(List<Student> stud)
        {
            Students = new List<Student>();
            Students = stud;
        }

        public CStudent() // default constructor for XMLSerialization
        {
            Students = new List<Student>();
        }

        public void Add(Student s)
        {
            Students.Add(s);
            Count = Students.Count;
        }
    }
}
