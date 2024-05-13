# Use and .obj file

First, you'll need to download an `.obj` file with his **texture**.\
Respectively add the .obj inside the `obj_files` folder, and the texture inside the `assets` folder.

## Data inside .obj

The syntax of the file, must be either this way :
```bash
v -0.353428 0.573690 -0.064701
f 224/162/171 31/163/172 197/112/112
```
or like that :
```bash
v -0.353428 0.573690 -0.064701
f 224/162/171 31/163/172 197/112/112 123/233/213
```

## Add .obj to scene file

Inside the [scene file](scene_file.md) you'll have to add this part :
```bash
obj : (
    {
        state : "yes", // or no
        path_file : "path/to/.obj",
        material : {
            type : "Texture",
            path : "path/to/Texture",
        },
        scale : { x = 0.0; y = 0.0; z = 0.0; },
        rotation : { x = 0.0; y = 0.0; z = 0.0; },
        position : { x = 0.0; y = 0.0; z = 0.0; },
    },
    {
        state : "yes", // or no
        path_file : "path/to/.obj",
        material : {
            type : "Texture",
            path : "path/to/Texture",
        },
        scale : { x = 0.0; y = 0.0; z = 0.0; },
        rotation : { x = 0.0; y = 0.0; z = 0.0; },
        position : { x = 0.0; y = 0.0; z = 0.0; },
    }
)
```
Where yes allow the .obj to be in the scene.