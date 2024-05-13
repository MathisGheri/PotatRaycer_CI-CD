# Add a new primitive

## Create file .hpp/cpp

In `src/Primitives/` add a new folder which will contain your cpp/hpp files.

The class you will create, will need to inheirit from the **IHitable** class.
You will have to add the following include:
```bash
#include "IHitable.hpp"
```
Your class implementation should look like this:
```bash
class [NewForm] : public IHitable {
```
You will then have to implement in your .cpp file the following methodes inheirited by IHitable:
```bash
virtual bool hit(const Ray &r, float t_min, float t_max, hit_record_t &rec) const = 0;
virtual void setMaterial(std::shared_ptr<IMaterial> m) = 0;
virtual std::shared_ptr<IMaterial> getMaterial() = 0;
```
It should look like this:
```bash
bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const;
void setMaterial(std::shared_ptr<IMaterial> m);
std::shared_ptr<IMaterial> getMaterial();
```
Once you've done all the implementation you can now add it to the scene.

## Add the new primitive to the scene

In `src/Builder/SceneBuilder.cpp` you will find the following function:
```bash
void SceneBuilder::createPrimitives(std::vector<Primitive> primitives)
```
In which you will be able to call the constructor of the new Primitive:
```bash
std::shared_ptr<IHitable> object = std::make_shared<[NewForm]>([constructor]);
```
Then add his material:
```bash
// Lambertian material for exemple
std::shared_ptr<IMaterial> material = std::make_shared<Lambertian>(Vec3(0.7, 0.7, 0.7));
object->setMaterial(material);
```
And finaly add it to the scene:
```bash
scene.addObject(object);
```
Make sure to include your new folder containing the primitive inside the cmake.

## Add folder to Cmake

At the root of the repository you'll find the `CMakeLists.txt` file.\
Simply add the path to your new folder:
```bash
${CMAKE_CURRENT_SOURCE_DIR}/src/Primitives/[NewForm]
```
That's it, you are good to go.