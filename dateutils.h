#ifndef __DATEUTILS__H__
#define __DATEUTILS__H__
#include <stdio.h>
#include <iostream>

const int DAY_OF_YEAR = 365;
const int DAYS[]={31,28,31,30,31,30,31,31,30,31,30,31};

class Date{
    public:
        Date(int y,int m,int d):
            year_(y),month_(m),day_(d){}
        Date(int y,int m):
            year_(y),month_(m),day_(1){}
        Date(int y):
            year_(y),month_(1),day_(1){}
        Date():
            year_(1),month_(1),day_(1){}

        int year() {return year_;}
        int month() {return month_;}
        int day() {return day_;}
        void setYear(int y){year_=y;}
        void setMonth(int m){month_=m;}
        void setDay(int d){day_=d;}

        bool operator<(Date& rhs)
        {
            return year_<rhs.year_||month_<rhs.month_||day_<rhs.day_;
        }

        friend std::ostream& operator<<(std::ostream & os, Date & rhs)
        {
            char buf[16];
            snprintf(buf,16,"%04d-%02d-%02d",rhs.year_,rhs.month_,rhs.day_);
            os<<buf;
            return os;
        }

        friend std::istream& operator>>(std::istream & is,Date & rhs)
        {
            is>>rhs.year_>>rhs.month_>>rhs.day_;
            return is;
        }
    private:
        int year_;
        int month_;
        int day_;

};

class DateUtils{
    public:
        static bool isLeapYear(int y);
        /*日期所在年的天数*/
        static int daysOfYear(Date & date);
        /*两个日期相差的天数*/
        static int daysBetween(Date & start, Date & end);
        /*指定日期几天之后的日期*/
        static Date daysAfter(Date & start, int days);

    private:
        static int daysBetween_(Date & start, Date & end);
        static Date daysAfter_(Date & start, int days);
        static Date daysAfterInYear_(Date & start, int days);
};
#endif
