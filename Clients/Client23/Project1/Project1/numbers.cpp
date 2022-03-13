#include "Numbers.h"

#include<stdexcept>
#include<string>

/**
If you are reading this, you may be puzzled as to why subtrahend is not passed as reference to const.
This is one of those few exceptions: we will need to make a copy of subtrahend anyway in order to modify
it in this function. It would actually be less efficient to pass by reference to const and then make a copy
inside the function. We just make a copy straightaway. Unless you really understand this deeply, do not
pass an object by value.
*/

std::string add(const std::string& first, const std::string& second, unsigned char base)
{
	std::string f = first, s = second;

	reverseString(f);
	reverseString(s);

	if (s.length() > f.length())
		f.append(s.length() - f.length(), '0');
	else
		s.append(f.length() - s.length(), '0');

	int b = 0,temp;

	std::string result;
	

	for (int i = 0; i < f.length(); ++i)
	{
		temp = f[i] - '0' + s[i] - '0' + b;
		result.push_back(temp % base + '0');
		b = temp / base;
	}
	if (b) result.push_back(b + '0');

	reverseString(result);

	return result;
}


std::string twoPower(size_t pow)
{
	std::string p1="1",p2="1",result="1";
	int i, j, b = 0;
	for (i = 1; i <= pow; ++i)
	{
		result = add(p1, p2, 10);
		p1 = p2 = result;
	}

	return result;
}


void reverseString(std::string& a)
{
	auto first = a.begin(), last = a.end();
	char temp;
	while (first != last && first != --last)
	{
		temp = *first;
		*first = *last;
		*last = temp;
		++first;
	}
}



unsigned char charToDigit(char c)
{
	return c - '0';
}


char digitToChar(unsigned char u)
{
	return u + '0';
}


std::string decimalToBinary(std::string a)
{
	std::string bin, result;
	bin = twoPower(0);
	int i = 0;
	for (i = 1; !lessThanOrEqual(a, bin); ++i)
		bin = twoPower(i);
	--i;
	for (; i>-1; --i)
	{
		bin = twoPower(i);
		if (lessThanOrEqual(bin, a))
		{
			result.push_back('1');
			a=subtract(a, bin, 10);
		}
		else result.push_back('0');
	}
	if (result[0] == '0') result = result.substr(1);

	return result;

}


std::string binaryToDecimal(std::string a)
{
	reverseString(a);
	std::string result="0";

	for (int i = 0; i < a.length(); ++i)
	{
		if (a[i] == '1')
			result = add(result, twoPower(i),10);
	}

	return result;

}



std::string subtract(const std::string& minuend, std::string subtrahend, unsigned char base) {
	/* We first wish to modify each digit of subtrahend by turning it into its complement.
	The digit d should be converted into (base-1-d).
	*/
	for (auto& c : subtrahend) { // for each char in the subtrahend string
		// need to convert the char to digits, do the arithmetic, and go back to char!
		c = digitToChar((base - 1) - charToDigit(c));
	}

	//Subtraction can be done by addition, now. We first add 1 to the subtrahend.
	subtrahend = add(subtrahend, "1", base);

	// now, add the minuend and updated subtrahend
	std::string difference = add(minuend, subtrahend, base);

	/*
	The resulting number will always have a superfluous digit at index 0 that we do not want.
	In addition, we wish to move past all the zeros at the start.
	*/
	size_t zeroEnd = 1; // index to track where zeros end

	// size of the difference  
	const size_t diff_sz = difference.size();

	// while index still within bounds (checked first) and there are still zeros
	while ((zeroEnd < diff_sz) && (difference[zeroEnd] == '0')) {
		++zeroEnd; // increase the index
	}

	if (zeroEnd == diff_sz) { // if zeroEnd is out of range then it was all 0's
		return "0";
	}

	return difference.substr(zeroEnd); // return the truncated number going from first nonzero to end of string
}


bool lessThanOrEqual(const std::string& first, const std::string& second) {
	if (first == second) { // if the two strings are equal, then they are equal!
		return true;
	}

	/* We need to look at their lengths: a longer number in proper format (no 0's at beginning)
	will always be larger than a number that is shorter */

	if (first.size() < second.size()) { // second longer
		return true; // so first < second
	}
	else if (second.size() < first.size()) { // first longer
		return false; // so first > second
	}
	else { // If the numbers have the same length, we can compare digit by digit because the chars 0-9 are ordered
		return first < second;
	}
}