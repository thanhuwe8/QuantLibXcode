# QuantLibXcode
- In this repository, we will provide several examples to implement the classes and functions available in QuantLib library
- Code is written in Xcode (Mac OS).
- UML diagram will be provided in several implementation.

# Version
- Pre-built QuantLib installed from brew. Version 1.13
- Pre-built Boost installed from brew. Version 1.68

# Note for implementation
- The newest version of Quantlib is 1.15 (released Feb 2019) which incorporate the standard smart pointer (ext::shared_ptr) instead of the boost::shared_ptr. To use the syntax suggested by official documentation, please include "ext.cpp" and "ext.hpp" in the preprocessor of the main.cpp.

# Reference
- Ballabio, Luigi. "Implementing QuantLib." (2005).
- Ametrano, Ferdinando, et al. "QuantLib: A free/open-source library for quantitative finance." (2018).

# License
- The project is licensed under GPL3 License.
