## Predefined macros

- BIN: target binary file
- SRC\_DIR: default source directory
- C\_SRC\_DIR: c source directory, if you have not defined this macro, Makefile will use SRC\_DIR as C\_SRC\_DIR
- C\_SRC\_FILES: c source files, if you defined this macro, Makefile will not find sources file under C\_SRC\_DIR automatically
- CXX\_SRC\_DIR: cpp source directory, if you have not defined this macro, Makefile will use SRC\_DIR as C\_SRC\_DIR
- CXX\_SRC\_FILES: cpp source files, if you defined this macro, Makefile will not find sources file under CXX\_SRC\_DIR automatically
- TARGET\_DIR: targets makefiles directory
- OBJ\_DIR: objects directory
- CC: C compiler
- CXX: C++ compiler
- LD: Linker
- CFLAGS: C compiler flags
- CXXFLAGS: C++ compiler flags
- LDFLAGS: Linker flags
