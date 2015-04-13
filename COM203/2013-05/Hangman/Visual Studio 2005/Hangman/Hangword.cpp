#include "stdhangman.h"

int hangword::getid()
{
	return id;
}
void hangword::setid(int id)
{
	this->id = id;
}

void hangword::setword(string word)
{
	this->word = word;
}
string hangword::getword()
{
	return word;
}

void hangword::Read(ifstream& file)
{
	setid(readid(file));
	setword(readword(file));
}

void hangword::Write(ofstream& file)
{
	int id = getid();
	writeid(file, id);
	writeword(file, getword());
}

void hangword::writeword(ofstream& file,const string& str)
{
  // get the length of the string data
  unsigned int len = str.size();

  // write the size:
  file.write( reinterpret_cast<const char*>( &len ), sizeof(len) );

  // write the actual string data:
  file.write( str.c_str(), len );
}

string hangword::readword(ifstream& file)
{
  // this probably isn't the optimal way to do it, but whatever
  string str;

  // get the length
  unsigned int len;
  file.read( reinterpret_cast<char*>( &len ), sizeof(len) );

  // we can't read to string directly, so instead, create a temporary buffer
  if(len > 0)
  {
    char* buf = new char[len];
    file.read( buf, len );
    str.append( buf, len );
    delete[] buf;
  }
  return str;
}

inline void hangword::writeid(ofstream& file, int& num)
{
   file.write(reinterpret_cast<char *>(&num),sizeof(int));
}

int hangword::readid(ifstream& file)
{
   int num;
   file.read(reinterpret_cast<char *>(&num),sizeof(int));
   return num;
}