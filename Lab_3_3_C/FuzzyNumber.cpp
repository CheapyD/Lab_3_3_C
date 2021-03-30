#include "FuzzyNumber.h"

FuzzyNumber::FuzzyNumber()
{
	x = 0;
	l = 0;
	r = 0;
}

FuzzyNumber::FuzzyNumber(double X = 0, double L = 0, double R = 0)
{
	x = X;
	l = L;
	r = R;
}

FuzzyNumber::FuzzyNumber(const FuzzyNumber& v)
{
	x = v.x;
	l = v.l;
	r = v.r;
}

FuzzyNumber& FuzzyNumber::operator = (const FuzzyNumber& n)
{
	x = n.x;
	l = n.l;
	r = n.r;
	return *this;
}

FuzzyNumber::operator string () const
{
	stringstream ss;
	ss << "(" << l << "; " << x << "; " << r << ")" << endl;
	return ss.str();
}

FuzzyNumber& FuzzyNumber::operator --()
{
	--l;
	return *this;
}

FuzzyNumber& FuzzyNumber::operator ++()
{
	++l;
	return *this;
}

FuzzyNumber FuzzyNumber::operator --(int)
{
	FuzzyNumber a(*this);
	r--;
	return a;
}

FuzzyNumber FuzzyNumber::operator ++(int)
{
	FuzzyNumber a(*this);
	r++;
	return a;
}

FuzzyNumber operator + (FuzzyNumber a, FuzzyNumber b)
{
	FuzzyNumber T(0, 0, 0);
	T.x = a.x + b.x;
	T.l = a.x + b.x - a.l - b.l;
	T.r = a.x + b.x + a.r + b.r;
	return T;
}

FuzzyNumber operator * (FuzzyNumber a, FuzzyNumber b)
{
	FuzzyNumber N(0, 0, 0);
	N.x = a.x * b.x;
	N.l = (a.x * b.x) - (b.x * a.l) - (a.x * b.l) - (a.l * b.l);
	N.r = (a.x * b.x) + (b.x * a.r) + (a.x * b.r) + (a.r * b.r);
	return N;
}

ostream& operator <<(ostream& out, const FuzzyNumber& a)
{
	return out << string(a);
}

istream& operator >>(istream& in, FuzzyNumber& a)
{
	do
	{
		cout << "x = "; in >> a.x;
		cout << "l = "; in >> a.l;
		cout << "r = "; in >> a.r;
	} while (!(a.x > (a.x - a.l) && (a.x + a.r) > a.x));
	return in;
}
