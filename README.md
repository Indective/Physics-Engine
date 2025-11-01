# Indective's AABB Physics Engine

## Introduction

This engine modles the movement and behavior of an AABB, colliding with another AABB or colliding with the ground.
spawn objects with different velocities, acceleration, and position, and examine how they behave.

---

## 📁 Project Structure

```text
├── build                  # CMake build output
├── include                # Header files
│   └── Physics.hpp
├── src                    # Source code
│   ├── main.cpp
│   └── Physics.cpp
├── external     
│   └── raylib          # raylib lib for gui testing
├── .gitignore
├── CMakeLists.txt
├── .gitmodules
├── LICENSE
└── README.md              # This file
```

---

## ⚙️ Build Instructions

### 📦 Requirements

- C++17-compatible compiler (e.g., `g++`, `clang++`)
- [CMake](https://cmake.org/download/) (3.10+)

### 🛠️ Building

```bash
git clone https://github.com/Indective/Gravity-Sandbox.git
cd Gravity-Sandbox
mkdir build && cd build
cmake ..
make
```

### ▶️ Running

```bash
./engine
```

## 🛠️ Tech Stack

- **C++**
- **CMake**
- **Raylib**

---

## 📄 License

Released under the **MIT License**. See [LICENSE](LICENSE) for details.

---

## 🤝 Contributing

Contributions are welcome! Feel free to open issues or submit pull requests to suggest improvements or new features.
