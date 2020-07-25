#include <stdio.h>
#include <stdlib.h>

typedef struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
}retire_info;

double profitCount(retire_info savings, double initial){
  double percentToCount = (savings.rate_of_return/100)/12;
  double saved = initial * percentToCount;
  double moneyPerMonth = saved + initial + savings.contribution;
  return moneyPerMonth;
}

void retirement (int startAge, double initial, retire_info working, retire_info retired){
  int monthAge = startAge % 12;
  int ageYears = (startAge - monthAge)/12;
  double money = initial;
  printf("Age %3d month %2d you have $%.2lf\n", ageYears, monthAge, initial);
  for(int i = 0; i < working.months; i++){
    double saves = profitCount(working, money);
    money = saves;
    monthAge++;
    if(monthAge % 12 == 0){
      ageYears++;
      monthAge = 0;
    }
    printf("Age %3d month %2d you have $%.2lf\n", ageYears, monthAge, money);
  }
  for(int i = 0; i < retired.months - 1; i++){
    double saves = profitCount(retired, money);
    money = saves;
    monthAge++;
    if(monthAge % 12 == 0){
      ageYears++;
      monthAge = 0;
    }
    printf("Age %3d month %2d you have $%.2lf\n", ageYears, monthAge, money);
  }

}

int main()
{
  retire_info work;
  work.months = 489;
  work.contribution = 1000;
  work.rate_of_return = 4.5;

  retire_info rett;
  rett.months = 384;
  rett.contribution = -4000;
  rett.rate_of_return = 1;

  retirement(327, 21345, work, rett);


  return 0;
}
