# Configure a scene file

The scene file is a `.cfg` file, used to execute the program after his compilation.\
All the values inside this files **must be float** and respect the same syntax of the following exemples.\
It contains the following configuration :

## Camera configuration :
```bash
camera : {
    lookfrom : { x = 0.0; y = 0.0; z = 0.0; },
    lookat : { x = 0.0; y = 0.0; z = 0.0; },
    vup : { x = 0.0; y = 0.0; z = 0.0; },
    vfov : { x = 0.0; },
    width : { x = 0.0; },
    height : { x = 0.0; },
    aperture : { x = 0.0; },
    ns : { x = 0.0; },
}
```

## Light configuration :
```bash
light : {
    position : { x = 0.0; y = 0.0; z = 0.0; },
    intensity : { x = 0.0; },
    normal : { x = 0.0; y = 0.0; z = 0.0; },
    direc : { x = 0.0; },
    size : { x = 0.0; }
}
```

## Primitives configuration :
```bash
primitives : {
    planes : (
        {
            first : { x = 0.0; y = 0.0; z = 0.0; },
            second : { x = 0.0; y = 0.0; z = 0.0; },
            material : {
                type : "lambertian",
                vec : { x = 0.0; y = 0.0; z = 0.0; }
            }
            effect : {
                type : "tint", // optionnal, if you want to change the color
                vec : { x = 0.0; y = 0.0; z = 0.0; }
            }
        },
    ),
    spheres : (
        {
            center : { x = 0.0; y = 0.0; z = 0.0; },
            radius : { x = 0.0; y = 0.0; z = 0.0; },
            material : {
                type : "lambertian",
                vec : { x = 0.0; y = 0.0; z = 0.0; },
            }
        },
	    {
            center : { x = 0.0; y = 0.0; z = 0.0; },
            radius : { x = 0.0; y = 0.0; z = 0.0; },
            material : {
                type : "metal",
                vec : { x = 0.0; y = 0.0; z = 0.0; },
                fuzz : { x = 0.0; }
            }
        },
	    {
            center : { x = 0.0; y = 0.0; z = 0.0; },
            radius : { x = 0.5; y = 0.0; z = 0.0; },
            material : {
                type : "metal",
                vec : { x = 0.0; y = 0.0; z = 0.0; },
                fuzz : { x = 0.0; }
            }
        },
	    {
            center : { x = 0.0; y = 0.0; z = 0.0; },
            radius : { x = 0.0; y = 0.0; z = 0.0; },
            material : {
                type : "lambertian",
                vec : { x = 0.0; y = 0.0; z = 0.0; },
            }
            effect : { // optionnal, if you want to change the color
                type : "tint",
                vec : { x = 0.0; y = 0.0; z = 0.0; }
            }
        },
    ),
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
}
```
You can have as many primitives you want, in fact you can also have none (but the result will be empty).