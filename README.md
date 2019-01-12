# ChaiScript Extras SFML 
Provides [ChaiScript](https://github.com/ChaiScript/ChaiScript) bindings to [SFML](https://github.com/SFML/SFML).

This is currently just a proof of concept. Far from complete Any assistance in getting this up and running would be much appreciated.

Not all of SFML is exposed

## Usage

1. Include the module source...
    ```cpp
    #include "ChaiScript_Extras_SFML/include/chaiscript/extras/sfml.hpp"
    ```

2. Add the module to the ChaiScript instance...
    ```cpp
    auto SFMLlib = chaiscript::extras::sfml::bootstrap();
    chai.add(SFMLlib);
    ```
3. Use SFML in ChaiScript...
    ```c
        //TODO
    ```
