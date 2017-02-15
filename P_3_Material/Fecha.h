/**
 * @file Fecha.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @desc Clase Fecha para las prácticas de POO
 * @date 12 de octubre de 2015, 17:08
 */


#ifndef FECHA_H
#define	FECHA_H
/**
 * @brief Clase fecha
 */
class Fecha {
public:
    Fecha();
    Fecha( int dia, int mes, int anio);
    Fecha(const Fecha& orig);
    virtual ~Fecha();
    void setAnio(int anio);
    int getAnio() const;
    void setMes(int mes);
    int getMes() const;
    void setDia(int dia);
    int getDia() const;
private:
    int _dia; ///< Dia dentro de un mes
    int _mes; ///< Mes dentro de un año
    int _anio; ///< Año de la fecha almacenada
};

#endif	/* FECHA_H */

