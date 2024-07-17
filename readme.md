# running it by simply running this in project root

```sh
make 
```

or you can

```sh
make prepare
```

then you `cd build` and after that run this for create Visual Studio 16 compatiable binary :

```sh
cmake -S .. -B . -G "Visual Studio 16 2019"
```

now you build by:

```sh
cmake --build .
```

now you have an excutable ...
for more info checkout : https://github.com/franneck94/UdemyCmake/blob/master/2_CMake/README.md