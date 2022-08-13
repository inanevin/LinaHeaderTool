![Lina](https://user-images.githubusercontent.com/62678643/184497323-6333c592-31dc-4ccf-8b6d-afefe9f051aa.png)

## Lina Header Tool
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT) 

This is a C++ reflection pre-processor tool for Lina Engine. Check out [Lina Engine Project](https://github.com/inanevin/LinaEngine) for more information.

Lina Header Tool is a C++ console program inspired by Epic's Unreal Header tool. It is used within Lina Engine to provide an automated reflection system via macros. This tool processes the .hpp & .h files inside the project directory and finds LINA_CLASS & LINA_PROPERTY macros. LINA_CLASS macros allow a user class to be registered within the ECS system so that will be serialized along with Lina Levels. LINA_PROPERTY macros define how should a variable be exposed to Lina Editor. The tool writes the reflected data into the appropriate Lina source files which are initialized during run-time.
## License

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT) 
Check out [Licence](LICENSE) file.
