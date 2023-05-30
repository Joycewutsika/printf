TEAM Project
This team project is a tailor-made function for the C programming language called Printf. It has been enhanced to take several inputs and alternative arguments which is established on how the standard library printf works. We presented this as part of ALX Software Engineering course requirement for grading.
Synopsis
Printf is a function in the C programming language that allows you to  print or information on the screen or terminal. It stands for "print formatted.” This function printf() uses the  ”stdout” , standard output to write and stream with the format and options without making use of any of the standard library file.s  It was made to use a local buffer of 1024 bytes when printing although it can print.
THE FLAG CHARACTERS
CHARACTERS	DESCRIPTION
#  For g and G types, trailing zeros are not removed.
For f, F, e, E, g, G types, the output always contains a decimal point.
For o, x, X types, the text 0, 0x, 0X, respectively, is prepended to non-zero numbers.
0	Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).
-	Left-align the output of this placeholder. (The default is to right-align the output.)
‘ 	The integer or exponent of a decimal has the thousands grouping separator applied.
+	Prepends a plus for positive signed-numeric types. positive = +, negative = -.
(space)	Prepends a space for positive signed-numeric types. positive =  , negative = -. This flag is ignored if the + flag exists.
(The default doesn't prepend anything in front of positive numbers.)
 
The Field
The Width Field
The Width field determines a minimum number of characters to output and is typically used to pad fixed-width fields in tabulated output, where the fields would otherwise be smaller, although it does not cause truncation of oversized fields.

The Precision
The Precision field usually determines a maximum limit on the output, depending on the particular formatting type. For floating-point numeric types, it specifies the number of digits to the right of the decimal point that the output should be rounded. For the string type, it limits the number of characters that should be output, after which the string is truncated.
The precision field may be omitted, or a numeric integer value, or a dynamic value when passed as another argument when indicated by an asterisk *. For example, printf("%.*s", 3, "abcdef") will result in abc being printed.

The Length Modifiers
Modifier		Descripption
i	An integer conversion to a long int or unsigned long int argument
h	
For integer types, causes printf to expect an int-sized integer argument which was promoted from a short.

 
The conversion specifier
Specifier	Description
c	character
s	Print string
p	void* (pointer to void) in an implementation-defined format.
%	Prints a literal % character (this type doesn't accept any flags, width, precision, length fields).
b	
o	unsigned int in octal.

x	unsigned int as a hexadecimal number.

u	Print decimal unsigned int.
Authors
Sandra Boadi & Joyce Wutsika
