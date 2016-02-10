/* 
 * File:   Temazo.h
 * Author: Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * Created on 12 de octubre de 2015, 17:08
 */

#include <string>
#ifndef TEMAZO_H
#define	TEMAZO_H

class Temazo {
public:
    Temazo();
    Temazo(std::string titulo, std::string interprete, int duracion, int puntuacion = 0);
    Temazo(const Temazo& orig);
    virtual ~Temazo();
    int getPuntuacion() const;
    void setDuracion(int duracion);
    int getDuracion() const;
    void setInterprete(std::string interprete);
    std::string getInterprete() const;
    void setTitulo(std::string titulo);
    std::string getTitulo() const;
    
    // Añadido en Práctica 3
    void incrementarPuntuacion(int puntos);
    bool debeEstarEnLaLista() const;

private:
    std::string titulo;
    std::string interprete;
    int duracion;
    int puntuacion;

    // Añadido en práctica 3
    static int numTemazos;
    static int puntuacionTotal;

    static void incrementarPuntuacionTotal(int puntos);
    static void decrementarPuntuacionTotal(int puntos);
    static double calcularPuntuacionMedia();


};

#endif	/* TEMAZO_H */

