# PotatRaycer: A C++ Raytracing Engine

Welcome to PotatRaycer, a versatile raytracing engine written in C++ that uses the raytracing technique to create highly realistic images by simulating the path of light through scenes defined in a custom scene description file.

## Installation

Clone this repository and compile the project using either Makefile or CMake:

```bash
git clone https://github.com/MathisGheri/PotatRaycer_CI-CD.git
cd potatraycer
make
# Or using CMake
mkdir -p build && cd build
cmake ..
make && cd ..
```
## Documentation

To access the project's documentation, run the following command:
```bash
doxygen Doxyfile
```
Then drag and drop into ur browser the **index.html** file, inside the **`docs/html/`** folder.

## Usage

To render an image with PotatRaycer, run:
```bash
./raytracer <SCENE_FILE>
```
Where `<SCENE_FILE>` is the path to a scene configuration file. Example scene files are included in the **`scenes/`** directory.

## Features

**PotatRaycer** supports a range of features that allow you to model complex scenes with various lighting and material properties:

- **Primitives Supported**: Spheres, Planes, OBJ files
- **Lighting**:
  - Directional Light
  - Ambient Light
- **Materials**:
  - Flat color materials
  - Support for transparency and reflection
  - Metal, lambertian, dielectric, Texture (with file)
- **Output**: Renders images to PPM files, with SFML real time render.

## How to ?

[How to add a new Primitive ?](docs/new_primitive.md)
[How to configure a scene file ?](docs/scene_file.md)
[How to use the logger ?](docs/logger.md)
[How to use a .obj file to render an 3D Image](docs/obj_explain.md)
