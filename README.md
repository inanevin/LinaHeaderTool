![Lina](Docs/Images/linalogofull_medium.png)

## Lina Header Tool
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT) 

Lina Header Tool is a C++ console program inspired by Epic's Unreal Header tool. It is used within Lina Engine to provide an automated reflection system via macros. This tool processes the .hpp & .h files inside the project directory and finds LINA_CLASS & LINA_PROPERTY macros. LINA_CLASS macros allow a user class to be registered within the ECS system so that will be serialized along with Lina Levels. LINA_PROPERTY macros define how should a variable be exposed to Lina Editor. The tool writes the said data to a reflection file, which is then picked-up by Lina during run-time and turned into appropriate commands.
## License

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT) 
Check out [Licence](LICENSE) file.



