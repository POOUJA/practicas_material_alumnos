/**
 * @file Temazo.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @desc Clase Temazo para las prácticas de POO
 * @date 12 de octubre de 2015, 17:08
 */

#include <string>
#include "Fecha.h"
#ifndef TEMAZO_H
#define TEMAZO_H

/**
 @brief Clase que guarda los datos de un temazo
 */
class Temazo {
public:
    Temazo();
    
    // Modificado para la práctica 4
    Temazo(std::string _titulo
            , std::string _interprete
            , int _duracion
            , std::string _nombreUltimoGarito
            , const Fecha& fechaUltimoUso
            , int _puntuacion = 0);
    
    
    Temazo(const Temazo& orig);
    virtual ~Temazo();
    int getPuntuacion() const;
    void setDuracion(int duracion);
    int getDuracion() const;
    void setInterprete(std::string interprete);
    std::string getInterprete() const;
    void setTitulo(std::string titulo);
    std::string getTitulo() const;
    
    // Añadido en práctica 3
    void incrementarPuntuacion(int puntos);
    bool debeEstarEnLaLista() const;
    
    // Añadido en práctica 4
    void setFechaUltimoUso(const Fecha& fechaUltimoUso);
    Fecha getFechaUltimoUso() const;
    
    void setNombreUltimoGarito(std::string nombreUltimoGarito);
    std::string getNombreUltimoGarito() const;

private:
    std::string titulo; ///< Título de la canción
    std::string interprete; ///< Intérprete
    int duracion; ///< Duración en segundos
    int puntuacion; ///< Puntuación en función de cómo la acoge el público

    // Añadido en práctica 3
    static int numTemazos; ///< Número de temazos que s ellevan instanciados
    static int puntuacionTotal; ///< Puntuación total de todos los temazos

    static void incrementarPuntuacionTotal(int puntos);
    static void decrementarPuntuacionTotal(int puntos);
    static double calcularPuntuacionMedia();
    
    // Añadido en práctica 4
    std::string nombreUltimoGarito; ///< Nombre del último garito en el que se usó este temazo
    Fecha fechaUltimoUso; ///< Fecha en que se usó por última vez este tema

};

#endif /* TEMAZO_H */

