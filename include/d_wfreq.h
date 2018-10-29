#ifndef D_WFREQ_H_INCLUDED
#define D_WFREQ_H_INCLUDED

#include <string>
#include <ostream>

class wordFreq
{
public:
	wordFreq(const string& str):word(str),freq(1)
	{}

	void increment()
	{
		freq++;
	}
    friend bool operator ==(const wordFreq& lhs, const wordFreq& rhs)
    {
    	return lhs.word == rhs.word;
    }
	friend bool operator <(const wordFreq& lhs, const wordFreqZ& rhs)
	{
		return lhs.word < rhs.word;
	}
	friend ostream& operator <<(ostream& ostr, const wordFreq& w)
	{
		ostr << w.word << "(" << w.freq << ")";
		return ostr;
	}
private:
	string word;
	unsigned int freq;
};


#endif // D_WFREQ_H_INCLUDED
