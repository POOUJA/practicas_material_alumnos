/* 
 * File:   Fecha.h
 * Author: Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * Created on 12 de octubre de 2015, 17:59
 */

#ifndef FECHA_H
#define	FECHA_H

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
    int dia, mes, anio;

};

#endif	/* FECHA_H */

