#include <stdio.h>

#define SIZE 8

int main()
{
  char binary[SIZE + 2], onesComp[SIZE + 1]; // +2 to account for newline and null terminator
  int i, error = 0;

  printf("Enter %d-bit binary value: ", SIZE);

  if (fgets(binary, sizeof(binary), stdin) != NULL)
  {
    // Remove the newline character, if present
    if (binary[SIZE] == '\n')
    {
      binary[SIZE] = '\0';
    }

    // Validate input length
    for (i = 0; i < SIZE; i++)
    {
      if (binary[i] == '\0')
      {
        printf("Input must be exactly %d bits.\n", SIZE);
        return 1;
      }
    }

    // Compute 1's complement
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
      else
      {
        printf("Invalid input. Please enter only 0s and 1s.\n");
        return 1;
      }
    }

    onesComp[SIZE] = '\0'; // Null-terminate the result

    // Display results
    printf("Original binary = %s\n", binary);
    printf("One's complement = %s\n", onesComp);
  }
  else
  {
    printf("Error reading input.\n");
    return 1;
  }

  return 0;
}
