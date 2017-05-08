#include "dateutils.h"

void scanfDate(char * str,Date * date)
{
    if(str==NULL||date==NULL) return;
    int y,m,d;
    sscanf(str,"%04d-%02d-%02d",&y,&m,&d);
    date->setYear(y);
    date->setMonth(m);
    date->setDay(d);
}
int main(int argc, char *argv[])
{
    Date gauss(1777,4,30);
    Date graduate(1791,12,15);
    scanfDate(argv[1],&gauss);
    scanfDate(argv[2],&graduate);

    std::cout<<gauss<<":"<<DateUtils::daysOfYear(gauss)<<std::endl;
    std::cout<<graduate<<":"<<DateUtils::daysOfYear(graduate)<<std::endl;
    int days;
    std::cout<<(days=DateUtils::daysBetween(gauss,graduate))<<std::endl;
    Date res = DateUtils::daysAfter(gauss,days);
    std::cout<<res<<std::endl;
    return 0;
}
