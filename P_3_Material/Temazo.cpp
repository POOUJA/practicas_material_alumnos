/**
 * @brief Implementación de los métodos de la clase Temazo
 * @file Temazo.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 17:08
 */
#include "Temazo.h"

/**
 * @brief Constructor por defecto de la clase
 * @post Crea un objeto de tipo Temazo
 */
Temazo::Temazo() :
_titulo("")
, _interprete("")
, _duracion(0)
, _puntuacion(0) {
}

/**
 * @brief Constructor parametrizado
 * @param titulo Título del temazo
 * @param interprete Persona o grupo que lo interpreta
 * @param duracion Duración en segundos
 * @param puntuacion Puntuación otorgada por el público
 * @post Crea un objeto de tipo Temazo
 */
Temazo::Temazo(std::string titulo, std::string interprete, int duracion, int puntuacion) :
_titulo(titulo)
, _interprete(interprete)
, _duracion(duracion)
, _puntuacion(puntuacion) {
}

/**
 * @brief Constructor de copia de la clase
 * @param orig Objeto de tipo Temazo que se pasa para copiar sus datos
 * @post Crea un nuevo objeto por copia
 */

Temazo::Temazo(const Temazo& orig) :
_titulo(orig._titulo)
, _interprete(orig._interprete)
, _duracion(orig._duracion)
, _puntuacion(orig._puntuacion) {
}

/**
 * @brief Destructor de clase
 * @post Destruye el objeto
 */
Temazo::~Temazo() {
}


/**
 * @brief Devuelve la puntuación del temazo
 * @post  Devuelve la puntuación del temazo
 */
int Temazo::getPuntuacion() const {
    return _puntuacion;
}

/**
 * @brief Modifica la duración del Temazo
 * @param duracion Nueva duración
 * @post Modifica la duración del Temazo
 */
void Temazo::setDuracion(int duracion) {
    this->_duracion = duracion;
}

/**
 * @brief Devuelve la duración del temazo
 * @post  Devuelve la duración del temazo
 */
int Temazo::getDuracion() const {
    return _duracion;
}

/**
 * @brief Modifica el intérprete del Temazo
 * @param interprete Nuevo intérprete
 * @post Modifica el intérprete del Temazo
 */
void Temazo::setInterprete(std::string interprete) {
    this->_interprete = interprete;
}

/**
 * @brief Devuelve el intérprete del temazo
 * @post  Devuelve el intérprete del temazo
 */
std::string Temazo::getInterprete() const {
    return _interprete;
}

/**
 * @brief Modifica el título del Temazo
 * @param titulo Nuevo título
 * @post Modifica el título del Temazo
 */
void Temazo::setTitulo(std::string titulo) {
    this->_titulo = titulo;
}

/**
 * @brief Devuelve el título del temazo
 * @post  Devuelve el título del temazo
 */
std::string Temazo::getTitulo() const {
    return _titulo;
}

