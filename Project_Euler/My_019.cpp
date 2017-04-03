
// Creates a sine function table
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include "Toolkit_functions.h"

using namespace std;



class date{
public:

    int day;
    int month;
    int year;
    int weekday;

};


date add_day(date x){
    date temp;
    //Initialize temp to prevent erros
    temp.day = 0;
    temp.month = 0;
    temp.year = 0;

    // Default jumps
    int day_jump = 1;
    int month_jump = 0;
    int year_jump = 0;

    if(x.weekday == 7){
        temp.weekday = 1;
    } else{
        temp.weekday = x.weekday + 1;
    }


    bool is_leap_year = ((x.year % 4 == 0) && (((x.year % 100 != 0)) || (x.year % 400 == 0)));

    //Main computation
    switch(x.month){
        default:{
            cout <<"SOMETHING WENT TERRIBLY WRONG" << endl;
        }
        case 1:{
            if(x.day == 31){
                month_jump = 1;
                temp.day = day_jump;
            } else{
                temp.day = x.day + day_jump;
            }
            temp.month = x.month + month_jump;
            temp.year = x.year + year_jump;
            goto finito;
        }
        case 2:{
            if(x.day == 28 + is_leap_year){
                month_jump = 1;
                temp.day = day_jump;
            } else{
                temp.day = x.day + day_jump;
            }
            temp.month = x.month + month_jump;
            temp.year = x.year + year_jump;
            goto finito;
        }
        case 3:{
            if(x.day == 31){
                month_jump = 1;
                temp.day = day_jump;
            } else{
                temp.day = x.day + day_jump;
            }
            temp.month = x.month + month_jump;
            temp.year = x.year + year_jump;
            goto finito;
        }
        case 4:{
            if(x.day == 30){
                month_jump = 1;
                temp.day = day_jump;
            } else{
                temp.day = x.day + day_jump;
            }
            temp.month = x.month + month_jump;
            temp.year = x.year + year_jump;
            goto finito;
        }
        case 5:{
            if(x.day == 31){
                month_jump = 1;
                temp.day = day_jump;
            } else{
                temp.day = x.day + day_jump;
            }
            temp.month = x.month + month_jump;
            temp.year = x.year + year_jump;
            goto finito;
        }
        case 6:{
            if(x.day == 30){
                month_jump = 1;
                temp.day = day_jump;
            } else{
                temp.day = x.day + day_jump;
            }
            temp.month = x.month + month_jump;
            temp.year = x.year + year_jump;
            goto finito;
        }
        case 7:{
            if(x.day == 31){
                month_jump = 1;
                temp.day = day_jump;
            } else{
                temp.day = x.day + day_jump;
            }
            temp.month = x.month + month_jump;
            temp.year = x.year + year_jump;
            goto finito;
        }
        case 8:{
            if(x.day == 31){
                month_jump = 1;
                temp.day = day_jump;
            } else{
                temp.day = x.day + day_jump;
            }
            temp.month = x.month + month_jump;
            temp.year = x.year + year_jump;
            goto finito;
        }
        case 9:{
            if(x.day == 30){
                month_jump = 1;
                temp.day = day_jump;
            } else{
                temp.day = x.day + day_jump;
            }
            temp.month = x.month + month_jump;
            temp.year = x.year + year_jump;
            goto finito;
        }
        case 10:{
            if(x.day == 31){
                month_jump = 1;
                temp.day = day_jump;
            } else{
                temp.day = x.day + day_jump;
            }
            temp.month = x.month + month_jump;
            temp.year = x.year + year_jump;
            goto finito;
        }
        case 11:{
            if(x.day == 30){
                month_jump = 1;
                temp.day = day_jump;
            } else{
                temp.day = x.day + day_jump;
            }
            temp.month = x.month + month_jump;
            temp.year = x.year + year_jump;
            goto finito;
        }
        case 12:{
            if(x.day == 31){
                month_jump = 1;
                temp.day = day_jump;
                year_jump = 1;

                temp.month = month_jump;
                temp.year = x.year + year_jump;
            } else{
                temp.day = x.day + day_jump;
                temp.month = x.month;
                temp.year = x.year;
            }

            goto finito;
        }

    }
    finito:
    return temp;
}

int main() {
    //Create object
    date today;
    today.day = 1;
    today.month = 1;
    today.year = 1900;
    today.weekday = 1;

    // Initialize database
    vector<date> cd  = {today};

    int count_sundays = 0;

    while(cd.back().year <2001){
        today = add_day(today);
        cd.push_back(today);
        if(today.weekday == 7 && today.day == 1 && today.year > 1900){
            count_sundays++;
        }
    }
    cout << "31.december 2000 was :" << cd.back().weekday<< endl;
    cout << "There have been " << count_sundays << " Sundays that happen on the first of the month";

}



