#include "lib.h"

int Strlen(const char *s)
{
    int len = 0;
    while (s && s[len] != '\0')
        len++;
    return len;
}

void Strcpy(char *&s1, const char *s2)
{
    if (!s2)
    {
        s1 = nullptr;
        return;
    }
    int len = Strlen(s2);
    s1 = new char[len + 1];
    for (int i = 0; i < len; i++)
        s1[i] = s2[i];
    s1[len] = '\0';
}

int Strcmp(const char *s1, const char *s2)
{
    if (!s1 || !s2)
        return (s1 == s2) ? 0 : (s1 ? 1 : -1);

    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

char Tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + ('a' - 'A');
    }
    return c;
}

char *catTen(const char *hoten)
{
    char *ketqua = new char[100];
    int i = 0, j = 0;
    int trong_tu = 0;
    int tu_so = 0;

    while (hoten[i] == ' ' || hoten[i] == '\t')
        i++;

    ketqua[j++] = Tolower(hoten[i]);
    tu_so = 1;
    trong_tu = 1;
    i++;

    while (hoten[i] != '\0' && hoten[i] != '\n')
    {
        if (hoten[i] == ' ' || hoten[i] == '\t')
        {
            trong_tu = 0;
        }
        else
        {
            if (!trong_tu)
            {
                tu_so++;
                trong_tu = 1;
            }
            if (tu_so >= 2)
            {
                ketqua[j++] = Tolower(hoten[i]);
            }
        }
        i++;
    }
    ketqua[j] = '\0';
    return ketqua;
}

void noiChuoi(char *chuoi1, const char *chuoi2)
{
    int i = 0, j = 0;
    while (chuoi1[i] != '\0')
        i++;

    while (chuoi2[j] != '\0')
    {
        chuoi1[i] = chuoi2[j];
        i++;
        j++;
    }
    chuoi1[i] = '\0';
}
