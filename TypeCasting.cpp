/*
Aspect	                          int(c)                                                       	static_cast<int>(c)
Type of Casting                  	C-style casting (legacy from C).	                            C++-style casting (modern and safer).
Readability	                      Less explicit about intent.	                                  Explicitly shows that you are converting c to int.
Type                              Safety	Allows many unsafe conversions without warnings.	    Provides better compile-time checking for valid conversions.
Best Practices	                  Generally not recommended in modern C++.                     	Recommended for explicit casting in C++.
*/

//Example: Using int(c)
char c = 'A';
cout << int(c) << endl;  // Outputs: 65

//Example: Using static_cast<int>(c)
char c = 'A';
cout << static_cast<int>(c) << endl;  // Outputs: 65
