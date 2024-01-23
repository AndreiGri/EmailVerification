#include <iostream>
#include <cstdlib>

using namespace std;
// Библиотека символов для первой половины
static char symboLibraryPartFirst[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U',
'V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x',
'y','z','!','#','$','%','&','*','+','-','/','=','?','^','_','`','{','|','}','~','.',
'1','2','3','4','5','6','7','8','9','0' };
// Библиотека символов для второй половины
static char symboLibraryPartSecond[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U',
'V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x',
'y','z','.','-','1','2','3','4','5','6','7','8','9','0'};

static string reversed(string str) {                               // Метод для разворота текста
    for (int i = 0; i < str.length() / 2; i++) {
        swap(str[i], str[(str.length() - 1) - i]);
    }
    return str;
}

static bool separator_check(string text) {                         // Метод подсчитывает кол-во разделителей '@' в email
    int n = 0;
    bool res = true;
    for (char c : text) {
        if (c == '@') {
            n++;
        }
    }
    if (res < 1 || res>1) res = false;
    return res;
}

static string text_delimiter(string text) {                         // Метод отделяет первую часть email
    string new_text = "";
    for (int i = 0; text[i] != '@' && i < text.length(); i++) {
        new_text += text[i];
    }
    return new_text;
}

static bool compare_text(string text1, string text2) {               // Метод считает кол-во совпавших знаков в
    int count = 0;                                                   // половине email и в библиотеке и сравнивает с 
    bool res = true;                                                 // кол-вом знаков в половине email, 
    for (int y = 0; y < text1.length(); y++) {                       // если совпадает то true иначе false
        for (int j = 0; j < text2.length(); j++) {                   // тем определяем допустимость всех введённых
            if (text2[j] == text1[y]) count++;                       // символов
        }
    }
    if (count != text1.length()) res = false;
    return res;
}

static bool dot_count(string text) {                                 // Метод вычисляет есть или нет две точки подряд
    bool dot = true;

    for (int y = 0; y < text.length() - 1; y++) {
        if (text[y] == '.' && text[y + 1] == '.') dot = false;
    }
    return dot;
}

string show_result(bool a, bool b) {                                 // Метод для вывода результата
    string text;
    if (a && b) {
        text = " Yes!";
    }
    else {
        text = " No!";
    }
    return text;
}

static bool emailVerification(string text, string lib, int n) {     // Метод обобщает вычисления всех методов
    bool res = true;                                                // в условии if 
    bool dot = dot_count(text_delimiter(text));
    string newText = text_delimiter(text);
    bool k = separator_check(text);
    bool m = compare_text(text_delimiter(text), lib);

    if (m && newText.length() <= n && newText.length() > 0 && newText[0] != '.'
        && newText[newText.length() - 1] != '.' && k && dot) {
        res = true;
    }
    else {
        res = false;
    }
 
    return res;
}

int main()
{
    string email;
    cout << " Enter E-mail:\n ";                                   // Запрашиваем емейл и записываем его в переменную
    cin >> email;                                                  

    bool a = emailVerification(email, symboLibraryPartFirst, 64);  // высчитываем правильность первой половины адреса
    email = reversed(email);                                       // преворачиваем адрес
    bool b = emailVerification(email, symboLibraryPartSecond, 63); // высчитываем правильность второй половины адреса

    cout << show_result(a, b) << endl;                             // выводим результат

    system("pause > nul");

    return 0;
}
