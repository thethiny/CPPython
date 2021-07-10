#include "pystring.h"

std::vector<PyString> PyString::split(PyString ToFind, int MaxSplit)
{
	std::vector<PyString> found;
	PyString ToSplit = *this;
	for (long long i = 0; i < ToSplit.length(); i++)
	{
		if (MaxSplit >= 0 && found.size() >= MaxSplit)
			break;
		if (!strcmp(ToSplit.substr(i, ToFind.length()).c_str(), ToFind.c_str()))
		{
			found.push_back(ToSplit.substr(0, i));
			ToSplit = ToSplit.substr(i + 1);
			i = -1;
		}
	}

	if (!this->empty())
	{
		found.push_back(ToSplit);
	}

	return found;
}

std::vector<PyString> PyString::rsplit(PyString ToFind, int MaxSplit)
{
	std::vector<PyString> found;
	PyString ToSplit = *this;
	for (long long i = ToSplit.length() - 1; i >= 0; i--)
	{
		if (MaxSplit >= 0 && found.size() >= MaxSplit)
			break;
		if (!strcmp(ToSplit.substr(i, ToFind.length()).c_str(), ToFind.c_str()))
		{
			found.insert(found.begin(), ToSplit.substr(i + 1));
			ToSplit = ToSplit.substr(0, i);
			i = ToSplit.length();
		}
	}
	if (!ToSplit.empty())
	{
		found.insert(found.begin(), ToSplit);
	}

	return found;
}

PyString PyString::lower()
{
	PyString new_string("");
	for (int i = 0; i < this->length(); i++)
	{
		new_string += std::tolower((*this)[i]);
	}
	return new_string;
}

PyString PyString::upper()
{
	PyString new_string("");
	for (int i = 0; i < this->length(); i++)
	{
		new_string += std::toupper((*this)[i]);
	}
	return new_string;
}

PyString PyString::join(PyString* str, uint64_t size)
{
	PyString x = "";
	for (uint64_t i = 0; i < size; i++)
	{
		x += str [i];
		if (i == size - 1)
		{
			x += *this;
		}
	}
	return x;
}

PyString PyString::strip(PyString ToStrip)
{
	PyString x = *this;
	uint64_t pos = 0, posend = x.length();
	for (auto i = 0; i < x.length(); i++)
	{
		bool in = false;
		bool in2 = false;
		for (auto j = 0; j < ToStrip.length(); j++)
		{
			if (x[i] == ToStrip[j])
			{
				in = true;
			}
			if (x[x.length() - i - 1] == ToStrip[j])
			{
				in2 = true;
			}
		}
		if (in)
			pos = i;
		if (in2)
			posend = x.length() - i - 1;
	}

	return x.substr(pos, posend-pos);
}

bool PyString::startswith(PyString Start)
{
	return !strncmp(*this, Start, Start.length());
}

bool PyString::endswith(PyString End)
{
	PyString NewStr = this->substr(this->length() - End.length());
	return !strncmp(NewStr, End, End.length());
}