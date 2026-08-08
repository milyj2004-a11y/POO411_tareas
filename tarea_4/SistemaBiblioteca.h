#ifndef SISTEMABIBLIOTECA_H
#define SISTEMABIBLIOTECA_H

#include <memory>
#include <vector>

#include "Libro.h"
#include "Prestamo.h"
#include "Revista.h"
#include "Usuario.h"

class SistemaBiblioteca
{
private:

    std::vector<Usuario> usuarios;

    std::vector<std::shared_ptr<MaterialBiblioteca>> materiales;

    std::vector<Prestamo> prestamos;

    int siguienteUsuario;

    int siguienteMaterial;

    void menu() const;

    void registrarUsuario();

    void registrarLibro();

    void registrarRevista();

    void mostrarUsuarios() const;

    void mostrarMateriales() const;

    void realizarPrestamo();

    void devolverMaterial();

    void mostrarPrestamos() const;

    int contarPrestamos(int codigoUsuario) const;

    void guardarUsuarios();

    void guardarMateriales();

    void guardarPrestamos();

    void cargarUsuarios();

    void cargarMateriales();

    void cargarPrestamos();

public:

    SistemaBiblioteca();

    ~SistemaBiblioteca();

    void ejecutar();
};

#endif