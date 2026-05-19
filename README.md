# Dynamic ASCII Art Suite

An advanced, premium-grade **Digital Image to ASCII Art Generator** developed as a university programming assignment. This project serves as an academic showcase of C++ image processing, dynamic downsampling, Rec. 601 grayscale intensity mapping, and standard graphics interfaces.

This suite features two distinct, production-ready interfaces:
1. **Universal C++ CLI Tool**: Headless, highly-optimized C++ application backed by `stb_image.h` to natively support JPEG, PNG, BMP, GIF, and PSD without external compiled dependencies.
2. **Interactive HTML5 Web Dashboard (Lumina)**: A beautiful single-page creative interface utilizing HTML5 Canvas for real-time slider-based image scaling, contrast adjustment, and dynamic inline color styling.

---

## 🖼️ Before & After Showcase

Below is a live rendering comparison showcasing how the generator handles digital image inputs:

| Original Image (`before.png`) | Generated ASCII Art Output |
|:---:|:---:|
| <img src="before.png" width="280" alt="Original Heart Image"> | <pre>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@%%%%%%@@@@@@@@%%%%%%@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@%#########%%@@%%#########%@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@%############%%############%@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@%############################%@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@%############################%@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@%############################%@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@%##########################%@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@%########################%@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@%####################%@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@%################%@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@%############%@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@%########%@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@%####%@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@<br>@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@</pre> |

---

## 🎓 Academic Portfolio Showcase

> [!NOTE]
> This repository represents a completed, polished C++ programming assignment for the **University of Academic Excellence**. It demonstrates proficiency in file I/O streams, binary data decoding, memory management, array flat-indexing, and interactive interface design.

---

## 🚀 Key Features

### 💻 1. C++ CLI Application
* **Universal Format Ingestion**: Uses a lightweight single-header `stb_image` wrapper to process almost any commercial image file (`.png`, `.jpg`, `.bmp`, `.gif`, etc.).
* **Pixel Density Rescaling**: Automatically maps and downsamples regional pixel blocks to fit character grid boundaries of typical monospace terminal screens.
* **Rec. 601 Grayscale Translation**: Uses standard human-eye perception luminance weighting to map color channels to individual brightness values:
  $$\text{Luminance} = 0.299R + 0.587G + 0.114B$$
* **Calibrated Output Mapping**: Maps brightness ranges to custom ink-density standard glyph patterns (`@%#*+=-:. `).

### 🎨 2. Lumina Web Dashboard (`ascii_art_app.html`)
* **Glassmorphic Theme**: Designed with an ultra-modern dark mode layout using sleek glowing gradients and responsive canvas rendering.
* **Aspect Ratio Compensation**: Built-in automatic aspect locking to correct the classic $2:1$ vertical stretch of monospace character fonts.
* **Full-Color Styling Mode**: Embeds custom inline-colors (`rgb(R, G, B)`) for each character to match original source colors.
* **Multi-Palette Library**: Supports blocks, binary characters, standard densities, and custom character palette overrides.

---

## 🛠️ Getting Started

### 📋 Prerequisites
- A standard C++11 compliant compiler (`g++` or `clang++`).

### 📦 Compilation
Compile the program in a single step with standard optimization:
```bash
g++ -std=c++11 home.cpp -o home
```

### 🏃 Running the CLI Tool
Execute the binary by passing your target image followed by custom character grid dimensions:
```bash
# Usage: ./home <image_path> [char_width] [char_height]
./home test.ppm 80 40
```

### 🌐 Launching the Web App
Simply double-click or open **`ascii_art_app.html`** in any modern web browser to load the interactive dashboard, drag-and-drop your images, and play with live sizing parameters.
