#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//��������

int main() {
    //������ ����
    int income; //����, ��������
    int family; //������
    int credit; //�ſ�ī�� ����, ��������
    int medical; //�Ƿ��, ���� ����
    int donation; //��α�, ���� ����

    //������ �Է�
    scanf("%d", &income);
    scanf("%d", &family);
    scanf("%d", &credit);
    scanf("%d", &medical);
    scanf("%d", &donation);

    //�������� ���������� �Է��ϰ� �����Ҷ� �� ������ ����
    income = income * 10000;
    credit = credit * 10000;
    medical = medical * 10000;
    donation = donation * 10000;

    //�������� ���
    //�켱 ������ �������� ������ ������ ����
    int family_e; //���� ������ ������ ����
    int credit_e; //�ſ�ī�� ������ ������ ����
    int medical_e; //�Ƿ�� ������ ������ ����
    int donation_e; //��α� ������ ������ ����

    //���� ����
    family_e = (family + 1) * 1000000;

    //�ſ�ī�� ����
    if (credit > 10000000)
    {
        credit_e = (credit - 10000000) * 0.1;
    }
    else
    {
        credit_e = 0;
    }

    //�Ƿ�� ����
    if (medical > income * 0.05)
    {
        medical_e = medical;
    }
    else
    {
        medical_e = 0;
    }

    //��α� ����
    donation_e = donation;

    //�� �����װ� ���� ��� �ҵ� ��� �� ���
    int exemtion; //������
    int taxable_income; //���� ��� �ҵ�

    exemtion = family_e + credit_e + medical_e + donation_e;
    taxable_income = income - exemtion;

    printf("������ �������� %d���Դϴ�.\n", family_e);
    printf("�ſ�ī�� �������� %d���Դϴ�.\n", credit_e);
    printf("�Ƿ�� �������� %d���Դϴ�.\n", medical_e);
    printf("��α� �������� %d���Դϴ�.\n", donation_e);

    //�� ������, ���� ��� �ҵ� ���
    printf("�� �������� %d���Դϴ�.\n", exemtion);
    printf("���� ��� �ҵ��� %d���Դϴ�.\n", taxable_income);

    //�������� ���
    int progressive_tax; //������

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

    //�� ���� ���
    printf("�� ������ %d�Դϴ�.", progressive_tax);
}