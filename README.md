# MyEarth3D
This project is an extension of the [myworld](https://github.com/Louis-dub/myworld) project, in which the edited map is no longer flat but spherical.
This project will also add more editing options.

## Feature

## Technologies Used
- **C**: For isometric calculations, memory management...
- **CSFML**: For rendering the window and the various graphical elements

## Installation

Prerequisites: Running on Linux

### Installing CSFML

**On Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install libcsfml-dev
```

**On Arch Linux:**
```bash
sudo pacman -S csfml
```

**On Fedora:**
```bash
sudo dnf install csfml-devel
```

If CSFML is not available in your distribution's repositories, you can build it from source: see the [official CSFML build instructions](https://github.com/SFML/CSFML#building-csfml).

**Clone the repository:**

- With URL:
```bash
git clone https://github.com/Louis-dub/myearth3d.git
```

- With SSH:
```bash
git clone git@github.com:Louis-dub/myearth3d.git
```

**Compile the program:**

```bash
make
```

**Run the project:**

```bash
./my_earth
```

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
