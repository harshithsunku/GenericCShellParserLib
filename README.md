# GenericCShellParserLIB

A comprehensive and versatile C library for parsing command-line interfaces. GenericCShellParserLIB is designed to facilitate robust CLI functionalities in C projects, featuring a range of built-in commands like show, config, debug, and clear. Ideal for developers seeking to integrate a powerful yet customizable shell parser into their applications.

## Features

- **Wide Range of Commands:** Includes common commands like show, config, debug, clear, and more.
- **Easy Integration:** Designed for seamless integration into existing C projects.
- **Customizability:** Easily extendable to add new commands specific to your application needs.
- **Robust Parsing:** Efficient and accurate parsing of command-line input.

## Getting Started

### Prerequisites

- Standard C development environment
- Basic understanding of command-line interfaces and C programming

### Installation

Clone the repository:

```bash
git clone https://github.com/harshithsunku/GenericCShellParserLIB.git
```
Install Readline library:
```bash
sudo apt-get install libreadline-dev
```

Compile the library:

```bash
//To Build
make

//To clean
make clean
```
### Usage

Here's a simple example of how to use GenericCShellParserLIB in your C application:

```c
int
main(int argc, char **argv){

    init_libcli();
    param_t *show   = libcli_get_show_hook();
    param_t *debug  = libcli_get_debug_hook();
    param_t *config = libcli_get_config_hook();
    param_t *clear  = libcli_get_clear_hook();
    param_t *run    = libcli_get_run_hook();


    support_cmd_negation(config);
    /*Do not add any param in config command tree after above line*/
    start_shell();
    return 0;
}

```
For more detailed documentation, see [docs/documentation.md](docs/documentation.md).

## Contributing

Contributions to GenericCShellParserLIB are welcome! Please read our [Contributing Guidelines](CONTRIBUTING.md) for more information on how to contribute.

## License

This project is licensed under the [GNU General Public License v3 (GPLv3)](LICENSE).


![GPLv3 License](https://img.shields.io/badge/License-GPLv3-blue.svg)




