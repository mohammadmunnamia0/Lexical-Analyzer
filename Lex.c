#include <stdio.h>

int main() 
{
    // The expression to analyze (using 'sqrt' instead of '√')
    const char expression[] = "Calculate=sqrt[{(((13*20)+50)-80)/2}]%2";

    printf("Analyzing Expression: %s\n\n", expression);

    int i = 0; // Position in the string
    while (expression[i] != '\0') 
    {
        char ch = expression[i];

        // Check for parentheses, braces, or brackets
        if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']') 
        {
            printf("Token: %c\tType: BRACE_OR_PARENTHESIS_OR_BRACKET\n", ch);
        }
        // Check for operators
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=' || ch == ';') 
        {
            printf("Token: %c\tType: OPERATOR\n", ch);
        }
        // Check for 'sqrt' function
        else if (ch == 's' && expression[i + 1] == 'q' && expression[i + 2] == 'r' && expression[i + 3] == 't') 
        {
            printf("Token: sqrt\tType: FUNCTION\n");
            i += 3; // Skip the additional characters of 'sqrt'
        }
        // Check for numbers
        else if (ch >= '0' && ch <= '9') 
        {
            printf("Token: %c", ch);
            i++;

            while (expression[i] >= '0' && expression[i] <= '9') 
            { // Handle multi-digit numbers
                printf("%c", expression[i]);
                i++;
            }

            printf("\tType: NUMBER\n");
            continue; // Skip increment at the end of the loop
        }
        // Check for identifiers (letters like Calculate)
        else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) 
        {
            printf("Token: %c", ch);
            i++;

            while ((expression[i] >= 'A' && expression[i] <= 'Z') || 
                   (expression[i] >= 'a' && expression[i] <= 'z')) 
            { // Handle multi-character identifiers
                printf("%c", expression[i]);
                i++;
            }

            printf("\tType: IDENTIFIER\n");
            continue; // Skip increment at the end of the loop
        }
        // Handle unknown characters
        else 
        {
            printf("Token: %c\tType: UNKNOWN\n", ch);
        }

        i++; // Move to the next character
    }

    return 0;
}
