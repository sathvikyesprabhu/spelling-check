# To store the source code

## How to write the source code?

* **Name_of_module.h**  
The _interface_ of the module.  
Should contain function prototypes, constants  
**Note**: Remember to have [include guards](https://en.wikipedia.org/wiki/Include_guard)

* **Name_of_module.c**  
The _implementation_ of the module.  
Should contain function definitions

* **Some_file.c**  
The _user_ of the module.  
Include the header file & use the function & constants  
**Note**: Include the custom header files as ```#include "custom-module-name.h"```

_See_ [Separate Compilation](https://www.cs.bu.edu/teaching/c/separate-compilation/) for more details
