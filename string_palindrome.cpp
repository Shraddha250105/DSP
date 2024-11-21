#include <iostream>
using namespace std;
class String
{
    char s1[100], s2[100];

public:
    void accept();
    void length();
    void copy();
    void compare();
    void reverse();
    void concat();
    void palindrome();
    void count();
};

void String::accept()
{
    cout << "Enter the 1st string: ";
    cin >> s1;
    cout << "Enter the 2nd string: ";
    cin >> s2;
}

void String::length()
{
    int len1 = 0, len2 = 0;
    int i;

    for (i = 0; s1[i] != '\0'; i++)
    {
        len1++;
    }
    cout << "Length of 1st String: " << len1 << endl;

    for (i = 0; s2[i] != '\0'; i++)
    {
        len2++;
    }
    cout << "Length of 2nd String: " << len2 << endl;
}

void String::copy()
{
    int i;
    for (i = 0; s2[i] != '\0'; i++)
    {
        s1[i] = s2[i];
    }
    s1[i] = '\0';

    cout << "1st String after copying: " << s1 << endl;
    cout << "2nd String: " << s2 << endl;
}

void String::compare()
{
    int i, flag = 0;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
    {
        if (s1[i] != s2[i])
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0 && s1[i] == '\0' && s2[i] == '\0')
    {
        cout << "Strings are equal." << endl;
    }
    else
    {
        cout << "Strings are not equal." << endl;
    }
}

void String::reverse()
{
    char temp;
    int len = 0;
    while (s1[len] != '\0')
    {
        len++;
    }
    for (int i = 0; i < len / 2; i++)
    {
        temp = s1[i];
        s1[i] = s1[len - i - 1];
        s1[len - i - 1] = temp;
    }
    cout << "Reversed 1st String: " << s1 << endl;
}

void String::concat()
{
    int i = 0, j = 0;

    while (s1[i] != '\0')
    {
        i++;
    }

    while (s2[j] != '\0')
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';

    cout << "Concatenated String: " << s1 << endl;
}

void String::palindrome()
{
    int len = 0;
    while (s1[len] != '\0')
    {
        len++;
    }

    int i, flag = 1;
    for (i = 0; i < len / 2; i++)
    {
        if (s1[i] != s1[len - i - 1])
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {
        cout << "1st String is a palindrome." << endl;
    }
    else
    {
        cout << "1st String is not a palindrome." << endl;
    }
}

int main()
{
    String str;
    int choice, ch;

    do
    {
        cout << "\nString Operations Menu:\n";
        cout << "1. Accept \n";
        cout << "2. Length \n";
        cout << "3. Copy \n";
        cout << "4. Compare \n";
        cout << "5. Reverse \n";
        cout << "6. Concatenate\n";
        cout << "7. Check Palindrome of 1st String\n";
        cout << "8. Exit\n";
        cout << "Enter your choice (1-9): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            str.accept();
            break;
        case 2:
            str.length();
            break;
        case 3:
            str.copy();
            break;
        case 4:
            str.compare();
            break;
        case 5:
            str.reverse();
            break;
        case 6:
            str.concat();
            break;
        case 7:
            str.palindrome();
            break;

        case 8:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 9.\n";
            break;
        }
        cout << "do you want to continue:(0/1):";
        cin >> ch;
    } while (ch == 1);

    return 0;
}