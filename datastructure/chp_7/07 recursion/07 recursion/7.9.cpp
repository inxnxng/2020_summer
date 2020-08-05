#include <stdio.h>
#include<iostream>
#define WHITE 0 // 0�� WHITE�� ����
#define BLACK 1 // 1�� BLACK�̶� ����
// [����] YELLOW�� ���ʿ��Ͽ� �����Ͽ����ϴ�.(ó������ 2�� �ʱ�ȭ �߽��ϴ�)

int screen[10][10] = // �迭 �ʱ�ȭ �� �ٷ� �ʱⰪ�� �־��ݴϴ�.
{ {2,2,2,2,2,2,2,2,2,2},
 {2,2,2,2,2,2,2,2,2,2},
 {2,2,2,0,0,0,0,2,2,2},
 {2,2,2,2,0,0,0,2,2,2},
 {2,2,2,2,0,0,0,2,2,2},
 {2,2,2,2,0,0,0,0,2,2},
 {2,2,2,2,0,2,2,2,2,2},
 {2,2,2,2,0,2,2,2,2,2},
 {2,2,2,2,0,2,2,2,2,2},
 {2,2,2,2,2,2,2,2,2,2} };

// screen �迭�� �о���̱�(��ȯ ȣ�⿡�� ����)
char read_pixel(int x, int y)
{
    return screen[x][y];
}

// �ش� x, y ��ġ�� color(BLACK)�� ä���(��ȯ ȣ�⿡�� ����)
void write_pixel(int x, int y, int color)
{
    screen[x][y] = color;
}


void result_print()
{
    int i, j; // �ε��� i, j ����
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", screen[i][j]); // 10x10 ũ���� �迭 ���(�����ֱ�)
        }
        printf("\n");
    }
}

// ���� ä��� �˰��� 
void flood_fill(int x, int y)
{
    if (read_pixel(x, y) == WHITE) // read_pixel �Լ� ȣ���� ����� 0�� �߰��ϸ�
    {
        write_pixel(x, y, BLACK); // write_pixel �Լ��� ȣ���ؼ� BLACK(1)�� ä���
        flood_fill(x - 1, y); // ��ȯȣ��(x-1��° ��ġ)
        flood_fill(x + 1, y); // ��ȯȣ��(x+1��° ��ġ) 
        flood_fill(x, y - 1); // ��ȯȣ��(y-1��° ��ġ)
        flood_fill(x, y + 1); // ��ȯȣ��(y+1��° ��ġ)
    }
    result_print();
    std::cout << std::endl;
}



int main()
{

    printf("���� ä��� ��� ����\n-------------------\n");
    result_print(); // �ʱⰪ���� ������ �迭�� ��� 

    flood_fill(4, 4); // ä��� ����(���� ��ġ: 4,4)

    printf("������ ä��� ��ȯ ȣ�� �Լ� �۵�\n-------------------\n");
    result_print(); // flood_fill �Լ� ȣ�� �� ���(�迭) ��� 

    return 0;
}