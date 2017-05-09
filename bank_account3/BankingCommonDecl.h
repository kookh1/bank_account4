#ifndef __BANKING_COMMON_DECL_H__
#define __BANKING_COMMON_DECL_H__

#include<iostream>
#include<cstring>
using namespace std;

/* 상수 정보 */
const int NAME_LEN = 20;  //고객의 이름길이

enum{ MAKE = 1, DEPOSIT, WITHDRAW, SHOW, EXIT }; //은행계좌 메뉴정보

enum{ NORMAL = 1, CREDIT };   //계좌종류 정보 

enum{ LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };  //신용신뢰 등급 별 이자율 정보

#endif