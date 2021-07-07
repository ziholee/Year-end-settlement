#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//연말정산

int main() {
    //변수를 선언
    int income; //수입, 만원단위
    int family; //가족수
    int credit; //신용카드 사용액, 만원단위
    int medical; //의료비, 만원 단위
    int donation; //기부금, 만원 단위

    //변수를 입력
    scanf("%d", &income);
    scanf("%d", &family);
    scanf("%d", &credit);
    scanf("%d", &medical);
    scanf("%d", &donation);

    //변수값은 만원단위로 입력하고 저장할땐 원 단위로 저장
    income = income * 10000;
    credit = credit * 10000;
    medical = medical * 10000;
    donation = donation * 10000;

    //공제액을 계산
    //우선 각각의 공제액을 저장할 변수를 선언
    int family_e; //가족 공제를 저장할 변수
    int credit_e; //신용카드 공제를 저장할 변수
    int medical_e; //의료비 공제를 저장할 변수
    int donation_e; //기부금 공제를 저장할 변수

    //가족 공제
    family_e = (family + 1) * 1000000;

    //신용카드 공제
    if (credit > 10000000)
    {
        credit_e = (credit - 10000000) * 0.1;
    }
    else
    {
        credit_e = 0;
    }

    //의료비 공제
    if (medical > income * 0.05)
    {
        medical_e = medical;
    }
    else
    {
        medical_e = 0;
    }

    //기부금 공제
    donation_e = donation;

    //총 공제액과 과세 대상 소득 계산 및 출력
    int exemtion; //공제액
    int taxable_income; //과세 대상 소득

    exemtion = family_e + credit_e + medical_e + donation_e;
    taxable_income = income - exemtion;

    printf("가족수 공제액은 %d원입니다.\n", family_e);
    printf("신용카드 공제액은 %d원입니다.\n", credit_e);
    printf("의료비 공제액은 %d원입니다.\n", medical_e);
    printf("기부금 공제액은 %d원입니다.\n", donation_e);

    //총 공제액, 과세 대상 소득 출력
    printf("총 공제액은 %d원입니다.\n", exemtion);
    printf("과세 대상 소득은 %d원입니다.\n", taxable_income);

    //누진세를 계산
    int progressive_tax; //누진세

    if (taxable_income <= 10000000)
    {
        progressive_tax = taxable_income * 1 / 100;
    }
    else if (taxable_income <= 20000000)
    {
        progressive_tax = 100000 + (taxable_income - 10000000) * 3 / 100;
    }
    else if (taxable_income <= 30000000)
    {
        progressive_tax = 100000 + 300000 + (taxable_income - 20000000) * 10 / 100;
    }
    else
    {
        progressive_tax = 100000 + 300000 + 1000000 + (taxable_income - 30000000) * 20 / 100;
    }

    //총 세금 출력
    printf("총 세금은 %d입니다.", progressive_tax);
}