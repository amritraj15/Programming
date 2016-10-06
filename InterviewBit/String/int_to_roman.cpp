/*
Another question which belongs to the category of questions which are intentionally stated vaguely. 
Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Given an integer, convert it to a roman numeral, and return a string corresponding to its roman numeral version

Input is guaranteed to be within the range from 1 to 3999.

Example :

Input : 5
Return : "V"

Input : 14
Return : "XIV"
*/

string Solution::intToRoman(int A) {

    int num=A,l,i,q;
    int integer[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string roman[] = {"M", "CM", "D","CD","C", "XC","L","XL", "X", "IX","V","IV", "I"};

    if (num<1)
        return "";

    string str="";
    l = sizeof(integer)/integer[0];
    //cout<<l<<" ";
    for(i = 0; i < 13; i ++)
    {
        q = num/integer[i];
        while(q>0)
        {
            str=str+roman[i];
            q--;
        }
    num=num%integer[i];
    }

return str;
} 
