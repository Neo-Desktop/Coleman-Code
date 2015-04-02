/*****************************************************************************
* Project: 2 - Payroll                                                       *
* Description: Implement a payroll system using abstract classes             *
* Author: Amrit Panesar - 77260                                              *
* License: Public Domain                                                     *
* File description: Houses the random functions found in the file Program.cs *
* The functions RandNumber(), RandDouble(), GenerateFirstName(), and         *
* GenerateLastName() can all be found in this file.                          *
* For further description please see ARCHITECTURE2.txt                       *
*****************************************************************************/

using System;
using System.Globalization;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Project3
{
    public partial class Program
    {
        // generate a random number from 0 to the maximum value an integer can hold. Positive values.
        public static int RandNumber(int Low = 0, int High = int.MaxValue)
        {
            Random rndNum = new Random(int.Parse(Guid.NewGuid().ToString().Substring(0, 8), NumberStyles.HexNumber));
            int rnd = rndNum.Next(Low, High);
            return rnd;
        }

        // generate a random floating point double. positive values.
        public static double RandDouble()
        {
            Random rndNum = new Random(int.Parse(Guid.NewGuid().ToString().Substring(0, 8), NumberStyles.HexNumber));
            double rnd = rndNum.NextDouble() * 28;
            if (rnd < 20) // make all numbers greater than 20.
            {
                rnd *= RandDouble();
            }
            return rnd;
        }

        // grab a random firstname from this string array.
        public static string GenerateFirstName()
        {
            string[] firstnames = { "Librada","Jeanne","Krishna","Roni","Kisha","Edison","Freda","Jed","Lorraine","Nelda","Corine","Lien","Daisy","Gita","Suzy","Gwyneth","Krysta","Erinn","Samual","Barney","Rosia","Malik","Franchesca","Cherryl","Ricardo","Inga","Lesley","Kory","Jaunita","Lacey","Chelsie","Kera","Isaac","Aracely","Delmy","Maggie","Rolland","Estela","Otha","Arturo","Devona",
                                "Wilton","Karey","Hillary","Jared","Tiffiny","Boris","Flavia","Rivka","Casimira","Adria","Odette","Wilbert","Xuan","Allyson","Rosendo","Elijah","Tad","Malisa","Kayleen","Jone","Reina","Laraine","Len","Leora","Fred","Sydney","Sona","Thuy","Sage","Sixta","Joseph","Chantell","Kiesha","Kacie","Maryellen","Fidelia","Anastasia","Stephaine","Johanne","Charlesetta",
                                "Crista","Jarod","Sherrell","Sebrina","Juliet","Charise","Candida","Jonnie","Daine","Jong","Maida","Danilo","Jeneva","Margret","Domenic","Luanna","Nana","Salley","Hipolito","Sanjuanita","Giuseppina","Domonique","Shayla","Melva","Leora","Ashleigh","Ruben","Delbert","Evelina","Jeanie","Margarett","Marcie","Assunta","Latoria","Jodie","Kenisha","Anamaria","Shirleen",
                                "Ashton","Yan","Fanny","Vanita","Marlyn","Maryland","Shandi","Adolph","Amina","Manuel","Dawne","Cristine","Alberto","Tabetha","Frida","Awilda","Louann","Karly","Dede","Kristina","Sue","Elissa","Jamika","Margret","Ninfa","Louisa","Vinita","Gigi","Quinn","Maricruz","Jeanmarie","Niesha","Marquita","Hertha","Shawnna","Jetta","Kristel","Shaunta","Kiyoko","Alana","Eduardo",
                                "Trish","Willa","Darline","Ching","Rosenda","Rufus","Kraig","Tia","Keely","Markita","Georgann","Nicola","Judy","Ignacio","Shantay","Cicely","Astrid","Ladawn","Nia","Babara","Deidre","Geoffrey","Leilani","Lamont","Delphine","Harrison","Anjanette","Zona","Carmen","Hui","Luvenia","Leeann","Marybelle","Shanon","Nicky","Carlene","Laquanda","Aldo","Larisa","Tony",
                                "Madeleine","Garnett","Shae","Shemika","Erich","Celestina","Foster","Kaitlyn","Mariela","Noe","Rafael","Jesusa","Cole","Lettie","Sherill","Trey","Marg","Shaunda","Randell","Piedad","Marjorie","Verena","Elicia","Mika","Colette","Corene","Veronika","Jerrie","Rosie","Georgene","Serafina","Sherman","Susannah","Annamae","Michell","Kelsey","Rosario","Carolina","Jeanie",
                                "Lyndia","Ora","Herta","Santa","Erline","Karmen","Griselda","Maud","Linnie","Nicholle","Mistie","Jordan"};
            // use the positive random number function above, mod'd by the length to grab a random value
            return (firstnames[RandNumber() % firstnames.Length]);
        }

        // grab a random lastname from this string array.
        public static string GenerateLastName()
        {
            string[] lastnames = { "Ives","Dole","Bechtel","Gilfillan","Fahey","Montrose","Harvin","Arvizo","Letarte","Reidhead","Ahlstrom","Hyneman","Reynoso","Douglass","Prato","Mccutchen","Mohl","Sperry","Greb","Cabell","Laramore","Fujiwara","Arpin","Brumfield","Fortin","Markell","Ballengee","Sanluis","Trickey","Haake","Zirkle","Gaines","Ahern","Lafond","Jude","Robie","Runion","Runyan","Futrell",
                               "Rather","Kinloch","Rugg","Senecal","Vanhook","Vallance","Stillwell","Haldeman","Thrush","Shomo","Valerius","Cazares","Townley","Rakestraw","Agar","Meinecke","Coll","Redick","Saint","Spight","Mcnaught","Gayman","Yerger","Rivero","Fabela","Wilhoite","Middlebrooks","Jefferys","Massie","Reichel","Lobb","Ristow","Rucks","Heckard","Hosmer","Dingess","Schamber","Hesson",
                               "Torbett","Goldschmidt","Hayter","Shew","Ugalde","Vicknair","Danks","Tate","Delorme","Ormand","Laughton","Wilkerson","Dickson","Mulvey","Junkin","Camacho","Barsh","Recker","Farnsworth","Gary","Drees","Knoles","Satter","Battin","Costa","Matsumura","Shears","Devinney","Macken","Garrett","Doney","Fulmer","Hoss","Loll","Tanner","Podesta","Asaro","Morningstar","Hilyard",
                               "Nehls","Fonseca","Eller","Wilkinson","Lamarca","Soliz","Westervelt","Carlino","Kunkle","Loucks","Jansson","Cothren","Darlington","Zahm","Pinegar","Emerick","Tall","Eveland","Umstead","Davisson","Batz","Plata","Ryberg","Beane","Koening","Putz","Daughtrey","Sinha","Gerdes","Arno","Lorch","Shehan","Chenard","Holloway","Castleberry","Bowlin","Battin","Donovan","Calton",
                               "Huot","Mcmurtrie","Delapp","Lankford","Biel","Kin","Caceres","Ormand","Streicher","Kimbrel","Cornish","Barahona","Southern","Stuart","Stoke","Scharff","Hartwell","Gildersleeve","Tedrick","Rex","Chaudhry","Wetzel","Desai","Ensey","Escobedo","Matranga","Falzone","Ritzman","Marchant","Babin","Friedt","Shoup","Gunder","Seim","Shadrick","Riggs","Moret","Howes","Steenbergen",
                               "Rodriques","Dries","Jefferson","Hulbert","Menendez","Ellington","Housand","Whitwell","Rearick","Wagnon","Schmitmeyer","Barhorst","Rosenfield","Summerville","Matus","Marrow","Kind","Searfoss","Denn","Appling","Grim","Huffer","Kellen","Roscoe","Garofalo","Simeone","Goucher","Parkhurst","Tarpey","Bassett","Ortman","Segundo","Mattson","Pullum","Kriner","Smiddy","Cohrs",
                               "Loring","Strebel","Mcnemar","Grossi","Raby","Dubray","Capra","Wittrock","Fazzino","Bedard","Sera","Lisk","Heldt","Barefoot","Heimbach","Hover","Guthrie","Hartigan","Noyes","Jarrard"};
            // use the positive random number function above, mod'd by the length to grab a random value
            return (lastnames[RandNumber() % lastnames.Length]);
        }

        // make a random social security number
        public static string GenerateSSN()
        {
            int G1 = RandNumber(1, 1000);
            int G2 = RandNumber(1, 100);
            int G3 = RandNumber(1, 10000);
            // use the string.format and tostring methods to numerically pad each tuple of a social security number
            return String.Format("{0}-{1}-{2}", G1.ToString("D3"), G2.ToString("D2"), G3.ToString("D4"));
        }
    }
}
