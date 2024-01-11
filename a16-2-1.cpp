
 #include <directory/headerfile.hpp> // Compliant
 #include <headerfile.hpp> // Compliant
 #include "directory/headerfile.hpp" // Compliant
 #include "headerfile.hpp" // Compliant
 #include <directory/*.hpp> // Non-compliant
 #include <header’file.hpp> // Non-compliant
 #include <"headerfile.hpp"> // Non-compliant
 #include <directory\\headerfile.hpp> // Non-compliant