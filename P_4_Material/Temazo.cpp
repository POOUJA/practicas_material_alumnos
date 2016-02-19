/** 
 * @brief Implementación de los métodos de la clase Temazo
 * @file Temazo.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 17:08
 */
#include "Temazo.h"
#include "ParametroNoValido.h"


int Temazo::numTemazos = 0;
int Temazo::puntuacionTotal = 0;

/**
 * @brief Constructor por defecto de la clase
 * @post Crea un objeto de tipo Temazo
 */
Temazo::Temazo() :
titulo("")
, interprete("")
, duracion(0)
, puntuacion(0) {
    ++numTemazos;
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
titulo(titulo)
, interprete(interprete)
, duracion(duracion)
, puntuacion(puntuacion) {
    ++numTemazos;
    incrementarPuntuacionTotal(puntuacion);
}

/**
 * @brief Constructor de copia de la clase
 * @param orig Objeto de tipo Temazo que se pasa para copiar sus datos
 * @post Crea un nuevo objeto por copia
 */

Temazo::Temazo(const Temazo& orig) :
titulo(orig.titulo)
, interprete(orig.interprete)
, duracion(orig.duracion)
, puntuacion(orig.puntuacion) {
    ++numTemazos;
    incrementarPuntuacionTotal(puntuacion);
}

/**
 * @brief Destructor de clase
 * @post Destruye el objeto
 */
Temazo::~Temazo() {
    --numTemazos;
    decrementarPuntuacionTotal(puntuacion);
}

/**
 * @brief Devuelve la puntuación del temazo
 * @post  Devuelve la puntuación del temazo
 */
int Temazo::getPuntuacion() const {
    return puntuacion;
}

/**
 * @brief Modifica la duración del Temazo
 * @param duracion Nueva duración
 * @post Modifica la duración del Temazo
 */
void Temazo::setDuracion(int duracion) {
    this->duracion = duracion;
}

/**
 * @brief Devuelve la duración del temazo
 * @post  Devuelve la duración del temazo
 */
int Temazo::getDuracion() const {
    return duracion;
}

/**
 * @brief Modifica el intérprete del Temazo
 * @param interprete Nuevo intérprete
 * @post Modifica el intérprete del Temazo
 */
void Temazo::setInterprete(std::string interprete) {
    this->interprete = interprete;
}

/**
 * @brief Devuelve el intérprete del temazo
 * @post  Devuelve el intérprete del temazo
 */
std::string Temazo::getInterprete() const {
    return interprete;
}

/**
 * @brief Modifica el título del Temazo
 * @param titulo Nuevo título
 * @post Modifica el título del Temazo
 */
void Temazo::setTitulo(std::string titulo) {
    this->titulo = titulo;
}

/**
 * @brief Devuelve el título del temazo
 * @post  Devuelve el título del temazo
 */
std::string Temazo::getTitulo() const {
    return titulo;
}

/**
 * @brief Incrementa la puntuación total
 * @param puntos Número de puntos para incrementar
 * @post Añade a la puntuación total los puntos que se indiquen.
 */
void Temazo::incrementarPuntuacionTotal(int puntos) {
    puntuacionTotal += puntos;
}

/**
 * @brief Decrementa la puntuación total
 * @param puntos Número de puntos para decrementar
 * @post Resta a la puntuación total los puntos que se indiquen.
 */

void Temazo::decrementarPuntuacionTotal(int puntos) {
    puntuacionTotal -= puntos;
}

/**
 * @brief Calcula la media de puntuación por temazo
 * @return la media de la puntuación por temazo
 */

double Temazo::calcularPuntuacionMedia() {
    return (numTemazos != 0) ? puntuacionTotal / numTemazos : 0;
}

/**
 * @brief Incrementa la puntuación de un temazo
 * @param puntos Número de puntos para incrementar
 * @thows Excepcion del tipo ParametroNoValido si el valor d epuntos es menor que 0 o mayor que 10.
 * @post Añade a la puntuación del temazo y a la puntuación total los puntos que se indiquen.
 */

void Temazo::incrementarPuntuacion(int puntos) {
    if( puntos<0 ) throw ParametroNoValido( "Temazo.cpp"
            , "incrementarPuntuacion"
            , "El valor de los puntos a incrementar no puede ser menor que 0.");
     if( puntos>10 ) throw ParametroNoValido( "Temazo.cpp"
            , "incrementarPuntuacion"
            , "El valor de los puntos a incrementar no puede ser mayor que 10.");
    puntuacion += puntos;
    incrementarPuntuacionTotal(puntos);
}

/**
 * @brief Devuelve true o false en función de si el temazo debe estar en la lista de éxitos del DJ
 * @return Develeuve true si la puntuación del tema es mayor o igual que la media; false en otro caso
 */
bool Temazo::debeEstarEnLaLista() const {
    return puntuacion>=calcularPuntuacionMedia();
}