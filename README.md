[![Choaib ELMADI - STM32](https://img.shields.io/badge/Choaib_ELMADI-STM32-8800dd)](https://elmadichoaib.vercel.app) ![Status - Learning](https://img.shields.io/badge/Status-Learning-2bd729) ![Platform - STM32](https://img.shields.io/badge/Platform-STM32-f7d620)

# Getting Started with STM32

This repository documents my journey with STM32 microcontrollers while studying "Mastering STM32 - Second Edition" book by Carmine Noviello. The goal is to reinforce concepts, explore embedded systems development, and share useful resources.

<div align="center">

![STM32](./Assets/stm32.png)

</div>

## ARM Buses and Their Types

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

## Development Board

I'm using the `Nucleo-F446RE` board for learning and experimenting with STM32 microcontrollers. This board is based on the `STM32F446RET6` MCU and provides a great balance between performance and flexibility for embedded systems development.

## Contents

- **Docs**: Notes extracted from the book.
- **Examples**: C and Assembly programs.
- **Notes**: Summaries and explanations from various sources. Recommended to check for quick understanding and diverse insights.
- **Projects WS**: Practical implementations and experiments.
- **Nucleo-F446RE**: Contains all the original projects and examples from the book repo.
- **Mastering STM32 - Second Edition.pdf**: The original PDF file of the book.

## STM32 Development Tools

Here are some essential tools for STM32 development:

- **[STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)**: An all-in-one IDE that integrates a compiler, debugger, and project manager for STM32 development.
- **[STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html)**: A graphical tool to configure STM32 microcontrollers and generate initialization code.
- **[STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html)**: A tool for flashing firmware onto STM32 microcontrollers via various interfaces.
- **[STM32CubeCLT](https://www.st.com/en/development-tools/stm32cubeclt.html)**: A command-line tool for building, debugging, and flashing STM32 projects.
- **[STMCUFinder](https://www.st.com/en/development-tools/st-mcu-finder-pc.html)**: A search tool to find STM32 and STM8 microcontrollers and their technical documentation.

## HAL (Hardware Abstraction Layer)

HAL `Hardware Abstraction Layer` is a high-level API provided by `STMicroelectronics` to simplify the development of applications on STM32 microcontrollers. It abstracts the low-level hardware details and provides a standardized way to interact with peripherals.

- **Portability**: Code written using HAL can be easily adapted to different STM32 models with minimal changes.
- **Ease of Use**: HAL provides user-friendly functions for configuring and controlling peripherals without dealing with complex register settings.
- **Reliability**: It includes built-in error handling and debugging features.
- **Compatibility**: Works with STM32CubeIDE, allowing seamless integration with ST's software ecosystem.

HAL is widely used for rapid development, but it has performance trade-offs compared to direct register manipulation or LL (Low Layer) drivers.

## STM32 Animations

I've also created some video animations using `Manim` to visualize some STM32 concepts. These animations aim to simplify complex topics and enhance learning. You can check them out in [manim-animation](https://github.com/Choaib-ELMADI/manim-animation).

<div align="center">

[![Manim](./Assets/manim.png)](https://github.com/Choaib-ELMADI/manim-animation)

[![Processors Bit Banding Feature](./Assets/bit-banding-feature.png)](https://github.com/Choaib-ELMADI/manim-animation/tree/master/Projects/Processors_Bit_Banding_Feature)

</div>

Feel free to explore the repository and contribute!
