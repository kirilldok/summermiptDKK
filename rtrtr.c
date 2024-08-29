#include <stdio.h>
#include <math.h> 
#include <assert.h>
#include <stdbool.h>
#include <string.h>

struct Window
{
    int Xmin;
    int Xmax;
    int Ymin;
    int Ymax;
};

bool viezd(Window okno, int N, int M);
bool Naezd(Window okno1, Window okno2);
// Заданы размеры фасада здания N x M "клеточек".
// По оси OX фасад расположен в интервале [0; N], по оси OY - в интервале [0; M].
// Заданы K штук окон этого здания (каждое окно - прямоугольник, нарисованный "по клеточкам" параллельно осям координат).
// Определить, всё ли в порядке с данным фасадом. Фасад считается не в порядке,
// если (а) окна вылезают за границы фасада или (б) окна перекрываются между собой.
// (Окно, прилегающее к границе фасада - это нормально. Если окна не перекрываются, но имеют общую границу - так тоже можно.
//  Архитектор художник, он так видит. А современная техника позволяет строить ещё и не такое.)

// Формат входных данных
// На первой строке через пробел целые числа N и M - размер фасада.
//  На второй строке целое число K - количество окон. Далее каждое окно в новой строке.
//   Для окна заданы через пробел minX max X minY maxY.

// Формат выходных данных
// Строка correct, если со зданием всё в порядке. Строка broken, если что-то за рамками разумного.

int main()
{
    int N = 0, M = 0, K = 0;
    scanf("%d %d", &N, &M);
    scanf("%d", &K);
    int Xmin = 0, Xmax = 0, Ymin = 0, Ymax = 0;
    Window Arrokno[100] = { 0 };

    for(int i = 0; i < K; i++)
    {
        scanf("%d %d %d %d", &Xmin, &Xmax, &Ymin, &Ymax);
        Window okno = {Xmin, Xmax, Ymin, Ymax};
        Arrokno[i] = okno;
    }

    bool t = 1;
    for(int i = 0; i < K; i++)
    {
        if (!viezd(Arrokno[i], N, M))
        {
            printf("broken");
            t = 0;
            break;
        }
        for(int j = 0; j < K - i; j++)
        {
            if (!Naezd(Arrokno[j], Arrokno[j + 1]))
            {
                printf("broken");
                t = 0;
                break;
            }
        }
    }

    if (t)
    {
        printf("correct");
    }
}


bool viezd(Window okno, int N, int M)
{
    if ((okno.Xmin >= 0) && (okno.Xmax <= N) && (okno.Ymin >= 0) && (okno.Ymax <= M))
    {
        return true;
    }
    return false;

}


bool Naezd(Window okno1, Window okno2)
{
    if ((okno1.Xmin < (2 * okno2.Xmin - okno2.Xmax)) || (okno2.Xmin < (2 * okno1.Xmin - okno1.Xmax)) 
    || (okno1.Ymin < (2 * okno2.Ymin - okno2.Ymin)) || (okno2.Ymin < (2 * okno1.Ymin - okno1.Ymin)))
    {
        return true;
    }

    return false;
}





