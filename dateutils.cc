#include "dateutils.h"

bool DateUtils::isLeapYear(int y)
{
    return y%400==0||(y%4==0&&y%100!=0);
}

/*日期所在年的天数*/
int DateUtils::daysOfYear(Date & date)
{
    int days = date.day();
    for(int m = 1;m < date.month();++m)
    {
        days+=DAYS[m-1];
    }
    if(DateUtils::isLeapYear(date.year())) ++days;
    return days;
}

/*两个日期相差的天数*/
int DateUtils::daysBetween_(Date & start, Date & end)
{
    int days = DateUtils::daysOfYear(end)-DateUtils::daysOfYear(start);
    for(int y = start.year();y<end.year();++y)
    {
        days+=DAY_OF_YEAR;
        if(DateUtils::isLeapYear(y)) ++days;
    }
    return days;
}

/*指定日期几天之后的日期*/
Date DateUtils::daysAfter_(Date & start, int days)
{
    int leftDay = DAY_OF_YEAR-DateUtils::daysOfYear(start);
    bool leap = DateUtils::isLeapYear(start.year());
    if(leap) leftDay++;
    // 在一年之内
    if(leftDay>=days)
    {
        return DateUtils::daysAfterInYear_(start,days);
    }else
    {
        days-=leftDay;
        int y;
        int left = 0;
        bool isLeap;
        for(y = start.year()+1;;++y)
        {
            days -= DAY_OF_YEAR;
            if(DateUtils::isLeapYear(y)) --days;
            // 在当前年天数之内
            if(days<=0) break;
        }
        Date cur(y);
        // 复原
        // BUG TODO
        if(days==0) ++days;
        days+=DAY_OF_YEAR;
        if(DateUtils::isLeapYear(y)) ++days;
        // 转化成一年之内计算
        return DateUtils::daysAfterInYear_(cur,days);
    }

}

Date DateUtils::daysAfterInYear_(Date & start, int days)
{
    Date res(start.year());
    int d = DAYS[start.month()-1] - start.day();
    if(start.month()==2&&DateUtils::isLeapYear(start.year())) ++d;
    // 在一个月之内
    if(d>=days)
    {
        res.setMonth(start.month());
        res.setDay(start.day()+days);
    }else
    {
        days -= d;
        int m;
        for(m = start.month()+1;m<12;++m)
        {
            days-= DAYS[m-1];
            if(m==2 && DateUtils::isLeapYear(start.year())) --days;
            //在当前月天数之内
            if(days<=0) break;
        }
        res.setMonth(m);
        int day = DAYS[m-1]+days;
        res.setDay(day);
    }
    return res;
}

int DateUtils::daysBetween(Date & start, Date & end)
{
    int days = 0;
    if(start<end)
    {
        days = DateUtils::daysBetween_(start,end);
    }else
    {
        days = -DateUtils::daysBetween_(end,start);
    }
    return days;
}

Date DateUtils::daysAfter(Date & start, int days)
{
    // 日期之后
    if(days>=0)
    {
        return DateUtils::daysAfter_(start,days);
    }
    // TODO: 日期之前

}
