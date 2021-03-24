# C++ to PostScript
C++ to PostScript Translator 

CPS (C++ to PostScript) is a C++ library that allows users to specify drawings at a high-level abstraction (C++) and output drawings as PostScript.

## Files in project src directory:
| Name | Purpose |
| --- | ---- |
| shape | Base class that other shapes inherit from |
| basic_shapes | Shapes that take only ints/doubles |
| complex_shapes | Meta shapes |
| interface | User interaction code |

## Running tests
```
mkdir build
cd build
cmake ..
make
./test_suite
```
## User interface usage
```cpp
#include "src/headers/interface.hpp"
#include <fstream>

int main() {
    std::ofstream output("file.ps");
    auto rectangle = makeRectangle(50,100);
    setCursor(output,200.0,200.0);
    rectangle->draw(output);
    output.close();
    return 0;
}
```
## Thoughts on PostScript

### Q: Is the language expressive enough?
#### A: With polygons and circles, the shape seems like it could do a lot of things. Partial shapes and filling shapes are not supported.
### Q: Are the shape abstractions well-designed, or not?
#### A: The shape abstractions allow developers to expand the language with new shapes.
### Q: Do the shape abstractions make certain drawings easy/difficult to create?
#### A: If you want precise/intricate shapes it will take time and effort to create. 
### Q: If we were to design the shape language from scratch, what would we do differently?
#### A: 
 - Allow colors 
 - Allow filling of shapes
 - Better cursor moving
 - Look more closely at PostScript to see what options are available to us
 - Find a better way to implement polygon
 - Better testing process