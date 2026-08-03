#include <iostream>
#include <string>
#include <vector>

/*---------------------------------
Práctica: sistema de préstamos de biblioteca

Convierta el programa entregado a programación orientada a objetos.

Debe crear una clase base abstracta MaterialBiblioteca y utilizar herencia y
polimorfismo para representar Libro y Revista. Los materiales deben guardarse
en una sola colección mediante punteros inteligentes.

Debe crear las clases Usuario, Prestamo y SistemaBiblioteca. SistemaBiblioteca
debe controlar el menú, las validaciones y la persistencia.

Debe separar cada clase en sus archivos .h y .cpp. Todos los atributos deben
ser privados. No puede utilizar variables globales ni `using namespace std`.

Debe conservar el comportamiento del programa original e implementar además:
  - Guardado y carga automática de usuarios, materiales y préstamos en archivos
    de texto.
  - Códigos únicos para usuarios y materiales.
  - Validación de disponibilidad antes de prestar un material.
  - Devolución de materiales prestados.
  - Un máximo de tres préstamos activos por usuario.

--------------------------------------*/

struct Material {
  int tipo;
  std::string codigo;
  std::string titulo;
  std::string responsable;
  bool disponible;
};

struct Usuario {
  std::string codigo;
  std::string nombre;
};

struct Prestamo {
  std::string codigoUsuario;
  std::string codigoMaterial;
};

void registrarLibro(std::vector<Material> &materiales) {
  Material material;
  material.tipo = 1;
  material.disponible = true;

  std::cout << "Codigo del libro: ";
  std::getline(std::cin, material.codigo);
  std::cout << "Titulo: ";
  std::getline(std::cin, material.titulo);
  std::cout << "Autor: ";
  std::getline(std::cin, material.responsable);

  materiales.push_back(material);
  std::cout << "Libro registrado.\n";
}

void registrarRevista(std::vector<Material> &materiales) {
  Material material;
  material.tipo = 2;
  material.disponible = true;

  std::cout << "Codigo de la revista: ";
  std::getline(std::cin, material.codigo);
  std::cout << "Titulo: ";
  std::getline(std::cin, material.titulo);
  std::cout << "Editorial: ";
  std::getline(std::cin, material.responsable);

  materiales.push_back(material);
  std::cout << "Revista registrada.\n";
}

void registrarUsuario(std::vector<Usuario> &usuarios) {
  Usuario usuario;

  std::cout << "Codigo del usuario: ";
  std::getline(std::cin, usuario.codigo);
  std::cout << "Nombre completo: ";
  std::getline(std::cin, usuario.nombre);

  usuarios.push_back(usuario);
  std::cout << "Usuario registrado.\n";
}

void mostrarMateriales(const std::vector<Material> &materiales) {
  if (materiales.empty()) {
    std::cout << "No hay materiales registrados.\n";
    return;
  }

  std::cout << "\n--- Materiales ---\n";
  for (const Material &material : materiales) {
    std::cout << (material.tipo == 1 ? "Libro: " : "Revista: ")
              << material.codigo << " - " << material.titulo << " - "
              << material.responsable << " - "
              << (material.disponible ? "Disponible" : "Prestado") << '\n';
  }
}

void prestarMaterial(std::vector<Material> &materiales,
                     const std::vector<Usuario> &usuarios,
                     std::vector<Prestamo> &prestamos) {
  std::string codigoUsuario;
  std::string codigoMaterial;

  std::cout << "Codigo del usuario: ";
  std::getline(std::cin, codigoUsuario);
  std::cout << "Codigo del material: ";
  std::getline(std::cin, codigoMaterial);

  bool usuarioExiste = false;
  for (const Usuario &usuario : usuarios) {
    if (usuario.codigo == codigoUsuario) {
      usuarioExiste = true;
      break;
    }
  }

  if (!usuarioExiste) {
    std::cout << "Usuario no encontrado.\n";
    return;
  }

  for (Material &material : materiales) {
    if (material.codigo == codigoMaterial) {
      if (!material.disponible) {
        std::cout << "El material no esta disponible.\n";
        return;
      }

      material.disponible = false;
      prestamos.push_back({codigoUsuario, codigoMaterial});
      std::cout << "Prestamo registrado.\n";
      return;
    }
  }

  std::cout << "Material no encontrado.\n";
}

void devolverMaterial(std::vector<Material> &materiales,
                      std::vector<Prestamo> &prestamos) {
  std::string codigoMaterial;
  std::cout << "Codigo del material: ";
  std::getline(std::cin, codigoMaterial);

  for (std::size_t i = 0; i < prestamos.size(); ++i) {
    if (prestamos[i].codigoMaterial == codigoMaterial) {
      for (Material &material : materiales) {
        if (material.codigo == codigoMaterial) {
          material.disponible = true;
          prestamos.erase(prestamos.begin() + static_cast<long>(i));
          std::cout << "Material devuelto.\n";
          return;
        }
      }
    }
  }

  std::cout << "No existe un prestamo activo para ese material.\n";
}

int main() {
  std::vector<Material> materiales;
  std::vector<Usuario> usuarios;
  std::vector<Prestamo> prestamos;
  int opcion = -1;

  while (opcion != 0) {
    std::cout << "\n=== Biblioteca ===\n";
    std::cout << "1. Registrar libro\n";
    std::cout << "2. Registrar revista\n";
    std::cout << "3. Registrar usuario\n";
    std::cout << "4. Prestar material\n";
    std::cout << "5. Devolver material\n";
    std::cout << "6. Mostrar materiales\n";
    std::cout << "0. Salir\n";
    std::cout << "Opcion: ";

    std::cin >> opcion;
    std::cin.ignore();

    if (opcion == 1) {
      registrarLibro(materiales);
    } else if (opcion == 2) {
      registrarRevista(materiales);
    } else if (opcion == 3) {
      registrarUsuario(usuarios);
    } else if (opcion == 4) {
      prestarMaterial(materiales, usuarios, prestamos);
    } else if (opcion == 5) {
      devolverMaterial(materiales, prestamos);
    } else if (opcion == 6) {
      mostrarMateriales(materiales);
    } else if (opcion != 0) {
      std::cout << "Opcion no valida.\n";
    }
  }

  return 0;
}
