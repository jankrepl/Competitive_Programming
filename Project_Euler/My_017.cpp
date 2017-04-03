// helloworld.cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;


string create_string(int x){
//Create all building blocks
    string all_units[] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten",
                            "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
                            "eighteen","nineteen"};
    string all_tens[] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    //cout << all_units[1] << endl;

    string final_string = "";
    int tens = (x%100)/10;
    int hundreds = x/100;
    if(x == 1000)
    {
        return "onethousand";}

    while(x>0){
        if(x<20){
            final_string += all_units[x];
            return final_string;

        }else if(x>=20 && x<100){
            final_string += all_tens[tens - 2];
            x -= tens*10;

        //100-999
        }else{
            //*00
            if(tens == 0 & x%10 == 0 )
            {
                final_string += all_units[hundreds]+"hundred";
                return final_string;}
            //all remaining
            else
            {
                final_string += all_units[hundreds]+"hundred"+"and";
                x -= hundreds*100;
            }

        }

    }
    return final_string;
}


long number_of_characters(string s){
    return s.length();
}

int main()
{
    int sum = 0;
    string number_string = "";
    for(int i = 1; i<= 1000; ++i){
        number_string = create_string(i);
        sum += number_of_characters(number_string);
    }
    cout << sum << endl;
}
