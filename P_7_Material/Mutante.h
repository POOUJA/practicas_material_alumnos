/**
 * @file Mutante.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef MUTANTE_H
#define MUTANTE_H

#include <string>

using std::string;

/**
 * @brief Clase Muntante
 */
class Mutante {
public:
    static const int MAX_PODERES = 10; ///< Max. moderes de un mutante

public:
    Mutante() = default;
    Mutante(string nombre, string apodo, int fechaN,string nacionalidad);
    Mutante(const Mutante& orig);
    virtual ~Mutante();
    void setNombreReal(string nombreReal);
    string getNombreReal() const;
    void setNacionalidad(string nacionalidad);
    string getNacionalidad() const;
    void setFechaDeNacimiento(int fechaDeNacimiento);
    int getFechaDeNacimiento() const;
    void setApodo(string apodo);
    string getApodo() const;

    string toCSV() const;

    Mutante& operator=(const Mutante& orig);

private:
    string _nombreReal = "---";
    string _apodo = "---";
    int _fechaDeNacimiento = 0;
    string _nacionalidad = "---";

};

#endif /* MUTANTE_H */

