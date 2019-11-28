/* Bismillahir Rahmanir Rahim*/
// Author: Grim Firefly
#include <bits/stdc++.h>
using namespace std;

//G_BigInt all process
class G_BigInt
{
private:
    string Bnum;
    short sign;

public:
    G_BigInt(string str = "0")
    {
        Bnum = str;
        prepare();
    }
    void operator=(string number)
    {
        Bnum = number;
        prepare();
    }
    //used for delete heading zero and taking sign
    void prepare()
    {
        int i = 0;
        Bnum[0] == '-' ? i++, sign = -1 : sign = 1;
        Bnum = Bnum.substr(i, Bnum.size() - i);
        headzero();
    }
    void headzero()
    {
        int i = 0;
        while (Bnum[i] == '0')
            i++;
        Bnum = Bnum.substr(i, Bnum.size() - i);
        if (!Bnum.size())
        {
            Bnum = "0";
            sign = 1;
        }
    }
    void signchange()
    {
        sign *= -1;
    }
    //printout of big integer
    friend ostream &operator<<(ostream &output, const G_BigInt &number)
    {
        if (number.sign == -1)
            printf("-");
        return output << number.Bnum, output;
    }
    //taking input of big integer
    friend istream &operator>>(istream &input, G_BigInt &number)
    {
        return input >> number.Bnum, number.prepare(), input;
    }

    //all compare component
    //less operator declared
    bool operator<(const G_BigInt &number) const;
    //less equal operator declared
    bool operator<=(const G_BigInt &number) const;
    //equal operator used
    bool operator==(const G_BigInt &number) const
    {
        return Bnum == number.Bnum and sign == sign;
    }
    bool operator!=(const G_BigInt &number) const
    {
        return Bnum != number.Bnum or sign != sign;
    }
    //greater equal operator declared
    bool operator>=(const G_BigInt &number) const;
    //greater operator declared
    bool operator>(const G_BigInt &numberconst) const;

    //all arithmetic operator
    G_BigInt operator+(G_BigInt number);
    G_BigInt operator-(G_BigInt number);
    G_BigInt operator/(G_BigInt number);
    G_BigInt operator%(G_BigInt number);
    G_BigInt operator*(G_BigInt number);

    //increment ++x
    G_BigInt operator++();
    //increment x++
    G_BigInt operator++(int);
    //decrement --x
    G_BigInt operator--();
    //decrement x++
    G_BigInt operator--(int);

    //add to own overloading
    G_BigInt operator+=(const G_BigInt number);
    //substract from own overloding
    G_BigInt operator-=(const G_BigInt number);
    //divide from own
    G_BigInt operator/=(const G_BigInt number);
    //multiple by own
    G_BigInt operator*=(const G_BigInt number);
    //vagsesh
    G_BigInt operator%=(const G_BigInt number);
    //minus
    G_BigInt operator-();
};
//return negative of this
G_BigInt G_BigInt::operator-()
{
    signchange();
    return *this;
}
//multiple by own
G_BigInt G_BigInt::operator*=(const G_BigInt number)
{
    *this = *this * number;
    return (*this);
}
//vagsesh by own
G_BigInt G_BigInt::operator%=(const G_BigInt number)
{
    *this = *this % number;
    return (*this);
}
//divide by own
G_BigInt G_BigInt::operator/=(const G_BigInt number)
{
    *this = *this / number;
    return (*this);
}
//substract from own
G_BigInt G_BigInt::operator-=(const G_BigInt number)
{
    *this = *this - number;
    return (*this);
}
//add to own
G_BigInt G_BigInt::operator+=(const G_BigInt number)
{
    *this = *this + number;
    return (*this);
}

// increment
G_BigInt G_BigInt::operator++(int)
{
    G_BigInt nn;
    nn = *this;
    if (Bnum[Bnum.size() - 1] != '9' and sign == 1)
        Bnum[Bnum.size() - 1]++;
    else if (Bnum[Bnum.size() - 1] != '0' and sign == -1)
        Bnum[Bnum.size() - 1]--, headzero();
    else
    {
        G_BigInt number("1");
        *this = *this + number;
    }
    return nn;
}
G_BigInt G_BigInt::operator++()
{
    if (Bnum[Bnum.size() - 1] != '9' and sign == 1)
        Bnum[Bnum.size() - 1]++;
    else if (Bnum[Bnum.size() - 1] != '0' and sign == -1)
        Bnum[Bnum.size() - 1]--, headzero();
    else
    {
        G_BigInt number("1");
        *this = *this + number;
    }
    return (*this);
}
//decrement
G_BigInt G_BigInt::operator--(int)
{
    G_BigInt nn;
    nn = *this;
    if (Bnum[Bnum.size() - 1] != '0' and sign == 1)
    {
        Bnum[Bnum.size() - 1]--, headzero();
    }
    else if (Bnum[Bnum.size() - 1] != '9' and sign == -1)
    {
        Bnum[Bnum.size() - 1]++;
    }
    else
    {
        G_BigInt number("1");
        *this = *this - number;
    }
    return nn;
}
G_BigInt G_BigInt::operator--()
{
    if (Bnum[Bnum.size() - 1] != '0' and sign == 1)
    {
        Bnum[Bnum.size() - 1]--, headzero();
    }
    else if (Bnum[Bnum.size() - 1] != '9' and sign == -1)
    {
        Bnum[Bnum.size() - 1]++;
    }
    else
    {
        G_BigInt number("1");
        *this = *this - number;
    }
    return (*this);
}

//multipication
G_BigInt G_BigInt ::operator*(G_BigInt number)
{
    G_BigInt ans;
    ans.sign = sign * number.sign;
    int l = Bnum.size() + number.Bnum.size();
    for (int i = 0; i < l; i++)
    {
        ans.Bnum += '0';
    }
    int carry = 0;
    int k, x = 0;
    for (int i = Bnum.size() - 1; i >= 0; i--)
    {
        k = x;
        for (int j = number.Bnum.size() - 1; j >= 0; j--)
        {
            carry += (Bnum[i] - '0') * (number.Bnum[j] - '0') + (ans.Bnum[k] - '0');
            ans.Bnum[k++] = carry % 10 + '0';
            carry /= 10;
        }
        while (carry)
        {
            ans.Bnum[k++] = carry % 10 + '0';
            carry /= 10;
        }
        x++;
    }
    reverse(ans.Bnum.begin(), ans.Bnum.end());
    ans.headzero();
    return ans;
}

//vagsesh
G_BigInt G_BigInt ::operator%(G_BigInt number)
{
    if (number.Bnum == "0")
        number.Bnum[0] /= (number.Bnum[0] - 48);
    G_BigInt db;
    db.Bnum = "";
    short s = number.sign * sign;
    number.sign = db.sign = 1;
    for (int i = 0; i < Bnum.size(); i++)
    {
        db.Bnum += Bnum.substr(i, 1);
        db.headzero();
        while (db >= number)
            db = db - number;
    }
    db.sign = s;
    db.headzero();
    return db;
}

//divition
G_BigInt G_BigInt ::operator/(G_BigInt number)
{
    if (number.Bnum == "0")
        number.Bnum[0] /= (number.Bnum[0] - 48);
    G_BigInt ans, db;
    ans.sign = number.sign * sign;
    for (int i = 0; i < Bnum.size(); i++)
    {
        ans.Bnum += '0';
    }
    db.Bnum = "";
    number.sign = db.sign = 1;

    for (int i = 0; i < Bnum.size(); i++)
    {
        db.Bnum += Bnum.substr(i, 1);
        db.headzero();
        while (db >= number)
        {
            db = db - number;
            ans.Bnum[i]++;
        }
    }
    ans.headzero();
    ans.Bnum = ans.Bnum.substr(0, ans.Bnum.size() - 1);
    if (!ans.Bnum.size())
        ans.Bnum = '0';
    return ans;
}

//substraction
G_BigInt G_BigInt ::operator-(G_BigInt number)
{
    if (sign != number.sign)
    {
        number.signchange();
        return (*this) + number;
    }
    string str1 = Bnum, str2 = number.Bnum;
    G_BigInt ans;
    ans.sign = sign;
    short s = sign;
    sign = number.sign = 1;
    if (*this < number)
    {
        swap(str1, str2);
        ans.signchange();
    }
    ans.Bnum = "";
    int l1 = str1.size() - 1;
    int l2 = str2.size() - 1;
    int l = max(l1, l2) + 1;
    int carry = 0;
    int sub = 0;
    while (l--)
    {
        sub = (l1 >= 0 ? str1[l1] - '0' : 0) - (l2 >= 0 ? str2[l2] - '0' : 0) - carry;
        sub < 0 ? sub = sub + 10, carry = 1 : carry = 0;
        ans.Bnum += sub + '0';
        l1--, l2--;
    }
    reverse(ans.Bnum.begin(), ans.Bnum.end());
    sign = s;
    ans.headzero();
    return ans;
}
//addition
G_BigInt G_BigInt ::operator+(G_BigInt number)
{
    if (sign != number.sign)
    {
        number.signchange();
        return (*this) - number;
    }
    G_BigInt ans;
    ans.Bnum = "";
    int l1 = Bnum.size() - 1;
    int l2 = number.Bnum.size() - 1;
    int l = max(l1, l2) + 1;
    int carry = 0;
    while (l--)
    {
        carry += (l1 >= 0 ? Bnum[l1] - '0' : 0) + (l2 >= 0 ? number.Bnum[l2] - '0' : 0);
        ans.Bnum += carry % 10 + '0';
        carry /= 10;
        l1--;
        l2--;
    }
    if (carry)
    {
        ans.Bnum += carry + '0';
    }
    ans.sign = sign;
    reverse(ans.Bnum.begin(), ans.Bnum.end());
    return ans;
}
// < lesser operator used
bool G_BigInt::operator<(const G_BigInt &number) const
{

    if (sign != number.sign)
        return sign < number.sign;
    if (Bnum.size() != number.Bnum.size())
        return sign == 1 ? Bnum.size() < number.Bnum.size() : Bnum.size() > number.Bnum.size();
    int i = 0;
    while (i < Bnum.size())
    {
        if (Bnum[i] != number.Bnum[i])
        {
            return sign == 1 ? Bnum[i] < number.Bnum[i] : Bnum[i] > number.Bnum[i];
        }
        i++;
    }
    return false;
}

// <= operator used
bool G_BigInt::operator<=(const G_BigInt &number) const
{
    if (sign == number.sign and Bnum == number.Bnum)
        return true;
    if (sign != number.sign)
        return sign < number.sign;
    if (Bnum.size() != number.Bnum.size())
        return sign == 1 ? Bnum.size() < number.Bnum.size() : Bnum.size() > number.Bnum.size();
    int i = 0;
    while (i < Bnum.size())
    {
        if (Bnum[i] != number.Bnum[i])
            return sign == 1 ? Bnum[i] < number.Bnum[i] : Bnum[i] > number.Bnum[i];
        i++;
    }
    return false;
}
//greater equal operator process
bool G_BigInt::operator>=(const G_BigInt &number) const
{
    if (sign == number.sign and Bnum == number.Bnum)
        return true;
    if (sign != number.sign)
        return sign > number.sign;
    if (Bnum.size() != number.Bnum.size())
        return sign == 1 ? Bnum.size() > number.Bnum.size() : Bnum.size() < number.Bnum.size();
    int i = 0;
    while (i < Bnum.size())
    {
        if (Bnum[i] != number.Bnum[i])
            return sign == 1 ? Bnum[i] > number.Bnum[i] : Bnum[i] < number.Bnum[i];
        i++;
    }
    return false;
}
//greater operator process
bool G_BigInt::operator>(const G_BigInt &number) const
{
    if (sign != number.sign)
        return sign > number.sign;
    if (Bnum.size() != number.Bnum.size())
        return sign == 1 ? Bnum.size() > number.Bnum.size() : Bnum.size() < number.Bnum.size();
    int i = 0;
    while (i < Bnum.size())
    {
        if (Bnum[i] != number.Bnum[i])
            return sign == 1 ? Bnum[i] > number.Bnum[i] : Bnum[i] < number.Bnum[i];
        i++;
    }
    return false;
}
int main()
{
    
    return 0;
}
