# Práctica final: Sistema de alquiler de vehículos

Desarrolle una aplicación de consola para administrar clientes, vehículos,
alquileres y devoluciones utilizando Programación Orientada a Objetos.

No se proporcionará código base. Debe diseñar e implementar la solución
completa.

---

## Funcionalidades

El sistema debe mostrar un menú que permita:

1. Registrar un cliente.
2. Registrar un automóvil.
3. Registrar una motocicleta.
4. Ver clientes.
5. Ver vehículos.
6. Registrar un alquiler.
7. Registrar una devolución.
8. Ver alquileres activos.
9. Ver historial de alquileres.
10. Guardar los datos y salir.

### Clientes

Cada cliente debe tener, como mínimo:

* Cédula o documento de identidad.
* Nombre completo.
* Número telefónico.

No se pueden registrar dos clientes con el mismo documento.

### Vehículos

Todo vehículo debe tener:

* Matrícula.
* Marca.
* Modelo.
* Año.
* Tarifa diaria.
* Estado de disponibilidad.

Debe existir una clase abstracta `Vehiculo` y, al menos, las clases derivadas
`Automovil` y `Motocicleta`. `Vehiculo` no puede instanciarse directamente.

Además de los datos comunes, un automóvil debe registrar la cantidad de
puertas y una motocicleta debe registrar la cilindrada.

La matrícula debe ser única. No se puede alquilar un vehículo que no esté
disponible.

### Alquileres

Cada alquiler debe relacionar un cliente con un vehículo y almacenar:

* Un código único.
* Fecha de inicio.
* Cantidad de días acordados.
* Tarifa diaria aplicada al momento del alquiler.
* Estado: activo o finalizado.

Al registrar una devolución, el sistema debe calcular y mostrar el costo total
del alquiler. El vehículo debe volver a estar disponible.

Un cliente no puede tener más de dos alquileres activos al mismo tiempo.

---

## Requisitos de diseño

Debe cumplir todos los siguientes requisitos:

* Implementar herencia y polimorfismo mediante una clase abstracta. La clase
  `Vehiculo` debe declarar, como mínimo, los métodos virtuales puros
  `obtenerTipo()` y `calcularTarifaDiaria()`. Las clases `Automovil` y
  `Motocicleta` deben sobrescribirlos utilizando `override`.
* Almacenar automóviles y motocicletas en una sola colección mediante
  `std::unique_ptr<Vehiculo>`.
* Crear una clase `SistemaAlquiler` que controle el menú, las colecciones, las
  validaciones, las consultas y la persistencia.
* Separar la declaración y la implementación de cada clase en sus archivos
  `.h` y `.cpp`.
* Mantener todos los atributos privados.
* Usar composición o referencias por identificador para relacionar un
  `Alquiler` con un cliente y un vehículo.
* Utilizar archivos de texto para guardar y cargar automáticamente clientes,
  vehículos y alquileres.
* Conservar el tipo concreto de cada vehículo al cargar los datos.
* Validar todas las entradas con bucles hasta recibir un valor correcto.
* Mostrar los listados en formato tabular.

---

## Validaciones mínimas

Debe validar, entre otros:

* Que los textos obligatorios no estén vacíos.
* Que el año, la cilindrada, la cantidad de puertas, los días y la tarifa sean
  valores positivos.
* Que los códigos, documentos y matrículas no estén duplicados.
* Que el cliente y el vehículo existan antes de registrar un alquiler.
* Que el vehículo esté disponible antes de alquilarlo.
* Que el alquiler exista y esté activo antes de registrar una devolución.

---

## Organización sugerida

```text
Sistema de alquiler/
├── main.cpp
├── SistemaAlquiler.h
├── SistemaAlquiler.cpp
├── Vehiculo.h
├── Automovil.h
├── Automovil.cpp
├── Motocicleta.h
├── Motocicleta.cpp
├── Cliente.h
├── Cliente.cpp
├── Alquiler.h
├── Alquiler.cpp
└── archivos de datos
```

La estructura puede variar, pero cada clase debe tener su archivo de
declaración y su archivo de implementación.

---

## Restricciones

* No se permite utilizar `using namespace std`.
* No se permite utilizar variables globales para almacenar información.
* No se permite utilizar atributos públicos.
* La lógica principal debe permanecer dentro de `SistemaAlquiler`.
* El programa debe ejecutarse completamente en la terminal.
* Los textos ingresados deben admitir espacios.
* El código debe compilar sin advertencias.

---

## Compilación

La evaluación utilizará el siguiente comando desde la carpeta del proyecto:

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic -Werror *.cpp -o outputs/salida
```
