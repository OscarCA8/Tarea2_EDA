## Pasos para realizar la compilación:

1- En cpp, debe ir al archivo llamado `test.cpp` y en las líneas de código N° 31, 32 y 33 (Especificamente, en el `main()`) debe cambiar las rutas de los datasets por la rutas donde usted tenga los 
archivos llamados `codes_500K.txt`, `codes_1M.txt` y `codes_10M.txt` que vienen en esta carpeta. (Recuerde guardar el archivo luego de hacer estos cambios :D)

2- Ir a la carpeta `build` que se encuentra en cpp/build

3- En caso de haber archivos previamente creados, realizar el siguiente comando en la terminal: 
```bash
make clean
```

4- Posteriormente, ejecutar el siguiente comando: 
```bash
cmake ..
```

5- Como penúltimo paso, se debe ejecutar el comando: 
```bash
make
```
(Esto creará el archivo ejecutable llamado test que se encontrará en la carpeta build. Si desea corroborarlo, escriba ls en la terminal y ejecutelo)

6- Por último, ejecute el comando: 
```bash
./test
```
y se deberían mostrar los resultados en la pantalla de la terminal.

## Esperamos que le haya funcionado nuestro código!
