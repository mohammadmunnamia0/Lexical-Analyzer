#include <stdio.h>


int main() 
{
    // The expression to analyze
    const char expression[] = "( 12 + x * ( y - 25 ) / z ) % 15";

    printf("Analyzing Expression: %s\n\n", expression);

    int i = 0; // Position in the string
    while (expression[i] != '\0') 
    {
        char ch = expression[i];

        // Skip spaces
        if (ch == ' ') 
            {
                i++;
                continue;
            }

        // Check for parentheses
        if (ch == '(' || ch == ')')
            {
                printf("Token: %c\tType: PARENTHESIS\n", ch);
            }
        // Check for operators
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') 
            {
                printf("Token: %c\tType: OPERATOR\n", ch);
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

        // Check for identifiers (letters like x, y, z)
        else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) 
            {
                printf("Token: %c\tType: IDENTIFIER\n", ch);
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
