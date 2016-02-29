/** 
 * @file ParametroNoValido.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 19 de febrero de 2016, 12:17
 * @brief Clase Parametro no Valido. Permitirá lanzar excepciones de este tipo.
 */

#include <string>
#ifndef PARAMETRONOVALIDO_H
#define PARAMETRONOVALIDO_H

/**
 * @brief Clase para lanzar excepciones de este tipo
 */
class ParametroNoValido {
public:
    ParametroNoValido( std::string _fichero
            , std::string _funcion
            , std::string _descripcion );
    ParametroNoValido(const ParametroNoValido& orig);
    virtual ~ParametroNoValido();
    
    std::string queOcurre() const;
private:
    std::string fichero; ///< Nombre del fichero en el que se realiza el throw de la excepción
    std::string funcion; ///< Nombre de la función o método en el que se realiza el throw.
    std::string descripcion; ///<  Una descripción del error ocurrido.
    
};

#endif /* PARAMETRONOVALIDO_H */

