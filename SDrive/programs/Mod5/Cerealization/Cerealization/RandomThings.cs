using System;
using System.Globalization;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cerealization
{
    /// <summary>
    /// Various randomly generated things.
    /// </summary>
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

        public static string GenerateAddr()
        {
            string[] set1 = { "Amber", "Auburn", "Bent", "Big", "Birch", "Blue", "Bright", "Broad", "Burning", "Calm", "Cinder", "Clear", "Cold", "Colonial", "Cool", "Cotton", "Cozy", "Crimson", "Crystal", "Dewy", "Dusty", "Easy", "Emerald", "Fallen", "Foggy", "Gentle", "Golden", "Grand", "Green", "Happy", "Harvest", "Hazy", "Heather", "Hidden", "High", "Honey", "Hush", "Indian", "Iron", "Ivory", 
                              "Jagged", "Lazy", "Little", "Lone", "Lonely", "Long", "Lost", "Merry", "Middle", "Misty", "Noble", "Old", "Orange", "Pearl", "Pied", "Pleasant", "Pretty", "Quaint", "Quaking", "Quiet", "Red", "Rocky", "Rose", "Rough", "Round", "Rustic", "Sandy", "Shady", "Silent", "Silver", "Sleepy", "Small", "Square", "Still", "Stony", "Strong", "Sunny", "Sweet", "Tawny", "Tender",
                              "Thunder", "Turning", "Twin", "Umber", "Velvet", "White", "Windy" };

            string[] set2 = { "Acorn", "Anchor", "Apple", "Autumn", "Axe", "Barn", "Beacon", "Bear", "Beaver", "Berry", "Bird", "Blossom", "Bluff", "Branch", "Bridge", "Brook", "Butterfly", "Butternut", "Castle", "Chestnut", "Cider", "Butt", "Cottage", "Creek", "Crow", "Dale", "Deer", "Diamond", "Dove", "Elk", "Elm", "Embers", "Fawn", "Feather", "Flower", "Forest", "Fox", "Gate", "Goat", "Goose", "Grove",
                              "Harbor", "Hickory", "Hills", "Holly", "Horse", "Island", "Lake", "Lamb", "Leaf", "Log", "Maple", "Mill", "Mountain", "Nectar", "Nest", "Nut", "Oak", "Panda", "Peach", "Pebble", "Pine", "Pioneer", "Pond", "Pony", "Prairie", "Pumpkin", "Quail", "Rabbit", "Rise", "River", "Robin", "Rock", "Shadow", "Sky", "Snake", "Spring", "Squirrel", "Stone", "Swan", "Timber", "Treasure",
                              "Turtle", "View", "Wagon", "Willow", "Zephyr" };

            string[] set3 = { "Acres", "Alcove", "Arbor", "Avenue", "Bank", "Bayou", "Bend", "Bluff", "Byway", "Canyon", "Chase", "Circle", "Corner", "Court", "Cove", "Crest", "Cut", "Dale", "Dell", "Drive", "Edge", "Estates", "Falls", "Farms", "Field", "Flats", "Gardens", "Gate", "Glade", "Glen", "Grove", "Haven", "Heights", "Highlands", "Hollow", "Isle", "Jetty", "Journey", "Knoll", "Lace", "Lagoon",
                              "Landing", "Lane", "Ledge", "Manor", "Meadow", "Mews", "Niche", "Nook", "Orchard", "Pace", "Park", "Pass", "Path", "Pike", "Place", "Point", "Promenade", "Quay", "Race", "Ramble", "Ridge", "Road", "Round", "Rove", "Run", "Saunter", "Shoal", "Stead", "Street", "Stroll", "Summit", "Swale", "Terrace", "Trace", "Trail", "Trek", "Turn", "Twist", "Vale", "Valley", "View", "Villa",
                              "Vista", "Wander", "Way", "Woods" };

            return string.Format("{0} {1} {2} {3}", RandNumber(0,10000), set1[RandNumber() % set1.Length], set2[RandNumber() % set2.Length], set3[RandNumber() % set3.Length]);
        }

        public static string GenerateState()
        {
            string[] states = { "AL", "AK", "AS", "AZ", "AR", "CA", "CO", "CT", "DE", "DC", "FM", "FL", "GA", "GU", "HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MH", "MD", "MA", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "MP", "OH", "OK", "OR", "PW", "PA", "PR", "RI", "SC", "SD", "TN", "TX", "UT", "VT", "VI", "VA", "WA", "WV", "WI", "WY" };
            return states[RandNumber() % states.Length];
        }

        public static string GenerateCity()
        {
            // grabbit from https://developers.google.com/adwords/api/docs/appendix/geotargeting?csw=1
            string[] cities = { "Anchorage", "Anderson", "Angoon", "Atqasuk", "Barrow", "Bethel", "Clear", "Cordova", "Craig", "Delta Junction", "Dillingham", "Eagle River", "Eielson AFB", "Elmendorf Air Force Base", "Fairbanks", "Galena", "Girdwood", "Glennallen", "Gustavus", "Haines", "Healy", "Homer", "Hoonah", "Juneau", "Kenai", "Ketchikan", "Klawock", "Kodiak", "Kotzebue", "McGrath", "Metlakatla", 
                                  "Mountain Village", "Nikiski", "Nome", "North Pole", "Palmer", "Pelican", "Petersburg", "Port Lions", "Seward", "Sitka", "Skagway", "Soldotna", "Saint Paul Island", "Tanacross", "Thorne Bay", "Tok", "Tununak", "Unalaska", "Valdez", "Wasilla", "Whittier", "Wrangell", "Yakutat", "Abbeville", "Adamsville", "Addison", "Adger", "Alabaster", "Albertville", "Alexander City", 
                                  "Alexandria", "Allgood", "Alpine", "Andalusia", "Anniston", "Arab", "Arlington", "Ashford", "Ashland", "Ashville", "Athens", "Atmore", "Attalla", "Auburn", "Auburn University", "Autaugaville", "Axis", "Bay Minette", "Berry", "Bessemer", "Birmingham", "Blountsville", "Boaz", "Bremen", "Brewton", "Brookwood", "Brownsboro", "Bucks", "Buhl", "Butler", "Calera", "Calhoun", 
                                  "Camden", "Carrollton", "Centre", "Centreville", "Chapman", "Chelsea", "Cherokee", "Childersburg", "Clanton", "Clayton", "Clio", "Coffeeville", "Columbia", "Columbiana", "Cottondale", "Cottonwood", "Cowarts", "Creola", "Crossville", "Cullman", "Daleville", "Daphne", "Dauphin Island", "Deatsville", "Decatur", "Demopolis", "Dixons Mills", "Dothan", "Eastaboga", "Eclectic",
                                  "Eight Mile", "Elba", "Elberta", "Enterprise", "Eufaula", "Eutaw", "Evergreen", "Excel", "Fairfield", "Fairhope", "Fayette", "Florence", "Foley", "Fruitdale", "Fort Deposit", "Fort Payne", "Fort Rucker", "Fulton", "Fultondale", "Gadsden", "Gardendale", "Geneva", "Glenwood", "Goodwater", "Gordo", "Grand Bay", "Graysville", "Greensboro", "Greenville", "Grove Hill", "Guin",
                                  "Gulf Shores", "Guntersville", "Haleyville", "Hamilton", "Hanceville", "Hartselle", "Hatchechubbee", "Hayden", "Hayneville", "Hazel Green", "Headland", "Heflin", "Helena", "Hodges", "Hope Hull", "Huntsville", "Huxford", "Ider", "Jack", "Jackson", "Jacksonville", "Jasper", "Jefferson", "Kellyton", "Killen", "Laceys Spring", "La Fayette", "Lanett", "Leeds", "Leesburg", 
                                  "Lillian", "Lincoln", "Linden", "Lineville", "Livingston", "Loachapoka", "Locust Fork", "Loxley", "Luverne", "Madison", "Marion", "Mathews", "Millport", "Millry", "Mobile", "Monroeville", "Montevallo", "Montgomery", "Montrose", "Morris", "Moulton", "Munford", "Muscle Shoals", "New Brockton", "New Market", "Newton", "Newville", "Normal", "Northport", "Notasulga", 
                                  "Oakman", "Oneonta", "Opelika", "Opp", "Orange Beach", "Oxford", "Ozark", "Paint Rock", "Pelham", "Pell City", "Pennington", "Perdue Hill", "Phenix City", "Piedmont", "Pike Road", "Pine Hill", "Pinson", "Pleasant Grove", "Prattville", "Quinton", "Ragland", "Rainbow City", "Rainsville", "Ramer", "Red Bay", "Reform", "Roanoke", "Robertsdale", "Russellville", "Rutledge",
                                  "Saginaw", "Saraland", "Scottsboro", "Selma", "Semmes", "Shannon", "Sheffield", "Shelby", "Spanish Fort", "Springville", "Sulligent", "Sumiton", "Summerdale", "Sycamore", "Sylacauga", "Talladega", "Tallassee", "Theodore", "Thomasville", "Toney", "Troy", "Trussville", "Tuscaloosa", "Tuscumbia", "Tuskegee", "Tuskegee University", "Union Springs", "Valley", "Vernon", 
                                  "Vinemont", "Wadley", "Walnut Grove", "Warrior", "Webb", "Wedowee", "Wetumpka", "Winfield", "York", "Adona", "Alexander", "Alma", "Altheimer", "Amity", "Arkadelphia", "Armorel", "Ash Flat", "Ashdown", "Augusta", "Bald Knob", "Barling", "Batesville", "Bauxite", "Bay", "Beebe", "Bella Vista", "Benton", "Bentonville", "Berryville", "Bigelow", "Blytheville", "Booneville",
                                  "Bradford", "Branch", "Brinkley", "Brockwell", "Brookland", "Bryant", "Burdette", "Cabot", "Calico Rock", "Camden", "Carlisle", "Carthage", "Cave City", "Center Ridge", "Charleston", "Charlotte", "Cherokee Village", "Clarendon", "Clarksville", "Clinton", "Compton", "Conway", "Corning", "Crossett", "Danville", "Dardanelle", "De Queen", "DeWitt", "Decatur", "Dermott", 
                                  "Des Arc", "Dumas", "Dyess", "El Dorado", "Elm Springs", "England", "Enola", "Eureka Springs", "Fairfield Bay", "Farmington", "Fayetteville", "Flippin", "Floral", "Fordyce", "Forrest City", "Fountain Hill", "Friendship", "Fort Smith", "Gassville", "Gentry", "Gillham", "Glenwood", "Gould", "Grady", "Gravette", "Greenbrier", "Greenwood", "Guion", "Hackett", "Hamburg", 
                                  "Hardy", "Harrisburg", "Harrison", "Hartford", "Hattieville", "Hazen", "Heber Springs", "Hector", "Helena", "Higden", "Hope", "Hot Springs National Park", "Hot Springs Village", "Hoxie", "Humphrey", "Huntsville", "Imboden", "Jacksonville", "Jasper", "Jessieville", "Joiner", "Jonesboro", "Keiser", "Kensett", "Lake Village", "Lavaca", "Lead Hill", "Lepanto", "Leslie", 
                                  "Little Rock", "Little Rock Air Force Base", "Lockesburg", "London", "Lonoke", "Lowell", "Luxora", "Lynn", "Mabelvale", "Magnolia", "Malvern", "Mammoth Spring", "Mansfield", "Marianna", "Marion", "Marked Tree", "Marmaduke", "Marshall", "Maumelle", "Maynard", "McCrory", "McGehee", "McRae", "Melbourne", "Mena", "Monticello", "Morrilton", "Mount Holly", "Mount Ida", 
                                  "Mount Pleasant", "Mount Vernon", "Mountain Home", "Mountain View", "Mountainburg", "Nashville", "Newark", "Newport", "Norfork", "Norman", "North Little Rock", "Osceola", "Ozark", "Palestine", "Paragould", "Paris", "Pea Ridge", "Pearcy", "Piggott", "Pine Bluff", "Plainview", "Plumerville", "Pocahontas", "Poplar Grove", "Pottsville", "Prairie Grove", "Prescott", 
                                  "Quitman", "Rector", "Rison", "Rogers", "Romance", "Rosston", "Russellville", "Salem", "Saratoga", "Scotland", "Searcy", "Sheridan", "Sherwood", "Siloam Springs", "Smackover", "Springdale", "Stamps", "Star City", "Arkansas State University", "Stuttgart", "Subiaco", "Sulphur Rock", "Swifton", "Texarkana", "Timbo", "Tontitown", "Trumann", "Valley Springs", "Van Buren" };
            return cities[RandNumber() % cities.Length];
        }

        // make a random social security number
        public static SocialSecurityNumber GenerateSSN()
        {
            int G1 = RandNumber(1, 1000); // 999
            int G2 = RandNumber(1, 100); // 99
            int G3 = RandNumber(1, 10000); // 9999
            // return a socialsecuritynumber
            return new SocialSecurityNumber(G1, G2, G3);
        }

        // make a random phonenumber
        public static PhoneNumber GeneratePhoneNumber()
        {
            int G1 = RandNumber(1, 1000); // 999
            int G2 = RandNumber(1, 1000); // 999
            int G3 = RandNumber(1, 10000); // 9999
            // return a phonenumber
            return new PhoneNumber(G1, G2, G3);
        }

        public static ZipCode GenerateZipCode()
        {
            int G1 = RandNumber(1, 100000); //99999
            int G2 = RandNumber(1, 10000); //9999
            return new ZipCode(G1, G2);
        }
    }
}
