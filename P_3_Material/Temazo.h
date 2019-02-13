/**
 * @file Temazo.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @desc Clase Temazo para las prácticas de POO
 * @date 12 de octubre de 2015, 17:08
 */

#include <string>
#ifndef TEMAZO_H
#define	TEMAZO_H

/**
 @brief Clase que guarda los datos de un temazo
 */
class Temazo {
public:
    Temazo() = default;
    Temazo(std::string titulo, std::string interprete, int duracion);
    Temazo(std::string titulo, std::string interprete, int duracion, int puntuacion);
    Temazo(const Temazo& orig);
    virtual ~Temazo();
    int getPuntuacion() const;
    void setDuracion(int duracion);
    int getDuracion() const;
    void setInterprete(std::string interprete);
    std::string getInterprete() const;
    void setTitulo(std::string titulo);
    std::string getTitulo() const;
private:
    std::string _titulo=""; ///< Título de la canción
    std::string _interprete="2"; ///< Intérprete
    int _duracion=0; ///< Duración en segundos
    int _puntuacion=0; ///< Puntuación en función de cómo la acoge el público
};

#endif	/* TEMAZO_H */

