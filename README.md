## Pasos para realizar la compilación:

1- En cpp, debe ir al archivo llamado `test.cpp` y en las líneas de código N° 31, 32 y 33 (Especificamente, en el `main()`) debe cambiar las rutas de los datasets por la rutas donde usted tenga los 
archivos llamados `codes_500K.txt`, `codes_1M.txt` y `codes_10M.txt` que vienen en esta carpeta. (Recuerde guardar el archivo luego de hacer estos cambios :D)

2- En cpp, se debe crear una carpeta llamada `build` a través del siguiente comando:
```bash
mkdir build
```

3- Ir a la carpeta `build` creada que se encuentra en `cpp/build` ejecutando:
```bash
cd build
```

4- En caso de haber archivos previamente creados, realizar el siguiente comando en la terminal: 
```bash
make clean
```

5- Posteriormente, ejecutar el siguiente comando: 
```bash
cmake ..
```

6- Como penúltimo paso, se debe ejecutar el comando: 
```bash
make
```
(Esto creará el archivo ejecutable llamado test que se encontrará en la carpeta build. Si desea corroborarlo, escriba ls en la terminal y ejecutelo)

7- Por último, ejecute el comando: 
```bash
./test
```
y se deberían mostrar los resultados en la pantalla de la terminal.

- Los resultados que se muestran para cada método de ordenación son los siguientes, junto con algunas indicaciones:
  - Las primeras 10 lineas de los archivos con los códigos postales antes de ser ordenados.
  - Los primeros 10 códigos postales después de que los archivos fueron ordenados por el método aplicado.
  - (En caso de que se quiera mostrar más o menos de 10 códigos postales, se debe cambiar el valor de `int sampleSize` de la función `showSample()` en `test.cpp` y volver a repetir todo el proceso de compilación.)
  - Tiempo de procesamiento del método aplicado en formato (μr ± σr), donde μr es el promedio y σr es la desviación.
  - (El código realiza la ejecución de cada método 5 veces en cada uno de los 3 archivos .txt, tal como se menciona en el enunciado. Esto quiere decir que el tiempo de procesamiento del método está calculado según el promedio (μ) y la desviación estándar (σ) a partir de las 5 ejecuciones del mismo método sobre el mismo conjunto de datos.)

- Cabe mencionar que para esta entrega, los resultados entregados en la plantalla de la terminal pueden tener cierta demora para el último caso. Esto se debe a que el archivo `codes_10M.txt` cuenta con 10 millones de códigos postales, sin embargo, el código fue probado y funciona correctamente (pero con paciencia, asi que se recomienda ir a preparar un café mientras carga este último caso).

## Esperamos que le haya funcionado nuestro código!
