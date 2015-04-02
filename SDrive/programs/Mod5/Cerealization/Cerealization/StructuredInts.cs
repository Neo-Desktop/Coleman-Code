// Structured ints for things that are structured.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cerealization
{
    [Serializable]
    public class PhoneNumber
    {
        ///<summary>
        /// phone numbers are composed of three parts:
        /// area code, phone prefix, line number
        /// this aggregates all three
        ///</summary>
        public int AreaCode { get; set; }
        public int Prefix { get; set; }
        public int LineNumber { get; set; }
        
        new public string ToString
        {
            get
            {
                return string.Format("({0:D3}) {1:D3}-{2:D4}",AreaCode,Prefix,LineNumber);
            }
            set
            {
                
            }
        }

        public PhoneNumber(int area, int pre, int line)
        {
            AreaCode = area;
            Prefix = pre;
            LineNumber = line;
        }
        public PhoneNumber() // default constructor for XMLSerialization
        {

        }
    }
    [Serializable]
    public class SocialSecurityNumber
    {
        ///<summary>
        /// Social Security Numbers are composed of 3 parts
        /// Group 1 - 3 digits
        /// Group 2 - 2 digits
        /// Group 3 - 4 digits
        /// this class aggregates all groups
        ///</summary>
        public int GroupOne { get; set; }
        public int GroupTwo { get; set; }
        public int GroupThree { get; set; }

        new public string ToString
        {
            get
            {
                return string.Format("{0:D3}-{1:D2}-{2:D4}", GroupOne, GroupTwo, GroupThree);
            }
            set
            {

            }
        }

        public SocialSecurityNumber(int g1, int g2, int g3)
        {
            GroupOne = g1;
            GroupTwo = g2;
            GroupThree = g3;
        }
        public SocialSecurityNumber() // default constructor for XMLSerialization
        {

        }
    }
    [Serializable]
    public class ZipCode
    {
        /// <summary>
        /// Zipcodes are composed of 3 parts
        /// Zip code - Maximum of 5 digits
        /// Plus four code - maximum of 4 digits
        /// this class aggregates all parts
        /// </summary>
        public int Zip { get; set; }
        public int PlusFour { get; set; }

        new public string ToString
        {
            get
            {
                return string.Format("{0:D5}-{1:D4}", Zip, PlusFour);
            }
            set
            {
                
            }
        }

        public ZipCode(int zip, int four)
        {
            Zip = zip;
            PlusFour = four;
        }
        public ZipCode() // default constructor for XMLSerialization
        {

        }
    }
}
