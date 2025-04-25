# Bare Metal Programming

`Bare metal programming` refers to writing software that runs directly on the hardware of a microcontroller without the support of an operating system or IDE. It involves manually managing hardware resources, such as memory, peripherals, and interrupts. This approach allows for more control over the hardware and is often used in embedded systems where performance and efficiency are critical.

## C Program Compilation Process

<div align="center">

```mermaid
graph LR
    subgraph Coding...[💻 Coding...]
        User_Application["User Application<br>(.c, .h files)"]
    end

    subgraph Building...[⚒️ Building...]
        Compiler --> Assembler["Assembler<br>(.o files)"]
        Assembler --> Linker["Linker<br>(.exe, .elf files)"]
    end

    subgraph Flashing...[📂 Flashing...]
        Programmer_and_Debugger[Programmer and<br>Debugger]
        Linker --> Programmer_and_Debugger
    end

    subgraph Running...[🏃 Running...]
        Programmer_and_Debugger --> Flash[uC Flash<br>Memory]
    end

    User_Application --> Compiler["Compiler<br>(.s, .asm files)"]

    class Coding... coding
    class User_Application user_app;
    class Building... building;
    class Compiler compiler;
    class Assembler assembler;
    class Linker linker;
    class Flashing... flashing;
    class Programmer_and_Debugger p_and_d;
    class Running... running;
    class Flash flash;

    classDef coding fill:#3D90D710,stroke:#3D90D7,stroke-width:2px,color:#3D90D7;
    classDef user_app fill:#FE774310,stroke:#FE7743,stroke-width:2px,color:#FE7743;
    classDef building fill:#3A59D110,stroke:#3A59D1,stroke-width:2px,color:#3A59D1;
    classDef compiler fill:#BE598510,stroke:#BE5985,stroke-width:2px,color:#BE5985;
    classDef assembler fill:#5F8B4C10,stroke:#5F8B4C,stroke-width:2px,color:#5F8B4C;
    classDef linker fill:#A89C2910,stroke:#A89C29,stroke-width:2px,color:#A89C29;
    classDef flashing fill:#81E7AF10,stroke:#81E7AF,stroke-width:2px,color:#81E7AF;
    classDef p_and_d fill:#FE774910,stroke:#FE7749,stroke-width:2px,color:#FE7749;
    classDef running fill:#F5C45E10,stroke:#F5C45E,stroke-width:2px,color:#F5C45E;
    classDef flash fill:#E5202010,stroke:#E52020,stroke-width:2px,color:#E52020;

    linkStyle 4 stroke:#FE7743,stroke-width:2px;
    linkStyle 0 stroke:#BE5985,stroke-width:2px;
    linkStyle 1 stroke:#5F8B4C,stroke-width:2px;
    linkStyle 2 stroke:#A89C29,stroke-width:2px;
    linkStyle 3 stroke:#FE7749,stroke-width:2px;
```

| Preprocessor                           | Compiler                 | Assembler                        | Linker                     |
| -------------------------------------- | ------------------------ | -------------------------------- | -------------------------- |
| - Remove comments                      | - Generate assembly code | - Generate object (binary) files | - Combine object files     |
| - Replace macros                       |                          |                                  | - Link libraries           |
| - Include header files                 |                          |                                  | - Produce final executable |
| - Produce translation unit (`.i file`) |                          |                                  |                            |

</div>

# ARM Buses and Their Types

<div align="center">

```mermaid
graph TD
    Memory_Controller[Memory Controller]
    AHB_External_Bridge[AHB External Bridge]

    subgraph 1[ ]
        ARM_Processor[ARM Processor]
        Interrupt_Controllers[Interrupt<br>Controllers]
        AHB

        ARM_Processor <--> Interrupt_Controllers
        ARM_Processor <---> AHB

        AHB <---> Memory_Controller
        AHB <---> AHB_External_Bridge
    end

    subgraph 2[ ]
        AHB_APB_Bridge[AHB - APB Bridge]

        AHB_APB_Bridge <--> USART
        AHB_APB_Bridge <--> RTC
        AHB_APB_Bridge <--> Ethernet
        AHB_APB_Bridge <--> Timers
    end

    AHB <--> AHB_APB_Bridge

    class 1 1;
    class 2 2;
    class ARM_Processor arm;
    class Interrupt_Controllers ic;
    class AHB ahb;
    class Memory_Controller mc;
    class AHB_External_Bridge ahb_eb;
    class AHB_APB_Bridge ahb_apb;
    class USART usrat;
    class RTC rtc;
    class Ethernet ethernet;
    class Timers timers;

    classDef 1 fill:transparent,stroke:transparent;
    classDef 2 fill:transparent,stroke:transparent;
    classDef arm fill:#FE774310,stroke:#FE7743,stroke-width:2px,color:#FE7743;
    classDef ic fill:#F5C45E10,stroke:#F5C45E,stroke-width:2px,color:#F5C45E;
    classDef ahb fill:#81E7AF10,stroke:#81E7AF,stroke-width:2px,color:#81E7AF;
    classDef mc fill:#3A59D110,stroke:#3A59D1,stroke-width:2px,color:#3A59D1;
    classDef ahb_eb fill:#FFA95510,stroke:#FFA955,stroke-width:2px,color:#FFA955;
    classDef ahb_apb fill:#3D90D710,stroke:#3D90D7,stroke-width:2px,color:#3D90D7;
    classDef usrat fill:#BE598510,stroke:#BE5985,stroke-width:2px,color:#BE5985;
    classDef rtc fill:#5F8B4C10,stroke:#5F8B4C,stroke-width:2px,color:#5F8B4C;
    classDef ethernet fill:#E5202010,stroke:#E52020,stroke-width:2px,color:#E52020;
    classDef timers fill:#A89C2910,stroke:#A89C29,stroke-width:2px,color:#A89C29;

    linkStyle 0 stroke:#FE7743,stroke-width:2px;
    linkStyle 1 stroke:#FE7743,stroke-width:2px;
    linkStyle 2 stroke:#81E7AF,stroke-width:2px;
    linkStyle 3 stroke:#81E7AF,stroke-width:2px;
    linkStyle 8 stroke:#81E7AF,stroke-width:2px;
    linkStyle 4 stroke:#3D90D7,stroke-width:2px;
    linkStyle 5 stroke:#3D90D7,stroke-width:2px;
    linkStyle 6 stroke:#3D90D7,stroke-width:2px;
    linkStyle 7 stroke:#3D90D7,stroke-width:2px;
```

</div>

- `Interrupt Controllers` determine which peripheral can access the processor at specified times.
- `AHB` stands for `Advanced High-Performance Bus`.
- `Memory Controller` connects different types of memory to the processor.
- `APB` stands for `Advanced Peripheral Bus`.
- The `AHB to APB` bridge is an AHB slave, providing an interface between the high-speed AHB and the low-power APB.

# GPIOs Variant Configurations

<div align="center">

![Input Mode - High Impedance](../Assets/4-1%20input-mode-high-impedance.png)

![Input Mode - Pull UP](../Assets/4-2%20input-mode-pull-up.png)

![Input Mode - Pull DOWN](../Assets/4-3%20input-mode-pull-down.png)

![Output Mode - Push Pull](../Assets/4-4%20output-mode-push-pull.png)

![Output Mode - Open Drain](../Assets/4-5%20output-mode-open-drain.png)

</div>
