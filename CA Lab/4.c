#include <stdio.h>
#define SIZE 8

int main()
{
  char binary[SIZE + 2], onesComp[SIZE + 1], twosComp[SIZE + 1];
  int i, carry = 1;

  printf("Enter %d-bit binary value: ", SIZE);

  // Read user input
  if (fgets(binary, sizeof(binary), stdin) != NULL)
  {
    // Remove newline character if present
    if (binary[SIZE] == '\n')
    {
      binary[SIZE] = '\0';
    }

    // Validate input length
    for (i = 0; i < SIZE; i++)
    {
      if (binary[i] != '0' && binary[i] != '1')
      {
        printf("Invalid input. Please enter only 0s and 1s.\n");
        return 1;
      }
    }

    // Calculate 1's complement
    for (i = 0; i < SIZE; i++)
    {
      if (binary[i] == '1')
      {
        onesComp[i] = '0';
      }
      else if (binary[i] == '0')
      {
        onesComp[i] = '1';
      }
    }
    onesComp[SIZE] = '\0'; // Null-terminate 1's complement string

    // Calculate 2's complement (add 1 to 1's complement)
    for (i = SIZE - 1; i >= 0; i--)
    {
      if (onesComp[i] == '1' && carry == 1)
      {
        twosComp[i] = '0';
      }
      else if (onesComp[i] == '0' && carry == 1)
      {
        twosComp[i] = '1';
        carry = 0; // Carry is used up
      }
      else
      {
        twosComp[i] = onesComp[i]; // No carry, copy the bit
      }
    }
    twosComp[SIZE] = '\0'; // Null-terminate 2's complement string

    // Display results
    printf("Original binary = %s\n", binary);
    printf("One's complement = %s\n", onesComp);
    printf("Two's complement = %s\n", twosComp);
  }
  else
  {
    printf("Error reading input.\n");
    return 1;
  }

  return 0;
}
