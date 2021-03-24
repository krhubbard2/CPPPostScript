# C++ to PostScript
C++ to PostScript Translator

## Files in project src directory:
| Name | Purpose |
| --- | ---- |
| shape | Base class that other shapes inherit from |
| basic_shapes | Shapes that take only ints/doubles |
| complex_shapes | Meta shapes |
| interface | User interaction code |

## Running tests
```
cmake build/
./build/test_suite
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
#### A: With polygons and circle's the shape seems like it could do a lot of things.
### Q: Are the shape abstractions well-designed, or not?
#### A: 
### Q: Do the shape abstractions make certain drawings easy/difficult to create?
#### A: 
### Q: If we were to design the shape language from scratch, what would we do differently?